// Searching element in Singly Circular Linked-List

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
        while(start != lastNode->next) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    newNode->next = start;
    return start;
}

void searchList(node* start, int num) {
    if(NULL == start) {
        printf("No Linked-List is present to perform search operation");
        return;
    }
    node* temp;
    temp = start;
    do {
        if(temp->info == num) {
            printf("Number Found in Linked-List");
            return;
        }
        temp = temp->next;
    } while(start != temp);
    printf("Number not found in Linked-List");
    return;
}

int main(void) {
    node* createList(node*, int);
    void searchList(node*, int);
    node* start;
    int num;
    int another;
    start = NULL;
    printf("YES/NO 1/0");
    scanf("%d", &another);
    while(another == 1) {
        printf("Enter the number to insert in Linked-List");
        scanf("%d", &num);
        start = createList(start,num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    if(NULL != start) {
        printf("Enter the number to search in the Linked-List");
        scanf("%d", &num);
        searchList(start,num);
    }
    return 0;
}