/*********************************
* ��������
* ��������ʽ�洢�ṹ
*********************************/
#include <stdio.h>
#define ENDOF NULL

typedef	 struct GNode* GList;

struct GNode {
	int Tage;//��־��:0��ʶ�ڵ��ǵ�Ԫ��,1��ʶ�ڵ��ǹ����
	union { // �ӱ�ָ����SubList�͵�Ԫ��������Data�����ڴ�,���ô洢�ռ�
		int Data;
		GList SubList;
	} URegion;
	GList Next;
};
