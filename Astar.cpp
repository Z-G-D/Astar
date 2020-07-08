#include "Astar.h"
#include<algorithm>
using namespace std;
Astar::Astar(int n, int m)
{
	nodeMap.resize(m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			nodeMap[i].push_back(Node(j, i));
		}
	}
}

void Astar::setBlock(initializer_list<pair<int, int>> initList)
{
	for (auto& ele : initList) {
		nodeMap[ele.first][ele.second].block = true;
	}
}

bool Astar::search(int x1, int y1, int x2, int y2)
{
	openList.push_back({ x1,y1 });//���Ƚ��������open��
	while (!openList.empty()) {
		auto currentIter = findLeastNode();//��open����ȡ��f��С��һ���ڵ�
		int cx = currentIter->first, cy = currentIter->second;//cx����current��x����
		auto &currentNode = nodeMap[cy][cx];
		openList.erase(currentIter);//����ǰȡ���Ľڵ��open�����Ƴ�
		closedList.push_back({ cx,cy });//����closed����

		if (cx == x2 && cy == y2)return true;//ȡ���Ľڵ����յ㷵��true
		for (auto& d : direction) {//�������������ĸ����������̽��һ��
			int nx = d[0] + cx, ny = d[1] + cy;//nx����next��̽���ڵ㣩��x����
			if (nx>=nodeMap[0].size() || nx < 0 ||//next�ڵ�������������
				ny>=nodeMap.size() || ny < 0 )
				continue;
			auto &next = nodeMap[ny][nx];//���������ҵ��ýڵ�
			//��������STL����find_if()��Pred��Lambta���ʽ����������������
			auto preLambta = [&](const pair<int,int>& a) {return nx == a.first && ny == a.second; };
			//��̽���ڵ㲻Ϊblock���Ҳ���closed����
			if (!next.block && find_if(closedList.begin(), closedList.end(), preLambta) == closedList.end()) {
				//��̽���ڵ㲻��open����
				if (find_if(openList.begin(), openList.end(), preLambta) == openList.end()) {
					next.calculateCost(&currentNode, x2, y2);
					openList.push_back({nx,ny});
				}
				else {//��̽���ڵ���open����
					//��ǰ�ڵ��g+1��С��̽���ڵ��g�����¼���open����̽���ڵ��g���ĸ��׽ڵ�Ϊ��ǰ�ڵ�
					if (currentNode.g+1  < next.g) {
						next.calculateCost(&currentNode, x2, y2);
					}
				}
			}
		}
	}
	return false;
}

list<pair<int,int>>::iterator Astar::findLeastNode()
{
	auto result = openList.begin();
	for (auto i = openList.begin(); i != openList.end();i++) {
		if (nodeMap[result->second][result->first].f > nodeMap[i->second][i->first].f) {
			result = i;
		}
	}
	return result;
}

