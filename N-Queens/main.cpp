// Computer Programming 
// "N-Queens"
// 
#include <iostream>
#include <vector>
using namespace std;

void print_board(const vector<vector<bool>>& board){
  
  for(int i = 0; i < board.size(); i++){
    for(int j = 0; j < board.size(); j++){
      if(board[i][j]){
       cout << "Q";
      }
      else{
       cout << ".";
      }
    }
   cout << endl;
  }
}

bool is_valid_position(const vector<vector<bool>>& board, int row, int col){
  
  if (row == 0){
   return true;
  }
  
  for(int i = 0; i <= row; i++){
   if(board[i][col]){
    return false;
   }
  }
  
  for (int i = 0; i < board.size(); ++i) {
   if ((row - i >= 0) && (col - i >= 0) && board[row - i][col - i]) {
    return false;
   }
   
   if ((row - i >= 0) && (col + i < board.size()) && board[row - i][col + i]) {
    return false;
   }
  }
  return true;
  
}

bool place_queens(vector < vector<bool>>& board, int queens, int current_row){
  
  if(queens == 0){
    return true;
  }
  
  for(int j = 0; j < board.size(); j++){
   if(is_valid_position(board, current_row, j)){
    board[current_row][j] = true;
    
    if (place_queens(board, queens - 1, current_row + 1)){
    return true;
    }
   }
   board[current_row][j] = false;
  }
  return false;
}

int main(){
  int n;

  try{
   cout << "How many queens to place on the board?";
   cin >> n;
   
   if(cin.fail() || n <= 0){
    throw runtime_error("error: invalid input");
   }
   
   vector<vector<bool>> board( n,  vector<bool>(n,false));
   
   if(place_queens(board, n, 0)) {
    print_board(board);
   } 
   else {
    cout << "No solution found to place " << n << " queens on a " << n << " by " << n << " chess board" << endl;
   }
  }
  
  catch (runtime_error &excpt){
    cout << excpt.what() << endl;
  }
  
  return 0;
}