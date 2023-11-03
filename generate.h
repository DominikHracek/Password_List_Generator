#ifndef GENERATE_H
#define GENERATE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Generate {
  public:
    Generate();
    void get_arguments(int argc, char *argv[]);
    void ask_for_patterns();
    void generate_combinations();
    void start_ui();
    void start_friendly_ui();
    void read_file(std::string input_file_name);

  private:
    int minimal_combination_length;
    int maximal_combination_length;
    std::string character_set_file;
    int character_set_line;
    int letter_case;
    std::ifstream input_file;
    std::string input_file_name;
    std::ifstream output_file;
    std::string output_file_name;
    std::vector<std::string> words;
};

#endif // GENERATE_H
