#include <cstring>
#include <iostream>

#include "generate.h"

int minimal_combination_length;
int maximal_combination_length;
int character_set; // int because of indentification by line
int letter_case;

std::string arguments[5][2] = {{"-n","--min"},
                               {"-x","--max"},
                               {"-r", "--char"},
                               {"-c", "--case"},
                               {"-f", "--file"}};

void Generate::get_arguments(int argc, char *argv[]){
  for (int i = 1; i < argc; i + 2){
    if (strcmp(argv[i], "-n") == 0){
      
    }
  }
}
void Generate::generate_combinations(){}