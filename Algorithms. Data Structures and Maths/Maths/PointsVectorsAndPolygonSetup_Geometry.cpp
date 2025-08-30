#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define Mask(x,i) (((x) >> (i)) & 1)
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define ins insert
#define sz(x) (int)(x.size())
#define fi first
#define se second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define name "TASK"
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
constexpr int MOD = 1e9+7;
constexpr int IINF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = 3.141592653589793238463;
constexpr int EPS = 1e-9;

struct point{
    double x,y;
    point() {
        x = y = 0;
    }
    point(double x1, double y1) {
        x = x1; y = y1;
    }
    bool operator < (point B) const {
        if (fabs(x-B.x) < EPS) {
            return y < B.y;
        } else return x < B.x;
    }
    bool operator == (point B) const {
        return (fabs(x-B.x) < EPS && fabs(y-B.x) < EPS);
    }
};

// Khoảng cách của 2 điểm
double distP(point A, point B) {
    return hypot(A.x - B.x,A.y - B.y);
}

// Xoay điểm
point rotation(point P, double alpha) {
    return point(P.x * cos(alpha) - P.y * sin(alpha), P.x * sin(alpha) + P.y * cos(alpha));
}

struct line{
    double a,b,c;
};

// Kiểm tra song song
bool areParallel(line A, line B) {
    return (A.a == B.a && A.b == B.b);
}

// Kiểm tra trùng nhau
bool areTheSame(line A, line B) {
    if (areParallel(A,B)) {
        return (A.c == B.c);
    }
}

// Kiểm tra cắt nhau
bool areIntersect(line A, line B, point& I) {
    if (areParallel(A,B)) return false;
    I.x = (A.c * B.b - A.b * B.c) / (A.a * B.b - A.b * B.a);
    I.y = (A.a * B.c - A.c * B.a) / (A.a * B.b - A.b * B.a);
    return true;
}

line makeline(point A, point B) {
    double a,b,c;
    if (A.x == B.y) {
        a = 1;
        b = 0;
        c = -A.x;
    } else {
        a = (B.y - A.y) / (A.x - B.x);
        b = 1;
        c = -a*A.x - A.y;
    }
    line t;
    t.a = a; t.b = b; t.c = c;
    return t;
}

struct vect{
    double x,y;
    vect(double x1, double y1) {
        x = x1; y = y1;
    }
};

// Lấy vector từ 2 điểm
vect getVec(point A, point B) {
    return vect(B.x-A.x, B.y-A.y);
}

// Nhân vector k lần
vect scale(vect v, double k) {
    return vect(v.x * k, v.y * k);
}

// Tích vô hướng
double scalarProduct(vect a, vect b) {
    return a.x*b.x + a.y*b.y;
}

// Tịnh tiến vector
point translate(point p, vect v) {
    return point(p.x+v.x, p.y+v.y);
}

// Lấy độ lớn của vector
double getLen(vect v) {
    return hypot(v.x,v.y);
}

// Lấy độ lớn của vector (Không dùng hàm)
double getLen_sq(vect v) {
    return v.x * v.x + v.y * v.y;
}

// Khoảng cách 1 điểm đến đường thẳng
double distToLine(point M, point a, point b) {
    double k = scalarProduct(getVec(a,M),getVec(a,b)) / getLen(getVec(a,b));
    point H = translate(a,scale(getVec(a,b),k));
    return distP(M,H);
}

// Lấy góc tại 2 vector OA, OB
double getAngle(point O, point A, point B) {
    vect OA = getVec(O,A); vect OB = getVec(O,B);
    return acos(scalarProduct(OA,OB) / sqrt(getLen_sq(OA) + getLen_sq(OB)));
}

// Tích có hướng
double crossProduct(vect u, vect v) {
    return u.x * v.y - u.y * v.x;
}

// Cùng chiều kim đồng hồ hay không?
bool ccw(point o, point a, point b) {
    vect OA = getVec(o,a), OB = getVec(o,b);
    return (crossProduct(OA,OB) > 0);
}

// Có thẳng hàng hay không?
bool collinear(point o, point a, point b) {
    vect OA = getVec(o,a), OB = getVec(o,b);
    return (fabs(crossProduct(OA,OB)) < EPS);
}

/// Hình tam giác
/// Tam giác ABC có BC = a, AB = c, AC = b. Chu vi tam giác P = p/2 với p = a + b + c.
/// Bán kính đường tròn ngoại tiếp là R và bán kính đường tròn nội tiếp là r
/// S = 1/2*ah = sqrt(p(p-a)(p-b)(p-c)) = abc/4*R = pr = 1/2*absin(C) = 1/2*acsin(B) = 1/2*bcsin(A)
/// BĐT tam giác a+b > c; a+c > b; b+c > a.
/// Định lý cosine: c^2 = a^2 + b^2 - 2abcos(C)
///                 b^2 = a^2 + c^2 - 2accos(B)
///                 a^2 = b^2 + c^2 - 2bccos(A)
/// Định lý Sine: a/sinA = b/sinB = c/sinC = 2R

/// Hình tứ giác
/// Các hình đặc biệt: HBH, HCN, HV, HThoi, HThang.
/// Tứ giác nội tiếp có tổng hai góc đổi nhau = pi.

// Chu vi đa giác
double perimeter(const vector<point> &p) {
    int n = p.size();
    double ans = 0;
    REP(i,n) {
        int nxt = (i+1)%n;
        ans += distP(p[i],p[nxt]);
    }
    return ans;
}

// Diện tích đa giác
double getArea(const vector<point> &p) {
    int n = p.size();
    double ans = 0;
    REP(i,n) {
        int nxt = (i+1)%n;
        ans += p[i].x*p[i+1].y-p[i].y*p[i+1].x;
    }
    return fabs(ans)/2;
}

// Bao lồi
bool checkConvex(point M,const vector<point> &p) {
    int n = p.size();
    if (n < 3) return 0;
    bool check = ccw(p[0],p[1],p[2]);
    REP(i,n) {
        int nxt = (i+1)%n, later = (i+2)%n;
        if (ccw(p[i],p[nxt],p[later]) != check) return 0;
    }
    return 1;
}

// Điểm có nằm trong đa giác hay không
bool insidePolygon(point M,const vector<point> &p) {
    int n = p.size();
    if (n < 3) return 0;
    double ans = 0;
    REP(i,n) {
        int nxt = (i+1)%n;
        ans += getAngle(M,p[i],p[nxt]);
    }
    return fabs(fabs(ans)-2*PI) < EPS;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    /// Đa giác
    vector<point> polygon;
    polygon.pb(point(0,0));
    polygon.pb(point(2,1));
    polygon.pb(point(1,3));
    polygon.pb(point(-5,2));
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
