#ifndef GENERATE_H
#define GENERATE_H

#include <vector>
#include <fstream>

class Generate{
    public:
        Generate();
        void get_info(int minimal_combination_length,
                        int maximal_combination_length,
                        const std::string& letter_case,
                        std::vector<std::string> separator,
                        const std::vector<std::vector<std::string>>& twod_combinations,
                        const std::string &output_file_name,
                        const std::string& hash_enabled,
                        bool verbose);

        std::vector<std::vector<std::string>> casing(const std::vector<std::string>& combinations);



        std::string hash_combination(const std::string& combination, const std::string& hash_function);

        void generate_combinations();

        void generate_combinations_with_repetition(int combination_length,
                                                          const std::vector<std::string>& words,
                                                          const std::vector<std::string>& separator,
                                                          std::string& combination,
                                                          int current);

        static std::vector<std::string> convert_2d_vector_to_normal_vector(const std::vector<std::vector<std::string>>& twod_vector);

    private:
        int minimal_combination_length{};
        int maximal_combination_length{};
        std::string letter_case;
        std::vector<std::string> separator;
        std::vector<std::vector<std::string>> twod_combinations;
        std::vector<std::string> combinations;
        std::vector<std::string> generated_combinations;
        std::string hash_enabled;
        bool verbose;

        int total_separators;
        unsigned long long int total_combinations;
        int total_words;
        int multiplier{};
        std::string output_file_name;
};

#endif
