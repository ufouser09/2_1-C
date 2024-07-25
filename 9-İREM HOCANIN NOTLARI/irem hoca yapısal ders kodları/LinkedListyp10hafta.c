#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

void push(struct node *head, int value){
    struct node *current = head;

    while(current->next != NULL)
        current = current->next;
    current->next = malloc(sizeof (struct node));
    current->next->value = value;
    current->next->next = NULL;
}

// returns new head
struct node *addHead(struct node *head, int value){

    struct node newNode = {value, head};
    return &newNode;
}
void list(struct node *head){
    struct node *current = head;
    while(current->next != NULL ){
        printf("%d,",current->value);
        current = current->next;
    }
    printf("%d",current->value);

}
void deleteNode(struct node * head, int val){
    struct node* current= head, *before =NULL;

    while(current->value != val && current->next !=NULL){
        before = current;
        current = current->next;
    }
    if(current->value != val)
        printf("yok");
    else{
        before->next = current->next;
        free(current);
    }
}
int main(){

    struct node *head,*newHead,*dummy;

    int num;
    head = malloc(sizeof(struct node));

    //
    scanf("%d", &num);
    (*head).value = num; // exact => head->value = num;
    head->next =NULL;

    //
    scanf("%d", &num);
    push(head,num);

    //
    scanf("%d",&num);
    newHead = addHead(head,num);
    list(head);




}