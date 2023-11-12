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
    "1) - _ / \\ ",
    "2) - _ / \\ ! ; : \" \'",
    "3) - _ / \\ ! ; : \" \' | @ # $ %",
    "4) - _ / \\ ! ; : \" \' | @ # $ % ^ & * , .",
    "5) - _ / \\ ! ; : \" \' | @ # $ % ^ & * , . [ ] { }",
    "6) - _ / \\ ! ; : \" \' | @ # $ % ^ & * , . [ ] { } + = < >",
    "7) - _ / \\ ! ; : \" \' | @ # $ % ^ & * , . [ ] { } + = < > ? ~ `"
};
    separator = "- _ / \\";

    letter_case = 0;

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
          std::cout << "Error: Unknown argument " << arg << '\n';
            break;
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

/*void Generate::read_file(std::string input_file_name) {
  input_file.open(input_file_name);
  if (input_file.is_open()){
    while(input_file.good()){
      std::string line_in_file;
      input_file >> line_in_file;
      words.push_back(line_in_file);
    }
  }
  input_file.close();
  int max_word_length = 0;
  for (std::string word : words) {
    if (word.length() > max_word_length) {
      max_word_length = word.length();
    }
  }
}*/

void Generate::get_separators(std::string separators_file_name, int line) {
  separators_file.open(separators_file_name);
<<<<<<< HEAD
  std::string line_being_read;
  while (std::getline(separators_file, line_being_read)){
    separators.push_back(line_being_read);
  }
  separators_file.close();

  if(line >=1 && line <= separators.size()){
    separator = separators[line - 1];
  }
=======
  if (separators_file.is_open()){
    while(separators_file.good()){
      std::string line_in_separators_file;
      separators_file >> line_in_separators_file;
      separators.push_back(line_in_separators_file);
    }
  }
  separators_file.close();
  separator = separators.at(line);
>>>>>>> 1500244baba2d4a5a34248777104c62a62f80d92
}

void Generate::get_separators(int line) {
  if (line >=1 && line <= separators.size()){
    separator = separators[line - 1];
  }
}

    // Show all words on the same line after 1 second
    /*for (int i = 0; i < words.size(); i++) {
      std::cout << '\r';
      for (int j = 0; j < max_word_length; j++) {
        std::cout << ' '; // Clear the line
      }
      std::cout << '\r' << words[i];
      std::cout.flush(); // Flush the output to make it visible
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }*/

//void Generate::ask_for_patterns() {}

/*
void Generate::generate_combinations() {
  read_file(input_file_name);
   number_of_words^number_of_places_for_words     * number_of_punctuation^number_of_places_for_punctuation
   (word1 word2; word2 word3, word3 word1 -> 3^2) * ( ,-,_,/)4^2 (-/,-_, etc.)
  for (int i = 1; i <=pow(words.size()); i++){}
    * TO-DO
  * If word is longer, than the expected output length, shorten it from the beginning, end, the middle and evenly both words
*/
