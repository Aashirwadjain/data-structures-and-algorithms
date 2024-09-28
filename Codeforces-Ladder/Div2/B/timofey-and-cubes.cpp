// Problem Statement: https://codeforces.com/problemset/problem/764/B

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n] = {0};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (i < n - i - 1 && flag % 2 == 0) {
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
        flag++;
        cout << arr[i] << " ";
    }

    return 0;
}