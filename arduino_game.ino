// Code written by anesss

int A = 12;
int B = 2;
int C = 3;
int D = 4;
int E = 5;
int F = 6;
int G = 7;

int zelena=13;
int plava=1;

int zvucnik = 8;
int coin = 9;
int zica = 10;
int master = 11;

int ocitanjePB;
int coinInsert;
int ocitanjeMaster;
int stanjeZelena=0;

int i=-1;
int i2=0;

int pomocna=0;
int pomocna1=0;
int pomocna2=0;


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
  pinMode(master, INPUT_PULLUP);

  pinMode(zelena, OUTPUT);
  pinMode(plava, OUTPUT);

  digitalWrite(zelena, LOW);
}


void loop() {

  ocitanjePB=digitalRead(zica);
  coinInsert=digitalRead(coin);
  ocitanjeMaster=digitalRead(master);

// MASTER
  if(ocitanjeMaster==0) {
    delay(50);
    while(i2<=2) {
      digitalWrite(plava, HIGH);
      delay(200);
      digitalWrite(plava, LOW);
      delay(200);
      i2++;
    }
    if(i2==3) {
      digitalWrite(zelena, HIGH);
      stanjeZelena=1;
      pomocna2=1;
      i2=0;
    }
  if(ocitanjeMaster==0 && pomocna2==1)
    if(ocitanjeMaster==0 && pomocna2==1) {
      while(i2<=2) {
        digitalWrite(plava, HIGH);
        delay(200);
        digitalWrite(plava, LOW);
        delay(200);
        i2++;
        }
        if(i2>=3) {
          digitalWrite(zelena, LOW);
          stanjeZelena=0;
          pomocna2=0;
        }
    }


  }
  //KRAJ MASTERA


  if(coinInsert==0 && pomocna1==0 && stanjeZelena==1) {
    i=5;
    pomocna1=1;
  }

  if(coinInsert==1 && pomocna1==1) {
    pomocna1=0;
    delay(20);
  }


    if(ocitanjePB==0 && pomocna==0 && stanjeZelena==1) {
      i--;
      pomocna=1;
      tone(zvucnik, 420);
      }

    if(ocitanjePB==1 && pomocna==1) {
      pomocna=0;
      noTone(zvucnik);
      }

    if(i==5) {
      prikazi5();
    }

    else if(i==4) {
      prikazi4();
    }

    else if(i==3) {
      prikazi3();
    }

    else if(i==2) {
      prikazi2();
    }

    else if(i==1) {
      prikazi1();
    }

    // a f g c d e g b

    else if (i==0) {
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


