#include <iostream>
#include <vector>
#include <stdio.h>
// LED_1 = 0, LED_142 = 141;
const int NUM_OF_LEDS = 142;

// prints one entry (= vector rgb) of a color vector
void print_RGB(std::vector<int> rgb) {
  std::cout <<"RGB: (" << rgb.at(0) << "," << rgb.at(1) << "," << rgb.at(2) << ")\n";
}

// prints all entries (vectors) of a color vectors
void print_colors(std::vector<std::vector<int>> colors) {
  for(int i = 0; i < colors.size(); i++) {
    print_RGB(colors.at(i));
  }
}


int steps(int length) {
  return NUM_OF_LEDS / length; // integer divison
}

void rainbow_grad_sample() {
  // iterates over all LEDS from {141,0,0} to {0,141,0}
  for(int i = 0; i < NUM_OF_LEDS; i++) {
    // calculate rgb
    std::vector<int> rgb = {141-i,i,0};
    std::cout << "LED index: "<< i << ", RGB-Code:" << rgb.at(0) <<","<< rgb.at(1) << "," << rgb.at(2) <<  "\n";
  }
}

std::vector<std::vector<int>> rainbow_grad_print_sample(std::vector<std::vector<int>> colors) {
  int size = colors.size(); // NUM_OF_LEDS
  // auf nächste "modulo Zahl runtergehen", also maximal 5 abziehen
  int modifier = size % 6;
  int mod_size = size - modifier;
  int range = size / 6; // 6 = numbers of steps

  for(int i = 0; i < NUM_OF_LEDS; i++) {
    // red {255,0+,0} -> yellow {255,255,0}
    if(0 < i && i <= range) std::cout <<"Index " << i <<": 1st\n";

    // yellow {255-,255,0} -> green {0,255,0}
    else if(range < i && i <= 2*range) std:: cout <<"Index " << i <<": 2st\n";

    // green {0,255,0+} -> light-blue {0,255,255}
    else if(2*range < i && i <= 3*range) std:: cout <<"Index " << i <<": 3st\n";

    // light-blue {0,255-,255} -> blau {0,0,255}
    else if(3*range < i && i <= 4*range) std:: cout <<"Index " << i <<": 4st\n";

    // blau {0+,0,255} -> violet {255,0,255}
    else if(4*range < i && i <= 5*range) std:: cout <<"Index " << i <<": 5st\n";

    // violet {255,0,255-} -> red {255,0,0}
    else if(5*range < i) std:: cout <<"Index " << i <<": 6st\n";

  }

  return colors;
}


void rainbow_grad(std::vector<std::vector<int>> colors) {
    int size = colors.size(); // NUM_OF_LEDS
    // auf nächste "modulo Zahl runtergehen", also maximal 5 abziehen
    int modifier = size % 6;
    int mod_size = size - modifier;
    int range = size / 6; // 6 = numbers of steps = 23

    for(int i = 0; i < NUM_OF_LEDS; i++) {
      // red {255,0+,0} -> yellow {255,255,0}
      if(0 < i && i <= range) {
        colors.at(i).at(0) = 255;
        colors.at(i).at(1) = (range/i)*255;
        colors.at(i).at(2) = 0;
      }

      // yellow {255-,255,0} -> green {0,255,0}
      else if(range < i && i <= 2*range) {
        colors.at(i).at(0) = 255-((2*(range)/i)*255);
        colors.at(i).at(1) = 255;
        colors.at(i).at(2) = 0;
      }

      // green {0,255,0+} -> light-blue {0,255,255}
      else if(2*range < i && i <= 3*range) {
        colors.at(i).at(0) = 0;
        colors.at(i).at(1) = 255;
        colors.at(i).at(2) = ((3*range)/i)*255;
      }

      // light-blue {0,255-,255} -> blau {0,0,255}
      else if(3*range < i && i <= 4*range) {
        colors.at(i).at(0) = 0;
        colors.at(i).at(1) = 255-((4*(range)/i)*255);
        colors.at(i).at(2) = 255;
      }

      // blau {0+,0,255} -> violet {255,0,255}
      else if(4*range < i && i <= 5*range) {
        colors.at(i).at(0) = ((5*range)/i)*255;
        colors.at(i).at(1) = 0;
        colors.at(i).at(2) = 255;
      }

      // violet {255,0,255-} -> red {255,0,0}
      else if(5*range < i) {
        colors.at(i).at(0) = 255;
        colors.at(i).at(1) = 0;
        colors.at(i).at(2) = 255-((6*(range)/i)*255);
      }
    }
}


std::vector<std::vector<int>> rainbow_grad_2(std::vector<std::vector<int>> colors) {
  int size = colors.size(); // NUM_OF_LEDS
  // auf nächste "modulo Zahl runtergehen", also maximal 5 abziehen
  int modifier = size % 6;
  int mod_size = size - modifier;
  int range = size / 6; // 6 = numbers of steps

  for(int i = 0; i < NUM_OF_LEDS; i++) {
    // red {255,0+,0} -> yellow {255,255,0}
    if(0 < i && i <= range) {
      (colors.at(i)).at(0) = 255;
    }

    // yellow {255-,255,0} -> green {0,255,0}
    else if(range < i && i <= 2*range) std:: cout <<"Index " << i <<": 2st\n";

    // green {0,255,0+} -> light-blue {0,255,255}
    else if(2*range < i && i <= 3*range) std:: cout <<"Index " << i <<": 3st\n";

    // light-blue {0,255-,255} -> blau {0,0,255}
    else if(3*range < i && i <= 4*range) std:: cout <<"Index " << i <<": 4st\n";

    // blau {0+,0,255} -> violet {255,0,255}
    else if(4*range < i && i <= 5*range) std:: cout <<"Index " << i <<": 5st\n";

    // violet {255,0,255-} -> red {255,0,0}
    else if(5*range < i) std:: cout <<"Index " << i <<": 6st\n";

  }

  return colors;
}


int main() {
  // create RGB Vector entry for every LED
  std::vector<std::vector<int>> colors(NUM_OF_LEDS);
  color.assign(NUM_OF_LEDS, )


  int length = 4;
  for (int i = 0; i < NUM_OF_LEDS; i++) {} // iterates of all LEDS
  colors = rainbow_grad_2(colors);



    return 0;
}
