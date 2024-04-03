#define BAUD 256000
#define delayTime 100

float read0 = A0;
float read1 = A1;
float read2 = A2;
float read3 = A3;
float read4 = A4;
float read5 = A5;

float V0 = 0;
float V1 = 0;
float V2 = 0;
float V3 = 0;
float V4 = 0;
float V5 = 0;

bool receive_flag = true;
bool send_flag = false;
char char_flag = 'n';

void setup() {
  // put your setup code here, to run once:

  pinMode(read0, INPUT);
  pinMode(read1, INPUT);
  pinMode(read2, INPUT);
  pinMode(read3, INPUT);
  pinMode(read4, INPUT);
  pinMode(read5, INPUT);

  Serial.begin(BAUD);
}

void loop() {
  // put your main code here, to run repeatedly:

  V0 = analogRead(read0) * (3.3 / 1023);
  V1 = analogRead(read1) * (3.3 / 1023);
  V2 = analogRead(read2) * (3.3 / 1023);
  V3 = analogRead(read3) * (3.3 / 1023);
  V4 = analogRead(read4) * (3.3 / 1023);
  V5 = analogRead(read5) * (3.3 / 1023);

  if (receive_flag == true && Serial.available() > 0) {
    char_flag = Serial.read();
    if (char_flag == 'x') {
      receive_flag = false;
    }
  }

  else if (receive_flag == false) {

    Serial.print(V0, 2);
    Serial.print(",");
    Serial.print(V1, 2);
    Serial.print(",");
    Serial.print(V2, 2);
    Serial.print(",");
    Serial.print(V3, 2);
    Serial.print(",");
    Serial.print(V4, 2);
    Serial.print(",");
    Serial.println(V5, 2);
    receive_flag = true;
  }

  //delay(delayTime);
}
