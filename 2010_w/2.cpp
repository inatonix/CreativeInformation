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
const static int MAX = 10001;


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

vector<int> Graph[MAX];
set<int> root;
vector<string> node;
set<int> node_set;

void rootAdd(int nodeNum){
  rep(i,Graph[nodeNum].size()){
    auto r = root.insert(Graph[nodeNum][i]);
    if(r.second) rootAdd(Graph[nodeNum][i]);
  }
}


int main() {
  vector<string> file;
  fileReader("a.txt",file);
  int line_num = 0;
  int intoNode[10001];
  rep(i,10001){
    intoNode[i] = 0;
  }
  root.insert(0);

  bool setFlag = false;
  bool rootFlag = false;

  int edgeCnt = 0;
  while(line_num < file.size()){
    split(file[line_num],"->",node);
    if(node[0].substr(0,1) == "!"){
      edgeCnt -= 2;
      rep(i,Graph[string_to_int(node[0])].size()){
        if(string_to_int(node[1]) == Graph[string_to_int(node[0])][i])
          Graph[string_to_int(node[0])].erase(Graph.begin() + i);
      }
    }


    Graph[string_to_int(node[0])].pb(string_to_int(node[1]));
    node_set.insert(string_to_int(node[0]));
    node_set.insert(string_to_int(node[1]));


    intoNode[string_to_int(node[1])] += 1;

    if(node_set.size() >= 1000 && !setFlag){
      setFlag = true;
      cout << "V >= 1000 になるt は  " << line_num + 1 << endl;
    }

    if(!rootFlag){
      for(auto itr = root.begin(); itr != root.end(); ++itr) {
      //  cout << *itr << endl;
        if(*itr == string_to_int(node[0])){
          auto r = root.insert(string_to_int(node[1]));
          if(r.second) rootAdd(string_to_int(node[1]));
        }
      }
    }

    if(root.size() >= 1000 && !rootFlag){
      rootFlag = true;
      cout << "R >= 1000になるtは  " << line_num + 1 << endl;
    }
    edgeCnt += 1;
    line_num += 1;
  }

  cout << "nodeの数は " << node_set.size() << endl;
  int max_outNode = 0; int max_outNode_i;
  int max_intoNode = 0;int max_intoNode_i;
  rep(i,10001){
    if(Graph[i].size() > max_outNode) {
      max_outNode = Graph[i].size();
      max_outNode_i = i;
    }
    if(intoNode[i] > max_intoNode){
      max_intoNode = intoNode[i];
      max_intoNode_i = i;
    }
  }
  cout << "最大出次頂点は " << max_outNode_i;
  cout << "頂点数は　" << max_outNode << endl;

  cout << "最大入次頂点は " << max_intoNode_i;
  cout << "頂点数は　" << max_intoNode << endl;

  return 0;
}
