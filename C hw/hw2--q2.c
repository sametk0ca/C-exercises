#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
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
        temp->next = lastNode;
        temp = temp->next;
    }


}


struct node2 {
    int data2;
    struct node2 *next2;
}*root2;



void createNode2(int n){
    struct node2 *lastNode2 ,*temp2;
    int data2 ,i;
    root2 = (struct node2 *)malloc(sizeof(struct node2));
    printf("\ninput data for node 1\n");
    scanf("%d",&data2);
    root2->data2=data2;
    root2->next2=NULL;
    temp2=root2;

    for(i=2 ; i<n+1 ; i++){
        lastNode2 = (struct node2*)malloc(sizeof(struct node2));
        printf("input data for node %d\n",i);
        scanf("%d" , &data2);
        lastNode2->data2 = data2;
        lastNode2->next2 = NULL;
        temp2->next2 = lastNode2;
        temp2 = temp2->next2;
    }

}

void compare(){
    struct node *temp;
    struct node2 *temp2;
    temp = root;
    temp2 = root2;

    while (temp != NULL){
        while(temp2 != NULL){

            if ( temp->data == temp2->data2) {
                printf("\nValues are same\n");
            }

            else{
                printf("\nValues are NOT same \n");
            }

            temp = temp->next;
            temp2 = temp2->next2;
            
        }
    }

}


void merge(){
    struct node *temp;
    temp = root;
    while (temp->next != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    };  
    temp->next = root2;
    while (temp->data != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    };  
    

};



int main(){
    createNode(3);
    createNode2(3);
    compare();
    merge();
    
    return 0;


}