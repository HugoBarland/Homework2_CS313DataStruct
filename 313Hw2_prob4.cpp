#include <iostream>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

//Coded by Hugo Barahona
//Creating a node and stack class (using a linked list).
class Node {
public:
    int value;
    Node* next;
    int pos;//the position of the node within the stack.

};
class Stack {
public:
    int count;
    Node* first;
    Node* last;

    Stack() {
        count = 0;
        first = last = nullptr;
    }

    void push(int a) {
        if (count == 0) { // in case nothing has ever been added to the list.
        first = last = new Node;
        last->value = a;
        last->pos = count;
        count++;
        } else {      // in case our list already had something inside.
            Node* resAdded = new Node; //new node to be added (resently added).
            resAdded->next = first;
            first = resAdded;
            first->value = a;
            first->pos = count;
            count++;
        }
    }
    void pop(){
        Node* toBeDeleted = first;//node to be popped.
        first = first->next;
        count--;
        delete toBeDeleted;
    }

    int top(){
        return first->value;
    }

    void changeValAtPos(int position, int changedVal) { //function to change the value of a node that is placed an the specified position
        if (!(position >= count) || position < 0) { //in case the position in the parameters is an invalid position
            Node* cur = first;
            while(position != cur->pos) {
                cur = cur->next;
            }
            cur->value = changedVal;
        } else {
            cout << "invalid position requested" << endl;
        }
    }

    void printList() {//a method that will represent (visually) what's inside of the list.
        Node* current;
        current = first; //creating a node pointer called current, we set it equal to first, and it will help us traverse the list.
        for (int i = 0; i < count; i++) {
            cout << "[" << current->value << "]->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};
//--------------------MAIN STARTS HERE-------------------
int main(){

    Stack stk;

    stk.push(4);
    stk.push(34);
    stk.push(44);
    stk.pop();
    stk.push(54);
    stk.push(999);
    stk.printList();
    stk.changeValAtPos(1, 777);
    stk.printList();
    cout << stk.top() << endl;


}





