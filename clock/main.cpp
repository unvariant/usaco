#include <iostream>
#include <cinttypes>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main (int argc, char ** argv) {
    int n, h, m, inc;
    string tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int answer = 0;
        cin >> tmp >> inc;
        h = (tmp[0] - 0x30) * 10 + tmp[1] - 0x30;
        m = (tmp[3] - 0x30) * 10 + tmp[4] - 0x30;

        int time = lcm(1440, inc);

        int hours = h;
        int elapsed = 0;
        int minutes = m;
        while (elapsed != time) {
            int flip = (hours % 10 * 10) + hours / 10;
            if (flip == minutes) {
                answer++;
            }
            hours = (hours + (minutes + inc) / 60) % 24;
            minutes = (minutes + inc) % 60;
            elapsed += inc;
        }

        cout << answer << "\n";
    }

    return 0;
}