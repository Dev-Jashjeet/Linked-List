// Insertion at the Beginning of Singly Circular Linked-List

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

node* insertList(node* start, int num) {
    if(start == NULL) {
        printf("No List is present to add the newNode at the beginning\n");
        return start;
    }
    node* newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->info = num;
    newNode->next = NULL;
    // Step 1: traverse the list to the last node and add the address of the newNode in it
    node* lastNode;
    lastNode = start;
    while(lastNode->next != start) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    
    // Step 2: add the address of the start node in the newNode
    newNode->next = start;
    
    // Step 3: change the address of the current start to the newNode
    start = newNode;
    return start;
}

void displayList(node* start) {
    if(start == NULL) {
        printf("No list is present to display\n");
        return;
    }
    node* temp;
    temp = start;
    do {
        printf("%d\t", temp->info);
        temp = temp->next;
    } while(temp != start);
    return;
}

int main(void) {
    node* createList(node*, int);
    node* insertList(node*, int);
    void displayList(node*);
    node* start;
    int num, another;
    start = NULL;
    printf("YES/NO 1/0");
    scanf("%d", &another);
    while(another == 1) {
        printf("Enter the number to insert in Linked-List");
        scanf("%d", &num);
        start = createList(start, num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    printf("Enter the number you want to insert in the beginning\n");
    scanf("%d", &num);
    
    printf("Before Insertion\n");
    displayList(start);
    printf("\n");
    
    start = insertList(start, num);
    
    printf("After Insertion\n");
    displayList(start);
    return 0;
}