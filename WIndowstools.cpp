#include <graphics.h>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

#define Mtop  Topmargin+(Interval+Mwidth)*((m_num-(nowpage-1)*5)-1)	//ÿһ���˵�������
#define MBotton Mtop+Mwidth							//ÿһ���˵�������

const Leftmargin=50;	//��߾�
const Topmargin=30;		//��һ���˵����ϱ߾�
const Interval=20;		//ÿһ���ļ��

const Mlenth=585;		//һ���˵���
const Mwidth=50;		//һ���˵���

const BLmargin=540;		//�˵���ť����߾�
const Blenth=70;		//һ����ť�ĳ�
const Bwidth=45;		//һ����ť�Ŀ�

const Alenghx=640;		//�������x
const Aweighy=480;		//�������y

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
	childmune(int num,char openapp[203],char introduce[203]	,char name[203])//Ĭ�Ϲ��츳ֵ����
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
		solidrectangle(Leftmargin-45,Mtop,Leftmargin-10,Mtop+Mwidth);//�����ŵ�λ��
		solidrectangle(Leftmargin,Mtop,Leftmargin+Mlenth,Mtop+Mwidth);//����˵���λ��
		fillrectangle(BLmargin,Mtop+5,BLmargin+Blenth,Mtop+Mwidth-3);//����򿪵İ�ťλ��
		fillrectangle(BLmargin-3-Blenth,Mtop+5,BLmargin-3,Mtop+Mwidth-3);//�˵���鰴ť��λ��
		setbkcolor(WHITE);
		settextstyle(28,0,"");
		outtextxy(BLmargin+3+5,Mtop+8,"��");
		outtextxy(Leftmargin-43,Mtop+6,str);
		outtextxy(BLmargin-Blenth+5,Mtop+8,"���");
		outtextxy(Leftmargin+2,Mtop+8,m_name);
	}
};





void readdata();//��������
void add();
void muneprinttoscreen();
bool rcheck(int,char *);	//������readdata�������ж�checkֵ�Ƿ���ȷ

vector<childmune> munevec;//�������β����ˣ���������Ϊȫ�ֱ���



int main()
{
	char appstr[202];
	printf("���ڳ�ʼ��......");
	COLORREF bkcolor=0xD8E9E9;
	initgraph(Alenghx, Aweighy);	// ������ͼ���ڣ���СΪ 640x480 ����
//	initgraph(640, 480, EW_SHOWCONSOLE);
	HWND hwnd = GetHWnd();
	settextcolor(BLACK);
	
	SetWindowText(hwnd, "Windowstools");
	setbkcolor(bkcolor);
	cleardevice();
	settextstyle(25,0,"");
	outtextxy(180,0,"��ӭʹ��windowstool");
	fillrectangle(0,120,1,115);
	//����Ϊͼ�α�����ʼ��
	
	
	
	
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
	outtextxy(501,410,"����˴�����¹���");

	settextstyle(22,0,"");
	if(nowpage!=allpage){	fillrectangle(410,380,490,410);		outtextxy(410+5,380+5,"��һҳ");}
	if(nowpage!=1){			fillrectangle(150,380,230,410);		outtextxy(150+5,380+5,"��һҳ");}
	
	
	ExMessage m;		// ������Ϣ����
	ExMessage *mm=&m;
	
	while(true)
	{
		// ��ȡһ�����
		
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
								outtextxy(180,0,"��ӭʹ��windowstool");
								muneprinttoscreen();
								settextstyle(15,0,"");
								setlinecolor(BLACK);
								fillrectangle(500,400,638,439);
								setbkcolor(WHITE);
								outtextxy(501,410,"����˴�����¹���");
								settextstyle(25,0,"");
								settextstyle(22,0,"");
								if(nowpage!=allpage){	fillrectangle(410,380,490,410);		outtextxy(410+5,380+5,"��һҳ");}
								if(nowpage!=1){			fillrectangle(150,380,230,410);		outtextxy(150+5,380+5,"��һҳ");}
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
								outtextxy(180,0,"��ӭʹ��windowstool");
								settextstyle(15,0,"");
								setlinecolor(BLACK);
								fillrectangle(500,400,638,439);
								setbkcolor(WHITE);
								outtextxy(501,410,"����˴�����¹���");
								muneprinttoscreen();
								settextstyle(25,0,"");
								settextstyle(22,0,"");
								if(nowpage!=allpage){	fillrectangle(410,380,490,410);		outtextxy(410+5,380+5,"��һҳ");}
								if(nowpage!=1){			fillrectangle(150,380,230,410);		outtextxy(150+5,230+5,"��һҳ");}
							}
						}

					}
					if(m.x>500 && m.y>400 && m.x<638 && m.y<439)
					{
						add();
						flushmessage();
					}
					if(m.x>470 && m.x<537)//���ͬһλ��
					{
						if(m.y>35 && m.y<77)
						{
							if((nowpage==allpage && lpnmune>=1 )|| (nowpage!=allpage))
							{
								MessageBox(NULL,munevec[5*(nowpage-1)].m_introduce, "���", MB_OK | MB_SYSTEMMODAL);
							}
						}
						if(m.y>105 && m.y<147)
						{
							if((nowpage==allpage && lpnmune>=2)|| (nowpage!=allpage))
							{
								MessageBox(NULL,munevec[5*(nowpage-1)+1].m_introduce, "���", MB_OK | MB_SYSTEMMODAL);
							}
						}
						if(m.y>175 && m.y<217)
						{
							if((nowpage==allpage && lpnmune>=3)|| (nowpage!=allpage))
							{
								MessageBox(NULL,munevec[5*(nowpage-1)+2].m_introduce, "���", MB_OK | MB_SYSTEMMODAL);
							}
						}
						if(m.y>245 && m.y<287)
						{
							if((nowpage==allpage && lpnmune>=4)|| (nowpage!=allpage))
							{
								MessageBox(NULL,munevec[5*(nowpage-1)+3].m_introduce, "���", MB_OK | MB_SYSTEMMODAL);
							}
						}
						if(m.y>315 && m.y<357)
						{
							if((nowpage==allpage && lpnmune>=5)|| (nowpage!=allpage))
							{
								MessageBox(NULL,munevec[5*(nowpage-1)+4].m_introduce, "���", MB_OK | MB_SYSTEMMODAL);
							}
						}
					}
					//�򿪵İ�ť
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
	
	
	
	_getch();				// �����������
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
	char app[202];		//���������˲��ܴ��ļ�Ŀ¼�������鲻�ö���200���ַ���100���֣�
	char intc[202];
	char name[202];
	freopen("data.dat","r",stdin);
	
	int i=0;
	int ich=0;	//��� ���ַ���ʱ�õ��±�
	char readkind=-1;//��ȡ�ַ�ʱ�õڼ���ģʽ
	bool isread=false;//�ж��Ƿ��ڶ�ȡ�ַ���
	bool ischeck=true;//�ж��Ƿ��ڼ�飨��Ϊ�ս�ѭ�����ڼ������Ϊtrue��
	char*t=check;


	int tcnumber;
	int tcfnumber;	
	while(1)
	{
		ch=getchar();
		if(ch==-1) break;
		/*
		data�ļ���ʽ:
		num+�ո�+���ֵ�ASCII+�س�
		app+�ո�+��app�����·��+�س�
		inc+�ո�+���+�س�
		nam+�ո�+����+�س�
		*/	
		
		if(isread)//��������ڶ�ȡ�ַ���
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
				//��һ����һ���ǲ��ǻس�
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
			if(readkind==1)//�ȼ���ǲ��Ƕ�ȡ����·��
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
					isread=false;//�������ȡʱ��״̬
					
					//��Ϊ�����ȡ��ʱ���������\n���������������ж���һ���ǲ��ǻس���������һ����ȡ���жϼ�����
					ischeck=true;
					
					continue;
				}
			}
			if(readkind==2)//����ǲ������ڶ�ȡ���
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
					isread=false;//�������ȡʱ��״̬
					
					//��Ϊ�����ȡ��ʱ���������\n���������������ж���һ���ǲ��ǻس���������һ����ȡ���жϼ�����
					ischeck=true;
					
					continue;
				}
			}
			
			if(readkind==3)//����ǲ������ڶ�ȡ����
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
					isread=false;//�������ȡʱ��״̬
					//�ж����ƽ�������һ���������
					
					readkind=-1; //��Ҫ��һ�ֵĶ�ȡ��
					num++;
					childmune t(num,app,intc,name);//�Ѹոն�������Ϣ�ŵ��˵���
					munevec.push_back(t);
					memset(app,0,sizeof(app));
					memset(intc,0,sizeof(intc));
					memset(name,0,sizeof(name));//���һ�У�Ϊ�˱������
					
					//��Ϊ�����ȡ��ʱ���������\n���������������ж���һ���ǲ��ǻس���������һ����ȡ���жϼ�����(�����һ����-1���ļ��ͽ�����)
					ischeck=true;
					continue;
				}
			}
		}
		
		if(ischeck)
		{
			//����������ڶ�ȡ�ַ���
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
					MessageBox(NULL,"��Ǹ��������ִ�������ϵ���߸�bug,��ǿ�ƽ�������", "��ʾ", MB_OK | MB_SYSTEMMODAL);//��Ӧ��Ӧ�ó���������������Ե������������˾ʹ���
					exit(-1);
				}
				isread=true;//��һ�������ж�
				continue;
				
			}
			if(i>4)
			{
				MessageBox(NULL,"��Ǹ��������ִ�������ϵ���߸�bug,��ǿ�ƽ�������", "��ʾ", MB_OK | MB_SYSTEMMODAL);//��Ӧ��Ӧ�ó���������������Ե������������˾ʹ���
				exit(-1);
			}
		}
		
	}
	if(error)
	{
		sprintf(errorstr,"���ʱ��ȡ��Ϣʧ�ܣ�����ֹ��ȡ��������� %d ��鿴data.dat�ļ��Ƿ����𻵣������Ը���data�ļ�",errornum);
		MessageBox(NULL,errorstr, "��ʾ", MB_OK | MB_SYSTEMMODAL);
	}
	if(num==0)
	{
		MessageBox(NULL,"δ��ȡ���κ���ȷ��Ϣ�����κ���Ϣ����ǰ�޿�ʹ�ù���", "��ʾ", MB_OK | MB_SYSTEMMODAL);
	}
	sprintf(errorstr,"�ɹ������Ϣ %d ����",num);
	MessageBox(NULL,errorstr, "��ʾ", MB_OK | MB_SYSTEMMODAL);
	fclose(stdin);
}

void add()
{
	freopen("data.dat","a+",stdout);
	char cha[202];
	char chi[202];
	char name[202];
	MessageBox(NULL,"���޵�����һ������ɾ�����޸ĵĹ��ܣ�����뱸��data.dat�ļ��������Ӵ����ñ����ļ��滻�����data.dat�ļ�", "��ʾ", MB_OK | MB_SYSTEMMODAL);
	
	if(!(InputBox(chi,200,"�����빤�߼�飬�벻Ҫ����س�����Ҫ����200�ַ���������������100�֣�������ɺ��ȷ����������ӵ�ȡ��","���߼��","",300,200,false)))//��ȡ������룬δ�������˳�
	{
		return;
	}
	if(!(InputBox(cha,200,"�����빤������Ŀ¼���벻Ҫ����س�����Ҫ����200�ַ���������ɺ��ȷ����������ӵ�ȡ��","Ŀ¼","",300,200,false)))//��ȡĿ¼
	{
		return;
	}
	if(!(InputBox(name,200,"�����빤�����ƣ��벻Ҫ����س�����Ҫ����200�ַ���������ɺ��ȷ����������ӵ�ȡ��","����","",300,200,false)))//��ȡĿ¼
	{
		return;
	}
	num++;
	printf("num %d\n",num);
	printf("app %s\n",chi);
	printf("inc %s\n",cha);
	printf("nam %s\n",name);
	MessageBox(NULL,"�����ɣ��������������ʹ���¹���", "��ʾ", MB_OK | MB_SYSTEMMODAL);
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
