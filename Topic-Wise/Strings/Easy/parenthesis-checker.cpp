// Problem Statement: https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x) {
        if (x.size() % 2 != 0)
            return false;

        stack<char> s;
        for (int i = 0; i < x.size(); i++) {
            if (s.empty())
                s.push(x[i]);
            else {
                char c = s.top();
                if ((c == '{' && x[i] == '}') || (c == '(' && x[i] == ')') || (c == '[' && x[i] == ']')) {
                    s.pop();
                }
                else {
                    s.push(x[i]);
                }
            }
        }

        if (!s.empty()) return false;
        return true;
    }
};