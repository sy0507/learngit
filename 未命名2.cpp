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
	for(fl=1;fl<=10;fl++,time++)//��¥,����Ż�����ð������Ѽ���begin�����ֵ�������Ϳ��ܿ���ʡȥ����ʱ�� 
	{
		for(i=0;i<5;i++)
		{
		   if(fl==stu[i].begin&&(stu[i].begin<stu[i].end))
		        time=max(time+1,stu[i].time+1);//��ߵ��ݾ�δ����֪�ˡ����ܵ��Ǹ��ˡ������벻������
			if(fl==stu[i].end&&fl!=stu[i].begin)
			     time+=1;
			      FILE *fpWrite=fopen("output.txt","w");
				 fprintf(fpWrite,"%dʱ��ͣ����%d¥\n",time,stu[i].end);
				 
		
	 } 	
}
}
   
