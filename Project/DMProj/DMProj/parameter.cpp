#include"parameter.h"



//Egde Weight =pow(pYear, standYear - year) + pConf*conf + pPaper*paper;
double pYear = 1; // coefficient of Year
double pConf = 1; // coefficient of Conference
double pPaper = 1; //coefficient of Paper

int pPredictYear=2010;
int pNumAuthor=10; // # of Authors
int pBFSlimit = 3; // BFS Limit
double pThreshold=0.8; 