#include<stdio.h>
void matrix_multi(double a[3][4], double b[4][5], double c[3][5]);
double a[3][4]={
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
	};
double b[4][5]={
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };
double c[3][5]={
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};
int main(){
	matrix_multi(a,b,c);
}
void matrix_multi(double a[3][4], double b[4][5], double c[3][5]){
	for (int i=0;i<3;i++){
		for (int j=0;j<5;j++){
			for (int p=0;p<4;p++){
					c[i][j]+=a[i][p]*b[p][j];
				}
			}
		}
	for (int i=0;i<3;i++){
		for (int j=0;j<5;j++){
			printf("%f",c[i][j]);
		}
		printf("\n");
	}
}

