/*********************************
* ���Ա��˳��洢�ṹ
*********************************/
#include <stdio.h>
#define MAXSIZE 15

typedef int ElementType;

struct LNode {
	ElementType Data[MAXSIZE]; //��������
	int Length;//��β
};
typedef struct LNode* List;

List MakeEmpty();
int Find(ElementType x, List PtrL);
void Insert(ElementType x, int i, List PtrL);
void Delete(int i, List PtrL);

void Invoke2_1_1();

//�Ƴ������е���Сֵ T=O(n)
bool RemoveMinValue(LNode& L, ElementType x);

//�������� T=O(n) S=O(1)
void Reset(LNode& L);

//ɾ��������ֵΪx��Ԫ�� T=O(n) S=O(1)
void RemoveAllRepeat(LNode& L, ElementType x);

//ɾ������sС��t��Ԫ�� T=O(n)
bool RemoveSpan(LNode& L, ElementType s, ElementType t);

//��������ȥ��
void DistinctSeq(LNode& L);

//�ϲ������������е�һ����������
bool CombineSeq(LNode& L1, LNode& L2, LNode& L);
void Test_CombineSeq();