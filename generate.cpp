#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>

#include "generate.h"

Generate::Generate() {
	total_combinations = 0;
	total_separators = 0;
	total_words = 0;
	combinations = {};
	generated_combinations = {};
	verbose = false;
	hash = false;
}

void Generate::get_info(const int minimal_combination_length,
                        const int maximal_combination_length,
                        const std::string letter_case,
                        std::vector<std::string> separator,
                        const std::vector<std::vector<std::string>>& twod_combinations,
                        const std::string& output_file_name,
                        const bool verbose,
                        const bool hash) {

	this->minimal_combination_length = minimal_combination_length;
	this->maximal_combination_length = maximal_combination_length;
	this->letter_case = letter_case;
	this->separator = std::move(separator);
	this->twod_combinations = twod_combinations;
	this->output_file_name = output_file_name;
	this->verbose = verbose;
	this->hash = hash;
}

std::vector<std::vector<std::string>> Generate::casing(const std::vector<std::string>& combinations) {
	std::vector<std::vector<std::string>> return_combinations;
	std::vector<std::string> vector_of_combinations;
	if (letter_case == "1") {
		for (const std::string& combination : combinations) {
			vector_of_combinations.clear();
			std::string upper_case_combination = combination;
			if (std::isalpha(upper_case_combination[0])/*TODO check if first character is a letter, if is uppercase it, otherwise uppercase the second character*/) {
				upper_case_combination[0] = std::toupper(upper_case_combination[0]);
			} else {
				upper_case_combination[1] = std::toupper(upper_case_combination[1]);
			}
			vector_of_combinations.push_back(combination);
			vector_of_combinations.push_back(upper_case_combination);
			return_combinations.push_back(vector_of_combinations);
		}
	} else if (letter_case == "2") {
		for (const std::string& combination : combinations) {
			vector_of_combinations.clear();
			if (combination.length() % 2 == 0) {
				std::string upper_case_combination = combination;
				upper_case_combination[0] = std::toupper(upper_case_combination[0]);
				upper_case_combination[upper_case_combination.length()/2-1] = std::toupper(upper_case_combination[upper_case_combination.length()/2-1]);
				upper_case_combination[upper_case_combination.length()/2] = std::toupper(upper_case_combination[upper_case_combination.length()/2]);
				upper_case_combination[upper_case_combination.length()-1] = std::toupper(upper_case_combination[upper_case_combination.length()-1]);
				vector_of_combinations.push_back(combination);
				vector_of_combinations.push_back(upper_case_combination);
				return_combinations.push_back(vector_of_combinations);
			} else {
				std::string upper_case_combination = combination;
				upper_case_combination[0] = std::toupper(upper_case_combination[0]);
				upper_case_combination[upper_case_combination.length()/2] = std::toupper(upper_case_combination[upper_case_combination.length()/2]);
				upper_case_combination[upper_case_combination.length()-1] = std::toupper(upper_case_combination[upper_case_combination.length()-1]);
				vector_of_combinations.push_back(combination);
				vector_of_combinations.push_back(upper_case_combination);
				return_combinations.push_back(vector_of_combinations);
			}
		}
	} else if (letter_case == "3a") {
		for (const std::string& combination : combinations) {
			vector_of_combinations.clear();
			std::string upper_case_combination = combination;
			for (int i = 0; i < upper_case_combination.length(); i++) {
				if (i % 2 == 0) {
					upper_case_combination[i] = std::toupper(upper_case_combination[i]);
				}
			}
			vector_of_combinations.push_back(combination);
			vector_of_combinations.push_back(upper_case_combination);
			return_combinations.push_back(vector_of_combinations);
		}
	} else if (letter_case == "3b") {
		for (const std::string& combination : combinations) {
			vector_of_combinations.clear();
			std::string upper_case_combination = combination;
			for (int i = 0; i < upper_case_combination.length(); i++) {
				if (i % 2 == 1) {
					upper_case_combination[i] = std::toupper(upper_case_combination[i]);
				}
			}
			vector_of_combinations.push_back(combination);
			vector_of_combinations.push_back(upper_case_combination);
			return_combinations.push_back(vector_of_combinations);
		}
	} else if (letter_case == "4") {
		for (const std::string& combination : combinations) {
			std::string upper_case_combination;
			for (int i = 0; i < (1 << combination.length()); i++) {
				upper_case_combination = combination;
				for (int j = 0; j < combination.length(); j++) {
					if ((i >> j) & 1) {
						upper_case_combination[j] = std::toupper(upper_case_combination[j]);
					}
				}
			}
			vector_of_combinations.push_back(combination);
			vector_of_combinations.push_back(upper_case_combination);
			return_combinations.push_back(vector_of_combinations);
		}
	} else {
			return_combinations.push_back(combinations);
	}
	return return_combinations;
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
	twod_combinations.clear();
	combinations = convert_2d_vector_to_normal_vector(casing(combinations));
	for (const std::string& combination : combinations) {
		std::cout << "Combination: " << combination << '\n';
	}

	generated_combinations.clear();

	if (hash) {
		if (verbose) {
			std::ofstream output_file(output_file_name);
			std::vector<std::string> correct_length_combinations;
			correct_length_combinations.clear();
			for (const std::string &generated_combination : generated_combinations){
				if (generated_combination.length() >= minimal_combination_length && generated_combination.length() <= maximal_combination_length) {
					correct_length_combinations.push_back(generated_combination);

				}
				output_file << generated_combination << '\n';
			}
			casing(correct_length_combinations);
			output_file.close();
			std::cout << '\n' << "Combinations written to file: " << output_file_name << '\n';
			exit(0);
		} else {
			std::ofstream output_file(output_file_name);
			std::vector<std::string> correct_length_combinations;
			correct_length_combinations.clear();
			for (const std::string &generated_combination : generated_combinations){
				if (generated_combination.length() >= minimal_combination_length && generated_combination.length() <= maximal_combination_length) {
					correct_length_combinations.push_back(generated_combination);
				}
			}
			casing(correct_length_combinations);
			output_file.close();
			std::cout << '\n' << "Combinations written to file: " << output_file_name << '\n';
			exit(0);
		}
	}
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
			Generate generate;
			generate.casing(new_words);
			for (const std::string& new_word : new_words){
				generated_combinations.push_back(new_word);
			}
		}
	}
	return generated_combinations;
}