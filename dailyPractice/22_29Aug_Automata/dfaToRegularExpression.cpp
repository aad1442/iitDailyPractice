#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dfa[3][2];
char RE[3][3][10];
char RE1[3][3][100];
char RE2[3][3][100];
int main()
{
    freopen("table.txt","r",stdin);
    printf("Enter the transition table: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
           // printf("For %d state if %d is encounterd move to-",i,j);
            scanf("%d",&dfa[i][j]);
        }
    }

    printf("Transition table-\n");

    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            printf("%d ",dfa[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                if(j==dfa[i][k]){
                    if(k==0) strcat(RE[i][j],"0");
                    else if(k==1) strcat(RE[i][j],"1");
                    if(i==j) strcat(RE[i][j]," + e");
                }
        }
        }

    }
    printf("Enter the value of R[0][i][j]\n");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                //printf("Enter RE[%d][%d]",i,j);
                scanf("%s",&RE[i][j]);
            }
        }

    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            printf("RE(0)%d%d %s\n",j,k,RE[j][k]);
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int k=1;
            strcat(RE1[i][j],RE[i][j]);
            strcat(RE1[i][j],"+");
            strcat(RE1[i][j],RE[i][k]);
//            if(RE[k][k]!=""){
            strcat(RE1[i][j],"(");
            strcat(RE1[i][j],RE[k][k]);
            strcat(RE1[i][j],")*");
//
//            }
            strcat(RE1[i][j],RE[k][j]);
        }
    }
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            printf("RE(1)%d%d %s\n",j,k,RE1[j][k]);
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int k=2;
            strcat(RE2[i][j],RE1[i][j]);
            strcat(RE2[i][j],"+");
            strcat(RE2[i][j],RE1[i][k]);
            if(RE1[k][k]!=""){
            strcat(RE2[i][j],"(");
            strcat(RE2[i][j],RE1[k][k]);
            strcat(RE2[i][j],")*");

            }
            strcat(RE2[i][j],RE1[k][j]);
        }
    }
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            printf("RE(2)%d%d %s\n",j,k,RE2[j][k]);
        }
    }
    return 0;
}
