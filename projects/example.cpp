#include <iostream>

using namespace std;

int main()
{
  //---Formatting Output---
  /*float input = 1.20000;
  cout.setf(ios::fixed, ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << input << endl;
  //cout.unsetf(ios::showpoint);
  //cout << input;*/

  //---Conditions---
  int input = 0;
  cin >> input;
  //-if/else-
  if (input == 3 || input == 4)
  {
    cout << "You put in a 3 or a 4!" << endl;
    input++;
  }
  /*else if (input == 4)
  {
    cout << "You put in a 4!" << endl;
    }*/
  else {
    cout << "You didn't put in a 3" << endl;
  }
  //-switch-
  /*switch (input) {
  case 3: cout << "You put in a 3" << endl;
    break;
  case 4: cout << "You put in a 4" << endl;
    break;
  default: cout << "You put in something else" << endl;
  }*/
  cout << input << endl;
  return 0;
}
