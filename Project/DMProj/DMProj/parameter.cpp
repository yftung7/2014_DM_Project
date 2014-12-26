#include"parameter.h"
#include<string>


//Egde Weight =pow(pYear, standYear - year) + pConf*conf + pPaper*paper;
double pYear = 1; // coefficient of Year
double pConf = 0; // coefficient of Conference
double pPaper = 0; //coefficient of Paper

int pPredictYear=2010;
int pNumAuthor=175899; // # of Authors
int pBFSlimit = 3; // BFS Limit
double pThreshold=0.5; 



string d2str(double val){
  stringstream ss;
  ss << val;
  string temp;
  ss >> temp;
  return temp;

}

string i2str(int val){
  stringstream ss;
  ss << val;
  string temp;
  ss >> temp;
  return temp;

}

double str2d(string val){
  stringstream ss;
  ss << val;
  double temp;
  ss >> temp;
  return temp;

}

int str2i(string val){
  stringstream ss;
  ss << val;
  int temp;
  ss >> temp;
  return temp;

}