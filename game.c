///////////////////////// std header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/////////////////////////  our header files

#include "binary_tree.h"
#include "play.h"
#include "learn.h"
////////////////////////  main()
int main() {
    FILE* filePtr = open_file();    // file pointer to text file
    Binary_tree countries;      // binary tree structure object for countries
    countries.root = NULL;
    construct_binary_tree(filePtr, &countries.root);    // constructing the structure with countries and their questions
    fclose(filePtr);    // close file after taking serilized data from it
    play(countries.root,countries.root, countries);     // playing the game using the binary tree sturcture
    free_binary_tree(countries.root);   // deallocating binary tree memory after finishing the game
    return 0;

}