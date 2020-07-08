#pragma once
#include<vector>
#include<set>
#include<list>
#include<memory>
namespace std {
	class Node
	{
	public:
		Node(int x, int y)//���캯��
			:x(x), y(y), f(0), g(0), h(0), parent(nullptr),block(false) {}
		int  x, y, f, g, h;
		Node* parent;
		bool block;
		void calculateCost(Node* par,int x2,int y2) {//���������پ���f��g��h
			parent = par;
			g = parent->g + 1;
			h = std::abs(x2 - x ) + std::abs(y2 - y );
			f = g + h;
		}
	};

	
	class Astar
	{
	public:
		vector<vector<Node>> nodeMap;//��ͼ����
		list<pair<int, int>> openList;//open��
		list<pair<int, int>> closedList;//closed��

		Astar(int n, int m);//���캯�������ͼ���󳤿�
		void setBlock(initializer_list<pair<int, int>> initList);//�����ϰ�
		bool search(int x1, int y1, int x2, int y2);//��ʼ����
	private:
		int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };//�������ɽڵ���Χ�������ҵ�����

		list<pair<int, int>>::iterator findLeastNode();//����open����f��С�Ľڵ�
	};



}