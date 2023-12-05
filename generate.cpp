#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>
#include <vector>

#include "generate.h"

Generate::Generate() {
	use_same_word_multiple_times_in_one = false;
	total_combinations = 0;
	total_words = 0;
	combinations = {};
}

void Generate::get_info(int minimal_combination_length,
                        int maximal_combination_length,
                        int letter_case,
                        std::vector<std::string> separator,
                        std::vector<std::vector<std::string>> twod_combinations,
                        bool use_same_word_multiple_times_in_one) {

	this->minimal_combination_length = minimal_combination_length;
	this->maximal_combination_length = maximal_combination_length;
	this->letter_case = letter_case;
	this->separator = separator;
	this->twod_combinations = twod_combinations;
	this->use_same_word_multiple_times_in_one = use_same_word_multiple_times_in_one;
}

void Generate::calculate_number_of_combinations() {
	for (auto combination : twod_combinations){
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
	std::cout << "Done converting 2d vector to normal one" << '\n';
	for (std::string combination : combinations){
		std::cout << combination << '\n';
	}

	for (int i = 1; i < combinations.size(); i++){
		generate_combinations(i, combinations, "", 1);
	}
	exit(0);
}

std::vector<std::string> Generate::convert_2d_vector_to_normal_vector(std::vector<std::vector<std::string>> twod_vector) {
	std::vector<std::string> converted_vector;
	for (int vector_in_2d_vector = 0; vector_in_2d_vector < twod_vector.size(); vector_in_2d_vector++){
		for (int element_in_vector = 0; element_in_vector < twod_vector[vector_in_2d_vector].size(); element_in_vector++){
			converted_vector.push_back(twod_vector[vector_in_2d_vector][element_in_vector]);
		}
	}
	return converted_vector;
}

std::vector<std::string> generateCombinations(const std::string& characters, int maxLength) {
  std::vector<std::string> combinations;

  // Generate combinations of length 1 to maxLength
  for (int length = 1; length <= maxLength; length++) {
    // Generate combinations using std::next_permutation
    std::string combination(length, characters[0]);
    combinations.push_back(combination);

    while (std::next_permutation(combination.begin(), combination.end())) {
      combinations.push_back(combination);
    }
  }

  return combinations;
}  