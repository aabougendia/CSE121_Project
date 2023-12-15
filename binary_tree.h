typedef struct Node{
    char* data;
    struct Node* y;
    struct Node* n;
} Node;

typedef struct Binary_tree{
    Node* root;
} Binary_tree ;

int read_file(){
    FILE* filePtr = fopen("countries2.txt", "r");
    if(!filePtr) {
        perror("Error encountered while opening file!\n");
        exit(-1);
    }
    char str[1500];
    if(str[0] == '-' && str[1] == '1')
        return -1;
    return 0;
}
void construct_binary_tree(Node* current){

}