#include <cctype>
#include <chrono>
#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

#include "generate.h"
#include "get_info.h"

#include "help.h"

/**
 * Constructor for the Get_Info class.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
Get_Info::Get_Info(){
    minimal_combination_length = 0;
    maximal_combination_length = 12;
    
    separators_file_name = "";
    separators_line = 1;
    separators = {
        {""," ","-","_","/","\\"},
        {""," ","-","_","/","\\","!",";",":","'","\""},
        {""," ","-","_","/","\\","!",";",":","'","\"","|","@","#","$","%"},
        {""," ","-","_","/","\\","!",";",":","'","\"","|","@","#","$","%","^","&","*",",","."},
        {""," ","-","_","/","\\","!",";",":","'","\"","|","@","#","$","%","^","&","*",",",".","[","]","{","}"},
        {""," ","-","_","/","\\","!",";",":","'","\"","|","@","#","$","%","^","&","*",",",".","[","]","{","}","+","=","<",">"},
        {""," ","-","_","/","\\","!",";",":","'","\"","|","@","#","$","%","^","&","*",",",".","[","]","{","}","+","=","<",">","?","~","`"}};
    separator = {""," ","-","_","/","\\"};

    letter_case = '0';

    input_file_name = "";
    words = {};
    patterns_of_words = {};

    output_file_name = "generated_passwords.txt";

    verbose = false;
}

/**
 * Get the arguments from the command line and parse them.
 *
 * @param argc the number of command line arguments
 * @param argv an array of C-strings containing the command line arguments
 *
 * @throws None
 */
void Get_Info::get_arguments(const int argc, char *argv[]) {
    for (int i = 1; i < argc; i += 2) {
        std::string arg = argv[i];
        std::string possible_value;
        if (i + 1 < argc) {
            possible_value = argv[i + 1];
        }

        if (arg == "-n" || arg == "--min") {
            if (i + 1 < argc && possible_value.find('-') == -1) {
                minimal_combination_length = std::stoi(argv[i + 1]);
            } else {
                std::cout << "Error: Missing value for -n/--min argument" << '\n';
                exit(0);
            }
        } else if (arg == "-x" || arg == "--max") {
            if (i + 1 < argc && possible_value.find('-') == -1) {
                maximal_combination_length = std::stoi(argv[i + 1]);
            } else {
                std::cout << "Error: Missing value for -x/--max argument" << '\n';
                exit(0);
            }
        } else if (arg == "-r" || arg == "--char") {
            if (i + 1 < argc && possible_value.find('-') == -1) {
                std::string character_file_checker = argv[i + 1];
                if (character_file_checker.find(',') != -1) {
                    separators_file_name = character_file_checker.substr(0, character_file_checker.find(','));
                    separators_line = std::stoi(character_file_checker.substr(character_file_checker.find(',') + 1));
                    get_separators(separators_file_name, separators_line);
                } else {
                    try {
                        separators_line = std::stoi(argv[i + 1]);
                        get_separators(separators_line);
                    } catch (std::invalid_argument&) {
                        separators_file_name = argv[i + 1];
                        get_separators(separators_file_name, separators_line);
                    }
                }
            } else {
                std::cout << "Error: Missing value for -r/--char argument" << '\n';
                exit(0);
            }
        } else if (arg == "-c" || arg == "--case") {
            if (i + 1 < argc && possible_value.find('-') == -1) {
                letter_case = argv[i + 1];
            } else {
                std::cout << "Error: Missing value for -c/--case argument" << '\n';
                exit(0);
            }
        } else if (arg == "-f" || arg == "--file") {
            if (i + 1 < argc && possible_value.find('-') == -1) {
                input_file_name = argv[i + 1];
            } else {
                std::cout << "Error: Missing value for -f/--file argument" << '\n';
                exit(0);
            }
        } else if (arg == "-o" || arg == "--output") {
            if (i + 1 < argc && possible_value.find('-') == -1) {
                output_file_name = argv[i + 1];
            } else {
                std::cout << "Error: Missing value for -o/--output argument" << '\n';
                exit(0);
            }
        } else if (arg == "-v" || arg == "--verbose") {
            verbose = true;
        } else {
            std::cout << "Error: Unknown argument " << '\"' << arg << '\"' << '\n';
            exit(1);
        }
    }
}

/**
 * Trims leading and trailing whitespace from the input string.
 *
 * @param string the input string to be trimmed
 *
 * @return the trimmed string
 *
 * @throws N/A
 */
std::string trim(const std::string& string) {
  const auto *whitespace = " \t\n\r\f\v";
  const size_t begin = string.find_first_not_of(whitespace);
  if (begin == std::string::npos) {
    return std::string{};
  }
  const size_t end = string.find_last_not_of(whitespace);
  return string.substr(begin, end - begin + 1);
}

/**
 * Checks if everything is ok and prompts for user input if not.
 *
 * @return void
 *
 * @throws N/A
 */
void Get_Info::is_everything_ok() {
    std::cout << "Is everything ok? [Y/n]: ";
    std::string output_check;
    std::getline(std::cin, output_check);
    for (char &character : output_check) {
        character = std::tolower(character);
    }
    output_check = trim(output_check);
    std::cin.clear();

    if (output_check == "y" || output_check == "yes" || output_check.empty()) {
        Generate generate;
        generate.get_info(minimal_combination_length,
                          maximal_combination_length,
                          letter_case,
                          separator,
                          combinations,
                          output_file_name,
                          verbose);
        generate.generate_combinations();
    } else {
        //TODO make sure, everything is working in this condition
        int whats_wrong;

        bool invalid_choice;
        do {
            invalid_choice = false;
            std::cout << '\t' << "1) Minimal length" << '\n';
            std::cout << '\t' << "2) Maximal length" << '\n';
            std::cout << '\t' << "3) Case-sensitivity level" << '\n';
            std::cout << '\t' << "4) Character set" << '\n';
            std::cout << '\t' << "5) Verbosity" << '\n';
            std::cout << '\t' << "6) Files" << '\n';
            std::cout << '\t' << "7) Combinations" << '\n';
            std::cout << '\t' << "8) Exit" << '\n';
            std::cout << "What's wrong: ";
            std::cin >> whats_wrong;
            std::cin.clear();

            invalid_choice = false;
            bool invalid_choice_inner = false;

            switch (whats_wrong) {
                case 1:
                    std::cout << "New minimal length: ";
                    std::cin >> minimal_combination_length;
                    break;
                case 2:
                    std::cout << "New maximal length: ";
                    std::cin >> maximal_combination_length;
                    break;
                case 3:
                    Help::show_case();
                    std::cout << '\n' << '\n';
                    std::cout << "New case-sensitivity level: ";
                    std::cin >> letter_case;
                    break;
                case 4:
                    do {
                        invalid_choice_inner = false;
                        std::cout << "1) File name" << '\n';
                        std::cout << "2) File line" << '\n';
                        std::cout << "3) Back" << '\n';
                        int file_checker;
                        std::cin >> file_checker;
                        switch (file_checker) {
                            case 1:
                                std::cout << "New file name: ";
                                std::getline(std::cin, separators_file_name);
                                get_separators(separators_file_name, separators_line);
                                break;
                            case 2:
                                std::cout << "New file line: ";
                                std::cin >> separators_line;
                                get_separators(separators_line);
                                break;
                            case 3:
                                break;
                            default:
                                invalid_choice_inner = true;
                                break;
                        }
                    } while (invalid_choice_inner);
                    break;
                case 5:
                    std::cout << "1) Enable" << '\n';
                    std::cout << "2) Disable" << '\n';
                    break;
                case 6:
                    std::cout << "Files" << '\n';
                    std::cout << "1) File with separators" << '\n';
                    std::cout << "2) Input file name (words)" << '\n';
                    std::cout << "3) Output file name (combinations)" << '\n';
                    break;
                case 7:
                    std::cout << "Combinations" << '\n';
                    //TODO make sure, everything is working in this condition
                    break;
                case 8:
                    break;
                default:
                    std::cout << "Incorrect number" << '\n';
                    invalid_choice = true;
                    break;
            }
        } while (invalid_choice);
    }
    std::cin.ignore();
    start_ui();
}

/**
 * Starts the user interface and displays information about the password list generator,
 * including combination length, case-sensitivity level, character set, verbose mode,
 * input and output file names, and generated passwords. It also handles possible errors.
 */
void Get_Info::start_ui() {
    #ifdef _WIN64
        std::system("cls");
    #else
        std::system("clear");
    #endif

    std::cout << ">>>>>>>>>>>>>>>>>>>>>Khakis's Password List Generator<<<<<<<<<<<<<<<<<<<<<" << '\n';
    std::cout << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(25));

    std::cout << "Minimal combination length: " << minimal_combination_length << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(25));

    std::cout << "Maximal combination length: " << maximal_combination_length << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(25));

    std::cout << "Case-sensitivity level: " << letter_case << "/" << 4 << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(25));

    if (separators_file_name.empty()) {
        if (separators_line < 1) {
            std::cout << "Each file's first line starts at index 1 -> index has been set to 1" << '\n';
            separators_line = 1;
        } else if (separators_line > 7) {
            //TODO check if this is possible even is a separators file is used
            std::cout << "Unsupported separator line index, please check the help page for -r/--char with";
            std::cout << "./kplg -h/--help -r/--char";
        } else {
            std::cout << "Character set:" << '\n';
            std::cout << '\t' << "Character file: " << "internal" << '\n';
            std::cout << '\t' << "Character line: " << separators_line << '\n';
            std::cout << '\t' << "Characters: ";
            for (const std::string& one_of_separators : separator){
                std::cout << one_of_separators << " ";
            }
            std::cout << '\n';
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
        }
    } else {
        std::cout << "Character set:" << '\n';
        std::cout << '\t' << "Character file: " << separators_file_name << '\n';
        std::cout << '\t' << "Character line: " << separators_line << '\n';
        std::cout << '\t' << "Characters: ";
        for (const std::string& one_of_separators : separator){
          std::cout << one_of_separators << " ";
        }
        std::cout << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(25));

    }
    std::cout << '\n';

    std::cout << "Verbose mode: " << (verbose ? "Active" : "Inactive") << '\n';

    std::cout << '\n';

    if (input_file_name.empty()) {
        std::cout << "File with words: " << "None" << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    } else {
        std::cout << "File with words: " << input_file_name << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }

    std::cout << "Output file name: " << output_file_name << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(25));

    std::cout << "Combinations: " << '\n';
    for (int i = 0; i < combinations.size(); i++) {
        std::cout << '\t' << words[i] << '\n';
        for (const auto & j : combinations[i]) {
            std::cout << '\t' << '\t' << j << '\n';
        }
    }
    std::cout << '\n';

    std::cout << "File with generated passwords: " << output_file_name << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    is_everything_ok();
    std::cout << '\n' << '\n';
}

/**
 * Retrieves separators from a specified file at a given line number, and populates the separators container.
 *
 * @param separators_file_name the name of the file containing the separators
 * @param line the line number from which to retrieve the separators
 *
 * @throws N/A
 */
void Get_Info::get_separators(const std::string& separators_file_name,const int line) {
    separators.clear();
    separators_file.open(separators_file_name);

    std::string line_being_read;
    int currently_read_line = 0;
    while (std::getline(separators_file, line_being_read) && currently_read_line < line) {
        std::stringstream ss(line_being_read);
        std::vector<std::string> subvector;
        std::string element_in_subvector;
        while (std::getline(ss, element_in_subvector, ',')){
            subvector.push_back(element_in_subvector);
        }
        separators.push_back(subvector);
        currently_read_line++;
    }

    if (line >= 1 && line <= separators.size()) {
        separator = separators[line - 1];
    }
    separators_file.close();
}

/**
 * Retrieves the separator at the specified index from the list of separators.
 *
 * @param line the index of the separator to retrieve
 *
 * @return void
 *
 * @throws None
 */
void Get_Info::get_separators(const int line) {
    if (line >= 1 && line <= separators.size()) {
        separator = separators[line - 1];
    }
}

/**
 * Reads the content of the input file and stores each line as a word in the
 * 'words' vector.
 *
 * @param input_file_name the name of the input file to be read
 *
 * @return void
 *
 * @throws N/A
 */
void Get_Info::get_words(const std::string& input_file_name) {
    words.clear();
    input_file.open(input_file_name);
    std::string line_being_read;
    while (std::getline(input_file, line_being_read)) {
        words.push_back(line_being_read);
    }
    input_file.close();
}

/**
 * A method to get words from the user input, lowercase them, and add them to a list.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void Get_Info::get_words() {
    std::cout << "Enter words to combine (separate with commas(,)).\nEverything will be lowercased: ";
    std::string words_to_add;
    std::getline(std::cin, words_to_add);

    std::stringstream stringstream(words_to_add);
    std::string substring;
    while (std::getline(stringstream, substring, ',')) {
        for (char &character : substring) {
            character = std::tolower(character);
        }
        substring = trim(substring);
        words.push_back(substring);
    }
    std::cin.clear();
}

/**
 * Asks for patterns and combinations of words from input file or standard input.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void Get_Info::ask_for_patterns() {
    if (input_file_name.empty()) {
        get_words();
    } else {
        get_words(input_file_name);
    }

    for (const std::string& word : words) {
        std::cout << "Enter all combination of the word: '" << word << "' (combination -> comb,combin) that should be used: ";
        std::string combinaton_to_use;
        std::getline(std::cin, combinaton_to_use);

        std::stringstream stringstream(combinaton_to_use);
        std::string combination;
        std::vector<std::string> word_combinations;
        word_combinations.push_back(word);
        while (std::getline(stringstream, combination, ',')) {
            for (char &character : combination) {
                character = std::tolower(character);
            }
            combination = trim(combination);
            word_combinations.push_back(combination);
        }
        combinations.push_back(word_combinations);
        std::cin.clear();
    }
}