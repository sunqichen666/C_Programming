#include <stdio.h>
#include <stdlib.h>
int check(int i,int j);
int queen(int i,int j);
int num=0;
int b[9][2]={{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};
//check函数用于判断位置是否满足放置要求 
int check(int i,int j){
	int flag=0;//满足放置要求 
	for (int k=0;k<num;k++){
		if ((b[k][0]==i)||(b[k][1]==j)||(abs(b[k][0]-i)==abs(b[k][1]-j))){
			flag=1;//不满足放置要求 
		}
	}
	return flag;
}
//queen用于实现深搜算法(以（i，j）为第一个皇后的位置遍历棋盘） 
int queen(int i,int j){
	int total=0;
	b[0][0]=i;
	b[0][1]=j;
	while (i<8){
		j++;
		if (j>7){
			j=j%8;
			i++;
		} 
		int flag=check(i,j);
		if (flag==0){
			num+=1;
			b[num][0]=i;
			b[num][1]=j;
		}
		if (num==7){
			total+=1;
			i=b[0][0];
			j=b[0][1]+1;
			if (j>=8){
				j=j%8;
				i++;}
			for (num;num>0;num--){
				b[num][0]=-1;
				b[num][1]=-1;
			}
		}
	} 
	//遍历到棋盘右下角却没有摆放8皇后，溯回 
	if (num<7&&i>7&&j>7){
		while(num>=0&&num<7){
			int p=b[num][0];
			int q=b[num][1]+1;
			if (q>7){
				q=q%8;
				p++;
			}
			b[num][0]=-1;
			b[num][1]=-1;
			total+=queen(p,q);
		}
	}
}
int main(){
	int all=0;
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			all+=queen(i,j);
		}
	}
	printf("%d",all);
}
 
