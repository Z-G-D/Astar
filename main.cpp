// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "Astar.h"
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    Astar astar(10, 10);//地图矩阵长宽
    //设置地图矩阵中的障碍
    astar.setBlock({ { 1,1},{0,1} ,{2,2},{3,3},{4,4}, {5,5},{6,6},{7,7}, {8,8} });
    if (astar.search(0, 0, 9,9)) {//返回真值就找到了通路
        cout << "最终搜索路径" << endl;
        list<Node*> searchPath;
        Node* sNode=&astar.nodeMap[9][9];
        do
        {
            searchPath.push_front(sNode);
            sNode = sNode->parent;
        } while (sNode != nullptr);//起点为空指针
        for (auto& x : searchPath) {
            cout << '(' << x->x << ',' << x->y << ')';
        }
        cout << endl;
        cout << "closed表中探索过的节点" << endl;;
        for (auto& x : astar.closedList) {//打印closed表输出搜索过的节点
            cout <<'('<< x.first << ',' << x.second << ')';
        }
        cout << endl;
    }
    //打印所有节点的f或g或h的值
    cout << "打印所有节点f的值" << endl;
    for (auto i = astar.nodeMap.rbegin(); i != astar.nodeMap.rend();i++) {
        for (auto j = i->begin(); j != i->end();j++) {
            cout<<setfill('0')<<setw(2) << j->f << ' ';
        }
        cout << endl;
    }
    cout << "打印所有节点g的值" << endl;
    for (auto i = astar.nodeMap.rbegin(); i != astar.nodeMap.rend(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            cout << setfill('0') << setw(2) << j->g << ' ';
        }
        cout << endl;
    }
    cout << "打印所有节点h的值" << endl;
    for (auto i = astar.nodeMap.rbegin(); i != astar.nodeMap.rend(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            cout << setfill('0') << setw(2) << j->h << ' ';
        }
        cout << endl;
    }
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
