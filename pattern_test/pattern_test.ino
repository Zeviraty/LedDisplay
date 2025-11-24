#include <SPI.h>
#include "hal/gpio_ll.h"
#include <PxMatrix.h>

#define P_LAT 22
#define P_A 19
#define P_B 23
#define P_C 18
#define P_D 5
#define P_E 15
#define P_OE 2
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

// Pins for LED MATRIX

//PxMATRIX display(32,16,P_LAT, P_OE,P_A,P_B,P_C);
//PxMATRIX display(64,32,P_LAT, P_OE,P_A,P_B,P_C,P_D);
PxMATRIX display(64,64,P_LAT, P_OE,P_A,P_B,P_C,P_D,P_E);

int c = 0;

void IRAM_ATTR display_updater(){
  // Increment the counter and set the time of ISR
  portENTER_CRITICAL_ISR(&timerMux);
  //isplay.display(70);
  //display.displayTestPattern(70);
  display.drawPixelRGB888(c%64, c/64, c%255, c%255, c%255);
  display.display();
  c ++;
  portEXIT_CRITICAL_ISR(&timerMux);
}

uint16_t myCYAN = display.color565(0, 255, 255);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  display.begin(32);
  display.flushDisplay();
  display.setTextColor(myCYAN);
  display.setCursor(2,0);
  display.print("Pixel");
  Serial.println("hello");

  timer = timerBegin(250000);
  timerAttachInterrupt(timer, &display_updater);
  timerAlarm(timer, 1000, true, 0);

  delay(1000);
}


void loop() {

 delay(100);

}
