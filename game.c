///////////////////////// std header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <gtk/gtk.h>
#include <unistd.h>

/////////////////////////  our header files
#include "binary_tree.h"
#include "play.h"
#include "learn.h"
////////////////////////  main()
static void credits(GtkWidget *widget, gpointer data);
static void start_game(GtkWidget *widget, gpointer data);

GtkWidget *output_label;
GtkWidget *start_button,*credits_button,*yes_button, *no_button;

int is_game_over = 0;

void play(Node* root, Node* original, GtkWidget *output_label);

// Global variables to store the current state of the game
Node *current_root, *original_root;

// Function prototypes for signal handlers
static void on_yes_clicked(GtkWidget *widget, gpointer data);
static void on_no_clicked(GtkWidget *widget, gpointer data);


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

    // Output label with larger font
    output_label = gtk_label_new("");
    intro(output_label);
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
    gtk_box_pack_start(GTK_BOX(vbox), yes_button, TRUE, TRUE, 0);
    gtk_widget_set_no_show_all(yes_button, TRUE);

    no_button = gtk_button_new_with_label("No");
    g_signal_connect(no_button, "clicked", G_CALLBACK(on_no_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), no_button, TRUE, TRUE, 0);
    gtk_widget_set_no_show_all(no_button, TRUE);

    // Credits button
    credits_button = gtk_button_new_with_label("Credits");
    g_signal_connect(credits_button, "clicked", G_CALLBACK(credits), window); // Pass the main window as data
    gtk_box_pack_start(GTK_BOX(vbox), credits_button, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

// Signal handler for the Yes button
static void on_yes_clicked(GtkWidget *widget, gpointer data) {
    if (is_game_over) {
        // Restart the game
        current_root = original_root;
        play(original_root, original_root, output_label);
        is_game_over = 0; // Reset the game over flag
    } else if (current_root != NULL) {
        // Continue the game
        current_root = current_root->y;
        play(current_root, original_root, output_label);
    }
}

static void on_no_clicked(GtkWidget *widget, gpointer data) {
    if (is_game_over) {
        // End the game
        gtk_main_quit();
    } else if (current_root != NULL) {
        // Continue the game
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
                                               "CSE 121 Country Guessing Game Project\n\nUnder the supervision of Dr. Fatma Elzahraa Elshahaby\n\nCreated by: \n@fouadhashesh\n@KareemYasser101\n@Salah-elsayed-2005\n@aabougendia\n@IbEhab25\n");
    gtk_dialog_run(GTK_DIALOG(dialog));
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
    Binary_tree countries;
    countries.root = NULL;
    construct_binary_tree(filePtr, &countries.root);
    original_root = countries.root;
    current_root = countries.root;
    play(current_root, original_root, output_label);
}

