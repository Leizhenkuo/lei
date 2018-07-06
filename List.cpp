/****************************************************************************
 *      Copyright:  (C) 2018 MINDA
 *                  All rights reserved.
 *
 *       Filename:  SCHOOL.CPP
 *    Description:  This program is used to manage staff information.
 *                  这个程序一共有九个模块：分别为读取、保存、查询、浏览、修改、
 *                  增添、删除、计算个人所得税、和主函数。
 *          Other:  no information.
 *        Version:  0.0.1(2018年06月28日)
 *         Author:  LeiZhenkuo <appler1998@qq.com>
 *      ChangeLog:  1, Release initial version on "2018年06月28日 16时49分00秒"
 *  Function List:  read(): 读取文件
 *                  write(): 写入文件
 *                  find(): 查询数据
 *                  list(): 浏览数据
 *                  modify(): 修改数据
 *                  del(): 删除数据
 *                  add(): 增加数据
 *                  grsds(double yfgz): 计算个人所得税
 *****************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;
double grsds(double);//计税函数声明
void write();
int n=0;//全局变量n用于累计算结构体组的下标
//-----------------------------------------------------------------------------
/*定义结构体*/
struct List
{  
	char gonghao[9];//学号
	char name[10];//姓名
	float gwgz;//岗位工资
	float xjgz;//薪级工资
	float zwjt;//职位津贴
	float jxgz;//绩效工资
	float yfgz;//应发工资
	float grsds;//个人所得税
	float sfgz;//实发工资
}woker[100];//结构体woker定义
//-----------------------------------------------------------------------------
/*读取职工工资数据*/
void read()
{
	List zg,*q;
	FILE *fp;//声明fp是指针，用来指向FILE类型的对象。
	char ch;
	int i;
	q=&zg;
	if((fp=fopen("gx.dat","rb"))==NULL)//判断是否打开文件成功
	{
		printf("文件不存在，正在为您创建新文件!\n");
		write();
		printf("重新打开文件继续您的操作!");
		exit(-1);
	}
	for(i=0;i<=100;i++)
	{
		fseek(fp,i*sizeof(struct List),0);//文件指针定位
		fread(q,sizeof(struct List),1,fp);//读取文件数据
		strcpy(woker[i].gonghao,q->gonghao);
		strcpy(woker[i].name,q->name);
		woker[i].gwgz=q->gwgz;
		woker[i].xjgz=q->xjgz;
		woker[i].zwjt=q->zwjt;
		woker[i].jxgz=q->jxgz;
		woker[i].yfgz=q->yfgz;
		double p=woker[i].yfgz;
		woker[i].grsds=grsds(p);
		woker[i].sfgz=woker[i].yfgz-woker[i].grsds;	
		ch=fgetc(fp);
		if(ch==EOF)//判断读取到最后无数据行
		{
			break;
		}		
	}
	n=i;
	fclose(fp);	//关闭流
}
//-------------------------------------------------------------------------
/*保存职工工资数据函数*/
void write()
{
	printf("保存中......!!\n");
	FILE *fp;
    int i;
    if ((fp = fopen("gx.dat", "wt")) == NULL)
	{
        printf("Don't open this file!\n");
    }
    for(i=0;i<n+1;i++)
		fwrite(&woker[i],sizeof(List),1,fp);//写到用户空间缓冲区
	fclose(fp);
	printf("已保存......");//保存文件
	system("pause");
	system("cls");
}
//-------------------------------------------------------------------------
/*查询职工工资数据函数*/
void find()
{
	char num[10];
	gets(num);
	char number[9];
	printf("输入你要查询职工数据的工号!\n");
	scanf("%s",&number);
	for(int i=0;i<=n;i++)
	{
		if(strcmp(number,woker[i].gonghao)==0)
		{
			printf("工号 名字 岗位工资 薪级工资 职务津贴 效绩工资 应发工资 个人所得税 实发工资\n");
			printf("%s  ",woker[i].gonghao);		
			printf("%s  ",woker[i].name);	
			printf("%.0f  ",woker[i].gwgz);
			printf("%.0f   ",woker[i].xjgz);
			printf("%.0f   ",woker[i].zwjt);
			printf("%.0f   ",woker[i].xjgz);
			printf("%.0f   ",woker[i].yfgz);
			printf("%.0f   ",woker[i].grsds);	
			printf("%.0f   ",woker[i].sfgz);	
			printf("\n");		
			break;
		}
		else if(i==n)
		{
			printf("未查询到你输入工号的数据!\n");
		}
	}
	system("pause");
	system("cls");
}
//------------------------------------------------------------------------
/*浏览职工工资数据函数*/
void list()
{	
	int num;
	int i=0;	
	for(;true;)
	{
		printf("输入1查看第一页输入2查看第二页输入0退出浏览");
		scanf("%d",&num);
		switch(num)
		{
			case 1: 
				printf("工号 名字 岗位工资 薪级工资 职务津贴 效绩工资 应发工资 个人所得税 实发工资\n");
				for(i=0;i<=n;i++)
				{
					printf("%s  ",woker[i].gonghao);
					printf("%s  ",woker[i].name);
					printf("%.0f  ",woker[i].gwgz);
					printf("%.0f   ",woker[i].xjgz);
					printf("%.0f   ",woker[i].zwjt);
					printf("%.0f   ",woker[i].xjgz);
					printf("%.0f   ",woker[i].yfgz);
					printf("%.0f   ",woker[i].grsds);
					printf("%.0f   ",woker[i].sfgz);
					printf("\n");
					if(i==(n/2))
					{
						system("pause");
						system("cls");
						break;	
					}
				}	
				break;
			case 2:
				for(i=(n/2);i<=n;i++)
				{
					printf("%s  ",woker[i].gonghao);
					printf("%s  ",woker[i].name);
					printf("%.0f  ",woker[i].gwgz);
					printf("%.0f   ",woker[i].xjgz);
					printf("%.0f   ",woker[i].zwjt);
					printf("%.0f   ",woker[i].xjgz);
					printf("%.0f   ",woker[i].yfgz);
					printf("%.0f   ",woker[i].grsds);
					printf("%.0f   ",woker[i].sfgz);
					printf("\n");
				}
				system("pause");
				system("cls");
				break;
			case 0:
				printf("退出浏览...\n");
				break;
			default:			
				printf("请输入提示数字,其他为无效操作\n");
				break;
		}
		if(num==0)
			break;			
	}	
}
//------------------------------------------------------------------------
/*修改职工工资数据函数*/
void modify()
{
	char num[10];
	gets(num);
	char number[9];
	printf("输入你要修改职工数据的工号!\n");
	scanf("%s",&number);
	for(int i=0;i<=n;i++)
	{
		if(strcmp(number,woker[i].gonghao)==0)//循环对比找到对应数据
		{
			printf("你正在修改工号%s的数据",woker[i].gonghao);
			printf("输入你要修改的具体数据!(格式请按,例1001 张三 1000 1000 200 300 2500输入)\n");
			printf("名字 岗位工资 薪级工资 职务津贴 效绩工资 应发工资\n");
			scanf("%s%f%f%f%f%f",&woker[i].name,&woker[i].gwgz,&woker[i].xjgz,&woker[i].zwjt,&woker[i].jxgz,&woker[i].yfgz);
			double p=woker[i].yfgz;
			woker[i].grsds=grsds(p);
			woker[i].sfgz=woker[i].yfgz-woker[i].grsds;
			printf("输入完成!\n");
			break;
		}
		else if(i==n)
		{
			printf("未查询到你输入工号的数据!检查工号后...重新修改....\n");
		}
	}
	system("pause");
	system("cls");
}
//----------------------------------------------------------------------
/*删除职工工资数据函数*/
void del()
{
	char num[10];
	gets(num);
	char number[9];
	printf("输入你要删除职工数据的工号!\n");
	scanf("%s",&number);
	for(int i=0;i<=n;i++)
	{
		if(strcmp(number,woker[i].gonghao) == 0)
		{
			for(int j=i;j<=n;j++)
			{
				woker[j]=woker[j+1];
			}
			n--;
			printf("已删除!\n");
			i=0;
			break;
		}		
	}
	if(n+1==i)
	{
		printf("请检查工号是否存在!");
	}
	system("pause");
	system("cls");
}
//----------------------------------------------------------------------
/*添加职工工资数据函数*/
void add()
{
	char num[10];
	gets(num);
	printf("输入增加的信息！！(格式请按,例1001 张三 1000 1000 200 300 2500输入)\n");
	printf("工号 名字 岗位工资 薪级工资 职务津贴 效绩工资 应发工资\n");
	scanf("%s%s%f%f%f%f%f",&woker[n+1].gonghao,&woker[n+1].name,&woker[n+1].gwgz,&woker[n+1].xjgz,&woker[n+1].zwjt,&woker[n+1].jxgz,&woker[n+1].yfgz);
	printf("查询文件中!\n");
	for(int i=0;i<n+1;i++)
	{
		if(strcmp(woker[n+1].gonghao,woker[i].gonghao)==0)
		{
			cout<<"该工号已存在，请重新输入\n"<<endl;
			scanf("%s%s%f%f%f%f%f",&woker[n+1].gonghao,&woker[n+1].name,&woker[n+1].gwgz,&woker[n+1].xjgz,&woker[n+1].zwjt,&woker[n+1].jxgz,&woker[n+1].yfgz);
			i=0;//重新回到零位判断
		}
	}
	double p=woker[i].yfgz;
	woker[i].grsds=grsds(p);//调用grsds()计算个人所得税
	woker[i].sfgz=woker[i].yfgz-woker[i].grsds;//计算实发工资
	n=n+1;
	printf("输入结束!!\n");
	system("pause");
	system("cls");
}
//---------------------------------------------------------------------
/*计算个人所得税*/
double grsds(double yfgz)
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
//---------------------------------------------------------------------
/*主函数*/
int main()
{
	read();
	printf("   ###\t欢迎使用广西民族大学软件与信息安全学院职工工资管理系统\t###\n\n\n");
	
	int num;	
	for(;true;)//无限循环体（以条件来结束循环）
	{
		printf("=========================================================================\n|\t1.查询职工工资记录\t\t\t\t\t\t|\n|\t2.修改职工工资记录\t\t\t\t\t\t|\n|\t3.添加职工工资记录\t\t\t\t\t\t|\n|\t4.删除职工工资记录\t\t\t\t\t\t|\n|\t5.保存数据到文件\t\t\t\t\t\t|\n|\t6.浏览职工记录\t\t\t\t\t\t\t|\n|\t7.退出系统\t\t\t\t\t\t\t|\n|\t8.弹出菜单\t\t\t\t\t\t\t|\n=========================================================================\n");
		printf("你的选择是：\n");
		scanf("%d",&num);
		printf("你输入的是%d\n",num);
	    switch(num)
		{
		case 1: find();
			break;
		case 2: modify();
			break;
		case 3: add();
			break;
		case 4: del();
			break;
		case 5:write();
			break;
		case 6: list();
			break;	   	  			   	   
		case 7:printf("退出系统!任意键结束.....\n");
			break;
		case 8:printf("=========================================================================\n|\t1.查询职工工资记录\t\t\t\t\t\t|\n|\t2.修改职工工资记录\t\t\t\t\t\t|\n|\t3.添加职工工资记录\t\t\t\t\t\t|\n|\t4.删除职工工资记录\t\t\t\t\t\t|\n|\t5.保存数据到文件\t\t\t\t\t\t|\n|\t6.浏览职工记录\t\t\t\t\t\t\t|\n|\t7.退出系统\t\t\t\t\t\t\t|\n|\t8.弹出菜单\t\t\t\t\t\t\t|\n=========================================================================\n");
			break;
	    default:			
			printf("请输入1~8的数字,其他为无效操作\n");
			break;
		}
		if(num==7)
			break;	
		else
			continue;
    };
    printf("\n");
    getchar();
    return 0;
}
//----------------------------------------------------------------------