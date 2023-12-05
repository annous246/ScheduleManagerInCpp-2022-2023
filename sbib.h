#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<cmath>
#include<fstream>
using namespace std;

class seance{
	private:
		string name,classe,pn,st;
		int group,type;
	public:
		seance(string n,string c,int t,string pn,string st,int l){
			name=n;
			classe=c;
			group=l;
			type=t;
			this->pn=pn;
			this->st=st;
		}
		seance(string v,int t){
			name=v;
			classe="";
			pn="";
			st="";
			group=0;
			type=t;
		}
		int get_sl(){
			return group;
		}
		int get_type(){
			return type;
		}
		string get_name(){
			return name;
		}
		void prt(){string type ="-";
		switch(this->type){
			case(0):type="C";break;
			case(1):type="TD";break;
			case(2):type="TP";break;
		}
			cout<<name<<" "<<classe<<" type:"<<type<<" prof:"<<pn<<" "<<st<<" A"<<group<<endl;
		}
};
class day{
	private:
	vector <seance> d;
	public:
		day(){
		}
		void add(seance s){
			d.push_back(s);
		}
		seance get(int i){
			return d[i];
		}
		int lg(){return d.size();
		}
		void prt(){
			for(int i=0;i<d.size();i++){
				cout<<"S"<<i+1<<" ";
				d[i].prt();
			}
		}
		void sprt(day y){
			for(int i=0;i<d.size();i++){
				cout<<"S"<<i+1<<" ";
				if(!y.get(i).get_name().compare("------")){
				
				cout<<" ------ ------ type:C prof:------ ------ An"<<endl;continue;}
				d[i].prt();
			}
		}
		int operator==(day d1){
			day d2=*this;
int n=d1.lg();
for(int i=0;i<n;i++){
	if(!d2.get(i).get_name().compare("------"))continue;
	if(d1.get(i).get_name().compare(d2.get(i).get_name())!=0){return 0;
	}
	if(d1.get(i).get_type()!=d2.get(i).get_type()){return 0;
	}
}return 1;
			
		
		
	}
};
