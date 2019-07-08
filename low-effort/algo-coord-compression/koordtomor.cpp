#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG

using namespace std;

class CoordinateManager {
    map<long long, int> Map;
    vector<long long> InverseMap;
    vector<long long> Lengths; // 0: 0-1
public:
    void insert(long long val) {
        InverseMap.push_back(val);
    }
    void finalize() {
        // sort&uniq
        // sort
        sort(InverseMap.begin(), InverseMap.end());
        // remove duplicates
        // http://www.cplusplus.com/reference/algorithm/unique/
        auto it = unique(InverseMap.begin(), InverseMap.end());
        InverseMap.resize(distance(InverseMap.begin(), it));
        // fill map too
        int idx = 0;
        for (auto elem: InverseMap) {
            Map[elem] = idx++;
        }
        // fill lengths
        for (int i = 1; i < InverseMap.size(); i++) {
            Lengths.push_back(InverseMap[i] - InverseMap[i-1]);
        }
    }
    int plsMap(long long val) {
        assert(Map.find(val) != Map.end());
        return Map[val];
    }
    int plsInverseMap(int idx) {
        assert(idx < InverseMap.size());
        return InverseMap[idx];
    }


    int lengthsSize() { return Lengths.size(); }
    long long getLength(int idx) { return Lengths[idx]; }
};

#define scanf whoops
#define printf whoops

struct Rect { int x1, y1, x2, y2; };

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    CoordinateManager X;
    CoordinateManager Y;

    vector<Rect> rect(N);
    for (auto& r: rect) {
        cin >> r.x1 >> r.y2 >> r.x2 >> r.y1;
        X.insert(r.x1);
        X.insert(r.x2);
        Y.insert(r.y1);
        Y.insert(r.y2);
    }
    X.finalize();
    Y.finalize();

    vector<vector<bool>> Cuccli(X.lengthsSize(), vector<bool>(Y.lengthsSize()));
    for (auto& r: rect) {
        int x1 = X.plsMap(r.x1), y1 = Y.plsMap(r.y1),x2 = X.plsMap(r.x2), y2 = Y.plsMap(r.y2);
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                Cuccli[x][y] = !Cuccli[x][y];
            }
        }
    }
    long long result = 0;
    for (int x = 0; x < Cuccli.size(); x++) {
        auto& row = Cuccli[x];
        for (int y = 0; y < row.size(); y++) {
            bool val = row[y];
            if (val) 
                result += X.getLength(x) * Y.getLength(y);
            cout << val;
        }
        cout << endl;
    }
    cout << endl;

    cout << result << endl;
}
