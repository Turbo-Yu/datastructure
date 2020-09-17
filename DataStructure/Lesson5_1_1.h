#define MAXDATA 10000
typedef struct HeapStruct* MaxHeap;
typedef int ElementType;

struct HeapStruct {
	ElementType* Elements; //�洢Ԫ��
	int Size; //�ѵĵ�ǰԪ�ظ���
	int Capacity; //�ѵ��������
};

//����һ���յ�����
MaxHeap Create(int MaxSize);
//�ж�����H�Ƿ�������
bool IsFull(MaxHeap H);
//��Ԫ��item��������H��
void Insert(MaxHeap H, ElementType item);
//�ж�����H�Ƿ�Ϊ�ա�
bool IsEmpty(MaxHeap H);
//����H�����Ԫ��(�����ȼ�)��
ElementType DeleteMax(MaxHeap H);
//����20�����ݣ�Ȼ�󰴶�˳�����
void Invoke5_1_1();