//
// created by Yong Cao on Jun/16/2017
//
#ifndef _IMG_PROCESSOR_TESSERACT_H_
#define _IMG_PROCESSOR_TESSERACT_H_


#include <string>

#include <allheaders.h> // leptonica main header for image io
#include <baseapi.h> // tesseract main header

struct Status;

class Tesseract {
public:
  struct Configure {
    std::string path_lang;
    std::string lang;
  };

  static Status Init(const Configure& conf, Tesseract** tesseract);
  Tesseract() {}
  ~Tesseract() {
    tess_.Clear();
  }

  Status GetUTF8Text(const std::string& path_img, std::string& str);

private:
  tesseract::TessBaseAPI tess_;
};



#endif // _IMG_PROCESSOR_TESSERACT_H_
