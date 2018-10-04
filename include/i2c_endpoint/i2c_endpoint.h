#pragma once

#include <string>

namespace BBT {

  class I2cEndPoint {

    public:
      I2cEndPoint(unsigned int address, std::string filename);
      ~I2cEndPoint(void);

    public:
      bool write(char * buffer, int length);
      bool read(char * buffer, int length);

    private:
      void open(void);

    private:
      std::string filename;
      unsigned int address;
      int fileHandle;
  };

};
