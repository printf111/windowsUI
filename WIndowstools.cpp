#include <graphics.h>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

#define Mtop  Topmargin+(Interval+Mwidth)*((m_num-(nowpage-1)*5)-1)	//每一个菜单的上面
#define MBotton Mtop+Mwidth							//每一个菜单的下面

const Leftmargin=50;	//左边距
const Topmargin=30;		//第一个菜单的上边距
const Interval=20;		//每一个的间隔

const Mlenth=585;		//一个菜单长
const Mwidth=50;		//一个菜单宽

const BLmargin=540;		//菜单按钮的左边距
const Blenth=70;		//一个按钮的长
const Bwidth=45;		//一个按钮的宽

const Alenghx=640;		//主程序的x
const Aweighy=480;		//主程序的y

int  lpnmune=1;
int  allpage=0;
int  nowpage=1;
int  num=0;

class childmune
{
public:
	int m_num;
	char m_openapp[203];
	char m_introduce[203];
	char m_name[203];
	childmune(int num,char openapp[203],char introduce[203]	,char name[203])//默认构造赋值属性
	{
		this->m_num=num;
		strcpy(this->m_openapp,openapp);
		strcpy(this->m_introduce,introduce);
		strcpy(this->m_name,name);
	}
	childmune()
	{
	}
	void printtoscreen()
	{
		char str[3];
		sprintf(str,"%d",m_num);
		solidrectangle(Leftmargin-45,Mtop,Leftmargin-10,Mtop+Mwidth);//输出序号的位置
		solidrectangle(Leftmargin,Mtop,Leftmargin+Mlenth,Mtop+Mwidth);//输出菜单的位置
		fillrectangle(BLmargin,Mtop+5,BLmargin+Blenth,Mtop+Mwidth-3);//输出打开的按钮位置
		fillrectangle(BLmargin-3-Blenth,Mtop+5,BLmargin-3,Mtop+Mwidth-3);//菜单简介按钮的位置
		setbkcolor(WHITE);
		settextstyle(28,0,"");
		outtextxy(BLmargin+3+5,Mtop+8,"打开");
		outtextxy(Leftmargin-43,Mtop+6,str);
		outtextxy(BLmargin-Blenth+5,Mtop+8,"简介");
		outtextxy(Leftmargin+2,Mtop+8,m_name);
	}
};





void readdata();//函数声明
void add();
void muneprinttoscreen();
bool rcheck(int,char *);	//用于在readdata函数中判断check值是否正确

vector<childmune> munevec;//函数传参不会了，所以设置为全局变量



int main()
{
	char appstr[202];
	printf("正在初始化......");
	COLORREF bkcolor=0xD8E9E9;
	initgraph(Alenghx, Aweighy);	// 创建绘图窗口，大小为 640x480 像素
//	initgraph(640, 480, EW_SHOWCONSOLE);
	HWND hwnd = GetHWnd();
	settextcolor(BLACK);
	
	SetWindowText(hwnd, "Windowstools");
	setbkcolor(bkcolor);
	cleardevice();
	settextstyle(25,0,"");
	outtextxy(180,0,"欢迎使用windowstool");
	fillrectangle(0,120,1,115);
	//以上为图形背景初始化
	
	
	
	
	//childmune demo(0,"text","text","text");
	//munevec.push_back(demo);
	//vector<childmune>::iterator it=munevec.begin();
	
	readdata();
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	settextstyle(30,0,"");
	

	allpage=num/5+1;
	lpnmune=num%5;
	nowpage=1;
	muneprinttoscreen();
	
	settextstyle(15,0,"");
	setlinecolor(BLACK);
	fillrectangle(500,400,638,439);
	setbkcolor(WHITE);
	outtextxy(501,410,"点击此处添加新工具");

	settextstyle(22,0,"");
	if(nowpage!=allpage){	fillrectangle(410,380,490,410);		outtextxy(410+5,380+5,"下一页");}
	if(nowpage!=1){			fillrectangle(150,380,230,410);		outtextxy(150+5,380+5,"上一页");}
	
	
	ExMessage m;		// 定义消息变量
	ExMessage *mm=&m;
	
	while(true)
	{
		// 获取一条鼠标
		
		if(peekmessage(mm,EM_MOUSE))
		{
			switch(m.message)
			{
			case WM_LBUTTONDOWN:
				{
					if(m.y>380 && m.y<410 )
					{
						if(m.x>410 && m.x<490)
						{
							if(nowpage!=allpage)
							{
								nowpage++;
								setbkcolor(bkcolor);
								cleardevice();
								settextstyle(25,0,"");
								outtextxy(180,0,"欢迎使用windowstool");
								muneprinttoscreen();
								settextstyle(15,0,"");
								setlinecolor(BLACK);
								fillrectangle(500,400,638,439);
								setbkcolor(WHITE);
								outtextxy(501,410,"点击此处添加新工具");
								settextstyle(25,0,"");
								settextstyle(22,0,"");
								if(nowpage!=allpage){	fillrectangle(410,380,490,410);		outtextxy(410+5,380+5,"下一页");}
								if(nowpage!=1){			fillrectangle(150,380,230,410);		outtextxy(150+5,380+5,"上一页");}
							}
						}

						if(m.x>150 && m.x<230)
						{
							if(nowpage!=1)
							{
								nowpage--;
								setbkcolor(bkcolor);
								cleardevice();
								settextstyle(25,0,"");
								outtextxy(180,0,"欢迎使用windowstool");
								settextstyle(15,0,"");
								setlinecolor(BLACK);
								fillrectangle(500,400,638,439);
								setbkcolor(WHITE);
								outtextxy(501,410,"点击此处添加新工具");
								muneprinttoscreen();
								settextstyle(25,0,"");
								settextstyle(22,0,"");
								if(nowpage!=allpage){	fillrectangle(410,380,490,410);		outtextxy(410+5,380+5,"下一页");}
								if(nowpage!=1){			fillrectangle(150,380,230,410);		outtextxy(150+5,230+5,"上一页");}
							}
						}

					}
					if(m.x>500 && m.y>400 && m.x<638 && m.y<439)
					{
						add();
						flushmessage();
					}
					if(m.x>470 && m.x<537)//简介同一位置
					{
						if(m.y>35 && m.y<77)
						{
							if((nowpage==allpage && lpnmune>=1 )|| (nowpage!=allpage))
							{
								MessageBox(NULL,munevec[5*(nowpage-1)].m_introduce, "简介", MB_OK | MB_SYSTEMMODAL);
							}
						}
						if(m.y>105 && m.y<147)
						{
							if((nowpage==allpage && lpnmune>=2)|| (nowpage!=allpage))
							{
								MessageBox(NULL,munevec[5*(nowpage-1)+1].m_introduce, "简介", MB_OK | MB_SYSTEMMODAL);
							}
						}
						if(m.y>175 && m.y<217)
						{
							if((nowpage==allpage && lpnmune>=3)|| (nowpage!=allpage))
							{
								MessageBox(NULL,munevec[5*(nowpage-1)+2].m_introduce, "简介", MB_OK | MB_SYSTEMMODAL);
							}
						}
						if(m.y>245 && m.y<287)
						{
							if((nowpage==allpage && lpnmune>=4)|| (nowpage!=allpage))
							{
								MessageBox(NULL,munevec[5*(nowpage-1)+3].m_introduce, "简介", MB_OK | MB_SYSTEMMODAL);
							}
						}
						if(m.y>315 && m.y<357)
						{
							if((nowpage==allpage && lpnmune>=5)|| (nowpage!=allpage))
							{
								MessageBox(NULL,munevec[5*(nowpage-1)+4].m_introduce, "简介", MB_OK | MB_SYSTEMMODAL);
							}
						}
					}
					//打开的按钮
					if(m.x>540 && m.x<607)
					{
						if(m.y>35 && m.y<77)
						{
							if((nowpage==allpage && lpnmune>=1)|| (nowpage!=allpage))
							{							
								strcpy(appstr,"start ");
								strcat(appstr,munevec[5*(nowpage-1)].m_openapp);
								system(appstr);
							}
						}
						if(m.y>105 && m.y<147) 
						{
							if((nowpage==allpage && lpnmune>=2)|| (nowpage!=allpage))
							{								
								strcpy(appstr,"start ");
								strcat(appstr,munevec[5*(nowpage-1)+1].m_openapp);
								system(appstr);
							}
						}
						if(m.y>175 && m.y<217)
						{
							if((nowpage==allpage && lpnmune>=3)|| (nowpage!=allpage))
							{
								strcpy(appstr,"start ");
								strcat(appstr,munevec[5*(nowpage-1)+2].m_openapp);
								system(appstr);
							}
						}
						if(m.y>245 && m.y<287)
						{
							if((nowpage==allpage && lpnmune>=4)|| (nowpage!=allpage))
							{	
								strcpy(appstr,"start ");
								strcat(appstr,munevec[5*(nowpage-1)+3].m_openapp);
								system(appstr);;
							}
						}
						if(m.y>315 && m.y<357)
						{
							if((nowpage==allpage && lpnmune>=5)|| (nowpage!=allpage))
							{
								strcpy(appstr,"start ");
								strcat(appstr,munevec[5*(nowpage-1)+4].m_openapp);
								system(appstr);
							}
						}
					}
					
				}
			}
		}
	}
	
	
	
	_getch();				// 按任意键继续
	return 0;
}


void readdata()
{
	char d[20];
	char check[5];
	char ch;
	char errorstr[250];
	bool error=false;
	int errornum=0;
	char app[202];		//这里限制了不能打开文件目录长度与简介不得多于200个字符（100个字）
	char intc[202];
	char name[202];
	freopen("data.dat","r",stdin);
	
	int i=0;
	int ich=0;	//存放 存字符串时用的下标
	char readkind=-1;//读取字符时用第几种模式
	bool isread=false;//判断是否在读取字符串
	bool ischeck=true;//判断是否在检查（因为刚进循环是在检查所以为true）
	char*t=check;


	int tcnumber;
	int tcfnumber;	
	while(1)
	{
		ch=getchar();
		if(ch==-1) break;
		/*
		data文件格式:
		num+空格+数字的ASCII+回车
		app+空格+打开app的相对路径+回车
		inc+空格+简介+回车
		nam+空格+名字+回车
		*/	
		
		if(isread)//如果是正在读取字符串
		{
			if(readkind==0)
			{
				if(!(rcheck(readkind,t))) 
				{
					errornum=-11;
					error=true;
					break;
				}
				if(ch-48!=num+1)	
				{
					if(num+1>=10)
					{
						ch-=48;
						tcfnumber=ch*10;
						ch=getchar();
						ch-=48;
						tcnumber=tcfnumber+ch;
						if(tcnumber!=num+1)
						{
							printf("%d,%d",tcnumber,num);
							errornum=10;
							error=true;
							break;
						}
					}
					else
					{
						errornum=1;
						error=true;
						break;
					}
					
				}
				//看一下下一个是不是回车
				ch=getchar();
				if(ch!='\n')
				{
					errornum=2;
					error=true;
					break;
				}
				ischeck=true;
				isread=false;
				continue;
			}
			if(readkind==1)//先检测是不是读取工具路径
			{
				if(!(rcheck(readkind,t)))
				{
					errornum=-12;
					error=true;
					break;
				}
				if(ch!='\n')
				{
					app[ich]=ch;
					ich++;
					if(ich>200)
					{
						errornum=3;
						error=true;
						break;
					}
					continue;
				}
				if(ch=='\n')
				{
					app[ich]='\0';
					ich=0;
					isread=false;//清除掉读取时的状态
					
					//因为这里读取的时候就是遇到\n结束，所以无需判断下一个是不是回车，所以下一个读取的判断检查就行
					ischeck=true;
					
					continue;
				}
			}
			if(readkind==2)//检测是不是正在读取简介
			{
				if(!(rcheck(readkind,t)))
				{
					errornum=-13;
					error=true;
					break;
				}
				if(ch!='\n')
				{
					
					intc[ich]=ch;
					ich++;
					if(ich>200)
					{
						errornum=4;
						error=true;
						break;
					}
					continue;
				}
				if(ch=='\n')
				{
					intc[ich]='\0';
					ich=0;
					isread=false;//清除掉读取时的状态
					
					//因为这里读取的时候就是遇到\n结束，所以无需判断下一个是不是回车，所以下一个读取的判断检查就行
					ischeck=true;
					
					continue;
				}
			}
			
			if(readkind==3)//检测是不是正在读取名称
			{
				if(!(rcheck(readkind,t)))
				{
					errornum=-14;
					error=true;
					break;
				}
				if(ch!='\n')
				{
					name[ich]=ch;
					ich++;
					if(ich>200)
					{
						errornum=5;
						error=true;
						break;
					}
					continue;
				}
				if(ch=='\n')
				{
					name[ich]='\0';
					ich=0;
					isread=false;//清除掉读取时的状态
					//判断名称结束代表一个工具完成
					
					readkind=-1; //需要新一轮的读取了
					num++;
					childmune t(num,app,intc,name);//把刚刚读到的信息放到菜单里
					munevec.push_back(t);
					memset(app,0,sizeof(app));
					memset(intc,0,sizeof(intc));
					memset(name,0,sizeof(name));//清空一切，为了避免干扰
					
					//因为这里读取的时候就是遇到\n结束，所以无需判断下一个是不是回车，所以下一个读取的判断检查就行(如果下一个是-1，文件就结束啦)
					ischeck=true;
					continue;
				}
			}
		}
		
		if(ischeck)
		{
			//如果不是正在读取字符串
			if(i>=0&&i<3)
			{
				check[i]=ch;
				i++;
				continue;
			}
			if(i==3)
			{
				check[i]=ch;
				i=0;
				readkind++;
				if(readkind>3)
				{
					MessageBox(NULL,"抱歉，程序出现错误，请联系作者改bug,以强制结束程序", "提示", MB_OK | MB_SYSTEMMODAL);//理应不应该出现这种情况，所以弹出弹窗出现了就错了
					exit(-1);
				}
				isread=true;//下一个进入判断
				continue;
				
			}
			if(i>4)
			{
				MessageBox(NULL,"抱歉，程序出现错误，请联系作者改bug,以强制结束程序", "提示", MB_OK | MB_SYSTEMMODAL);//理应不应该出现这种情况，所以弹出弹窗出现了就错了
				exit(-1);
			}
		}
		
	}
	if(error)
	{
		sprintf(errorstr,"检测时读取信息失败，已终止读取，错误代号 %d 请查看data.dat文件是否已损坏，并尝试更换data文件",errornum);
		MessageBox(NULL,errorstr, "提示", MB_OK | MB_SYSTEMMODAL);
	}
	if(num==0)
	{
		MessageBox(NULL,"未读取到任何正确信息或无任何信息，当前无可使用工具", "提示", MB_OK | MB_SYSTEMMODAL);
	}
	sprintf(errorstr,"成功检测信息 %d 个，",num);
	MessageBox(NULL,errorstr, "提示", MB_OK | MB_SYSTEMMODAL);
	fclose(stdin);
}

void add()
{
	freopen("data.dat","a+",stdout);
	char cha[202];
	char chi[202];
	char name[202];
	MessageBox(NULL,"暂无单独对一个工具删除或修改的功能，因此请备份data.dat文件，如果添加错误用备份文件替换错误的data.dat文件", "提示", MB_OK | MB_SYSTEMMODAL);
	
	if(!(InputBox(chi,200,"请输入工具简介，请不要输入回车，不要超过200字符（如果不带标点是100字，输入完成后点确定，不想添加点取消","工具简介","",300,200,false)))//获取简介输入，未输入则退出
	{
		return;
	}
	if(!(InputBox(cha,200,"请输入工具所在目录，请不要输入回车，不要超过200字符，输入完成后点确定，不想添加点取消","目录","",300,200,false)))//获取目录
	{
		return;
	}
	if(!(InputBox(name,200,"请输入工具名称，请不要输入回车，不要超过200字符，输入完成后点确定，不想添加点取消","名称","",300,200,false)))//获取目录
	{
		return;
	}
	num++;
	printf("num %d\n",num);
	printf("app %s\n",chi);
	printf("inc %s\n",cha);
	printf("nam %s\n",name);
	MessageBox(NULL,"添加完成，请重启启动软件使用新工具", "提示", MB_OK | MB_SYSTEMMODAL);
	fclose(stdout);
}

void muneprinttoscreen()
{
	int i;
	int tnum;
	int ti=(nowpage-1)*5;
	if(nowpage!=allpage)
	{
		tnum=5;
	}
	else
	{
		tnum=lpnmune;
	}
	setbkcolor(WHITE);
	for(i=0;i<tnum;i++)
	{
		
		munevec[ti+i].printtoscreen();
	}
}

bool rcheck(int readkind,char *check)
{
	char x[20];
	char checkdata[5];	
	if(readkind==0)
	{
		strcpy(checkdata,"num ");
		checkdata[4]='\0';
	}
	if(readkind==1)
	{	
		strcpy(checkdata,"app ");
		checkdata[4]='\0';
	}
	if(readkind==2)
	{
		strcpy(checkdata,"inc "); 
		checkdata[4]='\0';
	}
	if(readkind==3)
	{
		strcpy(checkdata,"nam ");
		checkdata[4]='\0';
	}
	for(int i=0;i<=3;i++)
	{
		if(checkdata[i]!=check[i])
			return false;
	}
	return true;
}
