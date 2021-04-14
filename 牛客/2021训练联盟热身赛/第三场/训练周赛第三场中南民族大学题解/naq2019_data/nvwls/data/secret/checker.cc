#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

string output_line, input_line, pout_line;
string origion, buf, New;
unordered_map<string, bool> dic;

int main(int argc, char *argv[]) {
    //ifstream output(argv[2]);
    ifstream input("input");
    ifstream output("output");
    ifstream pout("user_output");

    int n = 0;
    
    // 字典映射到map中
    int cnt = 0;
    while (getline(input, input_line)) {
        ++cnt;
        if (cnt == 1) {
            for (int i = 0; i < input_line.size(); i++) 
                n = n * 10 + input_line[i] - '0';
            n++;    
        }
        if (cnt >= 2 && cnt <= n) {
            dic[input_line] = 1;
        } else if (cnt > n) origion = input_line;
    }
    //得到输入的答案中含有多少个元音字母
    getline(output, output_line);
    int sum = 0;
    for (int i = 0; i < output_line.size(); i++) {
        if (isalpha(output_line[i]) &&
            (output_line[i] == 'A' || output_line[i] == 'E' || output_line[i] == 'I' || output_line[i] == 'O' ||
             output_line[i] == 'U'))
            sum++;
    }

    //判断答案
    cnt = 0;
    bool error = 0;
    getline(pout, pout_line);
    New = "";
    for (int i = 0; i < pout_line.size(); i++) {
        if (isalpha(pout_line[i])) {
            if (pout_line[i] != 'A' && pout_line[i] != 'E' && pout_line[i] != 'I' && pout_line[i] != 'O' &&
                pout_line[i] != 'U')
                New += pout_line[i];
            else cnt++;
        }
    }
    if (New == origion && cnt == sum) {
        stringstream ss(pout_line);
        while (ss >> buf) {
            if (!dic.count(buf)) {
                error = 1;
                break;
            }
        }
    } else error = 1;
    if (error) return 1;
    return 0;
}
