#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<conio.h>

using namespace std;
struct cook
{string cook_name;
    string cook_mima;

};
void cook2();
void cook3();
void cook1()
{ifstream file_zm("user.txt");//文件中存储账号和密码
    if(!file_zm)
    {exit(1);}
    vector<string> allmima;
    string line;
    while(getline(file_zm,line))
    {allmima.push_back(line);}
    file_zm.close();
    stringstream ss(allmima[1]);
    cook ps1;
    ss>>ps1.cook_name;
    ss>>ps1.cook_mima;
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
        if(na!=ps1.cook_name || mi!=ps1.cook_mima )
            cout<<"账号或密码错误！！！"<<endl;
        if(na==ps1.cook_name && mi==ps1.cook_mima)
        {cout<<"进入系统"<<endl;
            break;}
        cout<<"输入0结束;输出非0数继续输入账号"<<endl;

        cin>>w;
    }while (w!=0);
    if(w==0)
    {exit(1);}
    int choice;
    do{
        cout<<"1.查看点餐菜品信息 2.更改菜品状态 3.退出系统"<<endl;
        cin>>choice;
        switch (choice) {
        case 1:
            cook2();
            break;
        case 2:cook3();
            break;
        case 3:break;
        default:cout<<"输入错误请重新输入！！！！"<<endl;
        }
        system("pause");
        system("cls");
    }while(choice!=3);


}
void cook2()
{vector<string> xiaoplook;
    ifstream filelook("xiaopiaoout.txt");
    string line;
    while(getline(filelook,line))
    {xiaoplook.push_back(line);}
    for(auto it=xiaoplook.begin()+5;it!=xiaoplook.end()-1;it++)
    {cout<<*it<<endl;}


}
void cook3()
{vector<string> xiaoplook;//xiaoplook[0]
    ifstream filelook("xiaopiaoout.txt");
    string line;
    while(getline(filelook,line))
    {xiaoplook.push_back(line);}
    filelook.close();
    string gaibian1="     出菜";
    string gaibian2="     未出菜";
    cout<<xiaoplook[5]<<endl;
    for(auto it=xiaoplook.begin()+6;it!=xiaoplook.end()-1;)
    {int n;
        cout<<*it<<endl;
        cout<<"是否已出菜(1.出菜 2.未出菜）"<<endl;
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
    ofstream cookandwaiter("cook__waiter.txt");
    if(!cookandwaiter)
    {cout<<"文件打开错误"<<endl;
        exit(1);}
    for(auto it=xiaoplook.begin();it!=xiaoplook.end()-1;it++)
    {cookandwaiter<<*it<<endl;
    }
    cookandwaiter.close();}



