#include<iostream>//顾客点餐子系统
#include<string>
#include<fstream>
#include<iomanip>
#include <vector>
#include"zhuanzifu.h"
using namespace std;
 double sum=0;
string s;
 vector<string>  xiaopiao;
vector<string> caidan;
double c[6]={0,49.00,80.00,49.00,1.50,5.00};
 int  c2[6]={0};
 int  c1[6]={0};
void consumer1();
void consumer2();
void consumer3();
void consumer4();
void Consumer()
{int a=0;
    do{cout<<"1.线下点餐"<<endl;
        cout<<"2.线上点餐"<<endl;
        cout<<"3.添加菜品"<<endl;
        cout<<"4.查看小票"<<endl;
        cout<<"5.结束点餐"<<endl;

        cin>>a;
        switch (a) {
        case 1:consumer1();
            break;
        case 2:
            consumer2();
            break;
        case 3:consumer3();break;

        case 4:consumer4();break;
        case 5:break;
        default:cout<<"输入错误"<<endl;

        }
        system("pause");
        system("cls");
            }while(a!=5);


}


void consumer1()
{
    string line,table;
    ifstream infile("meau.txt");
    if(!infile)
    {cout<<"菜单有误"<<endl;
        exit(0); }
    while(getline(infile,line))
    {s+=line+"\n";
    caidan.push_back(line);}
    infile.close();
    ifstream infile1("table.txt");
    if(!infile1)
    {exit(0);}
    while(getline(infile1,line))
    {table+=line+"\n";}
    infile1.close();
    cout<<"选择餐位"<<endl;
    cout<<table<<endl;
    string li;
    cin>>li;


    cout<<setw(68)<<s;

    while(1){cout<<"选择菜或酒水的编号 注:一次输入一个编号，输入0结束，请勿重复输入相同编号"<<endl;

        int choice;
        cin>>choice;
        if(!(choice>=1&&choice<=5)){break;}
        else{cout<<"输入数量"<<endl;

            cin>>c1[choice];
        }


    }
    ifstream filepiao("xiaopiao.txt");
    if(!filepiao)
    {exit(0);}
    string line2;
    while(getline(filepiao,line2))
    {xiaopiao.push_back(line2);}
    filepiao.close();
    xiaopiao[2]+=li;
    }


void consumer2()
{    ifstream filepiao("xiaopiao.txt");
    if(!filepiao)
    {exit(0);}
    string line2;
    while(getline(filepiao,line2))
    {xiaopiao.push_back(line2);}
    filepiao.close();
    cout<<"请输入你的名字(按回车结束）"<<endl;
    string name;
    cin>>name;
    xiaopiao[0]+=name;
    cout<<"请输入你的电话(按回车结束）"<<endl;
    string ph;
    cin>>ph;
    xiaopiao[1]+=ph;
    cout<<"请输入你的特殊要求(按回车结束）"<<endl;
    string yq;
    cin>>yq;
    xiaopiao[3]+=yq;
    string line,table;
    ifstream infile("meau.txt");
    if(!infile)
    {cout<<"菜单有误"<<endl;
        exit(1); }

    while(getline(infile,line))
    {s+=line+"\n";
    caidan.push_back(line);}
    infile.close();
    ifstream infile1("table.txt");
    if(!infile1)
    {exit(1);}
    while(getline(infile1,line))
    {table+=line+"\n";}
    infile1.close();
    cout<<"选择餐位"<<endl;
    cout<<table<<endl;
    string li;
    cin>>li;
    cout<<setw(68)<<s;

    while(1){cout<<"选择菜或酒水的编号 注:一次输入一个编号，输入0结束"<<endl;

        int choice;
        cin>>choice;
        if(!(choice>=1&&choice<=5)){break;}
        else{cout<<"输入数量"<<endl;
            cin>>c1[choice];
        }


    }
    xiaopiao[2]+=li;
}

void consumer3()
{
     int choice;
    cout<<setw(68)<<s;
    do{ cout<<"选择菜或酒水的编号 注:一次输入一个编号，输入0结束"<<endl;
        cin>>choice;
        if(choice>=1&&choice<=5){
        cout<<"输入数量"<<endl;
            cin>>c2[choice];}
        else if(choice==0)
            break;
     else
        {cout<<"输入错误"<<endl;}
    }while(choice!=0);



    }

void consumer4()
{    int c3[6]={0};
    for(int i=1;i<6;i++)
    {c3[i]=c2[i]+c1[i];
    sum+=c3[i]*c[i];}

    for(int i=1;i<=5;i++)
    {if(c3[i]!=0)
        {
            caidan[i]+="        "+zhuzifu(c3[i]);
            xiaopiao.push_back(caidan[i]);
        }}
    string s1;
    if(sum>=500)
        s1="总价为"+zhuzifu(sum);
    else
        s1="总价为"+zhuzifu(sum+10);//10元餐位费
    xiaopiao.push_back(s1);

    ofstream xiaopiaoout("xiaopiaoout.txt");
    if(!xiaopiaoout)
    {exit(1);}
    string piao;
    for( auto it=xiaopiao.begin();it!=xiaopiao.end();it++)
    {piao+=*it+"\n";
        xiaopiaoout<<*it<<endl;}
    xiaopiaoout.close();
    cout<<piao;//打印小票

}
