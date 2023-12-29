// used extern to get the 2 functions from learn.h
extern void Write_BinTree(FILE *fPtr, Node * iterator);
extern void learn(Node** root, char* new_country, char* new_question);
void intro(){ // welcome message that only initializes at first round
    printf("Hello! Welcome to our game\n");
    printf("Think of a country, and we will guess it! \n");
    printf("---------------------------\n");
}
// Function to read a single character input and consume the newline
char getChoice() {
    char choice = getchar(); // get user answer
    choice = tolower(choice); // Convert to lowercase
    while (getchar() != '\n'); // Clear the input buffer
    return choice;
}
void endGame() {    // Function to handle the end of the game
    printf("\nThanks for Playing <3\n");
    printf("---------------------------\n");
    printf("This game was developed by:\n\n");
    printf("Abdulrahman Abougendia  22-101194\n");
    printf("Salah El-Sayed          22-101188\n");
    printf("Kareem Yasser           22-101124\n");
    printf("Fouad Hashesh           22-101062\n");
    printf("Ibrahim Ehab            22-101281\n");
    printf("Mohamed Farouk          22-101284\n");
 }

// Play function - recursive approach to traverse the tree based on user input
void play(Node* iterator, Node* original, Binary_tree countries) {
     // Check if there is no tree and terminate if true
    if (iterator == NULL || original == NULL) {
        fprintf(stderr, "Error: Null pointer provided to play function.\n");
        exit(1);
    }
    if(iterator == original){ // welcome function
        intro();
    }
     char ans; // A variable to get any user input
    label:
    // Leaf node - guess the country
    if (iterator->y == NULL && iterator->n == NULL) {
        printf("Is your country %s? (y/n): ", iterator->data);
        ans = getChoice();


        if (ans == 'y') {
            printf("Got it!\n"); // Correct answer
        } else if (ans == 'n') { // wrong asnwer
            printf("What was the country you were thinking of ? : ");
            char* new_country = (char*)malloc(MAX_LINE_SIZE * sizeof(char));
            gets(new_country); // get new_country from the user
            printf("What question should I have asked ? : ");
            char* new_question = (char*)malloc(MAX_LINE_SIZE * sizeof(char));
            gets(new_question);// get new_question from the user
            printf("OK!\n");

            learn(&iterator, new_country, new_question);
            // Learn function to add the new country and its question into the file
            FILE * fptr = fopen("countries.txt","w+");
            //Writing function to overwrite the file with the new changes
            Write_BinTree(fptr,countries.root); 
            // Close file
            fclose(fptr);
        }
        else {
            printf("Invalid input, Please try again!\n");
             goto label; // try again from current node
        }

        // Ask to play again
        printf("Would you like to try again? (y/n): ");
        ans = getChoice();

          if (ans == 'y') {
            play(original, original, countries); // replay the game
        }else if (ans == 'n') {
                endGame(); // end of game function
          }
          else{
              printf("Invalid input, Please try again!\n");
              goto label; // try again from current node
        }
    }

    else {
        // Non-leaf node - ask question
        printf("%s (y/n): ", iterator->data);
        ans = getChoice();

        if (ans == 'y') {
            play(iterator->y, original, countries);
        } else if (ans == 'n') {
            play(iterator->n, original, countries);
        } else {
            printf("Invalid input, Please try again!\n");
            goto label; // try again from current node
        }
    }
}
