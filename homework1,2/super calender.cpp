#include<stdio.h>
int countdays();
int whetherrun();
int week();
int f1();
void f2();
void f3();
int F29[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int F28[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int num,a1,a2,a3,whichday;
enum DAY {
	TUE,WED,THU,FRI,SAT,SUN,MON
};
typedef struct daytype{
	int year;
	int month;
	int day;
}daytype;
daytype nowday;
daytype base;
base.year=2024,base.month=10,base.day=29; 
int main(){

	printf("which function do you want to run?(1,2,3)\n");
	scanf("%d",&num);
	switch(num)
	{
		case 1:
			printf("请输入年月日，格式为（2024.10.29）\n");
			scanf("%d,%d,%d",&a1,&a2,&a3);
			nowday.year=a1,nowday.month=a2,nowday.day=a3;
			whichday= f1(nowday);
			switch(whichday){
				case TUE:
					printf("星期二");
					break;
				case WED:
					printf("星期三");
					break;
				case THU:
					printf("星期四");
					break;
				case FRI:
					printf("星期五");
					break;
				case SAT:
					printf("星期六");
					break;
				case SUN:
					printf("星期天");
					break;
				case MON:
					printf("星期一");
					break;
			}			

			
		case 2:
			printf("请输入年月，格式为（2024.10）\n");
			scanf("%d,%d",&a1,&a2);
			nowday.year=a1,nowday.month=a2,nowday.day=1;
			f2(nowday);
		case 3:
			printf("请输入年月，格式为（2024）\n");
			scanf("%d,",&a1);
			nowday.year=a1,nowday.month=1,nowday.day=1;
			f3(nowday);	
		default:
			printf("This function is not existing");		
			
	}
	return 0;
}
int countdays(daytype x)
{
	int monthday,i=x.month,tmp=x.day,j=x.year;
	int m[]{13};
	if (whetherrun(x)){
		m[]=F29;
	}
	else{
		m[]=F28;
	}	
	for (i;i>0;i--){
		tmp+=m[i];
	}
	for (j;j>1912;j--){
		if (whetherrun(j)){
			tmp+=366;
		}
		else{
			tmp+=365;
		}
	}
	return tmp;
}
int whetherrun (int x){
	if(x%4==0&&x%100!=0)||(x%400==0)
		return 0;
	else
		return 1;
}
int week(int x)
{
	int tmp1=x%7;
	if(tmp1<0) tmp1+=7;
	return tmp1;
}
int f1(daytype x){
	int dayday,whichday;
	dayday=countdays(x)-countdays(base);
	whichday=week(dayday);
	return whichday;
}

