const int trigPin = PG11;
const int echoPin = PG10;
const int buzzerPin = PE2;
const int LEDpin = PG13;
//const int buttonPin = PA0;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(LEDpin, OUTPUT);
  
  digitalWrite(LEDpin, HIGH);
  
}

void loop() {
  long mesafe = mesafeOlc();

  if(mesafe<25) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(LEDpin, HIGH);
    } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(LEDpin, LOW);
    }
    
  delay(50);
}

long mesafeOlc() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long sure = pulseIn(echoPin, HIGH);

  long mesafe = sure / 2 * 0.0343;

  return mesafe;
}
