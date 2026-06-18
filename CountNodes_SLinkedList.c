// Count number of nodes in Singly Linked List

# include <stdio.h>
# include <stdlib.h>

typedef struct singleList {
    int info;
    struct singleList* next;
} node;

node* createList(node* start, int num) {
    node* newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->info = num;
    newNode->next = NULL;
    if(start == NULL) {
        start = newNode;
        return start;
    }
    node* lastNode;
    lastNode = start;
    while(lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    return start;
}

void countListNode(node* start) {
    int count = 0;
    if(start == NULL) {
        printf("Count is %d", count);
        return;
    }
    while(start != NULL) {
        count++;
        start = start->next;
    }
    printf("Count is %d", count);
    return;
}

int main(void) {
    node* createList(node*, int);
    void countListNode(node*);
    node* start;
    int num, another;
    start = NULL;
    printf("YES/NO 1/0");
    scanf("%d", &another);
    while(another == 1) {
        printf("Enter the number to insert in list");
        scanf("%d", &num);
        start = createList(start, num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    countListNode(start);
    return 0;
}