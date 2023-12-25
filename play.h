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

// Function that returns the current number of countries
int numberOfCountries(){ 
    int i;
    for( i = 0; i < 100; ++i){
        if(countries[i][0]=='\0') // Marks the end of the list
            break;
    }
    return i;
}

// Display a welcome message that only initializes at the first round
void intro(GtkWidget *output_label) {
    char intro_text[1024] = "Hello, Welcome to our game!\n---------------------------\n";
    char country_list[1024] = "Our game currently consists of the following countries:\n";

    for (int i = 0; i < numberOfCountries(); ++i) {
        strcat(country_list, countries[i]);
        strcat(country_list, "\n");
    }

    strcat(intro_text, country_list);
    strcat(intro_text, "\nSo let's start playing !!\n");

    gtk_label_set_text(GTK_LABEL(output_label), intro_text);
}

// Function to read a single character input and clear the newline
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
// Play function - modified for GTK interface
void play(Node* root, Node* original, GtkWidget *output_label) {
    // Check if there is no tree and terminate if true
    if (root == NULL || original == NULL) {
        fprintf(stderr, "Error: Null pointer provided to play function.\n");
        exit(1);
    }

    // Display intro if at the beginning of the game
    if (root == original) {
        intro(output_label);
    }

    // Leaf node - guess the country
    if (root->y == NULL && root->n == NULL) {
        char question[256];
        sprintf(question, "Is your country %s?", root->data);
        gtk_label_set_text(GTK_LABEL(output_label), question);
        // The response will be handled by the "Yes" or "No" button signals in game.c
    }
    else {
        // Non-leaf node - ask question
        char question[256];
        sprintf(question, "%s", root->data);
        gtk_label_set_text(GTK_LABEL(output_label), question);
        // The response will be handled by the "Yes" or "No" button signals in game.c
    }
}
