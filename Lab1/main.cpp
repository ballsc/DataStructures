/*
Student Name: Sam Ball
Program Description:
A player character builder with many differnt functions to edit the player characters
*/

#include <iostream>
#include "Tokenizer.h"
#include <fstream>
#include "Linkedlist.h"

using namespace std;

bool processText(istream& is, bool interactive);

int main() {
  processText(cin, true);
}

//function for reading user input
bool processText(istream& is, bool interactive = true)
{
  //declaration of used variables
	string line;
	string command;
	string arg1, arg2, arg3;
	int int1;
	Tokenizer tkn;
  LinkedList pc;
  
	while (true)
	{
		if (!interactive){
			if (is.eof()) return true;
		}
		else { cout << ">> "; }
    
    //reads the user input to a tokenizer class tkn
		getline(is, line);
		tkn.setString(line);

    //using the first word of the user input, tests to see if it is a known command
		tkn.readWord(command);
		if(command == "exit"){
      //if it is exit, deconstructs the linkedlist and exits exits the while loop
      pc.~LinkedList();
			cout << "Exiting ...." << endl;
			return false;
		}
		if(command == "load"){
			// load expects a filename, reads one more word
			if (!tkn.readWord(arg1)) {
				cout << "Missing file name" << endl;
				continue; // skip back to the top of the read loop
			}
      //opens file and recursively calls the function until at eof
			ifstream fin;
			bool status = true;
			fin.open(arg1);
			if (fin.is_open())
			{
				status = processText(fin, false);
			}
			else { cout << "Failed to open the file" << endl; }
			fin.close();
			if (!status) return false;
      continue;
		}
		if(command == "add"){
      //expects a character name, so tries to read another word
      if(!tkn.readWord(arg1)){
        cout << "Failed to read Character Name\n";
        continue;
      }
      //if it reads another word, tests to see if that name is already used
      if(pc.searchString(";)",arg1,true)){
        //if not already used, adds character to the list w base parameters
        pc.add(arg1);
        cout << "PC successfully added!\n";
        continue;
      }
      //else, character is already in the list
      cout << "PC is already in the list\n";
      continue;
		}
    if(command == "display"){
      //tests if list is empty, will not diplsay if nothing is in the list
      if(pc.getSize() == 0){
        cout << "List is empty\n";
        continue;
      }
      //else, displays the lsit
      pc.display();
      continue;
    }
    if(command == "set"){
      //expects name, stat, value
      if(tkn.readWord(arg1)){
        if(tkn.readWord(arg2)){
          if(tkn.readInteger(int1)){
            //checks to see if there is anything in the list
            if(pc.getSize() == 0){
              cout << "List is empty\n";
              continue;
            }
            //if arguments are set, sets
            if(pc.setInt(arg1, arg2, int1)){
              cout << arg1 << "'s stat successfully updated\n";
              continue;
            }
            //else, state possible failure reasons
            cout << "Set failed, either character isn't in list, ";
            cout <<  "is already in the list,";
            cout << " or stat does not exist.\n";
            continue;
          }
          //if the stat is a string instead of a integer
          //run this test
          else if(tkn.readWord(arg3)){
            if(pc.getSize() == 0){
              cout << "List is empty\n";
              continue;
            }
            //if it is a string and list isnt empty, run this function
            if(pc.setString(arg1, arg2, arg3)){
              cout << arg1 << "'s stat successfully updated\n";
              continue;
            }
            //else, state possible failure reasons
            cout << "Set failed, either character isn't in list";
            cout << " or stat does not exist.\n";
            continue;
          }
          //if it fails to read stat value
          else{
            cout << "Failed to read Stat Value\n";
            continue;
          }
        }
        //if it fails to read stat
        else{
          cout << "Failed to read Stat\n";
          continue;
        }
      }
      //if it fails to read character name
      else{
        cout << "Missing Character Name\n";
        continue;
      }
    }
    if(command == "search"){
      //expects a stat and a value
      if(tkn.readWord(arg1)){
        if(tkn.readInteger(int1)){
          if(pc.getSize() == 0){
            cout << "List is empty\n";
            continue;
          }
          //if it gets a stat and value, and list isnt empty, run search int
          cout << "The character(s) with "  << arg1 << " " << int1 << " are ";
          if(pc.searchInt(arg1, int1)){
            cout << endl;
            continue;
          }
          cout << "NONE";
          cout << endl;
          continue;
        }
        else if(tkn.readWord(arg2)){
          if(pc.getSize() == 0){
            cout << "List is empty\n";
            continue;
          }
          //if it gets a word instead of an int, and list isnt empty, run search string
          cout << "The character(s) with "  << arg1 << " " << arg2 << " are ";
          if(pc.searchString(arg1, arg2, false)){
            cout << endl;
            continue;
          }
          cout << "NONE";
          cout << endl;
          continue;
        }
      }
    }
    if(command == "remove"){
      //expects one more argument, name
      if(tkn.readWord(arg1)){
        if(pc.getSize() == 0){
          cout << "List is empty\n";
          continue;
        }
        //if size != 0 and reads name, tries to remove name from list
        if(pc.remove(arg1)){
          cout << arg1 << " successfully removed!\n";
          continue;
        }
        //if it cannot remove, character isnt in the list
        cout << arg1 << " is not in list.\n";
        continue;
      }
    }
    else{
      //if it is an unknown command, output commant and continue
      cout << "Unknown Command " << command << endl;
      continue;
    }
	}
}