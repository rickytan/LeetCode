#include <iostream>
#include <vector>
#include <map>
#include <limits>

using namespace std;

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() <= 1)
            return points.size();

        int result = 0;
        map<double, int> cache;
        for (int i=0; i<points.size(); ++i)
        {
            cache.clear();

            Point p0 = points[i];
            int samePoint = 0;
            int numOfPointsInLine = 1;
            for (int j=i+1; j<points.size(); ++j)
            {
                Point p1 = points[j];
                double slope = std::numeric_limits<double>::infinity();
                if (p0.x == p1.x && p0.y == p1.y)
                    ++samePoint;
                else {
                    if (p0.x != p1.x)
                        slope = 1.0 * (p0.y - p1.y) / (p0.x - p1.x);
                    if (!cache.count(slope))
                        cache[slope] = 1;
                    ++cache[slope];
                    int num = cache[slope];
                    if (num > numOfPointsInLine)
                        numOfPointsInLine = num;
                }
            }
            if (numOfPointsInLine + samePoint > result)
                result = numOfPointsInLine + samePoint;
        }
        return result;
    }
};

int main()
{
    return 0;
}