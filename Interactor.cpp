//
//  DataManager.cpp
//  UdemyBaseCourse
//
//  Created by Ulises Omar Prieto Dominguez on 14/11/22.
//

#include "FileManager.cpp"
#include <iostream>
#include <vector>

using std::vector;
using std::string;

struct Interactor {
private:
  // MARK: - Properties
  vector<Account> dataSource = {};
  FileManager fileManager;
public:
  // MARK: - Methods
  /// To get all the file information accounts.
  /// - important: Use it at the start of application lifecycle.
  void fetchAccounts() {
    dataSource = fileManager.getAccounts();
  }
  
  /// To update all the file information of accounts.
  /// - important: Use it at the end of application lifecycle.
  void updateAccounts() {
    fileManager.updateAccounts(dataSource);
  }
  
  /// Add account to data source.
  void addAccount(string firstName, string lastName, float balance) {
    dataSource.push_back(Account(firstName, lastName, balance));
  }
  
  /// Remove account from position to data source
  void removeAccountAt(int clientNumber) {
    if (isValid(clientNumber)) {
      dataSource.erase(dataSource.begin() + (clientNumber - 1));
    } else {
      throw string("Invalid account number");
    }
  }
  
  void withDrawAt(int clientNumber, float quantity) {
    if (isValid(clientNumber)) {
      if (Account account = dataSource[clientNumber - 1];
          willAttempWithDraw(account.balance, quantity)) {
        account.balance -= quantity;
      } else {
        throw string("Balance isn't enough for this operation.");
      }
    } else {
      throw string("Invalid account number.");
    }
  }
  
  void depositAt(int clientNumber, float quantity) {
    if (isValid(clientNumber)) {
      if (Account& account = dataSource[clientNumber - 1];
          willAttempDeposit(quantity)) {
        account.balance += quantity;
      } else {
        throw string("Balance isn't enough for this operation.");
      }
    } else {
      throw string("Invalid account number.");
    }
  }
  
  float getBalanceAt(int clientNumber) {
    if (isValid(clientNumber)) {
      Account account = dataSource[clientNumber - 1];
      return account.balance;
    } else {
      throw string("Invalid account number.");
    }
  }
  
  vector<Account> getAllAccounts() {
    return dataSource;
  }
  
private:
  bool willAttempDeposit(float newValue) {
    return newValue > 0.0f;
  }
  
  bool willAttempWithDraw(float oldValue, float newValue) {
    if (newValue > 0.0f) {
      if ((oldValue - newValue) >= 0.0f) {
        return true;
      }
    }
    return false;
  }
  /// clientNumber in a starting index as 1.
  bool isValid(int clientNumber) {
    if (clientNumber > 0 && clientNumber < dataSource.size()) {
      return true;
    } else {
      return false;
    }
  }
};
