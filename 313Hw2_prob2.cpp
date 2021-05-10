#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

void calculate(string op[], int size);

int main(){
    string operation[] = {"-", "+", "25", "30", "/", "*", "20", "50", "5"}; //prefix expression presented within a String array

    calculate(operation, 9);    
 
    return 0;
}

void calculate(string op[], int size){
    stack<int> calc;//stack that will control all the numbers and pop them when necessary.
    int number1;//numbers to be used in every calculation.
    int number2;
    for(int i = size-1; i > -1; i--){
        if (op[i] == "+" || op[i] == "-" || op[i] == "/" || op[i] == "*") {
            number1 = calc.top();
            calc.pop();
            number2 = calc.top();
            calc.pop();
            if(op[i] == "+"){
                calc.push(number1+number2);
            } else if (op[i] == "-"){
                calc.push(number1-number2);
            } else if (op[i] == "/"){
                calc.push(number1/number2);
            } else {
                calc.push(number1*number2);
            }
        } else {
            calc.push(stoi(op[i]));
        }
    }
    cout << "The Result is: " << calc.top() << endl;
}