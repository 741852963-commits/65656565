#include <iostream>
#include"setting.h"
#include"Consumer.h"
#include"xtsz.h"
#include"waiter.h"
#include"cook1.h"
#include"cashier.h"
#include"boss.h"
using namespace std;

int main()
{
    int choice;

   do
    {setting();
        cin>>choice;
       switch(choice){
    case 1:xtsz();break;//系统管理子系统
    case 2:Consumer();break;//顾客点餐子系统
    case 3:waiter();break;//服务员子系统
    case 4:cook1();break;//厨师子系统
    case 5:cashier()   ;break;//收银员子系统
    case 6:   ;break;//老板子系统
    case 7:break;
    default:cout<<"输入错误！！！！！！"<<endl;}
   }while(choice!=7);

    return 0;
}
