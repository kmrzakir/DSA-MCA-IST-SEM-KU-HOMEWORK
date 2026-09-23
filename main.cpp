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

void findForAndElement(Node* head,int num){
    while(head != NULL){
        if(head->data == num){
            cout <<"Element "<<num<<" is present is linked list";
            return;
        }
        head = head->link;
    }
    cout << "Element "<< num << " is not present in the linked list";
}

int main()
{
    Node* head = NULL;
    cout << "ENTER THE ELEMENTS TO CREATE THE LINKED LIST : " << endl;
    head = inserElements(head);

    cout << "THR LINKED-LIST IS : ";
    display(head);

    while(true){
        cout << endl << "ENTER THE CHOICE : " << endl;

        cout <<"1 => TO INSERT AN ELEMENT AT THE BIGGNEING : " <<endl;
        cout <<"2 => TO INSERT AN ELEMENT AT THE END : " <<endl;
        cout <<"3 => TO INSERT AN ELEMENT AT ANY PARTICULAR POSITION : " <<endl;
        cout <<"4 => DELETE AN ELEMENT AT THE BIGGNING : " <<endl;
        cout <<"5 => DELETE AN ELEMENT AT THE END : " <<endl;
        cout <<"6 => FIND FOR AN ELEMENT IN A LINKED-LIST : " <<endl;
        cout <<"7 => DISPLAY THE LINKED-LIST : "<<endl;
        cout <<"-1 => ENTER -1 TO QUIT THE PROGRAM : "<<endl;

        int choice;
        cin >>choice;
        int num,position;
        switch (choice)
        {
        case 1:
            cout <<"ENTER AN ELEMENT TO INSERT AT THE BIGGNING OF THE LINKED-LIST : "<<endl;
            cin >>num;
            inserAtBiggneing(head,num);
            cout <<"LINKED-LIST AFTER INSERTING AN ELEMENT AT THE BEGGNING OF THE LINKED-LIST IS : ";
            display(head);
            break;
        case 2:
            cout <<"ENTER AN ELEMENT TO INSERT AT THE END OF THE LINKED-LIST : "<<endl;
            cin >>num;
            insertAtEnd(head,num);
            cout <<"LINKED-LIST AFTER INSERTING AN ELEMENT AT THE END OF THE LINKED-LIST IS : ";
            display(head);
            break;
        case 3:
            cout <<"ENTER AN ELEMENT TO INSERT AT PARTICULAR POSITION OF LINKED-LIST : "<<endl;
            int position;
            cin >>num;
            cout <<"ENTER THE POSITION WHERE YOU WANNA INSERT "<< num << " ELEMENT"<<endl;
            cin >>position;
            insertAtParticularPosition(head,num,position);
            cout <<"LINKED-LIST AFTER INSERTING AN ELEMENT AT A PARTICULAT POSITION OF THE LINKED-LIST IS : ";
            display(head);
            break;
        case 4:
            deleteAtBeggning(head);
            cout <<"LINKED LIST AFTER DELETING AN ELEMENT AT THE BIGGNING : "<<endl;
            display(head);
            break;
        case 5:
            deleteAtTheEnd(head);
            cout <<"LINKED LIST AFTER DELETING AN ELEMENT AT THE END : "<<endl;
            display(head);
            break;
        case 6:
            cout <<"ENTER AN ELEMENT WHICH YOU WANNA FIND IN THE LINKED-LIST : "<<endl;
            cin>>num;
            findForAndElement(head,num);
            break;
        case 7:
            cout <<"THE LINKED LIST IS : " << endl;
            display(head);
        case -1:
            return 0;
        
        default:
            return 0;
        }
    }
    return 0;
}