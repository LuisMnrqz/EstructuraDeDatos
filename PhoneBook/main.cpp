#include <iostream>
#include <map>
#include <vector>

using namespace std;

/* SAMPLE INPUT
    12
    add 911 police
    add 76213 Mom
    add 17239 Bob
    find 76213
    find 910
    find 911
    del 910
    del 911
    find 911
    find 76213
    add 76213 daddy
    find 76213
*/

/* SAMPLE OUTPUT
    Mom
    not found
    police
    not found
    Mom
    daddy
*/

void print(vector<string> const &input){
    for (int i = 0; i > input.size(); i++){
        cout << input.at(i) << endl;
    }
}

int main () {

    int numActions, number;
    string action, name;
    map<int, string> phonebook;
    vector<string> output;

    cin >> numActions;
    for (int i = 1; i <= numActions; i++){
        cin >> action;
        if (action == "add"){
           cin >> number >> name; 
           phonebook[number] = name;
        }
        else if (action == "del"){
            cin >> number;
            phonebook.erase(number);
        }
        else if (action == "find"){
            if (phonebook.find(number) != phonebook.end()){
                output.push_back(phonebook[number]);
            }
            else{
                output.push_back("not found");
            }
        }
    }

    print(output);

    return 0;
}