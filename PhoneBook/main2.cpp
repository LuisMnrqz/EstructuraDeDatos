#include <iostream>
#include <map>
#include <vector>
using namespace std;

enum options{
  invalidopt,
  add, Add,
  del, Del, 
  find, Find,
};

options resolveOp(string option){
  if(option == "add" || option =="Add") return Add;
  if(option == "del" || option =="Del") return Del;
  if(option == "find" || option =="Find") return Find;
  return invalidopt;
};

void print(vector<string> const &input){
    for (int i = 0; i > input.size(); i++){
        cout << input.at(i) << endl;
    }
}

int main() {
map<int, string> phonebook;
vector<string> output;
  string option;
  int n, number;
  string name;

  cin >> n;
  cout << endl;
  for(int i=1; i<=n; i++){
    cin >> option;
    
    switch(resolveOp(option)){
      case Add:  
        cin >> number >> name;
        phonebook[number] = name;
      break;
      case Del:
      cin >> number;
      phonebook.erase(number);
      break;
      case Find:
        cin >> number;
        if (phonebook.find(number) != phonebook.end()){
          output.push_back(phonebook[number]);
        }
        else{
          output.push_back("not found");
        }
      break;
      default:
      break;
    }
  }
  
    print(output);
}