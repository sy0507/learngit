#include<iostream>
#include<cstdio>
using namespace std;
typedef struct
{
	int begin,end,time,et;
}YY;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	YY man[6];
	int i,j,tt=0;
	for( i=0;i<5;i++ )
		{
			cin>>man[i].time>>man[i].begin>>man[i].end;
		}
	int stop,wt;
	wt=0;
	for( i=1;i<=10;i++ )
		{		
			stop=0;
			wt=0;
			for( j=0;j<5;j++)
				{
					if	( man[j].begin<man[j].end&&man[j].begin==i )
						{
							stop=1;
							wt=max(wt,tt);
							wt=max(wt,man[j].begin);
						}
					if	( man[j].end==i &&  man[j].begin<man[j].end )
						{
							stop=1;
							man[j].et=tt;
						}
				}
			if	( wt>tt )
				tt=wt;
			else if	( stop==1 )
				tt++;
			if	( i!=10 )
				tt++;
		}
	for( i=10;i>=1;i-- )
		{
			
			stop=0;
			for( j=0;j<5;j++)
				{
					if	( man[j].begin>man[j].end )
						{
							stop=1;
							wt=max(wt,tt);
							wt=max(wt,man[j].begin);
						}
					if	( man[j].end==i &&  man[j].begin>man[j].end )
						{
							stop=1;
							man[j].et=tt;
						}
				}
			if	( wt>tt )
				tt=wt;
			else if	( stop==1 )
				tt++;
		}
	int sum=0;
	for( i=0;i<5;i++)
		{
			printf("%dÊ±£¬Í£¿¿ÔÚ%dÂ¥\n",man[i].et,man[i].end);
			sum+=man[i].et-man[i].time;
		}
	printf("%d",sum);
	return 0;
}

