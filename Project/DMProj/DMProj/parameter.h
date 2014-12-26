#include<cstdlib>
#include<iostream>
#include<sstream>

using namespace std;

#ifndef _PARAMETER_H
#define _PARAMETER_H

extern int pNumAuthor;
extern int pPredictYear;
extern double pYear;
extern double pConf;
extern double pPaper;
extern double pThreshold;
extern int pBFSlimit;



extern string d2str(double val);
extern string i2str(int val);
extern double str2d(string val);
extern int str2i(string val);


#endif