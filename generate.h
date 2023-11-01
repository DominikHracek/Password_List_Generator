#ifndef GENERATE_H
#define GENERATE_H

#include <iostream>

class Generate {
  public:
    Generate();
    void get_arguments(int argc, char *argv[]);
    void generate_combinations();
    void start_ui();

  private:
    int minimal_combination_length;
    int maximal_combination_length;
    std::string character_set_file;
    int character_set_line;
    int letter_case;
    std::string input_file;
    std::string output_file;
};

#endif // GENERATE_H
