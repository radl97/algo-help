#include <bits/stdc++.h>
#define scanf whoops
#define printf whoops
#define cin whoops

using namespace std;

struct point {
    long long x,y;
    int idx;
};

inline bool operator==(point a, point b) {
    return a.idx == b.idx;
}

inline point operator-(point a, point b) {
    return point{a.x-b.x, a.y-b.y};
}

inline long long cross(point a, point b) {
    return 1LL*a.x*b.y - 1LL*b.x*a.y;
}

inline int Ford(point a, point b, point c) {
    point db = b-a;
    point dc = c-a;
    long long d = cross(db,dc);
    if (d > 0) return 1;
    if (d < 0) return -1;
    return 0;
    //return (d>0)-(d<0); // >0 -> 1; <0 -> -1; ==0 -> 0
}

int N;
vector<point> ps;
vector<point> convex;
point q;

inline bool balrale(point a, point b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

inline bool intriangle(point a, point b, point c, point q) {
    int fd = Ford(a,b,c);
    if (fd == 0) return false; // not a triangle
    int fa = Ford(a,b,q), fb = Ford(b,c,q), fc = Ford(c,a,q);
    return fa != -fd && fb != -fd && fc != -fd;
}

ostream& operator<<(ostream& os, const vector<point>& Q) {
    for (const point& q: Q) {
        os << q.x << " " << q.y << endl;
    }
    return os;
}

#define READ c = getchar_unlocked()
long long read() {
    char READ;
    while (c <= ' ') READ;
    bool sign = false;
    if (c == '-') { sign = true; READ; }
    long long r = 0;
    do {
        r *= 10;
        r += c-'0';
        READ;
    } while (c > ' ');
    if (sign) return -r;
    return r;
}
#undef READ

int main() {
    N = read();
    ps.resize(N);
    q.x = read(); q.y = read();
    for (int i = 0; i < N; i++) {
        ps[i].x = read();
        ps[i].y = read();
        ps[i].idx = i;
    }
    // sarok
    {
        point* min = &ps[0];
        for (int i = 1; i < N; i++) {
            if (balrale(*min, ps[i])) min = &ps[i];
        }
        swap(*min, ps[0]);
    }
    // sort
    sort(ps.begin()+1, ps.end(), [](const point& a, const point& b){
        return Ford(ps[0], a, b) > 0;
    });
    //cout << ps << endl;
    // eros konvexburok -> reverse nem kell, tavolsag szerinti sort sem
    // convex
    ps.push_back(ps[0]); // kamu elem: sarokpont
    convex.push_back(ps[0]);
    convex.push_back(ps[1]);
    assert(Ford(ps[0], ps[1], ps[2]) != -1);
    for (int i = 2; i < ps.size(); i++) {
#define lastie convex[convex.size()-1]
#define almostlastie convex[convex.size()-2]
        while (convex.size() > 2 && Ford(almostlastie, lastie, ps[i]) != 1) {
            convex.pop_back();
        }
        convex.push_back(ps[i]);
        //cout << convex << endl;
    }
    ps.pop_back(); // kamuelem kitorlese mindket helyrol
    convex.pop_back();
    for (int i = 2; i < convex.size(); i++) {
        point a = convex[0], b = convex[i-1], c = convex[i];
        if (intriangle(a,b,c, q)) {
            for (int j = 0; j < N; j++) {
                point& p = ps[j];
                if (a == p) continue;
                if (b == p) continue;
                if (c == p) continue;
                if (intriangle(a,b,c, p)) {
                    if (intriangle(a,b,p, q))
                        c = p;
                    else if (intriangle(b,c,p, q))
                        a = p;
                    else if (intriangle(c,a,p, q))
                        b = p;
                }
            }
            cout << a.idx+1 << " " << b.idx+1 << " " << c.idx+1 << endl;
            return 0;
        }
    }
    cout << "0 0 0" << endl;
}
