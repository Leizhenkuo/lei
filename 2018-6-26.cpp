#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;
double grsds(double);//��˰��������
int n=0;//ȫ�ֱ���n�����ۼ���ṹ������±�
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
}woker[100];//�ṹ��woker����
void read()//��ȡְ����������
{
	printf("��ȡ�ļ���......\n");
	List zg,*q;
	FILE *fp;//����fp��ָ�룬����ָ��FILE���͵Ķ���
	char ch;
	int i;
	q=&zg;
	if((fp=fopen("gx.dat","rb"))==NULL)//�ж��Ƿ���ļ��ɹ�
	{
		printf("Can't open this file!\n");
		getch();
		exit(-1);
	}
	for(i=0;i<5000;i++)
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
			printf("��ǰ��Ϊ�ս�����ǰ��ȡ\n");
			break;
		}		
	}
	n=i;
	fclose(fp);	//�ر���
	printf("��ȡ���!!��ѡ�����!");
}
void write()//����ְ���������ݺ���
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
	fclose(fp);//�����ļ�
}
void find()//��ѯְ���������ݺ���
{
	char number[9];
	printf("������Ҫ��ѯְ�����ݵĹ���!\n");
	scanf("%d",&number);
	for(int i=0;i<=n;i++)
	{
		if(strcmp(number,woker[i].gonghao) == 0)
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
}
void list()//���ְ���������ݺ���
{
	printf("�������\n");
	printf("���� ���� ��λ���� н������ ְ����� Ч������ Ӧ������ ��������˰ ʵ������\n");
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
void modify()//�޸�ְ���������ݺ���
{
	int j=0;
	char number[9];
	printf("������Ҫ�޸�ְ�����ݵĹ���!\n");
	scanf("%d",&number);
	for(int i=0;i<=n;i++)
	{
		if(strcmp(number,woker[i].gonghao) == 0)
		{
			printf("�����޸���Ϣ");
			printf("���� ���� ��λ���� н������ ְ����� Ч������ Ӧ������\n");
			scanf("%s%s%f%f%f%f%f",&woker[i].gonghao,&woker[i].name,&woker[i].gwgz,&woker[i].xjgz,&woker[i].zwjt,&woker[i].jxgz,&woker[i].yfgz);
			double p=woker[i].yfgz;
			woker[i].grsds=grsds(p);
			woker[i].sfgz=woker[i].yfgz-woker[i].grsds;
			printf("�������!\n");
		}		
		else if(i==n+1)
		{
			printf("���鹤���Ƿ����!\n");
		}	
	}
}
void del()//ɾ��ְ���������ݺ���
{
	char number[9];
	printf("������Ҫɾ��ְ�����ݵĹ���!\n");
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
			printf("��ɾ��!\n");
		}
		else if(i==n+1)
		{
			printf("���鹤���Ƿ����!\n");
		}		
	}
}
void add()//���ְ���������ݺ���
{
	printf("�������ӵ���Ϣ����\n");
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
		continue;
	}
	double p=woker[i].yfgz;
	woker[i].grsds=grsds(p);//����grsds()�����������˰
	woker[i].sfgz=woker[i].yfgz-woker[i].grsds;//����ʵ������
	n=n+1;
	printf("�������!!\n");
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
	printf("1.��ȡ�ļ�\n2.����\n3.��ѯ\n4.���\n5.�޸�\n6.ɾ��\n7.����\n8.�˳�\n9.�����˵�");
	int num;
	for(;true;)//����ѭ���壨������������ѭ����
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
		case 8:printf("�˳���ǰ!���������.....\n");
			break;
		case 9:printf("1.��ȡ�ļ�\n2.����\n3.��ѯ\n4.���\n5.�޸�\n6.ɾ��\n7.����\n8.�˳�\n9.�����˵�\n");
			break;
	    default:			
			printf("����1~8������\n");
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