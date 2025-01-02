#ifndef ZHUANZIFU_H
#define ZHUANZIFU_H
#include<string>
std:: string zhuzifu( int n  )

{int an[30];

    int cnt=0;
    while (n>0) {an[cnt]=n%10;
        n=n/10;
        cnt++;

    }
  std::  string s;
    for(int i=cnt-1;i>=0;i--)
  {char c;
        c=an[i]+'0';
        s+=c;
        }
    return s;



}
#endif // ZHUANZIFU_H
