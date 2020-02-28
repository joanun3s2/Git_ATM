#define _ATM_HPP_
#ifndef _ATM_HPP_

#include <string>

using namespace std;

class User{

  private:
    string nome;
    string senha;

  public:
    void setNome();
    string getNome();

};

#endif