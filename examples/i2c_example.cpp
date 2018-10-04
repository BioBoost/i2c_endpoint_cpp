#include <iostream>
#include <i2c_endpoint/i2c_endpoint.h>

using namespace std;

int main(void) {
  cout << "Basic demo of I2c Endpoint in C++" << endl;

  BBT::I2cEndPoint touch(0x1b, "/dev/i2c-1");

  char buffer[1];
  if (touch.read(buffer, 1)) {
    cout << "Chip ID = " << std::hex << "0x" << (int)buffer[0] << endl;
  }

  return 0;
}
