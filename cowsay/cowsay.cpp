#include <cstdlib>
#include <iostream>
#include "SimpleString.hpp"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Error: No message." << std::endl;
    return EXIT_FAILURE;
  }
  size_t total_length = 0;
  for (int i = 1; i < argc; i++) {
    total_length += cstrlen(argv[i]);
    if (i < argc - 1) {
      total_length++;
    }
  }
  char* temp = new char[total_length + 1];
  size_t pos = 0;
  for (int i = 1; i < argc; i++) {
    const char* message = argv[i];
    size_t j = 0;
    while (message[j] != '\0') {
      temp[pos] = message[j];
      pos++;
      j++;
    }
    if (i < argc - 1) {
      temp[pos] = ' ';
      pos++;
    }
  }
  temp[pos] = '\0';
  SimpleString total_msg = SimpleString_From(temp);
  delete[] temp;
  std::cout << " ";
  for (size_t i = 0; i < total_msg.len + 2; i++) {
    std::cout << "_";
  }
  std::cout << std::endl;
  std::cout << "<" << total_msg << ">" << std::endl;
  std::cout << " ";
  for (size_t i = 0; i < total_msg.len + 2; i++) {
    std::cout << "-";
  }
  std::cout << std::endl;
  std::cout << "        \\   ^__^" << std::endl;
  std::cout << "         \\  (oo)\\_______" << std::endl;
  std::cout << "            (__)\\       )\\/\\" << std::endl;
  std::cout << "                ||----w |" << std::endl;
  std::cout << "                ||     ||" << std::endl;
  SimpleString_Destruct(total_msg);
  return EXIT_SUCCESS;
}