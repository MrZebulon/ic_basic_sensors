#ifndef SENSORS_WRAPPER_H
#define SENSORS_WRAPPER_H

typedef unsigned char uint8_t;

#define WIRE Wire
#define WIRE2 Wire2

class SensorWrapper {
public:
  virtual bool init() = 0;
  virtual bool setup() = 0;
  virtual bool read_data(float* output, uint8_t size) = 0;

};

#endif