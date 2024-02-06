#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category,const std::string name, double price, int qty,const std::string author, const std::string ISBNnum) :
Product(category,name,price,qty), author_(author), ISBNnum_(ISBNnum)
{

  

}

/////////* do  i need a dtor *////////

/**
* Returns the appropriate keywords that this product should be associated with
*/
std::set<std::string> Book::keywords() const
{
  //product should match a keyword if it appears in the product name or 
  // one of the following sttributes below 

  // search for author's name 
  // search for ISBN number

  std::set<std::string> setAuthors = parseStringToWords(convToLower(author_));
  std::set<std::string> setNames = parseStringToWords(convToLower(name_));



  for(set<string>::iterator it=setAuthors.begin(); it != setAuthors.end(); ++it){
    setNames.insert(*it);
  }
  setNames.insert(ISBNnum_); // do i convert to lower here 
  

  return setNames;

}

/**
* Returns a string to display the product info for hits of the search
*/
std::string Book::displayString()  const
{

  stringstream ss; 
  ss << name_ << "\n" << "Author: " << author_ <<  " ISBN: " << ISBNnum_ << 
    "\n" << fixed<<setprecision(2)<<price_ <<  "  " << qty_ << " left.";
  return ss.str();

  // std::string disString = name_ + "\n " + "Author: " + author_ + " ISBN: " + ISBNnum_ + 
  //   "\n" + std::to_string(price_) +  " " + std::to_string(qty_ ) + " left.";
  // return disString;
}


void Book::dump(std::ostream& os)  const
{
  os << "book" << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBNnum_ << "\n" << author_ << endl;
}