#include "i2c_endpoint.h"

#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>          //O_RDWR
#include <unistd.h>         // Read and write

namespace BBT {

  /*
  * Pointer to write function used for i2c communication.
  * Also see http://linux.die.net/man/2/write
  */
  ssize_t (* file_write)(int, const void *, size_t) = write;

  /*
  * Pointer to read function used for i2c communication.
  * Also see http://linux.die.net/man/2/read
  */
  ssize_t (* file_read)(int, void *, size_t) = read;

  /*
  * Pointer to open function used for opening a file.
  * Also see https://linux.die.net/man/2/open
  */
  int (* file_open)(const char *pathname, int flags, ...) = open;

  I2cEndPoint::I2cEndPoint(unsigned int address, std::string filename) {
    this->address = address;
    this->filename = filename;
    open();
  }
  
  I2cEndPoint::~I2cEndPoint(void) {
    close(fileHandle);
  }

  void I2cEndPoint::open(void) {
    if ((fileHandle = file_open(filename.c_str(), O_RDWR)) < 0) {
      throw "Failed to open the i2c bus.";
    }

    if (ioctl(fileHandle, I2C_SLAVE, address) < 0) {
      throw "Failed to acquire bus access and/or talk to slave.";
    }
  }

  bool I2cEndPoint::write(char * buffer, int length) {
    return (file_write(fileHandle, buffer, length) == length);
  }

  bool I2cEndPoint::read(char * buffer, int length) {
    return (file_read(fileHandle, buffer, length) == length);
  }

};