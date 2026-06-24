// Insertion at the Middle of the Singly Circular Linked-List

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

void insertList(node* start, int pos, int num) {
    if(start == NULL) {
        printf("No List available to insert\n");
        return;
    }
    node* newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->info = num;
    newNode->next = NULL;
    int i=0;
    while(i<pos-2) {
        start = start->next;
        i++;
    }
    newNode->next = start->next;
    start->next = newNode;
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
    void insertList(node*, int, int);
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
    printf("Enter the position and number to be entered\n");
    scanf("%d %d", &another, &num);
    
    printf("Before Insertion\n");
    displayList(start);
    printf("\n");
    
    insertList(start, another, num);
    
    printf("After Insertion\n");
    displayList(start);
    return 0;
}