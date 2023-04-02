#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class bank_account{
  public:
  void set_name(const string& account_name);
  string get_name() const;

  void set_account_type(bool is_credit);
  bool get_account_type() const;

  void set_balance(double amount);
  double get_balance() const;

  private:
  string name;
  bool credit;
  double balance;
};

void bank_account::set_name(const string& account_name){
  name = account_name;
}

void bank_account::set_account_type(bool is_credit){
  credit = is_credit;
}

void bank_account::set_balance(double amount){
  if (amount < 0.0 && !get_account_type()){
   throw runtime_error("account cannot hold negative balance");
  }
  balance += amount;
}

double bank_account::get_balance()const{
  return balance;
}

string bank_account::get_name() const{
  return name;
}

bool bank_account::get_account_type() const{
  return credit;
}

class BankVector {
public:
    BankVector() {
        usedCapacity = 0;
    }
    
    ~BankVector() {}
    
    unsigned int size() const {
        return usedCapacity;
    }
  
    bank_account& at(unsigned int index) const {
        if(index >= 0 && index < usedCapacity){
            return entries[index];
        }
        throw IndexError();
    }

    void push_back(bank_account a){
        if(usedCapacity == maxCapacity) {
            if (usedCapacity == 0) {
                entries = new bank_account[1];
                maxCapacity = (usedCapacity + 1);
            } else {
                bank_account* temparray = new bank_account[maxCapacity + 1];
                maxCapacity++;
                for(int i = 0; i < usedCapacity; i++){
                    temparray[i] = entries[i];
                }
                delete[] entries;
                entries = temparray;
            }
        }
        entries[usedCapacity++] = a;
    }

    void erase(unsigned int index){
        if(index >= 0 && index < usedCapacity){
            for(int i = index + 1; i < usedCapacity; i++){
                entries[i - 1] = entries[i];
            }
            usedCapacity--;
        }
    }

    class IndexError {};
    
private:
    bank_account* entries;
    unsigned int usedCapacity;
    unsigned int maxCapacity;
};



class registry {
  public:
  void account_creation(const string& name, bool is_credit);
  void account_transaction(const string& name, double amount);
  void account_removal(const string& name);
  bool is_exist(const string& account_name) const;
  void print();

  private:
  bank_account& fetch_account(const string& account_name);
  BankVector reg;
};

bank_account& registry::fetch_account(const string& account_name){
  for(int i = 0; i < reg.size(); i++){
   if(reg.at(i).get_name() == account_name){
    return reg.at(i);
   }
  }
  throw runtime_error("account does not exist");
}

bool registry::is_exist(const string& account_name) const{
  for(int i = 0; i < reg.size(); i++){
   if(account_name == reg.at(i).get_name()){
    return true;
   }
  }
  return false;
}

void registry::account_creation(const string& name, bool is_credit){
  if(is_exist(name)){
   throw runtime_error("account already exists");
  }
  bank_account new_account;
  new_account.set_name(name);
  new_account.set_account_type(is_credit);
  new_account.set_balance(0);
  reg.push_back(new_account);
}

void registry::account_transaction(const string& name, double amount){
  fetch_account(name).set_balance(amount);
}

void registry::account_removal(const string& name){
  for(int i = 0; i < reg.size(); i++){
   if(reg.at(i).get_name() == name){
    if(reg.at(i).get_balance() >= 0){
     reg.erase(i);
      return;
    }
    else{
     throw runtime_error("account holds negative balance");
    }
   }
  }
  throw runtime_error("account does not exist");
}

void registry::print(){
  for(int i = 0; i < reg.size(); i++){
   if(reg.at(i).get_balance() < 0){
    cout << reg.at(i).get_name() << " owes " << - reg.at(i).get_balance() << " euros " << endl;
   }
   else{
    cout << reg.at(i).get_name() << " owns " <<  reg.at(i).get_balance() << " euros " <<endl;
   }
  }
}

int main(){
  ifstream inFS;
  string input;

  cout << "Enter the name of the records file: " << endl;
  cin >> input;

  inFS.open(input);

  if (!inFS.is_open()) {
   cout << "Could not open file " << input << endl;
  }

  registry bank;
  int line = 0;

  while(inFS){
   try{
    char type;
    string name;
    char is_credit;
    double amount;
    line++;

    inFS >> type >> name;
    if (!inFS) break;

    if (type == 'c') {
        inFS >> is_credit;
        bank.account_creation(name, is_credit == 'y');
    }

    else if (type == 't') {
        inFS >> amount;
        bank.account_transaction(name, amount);
    }

    else if (type == 'r') {
        bank.account_removal(name);
    }
   }

   catch (const runtime_error &excpt){
   cout << "error on line " << line << ": " << excpt.what() << endl;
   }
  }

  bank.print();

  inFS.close();

  return 0;
}