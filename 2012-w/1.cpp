#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <math.h>
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

//文字列を任意の文字で分割できる
//split("文字列","分解したい文字",入れる変数)
template <typename List>
void split(const std::string& s, const std::string& delim, List& result)
{
    result.clear();

    using string = std::string;
    string::size_type pos = 0;

    while(pos != string::npos )
    {
        string::size_type p = s.find(delim, pos);

        if(p == string::npos)
        {
            result.push_back(s.substr(pos));
            break;
        }
        else {
            result.push_back(s.substr(pos, p - pos));
        }

        pos = p + delim.size();
    }
}

void fileReader(string filename,vector<string> &vec){

  ifstream ifs(filename);
  string str;
  while(getline(ifs,str)){
    cout << "push" << " " <<str <<endl;
    vec.push_back(str);
  }
}


int main() {
  vector<string> file;
  fileReader("data.txt",file);
  int line_num = 0;

  vector<string> line;
  int x[30];int y[30];
  int max_y = 0;int max_line_num = 0;

  while(line_num < file.size()){
    split(file[line_num],",",line);
    x[line_num] = string_to_int(line[0].substr(1,2));
    y[line_num] = string_to_int(line[1].substr(0,line[1].size()-1));
  //  cout << x[line_num] << " " << y[line_num] << endl;

    if(y[line_num] > max_y){
       max_y = y[line_num];
       max_line_num = line_num;
     }

    line_num += 1;
  }

  cout << x[max_line_num] << " " << y[max_line_num] << endl;
  return 0;
}
