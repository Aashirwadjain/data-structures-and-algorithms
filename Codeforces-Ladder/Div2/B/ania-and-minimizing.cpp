// Problem Statement: https://codeforces.com/problemset/problem/1230/B

#include <iostream>
using namespace std;

int main() {

    long long int n, k;
    cin >> n >> k;

    char c;
    int arr[n] = {0};

    for (int i = 0; i < n; i++) {
        cin >> c;
        arr[i] = c - '0';
    }

    if (n == 1 && k > 0) {
        cout << 0;
        return 0;
    }

    int one = k == 0 ? 0 : 1;
    int zero = k == 0 ? 0 : k - 1;
    for (int j = 0; j < n; j++) {
        if (one > 0) {
            if (arr[j] == 1) {
                zero++;
            }
            else {
                arr[j] = 1;
            }
            one--;
        }
        else if (zero > 0) {
            if (arr[j] != 0) {
                arr[j] = 0;
                zero--;
            }
        }
        cout << arr[j];
    }

    return 0;
}