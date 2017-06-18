#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <amqpcpp.h>

#include "tesseract.h"
#include "status.h"
#include "mqhandler.h"

using namespace std;
using namespace AMQP;

int main(int argc, char *argv[])
{
  Status s;

  Tesseract::Configure conf;
  conf.path_lang = "/usr/share/tesseract-ocr/";
  conf.lang = "chi_sim";
  Tesseract* tesseract_ptr;
  s = Tesseract::Init(conf, &tesseract_ptr);
  unique_ptr<Tesseract> tesseract(tesseract_ptr);

  if (!s.ok()) {
    cout << "Error: " << s.msg << endl;
    return -1;
  }

  //string text;
  //tesseract->GetUTF8Text(argv[1], text);

  // create an instance of your own tcp handler
  MQHandler myHandler;

  // address of the server
  AMQP::Address address("amqp://localhost:5672");
  cout << string(address) << endl;

  // create a AMQP connection object
  AMQP::TcpConnection connection(&myHandler, address);

  // and create a channel
  AMQP::TcpChannel channel(&connection);

  channel.declareExchange("")

    .onSuccess([]() {
        // by now the exchange is created
        cout << "declear channel successed" << endl;
        })

  .onError([](const char *message) {
      // something went wrong creating the exchange
      //
      cout << "declear channel failed" << endl;
      });


  // callback function that is called when the consume operation starts
  auto startCb = [](const std::string &consumertag) {

    std::cout << "consume operation started" << std::endl;
  };

  // callback function that is called when the consume operation failed
  auto errorCb = [](const char *message) {

    std::cout << "consume operation failed" << std::endl;
  };

  // callback operation when a message was received
  auto messageCb = [&channel](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered) {

    std::cout << "message received" << std::endl;

    // acknowledge the message
    channel.ack(deliveryTag);
  };

  // start consuming from the queue, and install the callbacks
  channel.consume("hello")
    .onReceived(messageCb)
    .onSuccess(startCb)
    .onError(errorCb);


  return 0;
}
