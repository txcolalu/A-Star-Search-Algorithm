//
//  point.h
//  test
//
//  Created by jiawei on 2022/3/8.
//

#ifndef point_h
#define point_h
#include <iostream>
using namespace std;
class Point{
private:
    int x,y;
public:
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
    Point(){}
    void set(int x,int y){
        this->x = x;
        this->y = y;
    }
    friend int getCost(const Point&,const Point&);
    int getCost(const Point& P){
        return abs(P.x-x) + abs(P.y-y);
    }
    bool operator==(const Point& C){
        return C.x == x && C.y == y;
    }
    bool operator!=(const Point& C){
        return C.x != x || C.y != y;
    }
    constexpr int X(){
        return x;
    }
    constexpr int Y(){
        return y;
    }
    friend ostream& operator<<(ostream& os,const Point& P);
};
int getCost(const Point& A,const Point& B){
    return abs(A.x - B.x) + abs(A.y - B.y);
}
ostream& operator<<(ostream& os,const Point& P){
    os<<"("<<P.x<<","<<P.y<<") ";
    return os;
}
#endif /* point_h */
