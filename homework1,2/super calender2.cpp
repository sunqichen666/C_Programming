#include <stdio.h>

int countdays();
int whetherrun(int x);
int week();

int F29[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int F28[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int num, a1, a2, a3, whichday;

enum DAY {
    TUE,WED,THU,FRI,SAT,SUN,MON
};

typedef struct daytype{
    int year;
    int month;
    int day;
}daytype;
int f1(daytype x);
void f2(daytype x);
void f3(daytype x);

daytype nowday;
daytype base;

int main(){
	base.year = 2024, base.month = 10, base.day = 29; 
    printf("which function do you want to run?(1,2,3)\n");
    scanf("%d",&num);
    switch(num)
    {
        case 1:
            printf("请输入年月日，格式为（2024.10.29）\n");
            scanf("%d.%d.%d",&a1,&a2,&a3);
            nowday.year = a1;
            nowday.month = a2;
            nowday.day = a3;
            whichday = f1(nowday);
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
            break;
        case 2:
            printf("请输入年月，格式为（2024.10）\n");
            scanf("%d.%d",&a1,&a2);
            nowday.year = a1;
            nowday.month = a2;
            nowday.day = 1;
            f2(nowday);
            break;
        case 3:
            printf("请输入年月，格式为（2024）\n");
            scanf("%d",&a1);
            nowday.year = a1;
            nowday.month = 1;
            nowday.day = 1;
            f3(nowday);
            break;
        default:
            printf("This function is not existing");
            break;
    }
    return 0;
}

int countdays(daytype x) {
    int  i = x.month-1, tmp = x.day, j = x.year;
    int* m;
    if (whetherrun(j))
        m = F29;
	else 
        m = F28;
    
    for (i; i > 0; i--)
        tmp += m[i];
    j-=1;
    for (j; j >1912; j--){
        if (whetherrun(j)){
            tmp += 366;
        } else {
            tmp += 365;
        }
    }
    return tmp;
}

int whetherrun(int x){
    return ((x % 4 == 0 && x % 100!= 0) || (x % 400 == 0));
}

int week(int x)
{
    int tmp1 = x % 7;
    if(tmp1 < 0) tmp1 += 7;
    return tmp1;
}

int f1(daytype x){
	base.year = 2024, base.month = 10, base.day = 29; 
    int dayday,whichday;
    dayday = countdays(x) - countdays(base);
    whichday = week(dayday);
    return whichday;
}
void f2(daytype x){
	int day0,i,tmp,j;
	tmp=1;
	i=1;
	j=x.month;
	int* m;
    if (whetherrun(x.year))
        m = F29;
	else 
        m = F28;
	printf("日一二三四五六\n");
	day0=f1(x);
    switch(day0){
        case TUE:
        	i=2;
        	printf("    ");
        	break;
        case WED:
            i=3;
            printf("      ");
            break;
        case THU:
            i=4;
            printf("        ");
			break;
        case FRI:
            i=5;
            printf("          ");
            break;
		case SAT:
            i=6;
            printf("            ");
            break;
        case SUN:
            i=0;
            break;
        case MON:
            i=1;
            printf("  ");
            break;
        }
	while (tmp<=m[j])
	{
		printf("%d",tmp);
		if (tmp<10) printf(" ");
		if(i%7==6) printf("\n");
		i+=1;
		tmp+=1;
	} 
	
}  
void f3(daytype x){
	int i=1;
	while (i<=12){
		x.month=i;
		f2(x);
		printf("\n");
		i+=1;
                  	}
}
