#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <stdio.h>

typedef enum
{
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_LITERAL,
    TOKEN_OPERATOR,
    TOKEN_SYMBOL,
    TOKEN_EOF
} TokenType;

// Define a structure to represent tokens
typedef struct
{
    TokenType type;
    char lexeme[100]; // Adjust the size as needed
} Token;

// Function to recognize and classify tokens
Token recognizeToken(FILE *inputFile, int *lineNo);

#endif
