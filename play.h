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
void play(Node* root, Node* original) {

    // Check if there is no tree and terminate if true
    if (root == NULL || original == NULL) {
        fprintf(stderr, "Error: Null pointer provided to play function.\n");
        exit(1);
    }

    char ans;

    // Leaf node - guess the country
    if (root->y == NULL && root->n == NULL) {
        printf("Is your country %s? (y/n): ", root->data);
        ans = getChoice();

        if (ans == 'y') {
            printf("Got it!\n");
        } else if (ans == 'n') {
            printf("Whoops\n");
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
        } else {
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
