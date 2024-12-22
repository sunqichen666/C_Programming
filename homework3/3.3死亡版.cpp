#include <stdio.h>
#include <stdlib.h>
int b[100][2];
int main(){
	int tmpb[12][2];
	int num=0;
	int flag=0;
	int tol=0;
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j+=1){
			b[num][0]=i;
			b[num][1]=j;
			num+=1;
			for (int r=i;r<8;r++){
				for (int c=j;c<8;c++){
					flag=0;
					for (int k=0;k<num;k++){
						if ((b[num][0]!=-1&&b[num][1]!=-1)&&(r==i||c==j)||(abs(r-i)==abs(c-i))){
							flag=1;
						}
					if 	(flag==0){
						b[num][0]=r;
						b[num][1]=c;
						num+=1;
					}
					if (num==12){
						tol+=1;
					}					
					}	
				}
			}
			if (num<12){
				num-=1;
				b[num][0]=-1;
				b[num][1]=-1;
			} 
			
		}
	}
	printf("%d",tol);
	
}
