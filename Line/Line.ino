
const int QRD1114_PIN = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(QRD1114_PIN, INPUT);
}

void loop() { 
  // put your main code here, to run repeatedly:
  int proximityADC = analogRead(QRD1114_PIN);
  float proximityV = (float)proximityADC * 5.0 / 1023.0;
  Serial.println(proximityV);  
  delay(1000);
} 
