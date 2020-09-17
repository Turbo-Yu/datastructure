#include "Lesson5_1_1.h"
#include <stdio.h>
#include <iostream>

MaxHeap Create(int MaxSize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = (ElementType*)malloc((MaxSize + 1) * sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MAXDATA;//定义“哨兵”
    return H;
}

bool IsFull(MaxHeap H)
{
    return H->Size == H->Capacity - 1;
}

//将新增结点插入到从其父结点到根结点的有序序列中
void Insert(MaxHeap H, ElementType item)
{
    int i;
    if (IsFull(H)) {
        printf("堆满");
        return;
    }
    if (item > MAXDATA) {
        printf("超出最大值");
        return;
    }
    i = ++H->Size;//i指向插入后堆中的最后一个元素的位置
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
        printf("最大堆为空");
        return NULL;
    }
    MaxItem = H->Elements[1];
    temp = H->Elements[H->Size--];//用最大堆中最后一个元素从根结点开始向上过滤下层结点
    for (Parent = 1; Parent*2 < H->Size; Parent=Child)
    {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
            Child++;//Child指向左右子结点的较大者
        if (temp >= H->Elements[Child])
            break;
        else//移动temp元素到下一层
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

