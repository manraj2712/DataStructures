#include<bits/stdc++.h>

using namespace std;

class a{
	int data;
	public:
	a(){
		this->data=5;
	}
}a1;

class Node{
	int data;
	Node* nextPtr;
	public:
	Node(){
		this->data = 0;
		this->nextPtr = NULL;
	}
	Node(int data){
		this->data = data;
		this->nextPtr = NULL;
	}
	int getData(){
		return this->data;
	}
	Node* getNextPointer(){
		return this->nextPtr;
	}
	void setData(int data){
		this->data = data;
	}
	void setNextPointer(Node* p){
		this->nextPtr = p;
	}
};


class LinkedList {
	Node* head;
	public:
	LinkedList(){
		head = NULL;
	}
	Node* getHead(){
		return head;
	}
	void appendNode(int);
	void deleteNode(int);
	void printList(Node*);
	void moveToHead(int);
	void insertNode(int);
	void reverseList();
	void reverseRecursively(Node*,Node*);
	void concatenateList(LinkedList* l2){
		Node* temp = head;
		while(temp->getNextPointer()!=NULL){
			temp = temp->getNextPointer();
		}
		temp->setNextPointer(l2->getHead());
	}

};

void LinkedList::reverseRecursively(Node* p,Node* prev){
	if(p->getNextPointer() == NULL){
		p->setNextPointer(prev);
		head = p;
		return;
	}
	reverseRecursively(p->getNextPointer(),p);
	p->setNextPointer(prev);
}
void LinkedList::moveToHead(int key){
	Node* temp = head;

	while(temp->getNextPointer() != NULL){
			if(temp->getNextPointer()->getData()==key){
				Node* temp2 = temp->getNextPointer();
				temp->setNextPointer(temp2->getNextPointer());
				temp2->setNextPointer(head);
				head = temp2;
				cout<<"Key Found";
				return;
			}
		temp = temp->getNextPointer();
	}
	cout<<"No Key Found";
}
void LinkedList::deleteNode(int index){
	Node* temp = head;
	Node* temp2;
	if(index == 0){
		head = temp->getNextPointer();
		delete temp;
		return;
	}
	while(index-- > 0){
		temp2 = temp;
		temp = temp->getNextPointer();
	}
	temp2->setNextPointer(temp->getNextPointer());
	delete temp;
}

void LinkedList::appendNode(int data){
	Node* newNode = new Node(data);
	if(head == NULL){
		head = newNode;
		return;
	}
	Node* temp = head;
	while(temp->getNextPointer() != NULL){
		temp = temp->getNextPointer();
	}
	temp->setNextPointer(newNode);
	newNode->setNextPointer(NULL);
}

void LinkedList::printList(Node* p){
	if(p!=NULL){

	cout<<p->getData()<<endl;
	p->setNextPointer(p->getNextPointer());
	printList(p->getNextPointer());
	}
}

void LinkedList::insertNode(int data){
	Node* temp = head;
	Node* newNode = new Node(data);
	while(temp != NULL){
		if(temp->getNextPointer()!=NULL){
			if(newNode->getData() > temp->getNextPointer()->getData()){
				temp = temp->getNextPointer();
				continue;
			}
			break;
		}
	}
	newNode->setNextPointer(temp->getNextPointer());
	temp->setNextPointer(newNode);
}
void LinkedList::reverseList(){ // sliding pointers approach

	Node *current,*previous,*temp;
	current = head;
	temp = NULL;
	previous = NULL;
	while(current != NULL){
		temp = previous;
		previous = current;
		current = current->getNextPointer();
		previous->setNextPointer(temp);
	}
	head = previous;

	
}


int main() {

	LinkedList* l1 = new LinkedList();
	LinkedList* l2 = new LinkedList();
	l2->appendNode(60);
	l1->appendNode(10);  
	l1->appendNode(20);
	l1->appendNode(30); 
	l1->appendNode(40); 
	l1->appendNode(50); 
	l1->printList(l1->getHead());
	// l1->reverseRecursively(l1->getHead(),NULL);
	l1->concatenateList(l2);
	l1->printList(l1->getHead());
}