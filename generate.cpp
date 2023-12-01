#include <iostream>
#include <vector>

#include "generate.h"

Generate::Generate() {
	use_same_word_multiple_times_in_one = false;
	total_combinations = 0;
}

void Generate::get_info(int minimal_combination_length,
                        int maximal_combination_length,
                        int letter_case,
                        std::vector<std::string> separator,
                        std::vector<std::vector<std::string>> combinations) {

	this->minimal_combination_length = minimal_combination_length;
	this->maximal_combination_length = maximal_combination_length;
	this->letter_case = letter_case;
	this->separator = separator;
	this->combinations = combinations;
}

void Generate::calculate_number_of_combinations() {
	int total_words = 0;
	for (auto combination : combinations){
		total_words += combination.size();
	}
	for (int i = minimal_combination_length; i <=maximal_combination_length; i++){
		total_combinations = total_words;
		if (!use_same_word_multiple_times_in_one){
			int multiplier = 1;
			for (int i = total_words - 1; i > 0; i--){
				multiplier *= i;
				total_combinations += total_words * multiplier;
			}
		} else {
			int multiplier = 1;
			for (int i = total_words - 1; i > 0; i--){
				multiplier *= 5;
				total_combinations += total_words * multiplier;
			}
		}
	}
	Generate::generate_combinations();
}

void Generate::generate_combinations() {}