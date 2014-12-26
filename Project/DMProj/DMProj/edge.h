#include<cstdlib>
#include<iostream>
using namespace std;

#ifndef _EDGE_H
#define _EDGE_H

class Edge{
public:
  Edge();
  ~Edge();
  void init();
  void calWeight(int year,int conf, int paper);
  void setWeight(double n_weight);
  void setLink(bool link);
  bool isLink();
  double getWeight();
protected:
  bool linked;
  double weight;

};
#endif