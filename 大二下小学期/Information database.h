#include "stdafx.h"
#include"iostream"
#include "fstream"
#define MAX 50
using namespace std;
#pragma once 

class Information
{
	char barcode[MAX][10];//条形码 商品唯一标识 以字符串形式保存
	char name[MAX][10];   //商品名称
	char unit[MAX][4];
	float price[MAX];          //单价
	float discount1[MAX];       //折扣价
	float discount[MAX];       //折扣	
	float vipdiscount[MAX];
	int choose[MAX];              //结账方式,1时为买2赠1优惠活动（不参与打折与会员）
	int sum;              //库存商品种类
		
public:
	Information()
	{
		sum=0;
		read();
	}
	//录入商品信息
	void input();
	//输出商品信息
	void output( );
	//通过条形码，查看商品是否存在
	void write();
	void read();
	int search(char barcodex[MAX]);
	void returninformation(char *barcodex,char *namex,char *unitx,float &price,float &discount,float &vipdiscountx,int &choosex);
};
void Information::input()
{
	char barcodex[10];
	int sumx=sum;
	int numx;
	cout<<"the number of input commodity：";
	cin>>numx;
	for(int i=0;i<numx;i++)
	{
		do{
			cout<<endl;
			cout<<"please input commodity code（ITEM000000）：";
			scanf("%s",barcodex);
			if(search(barcodex))
				cout<<"input commodity code fault!"<<endl;
		}while(search(barcodex));
		strcpy(barcode[i+sumx],barcodex);
		cout<<"please input commodity name：";
		scanf("%s",name[i+sumx]);

		cout<<"please input commodity unit name（瓶/个）：";
		scanf("%s",unit[i+sumx]);

		cout<<" input commodity price：";
		cin>>price[i+sumx];
		cout<<"input commodity discount ：";
		cin>>discount[i+sumx];
		discount1[i+sumx]=price[i+sumx]*discount[i+sumx];
		
		do{
			cout<<"input commodity member discount（0-1）：";
		    cin>>vipdiscount[i+sumx];
			if(vipdiscount[i+sumx]<1&&vipdiscount[i+sumx]>0)
				break;
			else
				cout<<"input commodity member discount fault！"<<endl;
		}while(1);

		do{
			cout<<"sales promotion(three for two)（1/0）：";
		    cin>>choose[i+sumx];
			if(choose[i+sumx]==1||choose[i+sumx]==0)
				break;
			else
				cout<<"input fault！"<<endl;
		}while(1);


		sum++;
	}
	write();
}
//条形码内容是库内商品码，返回真
int Information::search(char barcodex[10])
{
	int result=0;
	for(int i=0;i<sum;i++)
	{
		if(!strcmp(barcode[i],barcodex))
		{
			result=1;
			break;
		}
	}
	return result;
}
void Information::output()
{
	cout<<"commodity basic information："<<endl;
	cout<<" commodity code    name    unit name    price    discount      member discount     sales promotion(three for two)"<<endl;
	for(int i=0;i<sum;i++)
	{
		
		printf("%6s",barcode[i]);
		
		printf("%8s",name[i]);
		cout<<"      ";
		printf("%2s",unit[i]);
		cout<<"          ";
		cout<<price[i];
		cout<<"       ";
		cout<<discount[i];
		cout<<"       ";
		cout<<vipdiscount[i];
		if(choose[i]==1)
			cout<<"         "<<"Y"<<endl;
		else
			cout<<"         "<<"N"<<endl;
	}
}
void Information::returninformation(char *barcodex,char *namex,char *unitx,float &pricex,float &discountx,float &vipdiscountx,int &choosex)
{
	for(int i=0;i<sum;i++)
	{
		if(!strcmp(barcode[i],barcodex))
		{
			strcpy(namex,name[i]);
			strcpy(unitx,unit[i]);
			pricex=price[i];
			discountx=discount[i];
			vipdiscountx=vipdiscount[i];
			choosex=choose[i];
			break;
		}
	}
}
void Information::write()
{
	char x;
	 FILE *fp;
	 fp=fopen("d:\\file\\a.txt","w");
	 if(fp==NULL)
	 {
		 printf("file inexistence！");
		 exit(0);
	 }
	 fprintf(fp,"%d",sum);
	 fprintf(fp,"%c",' ');
	 for(int i=0;i<sum;i++)
	 {
		 fwrite(barcode[i],sizeof(char)*10,1,fp);
		 fprintf(fp,"%c",' ');
	 }
	 for(int i=0;i<sum;i++)
	 {
		 fwrite(name[i],sizeof(char)*10,1,fp);
		 fprintf(fp,"%c",' ');
	 }
	 for(int i=0;i<sum;i++)
	 {
		 fwrite(unit[i],sizeof(char)*4,1,fp);
		 fprintf(fp,"%c",' ');
	 }
	  for(int i=0;i<sum;i++)
	 {
		 fprintf(fp,"%f",price[i]);
	     fprintf(fp,"%c",' ');
	 }
	   for(int i=0;i<sum;i++)
	 {
		 fprintf(fp,"%f",discount[i]);
	     fprintf(fp,"%c",' ');
	 }
	   for(int i=0;i<sum;i++)
	 {
		 fprintf(fp,"%f",vipdiscount[i]);
	     fprintf(fp,"%c",' ');
	 }
       for(int i=0;i<sum;i++)
	 {
		 fprintf(fp,"%d",choose[i]);
	     fprintf(fp,"%c",' ');
	 }
     fclose(fp);

	 
}
void Information::read()
{
	char x;
	FILE *fp;

	fp=fopen("d:\\file\\a.txt","r");
	 if(fp==NULL)
	 {
		 printf("file inexistence！");
		 exit(0);
	 }
	
	 fscanf(fp,"%d",&sum);
	 fscanf(fp,"%c",&x);
	 for(int i=0;i<sum;i++)
	 {
		 fread(barcode[i],sizeof(char)*10,1,fp);
		 fscanf(fp,"%c",&x);
	 }
	 for(int i=0;i<sum;i++)
	 {
		 fread(name[i],sizeof(char)*10,1,fp);
		 fscanf(fp,"%c",&x);
	 }
	 for(int i=0;i<sum;i++)
	 {
		 fread(unit[i],sizeof(char)*4,1,fp);
		 fscanf(fp,"%c",&x);
	 }
	 for(int i=0;i<sum;i++)
	 {
		 fscanf(fp,"%f",&price[i]);
		 fscanf(fp,"%c",&x);
	 }
	 for(int i=0;i<sum;i++)
	 {
		 fscanf(fp,"%f",&discount[i]);
		 fscanf(fp,"%c",&x);
	 }
	 for(int i=0;i<sum;i++)
	 {
		 fscanf(fp,"%f",&vipdiscount[i]);
		 fscanf(fp,"%c",&x);
	 }

	 for(int i=0;i<sum;i++)
	 {
		 fscanf(fp,"%d",&choose[i]);
		 fscanf(fp,"%c",&x);
	 }
	 fclose(fp);
}