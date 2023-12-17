void learn(char* oldcountry,char * newcountry,char* newquestion){
char* buffer = (char*)malloc(MAX_LINE_SIZE*sizeof(char*));
printf("Enterd learn funciton\n");
FILE* fileptr = fopen("countries.txt","r+");
if(fileptr==NULL){
    perror("Error encountered while opening file!\n");
    exit(-1);
}
else{
while(fgets(buffer,MAX_LINE_SIZE,fileptr)){

if(buffer==oldcountry){
   fprintf(fileptr,newquestion,"? (y/n):/n",newcountry,"-1\n-1/n",oldcountry,"\n-1\n-1\n");
   break;
}

}
}


fclose(fileptr);

//construct_binary_tree(fileptr,Binary_tree);
    
}