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
private:
	string name;
	int score[4];
};


void average(judge *jud){
	
}
int main() {
    student stu[4]; //�������� ѧ�� 
    judge jud[7]; //�������� ���� 
    ifstream stuin("C:/Users/13109/Desktop/project/stuin.txt");
    ifstream judgein("/Users/13109/Desktop/project/judgein.txt");
    ofstream ljlout("C:/Users/13109/Desktop/project/ljlout.txt");
    
    if(stuin.is_open()) //�ļ���ȡѧ��ѧ������ 
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
    
    if(judgein.is_open()) //�ļ���ȡ�������� ���ĸ�ѧ����ķ��� 
    {
        cout<<"file OK"<<endl;
        for(int i=0; i<7; i++) //ÿ������ 
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
    //average(jud);
    
    
    
    
    
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
    
    return 0;
}
