#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include <string>
#include<algorithm>
#include<ctime>

//用vector创建学生
//先创建学生的类，再创建学生的数组


//创建学生的类
class person
{
public:
	person(string name , int score)
	{
		this->m_name=name;
		this->m_score =score;
	}

	string m_name;
	int m_score;
};

void creatperson(vector<person> &v)//const vector<person> &v
{
	
	
//for(vector<person>::iterator it =v.begin();it!=v.end();it++)
	for(int i=0;i<5;i++)//因为明确规定了是5个人
{
	string name ="选手";
	//name+="ABCDE";
	string nameseed="ABCDE";
	name+=nameseed[i];
	int score=0; 
	/*person(name,0)a;a要在前面写！*/
	person p(name,score);
	v.push_back(p);
}
}

void setscore(vector<person> &v)
{
	

	for(vector<person>::iterator it =v.begin();it!=v.end();it++)
	{
		deque<int>d1;//!注意deque里面的类型是 int,不是person!
		for(int i=0;i<10;i++)
		{
			 int score= rand() %41 + 60;//产生随机数60-100
			 d1.push_back(score);//将产生的随机数放进到容器中
		}
		//将deque中的分数排序
		sort(d1.begin(),d1.end());

		//删除最高分和最低分
		d1.pop_back();
		d1.pop_front();

		int sum=0;
		//计算选手分数之和
		for(deque<int>::iterator dit =d1.begin();dit != d1.end();dit++)
		{
			
			sum += *dit;
		}
		int ave=sum/d1.size();
		
		//将平均分赋值给选手
		it->m_score=ave;
		

		
		/*d1.front(v);
		int ave=sum/v.size();
		person(name,ave);*/
	}

}

void show(vector<person> &v)
{
	for(vector<person>::iterator it =v.begin();it!=v.end();it++)
{
	cout<<"选手姓名："<<it->m_name<<"\t选手分数："<<it->m_score<<endl;//(*it).m_name这种格式也可以
}

}

int main ()
{
//创建许学生的容器
vector<person>v;


//建立随机数种子，保证每次随机产生的数都在变化
  srand((unsigned int)time(NULL));



//创建每个学生信息
//并每个学生的信息放到容器里
creatperson(v);
//测试
//for(vector<person>::iterator it =v.begin();it!=v.end();it++)
//{
//	cout<<"选手姓名："<<it->m_name<<"\t选手分数："<<it->m_score<<endl;//(*it).m_name这种格式也可以
//
//}


//给每一个学生打分
setscore(v);


//展示每位选手的分数
show(v);



	system("pause");
	return 0;
}