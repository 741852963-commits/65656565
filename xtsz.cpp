#include<iostream>//ϵͳ������ϵͳ���޸��˺����룩
#include<string>
#include<conio.h>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
struct admin
{string  admin_name;
    string  admin_mima;
};
void xtsz()
{admin a;
    ifstream file_mima("user(admin).txt");
    if(!file_mima)
    {exit(1);}
    string s,line;
    while(getline(file_mima,line))
    {s+=line+"\n";}
        stringstream ss(s);

    ss>>a.admin_name;
        ss>>a.admin_mima;
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
        if(na!=a.admin_name || mi!=a.admin_mima )
            cout<<"�˺Ż�������󣡣���"<<endl;
        if(na==a.admin_name && mi==a.admin_mima)
        {cout<<"����ϵͳ"<<endl;
            break;}
        cout<<"����0����;�����0�����������˺�"<<endl;

        cin>>w;
    }while (w!=0);

    int choice;
    do
    {
        cout<<" 1.�޸Ĺ���Ա����  0.�˳�"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
        {

            string in_name, in_mima;
            cout<<"������ԭ�˺ţ�"<<endl;
            cin>>in_name;
            cout<<"������ԭ���룺"<<endl;
            int cnt = 0;
            while(cnt < 6)
            {
                char ch = getch();
                in_mima += ch;
                putchar('*');
                cnt++;
            }
            cout<<endl;
            if (in_name == a.admin_name && in_mima == a.admin_mima)
            {

                string new_mima;
                cout<<"�������µ�����"<<endl;
                cin>>new_mima;
                ofstream outfile("user(admin).txt");
                outfile<<a.admin_name<<" "<<new_mima;
                outfile.close();
                cout<<"�����޸ĳɹ���"<<endl;
            }
            else
            {
                cout<<"�˺Ż���������޷��޸����룡"<<endl;
            }
            break;
        }
        case 0:
            break;
        default:
            cout<<"����������������룡"<<endl;
            break;
        }
    } while (choice!= 0);
    ifstream file_mima2("user.txt");
        if(!file_mima2)
    {exit(1);}
        string line2;
        vector<string> other_mima2;
        while(getline(file_mima2,line2))
        {other_mima2.push_back(line2);}
        file_mima2.close();

        int choice2=10;
        do{cout<<"1.�޸��ϰ��˺����� 2.�޸ķ���Ա�˺����� 3.�޸ĳ�ʦ�˺����� 4.�޸�����Ա�˺����� 5.����0����"<<endl;
            cin>>choice2;
            switch(choice2)
            {case 1: {cout<<"�����ϰ��µ��˺ź����루һ�У��м��ÿո������"<<endl;
                cin.ignore();
                getline(cin,other_mima2[0]);
                break;
            }
            case 2:{cout<<"�������Ա�µ��˺ź����루һ�У��м��ÿո������"<<endl;
                cin.ignore();
                getline(cin,other_mima2[1]);

            break;}
            case 3:{cout<<"�����ʦ�µ��˺ź����루һ�У��м��ÿո������"<<endl;
                cin.ignore();
                getline(cin,other_mima2[2]);

            break;}
            case 4:{cout<<"��������Ա�µ��˺ź����루һ�У��м��ÿո������"<<endl;
                cin.ignore();
                getline(cin,other_mima2[3]);

            break;}
            case 0:{break;}
            default : {cout<<"������󣡣���"<<endl;}}
        }while(choice2!=0);
        ofstream outfile("user.txt");
        if(!outfile)
        {exit(1);}
                for(auto it=other_mima2.begin();it!=other_mima2.end();it++)
                 outfile<<*it<<endl;
}
