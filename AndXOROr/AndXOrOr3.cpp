#include <cmath>
#include <cstdio>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nums[1001000];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, ret = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    stack<int> s;
    for (int i = 0; i < n; ) {
        if (s.empty() || s.top() < nums[i]) {
            s.push(nums[i++]);
        } else {
            int top = s.top();
            s.pop();
            ret = max(ret, top ^ nums[i]);
            if (!s.empty()) {
                ret = max(ret, top ^ s.top());
            }
        }
    }
    
    int top = s.top(); s.pop();
    while (!s.empty()) {
        ret = max(ret, top ^ s.top());
        top = s.top();
        s.pop();
    }
    
    cout << ret << endl;
    return 0;
}
