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
    case 1:xtsz();break;//ϵͳ������ϵͳ
    case 2:Consumer();break;//�˿͵����ϵͳ
    case 3:waiter();break;//����Ա��ϵͳ
    case 4:cook1();break;//��ʦ��ϵͳ
    case 5:cashier()   ;break;//����Ա��ϵͳ
    case 6:   ;break;//�ϰ���ϵͳ
    case 7:break;
    default:cout<<"������󣡣���������"<<endl;}
   }while(choice!=7);

    return 0;
}
