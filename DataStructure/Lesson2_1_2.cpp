/*********************************
* 线性表的链式存储结构
*********************************/

#include "Lesson2_1_2.h"
#include <stdio.h>
#include <iostream>
  
//链表的长度
int Length(List PtrL) 
{
	List p = PtrL;
	int i = 0;
	while (p->Data != ENDOF) {
		p = p->Next;
		i++;
	}
	return i;
}

//根据输入值查找
List FindIndex(int index, List PtrL)
{
	List p = PtrL;
	int i = 1;
	while (p != NULL && i < index) {//根据输入索引查找
		p = p->Next;
		i++;
	}
	if (i == index)
		return p;
	else
		return NULL;
}

//根据输入值查找
List FindValue(int value, List PtrL)
{
	List p = PtrL;
	int i = 1;
	while (p != NULL && p ->Data != value) {
		p = p->Next;
	}
	return p;
}

//将x插入链表中的i位置
List Insert(int x, int i, List PtrL)
{
	List p, s;
	if (i == 1) {
		s = (List)malloc(sizeof(struct LNode));
		s->Data = x;
		s->Next = PtrL;
		return s;
	}
	p = FindIndex(i - 1, PtrL);
	if (p == NULL) {
		printf("Validate Parameter.");
		return NULL;
	}
	else {//注意执行顺序
		s = (List)malloc(sizeof(struct LNode));
		s->Data = x;
		s->Next = p->Next;
		p->Next = s;
		return PtrL;
	}
}

List Delete(int i, List PtrL)
{
	List p, s;
	if (i == 1) {
		s = PtrL;
		if (PtrL != NULL)
			PtrL = PtrL->Next;
		else
			return NULL;
		free(s);
		return PtrL;
	}
	p = FindIndex(i - 1, PtrL);
	if (p == NULL) {
		printf("Can not find %d node.\n", i - 1);
		return NULL;
	}
	else if (p->Next == NULL) {
		printf("Can not find %d node's next node.\n", i - 1);
		return NULL;
	}
	else {
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return PtrL;
	}

}

void Invoke2_1_2()
{
	List PtrL = (List)malloc(sizeof(struct LNode));
	List p;
	int i = 0;
	for (i = 0; i < 10; i++) {
		PtrL = Insert(i + 5, i + 1, PtrL);//构造链表
	}

	PtrL = Insert(ENDOF, i + 1, PtrL);//插入结束标记
	printf("Current List length is: %d\n", Length(PtrL));
	printf("Current List is:\n");
	p = PtrL;
	i = 0;
	while (p->Data != ENDOF) {
		p = p->Next;
		i++;
		printf("%d:%d\n", i, p->Data);
	}
	printf("Inert 50 to current list.\n");
	Insert(50, 4, PtrL);
	printf("The index of 5 in list is %d.\n", FindIndex(5, PtrL)->Data);
	printf("The value of 50 in list is %d.\n", FindValue(50, PtrL)->Data);
	printf("Delete the value of index 3 in current list.\n");
	Delete(3, PtrL);
	printf("Current List length is: %d\n", Length(PtrL));
	printf("Current List is:\n");
	p = PtrL;
	i = 0;
	while (p->Data != ENDOF) {
		p = p->Next;
		i++;
		printf("%d:%d\n", i, p->Data);
	}
	return;
}