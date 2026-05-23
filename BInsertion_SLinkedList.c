// Insertion at the beginning of linked list

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
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    return start;
}

node* addNode_Beginning(node* start, int num) {
    node* newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->info = num;
    newNode->next = start;
    start = newNode;
    return start;
}

void displayList(node* start) {
    if(start == NULL) {
        printf("Link List is empty, nothing to display");
        return;
    }
    printf("The elements are\t");
    while(start != NULL) {
        printf("%d\t", start->info);
        start = start->next;
    }
    printf("\n");
    return;
}

int main(void) {
    node* createList(node*, int);
    node* addNode_Beginning(node*, int);
    void displayList(node*);
    node* start;
    int num;
    int another = 1;
    start = NULL;
    while(another == 1) {
        printf("Enter the number to enter");
        scanf("%d", &num);
        start = createList(start,num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    
    printf("Before Insertion\n");
    displayList(start);
    
    printf("Enter the number to enter");
    scanf("%d", &num);
    start = addNode_Beginning(start, num);
    
    printf("After Insertion\n");
    displayList(start);
    
    return 0;
}