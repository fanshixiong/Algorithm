
#include"getFirFol.cpp"
#include"LL.cpp"
#include<iostream>
#include<string>
#include<queue>
#include<fstream>
using namespace std;

int main(){
    string ts="test1\\terminalSymbol.ll";
    string nts="test1\\nonTerminalSymbol.ll";
    string rl = "test1\\rule.ll";
    string path="test1\\input1.ll";
    getFirst_Follow gff(ts,nts,rl);
    gff.getFirst();
    gff.getFollow();
    LL ll(&gff,ts,nts,rl);
    ll.fillInTheTable();
    ll.analyzeChars(path);
    system("pause");
    return 0;
}