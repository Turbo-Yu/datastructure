#define MAXDATA 10000
typedef struct HeapStruct* MaxHeap;
typedef int ElementType;

struct HeapStruct {
	ElementType* Elements; //存储元素
	int Size; //堆的当前元素个数
	int Capacity; //堆的最大容量
};

//创建一个空的最大堆
MaxHeap Create(int MaxSize);
//判断最大堆H是否已满。
bool IsFull(MaxHeap H);
//将元素item插入最大堆H。
void Insert(MaxHeap H, ElementType item);
//判断最大堆H是否为空。
bool IsEmpty(MaxHeap H);
//返回H中最大元素(高优先级)。
ElementType DeleteMax(MaxHeap H);
//插入20个数据，然后按堆顺序输出
void Invoke5_1_1();