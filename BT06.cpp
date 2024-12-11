#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Deque {
    struct Node* front;
    struct Node* rear;
} Deque;

void initDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

void addFront(Deque* deque, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = deque->front;
    if (deque->front == NULL) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }
    deque->front = newNode;
}
void addRear(Deque* deque,int value){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = deque->rear;
	if (deque->rear == NULL) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
}
void removeFront(Deque* deque) {
    if (deque->front == NULL) {
        printf("Hang doi rong\n");
        return;
    }
    struct Node* item = deque->front;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
}
void removeRear(Deque* deque){
	if (deque->front == NULL) {
        printf("Hang doi rong\n");
        return;
    }
    struct Node* tem = deque->rear;
    deque->rear = deque->rear->prev;
    if(deque->rear == NULL){
    	deque->front = NULL;
	}else{
		deque->rear->next = NULL;
	}
	free(tem);
}
void displayDeque(Deque* deque) {
    struct Node* temp = deque->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Deque deque;
    initDeque(&deque);
    addFront(&deque, 10);
    addFront(&deque, 20);
    addFront(&deque, 30);

    displayDeque(&deque);  
	addRear(&deque,40);
	displayDeque(&deque); 
	removeFront(&deque);
	displayDeque(&deque);
	removeRear(&deque); 
	displayDeque(&deque);
    return 0;
}

