// Sorting of the numbers from Linked-List

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

void sortList(node* start) {
    if(start == NULL) {
        printf("No list available to sort");
        return;
    }
    node* prev, *after;
    for(prev = start; prev->next != NULL; prev = prev->next) {
        for(after = prev->next; after != NULL; after = after->next) {
            if(prev->info > after->info) {
                int t = after->info;
                after->info = prev->info;
                prev->info = t;
            }
        }
    }
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
    void sortList(node*);
    void displayList(node*);
    node* start;
    int num;
    int another = 1;
    start = NULL;
    while(another == 1) {
        printf("Enter the number to enter");
        scanf("%d", &num);
        start = createList(start, num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    
    printf("Before Sorting\n");
    displayList(start);
    
    sortList(start);
    
    printf("After Sorting\n");
    displayList(start);
    return 0;
}