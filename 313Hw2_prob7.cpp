#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

class Node {
public:
    Node* right;
    Node* left; 
    Node* up;
    Node* down;
    string name;


    Node(){
        right = left = up = down = nullptr;
        name = "end";
    }

    void path(int r, int l, int u, int d, string n){ //r, l, u and d represent right, left, up and down respectively. if their value is 1, a path will be created in that node.
        name = n;
        if(r == 1){
            right = new Node;
            right->left = this;
        }
        if(l == 1){
            left = new Node;
            left->right = this;
        }
        if(u == 1){
            up = new Node;
            up->down = this;
        }
        if(d == 1){
            down = new Node;
            down->up = this;
        }
    }

    
};
void solveMaze(Node& myMaze);
int main(){
    Node maze;
    Node* last;
    //BUILDING THE MAZE
    //building first row
    maze.path(1,0,0,0,"path");
    last = maze.right;
    for(int i = 0; i < 3; i++){
        last->path(1,0,0,0,"path");
        last = last->right;
    }
    //building second row
    Node* last2;
    last2 = last->left->down = new Node;
    last2->up = last->left;
    last2->name = "path";
    for(int i = 0; i < 3; i++){
        last2->path(0,1,0,0,"path");
        last2 = last2->left;
    }
    //building upper right, middle and left of the maze
    last->left->down->left->path(0,0,0,1,"path");
    last->left->down->left->down->path(0,1,0,0,"path");
    Node* last3 = last->left->down->left->down->left;
    for(int i = 0; i < 2; i++){
        last->path(0,0,0,1,"path");
        last = last->down;
    }
    last->path(0,1,0,0,"path");
        last = last->left;
    for(int i = 0; i < 3; i++){
        last2->path(0,0,0,1,"path");
        last2 = last2->down;
    }
    //building the last 2 rows
    last2->path(1,0,0,0,"path");
    last2 = last2->right;
    last2->path(1,0,1,0,"path");
    last2->right->path(1,0,0,0,"path");
    last2 = last2->up;
    for(int i = 0; i < 3; i++){
        last2->path(1,0,0,0,"path");
        last2 = last2->right;
    }
    last2->path(0,0,0,1,"path");
    last2 = last2->down;
    last2->path(1,0,0,0,"path");
    last2 = last2->right;
    last2->name = "exit";
    //MAZE CONSTRUCTION FINISHED



    cout << last2->name << endl;
    cout << last2->left->up->left->left->left->down->left->up->up->up->right->right->down->left->name << endl;

    solveMaze(maze);


    return 0;
}


void solveMaze(Node& myMaze){
    bool exitFound = 0;
    Node* trav = myMaze.right; //node pointer to help traverse the maze.
    stack<string> stkDirection; // stack to record the direction taken within the maze.
    string comingFrom = "left";// name of the direction the node trav comes from.
    bool noPathFound = 0;// boolean to determine whether I reach a deadend.

    
    while(!exitFound){

        if (comingFrom == "left"){
            if(trav->up != nullptr){
                trav = trav->up;
                stkDirection.push("up");
                comingFrom = "down";
            } else if(trav->right != nullptr){
                trav = trav->right;
                stkDirection.push("right");
                comingFrom = "left";
            } else if(trav->down != nullptr){
                trav = trav->down;
                stkDirection.push("down");
                comingFrom = "up";
            } else {
                noPathFound = 1;
            }
        } else if (comingFrom == "up"){
            if(trav->right != nullptr){
                trav = trav->right;
                stkDirection.push("right");
                comingFrom = "left";
            } else if(trav->down != nullptr){                
                trav = trav->down;
                stkDirection.push("down");
                comingFrom = "up";
            } else if(trav->left != nullptr){
                trav = trav->left;
                stkDirection.push("left");
                comingFrom = "right";
            } else {
                noPathFound = 1;
            }
        } else if (comingFrom == "right"){
            if(trav->down != nullptr){
                trav = trav->down;
                stkDirection.push("down");
                comingFrom = "up";
            } else if(trav->left != nullptr){
                trav = trav->left;
                stkDirection.push("left");
                comingFrom = "right";
            } else if(trav->up != nullptr){
                trav = trav->up;
                stkDirection.push("up");
                comingFrom = "down";
            } else {
                noPathFound = 1;
            }
        } else if (comingFrom == "down"){
            if(trav->left != nullptr){
                trav = trav->left;
                stkDirection.push("left");
                comingFrom = "right";
            } else if(trav->up != nullptr){
                trav = trav->up;
                stkDirection.push("up");
                comingFrom = "down";
            } else if(trav->right != nullptr){
                trav = trav->right;
                stkDirection.push("right");
                comingFrom = "left";
            } else {
                noPathFound = 1;
            }
        } 
        if (noPathFound) {
            if (stkDirection.top() == "left"){
                trav = trav->right;
                stkDirection.pop();
                comingFrom = "left";
            } else if (stkDirection.top() == "up") {
                trav = trav->down;
                stkDirection.pop();
                comingFrom = "up";
            } else if (stkDirection.top() == "right") {
                trav = trav->left;
                stkDirection.pop();
                comingFrom = "right";
            } else if (stkDirection.top() == "down") {
                trav = trav->up;
                stkDirection.pop();
                comingFrom = "down";
            }
            noPathFound = 0;
        }
        if (trav->name == "exit") {
            exitFound=1;
        }
        stack<string> printableStk;
        for (stack<string> copyStk = stkDirection; !copyStk.empty(); copyStk.pop()) {
            printableStk.push(copyStk.top());
        }
        while(!printableStk.empty()) {
            cout << printableStk.top() << "->";
            printableStk.pop();
        }
        cout << "" << endl;
    }


    cout << "maze solved" << endl;
}

