#include <stdio.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node* next;
} *top = NULL;    

void push(){
    struct node *newNode = malloc(sizeof(newNode));
    if (newNode == NULL){
        printf("Stack overflow\n");
        exit(1);
    }
    int data;
    printf("Enter the number you want to push :\n");
    scanf("%d",&data);

    
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void display(){
    struct node *temp = top;
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    printf("The numbers from top to bottom :\n");
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

int isEmpty(){
    if( top == NULL){
        return 1;
    }
    else {
    return 0;
    } 
}

void pop(){
    struct node *temp;
    temp = top;
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    int popped = temp->data;
    top = top->next;
    free(temp);
    temp = NULL;
    printf("Item popped :%d\n",popped);
}

void peek(){
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    printf("The top data is : %d\n",top->data);
}

void posDisplay(){
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    int pos = 1;
    int displayPos;
    printf("Enter the position of number that you want to delete :\n");
    scanf("%d\n",&displayPos);
    struct node *temp = top;
    while(pos!=displayPos){
        temp=temp->next;
        pos++;
    }
    printf("The number at the location that you want to display :%d\n",temp->data);
}

int main(){
    for (int i = 0 ; i<10 ; i++){
        push();
    }
    display();
    pop();
    pop();
    push();
    display();
    peek();
    posDisplay();    
    return 0;
}
