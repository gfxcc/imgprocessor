
#include <memory>
#include <ev.h>
#include <amqpcpp.h>
#include <amqpcpp/libev.h>
#include <unistd.h>
#include <json.hpp>

#include "tesseract.h"
#include "status.h"

using namespace std;
using json = nlohmann::json;

int main()
{
  // create tesseract engine
  Status s;

  Tesseract::Configure conf;
  conf.path_lang = "/usr/share/tesseract-ocr/";
  conf.lang = "chi_sim";
  Tesseract* tesseract_ptr;
  s = Tesseract::Init(conf, &tesseract_ptr);
  shared_ptr<Tesseract> tesseract(tesseract_ptr);

  if (!s.ok()) {
    cout << "Error: " << s.msg << endl;
    return -1;
  }


  // access to the event loop
  auto *loop = EV_DEFAULT;

  AMQP::LibEvHandler handler(loop);
  AMQP::TcpConnection connection(&handler, AMQP::Address("amqp://localhost/"));
  AMQP::TcpChannel channel(&connection);

  // create a custom callback
  auto callback = [](const std::string &name, int msgcount, int consumercount) {
    // @todo add your own implementation
    cout << "declare queue successed" <<endl;
  };

  // declare the queue, and install the callback that is called on success
  channel.declareQueue("task_identify_img").onSuccess(callback);

  // callback function that is called when the consume operation starts
  auto startCb = [](const std::string &consumertag) {
    cout << "consume operation started" << endl;
  };

  // callback function that is called when the consume operation failed
  auto errorCb = [](const char *message) {
    cout << "consume operation failed" << endl;
  };

  // callback operation when a message was received
  auto messageCb = [&channel, &tesseract](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered) {
    cout << "task received" << endl;
    json task_json = json::parse(string{message.body(), message.bodySize()});
    string path(task_json["path_img"].get<string>()),
           keyword(task_json["keyword"].get<string>());
    cout << "path_img:" << path << endl;
    cout << "keyword:" << keyword << endl;

    string text;
    tesseract->GetUTF8Text(path, text);

    cout << "text:" << text << endl;
    channel.ack(deliveryTag);
  };

  // start consuming from the queue, and install the callbacks
  channel.consume("task_identify_img")
    .onReceived(messageCb)
    .onSuccess(startCb)
    .onError(errorCb);
  // run the loop
  ev_run(loop, 0);

  // done
  return 0;
}
