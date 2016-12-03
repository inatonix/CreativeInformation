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
  string numSt; cin >> numSt;
  int result = 0;
  char mod; int modTransformed;
  rep(i,numSt.length()){
    mod = numSt[numSt.length() - 1 - i];
    modTransformed = (int)(mod - 'a');
    result += pow(8,i) * modTransformed;

  }

  cout << result << endl;
  return 0;
}
