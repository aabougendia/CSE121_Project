#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <gtk/gtk.h>

// Assuming these header files contain the necessary declarations
#include "binary_tree.h"
#include "play.h"
#include "learn.h"

// Function Declarations
static void credits(GtkWidget *widget, gpointer data);
static void learnFunction(GtkWidget *widget, gpointer data, Node* iterator);
static void play_again(GtkWidget *widget, gpointer data);
static void start_game(GtkWidget *widget, gpointer data);
static void on_yes_clicked(GtkWidget *widget, gpointer data);
static void on_no_clicked(GtkWidget *widget, gpointer data);

// Global variables
GtkWidget *output_label;
GtkWidget *start_button, *credits_button, *yes_button, *no_button;
Binary_tree countries;
Node *current_root, *original_root;
int is_game_over = 0;

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Country Guessing Game");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Vertical box for layout
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Output label
    output_label = gtk_label_new("Hello! Welcome to our game\nThink of a country, and we will guess it!");
    PangoFontDescription *font_desc = pango_font_description_from_string("Sans Bold 14");
    gtk_widget_modify_font(output_label, font_desc);
    gtk_box_pack_start(GTK_BOX(vbox), output_label, TRUE, TRUE, 0);

    // Start Game button
    start_button = gtk_button_new_with_label("Start Game");
    g_signal_connect(start_button, "clicked", G_CALLBACK(start_game), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), start_button, TRUE, TRUE, 0);

    // Yes and No buttons (initially hidden)
    yes_button = gtk_button_new_with_label("Yes");
    g_signal_connect(yes_button, "clicked", G_CALLBACK(on_yes_clicked), NULL);
    gtk_widget_set_no_show_all(yes_button, TRUE);
    gtk_box_pack_start(GTK_BOX(vbox), yes_button, TRUE, TRUE, 0);

    no_button = gtk_button_new_with_label("No");
    g_signal_connect(no_button, "clicked", G_CALLBACK(on_no_clicked), NULL);
    gtk_widget_set_no_show_all(no_button, TRUE);
    gtk_box_pack_start(GTK_BOX(vbox), no_button, TRUE, TRUE, 0);

    // Credits button
    credits_button = gtk_button_new_with_label("Credits");
    g_signal_connect(credits_button, "clicked", G_CALLBACK(credits), window);
    gtk_box_pack_start(GTK_BOX(vbox), credits_button, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

// Signal handler for the Yes button
static void on_yes_clicked(GtkWidget *widget, gpointer data) {
    if (is_game_over) {
        play_again(NULL, NULL);
    }else if (current_root != NULL) {
        current_root = current_root->y;
        play(current_root, original_root, output_label);
    }
}

static void on_no_clicked(GtkWidget *widget, gpointer data) {
    if (is_game_over) {
        learnFunction(widget, data, current_root);
    }else if (current_root != NULL) {
        current_root = current_root->n;
        play(current_root, original_root, output_label);
    }
}

// Callback function for the guess button
static void credits(GtkWidget *widget, gpointer data) {
    GtkWidget *parent_window = GTK_WIDGET(data);

    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(parent_window),
                                               GTK_DIALOG_DESTROY_WITH_PARENT,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               "CSE 121 Country Guessing Game Project\n\nUnder the supervision of Dr. Fatma Elzahraa Elshahaby\n\nThis game was developed by:\n\n"
                                               "22-101194\t Abdulrahman Abougendia\n"
                                               "22-101188\t SalahEldin El-Sayed\n"
                                               "22-101124\t Kareem Yasser\n"
                                               "22-101062\t Fouad Hashesh\n"
                                               "22-101281\t Ibrahim Ehab\n"
                                               "22-101284\t Mohamed Farouk\n");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

static void learnFunction(GtkWidget *widget, gpointer data, Node* iterator) {
    GtkWidget *parent_window = GTK_WIDGET(data);

    // Create a new dialog
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Enter New Country",
                                                    GTK_WINDOW(parent_window),
                                                    GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                                    ("OK"),
                                                    GTK_RESPONSE_ACCEPT,
                                                    ("Cancel"),
                                                    GTK_RESPONSE_REJECT,
                                                    NULL);

    // Create two text entry widgets
    GtkWidget *entry1 = gtk_entry_new();
    GtkWidget *entry2 = gtk_entry_new();

    // Optional: Set maximum length for entries
    gtk_entry_set_max_length(GTK_ENTRY(entry1), 50);
    gtk_entry_set_max_length(GTK_ENTRY(entry2), 100);

    // Add a label and entry to the dialog's content area
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *label0 = gtk_label_new("What was the country you were thinking of ?\n");
    GtkWidget *label1 = gtk_label_new("Country Name:");
    GtkWidget *label2 = gtk_label_new("Question:");

    gtk_container_add(GTK_CONTAINER(content_area), label0);
    gtk_container_add(GTK_CONTAINER(content_area), label1);
    gtk_container_add(GTK_CONTAINER(content_area), entry1);
    gtk_container_add(GTK_CONTAINER(content_area), label2);
    gtk_container_add(GTK_CONTAINER(content_area), entry2);

    // Show all widgets in the dialog
    gtk_widget_show_all(dialog);

    // Run the dialog and wait for the user response
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));

    if (response == GTK_RESPONSE_ACCEPT) {
        // Retrieve text from entries and handle it
        char *new_country = gtk_entry_get_text(GTK_ENTRY(entry1));
        char *new_question = gtk_entry_get_text(GTK_ENTRY(entry2));
        // learn(original_root, new_country, new_question);

        learn(&iterator, new_country, new_question);
        // Learn function to add the new country and its question into the file
        FILE * fptr = fopen("countries.txt","w+");
        //Writing function to overwrite the file with the new changes
        Write_BinTree(fptr,countries.root);
        // Close file
        fclose(fptr);
        play_again(NULL,NULL);

    }else{
        play_again(NULL,NULL);
    }

    // Destroy the dialog after finishing
    gtk_widget_destroy(dialog);
}

static void play_again(GtkWidget *widget, gpointer data) {
    GtkWidget *parent_window = GTK_WIDGET(data);

    // Create a new dialog
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Play Again",
                                                    GTK_WINDOW(parent_window),
                                                    GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                                    ("OK"),
                                                    GTK_RESPONSE_ACCEPT,
                                                    ("No"),
                                                    GTK_RESPONSE_REJECT,
                                                    NULL);



    // Add a label and entry to the dialog's content area
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *label = gtk_label_new("Game has ended, Do you want to play again ?\n");

    gtk_container_add(GTK_CONTAINER(content_area), label);

    // Show all widgets in the dialog
    gtk_widget_show_all(dialog);

    // Run the dialog and wait for the user response
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));

    if (response == GTK_RESPONSE_ACCEPT) {
        is_game_over = 0;
        start_game(NULL,NULL);
    } else{
        free_binary_tree(countries.root);
        gtk_main_quit();
    }

    // Destroy the dialog after finishing
    gtk_widget_destroy(dialog);
}



// Callback function to start the game
static void start_game(GtkWidget *widget, gpointer data) {
    // Show Yes and No buttons when the game starts
    gtk_widget_show(yes_button);
    gtk_widget_show(no_button);
    gtk_widget_hide(start_button);
    gtk_widget_hide(credits_button);


    // Initialize and start the game
    FILE *filePtr = open_file();
    countries.root = NULL;
    construct_binary_tree(filePtr, &countries.root);
    fclose(filePtr);
    original_root = countries.root;
    current_root = countries.root;

    play(current_root, original_root, output_label);

}