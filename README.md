# Moved to https://gitlab.com/dominikhracek/Password_List_Generator
# Password List Generator Repository
Welcome to the `Password_List_Generator` repository! This project aims to provide an easy-to-use tool that generates passwords, that the victim could use, to make it easier to crack a password based on social engineering. The following information will help you understand how to use.
## Table of Contents
1. **Installation**
2. **Usage** - **Command Line Interface (CLI)**
## Installation
To install and run the CLI version locally, follow these steps:
```bash
git clone https://github.com/DominikHracek/Password_List_Generator.git
cd Password_List_Generator
chmod +x ./khakis
```
However if you want to edit the source code and build it use:
`g++ help.cpp kplg.cpp generate.cpp get_info.cpp -o khakis`
## Usage
`./khakis [parameter(s)]`
### Help page
```
Thanks for using Khakis's Password List Generator

Usage ./kplg [OPTIONS] -w
Usage ./kplg --help [OPTION]
DO NOT USE -w/--words AND -f/--file AT THE SAME TIME,
IF YOU DO SO, -f/--file HAS PRIVILEGE AND IF NOT FOUND -w/--words WILL BE IGNORED


Options:
	-h | --help	Shows this page
	-n | --min	Minimal number of characters (default: 1)
	-x | --max	Maximal number of characters (default: 12)
	-c | --case	Case-sensitivity settings
	-r | --char	What characters to use between words
	-v | --verbose	Enables verbose output
	-f | --file	Load words from a file
	-o | --output	Specifies the file to save the generated combinations

```
