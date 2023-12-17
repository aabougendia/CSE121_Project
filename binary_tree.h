#define MAX_LINE_SIZE 999

typedef struct Node{    // Node structure definition
    char* data;         // Node text data
    struct Node* y;     // yes link
    struct Node* n;     // no link
} Node;

typedef struct Binary_tree{     // Binary tree structure definition
    Node* root;
} Binary_tree ;

FILE* open_file(){      // function to open the text file
    char* file_name = "countries.txt";
    FILE* filePtr = fopen(file_name, "r");
    if(filePtr == NULL) {
        perror("Error encountered while opening file!\n");
        exit(-1);
    }
    return filePtr;
}

char* read_line(FILE* filePtr){     // function to read the text file line by line
    char* line = (char*)malloc(MAX_LINE_SIZE * sizeof (char));
    if(fgets(line, MAX_LINE_SIZE, filePtr) == NULL){    //  checking if errors occur while reading text lines
        free(line);
        return NULL;
    }
    if(!strcmp(line, "-1\n"))   // checking if the line contains -1 which indicates reaching a leaf node
        return NULL;
    line[strlen(line)-1] = '\0';
    return line;
}

void construct_binary_tree(FILE* filePtr, Node** iteratorPtr){  // a recursive function to construct the binary tree structure
    char* line = read_line(filePtr);
    if(line == NULL)    // recursion base case when we reach a leaf node
        return;

    *iteratorPtr = (Node*) malloc(sizeof(Node));    // allocating memory blocks for binary tree nodes

    (*iteratorPtr)->data = line;
    (*iteratorPtr)->y = NULL;
    (*iteratorPtr)->n = NULL;

    // performing pre-order traversal over the binary tree using recursion function calling
    construct_binary_tree(filePtr, &((*iteratorPtr)->y));
    construct_binary_tree(filePtr, &((*iteratorPtr)->n));
}


 
