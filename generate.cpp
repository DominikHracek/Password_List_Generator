#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>

#include "generate.h"

Generate::Generate() {
	total_combinations = 0;
	total_separators = 0;
	total_words = 0;
	combinations = {};
	generated_combinations = {};
}

void Generate::get_info(const int minimal_combination_length,
                        const int maximal_combination_length,
                        const int letter_case,
                        std::vector<std::string> separator,
                        const std::vector<std::vector<std::string>>& twod_combinations,
                        const std::string& output_file_name) {

	this->minimal_combination_length = minimal_combination_length;
	this->maximal_combination_length = maximal_combination_length;
	this->letter_case = letter_case;
	this->separator = std::move(separator);
	this->twod_combinations = twod_combinations;
	this->output_file_name = output_file_name;
}

void Generate::generate_combinations() {
	for (const auto& combination : twod_combinations){
		total_words += combination.size();
	}
	total_separators = separator.size();
	for (int i = total_words; i > 0; i--){
		total_combinations += std::pow(total_words, i) * std::pow(total_separators, i + 1);
	}
	std::cout << "Total generated combinations: " << total_combinations << '\n';
	combinations = convert_2d_vector_to_normal_vector(twod_combinations);
	std::vector<std::string> words_without_repetition = combinations;

	generated_combinations.clear();

	int previous_length = 0;
	for (int i = 1; i <= combinations.size(); i++){
		std::vector<std::string> temporary_combinations = generate_combinations_with_repetition(i, combinations, separator, "", 0);
		for (const std::string& combination : temporary_combinations){
			for (const std::string &sep : separator) {
				std::string new_combination = combination + sep;
				generated_combinations.push_back(new_combination);
				std::cout << '\r' << new_combination << std::flush;
				if (new_combination.length() < previous_length) {
					const int difference = previous_length - new_combination.length();
					std::cout << std::string(difference, ' ') << std::flush;
				}
				previous_length = new_combination.length();
			}
		}
	}

	std::ofstream output_file(output_file_name);
	for (const std::string &generated_combination : generated_combinations){
		output_file << generated_combination << '\n';
	}
	output_file.close();
	std::cout << "Combinations written to file: " << output_file_name << '\n';
	exit(0);
}

std::vector<std::string> Generate::convert_2d_vector_to_normal_vector(const std::vector<std::vector<std::string>>& twod_vector) {
	std::vector<std::string> converted_vector;
	for (auto & vector_in_2d_vector : twod_vector){
		for (const auto & element_in_vector : vector_in_2d_vector){
			converted_vector.push_back(element_in_vector);
		}
	}
	return converted_vector;
}

std::vector<std::string> Generate::generate_combinations_with_repetition(const int combination_length,
                                                     const std::vector<std::string>& words,
                                                     const std::vector<std::string>& separator,
                                                     const std::string& combination,
                                                     const int current) {
	std::vector<std::string> generated_combinations;
	if (current == combination_length){
		generated_combinations.push_back(combination);
		return generated_combinations;
	}

	for (const std::string& word : words){
		std::string current_combination = combination;
		current_combination += word;
	}

	for (const std::string& word : words){
		for (const std::string& sep : separator){
			std::vector<std::string> new_words = generate_combinations_with_repetition(combination_length, words, separator, combination + sep + word, current + 1);
			for (const std::string& new_word : new_words){
				generated_combinations.push_back(new_word);
			}
		}
	}
	return generated_combinations;
}
