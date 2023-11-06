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
    void get_separators(std::string separators_file_name, int line);
    void get_separators(int line);

  private:
    int minimal_combination_length = 0;
    int maximal_combination_length = 12;

    std::ifstream separators_file;
    std::string separators_file_name = "";
    int separators_line = 1;
    std::vector<std::string> separators = {};
    std::string separator = "";

    int letter_case = 0;

    std::string input_file_name = "";
    std::ifstream input_file;
    std::vector<std::string> words = {};

    std::string output_file_name = "generated_passwords.txt";
    std::ifstream output_file;
};

#endif // GENERATE_H
