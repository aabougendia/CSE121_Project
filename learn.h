
void insertnode(Binary_tree countries,char* oldcountry,char * newcountry,char* newquestion,Node** iteratorPtr){

   if(*iteratorPtr!=NULL){

       if(*iteratorPtr->data == oldcountry){

           Node * Qnode =(Node*) malloc(sizeof(Node));
           if(*iteratorPtr->n->data==oldcountry)
               *iteratorPtr->n=Qnode;
           else if(*iteratorPtr->y->data==oldcountry)
               *iteratorPtr->y=Qnode;
           Qnode->data=newquestion;
           Node * Ynode =(Node*) malloc(sizeof(Node));
           Qnode->y=Ynode;
           Ynode->data=newcountry;
           Ynode->y=NULL;
           Ynode->n=NULL;
           Node * Nnode =(Node*) malloc(sizeof(Node));
           Qnode->n=Nnode;
           Nnode->data=oldcountry;
           Nnode->y=NULL;
           Nnode->n=NULL;

       }

   }

//pre-order traversal left
insertnode(countries,oldcountry,newcountry,newquestion,&((*iteratorPtr)->y));
//pre-order traversal right
insertnode(countries,oldcountry,newcountry,newquestion,&((*iteratorPtr)->n));

}





void learn(Binary_tree countries,char* oldcountry,char * newcountry,char* newquestion){

insertnode(countries,oldcountry,&countries.root);

}

