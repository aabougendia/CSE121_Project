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

// Display a welcome message that only initializes at the first round
int numberOfCountries();
extern int is_game_over;
void intro(GtkWidget *output_label);
void play(Node* root, Node* original, GtkWidget *output_label);

// Main game functions
int numberOfCountries() {
    int i;
    for (i = 0; i < 100; ++i) {
        if (countries[i][0] == '\0')
            break;
    }
    return i;
}

void intro(GtkWidget *output_label) {
    char intro_text[1024] = "Hello, Welcome to our game!\n\n";
    char country_list[1024] = "Our game currently consists of the following countries:\n\n";

    for (int i = 0; i < numberOfCountries(); ++i) {
        strcat(country_list, countries[i]);
        strcat(country_list, "\n");
    }

    strcat(intro_text, country_list);
    strcat(intro_text, "\nPress 'Start Game' to begin.\n");
    gtk_label_set_text(GTK_LABEL(output_label), intro_text);

}

void play(Node* root, Node* original, GtkWidget *output_label) {
    if (root == NULL) {
        fprintf(stderr, "Error: Reached a null node in the tree.\n");
        return;
    }

    if (root == original) {
        intro(output_label);

    }

    if (root->y == NULL && root->n == NULL) {  // Leaf node
        is_game_over = 1;
        char end_game_msg[256];
        sprintf(end_game_msg, "The game is over!\nYour country was: %s\n\nDo you want to play again?", root->data);
        gtk_label_set_text(GTK_LABEL(output_label), end_game_msg);
        //end_game_choice(end_game_msg, original);
        return;
    } else {  // Non-leaf node
        char question[256];
        sprintf(question, "%s", root->data);
        gtk_label_set_text(GTK_LABEL(output_label), question);
    }
}


