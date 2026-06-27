// Creation of Doubly Circular Linked-List
# include <stdio.h>
# include <stdlib.h>

struct doublyList {
    struct doublyList* prev;
    int info;
    struct doublyList* next;
};
typedef struct doublyList node;
node *start, *last;

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
        newNode->prev = last;
        last = newNode;
    }
    newNode->next = start;
    start->prev = newNode;
    return;
}

void displayListForward() {
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

void displayListReverse() {
    if(start == NULL) {
        printf("No list is present to display\n");
        return;
    }
    node* temp;
    temp = last;
    do {
        printf("%d\t", temp->info);
        temp = temp->prev;
    } while(temp != last);
    return;
}

int main(void) {
    void createList(int);
    void displayListForward();
    void displayListReverse();
    start = last = NULL;
    int num, another;
    printf("YES/NO 1/0");
    scanf("%d", &another);
    while(another == 1) {
        printf("Enter the number to be insert");
        scanf("%d", &num);
        createList(num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    printf("Forward List\n");
    displayListForward();
    printf("\n");
    
    printf("Reverse List\n");
    displayListReverse();
    return 0;
}