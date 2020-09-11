#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=11000002;
char data[maxn<<1];
int p[maxn<<1],cnt,ans;
inline void qr(){
      char c=getchar();
      data[0]='~',data[cnt=1]='|';
      while(c<'a'||c>'z') c=getchar();
      while(c>='a'&&c<='z') data[++cnt]=c,data[++cnt]='|',c=getchar();
}
int main(){
      qr();
      for(int t=1,r=0,mid=0;t<=cnt;++t){
        if(t<=r) p[t]=min(p[(mid<<1)-t],r-t+1);
        while(data[t-p[t]]==data[t+p[t]]) ++p[t];       //拓展左右两侧
        if(p[t]+t>r) r=p[t]+t-1,mid=t;                  //更新mid和r
        if(p[t]>ans) ans=p[t];
      }
      printf("%d\n",ans-1);
      return 0;
}