cmake_minimum_required(VERSION 3.15)
project(Stack_myVersion C)

set(CMAKE_C_STANDARD 11)

add_executable(Stack_myVersion main.c stack.c infixpostfix.c functions.h evaluatepostfix.c)