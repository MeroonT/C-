// Computer Programming 
// "Run-length encoding"
// 
#include<iostream>
#include<vector>
using namespace std;

bool is_valid(const string input){
  for (int i = 0; i < input.size(); i++) {
   if ( !('a' <= input[i] && input[i] <= 'z')) 
    return false;
  }
  return true;
}
void compress(const string input, vector <int>& number, vector <char>& letters){ 
  int i = 0;
  int j = 0;
  number.push_back(1);
  letters.push_back(input.at(j));
  
  for (j = 1; j < input.size(); j++){
    if (input.at(j) == input.at(j - 1)){
      number.at(i) = number.at(i) + 1;
    }
    
    else {
      i++;
      number.push_back(i);
      number.at(i) = 1;
      letters.push_back(input.at(j));
    } 
  }
}

int main(){
  vector<int> number;
  vector<char> letters;
  string input;
  
  try{
   cout << "Enter the data to be compressed: " << endl;
   cin >> input;
   if (!is_valid(input)) {
    throw runtime_error("error: invalid input"); 
   }
   compress(input, number, letters);
   cout << "The compressed data is: ";
   for(int i = 0; i < number.size(); i++){
    cout << number[i] << letters[i];
   }  
  }  
  
  catch (runtime_error &excpt) {
         cout << excpt.what() << endl;
  }
  
  return 0;  
}