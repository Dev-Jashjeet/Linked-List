// Creation and Display of Singly Circular Linked List

# include <stdio.h>
# include <stdlib.h>

struct singleList {
    int info;
    struct singleList* next;
};
typedef struct singleList node;

node* createList(node* start, int num) {
    node* newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->info = num;
    newNode->next = NULL;
    if(start == NULL) {
        start = newNode;
    } else {
        node* lastNode;
        lastNode = start;
        while(lastNode->next != start) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    newNode->next = start;
    return start;
}

void displayList(node* start) {
    if(start == NULL) {
        printf("No list is present to display");
        return;
    }
    node* temp = start;
    do {
        printf("%d\t", start->info);
        start = start->next;
    }
    while(start != temp);
    return;
}

int main(void) {
    node* createList(node*, int);
    void displayList(node*);
    node* start;
    int num;
    int another = 1;
    start = NULL;
    while(another == 1) {
        printf("Enter the number to insert");
        scanf("%d", &num);
        start = createList(start, num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    displayList(start);
    return 0;
}