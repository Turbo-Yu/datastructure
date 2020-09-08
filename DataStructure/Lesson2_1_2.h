/*********************************
* 线性表的链式存储结构
*********************************/
#include <stdio.h>
#define ENDOF NULL

typedef struct LNode* List;
struct LNode {
	int Data;
	LNode* Next;
};
int Length(List PtrL);
List FindIndex(int index, List PtrL);
List FindValue(int value, List PtrL);
List Insert(int x, int i, List PtrL);
List Delete(int i, List PtrL);
void Invoke2_1_2();
