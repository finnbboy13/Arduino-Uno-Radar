import processing.serial.*;

Serial myPort;

float leftLimit = -200;
float rightLimit = 200;
float currentPos = 0;
float distanceVal = 0;

float radarRadius = 450;
float maxDistance = 200;

void setup() {

  size(1200, 700);
  smooth();

  println(Serial.list());

  // CHANGE PORT NUMBER IF NEEDED
  myPort = new Serial(this, Serial.list()[1], 9600);

  myPort.bufferUntil('\n');
}

void draw() {

  background(0);

  drawRadar();
  drawSweep();
  drawTarget();
  drawHUD();
}

void serialEvent(Serial p) {

  String data = p.readStringUntil('\n');

  if (data != null) {

    data = trim(data);

    String[] values = split(data, ',');

    if (values.length == 4) {

      leftLimit = float(values[0]);
      rightLimit = float(values[1]);
      currentPos = float(values[2]);
      distanceVal = float(values[3]);
    }
  }
}

float getAngle(float pos) {

  return map(pos,
             leftLimit,
             rightLimit,
             -90,
             90);
}

void drawRadar() {

  pushMatrix();

  translate(width/2, height-50);

  stroke(0,255,0);
  strokeWeight(1);
  noFill();

  float leftA = radians(getAngle(leftLimit) - 90);
  float rightA = radians(getAngle(rightLimit) - 90);

  // range arcs
  for (int r = 1; r <= 5; r++) {

    float radius = radarRadius * r / 5.0;

    arc(0, 0,
        radius*2,
        radius*2,
        leftA,
        rightA);
  }

  // angle guide lines
  for (int i = 0; i <= 6; i++) {

    float a = map(i, 0, 6,
                  getAngle(leftLimit),
                  getAngle(rightLimit));

    float rad = radians(a - 90);

    float x = cos(rad) * radarRadius;
    float y = sin(rad) * radarRadius;

    line(0,0,x,y);
  }

  popMatrix();
}

void drawSweep() {

  pushMatrix();

  translate(width/2, height-50);

  float angle = getAngle(currentPos);

  float rad = radians(angle - 90);

  float x = cos(rad) * radarRadius;
  float y = sin(rad) * radarRadius;

  stroke(0,255,0);
  strokeWeight(3);

  line(0,0,x,y);

  popMatrix();
}

void drawTarget() {

  pushMatrix();

  translate(width/2, height-50);

  float angle = getAngle(currentPos);

  float r = map(distanceVal,
                0,
                maxDistance,
                0,
                radarRadius);

  float rad = radians(angle - 90);

  float x = cos(rad) * r;
  float y = sin(rad) * r;

  // RED TARGET DOT
  fill(255,0,0);
  noStroke();

  ellipse(x,y,12,12);

  popMatrix();
}

void drawHUD() {

  fill(0,255,0);

  textSize(20);

  text("Distance: " + distanceVal + " cm", 20, 30);

  text("Motor Position: " + currentPos, 20, 60);

  text("Radar Synced", width - 180, 30);
}
