#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */

 //** store keyworsd in common case **////
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  // AND 
  std::set<T> intersectionSet;
  for(T item: s1){
    if(s2.end() != s2.find(item)){
      intersectionSet.insert(item);
    }
  }
  return intersectionSet;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{

//foudnd in either of the sets 
  std::set<T> intersectionSet;
  for(T item: s1){
    s2.insert(item);
  }
  return s2;

}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
