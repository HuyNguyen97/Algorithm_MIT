#include <iostream>

using namespace std;

struct node{
	int data;
	node* next;
};

struct Queue{
	node* front;
	node* rear;
};

node* new_q_node(int key){
	node* new_node = new node;
	new_node->data = key;
	new_node->next = NULL;
	return new_node;
}
void enqueue(Queue*& queue, int key){
	node* temp = new_q_node(key);
	if(queue->rear == NULL){
		queue->rear = queue->front = temp;
		return;
	}
	queue->rear->next = temp;
	queue->rear = temp;
}

int dequeue(Queue*& queue){
	if(queue->front == NULL) return 0;
	node* pTemp = queue->front;
	queue->front = pTemp->next;
	if(queue->front == NULL){
		queue->rear = NULL;
	}
	pTemp->next = NULL;
	int key = pTemp->data;
	delete pTemp;
	return key;
}

int main(){
	int num = 0;
	Queue* queue = new Queue;
	queue->front = NULL;
	queue->rear = NULL;
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	enqueue(queue, 5);
	enqueue(queue, 6);
	while(queue->front != NULL){
		num = dequeue(queue);
		cout<<num<<" ";
	}
	cout << endl;
	return 0;
}
