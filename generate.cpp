#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>

#include "generate.h"

Generate::Generate() {
	use_same_word_multiple_times_in_one = false;
	total_combinations = 0;
	total_words = 0;
	combinations = {};
	generated_combinations = {};
}

void Generate::get_info(const int minimal_combination_length,
                        const int maximal_combination_length,
                        const int letter_case,
                        std::vector<std::string> separator,
                        const std::vector<std::vector<std::string>>& twod_combinations,
                        const bool use_same_word_multiple_times_in_one,
                        const std::string output_file_name) {

	this->minimal_combination_length = minimal_combination_length;
	this->maximal_combination_length = maximal_combination_length;
	this->letter_case = letter_case;
	this->separator = std::move(separator);
	this->twod_combinations = twod_combinations;
	this->use_same_word_multiple_times_in_one = use_same_word_multiple_times_in_one;
	this->output_file_name = output_file_name;
}

void Generate::generate_combinations() {
	for (const auto& combination : twod_combinations){
		total_words += combination.size();
	}
	total_combinations = total_words;
	if (!use_same_word_multiple_times_in_one){
		int multiplier = 4;
		for (int i = total_words - 2; i >= 0; i--){
			total_combinations += total_words * multiplier;
			multiplier *= i;
		}
	} else {
		int multiplier = total_words;
		for (int i = total_words - 1; i > 0; i--){
			total_combinations += total_words * multiplier;
			multiplier *= total_words;
		}
	}
	//total_combinations *= pow(separator.size(), total_words);
	std::cout << "Total generated combinations: " << total_combinations << '\n';
	combinations = convert_2d_vector_to_normal_vector(twod_combinations);
	std::vector<std::string> words_without_repetition = combinations;

	generated_combinations.clear();
	if (use_same_word_multiple_times_in_one){
		for (int i = 1; i <= combinations.size(); i++){
			std::vector<std::string> temporary_combinations = generate_combinations_with_repetition(i, combinations, separator, "", 0);
			for (const std::string& combination : temporary_combinations){
				for (const std::string &sep : separator) {
					generated_combinations.push_back(combination + sep);
				}
			}
		}
	} else {
        std::vector<std::string> temporary_combinations = generate_combinations_without_repetition(combinations, separator);
		for (const std::string &combination : temporary_combinations) {
			for (const std::string &sep : separator) {
				generated_combinations.push_back(sep + combination);
			}
		}
	}
	std::ofstream output_file(output_file_name);
	for (const std::string& combination : generated_combinations) {
		output_file << combination << '\n';
	}
	output_file.close();
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

/*std::vector<std::string> Generate::generate_combinations_without_repetition(std::vector<std::string> words, const std::vector<std::string>& separators) {
	std::vector<std::string> permutations;
	std::sort(words.begin(), words.end());
	std::vector<std::string> combinations;
	for (int i = 1; i <= words.size(); i++) {
		do {
			std::string original_permutation;
			permutations.clear();
				for (int j = 0; j < i; j++) {
					std::string permutation = original_permutation;
					permutation += words[j];
					permutations.push_back(permutation);
					permutation = original_permutation;
					for (const std::string &separator : separators) {
						permutation += separator;
						original_permutation = permutation;
					}
				}
			//TODO: separator should be added between words (test-random, test_random, etc.)
			for (const std::string& permutation : permutations) {
				if (std::count(combinations.begin(), combinations.end(), permutation) == 0) {
					combinations.push_back(permutation);
				}
			}
		} while (std::next_permutation(words.begin(), words.end()));
	}
	return combinations;
}*/
