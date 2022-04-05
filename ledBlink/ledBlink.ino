float max = 1;
float min = -1;

float value = min;
float valueChange = 0.1;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //float valueSin = sin(value);

  led(value);

  value += valueChange;

  if(value <= min || value >= max){
    valueChange = -valueChange;
  }
}

void led(float valueSin){

  float valueSinMap = map(valueSin * 100, -100, 100, 100, 1000);

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(valueSinMap);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(valueSinMap);

  Serial.println(valueSin);
  Serial.println(valueSinMap);
}
