#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>

using namespace std;

int main() {
  char str[80];
  cin.get(str, 80);
  cin.get();
  
  cout << str << endl;
  int len = strlen(str);
  for(int i=0;i<len;i++) {
    putchar(tolower(str[i]));
  }
  
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] > 96 && str[i] < 123) {
      str[count++] = str[i];
    }
  }
  str[count] = '\0';

  cout << str << endl;
    
  return 0;
}
