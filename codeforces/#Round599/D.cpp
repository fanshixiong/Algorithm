#include<bits/stdc++.h>
using namespace std;
bool f(int a[], int val){
    for(int i = 3; i > 0; i--) { //故障
        if(a[i] == val)
            return true;
    }
    return false;
 } 

int main(){
    int a[4] = {0, 1, 2};
    f(a, 3); //没有产生error
    f(a, 3); //产生error，没有出现failure
    f(a, 0); //产生error，并且产生failure
    return 0;
}