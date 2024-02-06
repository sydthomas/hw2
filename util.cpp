#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    //create an empty string
    // iterate through rawWord
    // once you hit a space or punctuation (. , ' ""  || use ispunct function)
        // ^^ append the string you have gone through to the empty string
        // ^^ add it to a set 
        // create another new string and repeat the process
    
//***** what if the appended word from the inputed string stops at J.???
    std::set<std::string> wordSets;

    std::string tempString ="";
    //std::cout << " Raw words: " << wordSets[]
    for(size_t i = 0; i < rawWords.size(); i++){
        //cout << "index: " << i << "   val to check: `" << rawWords[i] << '`' << endl;
        if((ispunct(rawWords[i])) || (rawWords[i] == ' ')){
            //cout << "Letter was Punc or space" << endl;
            //cout << tempString << endl;
            if(tempString.size() >= 2){
                //cout << "Added word to set" << endl;
                wordSets.insert(tempString);
                //tempString.clear();
            }
            //std::cout << "Clearing set here: " << rawWords[i] << endl;
            tempString.clear();
        }
        else{
            tempString.push_back(rawWords[i]);
            if( i == (rawWords.size()-1) ){
              //cout << tempString << endl;
              //cout << "Last word input" << endl;
              //std::cout << "Just push_backed: " << rawWords[i] << endl;
              wordSets.insert(tempString);
              return wordSets;
            }
        }
    }
    //std::cout << "Retruning an empty string: " << rawWords[i] << endl;
    //return std::set<std::string>();
    return wordSets;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
