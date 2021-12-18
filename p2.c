#include "llist.h"
/**
*Program 2
*description
*CS320
*October 7, 2020
*@author Jenna Coffman cssc2616
*/

void printID(){
    printf("Program #2, cssc2616, Jenna Coffman\n");
}

int main(int argc, char* argv[]){
    printID();
    
    char buffer[30];
    
    FILE * database;
    
    if(argc!=2){
    	perror("Input file error:");
    }
    
    database = fopen(argv[1], "r");

    if (NULL == database){
         perror("Error opening file:");
         return (-1);
    }
	
	while(fscanf(database, "%[^\n]", buffer) != EOF){
        printf("> %s\n", buffer); 
    }
	
	Link root = strToList(buffer);
    
    print(root);
    printf("\n");
    
    printf("%d\n", size(root));
    
    Data t = 't';
    Data o = 'o';
    
    Link found = find(t, root);
    
	while(found != NULL){ 
	
		Link q = malloc(sizeof(Node));
    	q->data = o;
    	
        insert(found, found->next, q);
        
        found = find(t,found->next);

    }
    
    print(root);
    printf("\n");
    
    printf("%d\n", size(root)); 
     
    Link node2 = malloc(sizeof(Node));
    
    node2 = root->next;
    
    delete(node2, node2->next);
    
    print(root);
    printf("\n");
    
    deleteList(root);
    
    
    fclose(database);
    
    return 0;
}