#include <stdio.h>
#include <stdlib.h>


void switch_col(int **a,int col1,int col2,int m){

for (int i=0;i<m;i++){
    int temp=a[i][col1];
    a[i][col1]=a[i][col2];
    a[i][col2]=temp;
    }

}


void task3(){


int **a;
a=(int**)malloc(9*sizeof(int*));
for (int i=0;i<9;i++){
    a[i]=(int*)malloc(9*sizeof(int));
}
printf("vvedite massiv 9x9\n");
for (int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        scanf("%d",&a[i][j]);
    }
}
int ans=0;
for (int i=0;i<4;i++){
    for(int j=i;j<9-i;j++){
        ans+=a[i][j];
        ans+=a[8-i][j];
    }
}
ans+=a[4][4];
printf("summa(perviy variant): %d\n",ans);
}

void task4(){

    printf("vvedite razmer massiva(dva chisla)\n");
    int m,n;
    scanf("%d%d",&m,&n);
    printf("vvedite massiv\n");
    int **a;
    a=(int**)malloc(sizeof(int)*m);
    int* sum_strok;
    sum_strok=(int*)malloc(sizeof(int)*m);
    int cur_sum=1;
    for (int i=0;i<m;i++){
        a[i]=(int*)malloc(sizeof(int)*n);
    }
    for (int i=0;i<m;i++){
            cur_sum=1;
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            cur_sum*=a[i][j];
        }
        sum_strok[i]=cur_sum;
        cur_sum=1;
    }

int* sum_col;
sum_col=(int*)malloc(sizeof(int)*n);
cur_sum=0;
for (int i=0;i<n;i++){
        cur_sum=0;
    for (int j=0;j<m;j++){
        cur_sum+=a[j][i];
    }
    sum_col[i]=cur_sum;
    cur_sum=0;
}

    for (int i=0;i<m;i++){
        for (int j=0;j<m-i-1;j++){
            if (sum_strok[j]>sum_strok[j+1]){
                int temp=sum_strok[j];
                sum_strok[j]=sum_strok[j+1];
                sum_strok[j+1]=temp;
                int *temp1=a[j];
                a[j]=a[j+1];
                a[j+1]=temp1;
            }
        }
    }

    for (int i=0;i<n;i++){
            for (int j=0;j<n-i-1;j++){
                if (sum_col[j]>sum_col[j+1]){
                    int temp=sum_col[j];
                    sum_col[j]=sum_col[j+1];
                    sum_col[j+1]=temp;
                    switch_col(a,j,j+1,m);
                }
            }
    }


    printf("vozrastanie proizvedeniy strok i summ stolbcov\n");
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }


}



int sort_matrix(double **a,int var,int n){
int swaps=0;
double *temp;
for (int i=var;i<n;i++){
    for (int j=var;j<n-1;j++){
        if (a[j][var]<a[j+1][var]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            swaps++;
        }
    }
}
return swaps;
}



int change_matrix(double **a,int n,int m){

    int sw=0;
for (int i=0;i<n;i++){
    sw+=sort_matrix(a,i,n);
    for (int j=i+1;j<n;j++){
        double kef=a[j][i]/a[i][i];
        for (int k=0;k<m;k++){
            a[j][k]-=a[i][k]*kef;
        }
    }
}
return sw;
}


void prohod_up(double **a,int n,int m){
for (int i=n-1;i>0;i--){
    for (int j=i-1;j>=0;j--){
        double kef=a[j][i]/a[i][i];
        for(int k=j;k<m;k++){
            a[j][k]-=a[i][k]*kef;
        }
    }
}

for (int i=0;i<n;i++){
    for (int j=i+1;j<m;j++){
        //printf("\n do %lf \n",a[i][j]);
        a[i][j]/=a[i][i];
        //printf("\n posle %lf \n",a[i][j]);
    }
    a[i][i]/=a[i][i];
}

}

double** matrix_mult(double **a,double **b,int  n){

double** ans;
ans=(double**)malloc(sizeof(double*)*n);
for (int i=0;i<n;i++){
    ans[i]=(double*)malloc(sizeof(double)*n);
}

double sum=0;

for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
        sum=0;
        for (int k=0;k<n;k++){
            sum+=a[i][k]*b[k][j];
        }
        ans[i][j]=sum;
        sum=0;
    }
}



return ans;
}



void task5(){

printf("vvedite kolichestvo uravneniy\n");
int n;
scanf("%d",&n);
printf("vvedite systemu\n");
double **a;
a=(double**)malloc(sizeof(double*)*n);
for (int i=0;i<n;i++){
    a[i]=(double*)malloc(sizeof(double)*(n+1));
}

for (int i=0;i<n;i++){
    for (int j=0;j<n+1;j++){
        scanf("%lf",&a[i][j]);
    }
}
change_matrix(a,n,n+1);

double *ans;
ans=(double*)malloc(sizeof(double)*n);
double left=0;
for (int i=n-1;i>=0;i--){
        left=0;
    for(int j=i+1;j<n;j++){
        left+=a[i][j]*ans[j];
    }
    a[i][n]-=left;
    ans[i]=a[i][n]/a[i][i];
left=0;
}

printf("\n otveti:\n");
for (int i=0;i<n;i++){
    printf("%lf ",ans[i]);
}

printf("\n");


}


void task6(){
printf("vvedite razmer matrici(odno chislo)\n");
int m;
scanf("%d",&m);
double **a;
double** p;
double** rev;

p=(double**)malloc(sizeof(double*)*m);
rev=(double**)malloc(sizeof(double*)*m);
for (int i=0;i<m;i++){
    p[i]=(double*)malloc(sizeof(double)*m);
    rev[i]=(double*)malloc(sizeof(double)*m);
}
a=(double**)malloc(sizeof(double*)*m);
for (int i=0;i<m;i++){
    a[i]=(double*)malloc(sizeof(double)*2*m);
}

printf("vvedite matricu\n");
for (int i=0;i<m;i++){
    for (int j=0;j<m;j++){
        scanf("%lf",&a[i][j]);
        p[i][j]=a[i][j];
    }
    for (int j=m;j<2*m;j++){
        a[i][j]=((j-m)==i);
    }
}

change_matrix(a,m,m*2);
prohod_up(a,m,m*2);

for (int i=0;i<m;i++){
    for (int j=m;j<2*m;j++){
        rev[i][j-m]=a[i][j];
    }
}

double** prov=matrix_mult(p,rev,m);

printf("obratnaya:\n");
for (int i=0;i<m;i++){
    for (int j=0;j<m;j++){
        printf("%lf ",rev[i][j]);
    }
    printf("\n");
}

printf("proverka:\n");


for (int i=0;i<m;i++){
    for (int j=0;j<m;j++){
        printf("%lf ",prov[i][j]);
    }
    printf("\n");
}

}

void task7(){
printf("vvedite razmer matrici(odno chislo)\n");
int n;
scanf("%d",&n);
double **a;
a=(double**)malloc(sizeof(double*)*n);
for (int i=0;i<n;i++){
    a[i]=(double*)malloc(sizeof(double)*n);
}
printf("vvedite matricu\n");
for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){\
        scanf("%lf",&a[i][j]);
    }
}

int swaps=change_matrix(a,n,n);
double opr=1;




for (int i=0;i<n;i++){
    opr*=a[i][i];
}
if (swaps%2 && opr!=0)
    opr=-opr;
printf("opredelitel:   %lf\n",opr);

}





int main()
{
    int request;
    while(1){
        printf("vvedite nomer zadachi(3-7) 0 dlya zaversheniya\n");
        scanf("%d",&request);
        if (request==3)
            task3();
        if (request==4)
            task4();
        if (request==5)
            task5();
        if (request==6)
            task6();
        if (request==7)
            task7();
        if (request==0)
            return 0;
        printf("\n");

    }


    task7();
    return 0;
}
