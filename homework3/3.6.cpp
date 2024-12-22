#include<stdio.h>
int two_dim_array_access(int *x, int i, int j, int m ,int n,int C);
int main(){
	int A[2][3] = {{1,2,3},{4,5,6}};
	int a1=two_dim_array_access(&A[0][0],0,0,1,2,3);
	int a2=two_dim_array_access(&A[0][1],0,1,1,2,3);
	printf("%d,%d",a1,a2);
} 
int two_dim_array_access(int *x, int i, int j, int m ,int n,int C)
{
	int num=(m*C+n)-(i*C+j);
	x+=num;
	return *x;
}
