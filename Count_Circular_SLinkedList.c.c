// Counting of Nodes present in Singly Circular Linked-List

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

void countNodes(node* start) {
    int count = 0;
    if(NULL == start) {
        printf("Number of nodes is %d\n", count);
        return;
    }
    node* temp;
    temp = start;
    do {
        count++;
        temp = temp->next;
    } while(temp != start);
    printf("Number of nodes is %d\n", count);
    return;
}

int main(void) {
    node* createList(node*, int);
    void countNodes(node*);
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
    countNodes(start);
    return 0;
}