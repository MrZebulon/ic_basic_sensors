#ifndef BNO_WRAPPER_H
#define BNO_WRAPPER_H

#include <Wire.h>
#include <Adafruit_BNO055.h>

#include "SensorWrapper.h"

#define OUTPUT_PER_BNO 9
#define SENSORS_PER_BNO_WRAPPER 3
#define BNO_DATA_SIZE 27


class BNO055Wrapper : public virtual SensorWrapper {
private:
    Adafruit_BNO055 _bno1 = {-1, 0x28, &WIRE};
    Adafruit_BNO055 _bno2 = {-1, 0x29, &WIRE};
    Adafruit_BNO055 _bno3 = {-1, 0x29, &WIRE2};

    sensors_event_t _event;

public:
    BNO055Wrapper() : SensorWrapper() {}
    bool init() override;
    bool setup() override;
    bool read_data(float* output, uint8_t size) override;

};

#endif