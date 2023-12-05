#include<iostream>
#include<fstream>
using namespace std;

int main(){string group,day;
	char dir[500];
	cout<<"Welcome to schedule manager (Provided by Anas)"<<endl<<"Please set your preparatory class name where you wanna change schedule (1/2/3/4))"<<endl;
	cin>>group;
	cout<<"Please set which day schedule(Monday) "<<endl;
	cin>>day;
	string tdir=day+"\\prepaA0"+group+day+".csv";
	int n=tdir.length();
	for(int i=0;i<n;i++){dir[i]=tdir[i];
	}
	
	//************************************************************
	fstream file;
	file.open(dir,ios::out);string seance,type,classe,fp,lp,ts;
	if(!file.is_open()){cout<<"File or directory error"<<endl;return 0;
	}
	do{
	cout<<"Give the number of sessions in total(issatso=6)"<<endl;cin>>n;
	}while(n<0);
	cout<<"its "<<day<<" for prepaA0"<<group<<endl;
	file<<",,,Prepa A0"<<group<<" Weekly schedule"<<endl;
	for(int i=0;i<n;i++){
	cout<<"Give the material on session "<<i+1<<" or just put nothing if you dont have any"<<endl;
	cin>>seance;
	file<<"S"<<i+1<<",";
	if(!seance.compare("nothing")){file<<"------,------,------,------,------"<<endl;continue;
	}
	cout<<"Give the type of this material (TD/C/TP)"<<endl;
	cin>>type;
	cout<<"Give which room where this session will be held in(I01)"<<endl;
	cin>>classe;
	cout<<"Give the first name of the professor of this session "<<endl;
	cin>>fp;
	cout<<"Give the last name of the professor of this session "<<endl;
	cin>>lp;
	cout<<"Give the type of this material (H/Z3/QA)"<<endl;
	cin>>ts;
	file<<seance<<","<<type<<","<<classe<<","<<lp<<" "<<fp<<","<<ts<<","<<endl;
		
	}
	file.close();
	
}
