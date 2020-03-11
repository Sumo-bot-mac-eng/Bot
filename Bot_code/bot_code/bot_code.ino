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
const bool LEFT = 0;
const bool RIGHT = 1;


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
  Serial.begin(9600);
}

void loop() {
//  setMotor(RIGHT, HIGH, LOW, 200);
//  Serial.print(myUltra());
//  Serial.println(" cm");
//  Serial.println(line_sensor());
//  setMotor(RIGHT, HIGH, LOW, 200);
//  delay(500);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 85);
//  Serial.println(digitalRead(12));
//  analogWrite(enB, 200);
//  Serial.print(digitalRead(2));
//  Serial.print(" ");
//  Serial.println(digitalRead(3));
//  delay(500); 
  
  
}

void setMotor(bool side, bool dir1, bool dir2, int speed) //side: left=0, right =1; 
{
  if(side == 0)
  {
    digitalWrite(in1, dir1);
    digitalWrite(in2, dir2);
    analogWrite(enA, speed);
  }
  else
  {
    digitalWrite(in2, dir1);
    digitalWrite(in2, dir2);
    analogWrite(enB, speed);
  }
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

float line_sensor()
{
  int value_A0;
  bool value_D0;
  
  value_A0 = analogRead(IN_A0); // reads the analog input from the IR distance sensor
  value_D0 = digitalRead(IN_D0);// reads the digital input from the IR distance sensor
  return value_A0;

  
  delay(1000);
}

long duration;
int distance;

//call myUltra() in loop
float myUltra()
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
  return distance; //in cm

}
