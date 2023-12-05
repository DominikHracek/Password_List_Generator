/*
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

void generateCombinations(const std::vector<std::string>& words, std::string currentCombination, std::unordered_set<std::string>& usedWords) {
    if (currentCombination.size() > 0) {
        std::cout << currentCombination << std::endl;
    }
    
    for (const std::string& word : words) {
        if (usedWords.find(word) == usedWords.end()) {
            usedWords.insert(word);
            generateCombinations(words, currentCombination + word, usedWords);
            usedWords.erase(word);
        }
    }
}

int main() {
  std::vector<std::string> words = {"samsung", "word", "random"};
  std::unordered_set<std::string> usedWords;
  generateCombinations(words, "", usedWords);

  return 0;
}*/
/*
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

void generateCombinations(const std::vector<std::string>& words, std::string currentCombination, std::unordered_set<std::string>& usedWords, int lastWordIndex) {
  if (currentCombination.size() > 0) {
    std::cout << currentCombination << std::endl;
  }
   
  for (int i = lastWordIndex; i < words.size(); i++) {
    const std::string& word = words[i];
    usedWords.insert(word);
    generateCombinations(words, currentCombination + word, usedWords, i);
    usedWords.erase(word);
  }
}*/

/*
int main() {
  std::vector<std::string> words = {"samsung", "word", "random"};
  std::unordered_set<std::string> usedWords;
  generateCombinations(words, "", usedWords, 0);

  return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>

/**
* @brief Generates all possible combinations of characters from a given set.
*
* This function takes a set of characters and a maximum length and generates all possible
* combinations of characters from the set, ranging from length 1 to the maximum length.
*
* @param characters The set of characters to generate combinations from.
* @param maxLength The maximum length of the combinations.
* @return std::vector<std::string> A vector containing all the generated combinations.
*/
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

int main() {
  std::string characters;
  int maxLength;

  // Ask the user to input the set of characters
  std::cout << "Enter a set of characters: ";
  std::cin >> characters;

  // Ask the user to input the maximum length
  std::cout << "Enter the maximum length: ";
  std::cin >> maxLength;

  // Generate combinations
  std::vector<std::string> combinations = generateCombinations(characters, maxLength);

  // Print the generated combinations
  std::cout << "Generated combinations:\n";
  for (const std::string& combination : combinations) {
    std::cout << combination << "\n";
  }

  return 0;
}