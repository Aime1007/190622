#include <iostream>
#include <fstream>
using namespace std;

class student{
public:
    student(){}
    void get(int a,string b){       
        num = a;
        name = b;
    }
    void show()
    {
        cout << num <<" "<<name<<endl;
    }
private:
    string name;
    int num;
    
};

class judge{
public:
	judge(){		
	}
	void get(string a,int *p){
	
		name = a;
		for(int i=0; i<4; i++) 
			score[i]=*(p+i);
	}
	void show()
    {
    	cout << name <<" ";
    	for(int i=0; i<4; i++){
    		cout << score[i];    	
			if( i==3 )
				cout <<endl;
			else
				cout <<" ";	
		}        
    }
    friend void average(judge *jud);
private:
	string name;
	int score[4];
};


void average(judge *jud){
	int scor[4][7];
	for(int i=0; i<4; i++ )
		for(int j=0; j<7; j++ ){
			scor[i][j] = (*(jud+j)).score[i];
		}
	for(int i=0; i<4; i++ )
		for(int j=0; j<7; j++ ) {
			cout << scor[i][j];
			if( j==6 )
				cout <<endl;
			else
				cout <<" ";						
		}
	int max,min;
	for(int i=0; i<4; i++ ){
		max=0,min=1000;
		for(int j=0; j<7; j++ ){
			if( scor[i][j]>max )
				max = scor[i][j];
			if( scor[i][j]<min )
				min = scor[i][j];
		}
		cout << min <<" "<< max<<endl;
	}
		
}
int main() {
    student stu[4]; //对象数组 学生 
    judge jud[7]; //对象数组 裁判 
    ifstream stuin("C:/Users/13109/Desktop/project/stuin.txt");
    ifstream judgein("/Users/13109/Desktop/project/judgein.txt");
    ofstream ljlout("C:/Users/13109/Desktop/project/ljlout.txt");
    
    if(stuin.is_open()) //文件读取学生学号姓名 
    {
        cout<<"file OK"<<endl;
        for(int i=0; i<4; i++)
        {           
            int a;
            string b;
            stuin >> a >> b;
            stu[i].get(a,b);
        
        }
        stuin.close();
    }
    
    if(judgein.is_open()) //文件读取裁判姓名 给四个学生打的分数 
    {
        cout<<"file OK"<<endl;
        for(int i=0; i<7; i++) //每个裁判 
        {           
            string a;
            judgein >> a;
            int score[4];
            for(int j=0; j<4; j++)
            {
            	int s;
            	judgein >> s;
            	score[j] = s;
			}
        	jud[i].get(a,score);  
        }        
        judgein.close();
    }    
    
    
    
    
    
    
    if (ljlout.is_open())
    {
        cout<<"file OK"<<endl;
        for(int i=0; i<4; i++)
        {                      
            stu[i].show();       
        }
        for(int i=0; i<7; i++)
        {
        	jud[i].show();
		}
        //ljlout << <<endl;
        //stu01.show();
        ljlout.close();
    }
    average(jud);
    return 0;
}
