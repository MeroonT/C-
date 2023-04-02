// Computer Programming
// "Rectangle"
// 
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int length, width ,perimeter, area;
  double diagonal;
  
  cout << "Please enter the length and width of the rectangle: ";
  cin >> length >> width;
  
  perimeter = 2 * (length + width);
  area = width * length;
  diagonal = sqrt(length * length + width * width);
 
  cout << "The perimeter: " << perimeter << " " << "area: " << area << " " << "and diagonal: " << diagonal;
  cout << endl;
  
  return 0;
}