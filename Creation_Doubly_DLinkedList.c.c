// Creation of Doubly Linked-List

# include <stdio.h>
# include <stdlib.h>

struct doublyList {
    struct doublyList* prev;
    int info;
    struct doublyList* next;
};
typedef struct doublyList node;
node *start, *last;

void insertList(int num) {
    node* newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->prev = NULL;
    newNode->info = num;
    newNode->next = NULL;
    if(start == NULL) {
        start = last = newNode;
        return;
    }
    last->next = newNode;
    newNode->prev = last;
    last = newNode;
    return;
}

void displayListForward() {
    if(start == NULL) {
        printf("No list is present to display\n");
        return;
    }
    node* temp;
    temp = start;
    while(temp != NULL) {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    return;
}

void displayListReverse() {
    if(start == NULL) {
        printf("No list is present to display\n");
        return;
    }
    node* temp;
    temp = last;
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
    start = last = NULL;
    int num, another;
    printf("YES/NO 1/0");
    scanf("%d", &another);
    while(another == 1) {
        printf("Enter the number in the list\n");
        scanf("%d", &num);
        insertList(num);
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