// DataStruct_Ch06Tree.cpp : 定义控制台应用程序的入口点。
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

#define MAXSIZE 100 /* 存储空间初始分配量 */
#define MAX_TREE_SIZE 100 /* 二叉树的最大结点数 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int TElemType;  /* 树结点的数据类型，目前暂定为整型 */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0号单元存储根结点  */

typedef struct
{
	int level, order;
}Position;

Status visit(TElemType c)
{
	printf("%d ", c);
	return OK;
}

TElemType Nil = 0; /*  设整型以0为空 */

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
		T[j] = Nil; /* 将空赋值给T的后面的结点 */
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

/*  初始条件:二叉树存在.操作结果:返回T的深度  */
int BiTreeDepth(SqBiTree T)
{
	int i, j = -1;
	for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
	{//从数组的尾部向前搜索,避免出现空节点的(PS:这个与前面二叉树的检验:当前节点非空节点并且其父母不为空节点相违背)
		if (T[i] != Nil)
			break;
		i++;
		do
		j++;
		while (i >= powl(2, j));//父母与子的关系(非数组下标):Parent_Node = (int)Children_Node /2;
		return j;
	}
}

/*  初始条件:二叉树存在 */
/*  操作结果:当T不空时,用e返回T的根,返回OK.否则返回ERROR*/
Status Root(SqBiTree T, TElemType *e)
{
	if (T[0] != 0)
	{
		*e = T[0];
		return OK;
	}
	return ERROR;
}

/* 初始条件:二叉树T存在,e是T中某个结点(的位置) */
/* 操作结果:返回处于位置e的结点的值 */
Status Value(SqBiTree T, Position e)
{
	return T[(int)powl(2, e.level-1) + e.order - 1];
}

/* 初始条件:二叉树存在,e是T中的某个节点 */
/* 操作结果:若e是T的非根节点,则返回他的双亲,否则返回"否" */
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
	return Nil;/* 未找到其双亲 */
}

/* 初始条件:二叉树T存在,e是T中的某个节点 */
/* 操作结果:*/
TElemType LeftChild(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil)
	{
		return Nil;//空树
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
		return Nil;//空树
	}
	for (i = 0; i < MAX_TREE_SIZE - 1; i++)
	{
		if (T[i] == e)
			return T[i * 2+1];
	}
	return Nil;
}

/* 初始条件: 二叉树存在,e是其中的一个节点 */
/* 操作结果: 返回e的左兄弟,若e是T的左孩子或者无左兄弟,则返回空*/
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

/* 初始条件: 二叉树T存在,e是T中某个结点 */
/* 操作结果: 返回e的右兄弟。若e是T的右孩子或无右兄弟,则返回＂空＂ */
TElemType RightSibling(SqBiTree T, TElemType e)
{
	int i;
	if (T[0] == Nil) /* 空树 */
		return Nil;
	for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
	if (T[i] == e&&i % 2) /* 找到e且其序号为奇数(是左孩子) */
		return T[i + 1];
	return Nil; /* 没找到e */
}

/* PreOrderTraverse()调用 */
void PreTraverse(SqBiTree T, int e)
{
	visit(T[e]);
	if (T[2 * e + 1] != Nil) /* 左子树不空 */
		PreTraverse(T, 2 * e + 1);
	if (T[2 * e + 2] != Nil) /* 右子树不空 */
		PreTraverse(T, 2 * e + 2);
}

/* 初始条件: 二叉树存在 */
/* 操作结果: 先序遍历T。 */
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

