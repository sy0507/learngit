#include<stdio.h>
#define max(a,b)(a>b?a:b)
int main()
{
	struct elevator{
		int time;
		int begin;
		int end;
	};
	struct elevator stu[5],w;
	int i,fl,flag=0,time=0;
     FILE *fpRead=fopen("input.txt","r"); 
	for( i=0;i<5;i++)
	{
		fscanf(fpRead,"%d %d %d",&stu[i].time,&stu[i].begin,&stu[i].end);
		
	}
	fclose(fpRead);
	for(fl=1;fl<=10;fl++,time++)//上楼,这边优化，用冒泡排序把几个begin的最大值出来，就可能可以省去部分时间 
	{
		for(i=0;i<5;i++)
		{
		   if(fl==stu[i].begin&&(stu[i].begin<stu[i].end))
		        time=max(time+1,stu[i].time+1);//这边电梯就未卜先知了。还能等那个人。。。想不到了晕
			if(fl==stu[i].end&&fl!=stu[i].begin)
			     time+=1;
			      FILE *fpWrite=fopen("output.txt","w");
				 fprintf(fpWrite,"%d时，停靠在%d楼\n",time,stu[i].end);
				 
		
	 } 	
}
}
   
