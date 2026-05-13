#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

#define TRIG 6
#define ECHO 7

#define JOY A0
#define BTN_LEFT 2
#define BTN_RIGHT 3

// SPEED (lower = faster)
int stepDelay = 1;

// position tracking
long currentPos = 0;
long leftLimit = -200;
long rightLimit = 200;

bool leftSet = false;
bool rightSet = false;
bool scanning = false;

// step sequence
int seq[8][4] = {
  {1,0,0,0},
  {1,1,0,0},
  {0,1,0,0},
  {0,1,1,0},
  {0,0,1,0},
  {0,0,1,1},
  {0,0,0,1},
  {1,0,0,1}
};

void stepMotor(int s) {
  digitalWrite(IN1, seq[s][0]);
  digitalWrite(IN2, seq[s][1]);
  digitalWrite(IN3, seq[s][2]);
  digitalWrite(IN4, seq[s][3]);
  delay(stepDelay);
}

void moveStep(bool dir) {
  static int i = 0;

  if (dir) {
    i = (i + 1) % 8;
    currentPos++;
  } else {
    i = (i + 7) % 8;
    currentPos--;
  }

  stepMotor(i);
}

// HC-SR04 distance
int getDistanceCM() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 20000);
  int dist = duration * 0.034 / 2;

  if (dist == 0) dist = 200;
  return dist;
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  // ---------------- LIMIT SETUP ----------------
  if (digitalRead(BTN_LEFT) == LOW && !leftSet) {
    leftLimit = currentPos;
    leftSet = true;
    delay(300);
  }

  if (digitalRead(BTN_RIGHT) == LOW && leftSet && !rightSet) {
    rightLimit = currentPos;
    rightSet = true;
    scanning = true;
    delay(300);
  }

  // ---------------- MANUAL MODE ----------------
  if (!scanning) {
    int val = analogRead(JOY);

    if (val < 400) moveStep(false);
    else if (val > 600) moveStep(true);

    delay(3);
    return;
  }

  // ---------------- SCANNING MODE ----------------
  static bool dir = true;
  static int sensorCounter = 0;

  if (currentPos >= rightLimit) dir = false;
  if (currentPos <= leftLimit) dir = true;

  moveStep(dir);

  // SENSOR SPEED OPTIMISATION
  sensorCounter++;

  if (sensorCounter >= 3) {
    sensorCounter = 0;

    int dist = getDistanceCM();

    Serial.print(leftLimit);
    Serial.print(",");
    Serial.print(rightLimit);
    Serial.print(",");
    Serial.print(currentPos);
    Serial.print(",");
    Serial.println(dist);
  }

  delay(stepDelay);
}