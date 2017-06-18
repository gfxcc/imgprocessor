//
// created by Yong Cao on Jun/16/2017
//
#ifndef _IMG_PROCESSOR_STATUS_H_
#define _IMG_PROCESSOR_STATUS_H_

#include <string>

struct Status {
  int ret;
  std::string msg;

  bool ok() { return ret == 0; }

};

#endif // _IMG_PROCESSOR_STATUS_H_
