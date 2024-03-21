#include "library.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <string>

using namespace std;

library::library() {

}
library::~library() {
  moviesList.clear();
  cout << "deallocated list" << endl;
}

void library::read_from_file(const string file_name) {
  ifstream inFile;
  inFile.open(file_name);
  if(!inFile) {
    cout << "This file does not exist, try again" << endl;
  };
  string title;
  string directorName;
  int runtime;
  string format;
  float price;
  int year;
  while(getline(inFile,title)) {
    getline(inFile, directorName);
    inFile >> runtime;
    inFile >> format;
    inFile >> price;
    inFile >> year;
    inFile.ignore(1, '\n');
    insert_sorted(title, directorName, runtime, format, price, year);
  }
  inFile.close();
}

void library::insert_sorted(const string title, const string directorName, const int runtime, const string format, const float price, const int year) {
  movie insert;
  insert.Title = title;
  insert.DirectorName = directorName;
  insert.MovieRuntime = runtime;
  insert.Format = format;
  insert.Price = price;
  insert.Year = year;
  list<movie>::iterator it = moviesList.begin();
  if(it == moviesList.end() || it  -> Title > insert.Title) { //checking the title will come first alphabetically 
    push_front(insert);
  }
  else {
    while(it != moviesList.end() && it  -> Title < insert.Title) { //goes thru the list to find the correct position to insert the movie title alphabetically
      it++;
    }
    moviesList.insert(it, insert);
  }
}

void library::push_front(movie a) {
  moviesList.push_front(a);
}

void library::push_back(movie b) {
  moviesList.push_back(b);
}

void library::director_search(const string directorName) {
  list<movie>::iterator it;
  bool found = false;
  for(it = moviesList.begin(); it != moviesList.end(); it++) {
    if(it -> DirectorName == directorName) {
      cout << "Title: " << it -> Title << endl;
      cout << "Director: " << it -> DirectorName << endl;
      cout << "Format: " << it -> Format << endl;
      cout << "Runtime: " << it -> MovieRuntime << endl;
      cout << "Price: " << it -> Price << endl;
      cout << "Year: " << it -> Year << endl;
      cout << endl;
      found = true;
    }
  }
  if(!found) {
    cout << "No director found by that name, try again" << endl;
  }
}

void library::find_movie(const string title) {
  list<movie>::iterator it;
  bool foundit = false;
  for(it = moviesList.begin(); it != moviesList.end(); it++) {
      size_t found = it -> Title.find(title);
      if(found != string::npos) {
	cout << it -> Title << endl;
	foundit = true;
      }
  }
  if(!foundit) {
    cout << "No movies found with that substring, try again" << endl;
  }
}
  
void library::removed(string title) {
  list<movie>::iterator it;
  bool found = false;
  for(it = moviesList.begin(); it != moviesList.end(); it++) {
    if (it->Title == title) {
      it = moviesList.erase(it);
      cout << "Movie has been successfully deleted" << endl;
      found = true;
    }
  }
  if (!found) {
      cout << "No movie found with that name, try again" << endl;
  }
  
}

void library::write_from_file(const string file_name) {
  ofstream outFile;
  outFile.open(file_name);
  outFile.clear();

  list<movie>::iterator it;
  for(it = moviesList.begin(); it != moviesList.end(); it++) {
    outFile << it -> Title << endl << it -> DirectorName << endl << it -> Format << endl << it -> MovieRuntime << endl << it -> Price << endl << it -> Year << endl; 
  }
  outFile.close();
}

void library::print(){
  list<movie>::iterator it;
  for(it = moviesList.begin(); it != moviesList.end(); it++) {
    cout << it -> Title << endl << it -> DirectorName << endl << it -> Format << endl << it -> MovieRuntime << endl << it -> Price << endl << it -> Year << endl;
  }
}
