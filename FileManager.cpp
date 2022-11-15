//
//  DataManager.cpp
//  UdemyBaseCourse
//
//  Created by Ulises Omar Prieto Dominguez on 14/11/22.
//

#include "Entities.cpp"
#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::endl;

struct FileManager {
private:
  const string fileName = "Accounts.txt";
public:
  
  /// Will retrieve all the available accounts at the file.
  vector<Account> getAccounts() {
    vector<Account> accounts = {};
    ifstream inputStream(fileName);
    
    if (inputStream.is_open()) {
      while(!inputStream.eof()) {
        string firstName;
        inputStream >> firstName;
        
        if (!firstName.empty()) {
          string lastName;
          float balance;
          inputStream >> lastName;
          inputStream >> balance;
          
          accounts.push_back(Account(firstName, lastName, balance));
        }
      }
    }
    
    inputStream.close();
    return accounts;
  }
  
  /// Will truncate the previous file version and make a new with delete or update source operations.
  void updateAccounts(vector<Account> accounts) {
    ofstream outputStream(fileName, ios::trunc);
    if (outputStream.is_open()) {
      for(Account account: accounts) {
        outputStream << account.firstName << endl;
        outputStream << account.lastName << endl;
        outputStream << account.balance << endl;
      }
    }
    outputStream.close();
  }
};
