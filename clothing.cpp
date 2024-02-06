#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category,const std::string name, double price, int qty,const std::string size, const std::string brand) :
Product(category,name,price,qty), size_(size), brand_(brand)
{

}


/**
* Returns the appropriate keywords that this product should be associated with
*/
std::set<std::string> Clothing::keywords() const
{

  std::set<std::string> setBrand = parseStringToWords(convToLower(brand_));
  std::set<std::string> setName = parseStringToWords(convToLower(name_));
  std::set<std::string> returnSet;
  returnSet.insert(setBrand.begin(), setBrand.end());
  returnSet.insert(setName.begin(), setName.end());
  return returnSet;

}

/**
* Returns a string to display the product info for hits of the search
*/
std::string Clothing::displayString()  const
{
  stringstream ss; 
  ss << name_ << "\n" << "Size: " << size_ <<  " Brand: " << brand_ << 
    "\n" << fixed<<setprecision(2)<<price_ <<  " " << qty_ << " left.";
  return ss.str();
}


void Clothing::dump(std::ostream& os)  const
{
    os << "clothing" << "\n" << name_<< "\n" <<price_ << "\n" << qty_ << "\n" << size_  << "\n" << brand_ << endl;
}