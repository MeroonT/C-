// Computer Programming 
// "Second smallest"
// 
#include <iostream>
#include <vector>
#include <stdexcept> 
using namespace std;

int min2(vector<int> numbersVec, int second_smallest, const int MAX);
	
int main()
{
	const int MAX = 99999;
	int number,second_smallest;
	vector<int> numbersVec;

	cout << "Enter the numbers in random order: (close by entering q)" << endl;

	while(cin>>number){
		numbersVec.push_back(number);
	}

	try {
		second_smallest = min2(numbersVec, second_smallest, MAX);

		if(second_smallest==MAX){ 
			throw runtime_error("error: no second smallest");
		}
	}
	catch(runtime_error& excpt)
	{ 
		cout << excpt.what() << endl;
		return 0;
	}
	cout << "The second smallest number is " << second_smallest << endl;

	return 0;
}

int min2(vector<int> numbersVec, int second_smallest, const int MAX){

	int smallest = MAX;
	second_smallest = smallest;

	 for(int i=0; i<numbersVec.size(); i++)
	 {
	 	 if(numbersVec.at(i)<smallest)
		 {
		 	second_smallest = smallest; 
		 	smallest=numbersVec.at(i); 
		 }
		 else if(numbersVec.at(i)<second_smallest && numbersVec.at(i) != smallest)
		 { 
			second_smallest=numbersVec.at(i); 
		 }
	}
	return second_smallest;
}