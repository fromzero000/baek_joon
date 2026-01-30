#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};


int checkDirection(Point A, Point B, Point C) {
    long long result = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    
    if(result > 0) return 1;
    if(result < 0) return -1;
    return 0;
}

int main() {
    Point p1, p2, p3, p4;

    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    int dir1 = checkDirection(p1, p2, p3);
    int dir2 = checkDirection(p1, p2, p4);

    int dir3 = checkDirection(p3, p4, p1);
    int dir4 = checkDirection(p3, p4, p2);

    if(dir1 == 0 && dir2 == 0 && dir3 == 0 && dir4 == 0) {
        
        if(p1.x > p2.x || (p1.x == p2.x && p1.y > p2.y)) swap(p1, p2);
        if(p3.x > p4.x || (p3.x == p4.x && p3.y > p4.y)) swap(p3, p4);


        if(p1.x <= p4.x && (p1.x < p4.x || p1.y <= p4.y) &&
            p3.x <= p2.x && (p3.x < p2.x || p3.y <= p2.y)) 
        {
            cout << 1;
        }
        else 
        {
            cout << 0;
        }
    }
    
    else if(dir1 * dir2 <= 0 && dir3 * dir4 <= 0) 
    {
        cout << 1;
    }

    else 
    {
        cout << 0;
    }

    return 0;
}