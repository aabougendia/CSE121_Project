#define MAX_LINE_SIZE 999
typedef struct Node{
    char* data;
    struct Node* y;
    struct Node* n;
} Node;

typedef struct Binary_tree{
    Node* root;
} Binary_tree ;

FILE* open_file(){
    char* file_name = "countries.txt";
    FILE* filePtr = fopen(file_name, "r");
    if(!filePtr) {
        perror("Error encountered while opening file!\n");
        exit(-1);
    }
    return filePtr;
}

char* read_line(FILE* filePtr){
    char* line = (char*)malloc(MAX_LINE_SIZE * sizeof (char));
    if(fgets(line, MAX_LINE_SIZE, filePtr) == NULL){
        free(line);
        return NULL;
    }
    if(!strcmp(line, "-1\n"))
        return NULL;
    return line;
}

void construct_binary_tree(FILE* filePtr, Node** currentPtr){
    char* line = read_line(filePtr);
    if(line == NULL)
        return;

    *currentPtr = (Node*) malloc(sizeof(Node));

    (*currentPtr)->data = line;
    (*currentPtr)->y = NULL;
    (*currentPtr)->n = NULL;

    construct_binary_tree(filePtr, &((*currentPtr)->y));
    construct_binary_tree(filePtr, &((*currentPtr)->n));
}

 