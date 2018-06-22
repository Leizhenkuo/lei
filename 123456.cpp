#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;
double grsds(double);
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
	cout<<"工号"<<" "<<"名字"<<" "<<"岗位工资"<<" "<<"薪级工资"<<" "<<"职务津贴"<<" "<<"效绩工资"<<" "<<"应发工资"<<" "<<"个人所得税"<<" "<<"实发工资"<<endl;
	for(i=0;i<5000;i++)
	{
		fseek(fp,i*sizeof(struct List),0);
		fread(q,sizeof(struct List),1,fp);
		cout<<q->gonghao<<"     "<<q->name<<"     "<<q->gwgz<<"     "<<q->xjgz<<"     "<<q->zwjt<<"     "<<q->jxgz<<"     "<<q->yfgz<<"     "<<q->grsds<<"     "<<q->sfgz<<endl;
		n=i;
		ch=fgetc(fp);
		if(ch==EOF)
		{
			printf("当前列为空结束当前读取\n");
			break;
		}
	}
	fclose(fp);
}
void write(List *q)//保存职工工资数据函数
{
	if(q->gwgz<0||q->gwgz>50000)
	{	
		cout<<"你还没有输入任何数据!!\n请输入有效的数据!"<<endl;
	}
	else
	{
		cout<<q->gonghao<<"     "<<q->name<<"     "<<q->gwgz<<"     "<<q->xjgz<<"     "<<q->zwjt<<"     "<<q->jxgz<<"     "<<q->yfgz<<"     "<<q->grsds<<"     "<<q->sfgz<<endl;	
		cout<<"保存中......!!"<<endl;	
		fstream f1("gx.dat",ios::out|ios::binary|ios::app);
		if(!f1)
		{
			cout<<"open gx.dat error!"<<endl;
			abort();
		}
		f1.write((char*)q,sizeof(List));
		n++;
		f1.close();
	}
}
void find()//查询职工工资数据函数
{
	cout<<"查询文件中!"<<endl;
	List worker,*q;
	FILE *fp;
	char ch;
	int i;
	q=&worker;
	char number[9];
	cout<<"输入你要查询的数据的工号"<<endl;
	cin>>number;
	if((fp=fopen("gx.dat","rb"))==NULL)
	{
		cout<<"Can't open this file!";
		getch();
		exit(-1);
	}
	cout<<"工号"<<" "<<"名字"<<" "<<"岗位工资"<<" "<<"薪级工资"<<" "<<"职务津贴"<<" "<<"效绩工资"<<" "<<"应发工资"<<" "<<"个人所得税"<<" "<<"实发工资"<<endl;
	for(i=0;i<5000;i++)
	{
		fseek(fp,i*sizeof(struct List),0);
		fread(q,sizeof(struct List),1,fp);
		if(strcmp(q->gonghao,number)==0)
		{
			cout<<q->gonghao<<"     "<<q->name<<"     "<<q->gwgz<<"     "<<q->xjgz<<"     "<<q->zwjt<<"     "<<q->jxgz<<"     "<<q->yfgz<<"     "<<q->grsds<<"     "<<q->sfgz<<endl;
		}
		n=i;
		ch=fgetc(fp);
		if(ch==EOF)
		{
			printf("当前列为空结束当前读取!如果未查询到数据请检查你的工号.......!!\n");
			break;
		}
	}
	fclose(fp);
}
void list()//浏览职工工资数据函数
{
	cout<<"浏览文件中!"<<endl;
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
	cout<<"工号"<<" "<<"名字"<<" "<<"岗位工资"<<" "<<"薪级工资"<<" "<<"职务津贴"<<" "<<"效绩工资"<<" "<<"应发工资"<<" "<<"个人所得税"<<" "<<"实发工资"<<endl;
	for(i=0;i<5000;i++)
	{
		fseek(fp,i*sizeof(struct List),0);
		fread(q,sizeof(struct List),1,fp);
		cout<<q->gonghao<<"     "<<q->name<<"     "<<q->gwgz<<"     "<<q->xjgz<<"     "<<q->zwjt<<"     "<<q->jxgz<<"     "<<q->yfgz<<"     "<<q->grsds<<"     "<<q->sfgz<<endl;
		n=i;
		ch=fgetc(fp);
		if(ch==EOF)
		{
			printf("当前列为空结束当前读取\n");
			break;
		}
	}
	fclose(fp);
}
void modify(List *q)//修改职工工资数据函数
{
	/*
	List woker[n];
	for(int i=0;i<n;i++)
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
		cout<<"工号"<<" "<<"名字"<<" "<<"岗位工资"<<" "<<"薪级工资"<<" "<<"职务津贴"<<" "<<"效绩工资"<<" "<<"应发工资"<<" "<<"个人所得税"<<" "<<"实发工资"<<endl;
		for(i=0;i<5000;i++)
		{
			fseek(fp,i*sizeof(struct List),0);
			fread(q,sizeof(struct List),1,fp);
			cout<<q->gonghao<<"     "<<q->name<<"     "<<q->gwgz<<"     "<<q->xjgz<<"     "<<q->zwjt<<"     "<<q->jxgz<<"     "<<q->yfgz<<"     "<<q->grsds<<"     "<<q->sfgz<<endl;
			ch=fgetc(fp);
			if(ch==EOF)
			{
				printf("当前列为空结束当前读取\n");
				break;
			}
		}
		fclose(fp);
	}
	*/
}
void del()//删除职工工资数据函数
{
}
void add(List *q)//添加职工工资数据函数
{
	List woker;
	cout<<"输入增加的信息！！"<<endl;
	cout<<"工号"<<" "<<"名字"<<" "<<"岗位工资"<<" "<<"薪级工资"<<" "<<"职务津贴"<<" "<<"效绩工资"<<" "<<"应发工资"<<endl;
	cin>>woker.gonghao>>woker.name>>woker.gwgz>>woker.xjgz>>woker.zwjt>>woker.jxgz>>woker.yfgz;
	cout<<"查询文件中!"<<endl;
	FILE *fp;
	char ch;
	int i;
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
		if(strcmp(woker.gonghao,q->gonghao)==0)
		{
			cout<<"该工号已存在，请重新输入"<<endl;
			cin>>woker.gonghao>>woker.name>>woker.gwgz>>woker.xjgz>>woker.zwjt>>woker.jxgz>>woker.yfgz;
		}
		n=i;
		ch=fgetc(fp);
		if(ch==EOF)
		{
			printf("");
			break;
		}
	}
	fclose(fp);
	strcpy(q->gonghao,woker.gonghao);
	strcpy(q->name,woker.name);
	q->gwgz=woker.gwgz;
	q->xjgz=woker.xjgz;
	q->zwjt=woker.zwjt;
	q->jxgz=woker.jxgz;
	q->yfgz=woker.yfgz;
	double p=woker.yfgz;
	q->grsds=grsds(p);
	q->sfgz=woker.yfgz-q->grsds;
	cout<<"输入结束!!当前保存输入信息....选择保存"<<endl;
}
double grsds(double yfgz)//计算个人所得税
{
	double grsds;
	if(yfgz<=500)
		grsds=yfgz*0.05;                        //计算500内的个人所得税。 
	else if(500<yfgz&&yfgz<=2000)
		grsds=(yfgz-500)*0.1+500*0.05;                     // 计算500-2000的个人所得税。
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
	List woker;
	cout<<"1.读取文件\n2.保存\n3.查询\n4.浏览\n5.修改\n6.删除\n7.增加\n8.退出\n9.弹出菜单"<<endl;
	int num;
	for(;true;)
	{	
		scanf("%d",&num);
	    switch(num)
		{
		case 1: read();
			break;
		case 2: write(&woker);
			break;
		case 3: find();
			break;
		case 4: list();
			break;
		case 5: modify(&woker);
			break;	   	  
	    case 6: del();
			break;		   	  	  
	    case 7: add(&woker);
			break;				   	   
		case 8:cout<<"退出当前!任意键结束....."<<endl;
			break;
		case 9:cout<<"1.读取文件\n2.保存\n3.查询\n4.浏览\n5.修改\n6.删除\n7.增加\n8.退出\n9.弹出菜单"<<endl;
			break;
	    default:			
			cout<<"输入1~8的数字"<<endl;
		}
		if(num==8)
			break;	
		else
			continue;
    };
    printf("\n");
    getchar();
    return 0;
}