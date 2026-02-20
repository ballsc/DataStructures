#include "linkedlist.h"

// GIVEN TO STUDENTS

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    if(head != nullptr)
    {
        Node *temp;

        while(head != nullptr)
        {
            temp = head->next;

            // deletes head
            delete head;

            // goes to next element
            head = temp;
        }
    }
}

void LinkedList::display()
{
    Node *temp = head;

    for(int i = 0; i < size; i++)
    {
        cout << temp->data << "\t";

        temp = temp->next;
    }

    cout << endl;
}

void LinkedList::append(int num)
{
    // list is empty
    if(head == nullptr)
    {
        head = new Node;

        head->data = num;
        head->next = nullptr;

        // sets tail to head
        tail = head;
    }

    else
    {
        // creates new node
        Node *temp = new Node;

        // sets new node data
        temp->data = num;
        temp->next = nullptr;

        // sets previous tail link to new node
        tail->next = temp;

        // sets this node to new tail
        tail = temp;
    }

    // increments size
    size++;
}

void LinkedList::pop()
{
    if(size > 1)
    {
        Node *temp = head;

        // loops to node before tail
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        // deletes tail
        delete tail;

        // sets new tail
        tail = temp;
        tail->next = nullptr;
    }

    // if there's only one item
    else if(size == 1)
    {
        Node *temp = tail;

        // head and tail are now null
        head = nullptr;
        tail = nullptr;

        // deletes node
        delete temp;
    }

    size--;
}

// END GIVEN TO STUDENTS

/*
Name: Sam Ball                       NetID: scb548
Date: 4/24/22                  Due Date: 4/24/22
Description: a linked list with many included functions
*/

int LinkedList::min(){
  Node *temp = head;
  int num = head->data;
  //goes through the whole list and sets num equal to the smallest number
  while(temp != nullptr){
    if(temp->data < num){
      num = temp->data;
      temp = temp->next;
    }
    else{
      temp = temp->next;
    }
  }
  return num;
}

int LinkedList::max(){
  Node *temp = head;
  int num = head->data;
  //goes through the whole list and sets num equal to the largeest number
  while(temp != nullptr){
    if(temp->data > num){
      num = temp->data;
      temp = temp->next;
    }
    else{
      temp = temp->next;
    }
  }
  return num;
}

int LinkedList::mean(){
  Node *temp = head;
  int num = head->data;
  //goes through the whole list and adds it to num
  while(temp != nullptr){
    num += temp->data;
    temp = temp->next;
  }
  //returns num divided by size to give mean
  return num/size;
}

int LinkedList::linearSearch(int key){
  Node *temp = head;
  int location = 0;
  //goes through the whole list and compares each part to given "key"
  while(temp != nullptr){
    if(temp->data == key){
      //if it finds key, it returns the location in the list
      return location;
    }
    else{
      //while it hasnt reached the number, adds one to the location
      location += 1;
      temp = temp->next;
    }
  }
  //if n
  return -1;
}

void LinkedList::sort(){
//creates two for loops with node variables
  for(Node *i = head ; i != nullptr; i = i->next){
    for(Node *j = head; j->next !=nullptr; j=j->next){
      //checks if the following node has a larger number
        if(j->data > j->next->data){
          //if there is a larger number, swaps the pointers. 
          int temp = j->data;
          j->data = j->next->data;
          j->next->data = temp;
           }
       }
   }
}

void LinkedList::reverse(){
//creates two for loops with node variables
  for(Node *i = head ; i != nullptr; i = i->next){
    for(Node *j = head; j->next !=nullptr; j=j->next){
      //checks if the following node has a smaller number
        if(j->data < j->next->data){
          //if there is a smalelr number, swaps the pointers. 
          int temp = j->data;
          j->data = j->next->data;
          j->next->data = temp;
           }
       }
   }
}

void LinkedList::insert(int num, int pos){
  //creates a new node with the data from the user.
  Node *temp = new Node;
  temp->data = num;
  temp->next = nullptr;
//increases the size of the list
  size += 1;

  //if its at the start
  if(pos == 0){
    //sets the node after head to point to head
    temp->next = head;
    //makes the new head temp
    head = temp;
  }
    //if its at the end
  else if(pos == (size+1)){
    //makes the data after tail temp
    tail->next = temp;
    //sets the new tail to temp
    tail = temp;
    //makes the place after the tail point to nullptr
    tail->next = nullptr;
  }
  //if its somewhere random
  else{
    //creates a node pointing to the nead
    Node *temp2 = head;
    //creates a variables to run against the position
    int cap = 0;
    //runs through the list until its the number right before the position
    while(cap < (pos-1)){
      temp2 = temp2->next;
      cap += 1;
    }
    //creates a new node set to the pos number
    Node *temp3 = temp2->next;
    //makes the pos number set to temp 
    temp2->next = temp;
    temp2 = temp;
    //makes the list connected by pointing the new data to the next node
    temp->next = temp3;
  }
}

void LinkedList::remove(int pos){
  //decreases the size
  size -= 1;

  //if removing at the beginning
  if(pos == 0){
    //makes a node set to the point after head
    Node *temp = head->next;
    //removes the head node
    delete head;
    //makes temp the new head
    head = temp;
  }
  //if its deleting from the end basically just run pop
  else if(pos == (size+1)){
    Node *temp = head;
    while(temp->next != nullptr){
      temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
  }
  //if its at a random spot
  else{
    //set a node to the head and run through the list until youre at the node before the removed one
    Node *temp = head;
    int cap = 0;
    while(cap < (pos - 1)){
      temp = temp->next;
      cap += 1;
    }
    //make temp2 the node you are deleting
    Node *temp2 = temp->next;
    //make temp three the node after the deleted node
    Node *temp3 = temp2->next;
    //delete the middle node
    delete temp2;
    //connect the list
    temp->next = temp3;
  }
}