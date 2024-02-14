#include <cstdlib>
#include <cstring>
#include <iostream>

#include "help.h"
#include "get_info.h"

int main(const int argc, char *argv[]) {
  if (argc == 1) {
    Get_Info get_info;
    get_info.ask_for_patterns();
    get_info.start_ui();
  }
  if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
    Help help_page;
    if (argc == 2){
      help_page.show_general_help();
      
    } else if (argc == 3){
      if (strcmp(argv[2], "-n") == 0 || strcmp(argv[2], "--min") == 0) {
        help_page.show_minimal_character_length();
        
      } else if (strcmp(argv[2], "-x") == 0 || strcmp(argv[2], "--max") == 0){
        help_page.show_maximal_character_length();
        
      } else if (strcmp(argv[2], "-r") == 0 || strcmp(argv[2], "--char") == 0){
        help_page.show_characters();
        
      } else if (strcmp(argv[2], "-c") == 0 || strcmp(argv[2], "--case") == 0){
        help_page.show_case();
        
      } else if (strcmp(argv[2], "-f") == 0 || strcmp(argv[2], "--file") == 0){
        help_page.show_input_file();

      } else if (strcmp(argv[2], "-o") == 0 || strcmp(argv[2], "--output") == 0){
        help_page.show_output_file();

      } else {
        std::cout << "Error: Unknown argument " << argv[2] << '\n';
        exit(2);
      }
    }
  } else if (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--interactive") == 0) {
    Get_Info get_info;
    get_info.get_arguments(argc, argv);
    std::cout << "This will start interactive mode in the future, WIP" << '\n';
    //get_info.start_friendly_ui();
  } else {
    Get_Info get_info;
    get_info.get_arguments(argc, argv);
    get_info.ask_for_patterns();
    get_info.start_ui();
  }
  
  return 0;
}