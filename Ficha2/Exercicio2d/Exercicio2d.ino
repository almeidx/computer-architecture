#define GREEN_LED 10
#define YELLOW_LED 11
#define RED_LED 12
#define PEDESTRIAN_GREEN_LED 6
#define PEDESTRIAN_RED_LED 7

#define GREEN_DELAY 11000
#define YELLOW_DELAY 4000
#define RED_DELAY 7000

int current = RED_LED;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(PEDESTRIAN_GREEN_LED, OUTPUT);
  pinMode(PEDESTRIAN_RED_LED, OUTPUT);
}

void loop() {
  int _delay;

  switch (current) {
    case GREEN_LED:
      current = YELLOW_LED;
      _delay = YELLOW_DELAY;
      break;
    case YELLOW_LED:
      current = RED_LED;
      _delay = RED_DELAY;
      break;
    case RED_LED:
      current = GREEN_LED;
      _delay = GREEN_DELAY;
      break;
  }

  if (current == GREEN_LED || current == YELLOW_LED) {
    digitalWrite(PEDESTRIAN_GREEN_LED, LOW);
    digitalWrite(PEDESTRIAN_RED_LED, HIGH);
  } else {
    digitalWrite(PEDESTRIAN_RED_LED, LOW);
    digitalWrite(PEDESTRIAN_GREEN_LED, HIGH);
  }

  if (current == YELLOW_LED) {
    digitalWrite(current, HIGH);
    delay(500);
    digitalWrite(current, LOW);
    delay(500);
    digitalWrite(current, HIGH);
    delay(500);
    digitalWrite(current, LOW);
    digitalWrite(PEDESTRIAN_RED_LED, LOW);
    delay(500);
    digitalWrite(current, HIGH);
    digitalWrite(PEDESTRIAN_RED_LED, HIGH);
    delay(500);
    digitalWrite(current, LOW);
    digitalWrite(PEDESTRIAN_RED_LED, LOW);
    delay(500);
    digitalWrite(current, HIGH);
    digitalWrite(PEDESTRIAN_RED_LED, HIGH);
    delay(500);
    digitalWrite(current, LOW);
    digitalWrite(PEDESTRIAN_RED_LED, LOW);
    delay(500);
  } else {
    digitalWrite(current, HIGH);
    delay(_delay - 2000);

    if (current == RED_LED) digitalWrite(PEDESTRIAN_GREEN_LED, LOW);
    digitalWrite(current, LOW);
    delay(500);
    if (current == RED_LED) digitalWrite(PEDESTRIAN_GREEN_LED, HIGH);
    digitalWrite(current, HIGH);
    delay(500);
    if (current == RED_LED) digitalWrite(PEDESTRIAN_GREEN_LED, LOW);
    digitalWrite(current, LOW);
    delay(500);
    if (current == RED_LED) digitalWrite(PEDESTRIAN_GREEN_LED, HIGH);
    digitalWrite(current, HIGH);
    delay(500);
    if (current == RED_LED) digitalWrite(PEDESTRIAN_GREEN_LED, LOW);
    digitalWrite(current, LOW);
  }
}
