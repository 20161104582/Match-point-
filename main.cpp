//
//  main.cpp
//  Match point
//
//  Created by a20161104582 on 2018/7/7.
//  Copyright © 2018年 a20161104582. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <String>
#include <sstream>
#include <fstream>
using namespace std;


int menu()//菜单
{
    int MenuItem;
    
    cout<<"\n "<<endl;
    printf("          |   *********评分系统********  |     \n");
    printf("          | ---------------------------|      \n");
    printf("          |         主菜单项             |      \n");
    printf("          | -------------------------- |      \n");
    printf("          |	  1 --- 显示学生信息	       |      \n");
    printf("          |	  2 --- 显示评委信息	       |      \n");
    printf("          |	  3 --- 评委打分       	   |      \n");
    printf("          |	  4 --- 退出系统  	       |      \n");
    
    do
    {
        printf("\n请输入选项（1－4）：");
        fflush(stdin);
        scanf("%d",&MenuItem);
    }while(MenuItem<1||MenuItem>4);
    
    return MenuItem;
}
void Score()//评委打分
{
    int j,max=0,min=100,m;
    double sf;
    int f[10];
    ifstream fin("/Users/a20161104582/Desktop/Game points/input.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        max=0;
        min=100;
        sf=0;
        cout <<"姓名,性别,班级,电话，节目类别,节目名称"<< endl << line << endl; //整行输出
        
        for(j=1;j<=5;j++)//评分
        {
            cout<<"评委 "<<j<<" 打分:";
            cin>>f[j];
            sf=sf+f[j];
            if(max<f[j])
            {
                max=f[j];
            }
            if(min>f[j])
            {
                min=f[j];
            }
        }
        cout<<"去一个最高分:"<<max<<endl;
        cout<<"去一个最低分:"<<min<<endl;
        sf=(sf-max-min)/3;
        cout<<"选手最终得分:"<<sf<<endl;
        
        ofstream outfile("/Users/a20161104582/Desktop/Game points/output.csv",ios::app);  //写入文件
        outfile<<line<<","<<sf<<endl;
        
        cout<<"是否继续「是（1）否（0）」"<<endl;//中途结束评分
        cin>>m;
        if(m==0)
        {
            break;
        }
    }
    cout<<"评分完成"<<endl;
}

void racer()//选手信息
{
    int i=0;
    ifstream fin("/Users/a20161104582/Desktop/Game points/input.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        i++;
        cout<<"第 "<< i <<" 位选手:"<<endl;
        cout <<"姓名,性别,班级,电话,节目类型,节目名称"<< endl << line << endl;
    }
}
void rater()//评委信息
{
    int i=0;
    ifstream fin("/Users/a20161104582/Desktop/Game points/rater.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        i++;
        cout <<"姓名,性别,电话："<< endl << line << endl;
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    // std::cout << "Hello, World!\n";
    while(1)
    {
        switch(menu())
        {
            case 1:
                racer();
                break;
            case 2:
                rater();
                break;
            case 3:
                Score();
                break;
            case 4:
                cout<<"谢谢使用！"<<endl;
                return 0;
        }
    }
    
    return 0;
}
