/***************************

  I used a selection sorter based off the following website
  https://www.programiz.com/dsa/selection-sort

 ***************************/

/*
Name: Sam Ball
Date: 4/15/2022
Description: This program is a playlist sorter, shuffler, and searcher.
*/

#include "time.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "song.h"

using namespace std;

// given to you
void processFile(vector<Song> &playlist);

// you should create
void shuffle(vector<Song> &playlist);
int binarySearch(vector<Song> &playlist, string title);
void displayPlaylist(vector<Song> &playlist);
int nbinarySearch(vector<Song> &playlist, string artist);

// add your own sort function
void sort(vector<Song> &playlist);
void nsort(vector<Song> &playlist);

int main() {
  vector<Song> playlist;

  // sets up playlist
  processFile(playlist);

  //displays initial playlist
  cout << "\nInitial playlist: " << endl;
  displayPlaylist(playlist);

  cout << endl << "Welcome to the playlist display manager." << endl;

  //opens and loops a menu until user exits
  string x;
  while (x != "0") {
    cout << "\n0. EXIT\n1. Sort Playlist by Title\n2. Shuffle Playlist\n3. Search by Title\n4. Sort Playlist by Artist\n5. Search by Artist\nWhich option would you like? ";
    cin >> x;
    if (x == "0") {
      //closes the program
      continue;
    } 
      
    else if (x == "1") {
      cout << endl << "Alphabetically Sorted Playlist by Title:" << endl;
      //sorts the playlist by title
      sort(playlist);
      //displays the sorted playlist
      displayPlaylist(playlist);
    } 
      
    else if (x == "2") {
      //shuffles the playlist
      shuffle(playlist);
      //displays the newly shuffled playlist
      displayPlaylist(playlist);
    } 
      
    else if (x == "3") {
      string title;
      //prompts user for song title
      cout << "\nWhat is the Song Title? ";
      cin.ignore();
      getline(cin, title);
      //runs a search with the inputed title
      binarySearch(playlist, title);
    } 
    else if (x == "4") {
      cout << endl << "Alphabetically Sorted Playlist by Artist:" << endl;
      //sorts the playlist by artist
      nsort(playlist);
      //displays the current playlist
      displayPlaylist(playlist);
    }
    else if (x == "5"){
      string artist;
      //prompts user for an artist
      cout << "\nWhat is the Artist? ";
      cin.ignore();
      getline(cin, artist);
      //runs a search with the inputed artist
      nbinarySearch(playlist, artist);
    }
      
    else {
      //makes sure the user inputs a known input
      cout << "\nUnknow input\n";
    }
  }
  return 0;
}

void processFile(vector<Song> &playlist) {
  ifstream infile;
  string line;

  infile.open("songs.txt");

  if (infile.is_open()) {
    cout << "Successful songs opening." << endl;
  }

  else {
    cout << "Couldn't locate file. Program closing." << endl;
    exit(EXIT_FAILURE);
  }

  while (getline(infile, line)) {
    // first line --> song
    // second line --> artist

    if (line != "") {
      string song, artist;

      song = line;

      getline(infile, artist);

      Song temp(song, artist);

      playlist.push_back(temp);
    }
  }

  return;
}

void displayPlaylist(vector<Song> &playlist) {
  //loops through the playlist to display each song and artist
  for (int i = 0; i < playlist.size(); i++) {
    cout << playlist[i].getTitle() << " - " << playlist[i].getArtist() << endl;
  }
}

int binarySearch(vector<Song> &playlist, string title) {
  //loops through the playlist vector
  for (int i = 0; i < playlist.size(); i++) {
    string titletest = playlist[i].getTitle();
    //tests to see if each title in playlist is the same as the user inputed title
    if (title == titletest) {
      //if it's there, tells the user where in the playlist
      cout << title << " is number " << i+1 << " in your current playlist.\n";
      return i;
    } 
    else {
      continue;
    }
  }
  //if it is not it the playlist, displays Not in Playlist
  cout << "\nNot in Playlist.\n";
  return -1;
}

void sort(vector<Song> &playlist) {
  for (int i = 0; i < playlist.size() - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < playlist.size(); j++) {

      // Select the minimum title in each loop.
      string title1 = playlist[j].getTitle();
      string title2 = playlist[min_idx].getTitle();
      if ((title1) < (title2))
        min_idx = j;
    }
    // put min at the correct position
    string title1 = playlist[i].getTitle();
    string artist1 = playlist[i].getArtist();
    string title2 = playlist[min_idx].getTitle();
    string artist2 = playlist[min_idx].getArtist();

    playlist[i].setTitle(title2);
    playlist[i].setArtist(artist2);

    playlist[min_idx].setTitle(title1);
    playlist[min_idx].setArtist(artist1);
  }
}

void shuffle(vector<Song> &playlist) {
  cout << endl << "Shuffled Playlist:" << endl;
  //seeds a random number generator
  srand(time(NULL));

  for (int i = 0; i < playlist.size(); i++) {
    //sets random1 equal to a random number within the playlist's size
    int random1 = rand() % playlist.size();
    for (int j = 0; j < playlist.size(); j++) {
      //sets a differennt random2 equal to a different random number within the playlist's size
      int random2 = rand() % playlist.size();

      //switches the position of the two random selected songs and artists
      string title1 = playlist[random1].getTitle();
      string artist1 = playlist[random1].getArtist();
      string title2 = playlist[random2].getTitle();
      string artist2 = playlist[random2].getArtist();

      playlist[random1].setTitle(title2);
      playlist[random1].setArtist(artist2);

      playlist[random2].setTitle(title1);
      playlist[random2].setArtist(artist1);
    }
  }
}

int nbinarySearch(vector<Song> &playlist, string artist) {
  bool x;
  int y;
  vector<int> place;
  
  for (int i = 0; i < playlist.size(); i++) {
    string artisttest = playlist[i].getArtist();
    //runs through the playlist and tests if the selected artist is in the playlist
    if (artist == artisttest) {
      // if they are, adds one to y, or the amount of songs, sets the x, or is this artist in the playlist, to true, and adds the place number in the playlist to a place vector.
      x = true;
      place.push_back(i);
    } 
    else {
      continue;
    }
  }
  //checks to see if x, is it in playlist, is true
  if (x){
    //checks to see if there is only one song in the playlist
    if(y == 1){
      //if one, uses this cout statement
      cout << artist << " has one song on your playlist: " << playlist[place[0]].getTitle() << endl;
      return 1;
    }
    //if there are more than one songs from that artist in the playlist, program runs this long cout statment
    cout << artist << " has " << place.size() << " songs on your playlist: ";
    //this is part of the cout
    for(int i = 0; i < place.size()-1; i++){
      cout << playlist[place[i]].getTitle() << ", ";
    }
    //so is this
    cout << "and " << playlist[place[place.size()-1]].getTitle() << endl;
    return 2;
  }
  //if it's not in the playlist, states not in playlist
  cout << "\nNot in Playlist.\n";
  return -1;
}

void nsort(vector<Song> &playlist) {
  for (int i = 0; i < playlist.size() - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < playlist.size(); j++) {

      // Select the "minimum" artist in each loop.
      string artist1 = playlist[j].getArtist();
      string artist2 = playlist[min_idx].getArtist();
      if ((artist1) < (artist2))
        min_idx = j;
    }
    // put min at the correct position
    string title1 = playlist[i].getTitle();
    string artist1 = playlist[i].getArtist();
    string title2 = playlist[min_idx].getTitle();
    string artist2 = playlist[min_idx].getArtist();

    playlist[i].setTitle(title2);
    playlist[i].setArtist(artist2);

    playlist[min_idx].setTitle(title1);
    playlist[min_idx].setArtist(artist1);
  }
}