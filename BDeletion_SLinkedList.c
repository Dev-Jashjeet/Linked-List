// Deletion of element from starting of the Linked List

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

node* deleteList(node* start) {
    if(start == NULL) {
        printf("No list is present to delete");
        return NULL;
    }
    printf("The number deleted is %d\n", start->info);
    node* temp = start;
    start = start->next;
    free(temp);
    return start;
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
    node* deleteList(node*);
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
    
    start = deleteList(start);
    
    printf("After Deletion\n");
    displayList(start);
    return 0;
}