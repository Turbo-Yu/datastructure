typedef struct AVLNode* Position;
typedef Position AVLTree; /* AVL������ */
typedef int ElementType;
struct AVLNode {
	ElementType Data; /* ������� */
	AVLTree Left;     /* ָ�������� */
	AVLTree Right;    /* ָ�������� */
	int Height;       /* ���� */
};

int Max(int a, int b);
int GetHeight(AVLTree tree);
AVLTree SingleLeftRotation(AVLTree A);
AVLTree SingleRightRotation(AVLTree A);
AVLTree DoubleLeftRightRotation(AVLTree A);
AVLTree DoubleRightLeftRotation(AVLTree A);
AVLTree Insert(AVLTree T, ElementType X);