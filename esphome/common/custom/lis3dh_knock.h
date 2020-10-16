#include "Adafruit_LIS3DH.h"
#include "Adafruit_Sensor.h"
#include "esphome.h"

using namespace esphome;

// Adjust this number for the sensitivity of the 'click' force
// this strongly depend on the range! for 16G, try 5-10
// for 8G, try 10-20. for 4G try 20-40. for 2G try 40-80
#define CLICKTHRESHHOLD 40

// Use data structure according to: https://github.com/matthijskooijman/arduino-dsmr

class Lis3DHKnockKnockSensor : public PollingComponent, public BinarySensor {
 public:
  Lis3DHKnockKnockSensor()
      : PollingComponent(500) {}

  Adafruit_LIS3DH lis3dh = Adafruit_LIS3DH();
  //uint8_t click = 0;

  bool value = 0;
  bool lastPublished = 0;

  void
  setup() override {
    // This will be called by App.setup())
    if (!lis3dh.begin(0x19)) {  // change this to 0x18 for alternative i2c address
      ESP_LOGD("LIS3DH_Custom", "Can't init LIS3DH");
    }
    ESP_LOGD("LIS3DH_Custom", "LIS3DH init success!");

    lis3dh.setRange(LIS3DH_RANGE_2_G);  // 2, 4, 8 or 16 G!
    ESP_LOGD("LIS3DH_Custom", "LIS3DH range is %i G", (2 << lis3dh.getRange()));

    // 0 = turn off click detection & interrupt
    // 1 = single click only interrupt output
    // 2 = double click only interrupt output, detect single click
    // Adjust threshhold, higher numbers are less sensitive
    lis3dh.setClick(2, CLICKTHRESHHOLD);
  }

  void loop() override {
    uint8_t click = lis3dh.getClick();
    /*if (click == 0) {
      return;
    }
    if (!(click & 0x30)) {
      return;
    }*/
    if (click != 0 && (click & 0x30)) {
      ESP_LOGV("LIS3DH_Custom", "Click detected 0x%x", click);
      if (click & 0x10) {
        ESP_LOGD("LIS3DH_Custom", "single click");
      }
      if (click & 0x20) {
        ESP_LOGD("LIS3DH_Custom", "double click");
        value = true;
      }
    }
  }

  void update() override {
    if (value != lastPublished) {
      publish_state(value);
      ESP_LOGD("LIS3DH_Custom", "LIS3DH knock value is %i", this->value);
      value = false;
      lastPublished = value;
    }
  }
};