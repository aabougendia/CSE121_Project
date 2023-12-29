#define MAX_LINE_SIZE 999

typedef struct Node{    // Node structure definition
    char* data;         // Node text data
    struct Node* y;     // yes link
    struct Node* n;     // no link
} Node;

typedef struct Binary_tree{     // Binary tree structure definition
    Node* root;     // root Node
} Binary_tree ;

FILE* open_file(){      // function to open the text file, returns the file pointer
    char* file_name = "countries.txt";
    FILE* filePtr = fopen(file_name, "r+");
    if(filePtr == NULL) {       // checking if the file opens successfully
        perror("Error encountered while opening file!\n");
        exit(-1);
    }
    return filePtr; // returning text file pointer
}

char* read_line(FILE* filePtr){     // function to read the text file line by line
    // takes the file pointer as parameter and returns the line string each time the function is called
    char* line = (char*)malloc(MAX_LINE_SIZE * sizeof (char));
    if(fgets(line, MAX_LINE_SIZE, filePtr) == NULL){    //  checking if errors occur while reading text lines
        free(line);     // deallocating line pointer if errors occur
        return NULL;    // returning NULL pointer to indicate that error occurred
    }
    if(!strcmp(line, "-1\n"))   // checking if the line contains -1 which indicates reaching a leaf node
        return NULL;
    line[strlen(line)-1] = '\0';
    return line;
}

void construct_binary_tree(FILE* filePtr, Node** iteratorPtr){  // a recursive function to construct the binary tree structure
    // takes the file pointer as a parameter and passes and iterator pointer by reference to traverse over the binary tree

    char* line = read_line(filePtr);    // reading countries text file line by line
    if(line == NULL)    // recursion base case when we reach a leaf node
        return;

    *iteratorPtr = (Node*) malloc(sizeof(Node));    // allocating memory blocks for binary tree nodes

    (*iteratorPtr)->data = line;    // storing text data
    // initializing y and n linking pointers to NULL
    (*iteratorPtr)->y = NULL;
    (*iteratorPtr)->n = NULL;

    // performing pre-order traversal over the binary tree using recursion function calling
    construct_binary_tree(filePtr, &((*iteratorPtr)->y));
    construct_binary_tree(filePtr, &((*iteratorPtr)->n));
}
void free_binary_tree(Node* iterator){  // function to deallocate memory reserved for binary tree, traverses over the binary tree using the iterator pointer
    if(iterator == NULL)
        return;

    free_binary_tree(iterator->y);
    free_binary_tree(iterator->n);

    free(iterator);
}