#include <iostream>
#include <time.h>
#include <chrono>
#include <vector>

using namespace std;
chrono::time_point<chrono::system_clock>start;
chrono::time_point<chrono::system_clock> endt;
chrono::duration<float> elapsed;

void findPrimes(int limit) {
    if (limit < 2) return;

   
    vector<bool> isPrime(limit / 2, true);
    isPrime[0] = false;

    for (int i = 3; i * i <= limit; i += 2) {
        if (isPrime[i / 2]) {
            for (int j = i * i; j <= limit; j += 2 * i) {
                isPrime[j / 2] = false;
            }
        }
    }

    cout << 2 << " ";

    for (int i = 1; i < isPrime.size(); ++i) {
        if (isPrime[i]) {
            cout << (2 * i + 1) << " ";
        }
    }
    cout << endl;
}

int main() {

    start = chrono::system_clock::now();
    int limit = 1000000;
    cout << "Prime numbers between 1 and " << limit << " are:" << endl;
    findPrimes(limit);
    endt = chrono::system_clock::now();
    elapsed = endt - start;
    cout << "Time to complete task:" << elapsed.count() << endl;
    return 0;
}
