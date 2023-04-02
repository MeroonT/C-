// Computer Programming 
// "Quadratic Formula"
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