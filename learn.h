
void insertnode(Binary_tree countries,char* oldcountry,char * newcountry,char* newquestion,Node** iteratorPtr){

   if(*iteratorPtr!=NULL){

       if(*iteratorPtr->data == oldcountry){

           Node * Qnode =(Node*) malloc(sizeof(Node)); // creating new node for the new question
           if(*iteratorPtr->n->data==oldcountry)
               *iteratorPtr->n=Qnode;
           else if(*iteratorPtr->y->data==oldcountry)
               *iteratorPtr->y=Qnode;
           Qnode->data=newquestion;
           Node * Ynode =(Node*) malloc(sizeof(Node)); // creating new node for the Yes link ( New country )
           Qnode->y=Ynode;
           Ynode->data=newcountry;
           Ynode->y=NULL;
           Ynode->n=NULL;
           Node * Nnode =(Node*) malloc(sizeof(Node));//creating new node for the No link ( old country )
           Qnode->n=Nnode;
           Nnode->data=oldcountry;
           Nnode->y=NULL;
           Nnode->n=NULL;

       }

   }
   else
       return;

//pre-order traversal left
insertnode(countries,oldcountry,newcountry,newquestion,&((*iteratorPtr)->y));
//pre-order traversal right
insertnode(countries,oldcountry,newcountry,newquestion,&((*iteratorPtr)->n));

}

void Write_BinTree(Node * iterator){



    if(iterator->n!=NULL){


    if(iterator->y==NULL || iterator->n==NULL )
        fprintf(fptr,"\n-1\n-1\n");
    else
        fprintf(fptr,iterator->data);

Write_BinTree(iterator->y);

Write_BinTree(iterator->n);
}



void learn(Binary_tree countries,char* oldcountry,char * newcountry,char* newquestion){

insertnode(countries,oldcountry,newcountry,newquestion,&countries.root);
    FILE * fptr = fopen("C:\\Users\\Kareem\\Desktop\\Kareem\\University\\Engineering - Year 2\\2- Advanced Programming\\Project\\Country-guessing-game repo\\CSE121_Project\\Write_NewBinTree.txt","r+");
Write_BinTree(countries.root);


}




