// Sorting in Singly Circular Linked-List

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

void sortList(node* start) {
    if(start == NULL) {
        printf("No List is present to sort\n");
        return;
    }
    node* prev, *after;
    for(prev = start; prev->next != start; prev = prev->next) {
        for(after = prev->next; after != start; after = after->next) {
            if(prev->info > after->info) {
                int temp = prev->info;
                prev->info = after->info;
                after->info = temp;
            }
        }
    }
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
    void sortList(node*);
    void displayList(node*);
    node* start;
    int num, another;
    start = NULL;
    printf("YES/NO 1/0");
    scanf("%d", &another);
    while(another == 1) {
        printf("Enter the number to insert\n");
        scanf("%d", &num);
        start = createList(start, num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    printf("Linked-List Before Sorting\n");
    displayList(start);
    printf("\n");
    
    sortList(start);
    
    printf("Linked-List After Sorting\n");
    displayList(start);
    return 0;
}