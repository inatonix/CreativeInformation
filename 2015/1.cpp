#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <set>
using namespace std;
#define rep(i,n) for(int i = 0; i < n ; i++)
#define pb push_back

int getDigit(int num){
  return log10(num) + 1;
}

int main() {
  int a; cin >> a;
  int result = 0;
  int mod;
  cout << getDigit(a) << endl;
  for(int i = 0; i < getDigit(a)+2; i++){
    mod = a % 10;
    result += pow(4,i) * mod;
    cout << "result = " << result << endl;
    a = a / 10;
    cout << a << endl;
  }
  cout << result << endl;
  
  return 0;
}
