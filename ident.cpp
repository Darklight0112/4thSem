#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;
int main()
{
ifstream in;
ofstream out;
in.open("id.txt");
out.open("idout.txt");
int count=0;
string s;
while(getline(in,s))
{
if(s[0]=='{')
{
for(int i=0;i<count;i++)
out<<"  ";
out<<s<<endl;
count++;
}
else if(s[0]=='}')
{
count--;
for(int i=0;i<count;i++)
out<<"  ";
out<<s<<endl;
}
else
{
for(int i=0;i<count;i++)
out<<"  ";
out<<s<<endl;
}
}
in.close();
out.close();
}
