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
void read()//��ȡְ����������
{
	cout<<"��ȡ�ļ���!"<<endl;
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
			printf("��ǰ�ļ�Ϊ�ս�����ǰ��ȡ\n");
			break;
		}
	}
	fclose(fp);
}
void write()//����ְ���������ݺ���
{
}
void find()//��ѯְ���������ݺ���
{
}
void list()//���ְ���������ݺ���
{
}
void modify()//�޸�ְ���������ݺ���
{
}
void del()//ɾ��ְ���������ݺ���
{
}
void add()//���ְ���������ݺ���
{
}
void grsds()//�����������˰
{
}
int main()//������
{
	cout<<"1.��ȡ�ļ�\n2.����\n3.��ѯ\n4.�޸�\n5.���\n6.ɾ��\n7.����\n8.��˰\n9.�˳�"<<endl;
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
		case 9:cout<<"�˳���ǰ!���������....."<<endl;
			break;
	    default:			
			cout<<"����1~9������"<<endl;
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