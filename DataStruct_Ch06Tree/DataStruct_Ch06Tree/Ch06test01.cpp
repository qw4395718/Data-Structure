// DataStruct_Ch06Tree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
#define MAX_TREE_SIZE 100 /* ��������������� */

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int TElemType;  /* �������������ͣ�Ŀǰ�ݶ�Ϊ���� */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0�ŵ�Ԫ�洢�����  */

typedef struct
{
	int level, order;
}Position;

//TElemType visit(SqBiTree T)
//{
//	for (int i = 0; T[i] != NULL;i++)
//	printf("%d", T[i]);
//}
TElemType Nil = 0;

Status InitBiTree(SqBiTree T)
{
	for (int i = 0; T[i] != MAX_TREE_SIZE; i++)
		T[i] = Nil;
	return OK;
}

Status CreateBiTree(SqBiTree T)
{
	int i;
	int j;
	printf("Please input Node sum:");
	scanf("%d", i);
	for (j = 0; j < i; j++)
	{
		printf("Please input No%d :", i);
		scanf("%d", T[j]);
		if (0 != T[(j + 1) / 2 - 1]
			&& 0 != T[j])
			return ERROR;
	}
	while (j<MAX_TREE_SIZE)
	{
		T[j] = Nil; /* ���ո�ֵ��T�ĺ���Ľ�� */
		i++;
	}
	return OK;
}

#define ClearBiTree InitBiTree

Status BiTreeEmpty(SqBiTree T)
{
	if (T[0] == Nil)
		return OK;
}

int BiTreeDepth(SqBiTree T)
{
	int i, j = -1;
	for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
	{

	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
