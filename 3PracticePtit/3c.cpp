#include <iostream>
using namespace std;

bool canPayExactAmount(int N) {
    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            if (4*x + 7*y == N) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    
    if (N >= 1 && N <= 200) {
        if (canPayExactAmount(N)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}