//
// created by Yong Cao on Jun/16/2017
//

#include "tesseract.h"

#include <iostream>

#include "status.h"

using namespace std;

Status Tesseract::Init(const Configure& conf, Tesseract** tesseract) {
  Status s;
  Tesseract* tess_ptr = new Tesseract();
  if (tess_ptr->tess_.Init(conf.path_lang.c_str(), conf.lang.c_str())) {
    s.msg = "OCRTesseract: Could not initialize tesseract";
    s.ret = -1;
    return s;
  }

  tess_ptr->tess_.SetPageSegMode(tesseract::PageSegMode::PSM_AUTO);
  tess_ptr->tess_.SetVariable("save_best_choices", "T");

  *tesseract = tess_ptr;
  s.ret = 0;
  return s;
}


Status Tesseract::GetUTF8Text(const std::string& path_img, string& str) {
  Status s;

  // read img
  auto pixs = pixRead(path_img.c_str());
  if (!pixs) {
    s.msg = "Cannot open input file: " + path_img;
    s.ret = -1;
    return s;
  }

  //pixs->SetSourceYResolution(70);

  // recognize
  tess_.SetImage(pixs);
  tess_.SetSourceResolution(72);
  tess_.Recognize(0);

  // get result and delete[] returned char* string
  str = tess_.GetUTF8Text();

  pixDestroy(&pixs);

  s.ret = 0;
  return s;
}


