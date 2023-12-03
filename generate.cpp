#include <cmath>
#include <iostream>
#include <vector>

#include "generate.h"

Generate::Generate() {
	use_same_word_multiple_times_in_one = false;
	total_combinations = 0;
	total_words = 0;
}

void Generate::get_info(int minimal_combination_length,
                        int maximal_combination_length,
                        int letter_case,
                        std::vector<std::string> separator,
                        std::vector<std::vector<std::string>> combinations,
                        bool use_same_word_multiple_times_in_one) {

	this->minimal_combination_length = minimal_combination_length;
	this->maximal_combination_length = maximal_combination_length;
	this->letter_case = letter_case;
	this->separator = separator;
	this->combinations = combinations;
	this->use_same_word_multiple_times_in_one = use_same_word_multiple_times_in_one;
}

void Generate::calculate_number_of_combinations() {
	for (auto combination : combinations){
		total_words += combination.size();
	}
	total_combinations = total_words;
	if (!use_same_word_multiple_times_in_one){
		int multiplier = 4;
		for (int i = total_words - 2; i >= 0; i--){
			std::cout << "Multiplier: " << multiplier << '\n';
			total_combinations += total_words * multiplier;
			multiplier *= i;
		}
	} else {
		int multiplier = total_words;
		for (int i = total_words - 1; i > 0; i--){
			std::cout << "Multiplier: " << multiplier << '\n';
			total_combinations += total_words * multiplier;
			std::cout << "Total combinations: " << total_combinations << '\n';
			multiplier *= total_words;
		}
	}
	total_combinations *= pow(separator.size(), total_words);
	std::cout << total_combinations << '\n';
	Generate::generate_combinations();
}

void Generate::generate_combinations() {
	int created_combinations = 0;
	for (int i = 0; i < total_words; i++){
		
	}
}