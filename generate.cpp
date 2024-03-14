#include <cmath>
#include <iostream>
#include <utility>
#include <sys/stat.h>

#include "generate.h"
//#include "hash.h"

/**
 * Constructor for the Generate class.
 */
Generate::Generate() {
	minimal_combination_length = 1;
	maximal_combination_length = 12;
	total_combinations = 0;
	total_separators = 0;
	total_words = 0;
	combinations = {};
	generated_combinations = {};
	hash_enabled = "";
	verbose = false;
}

/**
 * Sets the values of the member variables based on the input parameters.
 *
 * @param minimal_combination_length the minimal length of combinations to generate
 * @param maximal_combination_length the maximal length of combinations to generate
 * @param letter_case the letter case to use for generating combinations
 * @param separator the separator to use for separating combinations
 * @param twod_combinations the two-dimensional vector of combinations
 * @param output_file_name the name of the output file
 * @param hash_enabled the hash function to use
 * @param verbose whether to output verbose information
 */
void Generate::get_info(const int minimal_combination_length,
                        const int maximal_combination_length,
                        const std::string& letter_case,
                        std::vector<std::string> separator,
                        const std::vector<std::vector<std::string>>& twod_combinations,
                        const std::string& output_file_name,
                        const std::string& hash_enabled,
                        const bool verbose) {

	this->minimal_combination_length = minimal_combination_length;
	this->maximal_combination_length = maximal_combination_length;
	this->letter_case = letter_case;
	this->separator = std::move(separator);
	this->twod_combinations = twod_combinations;
	this->output_file_name = output_file_name;
	this->hash_enabled = hash_enabled;
	this->verbose = verbose;
}

/**
 * Generates combinations with different casings based on the specified letter_case.
 *
 * @param combinations the vector of strings containing combinations to be cased
 *
 * @return a vector of vectors of strings containing the cased combinations
 *
 * @throws None
 */
std::vector<std::vector<std::string>> Generate::casing(const std::vector<std::string>& combinations) {
	std::vector<std::vector<std::string>> return_combinations;
	std::vector<std::string> vector_of_combinations;
	if (letter_case == "0") {
		for (const std::string& combination : combinations) {
			vector_of_combinations.push_back(combination);
		}
		return_combinations.push_back(vector_of_combinations);
	} else if (letter_case == "1") {
		for (const std::string& combination : combinations) {
			bool is_a_number = false;
			vector_of_combinations.clear();
			std::string upper_case_combination = combination;
			if (bool has_been_switched = false; !has_been_switched) {
				for (int i = 0; i < combination.length(); i++) {
					if (std::isalpha(upper_case_combination[i])) {
						upper_case_combination[i] = std::toupper(upper_case_combination[i]);
						has_been_switched = true;
						break;
					}
					if (i == combination.length()-1) {
						is_a_number = true;
					}
				}
			}
			if (!is_a_number) {
				vector_of_combinations.push_back(upper_case_combination);
			}
			vector_of_combinations.push_back(combination);
			return_combinations.push_back(vector_of_combinations);
		}
	} else if (letter_case == "2") {
		for (const std::string& combination : combinations) {
			bool is_a_number = false;
			vector_of_combinations.clear();
			std::string upper_case_combination = combination;
			if (bool has_been_switched = false; !has_been_switched) {
				int first_alpha_index = 0;
				for (int i = 0; i < combination.length(); i++) {
					if (std::isalpha(upper_case_combination[i])) {
						first_alpha_index = i;
						if ((combination.length() - first_alpha_index) % 2 == 0) {
							upper_case_combination[i] = std::toupper(upper_case_combination[i]);
							upper_case_combination[(upper_case_combination.length() - first_alpha_index)/2-1] = std::toupper(upper_case_combination[(upper_case_combination.length() - first_alpha_index)/2-1]);
							upper_case_combination[(upper_case_combination.length() - first_alpha_index)/2] = std::toupper(upper_case_combination[(upper_case_combination.length() - first_alpha_index)/2]);
							upper_case_combination[(upper_case_combination.length() - first_alpha_index)/2+1] = std::toupper(upper_case_combination[(upper_case_combination.length() - first_alpha_index)/2+1]);
						} else {
							upper_case_combination[i] = std::toupper(upper_case_combination[i]);
							upper_case_combination[(upper_case_combination.length() - first_alpha_index)/2 + i] = std::toupper(upper_case_combination[(upper_case_combination.length() - first_alpha_index)/2 + i]);
							upper_case_combination[upper_case_combination.length() - first_alpha_index-1 + i] = std::toupper(upper_case_combination[upper_case_combination.length() - first_alpha_index - 1 + i]);
						}
						break;
					}
					if (i == combination.length() - 1) {
						is_a_number = true;
					}
				}
			}
			if (!is_a_number) {
				vector_of_combinations.push_back(upper_case_combination);
			}
			vector_of_combinations.push_back(combination);
			return_combinations.push_back(vector_of_combinations);
		}
	} else if (letter_case == "3a") {
		for (const std::string& combination : combinations) {
			bool is_a_number = false;
			vector_of_combinations.clear();
			std::string upper_case_combination = combination;
			if (bool has_been_switched = false; !has_been_switched) {
				int first_alpha_index = 0;
				for (int i = 0; i < combination.length(); i++) {
					if (std::isalpha(upper_case_combination[i])) {
						first_alpha_index = i;
						for (int j = 0; j < upper_case_combination.length() - first_alpha_index; j += 2) {
							upper_case_combination[j+i] = std::toupper(upper_case_combination[j+i]);
						}
						break;
					}
					if (i == combination.length() - 1) {
						is_a_number = true;
					}
				}
			}
			vector_of_combinations.push_back(upper_case_combination);
			vector_of_combinations.push_back(combination);
			return_combinations.push_back(vector_of_combinations);
		}
	} else if (letter_case == "3b") {
		for (const std::string& combination : combinations) {
			bool is_a_number = false;
			vector_of_combinations.clear();
			std::string upper_case_combination = combination;
			if (bool has_been_switched = false; !has_been_switched) {
				int first_alpha_index = 0;
				for (int i = 0; i < combination.length(); i++) {
					if (std::isalpha(upper_case_combination[i])) {
						first_alpha_index = i;
						for (int j = 1; j < upper_case_combination.length() - first_alpha_index; j += 2) {
							upper_case_combination[j+i] = std::toupper(upper_case_combination[j+i]);
						}
						break;
					}
					if (i == combination.length() - 1) {
						is_a_number = true;
					}
				}
			}
			vector_of_combinations.push_back(upper_case_combination);
			vector_of_combinations.push_back(combination);
			return_combinations.push_back(vector_of_combinations);
		}
	} else if (letter_case == "4a") {
		for (const std::string& combination : combinations) {
			bool is_a_number = false;
			vector_of_combinations.clear();
			std::string upper_case_combination = combination;
			if (bool has_been_switched = false; !has_been_switched) {
				int first_alpha_index = 0;
				for (int i = 0; i < combination.length(); i++) {
					if (std::isalpha(upper_case_combination[i])) {
						first_alpha_index = i;
						for (int j = 0; j < upper_case_combination.length() - first_alpha_index; j++) {
							upper_case_combination[j+i] = std::toupper(upper_case_combination[j+i]);
						}
						break;
					}
					if (i == combination.length() - 1) {
						is_a_number = true;
					}
				}
			}
			vector_of_combinations.push_back(upper_case_combination);
			vector_of_combinations.push_back(combination);
			return_combinations.push_back(vector_of_combinations);
		}
	} else if (letter_case == "4b") {
		//TODO Implement 4b (pow(2, length)-1)
	} else {
		std::cout << "Invalid letter case: " << letter_case << '\n';
		exit(1);
	}
	return return_combinations;
}



/**
 * Generates combinations based on the twod_combinations and separator.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void Generate::generate_combinations() {
	const char* output_file = output_file_name.c_str();
	struct stat sb;
	if (stat(output_file, &sb) == 0 && !(sb.st_mode & S_IFDIR)) {
		std::cout << "The file already exists. If you want want to delete it enter 'y': ";
		char choice;
		std::cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			std::cout << "Deleting file: " << output_file_name << '\n';
			std::remove(output_file);
		}
	}

	for (const auto& combination : twod_combinations){
		total_words += combination.size();
	}
	total_separators = separator.size();
	for (int i = total_words; i > 0; i--){
		total_combinations += std::pow(total_words, i) * std::pow(total_separators, i + 1);
	}
	std::cout << "Total combinations to be generated: " << total_combinations << '\n'; //TODO correct math
	combinations = convert_2d_vector_to_normal_vector(twod_combinations);

	for (int i = 1; i <= combinations.size(); i++){
		std::string empty_string;
		generate_combinations_with_repetition(i,
										combinations,
										separator,
										empty_string,
										0);
	}
	std::cout << '\n' << "Combinations written to file:" << output_file_name << '\n';
	exit(0);
}

/**
 * Converts a 2D vector of strings to a normal vector of strings.
 *
 * @param twod_vector The 2D vector to be converted
 *
 * @return The normal vector of strings
 *
 * @throws None
 */
std::vector<std::string> Generate::convert_2d_vector_to_normal_vector(const std::vector<std::vector<std::string>>& twod_vector) {
	std::vector<std::string> converted_vector;
	for (auto & vector_in_2d_vector : twod_vector){
		for (const auto & element_in_vector : vector_in_2d_vector){
			converted_vector.push_back(element_in_vector);
		}
	}
	return converted_vector;
}

/**
 * Generates combinations with repetition.
 *
 * @param combination_length the length of the combination
 * @param words the list of words to combine
 * @param separator the list of separators to use between words
 * @param combination the current combination being generated
 * @param current the current position in the combination
 *
 * @return a vector of generated combinations
 *
 * @throws No specific error is mentioned
 */
void Generate::generate_combinations_with_repetition(const int combination_length,
                                                     const std::vector<std::string>& words,
                                                     const std::vector<std::string>& separator,
                                                     std::string& combination,
                                                     const int current) {
	if (current == combination_length){
		if (verbose) {
			int previous_length = 0;
			std::ofstream output_file(output_file_name, std::ios::app);
			std::string previous_combination = combination;
			for (const std::string &sep : separator) {
				combination = previous_combination;
				combination += sep;
				if (combination.length() >= minimal_combination_length && combination.length() <= maximal_combination_length) {
					std::string to_be_written = combination;
					/*if (!hash_enabled.empty()) {
						Hash hash;
						hash.get_parameters(combination, hash_enabled);
						std::string hashed_combination = hash.get_hash(combination, hash_enabled);
						to_be_written = combination + ":" + hashed_combination;
					}*/
					std::cout << '\r' << to_be_written << std::flush;
					if (to_be_written.length() < previous_length) {
						const int difference = previous_length - to_be_written.length();
						std::cout << std::string(difference, ' ') << std::flush;
					}
					previous_length = to_be_written.length();
					output_file << to_be_written << '\n';
				}
			}
			output_file.close();
		} else {
			std::ofstream output_file(output_file_name, std::ios::app);
			std::string previous_combination = combination;
			for (const std::string &sep : separator) {
				combination = previous_combination;
				combination += sep;
				if (combination.length() >= minimal_combination_length && combination.length() <= maximal_combination_length) {
					std::string to_be_written = combination;
					/*if (!hash_enabled.empty()) {
						Hash hash;
						hash.get_parameters(combination, hash_enabled);
						std::string hashed_combination = hash.get_hash(combination, hash_enabled);
						to_be_written = combination + ":" + hashed_combination;
					}*/
					output_file << to_be_written << '\n';
				}
			}
			output_file.close();
		}
		return;
	}

	for (const std::string& word : words){
		std::string current_combination = combination;
		current_combination += word;
	}

	for (const std::string& word : words){
		for (const std::string& sep : separator){
			std::string new_word = combination + sep + word;
			generate_combinations_with_repetition(combination_length, words, separator, new_word, current + 1);
		}
	}
}
