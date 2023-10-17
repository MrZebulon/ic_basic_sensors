#include "BMPWrapper.h"
#include "BNOWrapper.h"

BMP581Wrapper bmps = BMP581Wrapper();
BNO055Wrapper bnos = BNO055Wrapper();

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(100);  // wait for native usb
  
  WIRE.begin();
  WIRE2.begin();

  if (!bmps.init()) {
    Serial.println("Oops... One of the pressure sensors could nout be dectected");
    while (1) delay(10);
  }

  if (!bnos.init()) {
    Serial.println("Oops... One of the IMU sensors could nout be dectected");
    while (1) delay(10);
  }
}

float bmps_data[BMP_DATA_SIZE] = {0};
float bnos_data[BNO_DATA_SIZE] = {0};

// Prints acc (x,y,z) * 3, gyro (x,y,z) * 3,  pressure x3, temp x3
void loop() {
  bnos.read_data(bnos_data, BNO_DATA_SIZE);
  bmps.read_data(bmps_data, BMP_DATA_SIZE);
  
  //imu1
  for (uint8_t i = 0; i < 9; i++)
      Serial.printf("%.4f, ", bnos_data[i]);
  
  //imu2
  for (uint8_t i = 9; i < 18; i++)
      Serial.printf("%.4f, ", bnos_data[i]);

  //imu3
  for (uint8_t i = 18; i < 27; i++)
      Serial.printf("%.4f, ", bnos_data[i]);

  //pressures
  for (uint8_t i = 0; i < 3; i++)
    Serial.printf("%.4f, ", bmps_data[i]);

  //temp
  for (uint8_t i = 3; i < 6; i++)
    Serial.printf("%.4f, ", bmps_data[i]);

  Serial.print("\n");
}