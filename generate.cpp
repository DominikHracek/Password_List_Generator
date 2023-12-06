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
	std::vector<std::string> words_without_repetition = combinations;
	std::cout << "Done converting 2d vector to normal one" << '\n';

	if (use_same_word_multiple_times_in_one){
		for (int i = 1; i <= combinations.size(); i++){
			generate_combinations_with_repetition(i, combinations, "", 0);
		}
	} else {
          for (int i = 1; i <= combinations.size(); i++){
            generate_combinations_without_repetition(i, combinations, "", 0);
          }
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

void Generate::generate_combinations_with_repetition(int combination_length,
                                                     std::vector<std::string> words,
                                                     std::string combination,
                                                     int current) {
	if (current == combination_length){
		std::cout << combination << '\n';
		return;
	}

	for (std::string word : words){
		std::string current_combination = combination;
		current_combination += word;
	}

	for (std::string word : words){
		generate_combinations_with_repetition(combination_length, words, combination + word, current + 1);
	}
}

void Generate::generate_combinations_without_repetition(int combination_length,
                                                        std::vector<std::string> words_without_repetition,
                                                        std::string combination,
                                                        int current) {

	if (current == combination_length){
		std::cout << combination << '\n';
		return;
	}

	for (std::string word : words_without_repetition){
		std::string current_combination = combination;
		current_combination += word;
	}

	for (std::string word : words_without_repetition){
		auto remove_word = find(words_without_repetition.begin(), words_without_repetition.end(), word);
		if (remove_word != words_without_repetition.end()){
			words_without_repetition.erase(remove_word);
		}
		generate_combinations_without_repetition(combination_length, words_without_repetition, combination, current);
	}
}