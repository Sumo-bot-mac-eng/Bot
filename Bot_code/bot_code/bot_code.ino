const int in3 = 6;
const int in4 = 7;
const int enB = 10;
const int in2 = 5;
const int in1 = 4;
const int enA = 9;
const int trigPin = 11;
const int echoPin = 12;
const int IN_A0 = A0;
const int IN_D0 = 8;


void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode (IN_A0, INPUT);
  pinMode (IN_D0, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}

//call myMotor() in loop
void myMotor()
{
  
  delay(1000);
  
  digitalWrite(in1, HIGH);//Clockwise Direction 
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);

  delay(1000);
  

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
 
  delay (1000);
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  

}

void line_sensor()
{
  int value_A0;
  bool value_D0;
  
  value_A0 = analogRead(IN_A0); // reads the analog input from the IR distance sensor
  value_D0 = digitalRead(IN_D0);// reads the digital input from the IR distance sensor
  Serial.println(value_A0);

  
  delay(1000);
}

long duration;
int distance;

//call myUltra() in loop
void myUltra()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance in CM: ");
  Serial.println(distance);

}
