#include<iostream>//�˿͵����ϵͳ
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
    do{cout<<"1.���µ��"<<endl;
        cout<<"2.���ϵ��"<<endl;
        cout<<"3.��Ӳ�Ʒ"<<endl;
        cout<<"4.�鿴СƱ"<<endl;
        cout<<"5.�������"<<endl;

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
        default:cout<<"�������"<<endl;

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
    {cout<<"�˵�����"<<endl;
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
    cout<<"ѡ���λ"<<endl;
    cout<<table<<endl;
    string li;
    cin>>li;


    cout<<setw(68)<<s;

    while(1){cout<<"ѡ��˻��ˮ�ı�� ע:һ������һ����ţ�����0�����������ظ�������ͬ���"<<endl;

        int choice;
        cin>>choice;
        if(!(choice>=1&&choice<=5)){break;}
        else{cout<<"��������"<<endl;

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
    cout<<"�������������(���س�������"<<endl;
    string name;
    cin>>name;
    xiaopiao[0]+=name;
    cout<<"��������ĵ绰(���س�������"<<endl;
    string ph;
    cin>>ph;
    xiaopiao[1]+=ph;
    cout<<"�������������Ҫ��(���س�������"<<endl;
    string yq;
    cin>>yq;
    xiaopiao[3]+=yq;
    string line,table;
    ifstream infile("meau.txt");
    if(!infile)
    {cout<<"�˵�����"<<endl;
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
    cout<<"ѡ���λ"<<endl;
    cout<<table<<endl;
    string li;
    cin>>li;
    cout<<setw(68)<<s;

    while(1){cout<<"ѡ��˻��ˮ�ı�� ע:һ������һ����ţ�����0����"<<endl;

        int choice;
        cin>>choice;
        if(!(choice>=1&&choice<=5)){break;}
        else{cout<<"��������"<<endl;
            cin>>c1[choice];
        }


    }
    xiaopiao[2]+=li;
}

void consumer3()
{
     int choice;
    cout<<setw(68)<<s;
    do{ cout<<"ѡ��˻��ˮ�ı�� ע:һ������һ����ţ�����0����"<<endl;
        cin>>choice;
        if(choice>=1&&choice<=5){
        cout<<"��������"<<endl;
            cin>>c2[choice];}
        else if(choice==0)
            break;
     else
        {cout<<"�������"<<endl;}
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
        s1="�ܼ�Ϊ"+zhuzifu(sum);
    else
        s1="�ܼ�Ϊ"+zhuzifu(sum+10);//10Ԫ��λ��
    xiaopiao.push_back(s1);

    ofstream xiaopiaoout("xiaopiaoout.txt");
    if(!xiaopiaoout)
    {exit(1);}
    string piao;
    for( auto it=xiaopiao.begin();it!=xiaopiao.end();it++)
    {piao+=*it+"\n";
        xiaopiaoout<<*it<<endl;}
    xiaopiaoout.close();
    cout<<piao;//��ӡСƱ

}
