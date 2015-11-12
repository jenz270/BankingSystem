//
//  User.cpp
//  BankingSystem
//
//  Created by Jieni Hou on 2015-09-28.
//  CS3307 A1
//  Copyright (c) 2015 Jieni Hou. All rights reserved.
//

#include "User.h"
#include "Customers.h"

using namespace std;

/******************************************************************************************************
    User Constructor
 ******************************************************************************************************/
User::User():fName(" "),lName(" ") {
    accountNum = 1000 + (rand() % 1000);
    Customers cust;
    if(cust.findAccNum(accountNum)){
        accountNum = accountNum + 1;
    }
    
}

/******************************************************************************************************
    User Constructor
 ******************************************************************************************************/
User::User(int accNum, string first, string last):accountNum(accNum),fName(first),lName(last){
}

/******************************************************************************************************
    User Deconstructor
 ******************************************************************************************************/
User::~User(){
    
}

/******************************************************************************************************
    setFname sets the User's first name
 ******************************************************************************************************/
void User::setFname(string firstN){
    fName = firstN;
}


/*****************************************************************************************************
    setLname set's the User's last name
 ******************************************************************************************************/
void User::setLname(string lastN){
    lName = lastN;
}


/*****************************************************************************************************
    setAccNum set's the User's account number
 ******************************************************************************************************/

void User::setAccNum(int accNum){
    
    accountNum = accNum;
}

/*****************************************************************************************************
   getAccNum gets the account number of the user
 ******************************************************************************************************/
int User::getAccNum(){
    return accountNum;
}

/*****************************************************************************************************
    getFname gets the first name of the user
******************************************************************************************************/
string User::getFname(){
    return fName;
}

/*****************************************************************************************************
    getLname gets the last name of the user
 ******************************************************************************************************/
string User::getLname(){
    return lName;
}

/*****************************************************************************************************
    numAccounts gets the number of accounts within the User
 ******************************************************************************************************/
long User::numAccounts(){
    return accounts.size();
}


/*****************************************************************************************************
    addAccount adds a bank account for the User
 ******************************************************************************************************/
void User::addAccount(Account acc){
    accounts.push_back(acc);
}


/*****************************************************************************************************
    getAccount gets a specific account
 ******************************************************************************************************/
Account User::getAccount(int number){
    Account account;
    if(!(number > accounts.size())){
        account = accounts[number-1];
        return account;
     }
    else{
        cout << "Please choose a valid account. \n";
    }
    return account;
}


 /*****************************************************************************************************
    viewAllAccounts shows all the accounts that the customer has within their account.
 ******************************************************************************************************/
void User::viewAllAccounts(){
    for(int i = 0; i < accounts.size(); i ++){
        cout << "Account " << i+1 << ":\n";
        accounts[i].accountInformation();
        cout << "\n";
    }
}

/*****************************************************************************************************
    clearAccounts clears all accounts within the user
 ******************************************************************************************************/
void User::clearAccounts(){
    accounts.clear();
}