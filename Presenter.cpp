//
//  Presenter.cpp
//  UdemyBaseCourse
//
//  Created by Ulises Omar Prieto Dominguez on 14/11/22.
//

#include "Interactor.cpp"
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;

struct Presenter {
private:
  Interactor interactor;
  string navigationTitle = "\nSelect one option below: \n";
  string transactionTitle = "Add Client Number: \n";
  string options[7] = {
    "1. Open an account",
    "2. Balance enquiry",
    "3. Deposit",
    "4. Withdrawal",
    "5. Close an Account",
    "6. Show All Accounts",
    "7. Quit"
  };
public:
  Presenter() {
    interactor.fetchAccounts();
  }
 
  void willStartProgram() {
    string bodyOption = "";
    int menuOption = -1;
    
    cout << navigationTitle << endl;
    
    for(string option: options) {
      bodyOption += (option + "\n");
    }
    
    cout << bodyOption << endl;
    cin >> menuOption;
    
    willUserMakeAnOperation(menuOption);
  }
  
  void willUserMakeAnOperation(const int option) {
    if (option <= 0 || option > 7) {
      cout << "Invalid Option, please try again." << endl;
    } else {
      switch (option) {
        case 1:
          saveNewClient();
          break;
        case 6:
          showAllAccounts();
          break;
        case 7:
          interactor.updateAccounts();
          exit(0);
          break;
        default:
          willUserMakeTransactionForClientWith(option);
          break;
      }
    }
  }
  
  void willUserMakeTransactionForClientWith(const int menuOption) {
    int clientNumber;
    cout << "Enter client number" << endl;
    cin >> clientNumber;
    cout << endl;
    switch(menuOption) {
      case 5:
        closeAccountWithClient(clientNumber);
        break;
      case 4:
        withDrawWithClient(clientNumber);
        break;
      case 3:
        depositToClient(clientNumber);
        break;
      case 2:
        showBalanceFromClient(clientNumber);
        break;
      default:
        cout << "Invalid option, please try again." << endl;
        break;
    }
  }
  
  
  
private:
  void saveNewClient() {
    try {
      string firstName;
      string lastName;
      float balance;
      cout << "Please enter first name: " << endl;
      cin >> firstName;
      cout << "Please enter last name: " << endl;
      cin >> lastName;
      cout << "Please enter initial balance: " << endl;
      cin >> balance;
      interactor.addAccount(firstName, lastName, balance);
      cout << "Account added successfully" << endl;
    } catch(string error) {
      cout << "Couldn't retrieve client information, reason: \n:" << endl;
    }
  }
  
  void showBalanceFromClient(int number) {
    try {
      float clientBalance = interactor.getBalanceAt(number);
      cout << "Your balance is: " << clientBalance << endl;
    } catch(string error) {
      cout << "Couldn't get balance information. Reason:\n" << error << endl;
    }
  }
  
  void depositToClient(int number) {
    try {
      float quantity;
      cout << "Enter quantity to deposit: " << endl;
      cin >> quantity;
      interactor.depositAt(number, quantity);
    } catch(string error) {
      cout << "Couldn't deposit to balance. Reason:\n" << error << endl;
    }
  }
  
  void withDrawWithClient(int number) {
    try {
      float quantity;
      cout << "Enter quantity to withdraw: " << endl;
      cin >> quantity;
      interactor.withDrawAt(number, quantity);
    } catch(string error) {
      cout << "Couldn't withdraw from balance. Reason:\n" << error << endl;
    }
  }
  
  void closeAccountWithClient(int number) {
    try {
      interactor.removeAccountAt(number);
      cout << "Account number " << number << "removed";
    } catch(string error) {
      cout << "Couldn't remove client. Reason:\n" << error << endl;
    }
  }
  
  void showAllAccounts() {
    vector<Account> dataSource = interactor.getAllAccounts();
    if (dataSource.empty()) {
      cout << "There's no account registered yet..." << endl;
    } else {
      cout << "=== Account Information ===" << endl;
      for(int index = 0; index < dataSource.size(); index++) {
        cout << "Client Number: " << (index + 1) << endl;
        cout << "First Name: " << dataSource[index].firstName << endl;
        cout << "Last Name: " << dataSource[index].lastName << endl;
        cout << "Balance: " << dataSource[index].balance << endl << endl;
      }
    }
  }
};
