/****************************************************************************
 *      Copyright:  (C) 2018 MINDA
 *                  All rights reserved.
 *
 *       Filename:  SCHOOL.CPP
 *    Description:  This program is used to manage staff information.
 *                  �������һ���оŸ�ģ�飺�ֱ�Ϊ��ȡ�����桢��ѯ��������޸ġ�
 *                  ����ɾ���������������˰������������
 *          Other:  no information.
 *        Version:  0.0.1(2018��06��28��)
 *         Author:  LeiZhenkuo <appler1998@qq.com>
 *      ChangeLog:  1, Release initial version on "2018��06��28�� 16ʱ49��00��"
 *  Function List:  read(): ��ȡ�ļ�
 *                  write(): д���ļ�
 *                  find(): ��ѯ����
 *                  list(): �������
 *                  modify(): �޸�����
 *                  del(): ɾ������
 *                  add(): ��������
 *                  grsds(double yfgz): �����������˰
 *****************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;
double grsds(double);//��˰��������
void write();
int n=0;//ȫ�ֱ���n�����ۼ���ṹ������±�
//-----------------------------------------------------------------------------
/*����ṹ��*/
struct List
{  
	char gonghao[9];//ѧ��
	char name[10];//����
	float gwgz;//��λ����
	float xjgz;//н������
	float zwjt;//ְλ����
	float jxgz;//��Ч����
	float yfgz;//Ӧ������
	float grsds;//��������˰
	float sfgz;//ʵ������
}woker[100];//�ṹ��woker����
//-----------------------------------------------------------------------------
/*��ȡְ����������*/
void read()
{
	List zg,*q;
	FILE *fp;//����fp��ָ�룬����ָ��FILE���͵Ķ���
	char ch;
	int i;
	q=&zg;
	if((fp=fopen("gx.dat","rb"))==NULL)//�ж��Ƿ���ļ��ɹ�
	{
		printf("�ļ������ڣ�����Ϊ���������ļ�!\n");
		write();
		printf("���´��ļ��������Ĳ���!");
		exit(-1);
	}
	for(i=0;i<=100;i++)
	{
		fseek(fp,i*sizeof(struct List),0);//�ļ�ָ�붨λ
		fread(q,sizeof(struct List),1,fp);//��ȡ�ļ�����
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
		if(ch==EOF)//�ж϶�ȡ�������������
		{
			break;
		}		
	}
	n=i;
	fclose(fp);	//�ر���
}
//-------------------------------------------------------------------------
/*����ְ���������ݺ���*/
void write()
{
	printf("������......!!\n");
	FILE *fp;
    int i;
    if ((fp = fopen("gx.dat", "wt")) == NULL)
	{
        printf("Don't open this file!\n");
    }
    for(i=0;i<n+1;i++)
		fwrite(&woker[i],sizeof(List),1,fp);//д���û��ռ仺����
	fclose(fp);
	printf("�ѱ���......");//�����ļ�
	system("pause");
	system("cls");
}
//-------------------------------------------------------------------------
/*��ѯְ���������ݺ���*/
void find()
{
	char num[10];
	gets(num);
	char number[9];
	printf("������Ҫ��ѯְ�����ݵĹ���!\n");
	scanf("%s",&number);
	for(int i=0;i<=n;i++)
	{
		if(strcmp(number,woker[i].gonghao)==0)
		{
			printf("���� ���� ��λ���� н������ ְ����� Ч������ Ӧ������ ��������˰ ʵ������\n");
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
			printf("δ��ѯ�������빤�ŵ�����!\n");
		}
	}
	system("pause");
	system("cls");
}
//------------------------------------------------------------------------
/*���ְ���������ݺ���*/
void list()
{	
	int num;
	int i=0;	
	for(;true;)
	{
		printf("����1�鿴��һҳ����2�鿴�ڶ�ҳ����0�˳����");
		scanf("%d",&num);
		switch(num)
		{
			case 1: 
				printf("���� ���� ��λ���� н������ ְ����� Ч������ Ӧ������ ��������˰ ʵ������\n");
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
				printf("�˳����...\n");
				break;
			default:			
				printf("��������ʾ����,����Ϊ��Ч����\n");
				break;
		}
		if(num==0)
			break;			
	}	
}
//------------------------------------------------------------------------
/*�޸�ְ���������ݺ���*/
void modify()
{
	char num[10];
	gets(num);
	char number[9];
	printf("������Ҫ�޸�ְ�����ݵĹ���!\n");
	scanf("%s",&number);
	for(int i=0;i<=n;i++)
	{
		if(strcmp(number,woker[i].gonghao)==0)//ѭ���Ա��ҵ���Ӧ����
		{
			printf("�������޸Ĺ���%s������",woker[i].gonghao);
			printf("������Ҫ�޸ĵľ�������!(��ʽ�밴,��1001 ���� 1000 1000 200 300 2500����)\n");
			printf("���� ��λ���� н������ ְ����� Ч������ Ӧ������\n");
			scanf("%s%f%f%f%f%f",&woker[i].name,&woker[i].gwgz,&woker[i].xjgz,&woker[i].zwjt,&woker[i].jxgz,&woker[i].yfgz);
			double p=woker[i].yfgz;
			woker[i].grsds=grsds(p);
			woker[i].sfgz=woker[i].yfgz-woker[i].grsds;
			printf("�������!\n");
			break;
		}
		else if(i==n)
		{
			printf("δ��ѯ�������빤�ŵ�����!��鹤�ź�...�����޸�....\n");
		}
	}
	system("pause");
	system("cls");
}
//----------------------------------------------------------------------
/*ɾ��ְ���������ݺ���*/
void del()
{
	char num[10];
	gets(num);
	char number[9];
	printf("������Ҫɾ��ְ�����ݵĹ���!\n");
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
			printf("��ɾ��!\n");
			i=0;
			break;
		}		
	}
	if(n+1==i)
	{
		printf("���鹤���Ƿ����!");
	}
	system("pause");
	system("cls");
}
//----------------------------------------------------------------------
/*���ְ���������ݺ���*/
void add()
{
	char num[10];
	gets(num);
	printf("�������ӵ���Ϣ����(��ʽ�밴,��1001 ���� 1000 1000 200 300 2500����)\n");
	printf("���� ���� ��λ���� н������ ְ����� Ч������ Ӧ������\n");
	scanf("%s%s%f%f%f%f%f",&woker[n+1].gonghao,&woker[n+1].name,&woker[n+1].gwgz,&woker[n+1].xjgz,&woker[n+1].zwjt,&woker[n+1].jxgz,&woker[n+1].yfgz);
	printf("��ѯ�ļ���!\n");
	for(int i=0;i<n+1;i++)
	{
		if(strcmp(woker[n+1].gonghao,woker[i].gonghao)==0)
		{
			cout<<"�ù����Ѵ��ڣ�����������\n"<<endl;
			scanf("%s%s%f%f%f%f%f",&woker[n+1].gonghao,&woker[n+1].name,&woker[n+1].gwgz,&woker[n+1].xjgz,&woker[n+1].zwjt,&woker[n+1].jxgz,&woker[n+1].yfgz);
			i=0;//���»ص���λ�ж�
		}
	}
	double p=woker[i].yfgz;
	woker[i].grsds=grsds(p);//����grsds()�����������˰
	woker[i].sfgz=woker[i].yfgz-woker[i].grsds;//����ʵ������
	n=n+1;
	printf("�������!!\n");
	system("pause");
	system("cls");
}
//---------------------------------------------------------------------
/*�����������˰*/
double grsds(double yfgz)
{
	double grsds;
	if(yfgz<=500)
		grsds=yfgz*0.05;                        //����500�ڵĸ�������˰�� 
	else if(500<yfgz&&yfgz<=2000)
		grsds=(yfgz-500)*0.1+500*0.05;                     // ����500-2000�ĸ�������˰��
	else if(2000<yfgz&&yfgz<=5000)                                                                                
		grsds=(yfgz-2000)*0.15+1500*0.1+500*0.05;               //����2000-5000�ڵĸ�������˰��
	else if(5000<yfgz&&yfgz<=20000)
		grsds=(yfgz-5000)*0.2+3000*0.15+1500*0.1+500*0.05;                     //����5000-20000�ڵĸ�������˰��
	else if(20000<yfgz&&yfgz<=40000)
		grsds=(yfgz-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;                   //����20000-40000�ڵĸ�������˰��
	else if(40000<yfgz&&yfgz<=60000)
		grsds=(yfgz-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;                  //����40000-60000�ڵĸ�������˰��
	else if(60000<yfgz&&yfgz<=80000)
		grsds=(yfgz-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;             //����60000-80000�ڵĸ�������˰��
	else if(80000<yfgz&&yfgz<=100000)
		grsds=(yfgz-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;           //����80000-100000�ڵĸ�������˰��
	else if(100000<yfgz)
		grsds=(yfgz-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;         //����100000���ϵĸ�������˰��
	return grsds;
}
//---------------------------------------------------------------------
/*������*/
int main()
{
	read();
	printf("   ###\t��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ\t###\n\n\n");
	
	int num;	
	for(;true;)//����ѭ���壨������������ѭ����
	{
		printf("=========================================================================\n|\t1.��ѯְ�����ʼ�¼\t\t\t\t\t\t|\n|\t2.�޸�ְ�����ʼ�¼\t\t\t\t\t\t|\n|\t3.���ְ�����ʼ�¼\t\t\t\t\t\t|\n|\t4.ɾ��ְ�����ʼ�¼\t\t\t\t\t\t|\n|\t5.�������ݵ��ļ�\t\t\t\t\t\t|\n|\t6.���ְ����¼\t\t\t\t\t\t\t|\n|\t7.�˳�ϵͳ\t\t\t\t\t\t\t|\n|\t8.�����˵�\t\t\t\t\t\t\t|\n=========================================================================\n");
		printf("���ѡ���ǣ�\n");
		scanf("%d",&num);
		printf("���������%d\n",num);
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
		case 7:printf("�˳�ϵͳ!���������.....\n");
			break;
		case 8:printf("=========================================================================\n|\t1.��ѯְ�����ʼ�¼\t\t\t\t\t\t|\n|\t2.�޸�ְ�����ʼ�¼\t\t\t\t\t\t|\n|\t3.���ְ�����ʼ�¼\t\t\t\t\t\t|\n|\t4.ɾ��ְ�����ʼ�¼\t\t\t\t\t\t|\n|\t5.�������ݵ��ļ�\t\t\t\t\t\t|\n|\t6.���ְ����¼\t\t\t\t\t\t\t|\n|\t7.�˳�ϵͳ\t\t\t\t\t\t\t|\n|\t8.�����˵�\t\t\t\t\t\t\t|\n=========================================================================\n");
			break;
	    default:			
			printf("������1~8������,����Ϊ��Ч����\n");
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