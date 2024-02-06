#ifndef CLOTHING_H
#define CLOTHING_H

#include <string>
#include <iostream>
#include <set>

#include "product.h"

class Clothing : public Product { //should I use private or public in this situation 

public:

    Clothing(const std::string category,const std::string name, double price, int qty,const std::string size, const std::string brand);
    

    virtual std::set<std::string> keywords() const;

    virtual std::string displayString() const;
    
    virtual void dump(std::ostream& os) const; //idk if i override here 


protected:
    std::string size_;
    std::string brand_;

};
#endif