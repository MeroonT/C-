// Computer Programming
// "Permutation anc Combination"
// 
#include <iostream>
#include<stdexcept>
#include <cctype>
using namespace std;

long factorial(int n){
  long result;
  if (n <= 1){
    result = 1;
  }
  else {
    result = n * factorial(n - 1);
  }
  return result;
}
long Permutation(int Num1, int Num2){
  long result;
  result = factorial(Num1) / (factorial(Num1 - Num2));
  return result;
}
bool check(int Num1, int Num2){
  if((Num1 >= Num2) && (Num2 >= 0)){
   return true;
  }
  return false;
}
int main(){
  int Num1,Num2;
  long perm, combination;
  char operation;
  
  try{
   cout << "Enter two integers:" << endl;
   cin >> Num1 >> Num2;
   if(cin.fail()){
     throw runtime_error("error: invalid input, int only");
   }
   else{
    if (!check(Num1,Num2)){
     throw runtime_error("error: invalid input, a >=b >= 0");
    }
   }
   
   cout << "Please enter 'p' for permutation or 'c' for combination:" << endl;
   cin >> operation;
   
   if (operation == 'p'){
    perm = Permutation(Num1,Num2);
    cout << "permutations of " << Num1 << " and " << Num2 << " = " << perm; 
   }
   else if (operation == 'c'){
    combination = Permutation(Num1,Num2) / factorial(Num2);
    cout << "combinations of " << Num1 << " and " << Num2 << " = " << combination;
   }
   else {
    throw runtime_error("error: invalid input: p or c");
   }
  }
  catch (runtime_error& excpt) {
         cout << excpt.what() << endl;
  }
  return 0;
}