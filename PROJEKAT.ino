
int a=22;
int b=24;
int c=26;
int d=28;
int e=30;
int f=32;
int g=34;
int pin=36;
int ocitanje_pina;
int zvucnik=38;
int brojac=0;
int pomocna=0;
int prekidac=40;
int ocitanje_prekidaca;
int pomocna1=0;
int dioda=LED_BUILTIN;

void setup() {
  // put your setup code here, to run once:
pinMode(dioda,OUTPUT);
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);
pinMode(pin,INPUT_PULLUP);
pinMode(zvucnik,OUTPUT);
pinMode(prekidac,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

ocitanje_pina=digitalRead(pin);
ocitanje_prekidaca=digitalRead(prekidac);
if (ocitanje_prekidaca==0 && pomocna1==0){
  brojac=0;
  pomocna1=1;
  digitalWrite(dioda,HIGH);
}
if (ocitanje_prekidaca==1 && pomocna1==1){
  pomocna1=0;
  digitalWrite(dioda,LOW);
}


if (ocitanje_pina==0 && pomocna==0){
  brojac++;
  pomocna=1;
  tone(zvucnik,481);
}
if (ocitanje_pina==1 && pomocna==1){
  pomocna=0;
  noTone(zvucnik);
}
if(brojac==0){
  prikazi5();
}
else if(brojac==1){
  prikazi4();
}
else if(brojac==2){
  prikazi3();
}
else if(brojac==3){
  prikazi2();
}
else if(brojac==4){
  prikazi1();
}
else if(brojac==5){
  prikazi0();
  pomocna1=1;
}


delay(50);
}

void prikazi1(){
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void prikazi2(){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}

void prikazi3(){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}

void prikazi4(){
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void prikazi5(){
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void prikazi0(){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
}
