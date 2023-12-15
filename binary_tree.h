typedef struct Node{
    char* Q;
    struct Node* y;
    struct Node* n;
} Node;

typedef struct Binary_tree{
    Node* root;
} Binary_tree ;

void read_file(){
    FILE* filePtr = fopen("countries2.txt", "r");
    if(!filePtr) {
        perror("Error encountered while opening file!\n");
        return;
    }
    char str[2000];
    fgets(str, sizeof(str), filePtr);
    fgets(str, sizeof(str), filePtr);
    //fread(str, sizeof(str), 1, filePtr);
    printf("%s", str);
}