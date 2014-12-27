#include<cstdlib>
#include<iostream>
#include"edge.h"
#include<fstream>
#include <vector>
using namespace std;

#ifndef _GRAPH_H
#define _GRAPH_H

struct Node
{
  int conn;
  double weight;
};


class Graph{

public:
  Graph();
  ~Graph();
  void init();
  void setWeight(int i ,int j ,int year, int conf, int paper);
  bool isLink(int i, int j);
  double getWeight(int i , int j);
  void readData(int i, int j);
  void writeData(int i, int j);
  int findNode(int j);
  void refine();
  void flush();
  vector<Node> getVec();
protected:
  //Edge edge[50000];
  vector<Node> nodeList;
  ifstream infile;
  ofstream outfile;
  int row;
  int col;
  int lastIndex;
  bool output;
  bool refined;
};
#endif