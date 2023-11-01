#!/bin/bash
lex word_count.lex
gcc lex.yy.c -o word_count -lfl
./word_count < input.txt
