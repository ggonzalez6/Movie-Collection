#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <list>
class library {
 private:
  struct movie {
    std::string Title;
    std::string DirectorName;
    std::string Format;
    int MovieRuntime;
    float Price;
    int Year; //don't know if to make the type an int or short, just going with int for now.
  };
  std::list<movie> moviesList;
  
 public:
  library();
  ~library();
  void insert_sorted(const std::string title, const std::string directorName, const int runtime, const std::string format, const float price, const int year);
  void read_from_file(const std::string file_name);
  void write_from_file(const std::string file_name);
  void print();
  void push_front(movie a);
  void push_back(movie b);
  
  void find_movie(const std::string title);
  void director_search(const std::string directorName);
  void remove(std::string Title);
};
#endif //LIBRARY_H
