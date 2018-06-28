#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;
double grsds(double);//计税函数声明
int n=0;//全局变量n用于累计算结构体组的下标
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
}woker[100];//结构体woker定义
void read()//读取职工工资数据
{
	printf("读取文件中......\n");
	List zg,*q;
	FILE *fp;//声明fp是指针，用来指向FILE类型的对象。
	char ch;
	int i;
	q=&zg;
	if((fp=fopen("gx.dat","rb"))==NULL)//判断是否打开文件成功
	{
		printf("Can't open this file!\n");
		getch();
		exit(-1);
	}
	for(i=0;i<5000;i++)
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
			printf("当前列为空结束当前读取\n");
			break;
		}		
	}
	n=i;
	fclose(fp);	//关闭流
	printf("读取完成!!请选择操作!");
}
void write()//保存职工工资数据函数
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
	fclose(fp);//保存文件
}
void find()//查询职工工资数据函数
{
	char number[9];
	printf("输入你要查询职工数据的工号!\n");
	scanf("%d",&number);
	for(int i=0;i<=n;i++)
	{
		if(strcmp(number,woker[i].gonghao) == 0)
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
}
void list()//浏览职工工资数据函数
{
	printf("正在浏览\n");
	printf("工号 名字 岗位工资 薪级工资 职务津贴 效绩工资 应发工资 个人所得税 实发工资\n");
	for(int i=0;i<=n;i++)
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
}
void modify()//修改职工工资数据函数
{
	int j=0;
	char number[9];
	printf("输入你要修改职工数据的工号!\n");
	scanf("%d",&number);
	for(int i=0;i<=n;i++)
	{
		if(strcmp(number,woker[i].gonghao) == 0)
		{
			printf("输入修改信息");
			printf("工号 名字 岗位工资 薪级工资 职务津贴 效绩工资 应发工资\n");
			scanf("%s%s%f%f%f%f%f",&woker[i].gonghao,&woker[i].name,&woker[i].gwgz,&woker[i].xjgz,&woker[i].zwjt,&woker[i].jxgz,&woker[i].yfgz);
			double p=woker[i].yfgz;
			woker[i].grsds=grsds(p);
			woker[i].sfgz=woker[i].yfgz-woker[i].grsds;
			printf("输入完成!\n");
		}		
		else if(i==n+1)
		{
			printf("请检查工号是否存在!\n");
		}	
	}
}
void del()//删除职工工资数据函数
{
	char number[9];
	printf("输入你要删除职工数据的工号!\n");
	scanf("%d",&number);
	for(int i=0;i<=n;i++)
	{
		if(strcmp(number,woker[i].gonghao) == 0)
		{
			for(int j=0;j<=n;j++)
			{
				woker[j]=woker[j+1];
			}
			n--;
			printf("已删除!\n");
		}
		else if(i==n+1)
		{
			printf("请检查工号是否存在!\n");
		}		
	}
}
void add()//添加职工工资数据函数
{
	printf("输入增加的信息！！\n");
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
		continue;
	}
	double p=woker[i].yfgz;
	woker[i].grsds=grsds(p);//调用grsds()计算个人所得税
	woker[i].sfgz=woker[i].yfgz-woker[i].grsds;//计算实发工资
	n=n+1;
	printf("输入结束!!\n");
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
	printf("1.读取文件\n2.保存\n3.查询\n4.浏览\n5.修改\n6.删除\n7.增加\n8.退出\n9.弹出菜单");
	int num;
	for(;true;)//无限循环体（以条件来结束循环）
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
		case 8:printf("退出当前!任意键结束.....\n");
			break;
		case 9:printf("1.读取文件\n2.保存\n3.查询\n4.浏览\n5.修改\n6.删除\n7.增加\n8.退出\n9.弹出菜单\n");
			break;
	    default:			
			printf("输入1~8的数字\n");
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