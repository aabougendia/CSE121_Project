extern void Write_BinTree(FILE *fPtr, Node * iterator);
extern void learn(Node** root, char * new_country, char* new_question);
void intro(){ // welcome message that only initializes at first round
    printf("Hello! Welcome to our game: \n");
    printf("---------------------------\n");
}
// Function to read a single character input and consume the newline
char getChoice() {
    char choice = getchar();
    choice = tolower(choice); // Convert to lowercase
    while (getchar() != '\n'); // Clear the input buffer
    return choice;
}

// Function to handle the end of the game
void endGame() {
    printf("Thanks for Playing <3\n");
    // exit(0);
}

// Play function - recursive approach to traverse the tree based on user input
void play(Node* root, Node* original, Binary_tree countries) {
     // Check if there is no tree and terminate if true
    if (root == NULL || original == NULL) {
        fprintf(stderr, "Error: Null pointer provided to play function.\n");
        exit(1);
    }
    if(root == original){ // welcome function
        intro();
    }

    char ans;

    // Leaf node - guess the country
    if (root->y == NULL && root->n == NULL) {
        printf("Is your country %s? (y/n): ", root->data);
        ans = getChoice();

        if (ans == 'y') {
            printf("Got it!\n");
        } else if (ans == 'n') {
            printf("What was the country you were thinking of ? : ");
            char* new_country = (char*)malloc(MAX_LINE_SIZE * sizeof(char*));
            gets(new_country); // get new_country from the user
            printf("What question should I have asked ? : ");
            char* new_question = (char*)malloc(MAX_LINE_SIZE * sizeof(char*));
            gets(new_question);// get new_question from the user
            printf("OK!\n");

            learn(&root, new_country, new_question);
            // Learn function to add the new country and its question into the file
            FILE * fptr = fopen("countries.txt","w+");
            //Writing function to overwrite the file with the new changes
            Write_BinTree(fptr,countries.root); 
            // Close file
            fclose(fptr);
        }
        else {
            printf("Invalid input\n");
            return;
        }

        // Ask to play again
        printf("Would you like to try again? (y/n): ");
        ans = getChoice();

          if (ans == 'y') {
            play(original, original, countries);
        }else if (ans == 'n') {
                endGame();
          }
          else{
             printf("Invalid input\n");
        }
    }

    else {
        // Non-leaf node - ask question
        printf("%s (y/n): ", root->data);
        ans = getChoice();

        if (ans == 'y') {
            play(root->y, original, countries);
        } else if (ans == 'n') {
            play(root->n, original, countries);
        } else {
            printf("Invalid input\n");
        }
    }
}
