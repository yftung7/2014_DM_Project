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
  //cout << graph.getWeight(s, t)<<endl;
  int BFSlimit = pBFSlimit;
  double pathWeight = 0;
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
    
    graph.readData(ts, t);
    vector<Node> tempVec (graph.getVec());
    for (int i = 0; i < tempVec.size(); i++){
      
      
      if (!visit[tempVec.at(i).conn]){
        
        visit[tempVec.at(i).conn] = true;
        parent[tempVec.at(i).conn] = ts;
        deep[tempVec.at(i).conn] = deep[ts] + 1;
        
        if (tempVec.at(i).conn == t){
          
          //cout << "vec: " << ts << " " << tempVec.at(i).conn << " " << tempVec.at(i).weight << endl;
          //cout << "ts " << ts << "deep[ts]" << deep[ts] << " deep[t]" << deep[t] << endl;
          visit[t] = false;
          int temp=t;
          double tWeight = 0;
          if (parent[temp] == s)
            tWeight += graph.getWeight(temp, parent[temp]);
          
          
          while (parent[temp] != s){
            
            tWeight += graph.getWeight(temp,parent[temp]);
            temp = parent[temp];
          } // while
          
          pathWeight += tWeight / deep[t];
        } // if(tempvec)
        else 
          queue.push_back(tempVec.at(i).conn);
      } // if(!visit)
    } // for

   
  } // while


  return pathWeight;
}


int main(int argc, int * argv[]){


  ifstream infile;
  
  int tAuthor1 = 0;
  int tAuthor2 = 0;
  int tYear = 0;
  int tConf = 0;
  int tPaper = 0;
  
  ofstream outfile;
  string filename="Cquery.txt";

  
  graph.clear();

  infile.open("Ctest.txt");
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
  //infile.open(filename.c_str());
  if (!infile)
  {
    cout << "file in.txt not found!" << endl;
    system("pause");
    return 0;
  } // if




  //cout << "StratReadQ" << endl;
  while (infile >> tAuthor1){
    
    infile >> tAuthor2;
    cout << "weight " << findPath(tAuthor1, tAuthor2) << endl;
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