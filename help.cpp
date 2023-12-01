#include <chrono>
#include <iostream>
#include <thread>

#include "help.h"

void Help::show_general_help() {
  std::cout << "Thanks for using Khakis's Password List Generator" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\n';
  std::cout << "Usage ./kplg [OPTIONS] -w" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << "Usage ./kplg --help [OPTION]" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << "DO NOT USE -w/--words AND -f/--file AT THE SAME TIME," << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << "IF YOU DO SO, -f/--file HAS PRIVILEGE AND IF NOT FOUND -w/--words WILL BE IGNORED";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << '\n';
  std::cout << '\n';
  std::cout << '\n';
  std::cout << "Options:" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "-h" << " " << "|" << " " << "--help" << '\t' << "Shows this page" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "-n" << " " << "|" << " " << "--min" << '\t' << "Minimal number of characters (default: 0)" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "-x" << " " << "|" << " " << "--max" << '\t' << "Maximal number of characters (default: 12)" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "-m" << " " << "|" << " " << "--multiple" << '\t' << "Same word multiple times in one combination (if not specified, every word is used only ones)" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "-r" << " " << "|" << " " << "--char" << '\t' << "What characters to use between words" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "-c" << " " << "|" << " " << "--case" << '\t' << "Upper/Lowercase settings" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "-f" << " " << "|" << " " << "--file" << '\t' << "Load words from a file" << '\n';
  // Template: std::cout << '\t' << "-" << " " << "|" << " " << "--" << '\t' << "" << '\n';
}
void Help::show_minimal_character_length(){
  std::cout << "Usage:" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg -n" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg --min" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\n';
  std::cout << "Sets the minimal length of generated combinations" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\n';
  std::cout << "Example:" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg -n 8" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg --min 8" << '\n';
}

void Help::show_maximal_character_length(){
  std::cout << "Usage:" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg -x" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg --max" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\n';
  std::cout << "Sets the maximal length of generated combinations" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\n';
  std::cout << "Example:" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg -m 16" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg --max 16" << '\n';
}

void Help::show_use_multiple_times(){
  std::cout << "Specifies, whether to allow a combination to have the same word multipletimes(testcombinationtest)" << '\n';
  std::cout << "                                                                              ^^^^           ^^^^" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << "Usage and example:" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg -m" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg --multiple" << '\n';
}

void Help::show_characters(){
  std::cout << "Internal word separators (used when <separator_file> not specified) << '\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "1) - _ / \\ " << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "2) - _ / \\ ! ; : \" \'" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "3) - _ / \\ ! ; : \" \' | @ # $ %" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "4) - _ / \\ ! ; : \" \' | @ # $ % ^ & * , ." << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "5) - _ / \\ ! ; : \" \' | @ # $ % ^ & * , . [ ] { }" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "6) - _ / \\ ! ; : \" \' | @ # $ % ^ & * , . [ ] { } + = < >" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "7) - _ / \\ ! ; : \" \' | @ # $ % ^ & * , . [ ] { } + = < > ? ~ `" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\n';
  std::cout << '\n';
  std::cout << "Usage:" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg -r <(separator_file,)line_in_file>" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg --char <(separator_file,)line_in_file>" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\n';
  std::cout << "Decides what sepatators (word-word, word_word, wordword) to use to increase the probability of getting the right password" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\n';
  std::cout << "If <separator_file> not specified, internal separators from help page are used";
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << "Example:" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg -r 2 (2 separator in help page)" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg --char my_characters.txt,15 (line 15 in file my_characters.txt)" << '\n';
}

void Help::show_case(){
  std::cout << "Usage:" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg -c" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg --case" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\n';
  std::cout << "Decides, how much are letters switched from upper to lower case (0-n)" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "0 - Leave as it is" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "1  - Create all combinations of switching the first letter of every word (word word, word Word, Word word, Word Word)";
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "2  - Same as 1, but with first, the middle one (both middle ones, if even amount of characters in word) and last)";
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "3a - With odd indexed characters (LiKe ThIs)" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "3b - With even indexed characters (lIkE tHiS)" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "4  - Every character (one, onE, oNe, oNE, One, OnE, ONe, ONE)" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\n';
  std::cout << "Example:" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg -c 1" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg --case 1" << '\n';
}

void Help::show_file(){
  std::cout << "Usage:" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg -f" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg --file" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\n';
  std::cout << "Specifies the file, where to load the words to combine from" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\n';
  std::cout << "Example:" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg -f words.txt" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(25));
  std::cout << '\t' << "./kplg --file words" << '\n';
}
