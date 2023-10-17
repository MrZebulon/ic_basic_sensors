#include "BNOWrapper.h"

bool BNO055Wrapper::init(){
  bool status = _bno1.begin();
  status |= _bno2.begin();
  status |= _bno3.begin();
  return status;
}

bool BNO055Wrapper::setup(){
  return true;
}

bool BNO055Wrapper::read_data(float* output, uint8_t size) {

  _bno1.getEvent(&_event, Adafruit_BNO055::VECTOR_LINEARACCEL);
  output[0] = _event.acceleration.x; output[1] = _event.acceleration.y; output[2] = _event.acceleration.z;
  _bno1.getEvent(&_event, Adafruit_BNO055::VECTOR_GYROSCOPE);
  output[3] = _event.gyro.x; output[4] = _event.gyro.y; output[5] = _event.gyro.z;
  _bno1.getEvent(&_event, Adafruit_BNO055::VECTOR_MAGNETOMETER);
  output[6] = _event.magnetic.x; output[7] = _event.magnetic.y; output[8] = _event.magnetic.z;
  
  _bno2.getEvent(&_event, Adafruit_BNO055::VECTOR_LINEARACCEL);
  output[9] = _event.acceleration.x; output[10] = _event.acceleration.y; output[11] = _event.acceleration.z;
  _bno2.getEvent(&_event, Adafruit_BNO055::VECTOR_GYROSCOPE);
  output[12] = _event.gyro.x; output[13] = _event.gyro.y; output[14] = _event.gyro.z;
  _bno2.getEvent(&_event, Adafruit_BNO055::VECTOR_MAGNETOMETER);
  output[15] = _event.magnetic.x; output[16] = _event.magnetic.y; output[17] = _event.magnetic.z;

_bno3.getEvent(&_event, Adafruit_BNO055::VECTOR_LINEARACCEL);
  output[18] = _event.acceleration.x; output[19] = _event.acceleration.y; output[20] = _event.acceleration.z;
    _bno3.getEvent(&_event, Adafruit_BNO055::VECTOR_GYROSCOPE);
  output[21] = _event.gyro.x; output[22] = _event.gyro.y; output[23] = _event.gyro.z;    
  _bno3.getEvent(&_event, Adafruit_BNO055::VECTOR_MAGNETOMETER);
  output[24] = _event.magnetic.x; output[25] = _event.magnetic.y; output[26] = _event.magnetic.z;

  return true;
}
