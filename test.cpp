#include"fun.cpp"
#include <iostream>
#include <set>

int main() 
{pair <string,int> p,p2,p1;
map<pair <string,int>,int>m;

p.first="hi";
p.second=2;
m[p]++;
p.first="hi";
p.second=1;
m[p]++;
cout<<m[p2]<<m[p];
   return 0;
}
