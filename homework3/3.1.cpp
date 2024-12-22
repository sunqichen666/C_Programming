#include<stdio.h>
int main(){
	int a[5]={2,5,1,8,9};
	for (int k=0;k<5;k++){
		printf("%d",a[k]);
	} 
	printf("\n");
	printf("Ã°ÅÝÅÅÐò£¨ÉýÐò£©£¨1£© »òÊÇ Ñ¡ÔñÅÅÐò£¨½µÐò£©£¨2£©\n");
	int f;
	int tmp;
	scanf("%d",&f);
	if (f==1){
		for (int i=0;i<5;i++){
			for(int j=i+1;j<5;j++){
				if (a[i]>a[j]){
					tmp=a[j];
					a[j]=a[i];
					a[i]=tmp;
				} 
			}
		}
		for (int k=0;k<5;k++){
			printf("%d",a[k]);}
	}
	else if (f==2){
		int max;
		for (int i=0;i<5;i++){
			for(int j=i+1;j<5;j++){
				max=a[i];
				if (a[j]>max){
					max=a[j];}
			if (max!=a[i]){
				a[j]=a[i];
				a[i]=max;}
			}
			}
		
		for (int k=0;k<5;k++){
			printf("%d",a[k]);}		
		}
}

