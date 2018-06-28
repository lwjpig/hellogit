#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>

using namespace std;

typedef struct Student{string name;string sex;double score;}Student;

Student student[100];

bool cmp(Student A,Student B)
{
  if(A.score!=B.score)
  return A.score>B.score;
  if(A.score==B.score)
  return A.name<B.name;
}

int main()
{
  int number=0;double s_all=0.0;double a_all=0.0;
  int m_n=0;double s_m=0.0; double a_m=0.0;
  int f_n=0;double s_f=0.0; double a_f=0.0;
  ifstream fin("score.csv");
  string s;
  getline(fin,s);
  while(getline(fin,s))
  {
   stringstream ss;
   ss<<s;
   ss>>student[number].name;
   ss>>student[number].sex;

    if(student[number].sex[0]='M')
      m_n++;
   else 
     f_n++;

   ss>>student[number].score;
   if(student[number].sex[0]=='M')
    {
     s_m+=student[number].score;
     s_all+=student[number].score;
    }
    else
     {
      s_f+=student[number].score;
      s_all+=student[number].score;
     }
     number++;
}
  
   a_all=s_all/number;
   a_f=s_f/f_n;
   a_m=s_m/m_n;

sort(student,student+number,cmp);
 
cout<<"The average of the students is "<<a_all<<endl;
cout<<"The average of the girls is "<<a_f<<endl;
cout<<"The average of the boys is "<<a_m<<endl;

cout<<"\t\t#name,"<<"\t\t#sex,"<<"\t\t#score"<<endl;
 for(int i=0;i<number;i++)
  {
   cout<<"\t\t"<<student[i].name<<"\t\t"<<student[i].sex<<"\t\t"<<student[i].score<<endl;
 }
return 0;
}
