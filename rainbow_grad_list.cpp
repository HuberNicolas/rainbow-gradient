#include <iostream>
#include <vector>
#include <list>
const int NUM_OF_LEDS = 142;

std::list<int> rgb = {0,0,0};
std::list<std::list<int>> colors;

void print_RGB(std::list<int> rgb) {
  std::cout << "( ";
  for(auto v : rgb) {
    std::cout << v << " ";
  }
  std::cout << ")";
}

void print_colors(std::list<std::list<int>> colors) {
  int i = 0;
  for(auto v : colors) {
    std::cout << "RGB "<< i << ": ";
    print_RGB(v);
    std::cout << "\n";
    i++;
  }
}

void rainbow_grad(std::list<std::list <int>> colors) {
  int size = colors.size(); // NUM_OF_LEDS
  // auf nächste "modulo Zahl runtergehen", also maximal 5 abziehen
  int modifier = size % 6;
  int mod_size = size - modifier;
  int range = size / 6; // 6 = numbers of steps = 23


}


int main() {

  //init empty list
  colors.assign(NUM_OF_LEDS,rgb);
  //print_RGB(rgb);
  print_colors(colors);


    return 0;
}
