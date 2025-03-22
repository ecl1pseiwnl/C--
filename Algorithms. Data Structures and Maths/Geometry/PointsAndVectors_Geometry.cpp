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
const double PI = 3.141592653589793238463;
#define bmask(x,i) (((x) >> (i)) & 1)
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
constexpr int EPS = -1e9;
constexpr int MOD = 1e9+7;
constexpr int32_t IINF = 0x3f3f3f3f;
constexpr int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

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

double distP(point A, point B) {
    return hypot(A.x - B.x,A.y - B.y);
}

point rotation(point P, double alpha) {
    return point(P.x * cos(alpha) - P.y * sin(alpha), P.x * sin(alpha) + P.y * cos(alpha));
}

struct line{
    double a,b,c;
};

bool areParallel(line A, line B) {
    return (A.a == B.a && A.b == B.b);
}

bool areTheSame(line A, line B) {
    if (areParallel(A,B)) {
        return (A.c == B.c);
    }
}

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

vect getVec(point A, point B) {
    return vect(B.x-A.x, B.y-A.y);
}

vect scale(vect v, double k) {
    return vect(v.x * k, v.y * k);
}

double scalarProduct(vect a, vect b) {
    return a.x*b.x + a.y*b.y;
}

point translate(point p, vect v) {
    return point(p.x+v.x, p.y+v.y);
}

double getLen(vect v) {
    return hypot(v.x,v.y);
}

double distToLine(point M, point a, point b) {
    double k = scalarProduct(vect(a,M),vect(a,b)) / getLen(a,b);
    point H = translate(a,scale(vect(a,b)),k);
    return dist(M,H);
}

double getAngle(point O, point A, point B) {
    vect OA = vect(O,A); vect OB = vect(O,B);
    return acos(scalarProduct(OA,OB) / sqrt(getlen(OA),getlen(OB)));
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
