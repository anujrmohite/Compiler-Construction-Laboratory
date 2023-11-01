#include "tokenize.h"
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

Token recognizeToken(FILE *inputFile, int *lineNo)
{
    Token token;
    char c;
    int i = 0;

    // Initialize the token
    token.type = TOKEN_IDENTIFIER;
    memset(token.lexeme, 0, sizeof(token.lexeme));

    // Read characters from inputFile and process them
    while ((c = fgetc(inputFile)) != EOF)
    {
        if (c == '\n')
        {
            // Newline encountered, increment line number
            (*lineNo)++;
        }
        if (isspace(c))
        {
            // Ignore whitespace
            continue;
        }
        else if (isalpha(c) || c == '_')
        {
            // Handle identifiers and keywords
            token.lexeme[i++] = c;
            while ((c = fgetc(inputFile)) != EOF && (isalnum(c) || c == '_'))
            {
                token.lexeme[i++] = c;
            }
            ungetc(c, inputFile);
            token.lexeme[i] = '\0';

            // Check if it's a keyword
            if (strcmp(token.lexeme, "#include") == 0)
            {
                token.type = TOKEN_KEYWORD;
            }
            else if (strcmp(token.lexeme, "void") == 0 || strcmp(token.lexeme, "int") == 0)
            {
                token.type = TOKEN_KEYWORD;
            }
            else if (strcmp(token.lexeme, "main") == 0)
            {
                token.type = TOKEN_KEYWORD;
            }
            else
            {
                token.type = TOKEN_IDENTIFIER;
            }
            return token;
        }
        else if (c == '"')
        {
            // Handle string literals
            token.type = TOKEN_LITERAL;
            token.lexeme[i++] = c;
            while ((c = fgetc(inputFile)) != EOF && c != '"')
            {
                token.lexeme[i++] = c;
            }
            token.lexeme[i++] = '"';
            token.lexeme[i] = '\0';
            return token;
        }
        else if (strchr("+-*/%<>=!&|(){};", c))
        {
            // Handle symbols
            token.type = TOKEN_SYMBOL;
            token.lexeme[i++] = c;
            token.lexeme[i] = '\0';
            return token;
        }
        else if (c == '/' && (c = fgetc(inputFile)) == '/')
        {
            // Handle single-line comments, ignore the rest of the line
            while ((c = fgetc(inputFile)) != '\n' && c != EOF)
            {
                // Ignore characters until a newline or EOF is encountered
            }
        }
        else
        {
            // Handle operators
            token.type = TOKEN_OPERATOR;
            token.lexeme[i++] = c;
            while (strchr("+-*/%<>=!&|", (c = fgetc(inputFile))) && i < sizeof(token.lexeme) - 1)
            {
                token.lexeme[i++] = c;
            }
            ungetc(c, inputFile);
            token.lexeme[i] = '\0';
            return token;
        }
    }

    // Return a special token when EOF is reached
    token.type = TOKEN_EOF;
    return token;
}
