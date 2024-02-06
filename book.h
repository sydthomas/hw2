#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <set>

#include "product.h"

class Book : public Product { //should I use private or public in this situation 

public:

    Book(const std::string category,const std::string name, double price, int qty,const std::string author, const std::string ISBNnum);
    
    //~Book();// is this correct 

    virtual std::set<std::string> keywords() const;

    virtual std::string displayString() const;
    
    virtual void dump(std::ostream& os) const; //idk if i override here 


protected:
  std::string author_;
  std::string ISBNnum_;

};
#endif

