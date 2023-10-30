#include <iostream>

#include "help.h"

void Help::show_general_help() {
  std::cout << "Thanks for using Khakis's Password List Generator" << '\n';
  std::cout << '\n';
  std::cout << "Usage ./kplg [OPTIONS]" << '\n';
  std::cout << "Usage ./kplg --help [OPTION]" << '\n';
  std::cout << '\n';
  std::cout << "Options:" << '\n';
  std::cout << '\t' << "-h" << " " << "|" << " " << "--help" << '\t' << "Shows this page" << '\n';
  std::cout << '\t' << "-n" << " " << "|" << " " << "--min" << '\t' << "Minimal number of characters" << '\n';
  std::cout << '\t' << "-x" << " " << "|" << " " << "--max" << '\t' << "Maximal number of characters" << '\n';
  std::cout << '\t' << "-r" << " " << "|" << " " << "--char" << '\t' << "What characters to use between words TODO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  std::cout << '\t' << "-c" << " " << "|" << " " << "--case" << '\t' << "Upper/Lowercase settings" << '\n';
  std::cout << '\t' << "-f" << " " << "|" << " " << "--file" << '\t' << "Load words from a file" << '\n';
  // Template: std::cout << '\t' << "-" << " " << "|" << " " << "--" << '\t' << "" << '\n';
}
void Help::show_minimal_character_length(){
  std::cout << "Usage:" << '\n';
  std::cout << '\t' << "./kplg -n" << '\n';
  std::cout << '\t' << "./kplg --min" << '\n';
  std::cout << '\n';
  std::cout << "Sets the minimal length of generated combinations" << '\n';
  std::cout << '\n';
  std::cout << "Example:" << '\n';
  std::cout << '\t' << "./kplg -n 8" << '\n';
  std::cout << '\t' << "./kplg --min 8";
}

void Help::show_maximal_character_length(){
  std::cout << "Usage:" << '\n';
  std::cout << '\t' << "./kplg -x" << '\n';
  std::cout << '\t' << "./kplg --max" << '\n';
  std::cout << '\n';
  std::cout << "Sets the maximal length of generated combinations" << '\n';
  std::cout << '\n';
  std::cout << "Example:" << '\n';
  std::cout << '\t' << "./kplg -m 16" << '\n';
  std::cout << '\t' << "./kplg --max 16";
}

void Help::show_characters(){
  std::cout << "Usage:" << '\n';
  std::cout << '\t' << "./kplg -r" << '\n';
  std::cout << '\t' << "./kplg --char" << '\n';
  std::cout << '\n';
  std::cout << "Decides what characters are going to be used between words (word-word, word_word, wordword) to increase the probability of getting the right password" << '\n';
  // std::cout << "Characters are chosen from characters.kplg (Khakis's Password List Generator)";
  std::cout << '\n';
  std::cout << "Example:" << '\n';
  std::cout << '\t' << "./kplg -r TO-DO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << '\n';
  std::cout << '\t' << "./kplg --char TO-DO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
}

void Help::show_case(){
  std::cout << "Usage:" << '\n';
  std::cout << '\t' << "./kplg -c" << '\n';
  std::cout << '\t' << "./kplg --case" << '\n';
  std::cout << '\n';
  std::cout << "Decides, how much are letters switched from upper to lower case (0-n)" << '\n';
  std::cout << '\t' << "1  - Create all combinations of switching the first letter of every word (word word, word Word, Word word, Word Word)";
  std::cout << '\t' << "2  - Same as 1, but with first, the middle one (both middle ones, if even amount of characters in word) and last)";
  std::cout << '\t' << "3a - With odd indexed characters (LiKe ThIs)" << '\n';
  std::cout << '\t' << "3b - With even indexed characters (lIkE tHiS)" << '\n';
  std::cout << '\t' << "4  - Every character (one, onE, oNe, oNE, One, OnE, ONe, ONE)" << '\n';
  std::cout << '\n';
  std::cout << "Example:" << '\n';
  std::cout << '\t' << "./kplg -c 1" << '\n';
  std::cout << '\t' << "./kplg --case 1";
}

void Help::show_file(){
  std::cout << "Usage:" << '\n';
  std::cout << '\t' << "./kplg -f" << '\n';
  std::cout << '\t' << "./kplg --file" << '\n';
  std::cout << '\n';
  std::cout << "Specifies the file, where to load the words to combine from" << '\n';
  std::cout << '\n';
  std::cout << "Example:" << '\n';
  std::cout << '\t' << "./kplg -f words.txt" << '\n';
  std::cout << '\t' << "./kplg --file words";
}
