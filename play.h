char countries[100][50] = {
        "Nigeria",
        "Namibia",
        "Argentina",
        "Brazil",
        "Maldives",
        "New Zealand",
        "Saudi Arabia",
        "Democratic Republic of Congo",
        "Norway",
        "Sweden",
        "Hungary",
        "England",
        "Palestine",
        "Egypt",
        "United States of America",
        "Japan"
};

int number_of_countries(){ // function that returns the current number of countries
    int i;
    for  ( i = 0; i < 100; ++i) {
        if(countries[i][0]=='\0') // marks the end of list
            break;
    }
    return i;
}
void intro(){ // welcome message that only initializes at first round
    printf("Hello! Welcome to our game: \n");
    printf("---------------------------\n");
    printf("Our game consists currently of %d countries which are : \n",number_of_countries());
    for (int i = 0; i < number_of_countries(); ++i) {
        printf("%s\n",countries[i]);
    }
    printf("\n\n\"So let's start playing !!\" \n\n");
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
    exit(0);
}

// Play function - recursive approach to traverse the tree based on user input
void play(Node* root, Node* original,Binary_tree countries) {
     // Check if there is no tree and terminate if true
    if (root == NULL || original == NULL) {
        fprintf(stderr, "Error: Null pointer provided to play function.\n");
        exit(1);
    }
    if(root==original){ // welcome function
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
            char* newcountry = (char*)malloc(100*sizeof(char*));
            gets(newcountry);
            printf("What question should I have asked ? : ");
            char* newquestion = (char*)malloc(100*sizeof(char*));
            gets(newquestion);
            printf("OK!\n");

            learn(countries,root->data,newcountry,newquestion);// Learn function to add the new country and its question into the file
        } else {
            printf("Invalid input\n");
            return;
        }

        // Ask to play again
        printf("Would you like to try again? (y/n): ");
        ans = getChoice();

          if (ans == 'y') {
            play(original, original);
        } else if (ans == 'n') {
                endGame();
            }
          else {
             printf("Invalid input\n");
        }
    }

    else {
        // Non-leaf node - ask question
        printf("%s (y/n): ", root->data);
        ans = getChoice();

        if (ans == 'y') {
            play(root->y, original);
        } else if (ans == 'n') {
            play(root->n, original);
        } else {
            printf("Invalid input\n");
        }
    }
}