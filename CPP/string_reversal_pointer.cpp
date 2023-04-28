#include<iostream>
using namespace std;
int main()
{
    char str[100],*p,*q,temp;
    cout<<"Enter a string: ";
    cin>>str;
    p=str;
    q=str;
    while(*q)
    {
        q++;
    }
    q--;
    while(p<q)
    {
        temp=*p;
        *p=*q;
        *q=temp;
        p++;
        q--;
    }
    cout<<"Reverse of the string: "<<str;
    return 0;
}