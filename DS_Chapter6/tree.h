#ifndef _TREE_H_
#define _TREE_H__
typedef int TElemType;//�����������������Ԫ������
typedef struct BiTNode 

{
	//����������Ľ��
	TElemType data;
	struct BiTNode *lchild,*rchild;//���Һ���ָ��
}BiTNode,*BiTree;
typedef BiTree SElemType;//�Զ���ջԪ�������Ƕ�����
typedef BiTree QElemType;//�Զ������Ԫ�������Ƕ�����
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