   int  i = 2023, tmp =31 , j = x.year;
    int* m;
    if (whetherrun(j))
        m = F29;
	else 
        m = F28;
    
    for (i; i > 0; i--)
        tmp += m[i];
    
    for (j-1; j >1912; j--){
        if (whetherrun(j)){
            tmp += 366;
        } else {
            tmp += 365;
