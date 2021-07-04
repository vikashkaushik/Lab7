/*
 * Project Lab7
 * Description: uses tmp36 reader it displays temperature on oled. and when I press A, it sends push notification on blynk app.
 * Author: Vikash Kaushik
 * Date: 7/4/21
 */
SYSTEM_THREAD(ENABLED);
#include <blynk.h>
#include "oled-wing-adafruit.h"
OledWingAdafruit display;
// setup() runs once, when the device is first turned on.
void setup() {
  pinMode(A4, INPUT); // initiallizes tmp36
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
  
  //reads the values of the tmp and prints it in C and F
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
    Blynk.notify("Hey, got a push notification!"); // sends notification to Blynk app
		display.println("Push Sent"); //displays message for 5 sec on screen
    display.display();
    delay(5000);
    
		
  }



  

} 
