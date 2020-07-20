#include <Adafruit_NeoPixel.h>
#define LED_PIN    6
#define LED_COUNT 142 // First LED=0, Last LED=141;

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)



// Define colors
uint32_t black = strip.Color(0, 0, 0);
uint32_t red = strip.Color(255, 0, 0);
uint32_t green = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t yellow = strip.Color(255, 255, 0);
uint32_t aqua = strip.Color(0, 255, 255);
uint32_t magenta = strip.Color(255, 0, 255);
uint32_t white = strip.Color(255, 255, 255);

uint32_t rainbow[] = {black, red, green, blue, yellow, aqua, magenta, white};


uint32_t rgb[LED_COUNT]; 

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(25); // Set BRIGHTNESS  (max = 255)

  // to print something go to "Tools" -> Serial Monitor
  Serial.begin(9600);
  Serial.print(LED_COUNT);
  strip_gen(1,6);
}

void loop() {
  shift();
  delay(50);
  
  //delay(-1); // execute one time
}



void backwards() {
  rgb[LED_COUNT-1] = 255,0,0;
  strip.setPixelColor(LED_COUNT-1,rgb[141]);
  strip.show();

  for(int i = LED_COUNT-1; i>=0; i--) {
    strip.clear();
    strip.setPixelColor(i,rainbow[4]);
    strip.show();
    delay(50);
  }
}


void ran() {
  for(int i = LED_COUNT-1; i>=0; i--) {
    int r = random(0,255);
    int g = random(0,255);
    int b = random(0,255);
    strip.setPixelColor(i,r,g,b);
  }
  strip.show();
}

void rgb_ran() {
  for(int i = LED_COUNT-1; i>=0; i=i-3) {
    strip.setPixelColor(i,random(255),0,0);
    strip.setPixelColor(i-1,0,random(255),0);
    strip.setPixelColor(i-2,0,0,random(255));
  }
  strip.show();
}

void rgb_gen() {
  for(int i = LED_COUNT-1; i>=0; i--) strip.setPixelColor(i,0,random(255),random(255));
 
  strip.show();
}
void shift() {
  for(int i = LED_COUNT-1; i>=0; i--) {
    uint32_t color = strip.getPixelColor(i-1);
    strip.setPixelColor(i,color);
    //strip.show();
    //delay(75);
  }
  strip.setPixelColor(0,strip.getPixelColor(LED_COUNT-1));
  strip.show();
}

void strip_gen(int min, int max) {
  int length;
  for(int i = 0; i < LED_COUNT-1;) {
    length = random(min, max);
    int r = random(255);
    int g = random(255);
    int b = random(255);
    for(int k = 0; k < max; k++) {
      strip.setPixelColor(i+k,r,g,b);
    }
    i = i+length;
  }
  strip.show();
}
