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
	cout<<"����"<<" "<<"����"<<" "<<"��λ����"<<" "<<"н������"<<" "<<"ְ�����"<<" "<<"Ч������"<<" "<<"Ӧ������"<<" "<<"��������˰"<<" "<<"ʵ������"<<endl;
	for(i=0;i<5000;i++)
	{
		fseek(fp,i*sizeof(struct List),0);
		fread(q,sizeof(struct List),1,fp);
		cout<<q->gonghao<<"     "<<q->name<<"     "<<q->gwgz<<"     "<<q->xjgz<<"     "<<q->zwjt<<"     "<<q->jxgz<<"     "<<q->yfgz<<"     "<<q->grsds<<"     "<<q->sfgz<<endl;
		n=i;
		ch=fgetc(fp);
		if(ch==EOF)
		{
			printf("��ǰ��Ϊ�ս�����ǰ��ȡ\n");
			break;
		}
	}
	fclose(fp);
}
void write(List *q)//����ְ���������ݺ���
{
	if(q->gwgz<0||q->gwgz>50000)
	{	
		cout<<"�㻹û�������κ�����!!\n��������Ч������!"<<endl;
	}
	else
	{
		cout<<q->gonghao<<"     "<<q->name<<"     "<<q->gwgz<<"     "<<q->xjgz<<"     "<<q->zwjt<<"     "<<q->jxgz<<"     "<<q->yfgz<<"     "<<q->grsds<<"     "<<q->sfgz<<endl;	
		cout<<"������......!!"<<endl;	
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
void find()//��ѯְ���������ݺ���
{
	cout<<"��ѯ�ļ���!"<<endl;
	List worker,*q;
	FILE *fp;
	char ch;
	int i;
	q=&worker;
	char number[9];
	cout<<"������Ҫ��ѯ�����ݵĹ���"<<endl;
	cin>>number;
	if((fp=fopen("gx.dat","rb"))==NULL)
	{
		cout<<"Can't open this file!";
		getch();
		exit(-1);
	}
	cout<<"����"<<" "<<"����"<<" "<<"��λ����"<<" "<<"н������"<<" "<<"ְ�����"<<" "<<"Ч������"<<" "<<"Ӧ������"<<" "<<"��������˰"<<" "<<"ʵ������"<<endl;
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
			printf("��ǰ��Ϊ�ս�����ǰ��ȡ!���δ��ѯ������������Ĺ���.......!!\n");
			break;
		}
	}
	fclose(fp);
}
void list()//���ְ���������ݺ���
{
	cout<<"����ļ���!"<<endl;
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
	cout<<"����"<<" "<<"����"<<" "<<"��λ����"<<" "<<"н������"<<" "<<"ְ�����"<<" "<<"Ч������"<<" "<<"Ӧ������"<<" "<<"��������˰"<<" "<<"ʵ������"<<endl;
	for(i=0;i<5000;i++)
	{
		fseek(fp,i*sizeof(struct List),0);
		fread(q,sizeof(struct List),1,fp);
		cout<<q->gonghao<<"     "<<q->name<<"     "<<q->gwgz<<"     "<<q->xjgz<<"     "<<q->zwjt<<"     "<<q->jxgz<<"     "<<q->yfgz<<"     "<<q->grsds<<"     "<<q->sfgz<<endl;
		n=i;
		ch=fgetc(fp);
		if(ch==EOF)
		{
			printf("��ǰ��Ϊ�ս�����ǰ��ȡ\n");
			break;
		}
	}
	fclose(fp);
}
void modify(List *q)//�޸�ְ���������ݺ���
{
	/*
	List woker[n];
	for(int i=0;i<n;i++)
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
		cout<<"����"<<" "<<"����"<<" "<<"��λ����"<<" "<<"н������"<<" "<<"ְ�����"<<" "<<"Ч������"<<" "<<"Ӧ������"<<" "<<"��������˰"<<" "<<"ʵ������"<<endl;
		for(i=0;i<5000;i++)
		{
			fseek(fp,i*sizeof(struct List),0);
			fread(q,sizeof(struct List),1,fp);
			cout<<q->gonghao<<"     "<<q->name<<"     "<<q->gwgz<<"     "<<q->xjgz<<"     "<<q->zwjt<<"     "<<q->jxgz<<"     "<<q->yfgz<<"     "<<q->grsds<<"     "<<q->sfgz<<endl;
			ch=fgetc(fp);
			if(ch==EOF)
			{
				printf("��ǰ��Ϊ�ս�����ǰ��ȡ\n");
				break;
			}
		}
		fclose(fp);
	}
	*/
}
void del()//ɾ��ְ���������ݺ���
{
}
void add(List *q)//���ְ���������ݺ���
{
	List woker;
	cout<<"�������ӵ���Ϣ����"<<endl;
	cout<<"����"<<" "<<"����"<<" "<<"��λ����"<<" "<<"н������"<<" "<<"ְ�����"<<" "<<"Ч������"<<" "<<"Ӧ������"<<endl;
	cin>>woker.gonghao>>woker.name>>woker.gwgz>>woker.xjgz>>woker.zwjt>>woker.jxgz>>woker.yfgz;
	cout<<"��ѯ�ļ���!"<<endl;
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
			cout<<"�ù����Ѵ��ڣ�����������"<<endl;
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
	cout<<"�������!!��ǰ����������Ϣ....ѡ�񱣴�"<<endl;
}
double grsds(double yfgz)//�����������˰
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
int main()//������
{
	List woker;
	cout<<"1.��ȡ�ļ�\n2.����\n3.��ѯ\n4.���\n5.�޸�\n6.ɾ��\n7.����\n8.�˳�\n9.�����˵�"<<endl;
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
		case 8:cout<<"�˳���ǰ!���������....."<<endl;
			break;
		case 9:cout<<"1.��ȡ�ļ�\n2.����\n3.��ѯ\n4.���\n5.�޸�\n6.ɾ��\n7.����\n8.�˳�\n9.�����˵�"<<endl;
			break;
	    default:			
			cout<<"����1~8������"<<endl;
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