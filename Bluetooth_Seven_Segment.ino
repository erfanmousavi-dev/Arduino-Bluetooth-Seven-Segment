#include <SoftwareSerial.h>
SoftwareSerial bt(10,9); // RX TX It's Reversed...

// 7-Segment pins and diagram on how to connect

int a = 2;   //     a
int b = 3;   // f       b
int c = 4;   //     g
int e = 6;   // e       c
int d = 5;   //     d
int f = 7;
int g = 8;

void show_num(int x) {
  
  allOff();
  
  switch(x) {
    case 0:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      break;
      
    case 1:
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      break;
      
    case 2:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(g, LOW);
      break;
      
    case 3:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(g, LOW);
      break;
      
    case 4:
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
      
    case 5:
      digitalWrite(a, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
      
    case 6:
      digitalWrite(a, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
      
    case 7:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      break;
      
    case 8:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
      
    case 9:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
      
    default:
      allOff();
      break;
  }
}

void allOff() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  if(bt.available()){
    char data = bt.read();
    Serial.println("\n Reacived  :\n");
    Serial.println(data);
    if(data == '1'){
      show_num(1);
    }
    else if (data == '2'){
      show_num(2);
    }
    else if (data == '3'){
      show_num(3);
    }
    else if (data == '4'){
      show_num(4);
    }
    else if (data == '5'){
      show_num(5);
    }
    else if (data == '6'){
      show_num(6);
    }
    else if (data == '7'){
      show_num(7);
    }
    else if (data == '8'){
      show_num(8);
    }
    else if (data == '9'){
      show_num(9);
    }
    else {
      allOff();
    }
  }
}