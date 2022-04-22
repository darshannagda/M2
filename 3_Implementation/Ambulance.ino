int red1 = 10;
int green1 = 8;
int red2 = 9;
int green2 = 5;
int red3 = 2;
int green3 = 4;
int red4 = 12;
int green4 = 7;
int buzz = 6; 

const int ledpin = 13;
const int soundpin = A4;
const int threshold = 200;
const int threshold1 = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);

  pinMode(red3, OUTPUT);
  pinMode(green3, OUTPUT);

  pinMode(red4, OUTPUT);
  pinMode(green4, OUTPUT);


  pinMode(soundpin, INPUT);
  pinMode(ledpin, OUTPUT);
}
void loop() {
  traffic_light1();
  int soundsens = analogRead(soundpin);
  boolean x = true;
  traffic_light2();
  amb();
  delay(300);
  soundsens = analogRead(soundpin);
  amb();
  delay(300);
  noTone(buzz);

  if (soundsens >= threshold)
  {
    siren_sound();
    amb();
    delay(300);
    amb();
    delay(50);
    noTone(buzz);
    delay(5000);
    digitalWrite(ledpin, LOW);
  }
  else if (x)
  {
    traffic_light2();
  }

  traffic_light3();
  amb();
  delay(300);
  soundsens = analogRead(soundpin);
  amb();
  delay(300);
  noTone(buzz);


  if (soundsens >= threshold)
  {
    siren_sound();
    amb();
    delay(300);
    amb();
    delay(50);
    noTone(buzz);
    delay(5000);
    digitalWrite(ledpin, LOW);
  }
  else if (x)
  {
    traffic_light3();
  }
  traffic_light4();
  amb();
  delay(300);
  soundsens = analogRead(soundpin);
  amb();
  delay(300);
  noTone(buzz);


  if (soundsens >= threshold)
  {
    siren_sound();
    amb();
    delay(300);
    amb();
    delay(50);
    noTone(buzz);
    delay(5000);
    digitalWrite(ledpin, LOW);
  }
  else if (x)
  {
    traffic_light4();
    delay(3000);
  }
}



void traffic_light1()
{
  digitalWrite(green1, HIGH);
  digitalWrite(red1, LOW);

  digitalWrite(green2, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(green3, LOW);
  digitalWrite(red3, HIGH);
  digitalWrite(green4, LOW);
  digitalWrite(red4, HIGH);
  delay(5000);
}
void traffic_light2()
{
  digitalWrite(green3, HIGH);
  digitalWrite(red3, LOW);

  digitalWrite(green2, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(green1, LOW);
  digitalWrite(red1, HIGH);
  digitalWrite(green4, LOW);
  digitalWrite(red4, HIGH);
  delay(3000);
}
void traffic_light3()
{
  digitalWrite(green4, HIGH);
  digitalWrite(red4, LOW);

  digitalWrite(green2, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(green3, LOW);
  digitalWrite(red3, HIGH);
  digitalWrite(green1, LOW);
  digitalWrite(red1, HIGH);
  delay(5000);
}
void traffic_light4()
{
  digitalWrite(green2, HIGH);
  digitalWrite(red2, LOW);

  digitalWrite(green1, LOW);
  digitalWrite(red1, HIGH);
  digitalWrite(green3, LOW);
  digitalWrite(red3, HIGH);
  digitalWrite(green4, LOW);
  digitalWrite(red4, HIGH);
  delay(2000);
}
void siren_sound()
{
  digitalWrite(green1, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(ledpin, HIGH);
  digitalWrite(green2, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(green3, LOW);
  digitalWrite(red3, HIGH);
  digitalWrite(green4, LOW);
  digitalWrite(red4, HIGH);

}


void amb() {
  int i = 0; //This function produces the 3rd siren(AMBULANCE) sound with led transition.
  tone(buzz, 900);
  delay(300);
  tone(buzz, 600);
  delay(300);
  tone(buzz, 900);
  delay(300);
  tone(buzz, 600);
  delay(300);
  tone(buzz, 900);
  delay(300);
  tone(buzz, 600);
  delay(300);
  tone(buzz, 900);
  delay(300);
  tone(buzz, 600);
}
