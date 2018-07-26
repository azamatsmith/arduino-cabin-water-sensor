#define VALVE_PIN 4 
#define TOP_SENSOR 5 
#define BOTTOM_SENSOR 6 
#define ACTIVE_LED_PIN 8 // Green LED 
#define POWER_LED_PIN 9  // Red LED


bool valveOpen = false;
int bottomLevel = 0;
int topLevel = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BOTTOM_SENSOR,INPUT);
  pinMode(ACTIVE_LED_PIN,OUTPUT);
  pinMode(POWER_LED_PIN,OUTPUT);
  pinMode(TOP_SENSOR,INPUT);
  pinMode(VALVE_PIN, OUTPUT); 
  digitalWrite(POWER_LED_PIN,HIGH);
}

void closeValve() {
  valveOpen = false;
  digitalWrite(VALVE_PIN, LOW);
  /* Serial.println("Valve Closed"); */
}

void openValve() {
  valveOpen = true;
  digitalWrite(VALVE_PIN, HIGH);
  /* Serial.println("Valve Opened"); */
}

void loop() {
  bottomLevel=digitalRead(BOTTOM_SENSOR);
  topLevel=digitalRead(TOP_SENSOR);

  if (topLevel == 1 && valveOpen) {
    closeValve();
    digitalWrite(ACTIVE_LED_PIN,LOW);
  }

  else if (topLevel == 0 && bottomLevel == 0 && !valveOpen) {
    openValve();
    digitalWrite(ACTIVE_LED_PIN,HIGH);
  }
  delay(500);
}
