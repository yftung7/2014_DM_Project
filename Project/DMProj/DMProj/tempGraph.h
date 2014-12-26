#include<cstdlib>
#include<iostream>
#include"edge.h"
#include<fstream>
using namespace std;

#ifndef _GRAPH_H
#define _GRAPH_H

struct node
{
  int conn;
  double weight;
};


class Graph{

public:
  Graph();
  ~Graph();
  void init();
  void setWeight(int i, int j, int year, int conf, int paper);
  bool isLink(int i, int j);
  double getWeight(int i, int j);
protected:
  Edge edge[50000];
  ifstream infile;
  ofstream outfile;
  int row;
  int col;
  bool output;
};
#endif