# Movie-Collection, by Gerardo Gonzalez and Daniel Way
## Design Decisions
We divided the assignment in a struct class called 'movie' that initializes a set of 6 data members for an overall description about a movie. The struct class is also housed inside of a class called 'library' where it initializes the 'movie' class as its private members, and 11 methods as its public members. The methods have the purpose of creating a doubly linked list, as well as destroying it, inserting movies into a txt file in alphabetical order, reading from a writing to a txt file, printing out the list of movies from a txt file, pushing data nodes to the front and back of the doubly linked list, searching a txt file for a specific movie and a director, and also being able to delete data nodes from the doubly linked list.

## Challenges
* The biggest challenge was implememting the <list> library. Even though it made the coding process a lot easier, it was still a hassle to getting used to using the library's keywords since we were so used to implementing each function 'manually'.
* The other challenge we encountered was trying to use iterators, as it was our first time implementing them. Though, we learned the significance that iterators carry.
* Lastly, we also had trouble with the 'find_movie' function since we had to implement the use of substrings. However, we countered it with using the bool's functionality and 'size_t'.

## How to run
1. run `make` to create the program
2. run `./library` to run the program
3. It then gives you a list of options ranging from looking up movies and directors, as well as deleting and inserting movies.
4. The user is needed to input a specific number from the list of options that the program provides
5. When the user is done, they are required to enter `8` to exit and deallocate the program

## How the work was split up
Like our previous assignment, we set up all our 'skeleton' flies fisrt, then we went thru the process of actually coding it together on Gerardo's machine.
On the other hand, Daniel decided to do all the documentation, corrected all of the syntax errors, and wrote the READ.me file himself.
Gerardo also managed to recieve help from the SI lab with the 'find_movie' and 'director_search' functions