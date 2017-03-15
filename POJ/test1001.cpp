//求高精度幂
#include<iostream>
using namespace std;
#define SIZE 10000
int main()
{
    char c[SIZE];
    int n;
    while(cin>>c>>n)
    {
        int i=0,j,arr[SIZE]={0},len=strlen(c),max=0,set=0,temp,k,record=0;//arr[]中所有的元素初始化为0
        for(i=0;i
        {
            if(c[i]=='.')
                record=len-i-1;
            else
                max=max*10+c[i]-'0';
        }
        if(record)
        {
            for(k=len-1;c[k]=='0';k--,record--)
                 max/=10;//去掉后面多余的0
        }
        for(i=0,temp=max;i
            arr[i]=temp;//将数倒置导入数组
        record=record*n;//record为总的小数位
        for(i=0;i
        {
            for(j=0;j
            {
                arr[j]=arr[j]*max+set;
                set=arr[j]/10;
                arr[j]=arr[j];
            }
        }
        for(i=SIZE-1;arr[i]==0;i--)
            if(arr[i]!=0)
                break;  //注意此时计算结果仍是倒置的，并且把小数点前无用的零去掉
        if(record>i)
        {
            cout<<'.';
            for(k=record-1;k>=0;k--)
                cout<<arr[k];
        }
        else
        {
            for(;i>=0;i--)
            {
                cout<<arr[i];
                if(i==record&&record!=0)
                   cout<<'.';
            }
        }
        cout<<endl;
    }
    return 0;
}