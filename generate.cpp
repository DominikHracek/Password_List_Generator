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
                        const bool use_same_word_multiple_times_in_one) {

	this->minimal_combination_length = minimal_combination_length;
	this->maximal_combination_length = maximal_combination_length;
	this->letter_case = letter_case;
	this->separator = std::move(separator);
	this->twod_combinations = twod_combinations;
	this->use_same_word_multiple_times_in_one = use_same_word_multiple_times_in_one;
}

void Generate::calculate_number_of_combinations() {
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
			std::vector<std::string> temporary_combinations = generate_combinations_with_repetition(i, combinations, "", 0);
			for (const std::string& combination : temporary_combinations){
				generated_combinations.push_back(combination);
			}
		}
	} else {
        generated_combinations = generate_combinations_without_repetition(combinations);
	}
	std::ofstream output_file("generated_combinations.txt");
	for (const std::string& combination : generated_combinations) {
		output_file << combination << '\n';
		std::cout << combination << '\n';
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
		std::vector<std::string> new_words = generate_combinations_with_repetition(combination_length, words, combination + word, current + 1);
		for (const std::string& new_word : new_words){
			generated_combinations.push_back(new_word);
		}
	}
	return generated_combinations;
}

std::vector<std::string> Generate::generate_combinations_without_repetition(std::vector<std::string> v) {
	std::vector<std::string> permutations;
	std::sort(v.begin(), v.end());
	for (int i = 1; i <= v.size(); i++) {
		do {
			std::string permutation;
			for (int j = 0; j < i; j++) {
				permutation += v[j];
			}
			if (std::count(permutations.begin(), permutations.end(), permutation) == 0) {
				permutations.push_back(permutation);
			}
		} while (std::next_permutation(v.begin(), v.end()));
	}
	return permutations;
}
