#include "library.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <string>

using namespace std;

library::library() {
  list<movie> movies;
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
  list<movie>::iterator it = movies.begin();
  insert.Title = title;
  insert.DirectorName = directorName;
  insert.Runtime = runtime;
  insert.Format = format;
  insert.Price = price;
  insert.Year = year;
  if(movies.begin().Title > insert.Title) {
    movies.push_front(insert);
  } else {
    while(it.Title < insert.Title) {
      it++;
    }
    movies.insert(it, insert);
  }
  
}
  
