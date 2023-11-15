#include "head4tree.h"
#include "drawtree.h"

linktree bst_insert(linktree root, linktree new)
{
	if(new == NULL)
		return root;

	if(root == NULL)
		return new;

	if(new->data > root->data)
	{
		root->rchild = bst_insert(root->rchild, new);
	}
	else if(new->data < root->data)
	{
		root->lchild = bst_insert(root->lchild, new);
	}
	else
	{
		printf("%ld is already exist.\n", new->data);
	}

	return root;
}

/*
linktree bst_find(linktree root, tn_datatype data)
{
	if(root == NULL)
		return NULL;

	if(data < root->data)
		return bst_find(root->lchild, data);
	else if(data > root->data)
		return bst_find(root->rchild, data);
	else
		return root;
}

linktree bst_remove(linktree root, tn_datatype n)
{
	if(root == NULL)
		return NULL;

	if(n < root->data)
		root->lchild = bst_remove(root->lchild, n);
	else if(n > root->data)
		root->rchild = bst_remove(root->rchild, n);
	else
	{
		linktree tmp;
		if(root->lchild != NULL)
		{
			for(tmp=root->lchild; tmp->rchild!=NULL;
			    tmp=tmp->rchild);

			root->data = tmp->data;
			root->lchild = bst_remove(root->lchild, tmp->data);
		}
		else if(root->rchild != NULL)
		{
			for(tmp=root->rchild; tmp->lchild!=NULL;
			    tmp=tmp->lchild);

			root->data = tmp->data;
			root->rchild = bst_remove(root->rchild, tmp->data);
		}
		else
		{
			free(root);
			return NULL;
		}
	}
	return root;
}
*/

int main(void)
{
	linktree root;
	root = NULL;

	printf("输入大于0的数插入节点\n");
	printf("输入小于0的数删除节点\n");
	printf("输入0退出程序\n");

	int n;
	while(1)
	{
		scanf("%d", &n);

		if(n > 0)
		{
			linktree new = new_node(n);
			root = bst_insert(root, new);
		}
		/*
		else if(n < 0)
		{
			root = bst_remove(root, -n);
		}
		*/
		if(n == 0)
			break;

		// 画一个网页显示二叉树的样子
		draw(root);

	}

	// 用火狐打开网页看看
	system("firefox *.html &");

	return 0;
}
