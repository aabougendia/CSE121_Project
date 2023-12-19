
void insertnode(char* oldcountry,char * newcountry,char* newquestion,Node** iteratorPtr){
    printf("infinite recursion\n");
   if((*iteratorPtr)!=NULL) {

       if ((*iteratorPtr)->y->data == oldcountry || (*iteratorPtr)->n->data == oldcountry) {
           if ((*iteratorPtr)->y->data == oldcountry)
               (*iteratorPtr)->y->data = newquestion;
           else if ((*iteratorPtr)->n->data == oldcountry)
               (*iteratorPtr)->n->data = newquestion;

           Node *Ynode = (Node *) malloc(sizeof(Node)); // creating new node for the Yes link ( New country )
           (*iteratorPtr)->y = Ynode;
           Ynode->data = newcountry;
           Ynode->y = NULL;
           Ynode->n = NULL;
           Node *Nnode = (Node *) malloc(sizeof(Node));//creating new node for the No link ( old country )
           (*iteratorPtr)->n = Nnode;
           Nnode->data = oldcountry;
           Nnode->y = NULL;
           Nnode->n = NULL;
           return;
       }
       //pre-order traversal left
       insertnode(oldcountry,newcountry,newquestion,&((*iteratorPtr)->y));
       //pre-order traversal right
       insertnode(oldcountry,newcountry,newquestion,&((*iteratorPtr)->n));

   }



}

void Write_BinTree(FILE *fptr,Node * iterator){
    printf("Entered write function");
    if(iterator!=NULL){
        fprintf(fptr,"%s\n",iterator->data);
        Write_BinTree(fptr,iterator->y);
        Write_BinTree(fptr,iterator->n);
    }
    else if(iterator == NULL)
        fprintf(fptr,"-1\n");
}



void learn(Binary_tree countries,char* oldcountry,char * newcountry,char* newquestion){

insertnode(oldcountry,newcountry,newquestion,&countries.root);
printf("\n***********************Exited insertion function");
FILE * fptr = fopen("C:\\Users\\Kareem\\Desktop\\Kareem\\University\\Engineering - Year 2\\2- Advanced Programming\\Project\\Country-guessing-game repo\\CSE121_Project\\Write_NewBinTree.txt","w");
if(fptr==NULL)
    perror("Error encountered while opening file");
else
    Write_BinTree(fptr,countries.root);


}




