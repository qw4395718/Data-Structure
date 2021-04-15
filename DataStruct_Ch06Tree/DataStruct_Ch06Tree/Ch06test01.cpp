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

Status visit(TElemType c)
{
	printf("%d ", c);
	return OK;
}

TElemType Nil = 0; /*  ��������0Ϊ�� */

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

/*  ��ʼ����:����������.�������:����T�����  */
int BiTreeDepth(SqBiTree T)
{
	int i, j = -1;
	for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
	{//�������β����ǰ����,������ֿսڵ��(PS:�����ǰ��������ļ���:��ǰ�ڵ�ǿսڵ㲢���丸ĸ��Ϊ�սڵ���Υ��)
		if (T[i] != Nil)
			break;
		i++;
		do
		j++;
		while (i >= powl(2, j));//��ĸ���ӵĹ�ϵ(�������±�):Parent_Node = (int)Children_Node /2;
		return j;
	}
}

/*  ��ʼ����:���������� */
/*  �������:��T����ʱ,��e����T�ĸ�,����OK.���򷵻�ERROR*/
Status Root(SqBiTree T, TElemType *e)
{
	if (T[0] != 0)
	{
		*e = T[0];
		return OK;
	}
	return ERROR;
}

/* ��ʼ����:������T����,e��T��ĳ�����(��λ��) */
/* �������:���ش���λ��e�Ľ���ֵ */
Status Value(SqBiTree T, Position e)
{
	return T[(int)powl(2, e.level-1) + e.order - 1];
}

/* ��ʼ����:����������,e��T�е�ĳ���ڵ� */
/* �������:��e��T�ķǸ��ڵ�,�򷵻�����˫��,���򷵻�"��" */
TElemType Parent(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil)
		return Nil;
	for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
	{
		if (T[i] == e)
			return T[(i +1)/ 2 - 1];
	}
	return Nil;/* δ�ҵ���˫�� */
}

/* ��ʼ����:������T����,e��T�е�ĳ���ڵ� */
/* �������:*/
TElemType LeftChild(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil)
	{
		return Nil;//����
	}
	for (i = 0; i < MAX_TREE_SIZE - 1; i++)
	{
		if (T[i] == e)
			return T[i * 2];
	}
	return Nil;
}

TElemType RightChild(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil)
	{
		return Nil;//����
	}
	for (i = 0; i < MAX_TREE_SIZE - 1; i++)
	{
		if (T[i] == e)
			return T[i * 2+1];
	}
	return Nil;
}

/* ��ʼ����: ����������,e�����е�һ���ڵ� */
/* �������: ����e�����ֵ�,��e��T�����ӻ��������ֵ�,�򷵻ؿ�*/
TElemType LeftSibling(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil)
		return Nil;
	for (i = 1; i <= MAX_TREE_SIZE - 1;i++)
	if (T[i] == e&&i % 2 == 0)
		return T[i - 1];
	return Nil;
}

/* ��ʼ����: ������T����,e��T��ĳ����� */
/* �������: ����e�����ֵܡ���e��T���Һ��ӻ������ֵ�,�򷵻أ��գ� */
TElemType RightSibling(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil) /* ���� */
		return Nil;
	for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
	if (T[i] == e&&i % 2) /* �ҵ�e�������Ϊ����(������) */
		return T[i + 1];
	return Nil; /* û�ҵ�e */
}

/* PreOrderTraverse()���� */
void PreTraverse(SqBiTree T, int e)
{
	visit(T[e]);
	if (T[2 * e + 1] != Nil) /* ���������� */
		PreTraverse(T, 2 * e + 1);
	if (T[2 * e + 2] != Nil) /* ���������� */
		PreTraverse(T, 2 * e + 2);
}

/* ��ʼ����: ���������� */
/* �������: �������T�� */
Status PreOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T))
	{
		PreTraverse(T, 0);
	}
	printf("\n");
	return OK;
}





int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

