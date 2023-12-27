extern void Write_BinTree(FILE *fPtr, Node * iterator);
extern void learn(Node** root, char* new_country, char* new_question);
void intro(){ // welcome message that only initializes at first round
    printf("Hello! Welcome to our game\n");
    printf("Think of a country, and we will guess it! \n");
    printf("---------------------------\n");
}
// Function to read a single character input and consume the newline
char getChoice() {
    char choice = getchar();
    choice = tolower(choice); // Convert to lowercase
    while (getchar() != '\n'); // Clear the input buffer
    return choice;
}


void credits(){
    printf("---------------------------\n");
    printf("This game was developed by:\n\n");
    printf("Abdulrahman Abougendia  22-101194\n");
    printf("SalahEldin El-Sayed     22-101188\n");
    printf("Kareem Yasser           22-101124\n");
    printf("Fouad Hashesh           22-101062\n");
    printf("Ibrahim Ehab            22-101281\n");
    printf("Mohamed Farouk          22-101284\n");
}
void endGame() {    // Function to handle the end of the game
    printf("\nThanks for Playing <3\n");
    credits();
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
            gets(new_country);
            printf("What question should I have asked ? : ");
            char* new_question = (char*)malloc(MAX_LINE_SIZE * sizeof(char*));
            gets(new_question);
            printf("OK!\n");

            learn(&root, new_country, new_question);
            // Learn function to add the new country and its question into the file
            FILE * fptr = fopen("countries.txt","w+");
            Write_BinTree(fptr,countries.root);
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