#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<conio.h>
using namespace std;
extern double sum;
struct cashier
{string cashier_name;
    string cashier_mima;

};
void cashier()
{
    ifstream file_zm("user.txt");//�ļ��д洢�˺ź�����
    if(!file_zm)
    {exit(1);}
    vector<string> allmima;
    string line;
    while(getline(file_zm,line))
    {allmima.push_back(line);}
    file_zm.close();
    stringstream ss(allmima[1]);
    struct cashier a;
    ss>>a.cashier_name;
    ss>>a.cashier_mima;
    int w=1;
    do{string na,mi;
        na.clear();
        mi.clear();
        cout<<"�����˺ţ�6λ����"<<endl;
        cin>>na;
        cout<<"�������루6λ����"<<endl;
        int cnt=0;
        while(cnt<6)
        {cnt++;
            char ch=getch();
            mi+=ch;
            putchar('*');}
        cout<<endl;
        if(na!=a.cashier_name || mi!=a.cashier_mima )
            cout<<"�˺Ż�������󣡣���"<<endl;
        if(na==a.cashier_name && mi==a.cashier_mima)
        {cout<<"����ϵͳ"<<endl;
            break;}
        cout<<"����0����;�����0�����������˺�"<<endl;

        cin>>w;
    }while (w!=0);
    if(w==0)
    {exit(1);}
    int choice;



}
