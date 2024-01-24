#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isDelimiter(char ch) {
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ';' || ch == '=' || ch == '<' || ch == '>' ||
        ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
        ch == '[' || ch == ']') {
        return true;
    }
    return false;
}

bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' ||
        ch == '<' || ch == '>' || ch == '=') {
        return true;
    }
    return false;
}

bool isValidIdentifier(char* str) {
    if (str[0] >= '0' && str[0] <= '9') {
        char* endptr;
        strtol(str, &endptr, 10);
        if (*endptr == '\0') {
            return true; 
        } else {
            return false; 
        }
    }

    for (int i = 0; i < strlen(str); i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) {
            return false; 
        }
    }

    return true;
}


int main() {
    char str[100]; 
    printf("Type the line of code: \n");
    fgets(str, sizeof(str), stdin);

    char* token = strtok(str, " ");

    while (token != NULL) {
        if (token[strlen(token) - 1] == '\n') {
            token[strlen(token) - 1] = '\0';
        }

        int len = strlen(token);
        for (int i = 0; i < len; i++) {
            if (isOperator(token[i]) || isDelimiter(token[i])) {
                printf("Operator/Delimiter: %c\n", token[i]);
            }
        }

        if (isValidIdentifier(token)) {
            printf("Valid identifier: %s\n", token);
        } else {
            printf("Invalid identifier/Operator/Delimiter: %s\n", token);
        }

        token = strtok(NULL, " "); // Move to the next token
    }

    return 0;
}
