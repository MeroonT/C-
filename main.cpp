// Computer Programming, XB_40011, Fall 2018
// Vrije Universiteit, Amsterdam
//
// (GRADED) Assignment 2.4 "Quadratic Formula"
// 
// Submit this assignment to Canvas!
// By doing so you declare to comply to the regulations as stated
// on the page on "Ethical behaviour and fraud" in the course's
// Canvas site.
//
// Student name   : Meroon tesfai keleta  
// Student number : 2646691
// VUnet-id       : mel450
//
// Fill in your details above,
// then enter your code below this header.
//
#include <iostream>
#include <cmath>
using namespace std;

double delta(double a, double b, double c){
    return b * b - 4 * a * c; 
}
double sol1(double a, double b, double deltaValue){
  return (-b + sqrt(deltaValue)) / (2 * a);
}
double sol2(double a, double b, double deltaValue){
  return  (-b - sqrt(deltaValue)) / (2 * a);
}
  
int main()
{
  double a, b, c, deltaValue; 

  cout << "Please enter the values of a, b, and c respectively:";
  cin >> a >> b >> c;
  
  deltaValue = delta(a, b, c);
  
  if(deltaValue > 0) {
   cout << "There are 2 solutions." << endl;
  cout << "The solutions are: " << sol1(a, b, deltaValue) << " and " << sol2(a, b, deltaValue); 
  }
  else if (deltaValue == 0){
   cout << "There is 1 solution." << endl;
  cout << "The solution is: " << sol1(a, b, deltaValue);
  }
  else {
   cout << "There is no solution.";
  }    
  return 0;  
}