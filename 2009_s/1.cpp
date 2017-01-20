#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <set>
#include <map>
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

void fileReader(string filename,vector<string> &vec){

  ifstream ifs(filename);
  string str;
  while(getline(ifs,str)){
    cout << "push" << " " <<str <<endl;
    vec.push_back(str);
  }
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


int main() {
  vector<string> rectangles;
  string filename = "10.txt";
  fileReader(filename,rectangles);

  int map[100][100][2];
  rep(i,100){
    rep(j,100){
      map[i][j][0]= 0;
      map[i][j][1] = 0;
    }
  }

  int line_num = 0;
  int x,y,w,h;
  vector<string> pos;
  bool clasteredFlag = false;
  int clasterNum = 0;
  int max_thick = 0;
  vector<int> clasters[1000];
  int claster_cnt = 0;

  int axis_x[100][2]; int axis_y[100][2];

  while(line_num < rectangles.size()){
    split(rectangles[line_num]," ",pos);
    x = string_to_int(pos[0]);
    y = string_to_int(pos[1]);
    w = string_to_int(pos[2]);
    h = string_to_int(pos[3]);
    clasteredFlag = false;



    rep(i,w){
      rep(j,h){
        map[x+i][y+j][0] += 1;

        if(!clasteredFlag){
          if(j == 0){
            if(map[x+i][y-1][0] >= 1){
              clasteredFlag = true;
              clasterNum = map[x+i][y-1][1];
            }
          }

          if(j == h - 1){
            if(map[x+i][y+j+1][0] >= 1){
              clasteredFlag = true;
              clasterNum = map[x+i][y+j+1][1];
            }
          }

          if(i == 0){
            if(map[x-1][y+j][0] >= 1){
              clasteredFlag = true;
              clasterNum = map[x-1][y-1][1];
            }
          }

          if(i == w - 1){
            if(map[x+i+1][y+j][0] >= 1){
              clasteredFlag = true;
              clasterNum = map[x+i+1][y+j][1];
            }
          }
        }


        if(map[x+i][y+j][0] > max_thick)
          max_thick = map[x+i][y+j][0];


        map[x+i][y+j][1] += line_num;
      }
    }


    cout << "line_num = " << line_num << endl;
    if(clasteredFlag){
      cout << "clasterNum = " << clasterNum << endl;
      rep(i,claster_cnt+1){
        rep(j,clasters[i].size()){
          //search for exsisted claster
          cout << clasters[i][j] << endl;
          if(clasterNum == clasters[i][j]){
            clasters[i].pb(line_num);
            cout << "same claster" << endl;
            break;
          }
        }
      }
    }else{
      //new claster added
      clasters[claster_cnt].pb(line_num);
      cout << "different claster" << endl;
      claster_cnt += 1;
    }

    line_num += 1;
  }

  rep(j,30){
    rep(i,30){

      cout << map[i][j][0] << " ";
    }
    cout << endl;
  }

  cout << "暑さの最大は " << max_thick << endl;
  cout << "クラスタの数は " << claster_cnt << endl;

  int max_claster_factors = 0;;
  rep(i,claster_cnt){
    if(clasters[i].size() > max_claster_factors)
      max_claster_factors = clasters[i].size();
  }

  cout << "要素数の最大は " << max_claster_factors << endl;

  return 0;
}
