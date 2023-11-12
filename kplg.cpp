#include <cstdlib>
#include <cstring>
#include <iostream>

#include "help.h"
#include "generate.h"

Generate generate;

int main(int argc, char *argv[]) {
  if (argc == 1) {
    generate.start_ui();
    // TO-DO generate.start_friendly_ui(); <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
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
        help_page.show_file();
        
      } else {
        std::cout << "Error: Unknown argument " << argv[2] << '\n';
        exit(2);
      }
    }
  } else {
    generate.get_arguments(argc, argv);
    generate.start_ui();
    //generate.generate_combinations();
  }
  
  return 0;
}