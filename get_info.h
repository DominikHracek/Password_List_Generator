#ifndef GET_INFO_H
#define GET_INFO_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Get_Info {
  public:
    Get_Info();
    void get_arguments(int argc, char *argv[]);
    void is_everything_ok();
    void start_ui();
    void start_friendly_ui();
    void get_separators(std::string separators_file_name, int line);
    void get_separators(int line);
    void get_words(std::string input_file_name);
    void get_words();
    int count_occurrences(std::string string, char character);
    void ask_for_patterns();

  private:
    int minimal_combination_length;
    int maximal_combination_length;

    bool use_same_word_multiple_times_in_one;

    std::ifstream separators_file;
    std::string separators_file_name;
    int separators_line;
    std::vector<std::vector<std::string>> separators;
    std::vector<std::string> separator;

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

#endif