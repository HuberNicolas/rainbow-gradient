#include <iostream>
#include <vector>
#include <list>
const int NUM_OF_LEDS = 142;

int colors[NUM_OF_LEDS][3];


void init_colors(int colors[NUM_OF_LEDS][3]) {
  for(int i = 0; i < NUM_OF_LEDS; i++) {
    colors[i][0] = 0;
    colors[i][1] = 0;
    colors[i][2] = 0;
  }
}

void print_RGB(int rgb[3]) {
  std::cout << " RGB: (" << rgb[0] << "," << rgb[1] << "," << rgb[2] << ")\n";
}

void print_colors(int colors[NUM_OF_LEDS][3]) {
  for(int i = 0; i < NUM_OF_LEDS; i++) {
    std::cout << "LED " << i;
    print_RGB(colors[i]);
  }
}

void rainbow_grad(int colors[NUM_OF_LEDS][3]) {
  int size = NUM_OF_LEDS; // NUM_OF_LEDS
  // auf nächste "modulo Zahl runtergehen", also maximal 5 abziehen
  int modifier = size % 6;
  int mod_size = size - modifier;
  int range = size / 6; // 6 = numbers of steps

  for(int i = 0; i < NUM_OF_LEDS; i++) {
    // red {255,0+,0} -> yellow {255,255,0}
    if(0 < i && i <= range) {
      colors[i][0] = 255;
      colors[i][1] = (range/(i+1));
      colors[i][2] = 0;
    }
  }

}


int main() {
  init_colors(colors);
  print_colors(colors);
  rainbow_grad(colors);
  print_colors(colors);

    return 0;









}
