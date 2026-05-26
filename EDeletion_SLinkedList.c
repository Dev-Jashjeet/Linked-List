// Deletion of element at the end of the Linked List

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

void deleteList(node* start) {
    if(start == NULL) {
        printf("No list is present to delete");
        return;
    }
    while(start->next->next != NULL) {
        start = start->next;
    }
    node* temp = start->next;
    start->next = NULL;
    free(temp);
    return;
}

void displayList(node* start) {
    if(start == NULL) {
        printf("No list is present to display\n");
        return;
    }
    while(start != NULL) {
        printf("%d\t", start->info);
        start = start->next;
    }
    printf("\n");
    return;
}

int main(void) {
    node* createList(node*, int);
    void deleteList(node*);
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
    printf("Before Deletion\n");
    displayList(start);
    
    deleteList(start);
    
    printf("After Deletion\n");
    displayList(start);
    return 0;
}