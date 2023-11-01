---
title: CC Assignment 1
author: Anuj Mohite 142103002
date: September 15, 2023
---

## To Run Following Code

gcc -c tokenize.c -o tokenize.o
gcc main.c tokenize.o -o tokenizer
./tokenizer input.c

# Hand-Coded Lexical Analyzer for a Subset of C Language

## Problem Description
Write a program in C-language that takes a C-program as input and gives output that recognizes the text in the given input program.

### Input:

```c
#include<stdio.h>
void main()
{
    printf("Hello World");
}

//output.txt
Line no. Token no. Token                   Lexeme
1                0           Identifier               #include
1                1           Identifier               stdio
1                2           Identifier               h
2                3           Identifier                void
2                4            Keyword              main
2                5          opening bracket       (
2                5          closing bracket         )
3                6          opening braces       {
4                7           Identifier                printf
4                 8          opening bracket      (
4                 9           literal                      "Hello World"
4                10         closing bracket         )
4                11          Semicolon               ;
5                12        closing braces            }

