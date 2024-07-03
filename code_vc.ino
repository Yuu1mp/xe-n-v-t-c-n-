// Khai báo các chân kết nối
const int trigPin = 3;
const int echoPin = 4;

const int in1 = 6;
const int in2 = 7;

const int in3 = 8;
const int in4 = 9;

// Hàm đo khoảng cách từ cảm biến siêu âm
long readUltrasonicDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;  // Tính khoảng cách bằng cm
}

// Hàm để động cơ di chuyển tiến
void moveBackward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
 
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
}

void moveForward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
 
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
}
void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}
void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  
  digitalWrite(in3,LOW);
  digitalWrite(in4, HIGH);
  
}
void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
 
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
 
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long distance = readUltrasonicDistance();
  Serial.println(distance);
  if (distance < 20) {  // nếu khoảng cách nhỏ hơn 20 cm, tránh vật cản
    stopMotors();
    delay(500);
    moveBackward();
    delay(500);
    stopMotors();
    delay(500);
    turnRight();
    delay(500);
  } else {
    moveForward();
  }
  delay(100);
}
