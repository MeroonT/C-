// Computer Programming 
// "Stack"
// 
#include<iostream>
#include<vector>
using namespace std;

class property {
  private:
   vector<int> elements;
  public:
   bool isEmpty() {return (elements.size() > 0) ? false : true;}
   int peek();
   int pop();
   void push(int);
};

int property::peek() {
  if(!isEmpty()){
   return elements.at(elements.size() - 1);
  }
  else{
   throw runtime_error("Stack is empty");
  }
}

int property::pop(){
  int temp;
  if(!isEmpty()){
   temp = elements.back();
   elements.pop_back();
  }
  else{
   throw runtime_error("Stack is empty");
  }  
  return temp;
}

void property::push(int x){
  elements.push_back(x);
}

int main(){
 property stack;
 string input ;
  try{
    cin >> input;
    if(cin.fail()){
      c
    }
    
  }
  
  catch(runtime_error &excpt){
   cout << excpt.what() << endl;
  }
  
  return 0;
}