typedef struct AVLNode* Position;
typedef Position AVLTree; /* AVL树类型 */
typedef int ElementType;
struct AVLNode {
	ElementType Data; /* 结点数据 */
	AVLTree Left;     /* 指向左子树 */
	AVLTree Right;    /* 指向右子树 */
	int Height;       /* 树高 */
};

int Max(int a, int b);
int GetHeight(AVLTree tree);
AVLTree SingleLeftRotation(AVLTree A);
AVLTree SingleRightRotation(AVLTree A);
AVLTree DoubleLeftRightRotation(AVLTree A);
AVLTree DoubleRightLeftRotation(AVLTree A);
AVLTree Insert(AVLTree T, ElementType X);