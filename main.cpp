#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link = NULL;
};

Node* inserElements(Node* head){
    Node* temp;
    while(true){
        int num;
        cout <<"Enter elment (else -1) : ";
        cin >>num;
        if(num == -1){
            return head;
        }else if(head == NULL){
            head = new Node();
            temp = head;
            head->data = num;
        }else{
            temp->link = new Node();
            temp = temp->link;
            temp->data = num;
        }
    }
    return head;
}

void display(Node* head){
    Node* temp = head;
    if(temp == NULL){
        cout << "LINKED LIST IS EMPTY CAN'T DISPLAY" << endl;
    }

    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->link;
    }
    
}

 void inserAtBiggneing(Node*& head,int num){
    Node* newNode = new Node();
    newNode->data = num;
    newNode->link = head;
    head = newNode;
}

void insertAtEnd(Node* head, int num){
    Node* temp = head;

    if(temp == NULL){
        head = new Node();
        head->data = num;
        return;

    }

    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new Node();
    temp->link->data = num;

    

}

Node* insertAtParticularPosition(Node* head,int num, int position){
    if(head == NULL){
        head = new Node();
        head->data = num;
        return head;
    }else if (position == 1)
    {
        inserAtBiggneing(head,num);
    }
    else{
        Node* temp = head;
        for(int i=0;i<position-2 && temp->link != NULL;i++){
            temp = temp->link;
        }
        Node* nextNode = temp->link;
        Node* currentNode = new Node();
        currentNode->data = num;
        temp->link = currentNode;
        currentNode->link = nextNode;

    }
}

void deleteAtBeggning(Node*& head){
    if(head == NULL){
        cout << "LINKED LIST IS EMPTY CAN NOT DELETE AN ELEMENT : " << endl;
    }
    head = head->link;
}

void deleteAtTheEnd(Node* head){
    if(head == NULL){
        cout << "LINKED LIST IS EMPTY CAN NOT DELETE AN ELEMENT AT THE END : " << endl;
    }
    if(head->link == NULL){
        cout << "LINKED LIST HAS ONLY ONE ELEMENT SO DON'T DELETE IT : "<< endl;
    }
    Node* temp = head;
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = NULL;
}

int main()
{
    Node* head = NULL;

    head = inserElements(head);

    // inserAtBiggneing(head, 77);
    // insertAtEnd(head,88);
    // insertAtParticularPosition(head,99,2);
    // deleteAtBeggning(head);

    deleteAtTheEnd(head);


    display(head);

    return 0;
}