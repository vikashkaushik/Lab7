/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Vikash/Downloads/Lab7/src/Lab7.ino"
/*
 * Project Lab7
 * Description:
 * Author:
 * Date:
 */
void setup();
void loop();
#line 7 "c:/Users/Vikash/Downloads/Lab7/src/Lab7.ino"
SYSTEM_THREAD(ENABLED);
#include <blynk.h>
#include "oled-wing-adafruit.h"
OledWingAdafruit display;
// setup() runs once, when the device is first turned on.
void setup() {
  pinMode(A4, INPUT);
  // Put initialization like pinMode and begin functions here.
  
  display.display();  // cause the display to be updated
  display.clearDisplay();
  display.setup();
  Serial.begin(9600); 
  Blynk.begin("6YMH4FOd4ISmYITAH3retloWQyMTcCOJ", IPAddress(167, 172, 234, 162), 9090); 
}
// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  Blynk.run();
  display.loop();
  
  
  uint64_t reading = analogRead(A4);
  double voltage = (reading * 3.3) / 4095.0;
  double temperature = (voltage - 0.5) * 100;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print(temperature); // prints temp in C
  display.println(" C");
  display.print(voltage*100); // prints temp in F
  display.println(" F");
  display.display();  // cause the display to be updated
  Serial.println(temperature); 
  Serial.println(voltage*100); 

  if (display.pressedA()) {
		display.clearDisplay();
    Blynk.notify("Hey, got a push notification!");
		display.println("Push Sent");
    display.display();
    delay(5000);
    
		
  }



  

} 
