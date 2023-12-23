#include "mbed.h"
#include "Adafruit_SSD1306.h"

#define SDA PB_14
#define SCL PB_13
#define addr 0x78

I2C magistrala(SDA, SCL);
Adafruit_SSD1306_I2c ekran(magistrala, PA_5, addr, 64, 128);
AnalogIn pot1(PA_0);

int main() {
    while(1) {
        ekran.clearDisplay();
        int procenat = 100 * pot1.read();
        ekran.setTextCursor(0, 0);
        ekran.printf("Hello world! \n Vrednost: %d", procenat);
        ekran.display();
        ThisThread::sleep_for(10ms);
    }
    return 0;
}
