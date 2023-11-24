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
    void start_ui();
    void start_friendly_ui();
    void get_separators(std::string separators_file_name, int line);
    void get_separators(int line);
    void get_words(std::string input_file_name);
    void get_words();
    int count_occurrences(std::string string, char character);
    void ask_for_patterns();
    void generate_combinations();

  private:
    int minimal_combination_length;
    int maximal_combination_length;

    std::ifstream separators_file;
    std::string separators_file_name;
    int separators_line;
    std::vector<std::string> separators;
    std::string separator;

    int letter_case;

    std::string input_file_name;
    std::ifstream input_file;

    std::vector<std::string> words;
    std::vector<char> patterns_of_words;

    std::vector<std::string> word_combinations;
    std::vector<std::vector<std::string>> combinations;

    std::string output_file_name;
    std::ifstream output_file;
};

#endif // GENERATE_H
