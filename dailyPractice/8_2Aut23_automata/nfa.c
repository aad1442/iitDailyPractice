#include<stdio.h>
int main()
{
    int n,m;
    int i,j,k;
    char psc,fsc;
    int ps,fs;

    printf("Enter the number of states: \n");
    scanf("%d",&n);
    char state[n];
    for(i=0;i<n;i++){
        scanf(" %c",&state[i]);
    }
    for(i=0;i<n;i++){
        printf("state %c\n ",state[i]);
    }
    printf("Enter the number of alphabet: \n");
    scanf("%d",&m);
    int alphabet[m];
    for(i=0;i<m;i++){
        scanf("%d",&alphabet[i]);
    }
    for(i=0;i<m;i++){
        printf("Alphabet:%d",alphabet[i]);
    }
     int s[n],a[m];
    int mat[n][m];
    printf("Enter the starting state: \n");
    scanf(" %c",&psc);
    printf("Enter the final state: \n");
    scanf(" %c",&fsc);
    for(i=0;i<n;i++){
        if(psc == state[i]){
            ps = i;
        }
        if(fsc == state[i]){
            fs =i;
        }
    }
    printf("present state = %d, final state = %d",ps,fs);

    printf("Enter the transition table: \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Enter the value of mat[%d][%d]",i,j);
            scanf("%d",&mat[i][j]);
        }
    }

      for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("[%d]",mat[i][j]);
        }
        printf("\n");
    }
    int strlength;

    printf("Enter the string length");
    scanf("%d",&strlength);
    int str[strlength];
    for(i=0;i<strlength;i++){
        scanf("%d",&str[i]);
    }

    for(i=0;i<strlength;i++){
        printf("\n%d\n",str[i]);
    }
    for(i=0;i<strlength;i++){
        ps= mat[ps][str[i]];
        printf("Now present state is %d\n",ps);
    }

    if(ps==fs){
        printf("Accepted");
    }else{
        printf("Rejected");
    }
    return 0;

}