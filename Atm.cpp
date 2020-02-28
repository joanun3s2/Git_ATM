#include "Atm.hpp"
#include <iostream>

/** vars */
std::string userName;
std::string userPassword;
double userBalance = 0;

int menuAux;

/** Methods */
void menu();

void checkPassword(){
  std::cout << std::endl << "Your Password is: " <<
  userPassword << std::endl << std::endl;
  menu();
}

void checkBalance(){
  std::cout << std::endl << "Your Cash Balance is: " <<
  userBalance << std::endl << std::endl;
  menu();
}

void withDrawal(){
  double draw;
  std::cout << std::endl << "Type the amoutn of cash you wanto to withdrawal: ";
  std::cin >> draw;
  std::cout << "Processing.." << std::endl;

  if((userBalance < draw) || (draw <=0)){
    std::cout << std::endl << "You have not enough balance!" << std::endl <<
    "Canceling operation" << std::endl;
    menu();
  }else{
    userBalance = userBalance - draw;
    std::cout << std::endl <<
    "Withdrawn amount: " << draw << std::endl <<
    "We recomend to check your balance before leaving!" << std::endl;
    menu();
  }

}

bool depositMenu(){

  int depositAux;

  std::cout << std::endl <<
  "1 - Deposit to my own account" << std::endl <<
  "2 - Deposit to other person's account" << std::endl <<
  "0 - Cancel" << std::endl << std::endl <<
  "Type the number of the oparation you want: ";
  std::cin >> depositAux;

  switch(depositAux){
    case 1:
      std::cout << "Depositing to your own account..." << std::endl;
      return false;
      break;
    case 2:
      std::cout << "Depositing to other person's account..." << std::endl;
      return true;
      break;
    case 0:
      std::cout << "Canceling..." << std::endl;
      menu();
      break;
    default:
      std::cout << "Unexpected input, try again" << std::endl;
      depositMenu();
      break;
  }
}

void deposit(){

  double deposit;

  if(depositMenu()){

    std::string personName;

    std::cout << "Type the name of the person you wanto to deposit to: ";
    std::cin >> personName;

    std::cout << std::endl << "Type the amoutn of cash you wanto to deposit: ";
    std::cin >> deposit;
    std::cout << "Processing.." << std::endl;

    if(deposit <=0){
      std::cout << std::endl << "Not an valid value posted" << std::endl <<
      "Canceling operation" << std::endl;
      menu();
    }else{
      userBalance = userBalance + deposit;
      std::cout << std::endl <<
      "Depositen amount: " << deposit << std::endl <<
      " to " << personName << std::endl;
      menu();
    }


  }else{

    std::cout << std::endl << "Type the amoutn of cash you wanto to deposit: ";
    std::cin >> deposit;
    std::cout << "Processing.." << std::endl;

    if(deposit <=0){
      std::cout << std::endl << "Not an valid value posted" << std::endl <<
      "Canceling operation" << std::endl;
      menu();
    }else{
      userBalance = userBalance + deposit;
      std::cout << std::endl <<
      "Depositen amount: " << deposit << std::endl <<
      "We recomend to check your balance before leaving!" << std::endl;
      menu();
    }

  }
}

void pay(){
  double price;
  std::cout << std::endl << "Type the price you wanto to pay: ";
  std::cin >> price;
  std::cout << "Processing.." << std::endl;

  if((userBalance < price) || (price <=0)){
    std::cout << std::endl << "You have not enough balance!" << std::endl <<
    "Canceling operation" << std::endl;
    menu();
  }else{
    userBalance = userBalance - price;
    std::cout << std::endl <<
    "Paid amount: " << price << std::endl <<
    "We recomend to check your balance before leaving!" << std::endl;
    menu();
  }
}

void menu(){
  std::cout << std::endl <<
  "1 - Check Password" << std::endl <<
  "2 - Check Balance" << std::endl <<
  "3 - Withdrawal" << std::endl <<
  "4 - Deposit" << std::endl <<
  "5 - Pay" << std::endl <<
  "0 - Exit system" << std::endl << std::endl <<
  "Type the number of the oparation you want: ";
  std::cin >> menuAux;

  switch(menuAux){
    case 1:
      std::cout << "Checking User Password..." << std::endl;
      checkPassword();
      break;
    case 2:
      std::cout << "Checking User Balance..." << std::endl;
      checkBalance();
      break;
    case 3:
      std::cout << "Cash Withdrawal..." << std::endl;
      withDrawal();
      break;
    case 4:
      std::cout << "Cash Deposit..." << std::endl;
      deposit();
      break;
    case 5:
      std::cout << "Bill Payment..." << std::endl;
      pay();
      break;
    case 0:
      std::cout << "Exiting system..." << std::endl;
      break;
    default:
      std::cout << "Unexpected input, try again" << std::endl;
      menu();
      break;
  }

}

bool login(std::string name, std::string password){
  /** Simple login just for example. */
  if((name.compare("admin") == 0) && (password.compare("admin") == 0)){
    return true;
  }

  return false;
}

void start(){

  std::cout << "Welcome to LP I ATM" << std::endl <<
  "Type your name to enter: ";
  std::cin >> userName;

  std::cout << std::endl << "Now type your password to proceed: ";
  std::cin >> userPassword;

  if(login(userName,userPassword)){
    std::cout << std::endl << "Entering system";
    menu();
  }else{
    std::cout << std::endl << "Wrong input, try again.." << std::endl;
    start();
  }

}


