// Searching element in a Linked-List

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

void searchList(node* start, int num) {
    if(start == NULL) {
        printf("No list is present to be searched\n");
    } else {
        while(start != NULL) {
            if(start->info == num) {
                printf("Number Found\n");
                return;
            }
            start = start->next;
        }
        printf("Number not found\n");
    }
    return;
}

int main(void) {
    node* createList(node*, int);
    void searchList(node*, int);
    node* start;
    int num;
    int another = 1;
    start = NULL;
    while(another == 1) {
        printf("Enter the number to insert\n");
        scanf("%d", &num);
        start = createList(start, num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    printf("Give me the number to be searched\n");
    scanf("%d", &num);
    searchList(start, num);
    return 0;
}