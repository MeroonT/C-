// Computer Programming, XB_40011, Fall 2018
// Vrije Universiteit, Amsterdam
// 
// (Ungraded) Assignment 4.2 "bubble sort"
// 
// Get this assignment accepted by your teaching assistant!
// (Do not submit this assignment to Canvas.)
//
// Student name   : Meroon tesfai
// Student number : 2646691
// VUnet-id       : mel450
//
// Fill in your details above,
// then enter your code below this header.
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


void BubbleSort(vector<int>& Input){
  int temp;
  
  for(int i = 0; i < Input.size(); i++){  
    for(int j = 0; j < Input.size() - 1; j++){  
     if (Input.at(j) > Input.at(j + 1)){
       temp = Input.at(j);
       Input.at(j) = Input.at(j + 1);
       Input.at(j + 1) = temp;
     }
    }
  }
}

int main(){

 int Input;
 
  try{
  cout << "Please enter the number of elements:";
  cin >> Input;
   if (cin.fail()){
    throw runtime_error ("error: Invalid");
   }

  vector<int> ListInput(Input); 
    
  cout << "Enter the list to be sorted:";
  for (int i = 0; i < ListInput.size(); i++) {  
   cin >> ListInput.at(i);
   if (cin.fail()){
    throw runtime_error ("error: Invalid");
   }
  }
  
  BubbleSort(ListInput);
  
  cout << "The sorted list is: ";
   for(int i = 0; i < ListInput.size(); i++){
    cout << ListInput.at(i) << " ";
   } 
}
  catch(runtime_error &excpt){
    cout << excpt.what() << endl;
  }
  
  return 0;
}
