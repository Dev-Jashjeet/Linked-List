// Creation and Display of Doubly Linked-List

# include <stdio.h>
# include <stdlib.h>

struct doublyList {
    struct doublyList* prev;
    int info;
    struct doublyList* next;
};
typedef struct doublyList node;
node* start, *last;

void createList(int num) {
    node* newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->prev = NULL;
    newNode->info = num;
    newNode->next = NULL;
    if(start == NULL) {
        start = last = newNode;
    } else {
        last->next = newNode;
        newNode->prev= last;
        last = newNode;
    }
    return;
}

void displayListForward() {
    if(start == NULL) {
        printf("No list is present");
        exit(0);
    }
    node* temp = start;
    while(temp != NULL) {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void displayListReverse() {
    if(last == NULL) {
        printf("No List is present");
        return;
    }
    node* temp = last;
    while(temp != NULL) {
        printf("%d\t", temp->info);
        temp = temp->prev;
    }
    return;
}

int main(void) {
    void createList(int);
    void displayListForward();
    void displayListReverse();
    int num;
    int another;
    last = start = NULL;
    printf("YES/NO 1/0");
    scanf("%d", &another);
    while(another == 1) {
        printf("Enter the number to insert in the list");
        scanf("%d", &num);
        createList(num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    printf("Linked List Forward\n");
    displayListForward();
    printf("Linked List Reverse\n");
    displayListReverse();
    
    return 0;
}