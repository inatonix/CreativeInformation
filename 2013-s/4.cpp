#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <cmath>
#include <set>
using namespace std;
#define rep(i,n) for(int i = 0; i < n ; i++)
#define pb push_back


int string_to_int(std::string str){
  int ret;
  std::stringstream ss;
  ss << str;
  ss >> ret;
  return ret;
}

float l(int n){
  float tmp = pow((float)1/3,n-1) * 10; cout << " l = " << tmp << endl;
  return tmp;
}

float h(float n){
  float tmp = (n / 2) * sqrt(3); cout << " h = " << tmp << endl;
  return tmp;
}

int amount(int n){
  int tmp = pow(4,n-1); cout << " amount = " << tmp << endl;
  return tmp;
}

int main() {
  int n; cin >> n;

  float total = 0;
  for(int i = 1; i <= n; i++){
    total += (float)1/2 * l(i) * h(l(i)) * amount(i);
    cout << "total = " << total << endl;
  }

  cout << total << endl;


  return 0;
}
