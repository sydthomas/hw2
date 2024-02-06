#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string category,const std::string name, double price, int qty,const std::string genre, const std::string rating) :
Product(category,name,price,qty), genre_(genre), rating_(rating)
{

}


/**
* Returns the appropriate keywords that this product should be associated with
*/
std::set<std::string> Movie::keywords() const
{
  //product should match a keyword if it appears in the product name or 
  // one of the following sttributes below 

  // search for author's name 
  // search for ISBN number

  std::set<std::string> setGenre = parseStringToWords(convToLower(genre_));
  //std::set<std::string> setRating = parseStringToWords(movie->rating_);
  std::set<std::string> setName = parseStringToWords(convToLower(name_));
  std::set<std::string> returnSet;
  returnSet.insert(setGenre.begin(), setGenre.end());
  returnSet.insert(setName.begin(), setName.end());
  return returnSet;


}

/**
* Returns a string to display the product info for hits of the search
*/
std::string Movie::displayString()  const
{

  stringstream ss; 
  ss << name_ << "\n" << "Genre: " << genre_ <<  " Rating: " << rating_ << 
    "\n" << fixed<<setprecision(2)<<price_ <<  "  " << qty_ << " left.";
  return ss.str();

  // std::string disString = name_ + "\n " + "Genre: " + genre_ + " Rating: " + rating_ + 
  //   "\n" + std::to_string(price_) +  " " + std::to_string(qty_ ) + "left.";
  // return disString;
}


void Movie::dump(std::ostream& os)  const
{
    os << "movie" << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}