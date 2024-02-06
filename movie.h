#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include <set>

#include "product.h"

class Movie : public Product { //should I use private or public in this situation 

public:

    Movie(const std::string category,const std::string name, double price, int qty,const std::string genre, const std::string rating);
    
    //~Book();// is this correct 

    virtual std::set<std::string> keywords() const;

    virtual std::string displayString() const;
    
    virtual void dump(std::ostream& os) const; //idk if i override here 


protected:

    std::string genre_;
    std::string rating_;

};
#endif