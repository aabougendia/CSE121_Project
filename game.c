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
    FILE* filePtr = open_file();
    Binary_tree countries;
    countries.root = NULL;
    construct_binary_tree(filePtr, &countries.root);
    play(countries.root,countries.root,countries);
    return 0;

}