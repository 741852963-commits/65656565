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
    ifstream file_zm("user.txt");//文件中存储账号和密码
    if(!file_zm)
    {cout<<"文件打开失败"<<endl;
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
        cout<<"输入账号（6位数）"<<endl;
        cin>>na;
        cout<<"输入密码（6位数）"<<endl;
        int cnt=0;
        while(cnt<6)
        {cnt++;
            char ch=getch();
            mi+=ch;
            putchar('*');}
        cout<<endl;
        if(na!=a.waiterask_name || mi!=a.waiterask_mima )
            cout<<"账号或密码错误！！！"<<endl;
        if(na==a.waiterask_name && mi==a.waiterask_mima)
        {cout<<"进入系统"<<endl;
            break;}
        cout<<"输入0结束;输出非0数继续输入账号"<<endl;
        cin>>w;
    }while (w!=0);
    if(w==0)
    {exit(1);}
    int choice;
    do{
        cout<<"1.查看小票信息 2.更改菜品状态  3.退出系统"<<endl;
        cin>>choice;
        switch (choice) {
        case 1:
            waiter1();
            break;
        case 2:waiter2();
            break;
        case 3: break;
        default:cout<<"输入错误请重新输入！！！！"<<endl;
        }
        system("pause");
        system("cls");
    }while(choice!=3);
}
void waiter1()
{ifstream xplook("cook__waiter.txt");
    if(!xplook)
    {cout<<"打开失败"<<endl;
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
    {cout<<"打开失败"<<endl;
        exit(1);}
    vector<string> lookxp;
    string line;
    while(getline(xplook,line))
    {lookxp.push_back(line);}
    xplook.close();
    string gaibian1="     上菜";
    string gaibian2="     未上菜";
    cout<<lookxp[5]<<endl;
    for(auto it=lookxp.begin()+6;it!=lookxp.end();)
    {int n;
        cout<<*it<<endl;
        cout<<"是否已上菜(1.上菜 2.未上菜）"<<endl;
        cin>>n;
        if(n==1)
        {*it+=gaibian1;
            it++;}
        else  if(n==2)
        {*it+=gaibian2;
            it++;}
        else {
            cout<<"输入错误！！！！！！"<<endl;
        }

    }
    ofstream waiter__shangp("waiter__shangp.txt");
    if(!waiter__shangp)
    {cout<<"文件打开错误"<<endl;
        exit(1);}
    for(auto it=lookxp.begin();it!=lookxp.end();it++)
    {waiter__shangp<<*it<<endl;
    }
    waiter__shangp.close();}

