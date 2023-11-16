#include <chrono>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <thread>
#include "generate.h"

Generate::Generate() {
    minimal_combination_length = 0;
    maximal_combination_length = 12;

    separators_file_name = "";
    separators_line = 1;
    separators = {
    "- _ / \\ ",
    "- _ / \\ ! ; : \" \'",
    "- _ / \\ ! ; : \" \' | @ # $ %",
    "- _ / \\ ! ; : \" \' | @ # $ % ^ & * , .",
    "- _ / \\ ! ; : \" \' | @ # $ % ^ & * , . [ ] { }",
    "- _ / \\ ! ; : \" \' | @ # $ % ^ & * , . [ ] { } + = < >",
    "- _ / \\ ! ; : \" \' | @ # $ % ^ & * , . [ ] { } + = < > ? ~ `"
};
    separator = "- _ / \\";

    letter_case = 0;

    pattern = 0;

    input_file_name = "";
    words = {};
    
    output_file_name = "generated_passwords.txt";
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
                separators_file_name = character_file_checker.substr(0,character_file_checker.find(","));
                separators_line = std::stoi(character_file_checker.substr(character_file_checker.find(",") + 1));
                get_separators(separators_file_name, separators_line);
              } else {
                separators_line = std::stoi(argv[i + 1]);
                get_separators(separators_line);
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
            input_file_name = argv[i + 1];
          } else {
            std::cout << "Error: Missing value for -f/--file argument." << '\n';
            break;
          }
        } else {
          std::cout << "Error: Unknown argument " << '\"' << arg << '\"' << '\n';
            exit(1);
        }
    }
}

void Generate::start_ui() {
  std::cout << ">>>>>>>>>>>>>>>>>>>>>Khakis's Password List Generator<<<<<<<<<<<<<<<<<<<<<" << '\n';
  std::cout << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));

  std::cout << "Minimal combination length: " << minimal_combination_length << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));

  std::cout << "Maximal combination length: " << maximal_combination_length << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));

  std::cout << "Case-sensitivity level: " << letter_case << "/" << 4 << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));

  std::cout << "Spliting words pattern: " << patterns[pattern] << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));

  if (separators_file_name == ""){
    if (separators_line < 1){
      std::cout << "Each file's first line start at index 1 -> index has been set to 1" << '\n';
      separators_line = 1;
    } else if (separators_line > 7){
      std::cout << "Unsupported separator line index, please check the help page for -r/--char with";
      std::cout << "./kplg -h/--help -r/--char";
    } else {
      std::cout << "Character set:" <<  '\n';
      std::cout << '\t' << "Character file: " << "internal" << '\n';
      std::cout << '\t' << "Character line: " << separators_line << '\n';
      std::cout << '\t' << "Characters: " << separator << '\n';
      std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
  } else {
    std::cout << "Character set:" << '\n';
    std::cout << '\t' << "Character file: " << separators_file_name << '\n';
    std::cout << '\t' << "Character line: " << separators_line << '\n';
    std::cout << '\t' << "Characters: " << separator << '\n';
  }
  std::cout << '\n';

  std::cout << "File with words: " << input_file_name << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));

  std::cout << "File with generated passwords: " << output_file_name << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
}

void Generate::get_separators(std::string separators_file_name, int line) {
  separators.clear();
  separators_file.open(separators_file_name);
  std::string line_being_read;
  while (std::getline(separators_file, line_being_read)){
    separators.push_back(line_being_read);
  }
  separators_file.close();

  if(line >=1 && line <= separators.size()){
    separator = separators[line - 1];
  }
}

void Generate::get_separators(int line) {
  if (line >=1 && line <= separators.size()){
    separator = separators[line - 1];
  }
}

void Generate::get_words(std::string input_file_name) {
  words.clear();
  input_file.open(input_file_name);
  std::string line_being_read;
  while (std::getline(input_file, line_being_read)){
    words.push_back(line_being_read);
  }
  input_file.close();
}

void Generate::ask_for_patterns() {
  std::cout << "How do you want to split words to passwords" << '\n';
  std::cout << '\t' << "1) From start of every word by x letters (3: Generate words -> Gen, era, te, wor, ds)" << '\n';
  std::cout << '\t' << "2) From start by x letters (3: Generate words -> Gen, era, tew, ord, s)" << '\n';
}

void Generate::generate_combinations() {
  /*for (int i = 1; i <=pow(words.size()); i++){
    //
  }*/
}