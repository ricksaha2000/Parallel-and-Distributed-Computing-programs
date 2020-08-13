#include <omp.h>
#define _GNU_SOURCE
#include<stdio.h>
#include <sched.h>
int main()
{
int i;
int n;
scanf("%d",&n);
int a[n];
int even[n];
int odd[n];
int sume;int sumo;
for(int j=0;j<n;j++){
even[j]=0;
odd[j]=0;
}
for(int k=0;k<n;k++){
int u;
scanf("%d",&u);
a[k]=u;
}
#pragma omp parallel for schedule(static,2)
for(i=0;i<n;i++)
{
if(a[i]%2==0){
even[i]=a[i];
}
else{odd[i]=a[i];}
}
printf("even numbers :");
for(int l=0;l<n;l++){
if(even[l]!=0)
printf("%d \n",even[l]);
}
printf("odd numbers :");
for(int l=0;l<n;l++){
if(odd[l]!=0)
printf("%d\n",odd[l]);
}#pragma omp parallel for reduction(+:sume)
for (int p=0; p < n; p++)
{
sume += even[p];
}
printf("The sum of even numbers is %d\n",sume);
#pragma omp parallel for reduction(+:sumo)
for (int p=0; p < n; p++)
{
sumo += odd[p];
}
printf("The sum of odd numbers is %d\n",sumo);
}
