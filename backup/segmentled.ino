#define PIN_DP 6
#define PIN_C 4
#define PIN_D 5
#define PIN_E 7
#define PIN_B 3
#define PIN_A 2
#define PIN_F 8
#define PIN_G 9
int pins[]={PIN_A,PIN_B,PIN_C,PIN_D,PIN_E,PIN_F,PIN_G,PIN_DP};
void setup() {
  Serial.begin(9600);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(PIN_DP, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);
}
void one(){
  digitalWrite(PIN_A,HIGH);
  digitalWrite(PIN_B,LOW);
  digitalWrite(PIN_C,LOW);
  digitalWrite(PIN_D,HIGH);
  digitalWrite(PIN_E,HIGH);
  digitalWrite(PIN_F,HIGH);
  digitalWrite(PIN_G,HIGH);
  digitalWrite(PIN_DP,HIGH);
  delay(1000);
}
void two(){
  digitalWrite(PIN_A,LOW);
  digitalWrite(PIN_B,LOW);
  digitalWrite(PIN_C,HIGH);
  digitalWrite(PIN_D,LOW);
  digitalWrite(PIN_E,LOW);
  digitalWrite(PIN_F,HIGH);
  digitalWrite(PIN_G,LOW);
  digitalWrite(PIN_DP,LOW);
  delay(1000);
}
void three(){
  digitalWrite(PIN_A,LOW);
  digitalWrite(PIN_B,LOW);
  digitalWrite(PIN_C,LOW);
  digitalWrite(PIN_D,LOW);
  digitalWrite(PIN_E,HIGH);
  digitalWrite(PIN_F,HIGH);
  digitalWrite(PIN_G,LOW);
  digitalWrite(PIN_DP,HIGH);
  delay(1000);
}
void reset(){
  digitalWrite(PIN_A,HIGH);
  digitalWrite(PIN_B,HIGH);
  digitalWrite(PIN_C,HIGH);
  digitalWrite(PIN_D,HIGH);
  digitalWrite(PIN_E,HIGH);
  digitalWrite(PIN_F,HIGH);
  digitalWrite(PIN_G,HIGH);
  digitalWrite(PIN_DP,HIGH);
  delay(50);
}
void four(){
  digitalWrite(PIN_A,HIGH);
  digitalWrite(PIN_B,LOW);
  digitalWrite(PIN_C,LOW);
  digitalWrite(PIN_D,HIGH);
  digitalWrite(PIN_E,HIGH);
  digitalWrite(PIN_F,LOW);
  digitalWrite(PIN_G,LOW);
  digitalWrite(PIN_DP,HIGH);
  delay(1000);
}
void five(){
  digitalWrite(PIN_A,LOW);
  digitalWrite(PIN_B,HIGH);
  digitalWrite(PIN_C,LOW);
  digitalWrite(PIN_D,LOW);
  digitalWrite(PIN_E,HIGH);
  digitalWrite(PIN_F,LOW);
  digitalWrite(PIN_G,LOW);
  digitalWrite(PIN_DP,HIGH);
  delay(1000);
}
void six(){
  digitalWrite(PIN_A,LOW);
  digitalWrite(PIN_B,HIGH);
  digitalWrite(PIN_C,LOW);
  digitalWrite(PIN_D,LOW);
  digitalWrite(PIN_E,LOW);
  digitalWrite(PIN_F,LOW);
  digitalWrite(PIN_G,LOW);
  digitalWrite(PIN_DP,HIGH);
  delay(1000);
}
void seven(){
  digitalWrite(PIN_A,LOW);
  digitalWrite(PIN_B,LOW);
  digitalWrite(PIN_C,LOW);
  digitalWrite(PIN_D,HIGH);
  digitalWrite(PIN_E,HIGH);
  digitalWrite(PIN_F,HIGH);
  digitalWrite(PIN_G,HIGH);
  digitalWrite(PIN_DP,HIGH);
  delay(1000);
}
void eight(){
  digitalWrite(PIN_A,LOW);
  digitalWrite(PIN_B,LOW);
  digitalWrite(PIN_C,LOW);
  digitalWrite(PIN_D,LOW);
  digitalWrite(PIN_E,LOW);
  digitalWrite(PIN_F,LOW);
  digitalWrite(PIN_G,LOW);
  digitalWrite(PIN_DP,LOW);
  delay(1000);
}
void nine(){
  digitalWrite(PIN_A,LOW);
  digitalWrite(PIN_B,LOW);
  digitalWrite(PIN_C,LOW);
  digitalWrite(PIN_D,LOW);
  digitalWrite(PIN_E,HIGH);
  digitalWrite(PIN_F,LOW);
  digitalWrite(PIN_G,LOW);
  digitalWrite(PIN_DP,LOW);
  delay(1000);
}
void zero(){
  digitalWrite(PIN_A,LOW);
  digitalWrite(PIN_B,LOW);
  digitalWrite(PIN_C,LOW);
  digitalWrite(PIN_D,LOW);
  digitalWrite(PIN_E,LOW);
  digitalWrite(PIN_F,LOW);
  digitalWrite(PIN_G,HIGH);
  digitalWrite(PIN_DP,LOW);
  delay(1000);
}
int number=0;
void loop() {
  int state=digitalRead(12);
  if (state==1){
    Serial.println("First Pressed");
    switch(number){
      case 0:
        zero();
        number++;
        break;
      case 1:
        one();
        number++;
        break;
      case 2:
        two();
        number++;
        break;
      case 3:
        three();
        number++;
        break;
      case 4:
        four();
        number++;
        break;
      case 5:
        five();
        number++;
        break;
      case 6:
        six();
        number++;
        break;
      case 7:
        seven();
        number++;
        break;
      case 8:
        eight();
        number++;
        break;
      case 9:
        nine();
        number++;
        break;
      case 10:
        number=0;
    }
    delay(100);
    reset();
  }
  int secondstate=digitalRead(13);
  if (secondstate==1){
    Serial.println("Second Pressed");
    switch(number){
      case 0:
        zero();
        break;
      case 1:
        zero();
        number--;
        break;
      case 2:
        one();
        number--;
        break;
      case 3:
        two();
        number--;
        break;
      case 4:
        three();
        number--;
        break;
      case 5:
        four();
        number--;
        break;
      case 6:
        five();
        number--;
        break;
      case 7:
        six();
        number--;
        break;
      case 8:
        seven();
        number--;
        break;
      case 9:
        eight();
        number--;
        break;
  }
  delay(100);
  reset();
  }
  int thirdstate=digitalRead(11);
  if (thirdstate==1){
    Serial.println("Reset Pressed");
    number=0;
    reset();
    delay(100);
  }
  }
