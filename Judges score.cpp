#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include <string>
#include<algorithm>
#include<ctime>

//��vector����ѧ��
//�ȴ���ѧ�����࣬�ٴ���ѧ��������


//����ѧ������
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
	for(int i=0;i<5;i++)//��Ϊ��ȷ�涨����5����
{
	string name ="ѡ��";
	//name+="ABCDE";
	string nameseed="ABCDE";
	name+=nameseed[i];
	int score=0; 
	/*person(name,0)a;aҪ��ǰ��д��*/
	person p(name,score);
	v.push_back(p);
}
}

void setscore(vector<person> &v)
{
	

	for(vector<person>::iterator it =v.begin();it!=v.end();it++)
	{
		deque<int>d1;//!ע��deque����������� int,����person!
		for(int i=0;i<10;i++)
		{
			 int score= rand() %41 + 60;//���������60-100
			 d1.push_back(score);//��������������Ž���������
		}
		//��deque�еķ�������
		sort(d1.begin(),d1.end());

		//ɾ����߷ֺ���ͷ�
		d1.pop_back();
		d1.pop_front();

		int sum=0;
		//����ѡ�ַ���֮��
		for(deque<int>::iterator dit =d1.begin();dit != d1.end();dit++)
		{
			
			sum += *dit;
		}
		int ave=sum/d1.size();
		
		//��ƽ���ָ�ֵ��ѡ��
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
	cout<<"ѡ��������"<<it->m_name<<"\tѡ�ַ�����"<<it->m_score<<endl;//(*it).m_name���ָ�ʽҲ����
}

}

int main ()
{
//������ѧ��������
vector<person>v;


//������������ӣ���֤ÿ����������������ڱ仯
  srand((unsigned int)time(NULL));



//����ÿ��ѧ����Ϣ
//��ÿ��ѧ������Ϣ�ŵ�������
creatperson(v);
//����
//for(vector<person>::iterator it =v.begin();it!=v.end();it++)
//{
//	cout<<"ѡ��������"<<it->m_name<<"\tѡ�ַ�����"<<it->m_score<<endl;//(*it).m_name���ָ�ʽҲ����
//
//}


//��ÿһ��ѧ�����
setscore(v);


//չʾÿλѡ�ֵķ���
show(v);



	system("pause");
	return 0;
}