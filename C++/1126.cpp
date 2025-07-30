#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const double eps = 1e-6;

inline int sign(double x) {
    if (fabs(x) < eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}

struct Point3 {
    double x, y, z;
    Point3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    bool operator<(const Point3 &u) const {
        return sign(x - u.x) < 0 ||
               (sign(x - u.x) == 0 && sign(y - u.y) < 0) ||
               (sign(x - u.x) == 0 && sign(y - u.y) == 0 && sign(z - u.z) < 0);
    }
    bool operator>(const Point3 &u) const { return u < (*this); }
    bool operator==(const Point3 &u) const { return !(u < (*this) || (*this) < u); }
    bool operator!=(const Point3 &u) const { return !((*this) == u); }
    Point3 operator+(const Point3 &u) const { return Point3(x + u.x, y + u.y, z + u.z); }
    Point3 operator-(const Point3 &u) const { return Point3(x - u.x, y - u.y, z - u.z); }
    Point3 operator*(const double u) const { return Point3(x * u, y * u, z * u); }
    Point3 operator/(const double u) const { return Point3(x / u, y / u, z / u); }
    void read() { scanf("%lf%lf%lf", &x, &y, &z); }
};

typedef Point3 Vector3;

namespace Vectorial {
    double getDot(Vector3 a, Vector3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

    double getLength(Vector3 a) { return sqrt(getDot(a, a)); }

    Vector3 getCross(Vector3 a, Vector3 b) {
        return Vector3(a.y * b.z - a.z * b.y,
                       a.z * b.x - a.x * b.z,
                       a.x * b.y - a.y * b.x);
    }

    Vector3 getNormal(Point3 a, Point3 b, Point3 c) {
        Vector3 u = a - b, v = b - c;
        Vector3 k = getCross(u, v);
        return k / getLength(k);
    }

    double getDistancePointToPlane(Point3 p, Point3 p0, Vector3 v) {
        return fabs(getDot(p - p0, v));
    }

    Point3 getPlaneProjection(Point3 p, Point3 p0, Vector3 v) {
        return p - v * getDot(p - p0, v);
    }
};

namespace Linear {
    using namespace Vectorial;

    double getDistancePointToLine(Point3 p, Point3 a, Point3 b) {
        Vector3 v1 = b - a, v2 = p - a;
        return getLength(getCross(v1, v2)) / getLength(v1);
    }

    double getDistancePointToSegment(Point3 p, Point3 a, Point3 b) {
        if (a == b) return getLength(p - a);
        Vector3 v1 = b - a, v2 = p - a, v3 = p - b;
        if (sign(getDot(v1, v2)) < 0)
            return getLength(v2);
        else if (sign(getDot(v1, v3)) > 0)
            return getLength(v3);
        else
            return getLength(getCross(v1, v2)) / getLength(v1);
    }

    bool getPointLineToLine(Point3 a, Vector3 u, Point3 b, Vector3 v, double &s) {
        double p = getDot(u, u) * getDot(v, v) - getDot(u, v) * getDot(u, v);
        if (sign(p) == 0) return false;
        double q = getDot(u, v) * getDot(v, a - b) - getDot(v, v) * getDot(u, a - b);
        s = q / p;
        return true;
    }

    double getDistanceSegmentToSegment(Point3 a, Point3 b, Point3 c, Point3 d) {
        double s, t;
        bool flag1 = getPointLineToLine(a, b - a, c, d - c, s);
        bool flag2 = getPointLineToLine(c, d - c, a, b - a, t);
        if (flag1 && flag2 && sign(s) > 0 && sign(s - 1) < 0 && sign(t) > 0 && sign(t - 1) < 0) {
            Vector3 u = b - a, v = d - c;
            Point3 p = a + u * s, q = c + v * t;
            return getLength(p - q);
        } else {
            double ans = 1e20;
            ans = min(ans, getDistancePointToSegment(a, c, d));
            ans = min(ans, getDistancePointToSegment(b, c, d));
            ans = min(ans, getDistancePointToSegment(c, a, b));
            ans = min(ans, getDistancePointToSegment(d, a, b));
            return ans;
        }
    }
};

namespace Triangular {
    using namespace Vectorial;

    double getArea(Point3 a, Point3 b, Point3 c) {
        return getLength(getCross(b - a, c - a));
    }

    bool onTriangle(Point3 p, Point3 a, Point3 b, Point3 c) {
        double area1 = getArea(p, a, b);
        double area2 = getArea(p, b, c);
        double area3 = getArea(p, c, a);
        return sign(area1 + area2 + area3 - getArea(a, b, c)) == 0;
    }
};

using namespace Linear;
using namespace Triangular;

Point3 A[5], B[5];

double getDistancePointToTriangle(Point3 p, Point3 a, Point3 b, Point3 c) {
    double ret = 1e20;
    ret = min(ret, getDistancePointToSegment(p, a, b));
    ret = min(ret, getDistancePointToSegment(p, b, c));
    ret = min(ret, getDistancePointToSegment(p, c, a));
    Vector3 v = getNormal(a, b, c);
    Point3 tmp = getPlaneProjection(p, a, v);
    if (onTriangle(tmp, a, b, c))
        ret = min(ret, getDistancePointToPlane(p, a, v));
    return ret;
}

double solve() {
    double ret = 1e20;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++)
            for (int x = 0; x < 4; x++)
                for (int y = x + 1; y < 4; y++)
                    ret = min(ret, getDistanceSegmentToSegment(A[i], A[j], B[x], B[y]));
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a = (j + 1) % 4, b = (j + 2) % 4;
            ret = min(ret, getDistancePointToTriangle(A[i], B[j], B[a], B[b]));
            ret = min(ret, getDistancePointToTriangle(B[i], A[j], A[a], A[b]));
        }
    }
    return ret;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        for (int i = 0; i < 4; i++) A[i].read();
        for (int i = 0; i < 4; i++) B[i].read();
        printf("%.2lf\n", solve());
    }
    return 0;
}
