#include <cstring>
#include <iostream>

#include "generate.h"

Generate::Generate() {
    minimal_combination_length = 0;
    maximal_combination_length = 12;
    character_set_file = "characters.kplg";
    character_set_line = 1;
    letter_case = 0;
    input_file = "";
    output_file = "";
}

void Generate::get_arguments(int argc, char *argv[]) {
    for (int i = 1; i < argc; i += 2) {
        std::string arg = argv[i];
        std::string possible_value;
        if (i + 1 < argc){
          possible_value = argv[i + 1];
        }

        if (arg == "-n" || arg == "--min") {
            if (i + 1 < argc && possible_value.find("-") == -1) {
                minimal_combination_length = std::stoi(argv[i + 1]);
            } else {
              std::cout << "Error: Missing value for -n/--min argument." << '\n';
              break;
            }
        } else if (arg == "-x" || arg == "--max") {
            if (i + 1 < argc && possible_value.find("-") == -1) {
                maximal_combination_length = std::stoi(argv[i + 1]);
            } else {
              std::cout << "Error: Missing value for -x/--max argument." << '\n';
              break;
            }
        } else if (arg == "-r" || arg == "--char") {
            if (i + 1 < argc && possible_value.find("-") == -1) {
              std::string character_file_checker = argv[i + 1];
              if (character_file_checker.find(",") != -1){
                character_set_file = character_file_checker.substr(0,character_file_checker.find(","));
                character_set_line = std::stoi(character_file_checker.substr(character_file_checker.find(",") + 1));
              } else {
                character_set_line = std::stoi(argv[i + 1]);
              }
            } else {
              std::cout << "Error: Missing value for -r/--char argument." << '\n';
              break;
            }
        } else if (arg == "-c" || arg == "--case") {
            if (i + 1 < argc && possible_value.find("-") == -1) {
                letter_case = std::stoi(argv[i + 1]);
            } else {
              std::cout << "Error: Missing value for -c/--case argument." << '\n';
              break;
            }
        } else if (arg == "-f" || arg == "--file") {
            if (i + 1 < argc && possible_value.find("-") == -1) {
                input_file = argv[i + 1];
            } else {
              std::cout << "Error: Missing value for -f/--file argument." << '\n';
              break;
            }
        } else {
          std::cout << "Error: Unknown argument " << arg << '\n';
            break;
        }
    }
}

void Generate::start_ui() {
  std::cout << ">>>>>>>>>>>>>>>>>>>>>Khakis's Password List Generator<<<<<<<<<<<<<<<<<<<<<" << '\n';
  std::cout << '\n';
  std::cout << "Minimal combination length: " << minimal_combination_length << '\n';
  std::cout << "Maximal combination length: " << maximal_combination_length << '\n';
  std::cout << "Case-sensitivity level: " << letter_case << "/" << 4 << '\n';
  std::cout << "Character set:" << '\n';
  std::cout << '\t' << "Name: " << character_set_file << '\n';
  if (character_set_line < 1){
    character_set_line = 1;
    std::cout << '\t' << "Line: " << character_set_line << '\n';
    std::cout << '\t' << "Each file's first line start at index 1 -> index has been set to 1" << '\n';
    std::cout << '\n';
  } else {
    std::cout << '\t' << "Line: " << character_set_line << '\n';
  }
}

void Generate::generate_combinations() {
  
}