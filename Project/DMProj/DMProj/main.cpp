#include<cstdlib>
#include<iostream>
# include <fstream>
# include "edge.h"
#include <string>
#include"parameter.h"
#include <vector>
using namespace std;

Edge ** Graph;

double findPath(int s, int t){
  int BFSlimit = pBFSlimit;
  int pathWeight = 0;
  bool * visit = new bool[pNumAuthor];
  for (int i = 0; i < pNumAuthor; i++){
    visit[i] = false;
  }
  int * parent = new int[pNumAuthor];
  int * deep = new int[pNumAuthor];
  for (int i = 0; i < pNumAuthor; i++){
    deep[i] = 0;
  }
  vector<int> queue;
  int ts = s;
  queue.push_back(s);
  visit[s] = true;
  deep[s] = 0;
  while (!queue.empty()){
    ts = queue.back();
    if (deep[ts] >= BFSlimit)
      break;
    queue.pop_back();

    for (int i = 0; i < pNumAuthor; i++){
      if (Graph[ts][i].isLink()&&!visit[i]){
        queue.push_back(i);
        visit[i] = true;
        parent[i] = ts;
        deep[i] = deep[ts] + 1;
        if (i == t){
          visit[t] = false;
          int temp=t;
          double tWeight = 0;
          while (parent[temp] != s){
            tWeight += Graph[temp][parent[temp]].getWeight();
            temp = parent[temp];
          } // while
          pathWeight += tWeight / deep[t];
        } // if
      } // if
    } // for

  } // while


  return pathWeight;
}


int main(int argc, int * argv[]){


  ifstream infile;
  infile.open("CN1.txt");
  int tAuthor1 = 0;
  int tAuthor2 = 0;
  int tYear = 0;
  int tConf = 0;
  int tPaper = 0;
  Graph = new Edge*[pNumAuthor];
  for (int i = 0; i < pNumAuthor; i++){
    Graph[i] = new Edge[pNumAuthor];
  } // for

  if (!infile)
  {
    cout << "file in.txt not found!" << endl;
    return 0;
  } // if

  while (infile >> tAuthor1){
    infile >> tAuthor2;
    infile >> tYear;
    infile >> tConf;
    infile >> tPaper;
    Graph[tAuthor1][tAuthor2].setWeight(tYear, tConf, tPaper);
    Graph[tAuthor2][tAuthor1].setWeight(tYear, tConf, tPaper);
  }

  infile.close();
  infile.open("CN1_Q.txt");
  while (infile >> tAuthor1){
    infile >> tAuthor2;
    if (findPath(tAuthor1,tAuthor2) > pThreshold)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    
  }

  infile.close();

  system("pause");
  return 0;
}