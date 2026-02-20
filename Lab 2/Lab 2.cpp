#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    cout << "Welcome to quiz grade averaging!" << endl << endl;

    ifstream infile;

    string f;
    vector<double> grades;

    cout << "Input Filename: ";
    cin >> f;
    infile.open(f);
    while (!infile.is_open()){
      cout << "File does not exist." << endl;
      cout << "Input Filename: ";
      cin >> f;
      infile.open(f);
    }

    int g;
    while(infile >> g){
      grades.push_back(g);
    }

    // menuing
    infile.close();
    
  
    
    while(1)
    {
        string option; 
        double g1 = 0, gn, gs = grades.size(), ga;

        // displays menu
        cout << "Menu: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Display average" << endl;
        cout << "2. Display grades" << endl;
        cout << "3. Add new grade" << endl;
        cout << "Enter choice: ";
        cin >> option;

        cout << endl;

        for(int i = 0; i < gs; i++){
          g1 = grades[i]+g1;
        }
        ga = g1/gs;
        // exit
        if(option == "0")
        {
          if(ga >= 90 &&  ga <= 100){
            cout << "With an Average of " << ga << " you would have an A.";
          }
          else if(ga >= 80){
            cout << "With an Average of " << ga << " you would have an B.";
          }
          else if(ga >= 70){
            cout << "With an Average of " << ga << " you would have an C.";
          }
          else if(ga >= 60){
            cout << "With an Average of " << ga << " you would have an D.";
          }
          else{
            cout << "With an Average of " << ga << " you would have an F.";
          }
          break;
        }

        else if(option == "1"){
          cout << "Your average is " << ga << "." << endl;
        }

        else if(option == "2"){
          cout << "The grades are ";
          for(int i = 0; i < gs-1; i++){
            cout << grades[i] << ", ";
          }
          cout << grades[gs-1] << "." << endl;
        }

        else if(option == "3"){
          cout << "Enter the new grade(0.0-100.0): ";
          cin >> gn;
          cout << endl;
          while(gn < 0.0 || gn > 100.0){
            cout << "Invalid input." << endl;
            cout << "Enter the new grade: ";
            cin >> gn;
            cout << endl;
          }
          grades.push_back(gn);
          cout << "Grade added successfully." << endl;
        }

        else{
          cout << "Invalid input." << endl;
        }
        cout << endl;
    }

    cout << endl << "Good-bye!" << endl;

    return 0;
}
