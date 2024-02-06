#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include "mydatastore.h"
#include "product.h"
#include "product_parser.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "util.h"

using namespace std;


  MyDataStore::~MyDataStore(){
    //productDataBase.clear(); // iterate through both of theses 
    //userDataBase.clear();

    for(std::set<Product*>::iterator it = productDataBase.begin(); it != productDataBase.end(); ++it){
      delete *it;
    }
    productDataBase.clear();

    for(size_t i = 0; i < userVector.size(); i++){
      delete userVector[i];
    }
    

  }


  void MyDataStore::addProduct(Product* p)
  {

    std::set<std::string> keyWords = p->keywords();
    for(std::set<std::string>::iterator it = keyWords.begin(); it != keyWords.end(); ++it){
      if(keyWordSearch.find(*it) != keyWordSearch.end()){
        keyWordSearch[*it].insert(p); 
      }
      else{
        std::set<Product*> newUserCart;
        newUserCart.insert(p);
        keyWordSearch.insert({*it, newUserCart});
      }
    }

    //set of products
    productDataBase.insert(p);
  
// go throug serach terms
// 

    // create data structure to store products
        // something that has efficient searching 
        // insertion 
        // deletation 
        // retreival of products  
  }

  void MyDataStore::addUser(User* u)
  {
    //std::vector<std::variant<int, double>> userVecDetails; // vector to store user type & balance
    //std::map<std::User, userVecDetails>> userDataBase; // map where i store user as the key adn its data in the vector 
    //std::vector<Product*> c;
    //userVecDetails.pushback(u.type_);
    //userVecDetails.pushback(u.balance_);
    //userVector.push_back(u);
    //userCart[u];
    findUser[u->getName()] = u; 
    userVector.push_back(u);

  }

  std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
  { //*   search must be implemented efficeiently  *//
    // AND(one word, two words, no words, or more??)
    // OR(one word, two words, no worsdm or more??)

    

// all the products in the database 
    //std::set<Product*> allProdSet = productDataBase; // can you do this
 // set of products with the key word   
    std::set<Product*> prodSet; 
    std::set<Product*> finalSearchSet;
    std::vector<std::string> myTerms;

    for(size_t i = 0; i < terms.size(); i++ ){
      myTerms.push_back(convToLower(terms[i]));
    }

    if(type == 0)
    {
      for(std::vector<std::string>::iterator it = myTerms.begin(); it != myTerms.end(); ++it){
        if(keyWordSearch.end() != keyWordSearch.find(*it)){
          if(finalSearchSet.empty()){
            finalSearchSet = keyWordSearch[*it];
          }  
          else{
            finalSearchSet = setIntersection(keyWordSearch[*it], finalSearchSet);
            // if(finalSearchSet.empty()){
            //   break;
            // }
          }
        }
      }
      std::vector<Product*> productVect(finalSearchSet.begin(), finalSearchSet.end());
      return productVect;
    }
    else if(type == 1)
    {
      for(std::vector<std::string>::iterator it = myTerms.begin(); it != myTerms.end(); ++it){
        if(keyWordSearch.end() != keyWordSearch.find(*it)){
          if(finalSearchSet.empty()){
            finalSearchSet = keyWordSearch[*it];
          }  
          else{
            finalSearchSet = setUnion(keyWordSearch[*it], finalSearchSet);
            // if(finalSearchSet.empty()){
            //   break;
            // }
          }
        }
      }
      std::vector<Product*> productVect(finalSearchSet.begin(), finalSearchSet.end());
      return productVect;
    }
    else{
      return {}; // unless there isn't an AND or OR (maybe ask about that)
    }
  }


  void MyDataStore::dump(std::ostream& ofile)
  {
    ofile << "<products>"  << endl;
    for(std::set<Product*>:: iterator it =  productDataBase.begin(); it != productDataBase.end(); ++it){
      (*it)->dump(ofile);  
    }
    ofile << "</products>" << endl;
    ofile << "<users>"  << endl;
    for(size_t i = 0; i < userVector.size(); i++){
      userVector[i]->dump(ofile); 
    }
    ofile << "</users>" << endl;

// use the other dumps and just dump all products and then all the users 
  }

/* add to header file */
  void MyDataStore::addToCart(std::string userN, Product* lastHit){ 
    /// need to check if a user is logged in ... maybe ... 
    
    // if(findUser.find(userN) != findUser.end()){
    //   User* key = (findUser.find(userN))->second;
    //   userCart[key].push_back(lastHit);
    // }

    if(findUser.find(userN) != findUser.end()){
      User* key = (findUser.find(userN))->second;
      if(userCart.find(key) != userCart.end()){
        userCart[key].push_back(lastHit);
      }
      else{
        std::vector<Product*>userNewCart;
        userNewCart.push_back(lastHit);
        userCart.insert({key, userNewCart});
      }
    }
    else{
      std::cout << "Invalid request" << endl;
    }


  }

  void MyDataStore::viewCart(std::string userN){  
    /// print cart out (look for format)
      // print product info 
     // check to see if someone is logged in 
    //  if(findUser.find(userN) != findUser.end()){
    //   for(std::map<User*, std::vector<Product*>>::iterator it = userCart.begin(); it != userCart.end(); ++it){
    //     std::vector<Product *> uProducts = it->second;
    //     int j = 1;
    //     for (size_t i = 0; i < uProducts.size(); i++) {
    //       Product *p = uProducts[i];
    //       std::cout << "Item " << j << "\n" << p->displayString() << std::endl;
    //       j+=1;
    //       std::cout << std::endl; // maybe delete 
    //     }        
    //   }
    // }
    if (findUser.find(userN) == findUser.end()) {
      std::cout << "Invalid username" << endl;
      return;
    }

    User *user = findUser[userN];
    if (userCart.find(user) == userCart.end()) {
      return;
    }

    if(findUser.find(userN) != findUser.end()){
      User* key = (findUser.find(userN))->second;
      if(userCart.find(key) != userCart.end()){
        std::vector<Product *> uProducts = (userCart.find(key))->second;
        int j = 1;
        for (size_t i = 0; i < uProducts.size(); i++) {
          Product *p = uProducts[i];
          std::cout << "Item " << j << "\n" << p->displayString() << std::endl;
          j+=1;
          std::cout << std::endl; // maybe delete 
        }
      }        
    }
 
  }

  void MyDataStore::buyCart(std::string userN){
    // removes item from cart 
    // subtracts quantity in inventory 
    // subtracts users balance (think of a way to link this to the user)
    // add to user history
    // if(findUser.find(userN) != findUser.end()){
    //   User* key = findUser.find(userN)->second;
      //f(userCart.find(key) != userCart.end()){
    //  std::vector<Product*> usercarts = userCart[key]->second;
    //   for(std::vector<Product*>::iterator it = usercarts.begin(); it != usercarts.end(); ++it){
    //     if(key->getBalance() >= (*it)->getPrice()){
    //       if((*it)->getQty() > 0){
    //         (*it)->subtractQty(1);
    //         key->deductAmount((*it)->getPrice());
    //       }      
    //     }
    //   }
    // }
//temp cart for leftover items not bought 
    vector<Product*> leftOverCart;

    if (findUser.find(userN) == findUser.end()) {
      std::cout << "Invalid username" << endl;
      return;
    }

    User *user = findUser[userN];
    if (userCart.find(user) == userCart.end()) {
      return;
    }

    vector<Product *> uCart = userCart[user];
    for (size_t i = 0; i < uCart.size(); i++) {
      Product *p = uCart[i];
      if (user->getBalance() < p->getPrice() || p->getQty() < 1) {
        leftOverCart.push_back(p);
        //std::cout << "Added to leftover cart" << endl;
        continue;
      }

      p->subtractQty(1);
      user->deductAmount(p->getPrice());
    }

    if(leftOverCart.size() == 0){
      userCart.erase(user);
    }
    else{
      userCart[user] = leftOverCart;
    }

    


    // if(findUser.find(userN) != findUser.end()){
    //   for(std::map<User*, std::vector<Product*>>::iterator it = userCart.begin(); it != userCart.end(); ++it){
    //     std::vector<Product *> uProducts = it->second;
    //     for (int i = 0; i < uProducts.size(); i++) {
    //       Product *p = uProducts[i];
    //       if(it->getBalance() >= p->getPrice()){
    //         if((*it)->getQty() > 0){
    //           p->subtractQty(1);
    //           it->deductAmount(p->getPrice());
    //         }
    //       }
    //     }        
    //   }
    // }

  }


  /// **** add the menu option functions **** ///



  /*data base set compared to set created by inputs
     take the two strings and put them in a set 
      ^^ use string break down function for this 
    use intersection comparasion 

  
    auto it = keywordIndex.find(searchStr);
    if (it != keywordIndex.end()) {
        matchingProducts.insert(matchingProducts.end(), it->second.begin(), it->second.end());
    }

      if(map of products(item 1) == found )

// map keywords =  (the 2 items ) --> check to see if found 
    */