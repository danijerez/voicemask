#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>
#include <gamma.h>

#define lengthof(A) ((sizeof((A))/sizeof((A)[0])))

const PROGMEM uint8_t mouth_0[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {6, 6, 6, 6, 6, 6, 6, 6},
  {6, 6, 6, 6, 6, 6, 6, 6},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const PROGMEM uint8_t mouth_4[8][8] = {
  {0, 0, 6, 6, 6, 6, 0, 0},
  {0, 6, 0, 0, 0, 0, 6, 0},
  {6, 0, 0, 0, 0, 0, 0, 6},
  {6, 0, 0, 0, 0, 0, 0, 6},
  {6, 0, 0, 0, 0, 0, 0, 6},
  {6, 0, 0, 0, 0, 0, 0, 6},
  {0, 6, 0, 0, 0, 0, 6, 0},
  {0, 0, 6, 6, 6, 6, 0, 0}
};

const PROGMEM uint8_t mouth_3[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 6, 6, 6, 6, 0, 0},
  {0, 6, 0, 0, 0, 0, 6, 0},
  {6, 0, 0, 0, 0, 0, 0, 6},
  {6, 0, 0, 0, 0, 0, 0, 6},
  {0, 6, 0, 0, 0, 0, 6, 0},
  {0, 0, 6, 6, 6, 6, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const PROGMEM uint8_t mouth_2[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 6, 6, 6, 6, 6, 6, 0},
  {6, 0, 0, 0, 0, 0, 0, 6},
  {6, 0, 0, 0, 0, 0, 0, 6},
  {0, 6, 6, 6, 6, 6, 6, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const PROGMEM uint8_t mouth_1[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 6, 6, 0, 0, 0},
  {6, 6, 6, 0, 0, 6, 6, 6},
  {6, 6, 6, 0, 0, 6, 6, 6},
  {0, 0, 0, 6, 6, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const PROGMEM uint8_t mouth_smile[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {6, 0, 0, 0, 0, 0, 0, 6},
  {6, 6, 0, 0, 0, 0, 6, 6},
  {0, 6, 6, 6, 6, 6, 6, 0},
  {0, 0, 6, 6, 6, 6, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

#define PIN 3
const int pinMicrophone = 2;

uint16_t palette[8] = {};
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
                            NEO_MATRIX_BOTTOM     + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_ROWS    + NEO_MATRIX_ZIGZAG,
                            NEO_GRB            + NEO_KHZ800);

void drawImage(short image_addr) {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      uint8_t index = pgm_read_byte(image_addr + x + y * 8);
      matrix.drawPixel(x, y, palette[index]);
    }
  }

  matrix.show();
}

void setup() {
  matrix.begin();
  palette[0] = matrix.Color(0, 0, 0);
  palette[1] = matrix.Color(255, 0, 0);
  palette[2] = matrix.Color(0, 255, 0);
  palette[3] = matrix.Color(0, 0, 255);
  palette[4] = matrix.Color(0, 255, 255);
  palette[5] = matrix.Color(255, 0, 255);
  palette[6] = matrix.Color(255, 255, 0);
  palette[7] = matrix.Color(255, 255, 255);
  //pinMode (pinMicrophone, INPUT);
  Serial.begin(9600);
}

const uint16_t samples = 128;
float vol = 0;
int pop_detection = 0;
bool smiling = false;
unsigned long smiletimer = 0;
unsigned long last_face = 0;


void loop() {
  float nvol = 0;
    int previous_peak = -1;
    
    for (int i = 0; i<samples; i++){
        auto analog = analogRead(pinMicrophone);
        auto micline = abs(analog - 512);

        nvol = max(micline, nvol);
    }

    vol = (nvol + 1.0*vol)/2.0;
    Serial.println(vol);
    if(nvol > 200){
        pop_detection += 1;
        if(pop_detection > 2) {
            smiling = false;
            last_face = millis();
        }
    } else {
        if(pop_detection > 0 && pop_detection <= 2) {
            if(millis() > last_face + 500){
                smiling = true;
                smiletimer = millis() + 2000;
            }
        }
        pop_detection = 0;
    }

    if(millis() > smiletimer) smiling = false;

    if(smiling){
        drawImage((short)mouth_smile);
    } else if(vol < 225){
        drawImage((short)mouth_0);
    } else if(vol < 250){
        drawImage((short)mouth_1);
    } else if(vol < 350){
        drawImage((short)mouth_2);
    } else if(vol < 380){
        drawImage((short)mouth_3);
    } else {
        drawImage((short)mouth_4);
    }
}
