#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int isNaN(float f) {
    unsigned long x = *(unsigned long *) &f;
    return 0 != (x & 0x7ffffful) && 0x7f800000ul == (x & 0x7f800000ul);
}

string output_line, pout_line, input_line;

int main(int argc, char *argv[]) {

    //ifstream output(argv[2]);
    ifstream output("output");
    ifstream pout("user_output");
    ifstream iput("input");
    getline(iput, input_line);
    int n, m;
    stringstream s1(input_line);
    s1 >> n >> m;
    int line_no = 0, error_line_no = 0;
    char c, c1;
    int a, b, a1, b1;
    while (getline(output, output_line)) {
        getline(pout, pout_line);
        ++line_no;
        if (line_no <= m) {
            stringstream ss1(output_line);
            stringstream ss2(pout_line);
            ss1 >> c >> a >> b;
            ss2 >> c1 >> a1 >> b1;
            if (c != c1 || a != a1 || b != b1) {
                error_line_no = line_no;
            }
        } else {
            stringstream sfo(output_line);
            stringstream sfp(pout_line);
            double foutput, fpout;
            sfo >> foutput;
            sfp >> fpout;
            if (isNaN(fpout) && error_line_no == 0) {
                error_line_no = line_no;
            }
            // 浮点数的output规范是6位小数
            if (fabs(foutput - fpout) / max(1.0, fabs(foutput)) > 1e-6 && error_line_no == 0) {
                error_line_no = line_no;
            }
        }
    }

    while (error_line_no == 0 && getline(pout, pout_line)) {
        error_line_no = line_no - 1;
        break;
    }

    if (error_line_no > 0) {
        return 1;
    }
    return 0;
}
