#include <string>
#include <iostream>
#include <memory>

using namespace std;


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
  private:
    //node is used to store all player data, includes name, race, job 
    //physical, mental, social, and level as data points
    struct Node{
      string name,race,job;
      int level,physical,mental,social;
      Node *next;
      Node *prev;
    };
    Node *head, *tail;
    int size;

  public:
    //constructor and deconstuctor
    LinkedList();
    ~LinkedList();
    //used operators for the class
    bool add(string name);
    void display();
    bool remove(string name);
    //one search/set for each data type
    bool searchString(string stat, string value, bool rec);
    bool searchInt(string stat, int value);
    bool setString(string name, string stat, string value);
    bool setInt(string name, string stat, int value);
    int getSize();
};

#endif