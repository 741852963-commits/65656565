#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<conio.h>
using namespace std;
struct waiterask{
    string waiterask_name;
    string waiterask_mima;
};
void waiter1();
void waiter2();
void waiter3();
void waiter()
{waiterask a;
    ifstream file_zm("user.txt");//�ļ��д洢�˺ź�����
    if(!file_zm)
    {cout<<"�ļ���ʧ��"<<endl;
        exit(1);}
    vector<string> allmima;
    string line;
    while(getline(file_zm,line))
    {allmima.push_back(line);}
    file_zm.close();
    stringstream ss(allmima[0]);
    ss>>a.waiterask_name;
    ss>>a.waiterask_mima;
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
        if(na!=a.waiterask_name || mi!=a.waiterask_mima )
            cout<<"�˺Ż�������󣡣���"<<endl;
        if(na==a.waiterask_name && mi==a.waiterask_mima)
        {cout<<"����ϵͳ"<<endl;
            break;}
        cout<<"����0����;�����0�����������˺�"<<endl;
        cin>>w;
    }while (w!=0);
    if(w==0)
    {exit(1);}
    int choice;
    do{
        cout<<"1.�鿴СƱ��Ϣ 2.���Ĳ�Ʒ״̬  3.�˳�ϵͳ"<<endl;
        cin>>choice;
        switch (choice) {
        case 1:
            waiter1();
            break;
        case 2:waiter2();
            break;
        case 3: break;
        default:cout<<"����������������룡������"<<endl;
        }
        system("pause");
        system("cls");
    }while(choice!=3);
}
void waiter1()
{ifstream xplook("cook__waiter.txt");
    if(!xplook)
    {cout<<"��ʧ��"<<endl;
        exit(1);}
    vector<string> lookxp;
    string line;
    while(getline(xplook,line))
    {lookxp.push_back(line);}
    xplook.close();
    for(auto it=lookxp.begin();it!=lookxp.end();it++)
    {cout<<*it<<endl;}
}
void waiter2()
{ifstream xplook("cook__waiter.txt");
    if(!xplook)
    {cout<<"��ʧ��"<<endl;
        exit(1);}
    vector<string> lookxp;
    string line;
    while(getline(xplook,line))
    {lookxp.push_back(line);}
    xplook.close();
    string gaibian1="     �ϲ�";
    string gaibian2="     δ�ϲ�";
    cout<<lookxp[5]<<endl;
    for(auto it=lookxp.begin()+6;it!=lookxp.end();)
    {int n;
        cout<<*it<<endl;
        cout<<"�Ƿ����ϲ�(1.�ϲ� 2.δ�ϲˣ�"<<endl;
        cin>>n;
        if(n==1)
        {*it+=gaibian1;
            it++;}
        else  if(n==2)
        {*it+=gaibian2;
            it++;}
        else {
            cout<<"������󣡣���������"<<endl;
        }

    }
    ofstream waiter__shangp("waiter__shangp.txt");
    if(!waiter__shangp)
    {cout<<"�ļ��򿪴���"<<endl;
        exit(1);}
    for(auto it=lookxp.begin();it!=lookxp.end();it++)
    {waiter__shangp<<*it<<endl;
    }
    waiter__shangp.close();}

