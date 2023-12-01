#include <iostream>

#include "generate.h"

Generate::Generate() {
	use_same_word_multiple_times_in_one = false;
}

void Generate::get_info() {}

void Generate::generate_combinations() {
	int total_words;
	for (auto combination : combinations){
		total_words += combination.size();
	}
	for (int i = minimal_combination_length; i <=maximal_combination_length; i++){
		int total_combinations = total_words;
		if (!use_same_word_multiple_times_in_one){
			int multiplier = 1;
			for (int i = total_words - 1; i > 0; i--){
				std::cout << multiplier << '\n';
				multiplier *= i;
				total_combinations += total_words * multiplier;
			}
			std::cout << multiplier << '\n';
		} else {
		int multiplier = 1;
		for (int i = total_words - 1; i > 0; i--){
		std::cout << multiplier << '\n';
		multiplier *= 5;
		total_combinations += total_words * multiplier;
		}
		std::cout << multiplier << '\n';
		}
	}
	exit(0);
}