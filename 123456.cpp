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
double grsds()//�����������˰
{
	double yfgz,grsds;
	yfgz=zggz[a].gwgz+zggz[a].xjgz+zggz[a].zwjt+zggz[a].jxgz;
	if(yfgz<=500)
		grsds=yfgz*0.05;                        //����500�ڵĸ�������˰�� 
	else if(500<yfgz&&yfgz<=2000)
		grsds=(yfgz-500)0.1+500*0.05;                     // ����500-2000�ĸ�������˰��
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