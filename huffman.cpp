#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <tuple>

#include "ApperanceNum.hpp"
#include "InitHaffmanTree.hpp"
#include "MakeHuffmanTree.hpp"
using namespace std;


int main(){
    string input;
    ifstream InputFile("input.txt");
    InputFile >> input;
    // cout << input << endl;
    InputFile.close();

    map<char, int> AppNum;
    vector<pair<int, char>> AppNumpair;
    ApperanceNum(input, AppNum, AppNumpair);
    
    int InitNodeNum = AppNum.size();

    vector<tuple<int, int, vector<int>, string>> T(InitNodeNum*2-1); //ノード番号、出現回数の合計、子ノード番号の配列、割り当てる符号
    InitHaffmanTree(AppNumpair, T);


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> Pque;
    MakeHuffmanTree(Pque, T, InitNodeNum);


    return 0;
}