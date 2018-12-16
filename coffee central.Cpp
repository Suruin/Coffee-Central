#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MP make_pair            //生成pair对象
const int MaxN = 500009;
int dx, dy, N, Q, d;                //城市的规模为dx，dy，咖啡屋数为N，询问次数为Q，步长值为d
int X[MaxN], Y[MaxN];          //咖啡屋的坐标序列 
int Sum[2020][2020];            //前缀和数组
void Init()                     //读入n个咖啡屋的坐标位置
{
	for (int i = 1; i <= N; i++)
		cin >> X[i] >> Y[i];
}
void inc(int _x1, int _y1, int _x2, int _y2)
{                          //对上下点坐标为（_x1,_y1）和(_x2,_y2)的菱形内的元素加1       
	int x1 = _x1 + _y1 + 10; //计算菱形顺时针选择45度和正方形的左下角坐标（x1，y1）、右上角坐标（x2，y2）
	int y1 = _y1 - _x1 + 1010;
	int x2 = _x2 + _y2 + 10;
	int y2 = _y2 - _x2 + 1010;
	if (x1 < 10)
		x1 = 9;           //处理边界情况
	if (y1 < 10)
		y1 = 9;
	if (x2 > 2010)
		x2 = 2010;
	if (y2 > 2010)
		y2 = 2010;
	Sum[x2][y2]++;              //按照操作1修改前缀和数组
	cout << "(x1,y1) = (" << x1 << "," << y1<<")  " << "(x2,y2) = (" << x2 << "," << y2<<")" << endl;
	for (int i = 8; i <= 22; ++i)
	{
		for (int j = 1008; j <= 1022; ++j)
		{
			cout << Sum[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-----------------" << endl;
	Sum[x1 - 1][y1 - 1]++;          //按照操作2修改前缀和数组
	for (int i = 8; i <= 22; ++i)
	{
		for (int j = 1008; j <= 1022; ++j)
		{
			cout << Sum[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-----------------"<<endl;
	Sum[x1 - 1][y2]--;            //按照操作3修改前缀和数组
	for (int i = 8; i <= 22; ++i)
	{
		for (int j = 1008; j <= 1022; ++j)
		{
			cout << Sum[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-----------------" << endl;
	Sum[x2][y1 - 1]--;            //按照操作4修改前缀和数组
	for (int i = 8; i <= 22; ++i)
	{
		for (int j = 1008; j <= 1022; ++j)
		{
			cout << Sum[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-----------------" << endl;
}
int FindAns(int _x, int _y)
{                               //返回（_x,_y）点的元素值
	int x = _x + _y + 10;         //计算对应的坐标
	int y = _y - _x + 1010;
	return Sum[x][y];       //返回该坐标的元素值
}
void Adjust()                   //调整维护前缀和数组，并输出答案
{
	cout << "计算Sum" << endl;
	for (int i = 2010; i >= 0; i--)//由上而下、由右而左计算前缀和数组Sum[][]
	{
		for (int j = 2010; j >= 0; j--)
		{
			Sum[i][j] = Sum[i][j + 1] + Sum[i + 1][j] + Sum[i][j] - Sum[i + 1][j + 1];
			if (i <= 18 && i > 8 && j <= 1018 && j > 1008)
			{
				for (int ii = 8; ii <= 22; ++ii)
				{
					for (int jj = 1008; jj <= 1022; ++jj)
					{
						cout << Sum[ii][jj] << "\t";
					}
					cout << endl;
				}
				cout << "-----------------" << endl;
				system("pause");
			}
		}
	}
	
	
		pair<int, pair<int, int>>  Ans = MP(100, MP(-1, -1));  //Ans由可达的咖啡屋和坐标位置组成
	for (int i = 1; i <= dx; i++)                       //自上而下、由左而右搜索每个坐标点
		for (int j = 1; j <= dy; j++)
			if (MP(-FindAns(i, j), MP(j, i)) < Ans)    //若（i，j）可达的咖啡屋做多，则记下输出最大可以到达的咖啡屋个数的坐标位置
				Ans = MP(-FindAns(i, j), MP(j, i));
		cout << -Ans.first << "(" << Ans.second.second << "," << Ans.second.first << ")\n";
}
void Solve()                                          //计算和输出Q次询问的答案
{
	for (int i = 1; i <= Q; i++)                                //以此处理每次询问
	{
		cin >> d;                                        //读第i次询问的步长值d
		for (int x = 0; x <= 2011; x++)                         //前缀和数组初始化为0
			for (int y = 0; y <= 2011; y++)
				Sum[x][y] = 0;
		for (int j = 1; j <= N; j++)             //将每个咖啡屋所在菱形区域内的元素加1
			inc(X[j], Y[j] - d, X[j], Y[j] + d);
		Adjust();                       //调整维护前缀和数组，并得到答案
	}
}
int main()
{
	int Case = 0;
	while (cin >> dx >> dy >> N >> Q && (dx || dy || N || Q))   //反复输入城市的规模、咖啡屋的个数和询问次数，直至输入4个0为止
	{
		Init();                                       //读入n个咖啡屋的坐标位置
		cout << "Case" << ++Case << ":\n";                  //输出测试用例编号
		Solve();                                     //计算和输出Q次询问的答案
	}
	return 0;
}
