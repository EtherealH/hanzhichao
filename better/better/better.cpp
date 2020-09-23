// better.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

const int w_1m = 1000000;
int w[w_1m];

bool is_match(int t, int low, int high)
{
	int med;
	while (low <= high)
	{
		med = (low + high) / 2;
		if (t == w[med])
		{
			return false;
		}
		else if (t < w[med])
		{
			high = med - 1;

		}
		else
		{
			low = med + 1;
		}
	}
	return true;
}

// brute -w whitelist < T
int main(int argc, char *argv[])//agrc是命令的个数
{
	if (argc != 3 || strcmp(argv[1], "-w"))//要求输入两个命令参数，否则就返回1跳出程序。
	{
		return 1;
	}

	// init w
	////    for(int i=0;i<w_1m)
	////    {
	////        w[i]=-1; //填充非法数据
	////    }
	ifstream infile;
	//ofstream outfile;
	infile.open(argv[1]);//argv[0]是执行的.exe的文件；argv[1]是执行的txt所在的路径
	int i = 0;
	cout << argv[1] << endl;
	while (infile >> w[i++])//从whitelist中读取数据
	{

	}//挨个读取
	cout << i << endl;
	int w_length = i - 1;
	cout << w_length << endl;
	// check t
	int t;
	//outfile.open(argv[3]);
	//infilee.open(argv[2]);
	while (cin >> t)//输入一个数字，判断文本文件里有没有。//t应该是p提供的数据
	{
		if (is_match(t, 0, w_length))
		{
			//outfile << t << endl;
			cout << t << endl;
		}
	}
	//outfile.close();
	//infilee.close();
}

