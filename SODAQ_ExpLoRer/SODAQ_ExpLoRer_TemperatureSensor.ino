

#define debugSerial SerialUSB

void setup() {
  //block till serial monitor is opened
  while(!debugSerial);

  //begin usb serial
  debugSerial.begin(57600);

  //define temperature pin as input
  pinMode(TEMP_SENSOR, INPUT);
}

void loop() {
  //10mV per C, 0C is 500mV
  float mVolts = (float)analogRead(TEMP_SENSOR) * 3300.0 / 1023.0;
  float temp = (mVolts - 500.0) / 10.0;

  debugSerial.print(temp);
  debugSerial.println(" C");

  delay(1000);
}


