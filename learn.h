void Write_BinTree(FILE *fPtr, Node * iterator){
    fprintf(fPtr, "%s\n", iterator->data);
    if(iterator->y != NULL && iterator->n != NULL){
        Write_BinTree(fPtr, iterator->y);
        Write_BinTree(fPtr, iterator->n);
    }
    else{
        fprintf(fPtr, "-1\n");
        fprintf(fPtr, "-1\n");
    }
}

void learn(Node** root, char * new_country, char* new_question){
    char* temp = (*root) -> data; // old country

    (*root) -> data = new_question; // new_question
    (*root) -> y = (Node*) malloc(sizeof(Node)); //newnode
    (*root) -> n = (Node*) malloc(sizeof(Node)); //newnode

    (*root) -> y -> data = new_country; // new country
    (*root) -> n -> data = temp; // old country
}




