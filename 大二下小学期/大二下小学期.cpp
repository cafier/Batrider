// 大二下小学期.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Information database.h"
#include "opereat.h"
#include "Vip_ID.H"
#define MAX 50
int mainmenu();
int mainmenuinf();
int mainmenuope();
int mainmenuv();



int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	Information inf;//基本信息类对象
	opereat ope;    //基本操作类对象
	Vip_ID vip;
	
	do{
		x=mainmenu();
		if (x==1)
		{
			int y=mainmenuinf();
			if(y==1)
			{
				inf.input();
			}
			if(y==2)
			{
				inf.output();
			}
		}
		if(x==2)
		{
			char namey[10];
			int y=mainmenuope();
			if(y==1)
			{
				cout<<"please input member id：";
				scanf("%s",namey);
				int isvip=vip.search(namey);
				if(isvip)
					cout<<"Verification is successful ！"<<endl;
				else
					cout<<"Verification is not successful ！"<<endl;
				
				ope.Salesprocess(inf);
				if(isvip)
				{
					float money;
					money=ope.returnmoney(1);
					vip.elter(namey,money);
				}
				if(!isvip)
					ope.output1();
				else
					ope.vipoutput1();
			}
			if(y==2)
			{
				cout<<"please input member id：";
				scanf("%s",namey);
				int isvip=vip.search(namey);
				if(isvip)
					cout<<"Verification is successful ！"<<endl;
				else
					cout<<"Verification is not successful ！"<<endl;
				ope.Salesprocess(inf);
				if(isvip)
				{
					float money;
					money=ope.returnmoney(2);
					vip.elter(namey,money);
				}

				if(!isvip)
					ope.output2();
				else
					ope.vipoutput2();
			}
			if(y==3)
			{
				cout<<"please input member id：";
				scanf("%s",namey);
				int isvip=vip.search(namey);
				if(isvip)
					cout<<"Verification is successful ！"<<endl;
				else
					cout<<"Verification is not successful ！"<<endl;
				ope.addin(inf);
				if(isvip)
				{
					float money;
					money=ope.returnmoney(1);
					vip.elter(namey,money);
				}
				if(!isvip)
					ope.output1();
				else
					ope.vipoutput1();
			}
			if(y==4)
			{
				cout<<"please input member id：";
				scanf("%s",namey);
				int isvip=vip.search(namey);
				if(isvip)
					cout<<"Verification is successful ！"<<endl;
				else
					cout<<"Verification is not successful ！"<<endl;
				ope.addin(inf);
				if(isvip)
				{
					float money;
					money=ope.returnmoney(2);
					vip.elter(namey,money);
				}
				if(!isvip)
					ope.output2();
				else
					ope.vipoutput2();
			}

		}
		if(x==3)
		{
			int y=mainmenuv();
			if(y==1)
			{
				vip.ID_input();
			}
			if(y==2)
			{
				vip.ID_output();
			}
			if(y==3)
				vip.changecumulation();
		}
	}while(x!=4);	
	return 0;
}
int mainmenu()
{
	int i;
	do{
	cout<<endl<<endl<<endl;
	cout<<"        ****************************"<<endl;
	cout<<"        **  1、system entrance    **"<<endl;
	cout<<"        **  2、market entrance    **"<<endl;
	cout<<"        **  3、member entrance    **"<<endl;
	cout<<"        **  3、exit               **"<<endl;
	cout<<"        ****************************"<<endl;
	cout<<"          choose：";
	cin>>i;
	system("Cls");
	}while(i!=2&&i!=1&&i!=3&&i!=4);
	return i;
}
int mainmenuinf()
{
	int i;
	do{
	cout<<endl<<endl<<endl;
	cout<<"        ********************************************"<<endl;
	cout<<"        **  1、create commodity information       **"<<endl;
	cout<<"        **  2、display commodity information      **"<<endl;
	cout<<"        **  3、update commodity information       **"<<endl;
	cout<<"        **  4、exit                               **"<<endl;
	cout<<"        ********************************************"<<endl;
	cout<<"            choose：";
	cin>>i;
	system("Cls");
	}while(i<1&&i>4);
	return i;
}
int mainmenuope()
{
	int i;
	do{
	cout<<endl<<endl<<endl;
	cout<<"        ************************************************"<<endl;
	cout<<"        **  1、sell commodity                         **"<<endl;
	cout<<"        **  2、sell commodity in discount             **"<<endl;
	cout<<"        **  3、sell commodity with code               **"<<endl;
	cout<<"        **  4、sell commodity with code in discount   **"<<endl;
	cout<<"        **  5、sales promotion(three for two)         **"<<endl;
	cout<<"        **  6、exit                                   **"<<endl;
	cout<<"        ************************************************"<<endl;
	cout<<"            choose：";
	cin>>i;
	system("Cls");
	}while(i<1&&i>6);
	return i;
}

int mainmenuv()
{
	int i;
	do{
	cout<<endl<<endl<<endl;
	cout<<"        *****************************************"<<endl;
	cout<<"        **  1、create member information       **"<<endl;
	cout<<"        **  2、display member information      **"<<endl;
	cout<<"        **  3、update member information       **"<<endl;
	cout<<"        **  4、exit                            **"<<endl;
	cout<<"        *****************************************"<<endl;
	cout<<"            choose：";
	cin>>i;
	system("Cls");
	}while(i<1&&i>4);
	return i;
}


