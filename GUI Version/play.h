// used extern to ger the 2 functions from learn.h
extern void Write_BinTree(FILE *fPtr, Node * iterator);
extern void learn(Node** root, char* new_country, char* new_question);
extern int is_game_over;


extern Node *current_root, *original_root;


void endGame() {    // Function to handle the end of the game
    printf("\nThanks for Playing <3\n");
    printf("---------------------------\n");
    printf("This game was developed by:\n\n");
    printf("Abdulrahman Abougendia  22-101194\n");
    printf("SalahEldin El-Sayed     22-101188\n");
    printf("Kareem Yasser           22-101124\n");
    printf("Fouad Hashesh           22-101062\n");
    printf("Ibrahim Ehab            22-101281\n");
    printf("Mohamed Farouk          22-101284\n");
}

// Play function - recursive approach to traverse the tree based on user input

void play(Node* iterator, Node* original, GtkWidget *output_label) {
    if (iterator == NULL || original == NULL) {
        fprintf(stderr, "Error: Null pointer provided to play function.\n");
        exit(1);
    }

    // Additional checks for corrupted or uninitialized nodes
    if (iterator->y == NULL && iterator->n == NULL) {  // Leaf node - guess the country
        is_game_over = 1;
        char end_game_msg[256];
        snprintf(end_game_msg, sizeof(end_game_msg), "Is your country %s?", iterator->data);
        gtk_label_set_text(GTK_LABEL(output_label), end_game_msg);
    } else if (iterator->y != NULL && iterator->n != NULL) {  // Non-leaf node - ask question
        char question[256];
        snprintf(question, sizeof(question), "%s", iterator->data);
        gtk_label_set_text(GTK_LABEL(output_label), question);
    } else {
        fprintf(stderr, "Error: Corrupted node in the binary tree.\n");
        exit(1);
    }
}
