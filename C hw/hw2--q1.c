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


void display(){
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
}



void displayThird(){
    struct node *temp;
    temp=root;
    temp = temp->next->next; // eleman sayısı az diye böyle yazdım çok olsaydı for kullanacaktım.
    printf("Third data is : %d\n", temp->data);

};


void sumofData(){
    int sum = 0;
    int j ;
   
    struct node *temp;
    temp = root;
    
    for(j = 0 ; j < 4 ; j++){
      
        sum = sum + temp->data;
        temp = temp->next;
       
       

    }
    printf("The sum of datas : %d ", sum);
};





int main(){
    createNode(4);
    display();
    displayThird();
    sumofData();
    return 0;
}