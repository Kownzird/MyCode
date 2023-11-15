#include "common.h"

// 设计链表的节点
typedef struct node
{
	int data;
	struct node *next;
}listnode, *linklist;


linklist init_list(void)
{
	return NULL;
}

linklist new_node(int data)
{
	linklist new = calloc(1, sizeof(listnode));
	if(new != NULL)
	{
		new->data = data;
		new->next = NULL;
	}
	return new;
}

linklist list_add_tail(linklist new, linklist head)
{
	// 当链表为空时，new其实就是链表的第一个节点
	if(head == NULL)
	{
		new->next = new;
		head = new;
		return head;
	}

	// 否则，找到末尾节点并把new插入到最末尾
	linklist tail = head;
	while(tail->next != head)
	{	
		tail = tail->next;	
	}

	new->next  = head;
	tail->next = new;
	return head;
}

void show(linklist head)
{
	linklist tmp;
	for(tmp=head; tmp->next!=head; tmp=tmp->next)
	{
		printf("%d\t", tmp->data);
	}
	printf("%d\n", tmp->data);
}

// 删除指定节点，并返回其下一个节点的指针
linklist list_del(linklist del)
{
	if(del == NULL)
		return NULL;

	// 0
	linklist tail = del;
	while(tail->next != del)
	{
		tail = tail->next;
	}

	// 1
	tail->next = del->next;

	// 2
	del->next = NULL;

	return tail->next;
}


linklist kill3(linklist head)
{
	if(head == NULL)
		return NULL;

	linklist del = head->next->next;
	linklist tmp;

	while(del != del->next->next) // 意味着：链表中存在>=3个节点
	{
		// 删除del，并返回其下一个节点指针tmp
		tmp = list_del(del);
		free(del);

		del = tmp->next->next;
	}

	return del;
}

// 自顶向下

int main(void)
{
	// 初始化了一条空链表
	linklist head = init_list();

	// 插入一些元素
	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++)
	{
		linklist new = new_node(i);
		head = list_add_tail(new, head);
	}
	show(head);

	// 数3出局
	linklist p = kill3(head);
	show(p);
}
