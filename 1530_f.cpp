/**
 * 小方的版本
 * 似乎都是dfs
 **/
#include <iostream>
#include <cstdio>
#include <cstring>
#define re register
#define debug //printf("%d\n",__LINE__)
using namespace std;
inline int read(){//快读
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
    return x*f;
}
inline int read(char* str){
    while (cin.peek()==' '||cin.peek()=='\n'||cin.peek()=='\r')getchar();
    re int ind=0;
    while(true){
        str[ind]=getchar();
        if(str[ind]<'A'||str[ind]>'Z'){
            str[ind]='\0';
            return ind;
        }
        else ind++;
    }
    
}
const int MAXn=1e6+5;
char s[MAXn];
char s0[MAXn];//解码二叉树
int len;
void inorder(int x=1){
    if(x>len) return;
    int xx=x<<1;
    inorder(xx);
    putchar(s[x]);
    inorder(xx+1);
}
void preorder(int x=1){
    if(x>len) return;
    int xx=x<<1;
    putchar(s[x]);
    preorder(xx);
    preorder(xx+1);
}
void postorder(int x=1){
    if(x>len) return;
    int xx=x<<1;
    postorder(xx);
    postorder(xx+1);
    putchar(s[x]);
}
int index_s0=1;
void decode_in(int x=1){
    if(x>len) return;
    int xx=x<<1;
    decode_in(xx);
    s0[x]=s[index_s0++];
    decode_in(xx+1);
}
void decode_pre(int x=1){
    if(x>len) return;
    int xx=x<<1;
    s0[x]=s[index_s0++];
    decode_pre(xx);
    decode_pre(xx+1);
}
void decode_post(int x=1){
    if(x>len) return;
    int xx=x<<1;
    decode_post(xx);
    decode_post(xx+1);
    s0[x]=s[index_s0++];
}
void layer(int x=1){
    s0[len+1]='\0';
    printf("%s\n",s0+1);
}
int main(){
    // freopen("1530.in","r",stdin);
    re int t=read();
    while(t--){
        int n=read();
        char ch1[15],ch2[15];
        cin>>ch1>>ch2;
        len=read(s+1);
        if(ch2[0]=='E'){//encode
            if(ch1[1]=='N') inorder();
            else if(ch1[1]=='R') preorder();
            else postorder();
            puts("");
        }else{//decode
            index_s0=1;
            if(ch1[1]=='N') decode_in();
            else if(ch1[1]=='R') decode_pre();
            else decode_post();
            layer();
        }
    }
    return 0;
}