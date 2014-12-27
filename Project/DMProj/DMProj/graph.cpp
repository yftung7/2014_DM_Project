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
  lastIndex = 0;
  output = false;
}
Graph::~Graph(){

  
}
void Graph::init(){
  row = -BLOCKSIZE;
  col = -BLOCKSIZE;
}


vector<Node> Graph::getVec(){
  return nodeList;
}

int Graph::findNode(int j){
  for (int i = 0; i < nodeList.size(); i++){
    if (nodeList.at(i).conn == j){
      return i;
    }
    
  } // for

  return -1;
}

void Graph::flush(){
  writeData(row, col);
}

void Graph::refine(){
  if (refined)
    return;
  
  vector<Node> temp(nodeList);
  nodeList.clear();
  for (int i = 0; i < temp.size(); i++){
    int tIn = findNode(nodeList.at(i).conn);
    if (tIn == -1){
      temp.push_back(temp.at(i));
    } // if
    else{
      nodeList.at(tIn).weight += temp.at(i).weight;
    }//else
  } // for
}


bool Graph::readData(int i , int j){
  //refined = false;
  string filename = "data/Graph_" + i2str(i) + ".glist";
  infile.open(filename.c_str());
  Node node;
  nodeList.clear();
  if (!infile)
    return false;
  //infile >> refined;
  while (infile >> node.conn){
    infile >> node.weight;
    nodeList.push_back(node);
  }
  infile.close();
  return true;
}

void Graph::writeData(int i, int j){
  //cout << "i " << i << endl;
  string filename = "data/Graph_" + i2str(i) + ".glist";
  outfile.open(filename.c_str());
  //outfile << refined << endl;
  for (int i = 0; i < nodeList.size(); i++){
    outfile << nodeList.at(i).conn <<" "<< nodeList.at(i).weight << endl;
  } // for


  outfile.flush();
  outfile.close();

}

void Graph::setWeight(int i, int j,int year, int conf, int paper){
  int tIndex = 0;


  Node tempNode;
  if (row == i || row==-BLOCKSIZE ){
    if (row == i&&col == j)
      tIndex = lastIndex;
    else {
      tIndex = findNode(j);
      lastIndex = tIndex;
    } // else
    if (tIndex == -1){
      tempNode.conn = j;
      tempNode.weight = pow(pYear, 2010 - year);
      nodeList.push_back(tempNode);
    } // if
    else {
      nodeList.at(tIndex).weight = nodeList.at(tIndex).weight + pow(pYear, 2010 - year);
    } //else
    output = true;
  }
  else {
    
    if (output){
      writeData(row, col);
      output = false;
    } // if

    readData(i, j);
    
    if (row == i&&col == j)
      tIndex = lastIndex;
    else {
      tIndex = findNode(j);
      lastIndex = tIndex;
    } // else
    if (tIndex == -1){
      tempNode.conn = j;
      tempNode.weight = pow(pYear, 2010 - year);
      nodeList.push_back(tempNode);
    } // if
    else {
      nodeList.at(tIndex).weight = nodeList.at(tIndex).weight + pow(pYear, 2010 - year);
    } //else

    output = true;
    //row = i, col = j;

  } // else

  row = i, col = j;
} // setWeight

bool Graph::isLink(int i, int j){
  bool nlink = false;

  int tIndex = 0;
 

  if (row == i){
    if (row == i&&col == j)
      tIndex = lastIndex;
    else {
      tIndex = findNode(j);
      lastIndex = tIndex;
    } // else
    if (tIndex == -1){
      nlink = false;
    } // if
    else {
      nlink = true;
    } //else
  } // if
  else {

    if (output){
      writeData(row, col);
      output = false;
    } // if

    if(readData(i, j)==false)
      return false;

    if (row == i&&col == j)
      tIndex = lastIndex;
    else {
      tIndex = findNode(j);
      lastIndex = tIndex;
    } // else
    if (tIndex == -1){
      nlink = false;
    } // if
    else {
      nlink = true;
    } //else


  } // else

  row = i, col = j;
  return nlink;

}

double Graph::getWeight( int i , int j){

  double nWeight = 0;
  int tIndex = 0;
 

  if (row == i){
    if (row == i&&col == j)
      tIndex = lastIndex;
    else {
      tIndex = findNode(j);
      lastIndex = tIndex;
    } // else
    if (tIndex == -1){
      nWeight=0;
    } // if
    else {
      nWeight = nodeList.at(tIndex).weight;
    } //else
  } // if
  else {

    if (output){
      writeData(row, col);
      output = false;
    } // if

    if (readData(i, j) == false)
      return 0;
    if (row == i&&col == j)
      tIndex = lastIndex;
    else {
      tIndex = findNode(j);
      lastIndex = tIndex;
    } // else

    if (tIndex == -1){
      nWeight = 0;
    } // if
    else {
      nWeight = nodeList.at(tIndex).weight;
    } //else


  } // else

  row = i, col = j;
  return nWeight;
}