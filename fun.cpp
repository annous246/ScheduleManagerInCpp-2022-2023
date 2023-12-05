#include"sbib.h"
int compare(day d1,day d2){
			
			pair <string,int>p;int n=d1.lg();map<string,int>m,m2;map <pair <string,int>,int>type;
		for(int i=0;i<n;i++){
		m2[d2.get(i).get_name()]++;
		m[d1.get(i).get_name()]++;
		p.first=d2.get(i).get_name();p.second=d2.get(i).get_type();
		type[p]++;
		}
		
		for(int i=0;i<n;i++){
		pair <string,int> p2;
		p2.first=d1.get(i).get_name();
		p2.second=d1.get(i).get_type();
		int c=d1.get(i).get_name().compare("------");
		if(!c)continue;
		if(type[p2]==0)return 0;
		type[p2]--;
		}return 1;
		
		
}
int exist(vector<day> v,day d){
	for(int i=0;i<v.size();i++){
		if(v[i]==d)return 1;
	}return 0;
}


