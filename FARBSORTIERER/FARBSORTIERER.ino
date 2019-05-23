const int s0 = 8; //Verbindung der Farbsensorkontakte mit dem Arduino festlegen

const int s1 = 9;

const int s2 = 12;

const int s3 = 11;

const int out = 10;

int roteLED = 2; //Verbindung der LEDs mit dem Arduino festlegen

int grueneLED = 3;

int blaueLED = 4;

int rot = 0; //Variablen für LEDs benennen

int gruen = 0;

int blau = 0;

void setup()

{

  Serial.begin(9600); //Serielle Kommunikation starten

  pinMode(s0, OUTPUT); //Die Kontakte des Farbsensors werden als Output oder

  pinMode(s1, OUTPUT); // Input festgelgt

  pinMode(s2, OUTPUT);

  pinMode(s3, OUTPUT);

  pinMode(out, INPUT);

  pinMode(roteLED, OUTPUT); //Die LEDs werden als Output festgelegt

  pinMode(grueneLED, OUTPUT);

  pinMode(blaueLED, OUTPUT);

  digitalWrite(s0, HIGH); //Die vier weißen LEDs am Farbsensor sollen leuchten

  digitalWrite(s1, HIGH);

}

void loop()

{

  color();//Diese Funktion wird am Ende des Codes festgelegt (s.“void color();“)

  Serial.print(" Wert Rot: "); //Auf dem seriellen Monitor soll jeweils „Wert“

  Serial.print(rot, DEC); //mit der entsprechenden Farbe angezeigt

  Serial.print(" Wert Gruen: ");//werden und dahinter der Wert, welcher in der

  Serial.print(gruen, DEC); //void color(); Funktion ausgelesen wurde.

  Serial.print(" Wert Blau: ");

  Serial.print(blau, DEC);

  //Hier folgen die Befehle für die LEDs

  if (rot < blau && rot < gruen && rot < 20) //Wenn der Filterwert für rot //kleiner ist als alle anderen Werte..

  {

    Serial.println(" – (Rote Farbe)"); //..soll “Rote Farbe“ am seriellen //Monitor angezeigt werden und..

    digitalWrite(roteLED, HIGH); //…ie rote LED leuchtet auf, die anderen

    digitalWrite(grueneLED, LOW); //bleiben aus

    digitalWrite(blaueLED, LOW);

  }

  else if (blau < rot && blau < gruen) //Das gleiche bei Blau und Grün

  {

    Serial.println(" – (Blaue Farbe)");

    digitalWrite(roteLED, LOW);

    digitalWrite(grueneLED, LOW);

    digitalWrite(blaueLED, HIGH);

  }

  else if (gruen < rot && gruen < blau)

  {

    Serial.println(" – (Gruene Farbe)");

    digitalWrite(roteLED, LOW);

    digitalWrite(grueneLED, HIGH);

    digitalWrite(blaueLED, LOW);

  }

  else { //Wenn keine Werte vorhanden sind..

    Serial.println(); //..nichts auf dem seriellen Monitor anzeigen und..

  }

  delay(300);

  digitalWrite(roteLED, LOW); //…alle LEDs ausschalten

  digitalWrite(grueneLED, LOW);

  digitalWrite(blaueLED, LOW);

}

void color() //Hier werden die Werte vom Farbsensor ausgelesen und unter den

//entsprechenden Variablen gespeichert

{

  digitalWrite(s2, LOW);

  digitalWrite(s3, LOW);

  rot = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  digitalWrite(s3, HIGH);

  blau = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  digitalWrite(s2, HIGH);

  gruen = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

}
