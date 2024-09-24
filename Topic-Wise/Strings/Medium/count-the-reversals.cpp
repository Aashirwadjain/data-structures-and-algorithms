// Problem Statement: https://www.geeksforgeeks.org/problems/count-the-reversals0401/1

#include <bits/stdc++.h>
using namespace std;

int countRev(string str) {

    if (str.size() % 2 != 0) {
        return -1;
    }

    int count = 0;
    stack<char> s;

    for (int i = 0; i < str.size(); i++) {
        if (s.empty()) {
            s.push(str[i]);
        }
        else {
            char c = s.top();
            if (c == '{' && str[i] == '}') {
                s.pop();
            }
            else {
                s.push(str[i]);
            }
        }
    }

    while (!s.empty()) {
        char c = s.top();
        s.pop();

        if (s.top() == '}' && c == '{') count += 2;
        else    count++;

        s.pop();
    }

    return count;
}