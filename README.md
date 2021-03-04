# esphome-config
Modularised ESPHome configurations with substitutions and packages

- :red_circle: Not (yet) updated to new modular config system
- :white_check_mark: Ready for use config
- :eight_spoked_asterisk: Ready for use config for DIY circuit
## Devices
<details><summary>:red_circle: LCS Power plug</summary>

(Store: Action)([info](https://templates.blakadder.com/lsc_smart_connect_power_plug.html))

- GPIO04 = LED (inverted)
- GPIO12 = Relay
- GPIO13 = Button (input pullup)
</details>

<details><summary>:red_circle: TTGO Tcamera v05</summary>

(Store: Aliexpress)([info](https://github.com/lewisxhe/esp32-camera-series/blob/master/schematic/OV2640_V05.pdf))

- SSD1306 (0x3C)
    - GPIO21 = SDA
    - GPIO22 = SCL
- Battery charger ([info](https://datasheet.lcsc.com/szlcsc/1809201029_INJOINIC-IP5306_C181692.pdf))
    - GPIO02 = LED3 (not connected?)
    - GPIO21 = LED2
    - GPIO22 = LED1
- Camera
    - GPIO05 = Y2
    - GPIO14 = Y3
    - GPIO04 = Y4
    - GPIO15 = Y5
    - GPIO18 = Y6
    - GPIO23 = Y7
    - GPIO36 = Y8
    - GPIO39 = Y9
    - GPIO27 = VSNC
    - GPIO25 = HREF
    - GPIO19 = PLCK
    - GPIO26 = PWD
    - GPIO32 = XCLK/External_clock
    - GPIO13 = SIOD/SDA
    - GPIO12 = SIOC/SCL
- Other
    - GPIO33 = PIR
    - GPIO34 = Button (input pullup)
    - GPIO35 = VBatt (100k/100k) (ADC1_CH7) (11dB) 1.65v = 0%, 2.10v = 100%
</details>

<details><summary>:red_circle: Emil's Slimmer dimmer</summary>

(Store: Emil)([info](https://github.com/EmilFlach/slimmer_dimmer_v2))

- GPIO02 = LED (inverted)
- GPIO05 = Rotary encoder switch (external input pullup)
- GPIO14 = Rotary encoder A (external input pullup)
- GPIO12 = Rotary encoder B (external input pullup)
- GPIO13 = 24x WS2812B
- GPIO00 = Switch (external input pullup)
</details>

<details><summary>:eight_spoked_asterisk: ESP32 P1 DSMR</summary>

(Store: Ruben)([info](https://github.com/Mynasru/))

- :red_circle: To do
</details>

<details><summary>:red_circle: Alarm clock</summary>

(Store: Ruben)([info](https://github.com/Mynasru/))
Based on the ESP32 P1 board

- 
</details>

<details><summary>:white_check_mark: TTGO T-HiGrow V1.1</summary>

(Store: Aliexpress)([info](https://aliexpress.com/item/32962409404.html))

[Schematic](https://github.com/Xinyuan-LilyGO/TTGO-HiGrow/raw/master/schematic.pdf)

- GPIO25 = SDA (Bus A)
- GPIO26 = SCK (Bus A)
- GPIO04 = Power enable for sensors
- GPIO35 = Wake button
- GPIO16 = DHT11
- GPIO33 = Battery ADC
- GPIO32 = Soil humidity ADC
- GPIO34 = Soil salt ADC
</details>

<details><summary>:eight_spoked_asterisk: Air quality sensors [DIY]</summary>

Measure:
- eCO2
- eVOC
- Temperature (2x)
- Humidity
- Pressure
- PM (µm): 1, 2.5, 10
</details>