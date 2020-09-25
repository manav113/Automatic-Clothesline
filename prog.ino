#define OutputDO 8 //nama alias pin 8 yaitu output DO
int Ldr = A1;  //inisialisasi 
int ldr;
int en1= 6; //inisialisasi en1 masuk pwm yaitu 6
int en2= 5; //inisialisasi en2 masuk pwm yaitu 5
int in1= 2;  //inisialisasi pin input1/in1 masuk pin 13
int in2= 12;  //inisialisasi pin input2/in2 masuk pin 12
int in3= 11;  //inisialisasi pin input3/in3 masuk pin 11
int in4= 10;  //inisialisasi pin input4/in4 masuk pin 10

int OutputAO=A0; //nama alias pin AO yaitu Output AO
int Led=13; //nama alias pin 13 yaitu LED


int val;//val sebagai buffer data
float sensor; //sebagai data buffer sensor

void setup() {
  pinMode(en1, OUTPUT); //pin en1 sebagai OUTPUT
  pinMode(en2, OUTPUT); //pin en2 sebagai OUTPUT
  pinMode(in1, OUTPUT); //pin in1 sebagai OUTPUT
  pinMode(in2, OUTPUT); //pin in2 sebagai OUTPUT
  pinMode(in3, OUTPUT); //pin in3 sebagai OUTPUT
  pinMode(in4, OUTPUT); //pin in4 sebagai OUTPUT

pinMode (Led, OUTPUT) ; //Defisini LED sebagai output
pinMode (OutputDO, INPUT) ; //Defisini OutputDO sebagai input
pinMode (OutputAO, INPUT) ; //Defisini OutputAO sebagai input
pinMode (ldr, INPUT);

//inisialisasi komunikasi serial
Serial.begin(9600);
  
}

void hujan(){
  digitalWrite (Led, HIGH);

  analogWrite(en1,125);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  analogWrite(en2,125);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);

  Serial.println("mundur");
  
}
void mendung(){
  digitalWrite (Led, HIGH);

  analogWrite(en1,125);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  analogWrite(en2,125);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);

  Serial.println("mundur");
}
void terang(){
  digitalWrite (Led, LOW);

  analogWrite(en1,125);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  analogWrite(en2,125);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);

  Serial.println("maju");
}
void mati(){
  analogWrite(en1,0);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);

  analogWrite(en2,0);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

  Serial.println("mati");
  delay(5000);
}

void loop() {
sensor = analogRead(OutputAO);//Pembacaan nilai sensor
Serial.println(sensor); //hasil akan ditampilkan di serial monitor

ldr = analogRead(A1);
Serial.print("ldr : ");
Serial.println(ldr);
//pembacaan nilai sensor (logika 1 dan 0)
val = digitalRead (OutputDO);

//Pengondisian
 if (ldr <= 250 )  
 {
  if (sensor <=500)
    //lampu led akan menyala
   
    hujan(); delay(500);
    mati(); delay(5000);
   
 }

 else if(ldr <= 250 ){
  if (sensor > 500){
   mendung(); delay(400);
   mati(); delay(5000);
 }
 }
 
else if(ldr >= 250 ){
  if (sensor > 500){
   terang(); delay(10 00);
   mati(); delay(5000);
 }
 }
}
