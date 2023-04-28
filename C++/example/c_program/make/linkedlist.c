#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *createLinkedList(){
    Node *head = (Node*)malloc(sizeof(Node));
    if(head == NULL){
        return NULL;
    }
    head->next = NULL;
    return head;
}

Node *insertNodeHead(Node *head, int data){
    Node *node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        printf("Create Node fail\n");
        exit(1);
    }
    printf("insert ...\n");

    node->data = data;
    node->next = head->next;
    head->next = node;

    return head;
}

Node *insertNodeTail(Node *head, int data){
    Node *cur = head;
    while (cur->next != NULL){
        cur = cur->next;
    }
    
    Node *node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        printf("Create Node fail\n");
        exit(1);
    }

    node->data = data;
    node->next = NULL;
    cur->next = node;

    return head;

}

void printLinkedList(Node *head){
    printf("Print Linked List...\n");
    head = head->next;
    while (head != NULL){
        printf("{data:%d,next:%p}\n",head->data, head->next);
        head = head->next;
    }
}

void reverseLinkedList(Node *head){
    Node *pre, *cur;
    pre = head ->next;
    head->next = NULL;

    while(pre){
        cur = pre->next;
        pre->next = head->next;
        head->next=pre;

        pre = cur;
    }
}

int main(int argc, char *argv[]) {
    Node *head = createLinkedList();
    if(head == NULL){
        printf("Create Linked List fail\n");
        return -1;
    }
    printf("head=%p\n",head);

    head = insertNodeHead(head,2);
    head = insertNodeHead(head,3);
    head = insertNodeHead(head,4);
    head = insertNodeTail(head,5);
    head = insertNodeTail(head,7);
    head = insertNodeTail(head,6);
    printf("=====\n");
    printLinkedList(head);

    reverseLinkedList(head);
    printf("================================\n");
    printLinkedList(head);
}