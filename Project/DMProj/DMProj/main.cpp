#include<cstdlib>
#include<iostream>
# include <fstream>
# include "edge.h"
#include <string>
#include"parameter.h"
#include"graph.h"
#include <vector>
#define BLOCKSIZE 500
using namespace std;

Graph graph;

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

    vector<Node> tempVec (graph.getVec());
    for (int i = 0; i < tempVec.size(); i++){
      if (!visit[tempVec.at(i).conn]){
        queue.push_back(tempVec.at(i).conn);
        visit[tempVec.at(i).conn] = true;
        parent[tempVec.at(i).conn] = ts;
        deep[tempVec.at(i).conn] = deep[ts] + 1;
        if (tempVec.at(i).conn == t){
          visit[t] = false;
          int temp=t;
          double tWeight = 0;
          while (parent[temp] != s){
            tWeight += graph.getWeight(temp,parent[temp]);
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
  infile.open("Ctest.txt");
  int tAuthor1 = 0;
  int tAuthor2 = 0;
  int tYear = 0;
  int tConf = 0;
  int tPaper = 0;
  
  ofstream outfile;
  string filename;



  for (int i = 0; i < pNumAuthor; i++){
    for (int j = 0; j < pNumAuthor / BLOCKSIZE; j = j + BLOCKSIZE){
      filename = "data/matrix_" + i2str(i) + "_" + i2str(j / BLOCKSIZE)+".matrix";
      outfile.open(filename.c_str());
      for (int q = 0; q < pNumAuthor; q++){
        outfile << 0 << " " << 0 <<endl;
      } // for
      outfile.flush();
      outfile.close();
    } // for
  } // for

  
 
  if (!infile)
  {
    cout << "file in.txt not found!" << endl;
    return 0;
  } // if

  //cout << "StratRead" << endl;
  while (infile >> tAuthor1){
    infile >> tAuthor2;
    infile >> tYear;
    infile >> tConf;
    infile >> tPaper;
    graph.setWeight(tAuthor1, tAuthor2, tYear, tConf, tPaper);
    graph.setWeight(tAuthor2, tAuthor1, tYear, tConf, tPaper);
  } // while


  graph.flush();

  infile.close();
  infile.open("Cquery.txt");
  //cout << "StratReadQ" << endl;
  while (infile >> tAuthor1){
    infile >> tAuthor2;
    cout << findPath(tAuthor1, tAuthor2) << endl;
    /*
    if (findPath(tAuthor1,tAuthor2) > pThreshold)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    */
  }

  infile.close();

  system("pause");
  return 0;
}