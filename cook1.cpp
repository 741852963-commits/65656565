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
{ifstream file_zm("user.txt");//�ļ��д洢�˺ź�����
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
        if(na!=ps1.cook_name || mi!=ps1.cook_mima )
            cout<<"�˺Ż�������󣡣���"<<endl;
        if(na==ps1.cook_name && mi==ps1.cook_mima)
        {cout<<"����ϵͳ"<<endl;
            break;}
        cout<<"����0����;�����0�����������˺�"<<endl;

        cin>>w;
    }while (w!=0);
    if(w==0)
    {exit(1);}
    int choice;
    do{
        cout<<"1.�鿴��Ͳ�Ʒ��Ϣ 2.���Ĳ�Ʒ״̬ 3.�˳�ϵͳ"<<endl;
        cin>>choice;
        switch (choice) {
        case 1:
            cook2();
            break;
        case 2:cook3();
            break;
        case 3:break;
        default:cout<<"����������������룡������"<<endl;
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
    string gaibian1="     ����";
    string gaibian2="     δ����";
    cout<<xiaoplook[5]<<endl;
    for(auto it=xiaoplook.begin()+6;it!=xiaoplook.end()-1;)
    {int n;
        cout<<*it<<endl;
        cout<<"�Ƿ��ѳ���(1.���� 2.δ���ˣ�"<<endl;
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
    ofstream cookandwaiter("cook__waiter.txt");
    if(!cookandwaiter)
    {cout<<"�ļ��򿪴���"<<endl;
        exit(1);}
    for(auto it=xiaoplook.begin();it!=xiaoplook.end()-1;it++)
    {cookandwaiter<<*it<<endl;
    }
    cookandwaiter.close();}



