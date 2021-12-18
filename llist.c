#include "llist.h"

Link root = NULL;

Link strToList(char s[]){ 
    Link node;
    Link temp;
    char *z = s;
    
    if( *z != '\0'){
          
        if(root == NULL){
        
            root = malloc(sizeof(Node));
       		root->data = *z; 
        	root->next = NULL;  
        	
        } else{
        
			node = malloc(sizeof(Node));
        	node->data = *z; 
        	node->next = NULL; 
        	 
            temp = root;
            
            while(temp != NULL){
            
                if(temp->next == NULL){
                
                    temp->next = node;
                    break;
                }
                
                temp = temp->next;
            }
        }
        
        printf("%s: %c\n", z , *z);
        z++;
        s = z; 
        strToList(s);
        
    }
    return root; 
}

int size(Link head){

    if(head == NULL) return 0;
    
    return 1 + size(head->next);
}

Link find(Data c, Link head){

    if(head == NULL){
    
        return NULL;
        
    }else if(head->data == c){
    
        return head;
        
    }else{
    
        find(c, head->next);
        
    }
    
    return NULL;
}

void insert(Link p1, Link p2, Link q){

    q->next = p2;
    p1->next = q; 
        
}

void delete(Link p, Link q){

    p->next = q->next;
    free(q);
    
}

void deleteList(Link head){

    if (head==NULL) return;
    
    printf("deleting %c\n", head->data);
    
    deleteList(head->next);
    free(head);
    
}

void print(Link head){
    
    if(head==NULL)return;
    
    printf("%c ", head->data);
    
    if(head->next==NULL) return;
    
    print(head->next);
}
