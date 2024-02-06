#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"


class MyDataStore : public DataStore{

public:
    ~MyDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

    //other functions:
    void addToCart(std::string userN, Product* lastHit);
    void viewCart(std::string userN);
    void buyCart(std::string userN);

private:

  std::set<Product*> productDataBase; 
  std::map<std::string, std::set<Product*>> keyWordSearch;

  //std::set<User*> userDataBase;
  std::vector<Product*> cart;
  std::vector<User*> userVector; 
  
  
  std::map<User*, std::vector<Product*>> userCart; //use to be userDataBase
  std::map<std::string, User*> findUser;

};

#endif

