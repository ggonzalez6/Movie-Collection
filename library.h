#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>

class library {
 private:
  struct movie {
    std::string Title;
    std::string DirectorName;
    std::string format;
    int MovieRuntime;
    float Price;
    int Year; //don't know if to make the type an int or short, just going with int for now.
  };
  
 public:
  library();
  ~library();
  void insert_sorted(const std::string title, const std::string directorName, const int runtime, const std::string format, const float price, const int year);
  void read_from_file(const std::string file_name);
  void write_from_file(const std::string file_name);
  void print();
  void push_front();
  void push_back();
  std::string find_movie();
  std::string director_search();
  std::string remove(std::string Title);
};
#endif //LIBRARY_H
