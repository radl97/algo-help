// Sorozatok - tolerancia
#include <bits/stdc++.h>

using namespace std;

template <typename F = less<int>>
class MinStack {
public:
    using index_t = int;
    using value_t = int;
private:
    vector<index_t> T;
    const vector<value_t>& values;
public:
    using iterator = vector<index_t>::iterator;
    MinStack(const vector<value_t>& values) : values(values) {}
    iterator begin() { return T.begin(); }
    iterator end() { return T.end(); }
    // must be called sequentially
    void addElement(index_t index) {
        while (!T.empty() && !F()(values[T.back()], values[index]))
            T.pop_back();
        T.push_back(index);
    }
};

#define gc getchar_unlocked()
int read() {
    char c = gc;
    while (c <= ' ') c = gc;
    int r = 0;
    do {
        r *= 10;
        r += c-'0';
        c = gc;
    } while (c > ' ');
    return r;
}

int main() {
    int N, T;
    T = read();
    N = read();
    vector<int> Values(N);
    for (int& v: Values) v = read();
    MinStack<> minStack(Values);
    MinStack<greater<int>> maxStack(Values);
    int best = 1;
    for (int i = 0; i < N; i++) {
        minStack.addElement(i);
        maxStack.addElement(i);

        auto minit = minStack.begin();
        auto maxit = maxStack.begin();
        int prevMinLimit = -1;
        int prevMaxLimit = -1;
        // probably divide and conquer / binary search could be used
        while (minit != minStack.end() || maxit != maxStack.end()) {
            int limit = prevMinLimit;
            if (limit < prevMaxLimit) limit = prevMaxLimit;
            int val = Values[*maxit] - Values[*minit];
            if (val <= T && i-limit > best) best = i-limit; // break?
            
            if (*minit < *maxit) {
                prevMinLimit = *minit;
                minit++;
            } else if (*minit > *maxit) {
                prevMaxLimit = *maxit;
                maxit++;
            } else {
                prevMinLimit = *minit;
                prevMaxLimit = *maxit;
                minit++;
                maxit++;
            }
        }
    }
    cout << best << endl;
}
