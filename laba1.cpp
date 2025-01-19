#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float c = 299792.0f;
    float m0 = 1.675;
    float v[] = {50000.0f, 100000.0f, 150000.0f, 200000.0f, 250000.0f, 260000.0f, 270000.0f, 280000.0f, 290000.0f};
    float m;

    for (int i = 0; i < 9; i++) {
        m = m0 / sqrt(1 - pow(v[i] / c, 2));
        cout << v[i] << "    " << (int)(m * 1000) / 1000.0f << endl;
    }

    return 0;
}
