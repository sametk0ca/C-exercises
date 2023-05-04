#include <stdlib.h>
#include <stdio.h>
int dnumber;
struct node {
    int data;
    struct node *next;
    struct node *prev;
    
}*root;


void createNode(int n){
    struct node *lastNode ,*temp;
    int data ,i;
    root = (struct node *)malloc(sizeof(struct node));
    printf("\ninput data for node 1\n");
    scanf("%d",&data);
    root->data=data;
    root->next=NULL;
    temp=root;


    for(i=2 ; i<n+1 ; i++){
        lastNode = (struct node*)malloc(sizeof(struct node));
        printf("input data for node %d\n",i);
        scanf("%d" , &data);
        lastNode->data = data;
        lastNode->next = NULL;
        lastNode->prev = temp; 
        temp->next = lastNode;
        temp = temp->next;
    }
};


 void display() {
    struct node *temp;
    if(root==NULL){
        printf("list is empty");

    }
    else{
        temp = root;
        while(temp!= NULL){
            printf("Data = %d\n",temp->data);
            

            temp = temp->next;
            
        }
    }
};

void findMax(){
    
    struct node *temp = root;
    int max = temp->data;
    
   
    while(temp != NULL){
        if( max < temp->data ){
           
            max = temp->data;
        }
        temp = temp->next;
    }
    printf("\nThe max value is : %d\n" , max);    
};

void delete(){
    struct node *temp = root;
    struct node *temp2;
   
    printf("\nEnter the number that you want to delete :\n");
    scanf("%d",&dnumber);
    
    while(temp->data != dnumber){
        temp = temp->next;
    }
   
    if(temp->prev == NULL){
       
        root=root->next;
        free(temp);
        temp = NULL;
        
    }

    else if(temp->next == NULL){
       
        while(temp->next!=NULL){
            temp = temp->next; 
        }
        
        temp2 = temp->prev;
        temp2->next = NULL;
        free(temp);
        
    }

    
    
    else{
        
        temp2 = temp->prev;
       
        temp2->next = temp->next;
        
        temp->next->prev = temp2;       
        
        free(temp);
        temp = NULL;
    }
    
};



   

int main(){
    createNode(4);
    display();
    findMax();
    delete();
    display();
 

    return 0;
}
