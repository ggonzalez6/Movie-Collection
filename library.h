/**
 * @file library.h
 * @author Daniel Way
 * @date 2024-03-22
 * @brief library class definition and prototypes
 * 
 * 
 */
#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <list>


/**
 * Movie collection class
 *
 * @class library library.h "Movie-Collection/library.h"
 * @brief Class that defines a movie collection program
 *
 */
class library {
 private:

  struct movie {
    std::string Title;
    std::string DirectorName;
    std::string Format;

    int MovieRuntime;
    float Price;
    int Year;
    
  };
  std::list<movie> moviesList;
  
 public:
  

/**
 * Does nothing
 *
 * @pre 
 * @post 
 * 
 */
  library();


  

/**
 * Clears the movie list
 *
 * @pre 
 * @post prints "deallocated list" to std out
 * 
 */
  ~library();




/**
 * Inserts the given information into its proper spot, sorted
 *
 * @param const std::string title 
 * @param const std::string directorName 
 * @param const int runtime 
 * @param const std::string format 
 * @param const float price 
 * @param const int year 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void insert_sorted(const std::string title, const std::string directorName, const int runtime, const std::string format, const float price, const int year);




/**
 * Reads the information from the file
 *
 * @param const std::string file_name 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void read_from_file(const std::string file_name);




/**
 * Loads the saved information into a file
 *
 * @param const std::string file_name 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void write_from_file(const std::string file_name);




/**
 * Prints the information in a nice format
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void print();




/**
 * Pushes the information into the front of the list
 *
 * @param movie a 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void push_front(movie a);




/**
 * Pushes the information into the back of the list 
 *
 * @param movie b 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void push_back(movie b);
  




/**
 * Checks for the given movie
 *
 * @param const std::string title 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void find_movie(const std::string title);




/**
 * Allows search for a director and gives what movies they made
 *
 * @param const std::string directorName 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void director_search(const std::string directorName);




/**
 * Removes a movie from the list
 *
 * @param std::string Title 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void removed(std::string Title);

};
#endif //LIBRARY_H
