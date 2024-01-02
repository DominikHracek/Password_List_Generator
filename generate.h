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
                    const std::vector<std::vector<std::string>>& twod_combinations,
                    const std::string &output_file_name);

        void generate_combinations();

        static std::vector<std::string> generate_combinations_with_repetition(int combination_length,
                                                          const std::vector<std::string>& words,
                                                          const std::vector<std::string>& separator,
                                                          const std::string& combination,
                                                          int current);

        static std::vector<std::string> convert_2d_vector_to_normal_vector(const std::vector<std::vector<std::string>>& twod_vector);

    private:
        int minimal_combination_length;
        int maximal_combination_length;
        int letter_case;
        std::vector<std::string> separator;
        std::vector<std::vector<std::string>> twod_combinations;
        std::vector<std::string> combinations;
        std::vector<std::string> generated_combinations;

        int total_separators;
        int total_combinations;
        int total_words;
        int multiplier;
        std::string output_file_name;
};

#endif