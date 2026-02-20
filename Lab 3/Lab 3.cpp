#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
  Sam Ball
  2/19/22
  This is a scedule building program
*/
    
vector<string> courseCodes, courseNames;

void viewSchedule();
int addClass();
int removeClass(vector<string>& courseCodes, vector<string>& courseNames);

int main() {
  int x;
  
  while (x != 0) {
    cout << "Menu\n1. View Schedule\n2. Add Class\n3. Remove Class\n0. "
            "Exit\nWhich Option would you like? ";
    cin >> x;
    cout << endl;

    switch(x){
      case 0:
        continue;
      case 1:
        if(courseCodes.size() < 1){
          cout << "You have to add classes first." << endl;
        }
        else{
          viewSchedule();
        }
        break;
      case 2:
        addClass();
        break;
      case 3:
        if(courseCodes.size() < 1){
          cout << "You have to add classes first." << endl;
        }
        else{
          viewSchedule();
          cout << endl;
          removeClass(courseCodes, courseNames);
        }
        break;
      default:
        cout << "Unknown Input" << endl;
    }
    cout << endl;
  }
  cout << "Goodbye";
  return 0;
}

void viewSchedule() {
  for (int i = 0; i < courseNames.size(); i++) {
      cout << i + 1 << ". " <<courseNames.at(i) << " " << courseCodes.at(i) << endl;
  }
}

int addClass() {
  string code;
  int codes;
  string name;
  
  cout << "What class code would you like to add? (4 characters) ";
  cin >> code;
  vector<char> test(code.length());
  cout << endl;
  
  if (test.size()==4){
    courseCodes.push_back(code);
    cout << "What is the course name? ";
    cin.ignore();
    getline(cin, name);
    courseNames.push_back(name);
    cout << endl << "Course Added!" << endl;
    return 1;
  }
    
  else{
    cout << "Error Adding Class. Try again." << endl;
    return 0;
  }
  
}

int removeClass(vector<string>& courseCodes, vector<string>& courseNames) {
  int remove;
  vector<int> ahh;
  vector<int> ahhh;
  
  cout << "Which class would you like to remove? ";
  cin >> remove;
  if(remove < 1 || remove > courseCodes.size()){
    cout << "Error Removing Course" << endl;
    return 0;
  }
  else{
    courseCodes.erase(courseCodes.begin()+remove-1);
    courseNames.erase(courseNames.begin()+remove-1);
    cout << endl << "Course Successfully Removed" << endl;
    return 1;
  }
}