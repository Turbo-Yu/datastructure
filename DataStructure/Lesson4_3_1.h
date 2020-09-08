/*********************************
* 判断是否是相同二叉搜索树
*********************************/
#include <stdio.h>
#define MAXSIZE 10

typedef struct TreeNode* Tree;
struct TreeNode {
	int value;
	Tree Left, Right;
	int flag;
};