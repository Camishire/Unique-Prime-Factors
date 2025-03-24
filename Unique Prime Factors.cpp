#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> Pirmin(long long max) {
    vector<long long> p;
    for (long long i = 2; i <= max; i++) p.push_back(i);

    for (long long i = 0; i < p.size(); i++) {
        long long pirminis = p[i];
        for (long long j = i + 1; j < p.size(); j++) {
            if (p[j] % pirminis == 0) {
                p.erase(p.begin() + j);
                j--;
            }
        }
    }

    return p;
}


int faktorialuKiekis(long long z, const vector<long long>& pirminiai) {
    int c = 0;
    for (long long p : pirminiai) {
        if (p * p > z) break;
        if (z % p == 0) {
            c++;
            while (z % p == 0) z /= p;
        }
    }
    if (z > 1) c++;
    return c;
}

int main() {
    long long n, k, c;
    long long maxel = 0;
    long long maxdal = 0;
    cin >> n >> k;

    if (k - n <= 1500000) c = (((k - n) * 0.75) + n);
    else c = (((k - n) * 0.89) + n);

    vector<long long> pirminiai = Pirmin(sqrt(k));

    for (long long i = k; i >= c; i--) {
        long long dal = faktorialuKiekis(i, pirminiai);
        if (dal > maxdal) {
            maxdal = dal;
            maxel = i;
        }
    }
    if (maxel == 0) cout << k;
    else cout << maxel;

    return 0;
}