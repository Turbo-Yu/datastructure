/*********************************
* �ж��Ƿ�����ͬ����������
*********************************/
#include <stdio.h>
#define MAXSIZE 10

typedef struct TreeNode* Tree;
struct TreeNode {
	int value;
	Tree Left, Right;
	int flag;
};