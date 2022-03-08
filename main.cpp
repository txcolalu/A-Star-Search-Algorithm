#include <iostream>
#include <map>
#include "point.h"
using namespace std;
int mp[][8] = {{1,1,1,1,1,1,1,1},
                {1,1,1,1,1,0,1,1},
                {1,1,1,0,1,0,1,1},
                {1,1,1,0,1,0,1,1},
                {1,1,1,0,0,0,1,1},
                {1,1,1,0,1,1,1,1}};

void A_Search(Point& S,Point& E){
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    map<pair<int,int>,Point> came_from;
    multimap<int, Point> p;
    p.insert({0,S});
    came_from[{S.X(), S.Y()}] = Point(-1,-1);
    Point cur;
    while(!p.empty()){
        cur = p.begin()->second;
        if(cur == E) break;
        p.erase(p.begin());
        for(int i = 0;i<4;i++){
            int nx = dx[i] + cur.X();
            int ny = dy[i] + cur.Y();
            if(nx<0 ||ny<0 || nx>5 || ny>7 || mp[nx][ny] == 0) continue;
            Point tmp(nx,ny);
            if(came_from.count({nx,ny})) continue;
            int cost = tmp.getCost(S)+tmp.getCost(E);
            p.insert({cost,tmp});
            came_from[{nx,ny}] = cur;
        }
    }
    cur = E;
    while(came_from[{cur.X(),cur.Y()}] != Point(-1,-1)){
        cout<<cur;
        cur = came_from[{cur.X(),cur.Y()}];
    }
}
int main(){
    Point a(3,1),b(3,6);
    A_Search(a,b);
    return 0;
}
