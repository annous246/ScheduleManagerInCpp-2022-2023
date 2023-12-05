#include "fun.cpp"

int main(){
	//shcedual input
	cout<<"Welcome to Schedule Explorer (Provided by Anas)"<<endl;
	int n,s,b;
	do{
	cout<<"Give Number of prepa classes"<<endl;cin>>n;
	}while(n<1);
	int wc=0;
	do{
	cout<<"Give which week (Qa=1/Qb=2)"<<endl;cin>>wc;
	
	}while(wc!=1&&wc!=2);
	int zt=0;
	do{
	cout<<"Give which week mid semester (Z3=1/Z4=2)"<<endl;cin>>zt;
	
	}while(zt!=1&&zt!=2);
	cout<<"Give Number sessions in total for this prepa"<<endl;
do{
	cin>>b;}while(b<1);
	vector <day> all;
	string dayy;r:
	cout<<"Please Select which week day (Monday/Tuesday/Wednesday/Thursday/Friday/Saturday)"<<endl;
	cin>>dayy;
	for(int i=0;i<n;i++){
		fstream file;
		char dir[500];
		string nb=to_string(i+1);
		string rep="schedule manager\\"+dayy+"\\prepaA0"+nb;
    	string adir=rep+dayy+".csv";int v;
    	cout<<adir<<endl;
	    for( v=0;v<adir.length();v++)dir[v]=adir[v];
	    dir[v]='\0';
	    file.open(dir,ios::in);
		if(!file.is_open()){cout<<"The file didnt open correctly "<<endl<<"Either check you day spelling or creat the required schedules using Schedule Manager extension"<<endl;goto r;
		}
		
		string session,type,classe,pn,ts,buffer;
		getline(file,buffer,'\n');
		
		day d;
		for(int j=0;j<b;j++){
		getline(file,buffer,',');
		getline(file,session,',');
		getline(file,type,',');
		getline(file,classe,',');
		getline(file,pn,',');
		getline(file,ts,'\n');
		int tp=0;
		if(type[1]=='P')tp=2;
		if(type[1]=='D')tp=1;
		// week check*****************************************
		if(ts[0]=='Q'){
		if(wc==1&&ts[1]=='B'){
				session="------";
				type="------";
				classe="------";
				ts="------";
				pn="------";
			
		}
		else if(ts[1]=='A'&&wc==2){
				session="------";
				type="------";
				classe="------";
				ts="------";
				pn="------";
			
		}	}
		else if(ts[0]=='Z'){
		if(zt==1&&ts[1]=='4'){
				session="------";
				type="------";
				classe="------";
				ts="------";
				pn="------";
			
		}
		else if(ts[1]=='3'&&zt==2){
				session="------";
				type="------";
				classe="------";
				ts="------";
				pn="------";
			
		}
		}
		
		
		seance sc(session,classe,tp,pn,ts,i+1);
		sc.prt();cout<<endl<<endl;//////////////////////////////////////////////////////
		d.add(sc);
		
			
		}
		file.close();
		all.push_back(d);
		}
	
	//******************************************************
	//******************************************************
	
	//scheduals printing
	cout<<"There are "<<pow(n,b)<<" possible schedules in total"<<endl;
	vector <day> possibles;
	for(int a=0;a<n;a++){
	for(int b=0;b<n;b++){
	for(int c=0;c<n;c++){
	for(int d=0;d<n;d++){
	for(int e=0;e<n;e++){
	for(int f=0;f<n;f++){
		day md;
		md.add(all[a].get(0));
		md.add(all[b].get(1));
		md.add(all[c].get(2));
		md.add(all[d].get(3));
		md.add(all[e].get(4));
		md.add(all[f].get(5));
		possibles.push_back(md);
		
	}
	}}}}}/*
	for(int i=0;i<possibles.size();i++){cout<<"poss "<<i+1<<endl;
		possibles[i].prt();cout<<endl<<endl;
	}*/
	//******************************************************
	//******************************************************
	
	//schedual personnalisation section
	cout<<"Welcome to personnalized schedule section"<<endl;
	cout<<"Give me The pattern of your schedule"<<endl;
	cout<<"Each seance put the name of the desired (material) or just put (nothing)"<<endl;
	day pd;
	int k;
	do{
	cout<<"Provide The number of materials and  to study"<<endl;
	cin>>k;}while(k<1);
	for(int i=0;i<b;i++){
	cout<<"S"<<i+1<<": material name and ,which type (0/1/2) (if nothing input nothing)"<<endl;
	string nm;int t;
	cin>>nm;
	if(nm.compare("nothing")==0){
	nm="------";t=0;goto m;}
	cin>>t;m:
	seance s(nm,t);
	pd.add(s);
	 }
	//******************************************************
	//******************************************************
	//******************************************************
	vector <day> person;cout<<"---------------------------------------------------------"<<endl;
	cout<<"Choose "<<endl;
	int ok;
	do{
	cout<<"(0) For Random schedule Order "<<endl;
	cout<<"(1) For Exact Order "<<endl;cin>>ok;}while(ok<0||ok>1);
	if(!ok){
	for(int i=0;i<possibles.size();i++){	
		if(compare(pd,possibles[i])){
			if(!exist(person,possibles[i]))
	person.push_back(possibles[i]);
	
		}
	}
	for(int i=0;i<person.size();i++){
		person[i].prt();
		
		
		
		cout<<endl<<endl<<endl;
	}if(!person.size())cout<<"Sorry such a schedule dosen't exist";
	}
else{
	for(int i=0;i<possibles.size();i++){	
		if(pd==possibles[i]){
	person.push_back(possibles[i]);goto ex;
	
		}
	}cout<<"Sorry such a schedule dosen't exist";return 0;ex:person[0].sprt(pd);
}

if(!ok)cout<<"The probability to find you a valid schedules is "<<setprecision(4)<<((float)person.size()/pow(n,b))*100<<"% ("<<person.size()<<" personnalized schedules in a total of "<<pow(n,b)<<" possible schedules)"<<endl;
}
