#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include<fstream>
#include<vector>


using namespace std;

// Function to reverse a string where the parameter is a string reference.
void reverseByWord(string& str) {
    stack<char> stkToReverse;
    string wordToReverse;//string that will be used to reverse each word.
    string reversedPhrase = "";//string that will contain the final result.
    for (int i = 0; i < str.size(); i++) {
        wordToReverse = "";
        while(i <= str.size() && str[i] != ' ' && str[i] != ',' && str[i] != '.'){
           wordToReverse += str[i];
           i++;
        }
        for (int e = 0; e < wordToReverse.size(); e++){
            stkToReverse.push(wordToReverse[e]);
        }
        for (int e = 0; e < wordToReverse.size(); e++){
            reversedPhrase += stkToReverse.top();
            stkToReverse.pop();
        }
        if (i != str.size()-1){
            if (str[i] == ','){
                reversedPhrase+= ",";
            }
            if (str[i] == '.'){
                reversedPhrase+= ".";
            }
            reversedPhrase+= " ";
        }

    }
    str = reversedPhrase;
}

int main(){
    ifstream file("chuckNorrisJokes.txt");
    string input;

    while(file) {
        getline(file, input);
        cout << input << endl;
        reverseByWord(input);
        cout << input << endl;
    }

}
