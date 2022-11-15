//
//  InteractorLayer.cpp
//  UdemyBaseCourse
//
//  Created by Ulises Omar Prieto Dominguez on 14/11/22.
//

#include <iostream>

using std::string;

struct Account {
  string firstName;
  string lastName;
  float balance;
  
  Account(string firstName, string lastName, float balance) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->balance = balance;
  }
};
