#include "library.h"
#include <iostream>

using namespace std;

int main() {
  library a;
  string option;

  cout << "Welcome to the UTM Movie Collection! You may select one of the following options: " << endl;
  cout << "1 Read the Movie Collection from a file" << endl;
  cout << "2 Write the Movie Collection  to a file" << endl;
  cout << "3 Print the Movie Collection" << endl;
  cout << "4 Search for a movie" << endl;
  cout << "5 Search for a Director" << endl;
  cout << "6 Add a movie" << endl;
  cout << "7 Delete a movie" << endl;
  cout << "8 Exit this program" << endl;
  
  return 0;
}
