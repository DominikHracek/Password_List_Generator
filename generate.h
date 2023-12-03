#ifndef GENERATE_H
#define GENERATE_H

#include <iostream>
#include <string>
#include <vector>
class Generate{
    public:
        Generate();
        void get_info(int minimal_combination_length,
                      int maximal_combination_length,
                      int letter_case,
                      std::vector<std::string> separator,
                      std::vector<std::vector<std::string>> combinations,
                      bool use_same_word_multiple_times_in_one);
        void calculate_number_of_combinations();
        void generate_combinations();

    private:
        int minimal_combination_length;
        int maximal_combination_length;
        int letter_case;
        std::vector<std::string> separator;
        std::vector<std::vector<std::string>> combinations;

        bool use_same_word_multiple_times_in_one;
        int total_combinations;
        int total_words;
        int multiplier;
};

#endif