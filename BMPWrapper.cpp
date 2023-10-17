#include "BMPWrapper.h"

bool BMP581Wrapper::init(){
  bool status = (_bmp1.beginI2C(0x47, Wire) == BMP5_OK);
  status |= (_bmp2.beginI2C(0x46, Wire) == BMP5_OK);
  status |= (_bmp3.beginI2C(0x47, Wire2) == BMP5_OK);
  return status;
}

bool BMP581Wrapper::setup(){
  return true;
}

bool BMP581Wrapper::read_data(float* output, uint8_t size) {
  bmp5_sensor_data data = {0, 0};
  bool status = (_bmp1.getSensorData(&data) == BMP5_OK);
  output[0] = data.pressure;
  output[3] = data.temperature;

  status |= (_bmp2.getSensorData(&data) == BMP5_OK);
  output[1] = data.pressure;
  output[4] = data.temperature;

  status |= (_bmp3.getSensorData(&data) == BMP5_OK);
  output[2] = data.pressure;
  output[5] = data.temperature;

  return status;
}
