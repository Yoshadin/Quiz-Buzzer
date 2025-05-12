/* 

Code completed on 16-03-2025 21:35 pm IST.

You are free to use the code anyhow you want, but please try to keep this comment attached. It means a lot to me.

  _____  _____ _______ _    _ _____ _   _ 
 |  __ \|_   _|__   __| |  | |_   _| \ | |
 | |__) | | |    | |  | |__| | | | |  \| |
 |  _  /  | |    | |  |  __  | | | | . ` |
 | | \ \ _| |_   | |  | |  | |_| |_| |\  |
 |_|  \_\_____|  |_|  |_|  |_|_____|_| \_|

Support me 

Github - https://github.com/RithinM69

*/


const int mButton = 11;

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;

const int buzzer1 = 5;
const int buzzer2 = 6;
const int buzzer3 = 7;

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

boolean button1Pressed = false;
boolean button2Pressed = false;
boolean button3Pressed = false;

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  
  pinMode(mButton, INPUT_PULLUP);

  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);
  Serial.println("Starting");
}

void stop(){
  Serial.println("Round Over");
  delay(500);
  return 0;
}

void answer1() {
    Serial.print("\nBtn 1");
    button1Pressed = true;
    digitalWrite(buzzer1, HIGH);
    digitalWrite(led1, HIGH);
    delay(1000); // buzz for 1 second
    digitalWrite(buzzer1, LOW);
    digitalWrite(led1, LOW);
    
    stop();
}
void answer2(){
    Serial.print("\nBtn 2");
    button2Pressed = true;
    digitalWrite(buzzer2, HIGH);
    digitalWrite(led2, HIGH);
    delay(1000); // buzz for 1 second
    digitalWrite(buzzer2, LOW);
    digitalWrite(led2, LOW);
    stop();
}
void answer3(){
    Serial.print("\nBtn 3");
    button3Pressed = true;
    digitalWrite(buzzer3, HIGH);
    digitalWrite(led3, HIGH);
    delay(1000); // buzz for 1 second
    digitalWrite(buzzer3, LOW);
    digitalWrite(led3, LOW);
    stop();
}

  // reset after 10 seconds
void reset(){
  button1Pressed = false;
  button2Pressed = false;
  button3Pressed = false;
}

void loop(){
    if(digitalRead(mButton)== LOW){
      reset();
      if (digitalRead(button1) == LOW && !button1Pressed) {
        answer1();
      }
      if (digitalRead(button2) == LOW && !button2Pressed){
        answer2();
      }
      if (digitalRead(button3) == LOW && !button3Pressed){
        answer3();
      }
    }
}
