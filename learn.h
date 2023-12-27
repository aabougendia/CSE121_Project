void Write_BinTree(FILE *fPtr, Node * iterator){ // writing on the file with pre-order traversal
    fprintf(fPtr, "%s\n", iterator->data); //writing data to file
    if(iterator->y != NULL && iterator->n != NULL){
        Write_BinTree(fPtr, iterator->y); // traversing left
        Write_BinTree(fPtr, iterator->n); // traversing right
    }
    else{
        fprintf(fPtr, "-1\n"); // Serializing file by adding "-1" after each leaf
        fprintf(fPtr, "-1\n");
    }
}

void learn(Node** root, char * new_country, char* new_question){ // Learn function to add the two new nodes 
    char* temp = (*root) -> data; // old country

    (*root) -> data = new_question; // new_question
    (*root) -> y = (Node*) malloc(sizeof(Node)); //newnode
    (*root) -> n = (Node*) malloc(sizeof(Node)); //newnode

    (*root) -> y -> data = new_country; // new country
    (*root) -> n -> data = temp; // old country
}




