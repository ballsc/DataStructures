#include "Linkedlist.h"

//definition of base constructor
LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}
//definition of deconstructor
LinkedList::~LinkedList(){
  Node *temp = head;
  while(temp != nullptr){
    head = head->next;
    delete temp;
    temp = head;
    size--;
  }
  tail = nullptr;
}
//definition of getSize
int LinkedList::getSize(){
  //returns the size of the list
  int larg = size;
  return larg;
}
//definition of add
bool LinkedList::add(string name){
  //makes a new node and adds all the base data points to it.
  Node *temp = new Node;
  temp->name = name;
  temp->level = 1;
  temp->mental = 1;
  temp->social = 1;
  temp->physical = 1;
  temp->job = "Villager";
  temp->race = "PC";
  temp->next = nullptr;
  temp->prev = nullptr;
  size++;
  //if the list is empty 
  if(head == nullptr){
    head = temp;
    head->prev = nullptr;
    head->next = nullptr;
    tail = head;
  }
  //if the list only has one value
  if(head->next == nullptr){
    //checks for where to set the name alphabetically
    //if it is before the head
    if(head->name > temp->name){
      head->prev = temp;
      tail = head;
      head = temp;
      head->next = tail;
      tail->next = nullptr;
      return true;
    }
    //if it is after the head
    head->next = temp;
    tail = temp;
    tail->next = nullptr;
    tail->prev = head;
    return true;
  }
  //if it has more than 1 character in the list
  else{
    //if it is before the head alphabetically
    if(head->name > temp->name){
      head->prev = temp;
      temp->next = head;
      head = temp;
      head->prev = nullptr;
      return true;
    }
    //else
    Node *temp1 = head;
    int count = 0;
    //run while in not at the last character in the list
    while(count != size-1){
      //test current character against name
      if(temp1->name > temp->name){
        //if current character name is greater than name, put name between
        //current and next character
        temp1->prev->next=temp;
        temp->prev = temp1->prev;
        temp->next = temp1;
        temp1->prev = temp;
        return true;
      }
      temp1 = temp1->next;
      count ++;
      }
    //if it gets all the way through the list, add name to tail.
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    tail->next = nullptr;
    return true;
    }
  }
//definition of display
void LinkedList::display(){
  //set node to head
  Node *temp = head;
  //loop through list while temp isnt nullptr
  while(temp != nullptr){
    //output each datapoint related to each character in the list
    cout << temp->name << ": LVL " << temp->level << ", PHY " << temp->physical << ", MEN " << temp->mental << ", SOC " << temp->social << ", " << temp->job << ", " << temp->race << endl;
    temp = temp->next;
  }
}
//definition of setInt
bool LinkedList::setInt(string name, string stat, int value){
  //sets a node to the head of the list
  Node *temp = head;
  int count = 0;
  //loops through the list while its not at the end of the list
  while(count != size){
    //tests the current name against the name the user is trying to edit
    if(temp->name == name){
      //if it finds the name, tests for what stat they are trying to change
      //and if it finds the stat, it updates the stat
      if(stat == "level"){
        temp->level = value;
      }
        
      else if(stat == "physical"){
        temp->physical = value;
      }
        
      else if(stat == "mental"){
        temp->mental = value;
      }
        
      else if(stat == "social"){
        temp->social = value;
      }
      //if it doesnt find the stat, return false
      else{
        return false;
      }
      return true;
    }
    temp = temp->next;
    count ++;
  }
  //if it doesnt find the name return false
  return false;
}
//definition of setString
bool LinkedList::setString(string name, string stat, string value){
  //sets a node to the head of the list
  Node *temp = head;
  int count = 0;
  //loops through the list while its not at the end of the list
  while(count != size){
    //tests the current name against the name the user is trying to edit
    if(temp->name == name){
      //if it finds the name, tests for what stat they are trying to change
      //and if it finds the stat, it updates the stat
      if(stat == "race"){
        temp->race = value;
      }
      else if(stat == "job"){
        temp->job = value;
      }
      //if it doesnt find the stat
      else{
        return false;
      }
      return true;
    }
    temp = temp->next;
    count ++;
  }
  //if it doesnt find the name, return false
  return false;
}
//definition searchString 
bool LinkedList::searchString(string stat, string value, bool rec){
  //function for seeing if a name is already in the list
  //only accessible if called with true
  if(rec){
    Node *temp = head;
    
    while(temp != nullptr){
      if(temp->name == value){
        return false;
      }
      temp = temp->next;
    }
    //returns true if name isnt in the list
    return true;
  }
  //sets a node to the head of the list
  Node *temp = head;
  //tests if the stat exists
  //if it finds the stat, outputs the name of the character with the stat value
  if(stat == "name"){
    while(temp != nullptr){
      if(temp->name == value){
        cout << temp->name << "  ";
      }
      temp = temp->next;
    }
  }
    
  else if(stat == "job"){
    while(temp != nullptr){
      if(temp->job == value){
        cout << temp->name << "  ";
      }
      temp = temp->next;
    }
  }
    
  else if(stat == "race"){
    while(temp != nullptr){
      if(temp->race == value){
        cout << temp->name << "  ";
      }
      temp = temp->next;
    }
  }
  //if it cant find the stat return false
  else{
    return false;
  }
  return true;;
}
//definition searchInt
bool LinkedList::searchInt(string stat, int value){
  //sets a node to the head of the list
  Node *temp = head;
  //tests if the stat exists
  //if it finds the stat, outputs the name of the character with the stat value
  if(stat == "level"){
    while(temp != nullptr){
      if(temp->level == value){
        cout << temp->name << "  ";
      }
      temp = temp->next;
    }
  }
    
  else if(stat == "physical"){
    while(temp != nullptr){
      if(temp->physical == value){
        cout << temp->name << "  ";
      }
      temp = temp->next;
    }
  }
    
  else if(stat == "mental"){
    while(temp != nullptr){
      if(temp->mental == value){
        cout << temp->name << "  ";
      }
      temp = temp->next;
    }
  }
    
  else if(stat == "social"){
    while(temp != nullptr){
      if(temp->social == value){
        cout << temp->name << "  ";
      }
      temp = temp->next;
    }
  }
  //if it cant find the stat, return false
  else{
    return false;
  }
  return true;
}
//definition of remove
bool LinkedList::remove(string name){
  //if there is only one item in the list
  if(head->next == nullptr){
    if(head->name == name){
      size--;
      delete head;
      head = nullptr;
      tail = nullptr;
      return true;
    }
    return false;
  }
  //sets a node to the head of the list
  Node *temp = head;
  
  int count = 0;
  //loops through the list
  while(count != size-1){
    //if it finds the character the user wants to remove
    if(temp->name == name){
      //if the name is the head
      if(temp == head){
        //move the head to head->next and delete the head
        head = head->next;
        head->next = temp->next->next;
        delete temp;
        head->prev = nullptr;
        size--;
        return true;
      }
      //if the name isnt the head
      //connect the previous and the next, and then delete the character
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
      delete temp;
      size--;
      return true;
    }
    temp = temp->next;
    count++;
  }
  //if it reaches the end, test if name is the name at tail
  // and if it is, removes tail
  if(temp == tail){
    if(temp->name == name){
      tail = temp->prev;
      tail->prev = temp->prev->prev;
      temp->prev->prev->next = tail;
      delete temp;
      tail->next = nullptr;
      size--;
      return true;
    }
  }
  return false;
}