// Deletion at the End of Singly Circular Linked-List

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

void deleteNode(node* start) {
    if(start == NULL) {
        printf("No Node exists to delete\n");
        return;
    }
    node* prevNode, *temp;
    prevNode = start;
    while(prevNode->next->next != start) {
        prevNode = prevNode->next;
    }
    temp = prevNode->next;
    prevNode->next = start;
    free(temp);
    return;
}

void displayList(node* start) {
    if(start == NULL) {
        printf("No List is present to display\n");
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
    void deleteNode(node*);
    void displayList(node*);
    node* start;
    int num, another;
    start = NULL;
    printf("YES/NO 1/0");
    scanf("%d", &another);
    while(another == 1) {
        printf("Enter the number to insert at Linked-List\n");
        scanf("%d", &num);
        start = createList(start, num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    
    printf("Before Deletion\n");
    displayList(start);
    printf("\n");
    
    deleteNode(start);
    
    printf("After Deletion\n");
    displayList(start);
    return 0;
}