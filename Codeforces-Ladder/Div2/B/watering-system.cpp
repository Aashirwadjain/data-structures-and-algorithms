// Problem Statement: https://codeforces.com/contest/967/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, a, b;
    cin >> n >> a >> b;

    int arr[n] = {0};
    int sumOfNonBlocked = 0;
    int numOfBlocked = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sumOfNonBlocked += arr[i];
    }

    sort(arr + 1, arr + n, greater<int>());

    if (arr[0] * a * 1.0 / sumOfNonBlocked >= b) {
        cout << numOfBlocked;
    }
    else {
        for (int i = 1; i < n; i++) {
            sumOfNonBlocked -= arr[i];
            numOfBlocked++;
            if (arr[0] * a * 1.0 / sumOfNonBlocked >= b) {
                cout << numOfBlocked;
                break;
            }
        }
    }

    return 0;
}