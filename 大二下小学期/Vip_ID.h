#include "stdafx.h"
#include "Information database.h"
#include<stdlib.h>
#include <stdio.h> 
#include"iostream"
#include "fstream"
#include <time.h>

class Vip_ID
{
	struct ID
	{
		char name[10];//��Ա���
		int flag;    //����Ƿ��ǻ�Ա
		int cumulation;//��Ա����
	};
	struct ID user[50];
	int num;
public:
	Vip_ID(){ID_read();}
	void ID_input();
	void ID_output();
	void ID_write();
	void ID_read();
	int search(char namex[10]);
	void elter(char namex[10],int money);
	void changecumulation();
};

//�ж��û��Ƿ�Ϊ��Ա����ʱ����1
int Vip_ID::search(char namex[10])
{
	int result=0;
	for(int i=0;i<num;i++)
	{
		if(!strcmp(user[i].name,namex))
		{
			result=user[i].flag;
			break;
		}
	}
	return result;
}
void Vip_ID::ID_output()
{
	cout<<"member basic information��"<<endl;
	cout<<"member id    member authentication    Member Points"<<endl;
	for(int i=0;i<num;i++)
	{
		
		printf("%6s",user[i].name);
		cout<<"      ";
		if(user[i].flag)
		{
			cout<<"true";
		}
		else 
			cout<<"false";
		cout<<"       ";
		cout<<user[i].cumulation;
		cout<<endl;
	}
}
void Vip_ID::ID_read()
{
	char x;
	FILE *fp;

	fp=fopen("d:\\file\\b.txt","r");
	 if(fp==NULL)
	 {
		 printf("can't find the file ��");
		 exit(0);
	 }
	
	 fscanf(fp,"%d",&num);
	 fscanf(fp,"%c",&x);
	 for(int i=0;i<num;i++)
	 {
		 fread(user[i].name,sizeof(char)*10,1,fp);
		 fscanf(fp,"%c",&x);
	 }
	 for(int i=0;i<num;i++)
	 {
		 fscanf(fp,"%d",&user[i].flag);
		 fscanf(fp,"%c",&x);
	 }
	 for(int i=0;i<num;i++)
	 {
		 fscanf(fp,"%d",&user[i].cumulation);
		 fscanf(fp,"%c",&x);
	 }
	 fclose(fp);
}
void Vip_ID::ID_write()
{
	char x;
	 FILE *fp;
	 fp=fopen("d:\\file\\b.txt","w");
	 if(fp==NULL)
	 {
		 printf("can't find the file ��");
		 exit(0);
	 }
	 fprintf(fp,"%d",num);
	 fprintf(fp,"%c",' ');
	 for(int i=0;i<num;i++)
	 {
		 fwrite(user[i].name,sizeof(char)*10,1,fp);
		 fprintf(fp,"%c",' ');
	 }
	 for(int i=0;i<num;i++)
	 {
		 fprintf(fp,"%d",user[i].flag);
		 fprintf(fp,"%c",' ');
	 }
	  for(int i=0;i<num;i++)
	 {
		 fprintf(fp,"%d",user[i].cumulation);
		 fprintf(fp,"%c",' ');
	 }
     fclose(fp);

}
void Vip_ID::ID_input()
{
	char namex[10];

	cout<<"please input member code��USER000000����"<<endl;
	cout<<"��Ա�������0ʱ��¼����Ϣ��������!"<<endl;
	do{
		cout<<"member id��";
		scanf("%s",namex);
		if(!strcmp(namex,"0"))
			break;
		if(search(namex))
			cout<<"input member id fault!"<<endl;
		else 
		{
			strcpy(user[num].name,namex);
			cout<<" member authentication��1/0����";
			cin>>user[num].flag;
			
			user[num].cumulation=0;
			num++;
		}
	}while(1);
	ID_write();
}
void Vip_ID::elter(char namex[10],int money)
{
	for(int i=0;i<num;i++)
	{
		if(!strcmp(user[i].name,namex))
		{
			cout<<endl<<"***********************************"<<endl;
			cout<<"****��Ʒ�����嵥*******"<<endl;;
			cout<<"��Ա���";
		    printf("%s",namex);
			cout<<endl;
			cout<<"ԭ�л���Ϊ��";
			cout<<user[i].cumulation<<endl;
			cout<<"��û���Ϊ��";
			if(user[i].cumulation<=200)
				money=money/5;
			else if(user[i].cumulation<=500)
				money=(money/5)*3;
			else
				money=(money/5)*5;
			cout<<money<<endl;
			user[i].cumulation+=money;
			cout<<"��ǰ����Ϊ��";
			cout<<user[i].cumulation<<endl;

			ID_write();
			break;
		}
	}
	
}
void Vip_ID::changecumulation()
{
	
	cout<<"�����Ա���֣�";
	cin>>user[0].cumulation;
	for(int i=0;i<num;i++)
	{
		user[i].cumulation=user[0].cumulation;
	}
	ID_write();
}