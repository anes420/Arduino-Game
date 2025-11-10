// Code written by anesss

int A = 12;
int B = 2;
int C = 3;
int D = 4;
int E = 5;
int F = 6;
int G = 7;

int greenLED=13;
int blueLED=1;

int zvucnik = 8;
int coin = 9;
int zica = 10;
int button = 11;

int ocitanjePB;
int coinInsert;
int ocitanjeMaster;
int stanjeZelena=0;

int i=0;
int i2=0;
int iMaster=0;

int pomocna=0;
int pomocna1=0;
int pomocnaMaster=0;

bool state = false; // false = green OFF, true = green ON
bool lastButton = LOW;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;



void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(zvucnik, OUTPUT);
  pinMode(zica, INPUT_PULLUP);
  pinMode(coin, INPUT_PULLUP);
  pinMode(button, INPUT_PULLUP);

  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  digitalWrite(greenLED, LOW);
}


void loop() {

  ocitanjePB=digitalRead(zica);
  coinInsert=digitalRead(coin);

// // MASTER gpt
   bool reading = !digitalRead(button); // button pressed = HIGH (since using pull-up)

  if (reading != lastButton) {
    lastDebounceTime = millis();
  }

  // simple debounce
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading) { // button is held
      blinkBlue(3);          // blink 3 times before toggle
      state = !state;        // toggle state
      digitalWrite(greenLED, state ? HIGH : LOW);
      while (digitalRead(button) == LOW) {
        // wait for release
      }
      delay(20); // small delay after release
    }
  }

  lastButton = reading;



  if(coinInsert==0 && pomocna1==0 && state==1) {
    i=5;
    pomocna1=1;
  }

  if(coinInsert==1 && pomocna1==1 && state==1) {
    pomocna1=0;
    delay(20);
  }


    if(ocitanjePB==0 && pomocna==0 && state==1 && i>0) {
      i--;
      pomocna=1;
      tone(zvucnik, 420);
      }

    if(ocitanjePB==1 && pomocna==1 && state==1) {
      pomocna=0;
      noTone(zvucnik);
      }


    if(state==0) {
      none();
    }  
    if(i==5 && state==1) {
      prikazi5();
    }

    else if(i==4 && state==1) {
      prikazi4();
    }

    else if(i==3 && state==1) {
      prikazi3();
    }

    else if(i==2 && state==1) {
      prikazi2();
    }

    else if(i==1 && state==1) {
      prikazi1();
    }

    // a f g c d e g b

    else if(i==0 && state==1){
      digitalWrite(A, HIGH);
      delay(100);
      digitalWrite(A, LOW);
    
      digitalWrite(F, HIGH);
      delay(100);
      digitalWrite(F, LOW);

      digitalWrite(G, HIGH);
      delay(100);
      digitalWrite(G, LOW);

      digitalWrite(C, HIGH);
      delay(100);
      digitalWrite(C, LOW);

      digitalWrite(D, HIGH);
      delay(100);
      digitalWrite(D, LOW);

      digitalWrite(E, HIGH);
      delay(100);
      digitalWrite(E, LOW);

      digitalWrite(G, HIGH);
      delay(100);
      digitalWrite(G, LOW);

      digitalWrite(B, HIGH);
      delay(100);
      digitalWrite(B, LOW);


    }
  delay(20);
  
}

void blinkBlue(int times) {
  for (int i = 0; i < times; i++) {
    delay(200);
    digitalWrite(blueLED, HIGH);
    delay(200);
    digitalWrite(blueLED, LOW);
  }
}

void none() {
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
}

void prikazi0() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void prikazi1() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void prikazi2() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void prikazi3() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void prikazi4() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void prikazi5() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void prikazi6() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void prikazi7() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void prikazi8() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void prikazi9() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
