
const int enA = 7; //Enable A motor pin
const int in1 = 5; //Set CW pin to 5
const int in2 = 6; //Set CCW pin to 6

void myMotor();

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  myMotor(); 

}
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
