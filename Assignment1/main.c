#include "tokenize.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <input_filename>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL)
    {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    Token token;
    int lineNo = 1;
    int tokenNo = 0;

    fprintf(outputFile, "//output.txt\n");
    fprintf(outputFile, "Line no.\tToken no.\tToken\t\tLexeme\n");

    do
    {
        token = recognizeToken(inputFile, &lineNo);

        // Print token information to the output file
        if (token.type != TOKEN_EOF)
        {
            fprintf(outputFile, "%d\t\t%d\t\t", lineNo, tokenNo);
            switch (token.type)
            {
            case TOKEN_KEYWORD:
                fprintf(outputFile, "Keyword\t\t");
                break;
            case TOKEN_IDENTIFIER:
                fprintf(outputFile, "Identifier\t");
                break;
            case TOKEN_LITERAL:
                fprintf(outputFile, "Literal\t\t");
                break;
            case TOKEN_OPERATOR:
                fprintf(outputFile, "Operator\t");
                break;
            case TOKEN_SYMBOL:
                fprintf(outputFile, "Symbol\t\t");
                break;
            default:
                break;
            }
            fprintf(outputFile, "%s\n", token.lexeme);
            tokenNo++;
        }
    } while (token.type != TOKEN_EOF);

    fclose(inputFile);
    fclose(outputFile);
    printf("Tokenization complete. Results saved in output.txt.\n");
    return 0;
}
