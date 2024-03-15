#include "library.h"
#include <iostream>

using namespace std;

int main() {
  library a;
  string option;
  string fileName;
  string title;
  string directorName;
  cout << "Welcome to the UTM Movie Collection! You may select one of the following options: " << endl;
  cout << "1 Read the Movie Collection from a file" << endl;
  cout << "2 Write the Movie Collection to a file" << endl;
  cout << "3 Print the Movie Collection" << endl;
  cout << "4 Search for a movie(s)" << endl;
  cout << "5 Search for a Director's catalog" << endl;
  cout << "6 Add a movie" << endl;
  cout << "7 Delete a movie" << endl;
  cout << "8 Exit this program" << endl;

  cout << endl;
  cout << "Please enter your choice now: ";

  while(option != "8") {
    if(option == "1") {
      cout << "What is the file name: ";
      cin >> fileName;
      a.read_from_file(fileName);

      cout << endl;
      cout << "Please enter your next choice now: ";
    }
    else if (option == "2") {
      cout << "Name the new file you want to write to: ";
      cin >> fileName;
      a.write_from_file(fileName);

      cout << endl;
      cout << "Please enter your next choice now: ";
    }
    else if (option == "3") {
      a.print();

      cout << endl;
      cout << "Please enter your next choice now: ";
    }
    else if (option == "4") {
      cout << "What is the full or partial name of the movie: ";
      cin >> title;
      a.find_movie(title);

      cout << endl;
      cout << "Please enter your next choice now: ";
    }
    else if (option == "5") {
      cout << "What is the name of the director: ";
      cin >> directorName;
      a.director_search(directorName);

      cout << endl;
      cout << "Please enter your next choice now: ";
    }
    else {

    }
    cin >> option;
    cout << endl;
  }
  return 0;
}
