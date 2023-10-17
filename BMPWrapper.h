#ifndef BMP_WRAPPER_H
#define BMP_WRAPPER_H

#include <Wire.h>
#include <SparkFun_BMP581_Arduino_Library.h>

#include "SensorWrapper.h"

#define OUTPUT_PER_BMP 2
#define SENSORS_PER_BMP_WRAPPER 3
#define BMP_DATA_SIZE 6

class BMP581Wrapper : public virtual SensorWrapper {
private:
    BMP581 _bmp1;
    BMP581 _bmp2;
    BMP581 _bmp3;
public:
    BMP581Wrapper() : SensorWrapper() {}
    bool init() override;
    bool setup() override;
    bool read_data(float* output, uint8_t size) override;
};

#endif