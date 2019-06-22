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
	judge(){}
	void get(string a,int *p){
		name = a;
		for(int i=0; i<4; i++) {
			score[i]=*(p+i);
		}
	}
private:
	string name;
	int score[4]; 
};
int main() {
    student stu[4];
    judge jud[7];
    ifstream stuin("C:/Users/13109/Desktop/project/stuin.txt");
    ifstream judgein("/Users/13109/Desktop/project/judgein.txt");
    ofstream ljlout("C:/Users/13109/Desktop/project/ljlout.txt");
    
    if(stuin.is_open())
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
    
    if(judgein.is_open())
    {
        cout<<"file OK"<<endl;
        for(int i=0; i<7; i++)
        {           
            string a;
            stuin >> a;
            int score[4];
            for(int j=0; i<4; j++)
            {
            	int s;
            	stuin >> s;
			}
        	jud[i].get(a,score);
        }        
        stuin.close();
    }    
    
    if (ljlout.is_open())
    {
        cout<<"file OK"<<endl;
        for(int i=0; i<4; i++)
        {                      
            stu[i].show();       
        }
        //ljlout << <<endl;
        //stu01.show();
        ljlout.close();
    }
    
    return 0;
}
