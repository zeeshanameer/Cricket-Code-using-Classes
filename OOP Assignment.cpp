//Submitted by Muhammad zeeshan Amir
// Sap id= 42909


#include<iostream>
#include<ctime>
#include<string>
using namespace std;

class Cricketer{
	protected:
	string name;
	int shirtnumber;
	string dob;
	int odi_rating;
	int test_rating;
	int t20_rating;
	int startyear;
	time_t t=time(NULL);
	tm* tptr = localtime(&t);
	int current_year=(tptr->tm_year)+1900;
	
		
	public:
		
	Cricketer(){
		
		cout<<"\n--------------------------\n";
		}
	    
	Cricketer(string name,int shirtnumber,string dob,int odi_rating,int test_rating,int t20_rating,int startyear){
	    	
	    	this->name=name;
	    	this->shirtnumber=shirtnumber;
	    	this->odi_rating=odi_rating;
	    	this->startyear=startyear;
	    	this->test_rating=test_rating;
	    	this->dob=dob;
	    	this->t20_rating=t20_rating;
	    	}
	  
	int calculateAge(){
		int year=stoi(dob);
		cout<<"Age of player: "<<current_year - year<<endl;
		return current_year - year;
			}
	
	int calculateExperience(){
		
		cout<<"Experience of palyer: "<<current_year-startyear<<endl;
		return current_year-startyear;
		
	}
	
	void changeODIRating(int odi_rat){
	    odi_rating=odi_rat;
	}
		
	void changeTestRating(int test_rat){
		
		test_rating=test_rat;
	}
	
	void changeT20Rating(int t20_rat){
		t20_rating=t20_rat;
	}
	
	void info(){
		cout<<"----------------------"<<endl;
		
		cout<<"Name: "<<name<<endl<<"Shirt_no. : "<<shirtnumber<<endl<<"ODI_Rating : "<<odi_rating<<endl<<"T20_Rating: "<<t20_rating<<endl<<"Test_Rating: "<<test_rating<<endl<<"Date of Birth: "<<dob<<endl<<"Starting Year: "<<startyear<<endl<<endl; 
cout<<"----------------------"<<endl;
        
	}
	
	~Cricketer(){
		
	}
};


class Bowler:public Cricketer{
	private:
	string type;
	int total_wickets;
	int match_played;
	
	public:
		
		Bowler(){
			
		}
		
		Bowler(string name,int shirtnumber,string dob,int odi_rating,int test_rating,int t20_rating,int startyear,string type,int total_wickets,int match_played):Cricketer(name, shirtnumber, dob, odi_rating, test_rating, t20_rating, startyear){
		this->type=type;
		this->total_wickets=total_wickets;
		this->match_played=match_played;
		
		}
		
		int calculateBowlAverage(){
			int average= total_wickets/match_played;
			cout<<"Average of Bowler: "<<average<<endl;
             return average;
		}
		
		void updateMatches(int x){
			match_played=x+match_played;
		}
		
		void updateWickets(int z){
			total_wickets=z+total_wickets;
		}
		
		void Ballinfo(){
		
		cout<<"Name: "<<name<<endl<<"Shirt_no. : "<<shirtnumber<<endl<<"ODI_Rating : "<<odi_rating<<endl<<"T20_Rating: "<<t20_rating<<endl<<"Test_Rating: "<<test_rating<<endl<<"Date of Birth: "<<dob<<endl<<"Starting Year: "<<startyear<<endl<<"Category: "<<type<<endl<<"Wickets Taken"<<total_wickets<<endl<<"Matches Played: "<<match_played<<endl; 
	}
		
		~Bowler(){
			
		}
		
};


class Batsman:public Cricketer{
	private:
	string type; 
	int total_runs;
	int match_played;
	int best_score;
	
	public:
		
		Batsman(){
			
		}
		
		Batsman(string name,int shirtnumber,string dob,int odi_rating,int test_rating,int t20_rating,int startyear,string type,int total_runs,int match_played,int best_score): Cricketer( name,  shirtnumber, dob, odi_rating, test_rating, t20_rating, startyear){
		this->type=type;
		this->total_runs=total_runs;
		this->match_played=match_played;
		this->best_score=best_score;
		}
		
		int calculateBatAverage(){
			int average=total_runs/match_played;
			cout<<"Average of Batsman :"<<average<<endl;
			return average;
		}
		
		void updateMatches(int x){
			match_played=x+match_played;
		}
		
		void updateRuns(int z){
			total_runs= z+total_runs;
		}
		
		void Batinfo(){
		
		cout<<"Name: "<<name<<endl<<"Shirt_no. : "<<shirtnumber<<endl<<"ODI_Rating : "<<odi_rating<<endl<<"T20_Rating: "<<t20_rating<<endl<<"Test_Rating: "<<test_rating<<endl<<"Date of Birth: "<<dob<<endl<<"Starting Year: "<<startyear<<endl<<"Category: "<<type<<endl<<"Total Runs: "<<total_runs<<endl<<"Matches Played: "<<match_played<<endl<<"Best Score: "<<best_score<<endl; 
	}
		
		~Batsman(){
			
		}
};

class AllRounder:public Bowler,Batsman{
	public:
     AllRounder(){
		
	}
	
	~AllRounder(){
		
	}
};




int main() {
	
	Cricketer c("Zeeshan",40,"2001",2,3,1,2015);
		c.info();
	c.calculateAge();
	c.calculateExperience();
	
	int a,b,d;
	cout<<"\nEnter Your Rating of Test_T20_ODI :"<<endl;
	cin>>a;
	cin>>b;
	cin>>d;
	c.changeTestRating(a);
	c.changeT20Rating(b);
	c.changeODIRating(d);
	cout<<"Rankings successfully changed: "<<endl;
	cout<<"\n-------After Changing------------\n"<<endl;
	c.info();
	Bowler f("Zeeshan",40,"2001",2,3,1,2015,"Bowler",15,5);
	f.Ballinfo();
	f.calculateBowlAverage();
	cout<<"\n"<<endl;
	Batsman e("Zeeshan",40,"2001",2,3,1,2015,"Batsman",1000,15,150);	
	e.Batinfo();
	e.calculateBatAverage();
	AllRounder r;
	return 0;
}
