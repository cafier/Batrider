#include "stdafx.h"
#include "Information database.h"
#include"iostream"
#include "fstream"
#include<stdlib.h>
#include <stdio.h> 
#include <time.h>

#define MAX 50
#pragma once


class opereat
{
	char barcode[MAX][10];//������ ��ƷΨһ��ʶ ���ַ�����ʽ����
	char name[MAX][10];   //��Ʒ����
	char unit[MAX][4];

	float price[MAX];          //����
	float discount[MAX];       //�ۿۼ�
	float discount1[MAX];       //�ۿ�
	float vipdiscount[MAX];    //��Ա�Ż�

	int number[MAX];         //������Ʒ����
	int choose[MAX];         //���˷�ʽ,1ʱΪ��2��1�Żݻ��������������Ա��
	
	float prices[MAX];   //
	float vipprices[MAX];
	float discounts[MAX];
	float vipdiscounts[MAX];

	float totalprice;
	float totalvipprice;
	float totaldiscout;
	float totalvipdiscount;

	int num;//��Ʒ������
public:	
	opereat()
	{
		num=0;
		totalprice=0;
		totalvipprice=0;
		totaldiscout=0;
		totalvipdiscount=0;
		for(int i=0;i<MAX;i++)
		{
			prices[i]=vipprices[i]=discounts[i]=vipdiscount[i]=0;
			number[i]=0;
		}

	}
	int search(Information &jia,char barcodex[10]);
	void input(Information &jia,char barcodex[10],int number);
	void input(Information &jia,char barcodex[10]);//�������غ���
	void output1();   //��������ʱ���ǻ�Ա��ӡƱ��
	void vipoutput1();//��������ʱ����Ա��ӡƱ��
	void output2();   //������Ʒʱ���ǻ�Ա��ӡƱ��
	void vipoutput2();//������Ʒʱ����Ա��ӡƱ��
	void total();
    void Salesprocess(Information &jia);
	void addin(Information &inf);//�������뵥��������������
	float returnmoney(int i);
};
int opereat::search(Information &jia,char barcodex[10])
{
	return jia.search(barcodex);
}
void opereat::input(Information &jia,char barcodex[10],int numberx)
{
	jia.returninformation(barcodex,name[num],unit[num],price[num],discount[num],vipdiscount[num],choose[num]);
	strcpy(barcode[num],barcodex);


	prices[num]=price[num]*numberx;
	vipprices[num]=price[num]*vipdiscount[num]*numberx;
	discounts[num]=price[num]*discount[num]*numberx;
	vipdiscounts[num]=price[num]*discount[num]*numberx*vipdiscount[num];

	number[num]=numberx;
	num++;
}
void opereat::input(Information &jia,char barcodex[10])
{
	int flag=0;//��Ƿ�������Ʒ������Ϊ1��
	jia.returninformation(barcodex,name[num],unit[num],price[num],discount[num],vipdiscount[num],choose[num]);
	for(int i=0;i<num;i++)
	{
		if(!strcmp(barcode[i],barcodex))
		{
			number[i]+=1;
			prices[i]+=price[i];
			vipprices[i]=vipprices[i]+price[i]*vipdiscount[i];
			discounts[i]=discounts[i]+discount[i]*price[i];
			vipdiscounts[i]=vipdiscounts[i]+discount[i]*price[i]*vipdiscount[i];
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		strcpy(barcode[num],barcodex);
		prices[num]=price[num];
		vipprices[num]=price[num]*vipdiscount[num];
		discounts[num]=discount[num]*price[num];
		vipdiscounts[num]=discount[num]*price[num]*vipdiscount[num];

		number[num]=1;
		num++;
	}
}
void opereat::output1()
{
	cout<<"************************commodity******************"<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<"name��";
		printf("%s",name[i]);
		cout<<"   ";
		cout<<"quantity��";
	    cout<<number[i];
		printf("%s",unit[i]);
		cout<<"   ";
		cout<<"price��";
		cout<<price[i];
	    cout<<"(Ԫ)";
		cout<<"   ";
		cout<<"sum price��";
		cout<<prices[i];
		cout<<"(Ԫ)"<<endl;
	}
	cout<<"----------------------"<<endl;
	cout<<"total price��";
	cout<<totalprice<<" (Ԫ)"<<endl;
	num=0;
	totalprice=0; 
	totaldiscout=0;
}

void opereat::vipoutput1()
{
	cout<<"---------------------------"<<endl;

	cout<<endl;cout<<"��ӡʱ�䣺";
	time_t t = time(0); 
    char tmp[64]; 
    strftime( tmp, sizeof(tmp), "%Y��%m��%d�� %X ",localtime(&t) ); 
    puts( tmp ); 
	

	cout<<"---------------------------"<<endl;
	
	for(int i=0;i<num;i++)
	{
		cout<<"name��";
		printf("%s",name[i]);
		cout<<"   ";
		cout<<"quantity��";
	    cout<<number[i];
		printf("%s",unit[i]);
		cout<<"   ";
		cout<<"price��";
		cout<<price[i]*vipdiscount[i];
	    cout<<"(Ԫ)";
		cout<<"   ";
		cout<<"total��";
		cout<<prices[i]*vipdiscount[i];
		cout<<"(Ԫ)"<<endl;
	}
	cout<<"----------------------"<<endl;
	cout<<"total��";
	cout<<totalvipprice<<" (Ԫ)"<<endl;
	cout<<"save money��";
	cout<<totalprice-totalvipprice<<" (Ԫ)"<<endl;
	num=0;
	totalprice=0; 
	totalvipprice=0;
	totaldiscout=0;
	totalvipdiscount=0;
}

void opereat::output2()
{
	cout<<endl;
	cout<<"��ӡʱ�䣺";
	time_t t = time(0); 
    char tmp[64]; 
    strftime( tmp, sizeof(tmp), "%Y��%m��%d�� %X ",localtime(&t) ); 
    puts( tmp );

	totalvipdiscount=0;
	cout<<"************************commodity******************"<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<"name��";
		printf("%s",name[i]);
		cout<<"   ";
		cout<<"quantity��";
	    cout<<number[i];
		printf("%s",unit[i]);
		cout<<"   ";
		cout<<"sales promotion(three for two)��";
		if(!choose[i])
		{
			cout<<"N"<<"   ";
			cout<<"price��";
			cout<<discount[i]*price[i];
			cout<<"(Ԫ)";
			cout<<"   ";
			cout<<"total��";
			cout<<discounts[i];
			cout<<"(Ԫ)"<<endl;
		}
		else
		{
			cout<<"Y"<<"   ";
			cout<<"price��";
			cout<<price[i];
			cout<<"(Ԫ)";
			cout<<"   ";
			cout<<"total��";
			cout<<prices[i];
			cout<<"(Ԫ)"<<endl;
		}
	}
	cout<<"----------------------"<<endl;
	cout<<"sales promotion(three for two)"<<endl;
	for(int i=0;i<num;i++)
	{
		if(number[i]>1&&choose[i]==1)
		{
			cout<<"name��";
			printf("%s",name[i]);
			cout<<"   ";
			cout<<"quantity��";
			cout<<number[i]/2;
			printf("%s",unit[i]);
			cout<<"   ";
			totalvipdiscount+=price[i]*(number[i]/2);
			cout<<endl;
		}
	}

	cout<<"total��";
	cout<<totaldiscout<<" (Ԫ)"<<endl;
	cout<<"save money��";
	cout<<totalprice-totaldiscout+totalvipdiscount<<" (Ԫ)"<<endl;
	num=0;
	totalprice=0; 
	totalvipprice=0;
	totaldiscout=0;
	totalvipdiscount=0;
}
//��Աʱ������
void opereat::vipoutput2()
{
	cout<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"��ӡʱ�䣺";
	time_t t = time(0); 
    char tmp[64]; 
    strftime( tmp, sizeof(tmp), "%Y��%m��%d�� %X ",localtime(&t) ); 
    puts( tmp );
	totaldiscout=0;
	cout<<"---------------------------"<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<"name��";
		printf("%s",name[i]);
		cout<<"   ";
		cout<<"quantity��";
	    cout<<number[i];
		printf("%s",unit[i]);
		cout<<"   ";
		cout<<"sales promotion(three for two)��";
		if(!choose[i])
		{
			cout<<"N"<<"   ";
			cout<<"price��";
			cout<<vipdiscount[i]*price[i]*discount[i];
			cout<<"(Ԫ)";
			cout<<"   ";
			cout<<"total��";
			cout<<vipdiscounts[i];
			cout<<"(Ԫ)"<<endl;
		}
		else
		{
			cout<<"Y"<<"   ";
			cout<<"price��";
			cout<<price[i];
			cout<<"(Ԫ)";
			cout<<"   ";
			cout<<"total��";
			cout<<prices[i];
			cout<<"(Ԫ)"<<endl;
		}
	}
	cout<<"----------------------"<<endl;
	cout<<"sales promotion(three for two)"<<endl;
	for(int i=0;i<num;i++)
	{
		if(number[i]>1&&choose[i]==1)
		{
			cout<<"name��";
			printf("%s",name[i]);
			cout<<"   ";
			cout<<"quantity��";
			cout<<number[i]/2;
			printf("%s",unit[i]);
			cout<<"   ";
			totaldiscout+=price[i]*(number[i]/2);
			cout<<endl;
		}
	}

	cout<<"total��";
	cout<<totalvipdiscount<<" (Ԫ)"<<endl;
	cout<<"save money��";
	cout<<totalprice-totalvipdiscount+totaldiscout<<" (Ԫ)"<<endl;
	num=0;
	totalprice=0; 
	totalvipprice=0;
	totaldiscout=0;
	totalvipdiscount=0;
}
void opereat::total()
{
	for(int i=0;i<num;i++)
	{
		totalprice+=prices[i];
		totalvipprice+=vipprices[i];
		if(!choose[i])
			totaldiscout+=discounts[i];
		else
			totaldiscout+=prices[i];
		if(!choose[i])
			totalvipdiscount+=vipdiscounts[i];
		else
			totalvipdiscount+=prices[i];
	}
}
void opereat::Salesprocess(Information &inf)
{
	char barcode[MAX];
	int numble;
	cout<<"please input shopping information��exit when code is0��"<<endl;
	do
	{
		cout<<"please input commodity code��";
		scanf("%s",barcode);
		if(!strcmp(barcode,"0"))
			break;
		if(!search(inf,barcode))
		{
			cout<<"can't find commodity ��"<<endl;
			continue;
		}
		cout<<"please input shopping quantity��";
		cin>>numble;
		input(inf,barcode,numble);
	}while(1);
	total();
}
//��ɨ��Ĺ���
void opereat:: addin(Information &inf)
{
	char barcode[MAX];
	int numble;
	cout<<"please input shopping information��exit when code is0��"<<endl;
	do
	{
		cout<<"please input commodity code����";
		scanf("%s",barcode);
		if(!strcmp(barcode,"0"))
			break;
		if(!search(inf,barcode))
		{
			cout<<"can't find commodity ��"<<endl;
			continue;
		}
		input(inf,barcode);
	}while(1);
	total();
}
float opereat::returnmoney(int i)
{
	if(i==1)
		return totalvipprice;
	if(i==2)
		return totalvipdiscount;
}











