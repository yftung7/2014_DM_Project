#include<cstdlib>
#include<iostream>
#include"graph.h"
#include"parameter.h"
#include<math.h>
#include<string>
#define BLOCKSIZE 50000
using namespace std;


Graph::Graph(){
  row = -BLOCKSIZE;
  col = -BLOCKSIZE;
  output = false;
}
Graph::~Graph(){
  if (edge != NULL){
    //delete edge;
  }
}
void Graph::init(){
  row = -BLOCKSIZE;
  col = -BLOCKSIZE;
}
void Graph::setWeight(int i, int j, int year, int conf, int paper){
  if (row == i && (col / BLOCKSIZE == j / BLOCKSIZE)){
    edge[j % BLOCKSIZE].calWeight(year, conf, paper);
    //row = i, col = j;
    output = true;
  }
  else {
    string filename = "data/matrix_" + i2str(row) + "_" + i2str(col / BLOCKSIZE) + ".matrix";
    if (output){
      outfile.open(filename.c_str());
      for (int i = 0; i < BLOCKSIZE; i++){
        outfile << edge[i].isLink() << " " << edge[i].getWeight() << endl;
      } // for
      outfile.flush();
      outfile.close();
      output = false;
    } // if

    filename = "data/matrix_" + i2str(i) + "_" + i2str(j / BLOCKSIZE) + ".matrix";
    infile.open(filename.c_str());
    for (int i = 0; i < BLOCKSIZE; i++){
      bool tLink = false;
      double tWei = 0;
      infile >> tLink >> tWei;
      edge[i].setLink(tLink);
      edge[i].setWeight(tWei);
    } // for

    edge[j % BLOCKSIZE].calWeight(year, conf, paper);
    output = true;
    //row = i, col = j;

  } // else

  row = i, col = j;
} // setWeight

bool Graph::isLink(int i, int j){
  bool nLink = false;
  if (row == i && (col / BLOCKSIZE == j / BLOCKSIZE)){
    nLink = edge[j%BLOCKSIZE].isLink();
  }
  else {
    string filename = "data/matrix_" + i2str(row) + "_" + i2str(col / BLOCKSIZE) + ".matrix";
    if (output){
      outfile.open(filename.c_str());
      for (int i = 0; i < BLOCKSIZE; i++){
        outfile << edge[i].isLink() << " " << edge[i].getWeight() << endl;
      } // for
      outfile.flush();
      outfile.close();
      output = false;
    } // if

    filename = "data/matrix_" + i2str(i) + "_" + i2str(j / BLOCKSIZE) + ".matrix";
    infile.open(filename.c_str());
    for (int i = 0; i < BLOCKSIZE; i++){
      bool tLink = false;
      double tWei = 0;
      infile >> tLink >> tWei;
      edge[i].setLink(tLink);
      edge[i].setWeight(tWei);
    } // for


    nLink = edge[j%BLOCKSIZE].isLink();
    //row = i, col = j;

  } // else



  row = i, col = j;
  return nLink;
}

double Graph::getWeight(int i, int j){

  double nWeight = 0;
  if (row == i && (col / BLOCKSIZE == j / BLOCKSIZE)){
    nWeight = edge[j%BLOCKSIZE].getWeight();
  }
  else {
    string filename = "data/matrix_" + i2str(row) + "_" + i2str(col / BLOCKSIZE) + ".matrix";
    if (output){
      outfile.open(filename.c_str());
      for (int i = 0; i < BLOCKSIZE; i++){
        outfile << edge[i].isLink() << " " << edge[i].getWeight() << endl;
      } // for
      outfile.flush();
      outfile.close();
      output = false;
    } // if

    filename = "data/matrix_" + i2str(i) + "_" + i2str(j / BLOCKSIZE) + ".matrix";
    infile.open(filename.c_str());
    for (int i = 0; i < BLOCKSIZE; i++){
      bool tLink = false;
      double tWei = 0;
      infile >> tLink >> tWei;
      edge[i].setLink(tLink);
      edge[i].setWeight(tWei);
    } // for


    nWeight = edge[j%BLOCKSIZE].getWeight();
    //row = i, col = j;

  } // else



  row = i, col = j;
  return nWeight;
}