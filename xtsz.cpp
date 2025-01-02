#include<iostream>//系统设置子系统（修改账号密码）
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
        if(na!=a.admin_name || mi!=a.admin_mima )
            cout<<"账号或密码错误！！！"<<endl;
        if(na==a.admin_name && mi==a.admin_mima)
        {cout<<"进入系统"<<endl;
            break;}
        cout<<"输入0结束;输出非0数继续输入账号"<<endl;

        cin>>w;
    }while (w!=0);

    int choice;
    do
    {
        cout<<" 1.修改管理员密码  0.退出"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
        {

            string in_name, in_mima;
            cout<<"请输入原账号："<<endl;
            cin>>in_name;
            cout<<"请输入原密码："<<endl;
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
                cout<<"请输入新的密码"<<endl;
                cin>>new_mima;
                ofstream outfile("user(admin).txt");
                outfile<<a.admin_name<<" "<<new_mima;
                outfile.close();
                cout<<"密码修改成功！"<<endl;
            }
            else
            {
                cout<<"账号或密码错误，无法修改密码！"<<endl;
            }
            break;
        }
        case 0:
            break;
        default:
            cout<<"输入错误，请重新输入！"<<endl;
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
        do{cout<<"1.修改老板账号密码 2.修改服务员账号密码 3.修改厨师账号密码 4.修改收银员账号密码 5.输入0结束"<<endl;
            cin>>choice2;
            switch(choice2)
            {case 1: {cout<<"输入老板新的账号和密码（一行，中间用空格隔开）"<<endl;
                cin.ignore();
                getline(cin,other_mima2[0]);
                break;
            }
            case 2:{cout<<"输入服务员新的账号和密码（一行，中间用空格隔开）"<<endl;
                cin.ignore();
                getline(cin,other_mima2[1]);

            break;}
            case 3:{cout<<"输入厨师新的账号和密码（一行，中间用空格隔开）"<<endl;
                cin.ignore();
                getline(cin,other_mima2[2]);

            break;}
            case 4:{cout<<"输入收银员新的账号和密码（一行，中间用空格隔开）"<<endl;
                cin.ignore();
                getline(cin,other_mima2[3]);

            break;}
            case 0:{break;}
            default : {cout<<"输入错误！！！"<<endl;}}
        }while(choice2!=0);
        ofstream outfile("user.txt");
        if(!outfile)
        {exit(1);}
                for(auto it=other_mima2.begin();it!=other_mima2.end();it++)
                 outfile<<*it<<endl;
}
