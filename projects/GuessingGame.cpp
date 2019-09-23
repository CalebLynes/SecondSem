#include <iostream>

using namespace std;

int main() {
  //count attempts
  int count = 0;
  
  //initialize random seed
  srand(time(NULL));

  //generate random number between 1 and 100
  int num = rand() % 100 + 1;
  
  cout << num << endl; 

  return 0;
}
