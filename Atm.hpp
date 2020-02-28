#ifndef _ATM_HPP_
#define _ATM_HPP_

#include <iostream>
#include <string>

void start();

bool login(std::string name, std::string password);

void checkPassword();
void checkBalance();
void withDrawal();
void deposit();
void pay();

#endif