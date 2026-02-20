#include <iostream>
#include <string>

using namespace std;

string buildEq(bool nested, string tab);

/*
Name: Sam Ball
Date: 4/2/2022
Description: An equation builder using recursion
*/

int main() {
  cout << "Welcome to the equation builder!" << endl << endl;

  cout << "Instructions: Each step can only have one operation between two numbers."<< endl;
  cout << "So the equation (3 + 4) + 6 would have one 'nested' operation." << endl << endl;

  string equation = buildEq(false, "");

  cout << endl << "The equation you have built is... " << equation << endl;
  cout << endl << "Thanks for coming!" << endl;

  return 0;
}

string buildEq(bool nested, string tab) {
  //initialize variables to be used in the code
  string equation;
  string num1, symb, select;

  //adds a ( if the equation has been called recursively
  if(nested){
    equation += "(";
  }
  //asks the user if they need a nested equation
  cout << tab << "For this step is there nesting? ";
  cin >> select;
  //makes sure the user inputs y or n
  while(select != "y" && select != "n"){
    cout << "\ninvalid input\n\n";
    
    cout << tab << "For this step is there nesting? ";
    cin >> select;
  }
  //if the user needs nesting, it calls the equation again,
  //and adds 1 \t to tab
  if(select == "y"){
    equation += buildEq(true, tab+="\t");
  }
  //if n, the user is asked to input a number
  else{
    cout << tab << "What number would you like? ";
    cin >> num1;

    equation += num1;
  }
  //after the first n, the user is then asked for a symbol
  cout << tab << "What symbol would you like?(+ - / *) ";
  cin >> symb;
  //checks to make sure there is a valid symbol
  while(symb != "+" && symb != "-" && symb != "/" && symb != "*"){
    cout << "\ninvalid input\n\n";

    cout << tab << "What symbol would you like?(+ - / *) ";
    cin >> symb;
  }
  //adds the sumbol to the equation string
  equation += " ";
  equation += symb;
  equation += " ";
  //same code as before, but is focused for the last part of
  //an equation
  cout << tab << "For this step is there nesting? ";
  cin >> select;
  
  while(select != "y" && select != "n"){
    cout << "\ninvalid input\n\n";
    
    cout << tab << "For this step is there nesting? ";
    cin >> select;
  }

  if(select == "y"){
    equation += buildEq(true, tab+="\t");
  }
  else{
    cout << tab << "What number would you like? ";
    cin >> num1;

    equation += num1;
  }
  //adds a ) for each recursively called function
  if(nested){
    equation += ")";
  }
    return equation;
}