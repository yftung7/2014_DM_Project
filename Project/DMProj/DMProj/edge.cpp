#include<cstdlib>
#include<iostream>
#include"edge.h"
#include"parameter.h"
#include<math.h>
using namespace std;


Edge::Edge(){

  linked = false;
  weight = 0;
}
Edge::~Edge(){}
void Edge::init(){
  linked = false;
  weight = 0;
}
void Edge::calWeight(int year, int conf, int paper){
  linked = true;
  int standYear = pPredictYear;
  weight = weight +  pow(pYear, standYear - year) + pConf*conf + pPaper*paper;
}

bool Edge::isLink(){
  return linked;
}
double Edge::getWeight(){
  return weight;
}
void Edge::setWeight(double n_weight){
  weight = n_weight;
}

void Edge::setLink(bool link){
  linked = link;
}