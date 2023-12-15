#define MAX_LINE 1500;
typedef struct Node{
    char* data;
    struct Node* y;
    struct Node* n;
} Node;

typedef struct Binary_tree{
    Node* root;
} Binary_tree ;

FILE* open_file(){
    FILE* filePtr = fopen("countries2.txt", "r");
    if(!filePtr) {
        perror("Error encountered while opening file!\n");
        exit(-1);
    }
    return filePtr;
}
char* read_file(FILE* filePtr){
    char* line = (char*)malloc(1500 * sizeof (char));
    if(fgets(line, 1500, filePtr) == NULL){
        free(line);
        return NULL;
    }
    if(line[0] == '-' && line[1] == '1')
        return NULL;
    return line;
}
void construct_binary_tree(FILE* filePtr, Node** currentPtr){
    char* line = read_file(filePtr);
    if(!line)
        return;
    *currentPtr = (Node*) malloc(sizeof(Node));

    (*currentPtr)->data = line;
    (*currentPtr)->y = NULL;
    (*currentPtr)->n = NULL;

    construct_binary_tree(filePtr, &(*currentPtr)->y);
    construct_binary_tree(filePtr, &(*currentPtr)->n);
}