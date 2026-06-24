// Insertion at the Last of the Singly Circular Linked-List

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

void insertList(node* start, int num) {
    if(start == NULL) {
        printf("No List is present to insert\n");
        return;
    }
    node* newNode, *lastNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->info = num;
    newNode->next = NULL;
    lastNode = start;
    while(lastNode->next != start) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->next = start;
    return;
}

void displayList(node* start) {
    if(start == NULL) {
        printf("List is empty to display\n");
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
    void insertList(node*, int);
    void displayList(node*);
    node* start;
    int num, another;
    start = NULL;
    printf("YES/NO 1/0");
    scanf("%d", &another);
    while(another == 1) {
        printf("Enter the number to add in Linked-List");
        scanf("%d", &num);
        start = createList(start, num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    printf("Enter the number to be entered\n");
    scanf("%d", &num);
    
    printf("Before Insertion\n");
    displayList(start);
    printf("\n");
    
    insertList(start, num);
    
    printf("After Insertion\n");
    displayList(start);
    return 0;
}