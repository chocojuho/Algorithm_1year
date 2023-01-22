#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double e = 0;

int main()
{
    ofstream fout;
    fout << fixed;
    fout.precision(100);
    fout.open("e.txt");
    for (long long i = 1; i < 40; i++) {
        e += 1 / tgamma(i);
        fout << e << endl;
    }
}