#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node* next;
};

void printList(Node* n){
	while(n != NULL){
		cout<<n->data<<" ";
		n = n->next;
	}
	cout<<endl;
}

Node* reverseList(Node* head){
	Node *prevNode, *currentNode, *nextNode;
	prevNode = NULL;
	currentNode = head;
	while(currentNode != NULL){
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
	head = prevNode;
	return head;
}

int main(){
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	cout<<"Original List: ";
	printList(head);

	head = reverseList(head);

	cout<<"Reversed List: ";
	printList(head);

	return 0;
}




