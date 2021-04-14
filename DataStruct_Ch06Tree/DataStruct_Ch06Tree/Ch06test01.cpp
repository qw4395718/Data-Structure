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

//TElemType visit(SqBiTree T)
//{
//	for (int i = 0; T[i] != NULL;i++)
//	printf("%d", T[i]);
//}
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

}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

