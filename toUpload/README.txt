20150126 by Tung & Wu

Environment
any linux platform with g++ compiler and libSVM

Usage
1. concat CN3.txt and CN3_query.txt to a new file named CN3.txt
2. modify the CN3.txt such that it follows the format of original CN3.txt
3. "./run -y1.8 -d3 -f24" to produce feature.txt
4. use methods depicted in test4.sh to scale the feature.txt
5. call libSVM to train a model
6. "./run -y1.8 -d3 -f24 -te" to produce yTest.txt, the test data set
7. use the scaling parameter in 4. to scale yTest.txt
8. call libSVM to predict yTest.txt
9. modify the output to make it follows the desired output format
