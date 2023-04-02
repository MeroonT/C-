// Computer Programming, XB_40011, Fall 2018
// Vrije Universiteit, Amsterdam
//
// (Ungraded) Assignment 5.2 "Towers of Hanoi"
// 
// Get this assignment accepted by your teaching assistant!
// (Do not submit this assignment to Canvas.)
//
// Student name   : Meroon tesfai keleta sengal
// Student number : 2264691
// VUnet-id       : mel450
//
// Fill in your details above,
// then enter your code below this header.
//
#include <iostream>
#include <string>
using namespace std;

void Hanoi(int Num, char first, char second, char third){
  if(Num == 1){
    cout << "Move disk 1 from " << first << " to " << third << endl;
    return;
  }
  
  Hanoi(Num - 1, first, third, second);
  cout << "Move disk " << Num << " from " << first << " to " <<  third  << endl;
  Hanoi(Num - 1, second, first, third);
}

int main(){ 
char A = 'A';
char B = 'B';
char C = 'C';
int inputDisks;
  
  try{
   cout << "How many disks should the tower consist of?";
   cin >> inputDisks;
   if (cin.fail() || inputDisks <= 0){
    throw runtime_error("invalid input.");
   }
   Hanoi(inputDisks,A,B,C);
  }
  
  catch (runtime_error& excpt) {
  cout << excpt.what() << endl;
  }
  return 0;
}