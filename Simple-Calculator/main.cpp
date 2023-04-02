// Computer Programming 
// "Simple Calculator"
//
#include <iostream>
using namespace std;

int main()
{
  double num1,num2;
  char oper;
  
  cout << "Enter the expression: ";
  
  while(cin >> num1) {
    cin >> oper >> num2;
    switch (oper) {
    
      case '+':
        cout << num1 << " " << oper << " " << num2 << " = " << num1 + num2;
        break;
    
      case '-':
        cout << num1 << " " << oper << " " << num2 << " = " << num1 - num2;
        break;
    
      case '/':
        cout << num1 << " " << oper << " " << num2 << " = " << num1 / num2;
        break;
    
      case '*':
        cout << num1 << " " << oper << " " << num2 << " = " << num1 * num2;
        break;
    
      default:
        cout << " ";
        break;
    }
    
    cout << endl << "Enter the expression: ";
    
  }  
  return 0;
}
  