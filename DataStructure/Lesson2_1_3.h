/*********************************
* 多重链表
* 广义表的链式存储结构
*********************************/
#include <stdio.h>
#define ENDOF NULL

typedef	 struct GNode* GList;

struct GNode {
	int Tage;//标志域:0标识节点是单元素,1标识节点是广义表
	union { // 子表指针域SubList和单元素数据域Data复用内存,公用存储空间
		int Data;
		GList SubList;
	} URegion;
	GList Next;
};
