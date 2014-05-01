#ifndef _TREE_H_
#define _TREE_H__
typedef int TElemType;//定义二叉树结点的数据元素类型
typedef struct BiTNode 

{
	//定义二叉树的结点
	TElemType data;
	struct BiTNode *lchild,*rchild;//左、右孩子指针
}BiTNode,*BiTree;
typedef BiTree SElemType;//自定义栈元素类型是二叉树
typedef BiTree QElemType;//自定义队列元素类型是二叉树
Status CreateBiTree (BiTree &T);
Status Display(TElemType e);
Status PreOrderTraverse(BiTree T,Status (*visit) (TElemType e));
Status InOrderTraverse(BiTree T,Status (*visit) (TElemType e));
Status PosterOrderTraverse (BiTree T,Status (*visit) (TElemType e));
Status LevelOrderTraverse (BiTree T,Status (*visit) (TElemType e));
Status PreOrderTraverse2 (BiTree T,Status (*visit) (TElemType e));
Status InOrderTraverse2 (BiTree T,Status (*visit) (TElemType e));
Status InOrderTraverse3 (BiTree T,Status (*visit) (TElemType e));
Status PosterOrderTraverse2 (BiTree T,Status (*visit) (TElemType e));
Status InOrderTraverse3(BiTree T,Status (*visit)(TElemType e));
#endif