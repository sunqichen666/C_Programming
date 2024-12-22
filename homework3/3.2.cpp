  #include<stdio.h>
int main(){
    int A[5][6] = {
        {'S', 'D', 'U', 'Y', 'E', 'S'},
        {'C', 'H', 'I', 'N', 'A', '!'},
        {'A', 'F', 'T', 'E', 'R', 'X'},
        {'h', 'e', 'r', 'o', 'a', 'b'},
        {'C', 'y', 'y', 'D', 'S', '!'}
    };
    int tmp1=0;int tmp2=0;int tmp=0;
	//每行先行内排序 
	for (int i=0;i<5;i++){
		for (int p=0;p<6;p++){
			for(int j=0;j<5-p;j++){
				if (A[i][j]>A[i][j+1]){
					tmp=A[i][j+1];
					A[i][j+1]=A[i][j];
					A[i][j]=tmp;
				} 
			}
		}
	}
	//做行间交换 
	for (int i=0;i<5;i++){
		for (int p=0;p<6;p++){
			tmp1+=A[i][p];
		}
		for(int j=i+1;j<5;j++){
			for (int p=0;p<6;p++){
				tmp2+=A[j][p];
			}
			if (tmp1>=tmp2){
				for (int p=0;p<6;p++){
					tmp=A[j][p];
					A[j][p]=A[i][p];
					A[i][p]=tmp;
				} 
			}
		}
	}
	//输出 
	for (int i=0;i<5;i++){
		for (int j=0;j<6;j++){
			printf("%c",A[i][j]);
		}
		printf("\n");
	}
}

