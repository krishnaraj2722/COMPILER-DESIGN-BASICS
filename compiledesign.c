#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// List of keywords
char keywords[32][10] = {
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","int","long",
    "register","return","short","signed","sizeof","static","struct","switch",
    "typedef","union","unsigned","void","volatile","while"
};

// Check if the word is a keyword
int isKeyword(char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>');
}

// Main lexical analyzer function
int main() {
    FILE *fp;
    char ch, word[20];
    int i;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        // Skip whitespace
        if (isspace(ch))
            continue;

        // Operator check
        if (isOperator(ch)) {
            printf("Operator: %c\n", ch);
        }

        // Identifier/Keyword check
        else if (isalpha(ch)) {
            i = 0;
            while (isalnum(ch)) {
                word[i++] = ch;
                ch = fgetc(fp);
            }
            word[i] = '\0';
            fseek(fp, -1, SEEK_CUR); // Step back one char

            if (isKeyword(word))
                printf("Keyword: %s\n", word);
            else
                printf("Identifier: %s\n", word);
        }

        // Number check (optional extension)
        else if (isdigit(ch)) {
            i = 0;
            while (isdigit(ch)) {
                word[i++] = ch;
                ch = fgetc(fp);
            }
            word[i] = '\0';
            fseek(fp, -1, SEEK_CUR);
            printf("Number: %s\n", word);
        }
    }

    fclose(fp);
    return 0;
}
