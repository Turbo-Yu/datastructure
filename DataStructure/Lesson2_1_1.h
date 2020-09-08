/*********************************
* 线性表的顺序存储结构
*********************************/
#include <stdio.h>
#define MAXSIZE 15

typedef int ElementType;

struct LNode {
	ElementType Data[MAXSIZE]; //数据内容
	int Length;//结尾
};
typedef struct LNode* List;

List MakeEmpty();
int Find(ElementType x, List PtrL);
void Insert(ElementType x, int i, List PtrL);
void Delete(int i, List PtrL);

void Invoke2_1_1();

//移除数列中的最小值 T=O(n)
bool RemoveMinValue(LNode& L, ElementType x);

//逆置数列 T=O(n) S=O(1)
void Reset(LNode& L);

//删除数列中值为x的元素 T=O(n) S=O(1)
void RemoveAllRepeat(LNode& L, ElementType x);

//删除大于s小于t的元素 T=O(n)
bool RemoveSpan(LNode& L, ElementType s, ElementType t);

//有序数列去重
void DistinctSeq(LNode& L);

//合并两个有序数列到一个有序数列
bool CombineSeq(LNode& L1, LNode& L2, LNode& L);
void Test_CombineSeq();