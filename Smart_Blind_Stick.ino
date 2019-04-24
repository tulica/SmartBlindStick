const int trig = 11;
const int echo = 12;
const int buzz = 3;
const int lightPin = 7;

long int time_taken;
int dist;
int light;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzz, OUTPUT);

}

/*Calculating Distance from Sensor*/
void calculate_distance(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  time_taken = pulseIn(echo, HIGH);
  dist = time_taken * 0.034 / 2;
  if (dist > 300)
    dist = 300;
}

void loop() {
  // put your main code here, to run repeatedly:

  calculate_distance(trig, echo);
  light = analogRead(lightPin);

  /*Intensity*/
  if (light < 200)
  {
    Serial.print(light);
    Serial.println("Bright");

    digitalWrite(buzz, HIGH);
    delay(200);
    digitalWrite(buzz, LOW);
    delay(200);
    delay(500);
  }

  if (light > 1100)
  {
    Serial.print(light);
    Serial.println("Low Light");

    digitalWrite(buzz, HIGH);
    delay(200);
    digitalWrite(buzz, LOW);
    delay(200);
    delay(500);
  }

  /*Distance*/
  if (dist < 50)
  {
    digitalWrite(buzz, HIGH);
    for (int i = dist; i > 0; i--)
      delay(10);
    digitalWrite(buzz, LOW);
    for (int i = dist; i > 0; i--)
      delay(10);
      
    Serial.print(dist);
    Serial.println("Obstacle Near");

  }
}
