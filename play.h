#include "learn.h"
char* list[100];
void play(Node* root,Node*original){
     char ans ;
    if(root->y == NULL && root->n == NULL) {
        printf("%s",root->data);
        printf("\nDid I guess correctly? (y/n): ");
        ans=getchar();
        getchar();
        if(ans=='y'){
            printf("ksbtk yala\n");
            printf("Would you like to try again ? (y/n): ");
             ans=getchar();
             getchar();
             if(ans=='y'){
                 play(original,original);
             }
             if(ans=='n')
             {
                 printf("Thanks for Playing <3");
                 exit(0);
             }
        }
        else if(ans=='n'){

            //learning section

            printf("What was the country you were thinking of ? : ");
            char* newcountry = scanf("%s",&newcountry);
            printf("What question should I have asked ? : ");
            char* newquestion = scanf("%s",&newquestion);
            printf("OK!\n");
            learn(root->data,newcountry,newquestion);// Learn function to add the new country and its question into the file
            
            printf("Would you like to try again ? (y/n): ");
            ans=getchar();
            getchar();
            if(ans=='y'){
                play(original,original);
            }
            else if(ans=='n')
            {
                printf("Thanks for Playing <3");
                exit(0);
            }
            else
                printf("Wrong input please try again");
        }
    }
    else{
        printf("%s ",root->data);
        ans=getchar();
        getchar();
    }
    if(ans=='y')
      play(root->y, original);
    else if (ans=='n')
      play(root->n,original);
    else
      printf("Invalid input");

}