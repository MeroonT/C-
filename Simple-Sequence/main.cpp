// Computer Programming 
// "Simple Sequence"
// 
#include <iostream>
#include <vector>
using namespace std;

int main()
{

  double iterations,Term,i;
  
  vector<double> seq;
  
  cout << "Please enter the number of iterations:";
  cin >> iterations;
  
  cout << "Which term would you like to know:";
  cin >> Term;
  
  for(i = 1; i <= iterations; ++i){
    seq.push_back((2*i)-3);
  }
  cout << "The value of term " << Term << " is " << seq.at(Term - 1) << endl;
  cout << "The entire sequence up to " << iterations << " terms is " << " ";
  
  for(i = 0; i < iterations; ++i){
   cout << seq.at(i) << " ";
  }
 return 0;
}