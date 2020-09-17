#include "Lesson5_1_1.h"
#include <stdio.h>
#include <iostream>

MaxHeap Create(int MaxSize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = (ElementType*)malloc((MaxSize + 1) * sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MAXDATA;//���塰�ڱ���
    return H;
}

bool IsFull(MaxHeap H)
{
    return H->Size == H->Capacity - 1;
}

//�����������뵽���丸��㵽����������������
void Insert(MaxHeap H, ElementType item)
{
    int i;
    if (IsFull(H)) {
        printf("����");
        return;
    }
    if (item > MAXDATA) {
        printf("�������ֵ");
        return;
    }
    i = ++H->Size;//iָ��������е����һ��Ԫ�ص�λ��
    for (; H->Elements[i / 2] < item; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = item;
}

bool IsEmpty(MaxHeap H)
{
    return H->Size == 0;
}

ElementType DeleteMax(MaxHeap H)
{
    int Parent, Child;
    ElementType MaxItem, temp;
    if (IsEmpty(H)) {
        printf("����Ϊ��");
        return NULL;
    }
    MaxItem = H->Elements[1];
    temp = H->Elements[H->Size--];//�����������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²���
    for (Parent = 1; Parent*2 < H->Size; Parent=Child)
    {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
            Child++;//Childָ�������ӽ��Ľϴ���
        if (temp >= H->Elements[Child])
            break;
        else//�ƶ�tempԪ�ص���һ��
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = temp;
    return MaxItem;
}


void Invoke5_1_1()
{
    int simple[20] = { 32,56,44,25,66,34,554,134,19,854,68,457,788,431,98,40,543,678,93,444 };
    MaxHeap H = Create(100);
    for (int i = 0; i < 20; i++)
    {
        Insert(H, simple[i]);
    }

    for (int i = 0; i < 20; i++)
    {
        printf("%d,\n",DeleteMax(H));
    }
    return;
}

