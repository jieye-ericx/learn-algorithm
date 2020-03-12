#include <stdio.h>

int main(){
	double stu_scores[50][5]={0};
	double ave_per_stu_sco[50]={0};
	double ave_per_less[5]={0};
	int m_cnt=0,n_cnt=0;
	int n,m;
	while(scanf("%d%d",&n,&m)!=-1&&n<=50&&m<=5){
    m_cnt=0;n_cnt=0;
    for(int p=0;p<50;p++){
    	ave_per_stu_sco[p]=0.0;
    	for(int q=0;q<5;q++){
    		stu_scores[p][q]=0.0;
		}
	}
	for(int y=0;y<5;y++)
		ave_per_less[y]=0.0;
	//******************初始化********** 
	
	double dn=n,dm=m;
	while(n_cnt<n)
	{
		m_cnt=0;
		while(m_cnt<m)
		{
		scanf("%lf",&stu_scores[n_cnt][m_cnt]);
		m_cnt++;
		}
		n_cnt++;
	}
	for(int i=0;i<n;i++)
		ave_per_stu_sco[i]=(stu_scores[i][0]+stu_scores[i][1]+stu_scores[i][2]+stu_scores[i][3]+stu_scores[i][4])/dm;
	
	for(int t=0;t<m;t++) 
	{
			for(int x=0;x<n;x++)
			{
			ave_per_less[t]+=stu_scores[x][t];
			}
			ave_per_less[t]/dn;
			}
	int num=0,cnt=0;
	
	for(int t=0;t<n;t++) 
	{
		for(int x=0;x<m;x++)
		{
			if(stu_scores[t][x]>=ave_per_less[x])cnt++;
			else break;
		}
		if(cnt==m)num++;
		cnt=0;
	}
	
	
	for(int a=0;a<n;a++){
		printf("%.2lf",ave_per_stu_sco[a]);
		if(a!=n-1)printf(" ");
	}
	printf("\n");
	for(int b=0;b<m;b++){
		printf("%.2lf",ave_per_less[b]);
		if(b!=m-1) printf(" ");
	}
	printf("\n%d\n\n",num);
	
	//**********标准输出
} 
 return 0;
}
