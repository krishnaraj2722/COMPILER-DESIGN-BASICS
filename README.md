# COMPILER-DESIGN-BASICS
COMPANY: CODE TECH IT SOLUTIONS
NAME: KRISHNA RAJ 
INTERN ID: CT04DF1265
DOMAIN: C LANGUAGE
DURATION: 4 WEEKS 
MENTOR: NEELA SANTOSH

#📜 Description:
This C program is a simple lexical analyzer designed as part of the Compiler Design basics. It takes an input source code (from a file), scans it line by line, and classifies each token into one of the following categories:

Keyword (e.g., int, return, if)

Identifier (e.g., variable names like a, sum)

Operator (e.g., +, =, >)

Number (e.g., 10, 5)
🧠 How It Works:
Input Reading:

The program opens an external file named input.txt.

This file contains sample C code which will be analyzed.

Tokenization:

The program reads each word and character using fscanf and fgetc.

It checks if each word matches with the predefined list of C language keywords.

Functions Used:isKeyword(char *word):

Compares the word with a predefined list of 32 C keywords.

Returns 1 if it is a keyword, 0 otherwise.

isOperator(char ch):

Checks if the character is a common operator (+, -, *, /, =, <, >).

Returns 1 if it's an operator, 0 otherwise.
Classification & Output:

Keywords are printed as Keyword: <word>

Numbers are printed as Number: <value>

Operators are printed as Operator: <symbol>

Remaining valid tokens are printed as Identifier: <name>

#OUTPUT 
![Image](https://github.com/user-attachments/assets/23f24472-1d91-41f8-b5b1-3f29ba19bea5)
