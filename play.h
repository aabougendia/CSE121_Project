char* list[100];
void play(Node* root,Node*original){
     char ans ;
    if(root->y == NULL && root->n==NULL) {
        printf("Is your country %s ? : ",root->data);
        ans=getchar();
        getchar();
        if(ans=='y'){
            printf("ksbtk yala\n");
            printf("Would you like to try again ? : ");
             ans=getchar();
             getchar();
             if(ans=='y')
                 play(original,original);
             if(ans=='n')
             {
                 printf("Thanks for Playing <3");
                 exit(0);
             }
        }
        else if(ans=='n'){
            printf("Whoops  ");
            printf("Would you like to try again ? : ");
            ans=getchar();
            getchar();
            if(ans=='y')
                // learn.h
            if(ans=='n')
            {
                printf("Thanks for Playing <3");
                exit(0);
            }
        }
    }
    else{
        printf("%s : ",root->data);
        ans=getchar();
        getchar();
    }
    if(ans=='y')
        play(root->y,original);
    else if (ans=='n')
        play(root->n,original);
    else
        printf("Invalid input");
}