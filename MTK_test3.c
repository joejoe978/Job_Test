#include <stdlib.h>
#include <stdio.h>

struct node{
    int val;
    struct node *next;
};
typedef struct node Node;

Node *tmp1,*tmp2,*tmp3,*tmp4,*head;

Node* reverseLinklist(Node *first){
    if(!first) return NULL;
    if(!first->next) return first;

    Node *pre = NULL, *future = first->next;

    while(first->next!=NULL && first->next->next!=NULL){
        first->next = pre;
        pre = first;
        first = future;
        future = future->next;
    }
    first->next = pre;
    future->next = first;
    return future;
}
void print(Node *first){
    //if (first==NULL) return NULL;

    while(first!=NULL){
        printf("%d -> ",first->val);
        first = first->next;
    }
    printf("NULL \n");
    return ;
}

int main(){
    tmp1 = (Node*)malloc(sizeof(Node));
    tmp2 = (Node*)malloc(sizeof(Node));
    tmp3 = (Node*)malloc(sizeof(Node));
    tmp4 = (Node*)malloc(sizeof(Node));

    head = tmp1;
    tmp1->val = 1;
    tmp1->next = NULL;
    //tmp2->val = 2;
    //tmp2->next = NULL;
    //tmp3->val = 3;
    //tmp3->next = tmp4;
    //tmp4->val = 4;
    //tmp4->next = NULL;
    print(head);

    Node *newhead = reverseLinklist(head);
    print(newhead);
    return 0;
}

