// Deletion of element at the middle of the Linked List

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

void deleteList(node* start, int pos) {
    if(start == NULL) {
        printf("No list is present to delete");
        return;
    }
    int i=0;
    while(i<pos-2) {
        start = start->next;
        i++;
    }
    node* temp = start->next;
    start->next = start->next->next;
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
    void deleteList(node*, int);
    void displayList(node*);
    node* start;
    int num,pos;
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
    
    printf("Enter the position you want to delete from the list");
    scanf("%d", &pos);
    deleteList(start, pos);
    
    printf("After Deletion\n");
    displayList(start);
    return 0;
}