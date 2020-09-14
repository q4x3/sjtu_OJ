
#include"iostream"
#include"ctime"
#include"cstdlib"
#define MAX 200000
using namespace std; 
struct element{     //用来排序的数据结构 
		int data;  // 数据 
		int index;  // 序号 
};
int cmp(const void *a,const void *b); //升序排列 
void rand_of_n(int a[],int n);  //产生 1-n 的随机排列并存到 a[] 中 
int main(){
	freopen("a1.in", "w", stdout);
	int a[MAX];
	int i,n;
    cin >> n;
	rand_of_n(a,n);   
	for(i=0;i<n;i++)
		cout<<"* "<<a[i]<<endl;
    //cout << endl;
	return 0; 
}
 
int cmp(const void *a,const void *b){   // 升序排序
	return((struct element*)a)->data - ((struct element*)b)->data;
}
void rand_of_n(int a[],int n){
	int i;
	struct element ele[MAX];
	srand((int)time(0));  // 初始化随机数种子 
	for(i=0;i<n;i++){
		ele[i].data=rand();  // 随机生成一个数 
		ele[i].index=i;
	}
	qsort(ele,n,sizeof(ele[0]),cmp);  //排序 
	for(i=0;i<n;i++){
		a[i]=ele[i].index;
	}
}