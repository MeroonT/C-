// Computer Programming 
// "Matrix-vector multiplication"
// 
#include <iostream>
#include <vector> 

using namespace std;

vector<double> result (vector<vector<double>> matrix, vector<double> vecCoef) {
  vector<double> vecResult(3);
  
  for(int i = 0; i < 3; ++i) {
    
    for(int j = 0; j < 3; ++j){
      
      vecResult.at(i) +=matrix.at(i).at(j) * vecCoef.at(j);
    }
  }
  return vecResult;
  
}

int main() {
  
  vector < vector<double> > matrix (3);
  vector<double>vecCoef(3), vecResult(3);
  
  cout << "Please enter the three vector coefficients" << endl;
  cin >> vecCoef.at(0) >> vecCoef.at(1) >> vecCoef.at(2);
   
  matrix = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}}; 
   
  cout << "The result vector is ["; 
  vecResult = result(matrix, vecCoef);
  

  
  for(int i = 0; i < 3; ++i){
     (i == 2) ? cout << vecResult.at(i) << "]"<< endl : cout << vecResult.at(i) << ", ";
    
  }
  
  return 0; 
}