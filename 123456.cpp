#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int n=0;
struct List
{  
	char gonghao[9];
	char name[10];
	float gwgz;
	float xjgz;
	float zwjt;
	float jxgz;
	float yfgz;
	float grsds;
	float sfgz;
};
void read()//读取职工工资数据
{
	cout<<"读取文件中!"<<endl;
	List worker,*q;
	FILE *fp;
	char ch;
	int i;
	q=&worker;
	if((fp=fopen("gx.dat","rb"))==NULL)
	{
		cout<<"Can't open this file!";
		getch();
		exit(-1);
	}
	for(i=0;i<5000;i++)
	{
		fseek(fp,i*sizeof(struct List),0);
		fread(q,sizeof(struct List),1,fp);
		cout<<q->gonghao<<" "<<q->name<<" "<<q->gwgz<<" "<<q->xjgz<<" "<<q->zwjt<<" "<<q->jxgz<<" "<<q->yfgz<<" "<<q->grsds<<" "<<q->sfgz<<endl;
		n=i;
		ch=fgetc(fp);
		if(ch==EOF)
		{
			printf("当前文件为空结束当前读取\n");
			break;
		}
	}
	fclose(fp);
}
void write()//保存职工工资数据函数
{
}
void find()//查询职工工资数据函数
{
}
void list()//浏览职工工资数据函数
{
}
void modify()//修改职工工资数据函数
{
}
void del()//删除职工工资数据函数
{
}
void add()//添加职工工资数据函数
{
}
double grsds()//计算个人所得税
{
	double yfgz,grsds;
	yfgz=zggz[a].gwgz+zggz[a].xjgz+zggz[a].zwjt+zggz[a].jxgz;
	if(yfgz<=500)
		grsds=yfgz*0.05;                        //计算500内的个人所得税。 
	else if(500<yfgz&&yfgz<=2000)
		grsds=(yfgz-500)0.1+500*0.05;                     // 计算500-2000的个人所得税。
	else if(2000<yfgz&&yfgz<=5000)                                                                                
		grsds=(yfgz-2000)*0.15+1500*0.1+500*0.05;               //计算2000-5000内的个人所得税。
	else if(5000<yfgz&&yfgz<=20000)
		grsds=(yfgz-5000)*0.2+3000*0.15+1500*0.1+500*0.05;                     //计算5000-20000内的个人所得税。
	else if(20000<yfgz&&yfgz<=40000)
		grsds=(yfgz-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;                   //计算20000-40000内的个人所得税。
	else if(40000<yfgz&&yfgz<=60000)
		grsds=(yfgz-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;                  //计算40000-60000内的个人所得税。
	else if(60000<yfgz&&yfgz<=80000)
		grsds=(yfgz-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;             //计算60000-80000内的个人所得税。
	else if(80000<yfgz&&yfgz<=100000)
		grsds=(yfgz-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;           //计算80000-100000内的个人所得税。
	else if(100000<yfgz)
		grsds=(yfgz-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;         //计算100000以上的个人所得税。
	return grsds;
}
int main()//主函数
{
	cout<<"1.读取文件\n2.输入\n3.查询\n4.修改\n5.添加\n6.删除\n7.增加\n8.计税\n9.退出"<<endl;
	int num;
	for(;true;)
	{	
		scanf("%d",&num);
	    switch(num)
		{
		case 1: read();
			break;
		case 2: write();
			break;
		case 3: find();
			break;
		case 4: list();
			break;
		case 5: modify();
			break;	   	  
	    case 6: del();
			break;		   	  	  
	    case 7: add();
			break;				   	   
	    case 8: grsds();
			break;
		case 9:cout<<"退出当前!任意键结束....."<<endl;
			break;
	    default:			
			cout<<"输入1~9的数字"<<endl;
		}
		if(num==9)
			break;	
		else
			continue;
    };
    printf("\n");
    getchar();
    return 0;
}