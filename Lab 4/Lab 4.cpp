#include "person.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Name: Sam Ball
Date: 3/2/2022
Description: this is a contact building and storing program
*/

vector<Person> contacts;
string file;

void displayContacts(vector<Person> contacts);
void addContacts(vector<Person>& contacts, string file);
void readContacts(vector<Person>& contacts, string file);
void removeContacts(vector<Person>& contacts, string file);

int main() {
  string x;
  ifstream in;
  
  cout << "Welcome to the Contact Manager\n"<< "Enter File to Read From: ";
  cin >> file;
  
  in.open(file);
  while (!in.is_open()) {
    cout << "Enter exact filename.\n"
         << "Enter File Name: ";
    cin >> file;
    in.open(file);
  }
  cout << endl;

  readContacts(contacts, file);
  
  while (x != "0") {
    cout << "Menu:\n0. Exit\n1. Display Contacts\n2. Add Contact\n3. Remove Contact\nWhich would "
            "you like? ";
    cin >> x;
    cout << endl;
    if(x == "0"){
      continue;
    }
    else if(x == "1"){
      if(contacts.size() < 1){
        cout << "No contacts in the file.\n\n";
      }
      else{
        displayContacts(contacts);
      }
    }
    else if(x == "2"){
      addContacts(contacts, file);
    }
    else if(x == "3"){
      if(contacts.size() < 1){
        cout << "No contacts to remove.\n\n";
      }
      else{
        cout << "Here are your contacts:\n";
        displayContacts(contacts);
        removeContacts(contacts, file);
      }
    }
    else{
       cout << "Unknown Input, try again." << endl << endl;
    }
  }
  cout << "Goodbye";
  return 0;
}

void readContacts(vector<Person>& contacts, string file){
  ifstream in;
  in.open(file);
  while(!in.eof()){
    Person read;
    string fn, ln, phone, email;
    in >> fn >> ln >> phone >> email;

    if(fn != " "){
      read.setFirstName(fn);
      read.setLastName(ln);
      read.setPhone(phone);
      read.setEmail(email);
      
      contacts.push_back(read);
    }
    else{
      continue;
    }
  }
  in.close();
  cout << "Contacts read successfully." << endl << endl;
}

void displayContacts(vector<Person> contacts) {
  for (int i = 0; i < contacts.size(); i++) {
    cout << "Contact " << i+1 << ":\nName: " << contacts[i].getFirstName() << " " << contacts[i].getLastName() << "\nPhone Number: " << contacts[i].getPhone() << "\nEmail Address: " << contacts[i].getEmail() << endl << endl;
  }
  return;
}

void addContacts(vector<Person>& contacts, string file) {
  ofstream write;
  Person out;
  string fn, ln, phone, email;
  
  cout << "Let's do this" << endl << "Name(first and last)? ";
  cin >> fn >> ln;
  cout << "Phone Number(no spaces)? ";
  cin >> phone;
  cout << "Email? ";
  cin >> email;
  cout << "Contact successfully added." << endl << endl;

  Person add;
  add.setFirstName(fn);
  add.setLastName(ln);
  add.setPhone(phone);
  add.setEmail(email);
  contacts.push_back(add);
  
  write.open(file, ios_base::app);
  write << endl << fn << " " << ln << " " << phone << " " << email;
  write.close();
  return;
}

void removeContacts(vector<Person>& contacts, string file){
  int remove;

  cout << "Which contact would you like to remove: ";
  cin >> remove;
  contacts.erase(contacts.begin()+(remove-1));

  ofstream write;
  write.open(file);
  for(int i = 0; i < contacts.size(); i++){
    write << endl << contacts[i].getFirstName() << " " << contacts[i].getLastName() << " " << contacts[i].getPhone() << " " << contacts[i].getEmail();
  }
  write.close();
    
  cout << "Contact successfully removed.\n" << endl;
  
  return;
}