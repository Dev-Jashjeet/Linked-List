// MergeSort of 2 sorted Linked List

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

node* createResultList(node* result, int num) {
    node* newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->info = num;
    newNode->next = NULL;
    if(result == NULL) {
        result = newNode;
    } else {
        node* lastNode;
        lastNode = result;
        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    return result;
}

void displayList(node* result) {
    if(result == NULL) {
        printf("List is empty");
        return;
    }
    printf("The resultant elements in linked list are \n");
    while(result != NULL) {
        printf("%d\t", result->info);
        result = result->next;
    }
    return;
}

int main(void) {
    node* createList(node*, int);
    node* createResultList(node*, int);
    void displayList(node*);
    node* left, *right, *result;
    left = right = result = NULL;
    int num;
    int another = 1;
    printf("Enter the values in 1st Linked List\n");
    while(another == 1) {
        printf("Number to be inserted");
        scanf("%d", &num);
        left = createList(left,num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    
    printf("Enter the values in 2nd Linked List\n");
    another = 1;
    while(another == 1) {
        printf("Number to be inserted");
        scanf("%d", &num);
        right = createList(right,num);
        printf("YES/NO 1/0");
        scanf("%d", &another);
    }
    
    while(left!= NULL && right!= NULL) {
        if(left->info > right->info) {
            result = createResultList(result, right->info);
            right = right->next;
        }
        else if(left->info < right->info) {
            result = createResultList(result, left->info);
            left = left->next;
        }
        else {
            result = createResultList(result, left->info);
            left = left->next;
            right = right->next;
        }
    }
    while(left != NULL) {
        result = createResultList(result, left->info);
        left = left->next;
    }
    while(right != NULL) {
        result = createResultList(result, right->info);
        right = right->next;
    }
    
    displayList(result);
    return 0;
}