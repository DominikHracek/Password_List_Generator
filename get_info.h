#ifndef GET_INFO_H
#define GET_INFO_H

#include <fstream>
#include <string>
#include <vector>

class Get_Info {
  public:
    Get_Info();
    void get_arguments(int argc, char *argv[]);

    std::string new_word();
    void modify_word();
    void is_everything_ok();
    void start_ui();
    static bool fileExists(const std::string& fileName);
    void get_separators(const std::string& separators_file_name, int line);
    void get_separators(int line);
    void get_words(const std::string& input_file_name);
    void get_words();
    void ask_for_patterns();

  private:
    int minimal_combination_length;
    int maximal_combination_length;

    std::ifstream separators_file;
    std::string separators_file_name;
    int separators_line;
    std::vector<std::vector<std::string>> separators;
    std::vector<std::string> separator;

    std::string letter_case;

    std::string input_file_name;
    std::ifstream input_file;

    std::vector<std::string> words;
    std::vector<char> patterns_of_words;

    std::vector<std::string> word_combinations;
    std::vector<std::vector<std::string>> combinations;

    std::string output_file_name;
    std::ifstream output_file;

    std::string hash_enabled;

    bool verbose;
};

class FileNotFoundException : public std::runtime_error {
  public:
    explicit FileNotFoundException(const std::string& fileName) : std::runtime_error("File not found: " + fileName) {}
};

#endif