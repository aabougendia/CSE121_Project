void Write_BinTree(FILE *fptr,Node * iterator){
    fprintf(fptr,"%s\n",iterator->data);
    if(iterator->y!=NULL && iterator->n!=NULL){
        Write_BinTree(fptr,iterator->y);
        Write_BinTree(fptr,iterator->n);
    }
    else{
        fprintf(fptr,"-1\n");
        fprintf(fptr,"-1\n");
    }
}

void learn(Node** rnode,char * newcountry,char* newquestion){
    char* temp = (*rnode) -> data; // old country

    (*rnode) -> data = newquestion; // newquestion
    (*rnode) -> y = (Node*) malloc(sizeof(Node)); //newnode
    (*rnode) -> n = (Node*) malloc(sizeof(Node)); //newnode

    (*rnode) -> y -> data = newcountry; // new country
    (*rnode) -> n -> data = temp; // old country
}




