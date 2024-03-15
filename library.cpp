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
    cout << "There was an error opening the file, try again" << endl;
  }
  string Title;
  string DirectorName;
  int Runtime;
  string Format;
  float Price;
  int Year;
  getline(inFile, Title);
  while(inFile) {
    getline(inFile, DirectorName);
    inFile >> Runtime;
    inFile >> Format;
    inFile >> Price;
    inFile >> Year;
    insert_sorted(Title, DirectorName, Runtime, Format, Price, Year);
    getline(inFile, Title);
  }
  inFile.close();
}

void library::insert_sorted(const string title, const string directorName, const int runtime, const string format, const float price, const int year) {
  movie insert;
  list<movie>::iterator it = moviesList.begin();
  insert.Title = title;
  insert.DirectorName = directorName;
  insert.MovieRuntime = runtime;
  insert.Format = format;
  insert.Price = price;
  insert.Year = year;
  if(moviesList.begin() -> Title > insert.Title) { //checking the title will come first alphabetically 
    push_front(insert);
  }
  else {
    while(it -> Title < insert.Title) { //goes thru the list to find the correct position to insert the movie title alphabetically
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

  for(it = moviesList.begin(); it != moviesList.end(); it++) {
    if(it -> DirectorName == directorName) {
      cout << it -> Title << it -> DirectorName << it -> MovieRuntime;
    }
  }
}

void library::find_movie(const string title) {
  list<movie>::iterator it;
  int count = 0;
  for(it = moviesList.begin(); it != moviesList.end(); it++) {
      size_t found = it -> Title.find(title);
      if(found != string::npos) {
	cout << it -> Title << endl;
	count++;
      }
      if(count == 0) {
	cout << "No movies found with that substring" << endl;
      }
  }
}
  
void library::remove(const string title) {
  list<movie>::iterator it;
  for(it = moviesList.begin(); it != moviesList.end(); it++) {
    if(it -> Title == title) {
      moviesList.erase(it);
    }
  }
}

void library::write_from_file(const string file_name) {
  ofstream outFile;
  outFile.open(file_name);
  outFile.clear();

  list<movie>::iterator it;
  for(it = moviesList.begin(); it != moviesList.end(); it++) {
    outFile << it -> Title << endl  << it -> DirectorName << endl;
  }
  outFile.close();
}

void library::print(){
  list<movie>::iterator it;
  for(it = moviesList.begin(); it != moviesList.end(); it++) {
    cout << it -> Title << endl << it -> DirectorName << endl;
  }
}
