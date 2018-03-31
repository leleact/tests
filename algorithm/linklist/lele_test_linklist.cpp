#include <iostream>

template<typename T>
struct Node
{
	T value;
	struct Node *pNext;
};

// 清空线性表
template<typename T>
void ClearList(Node<T> *pList)
{
	if (nullptr == pList)
	{
		return;	
	}

	Node<T> *Temp = nullptr;
	while(pList != nullptr)
	{
		Temp = pList->pNext;
		free(pList);
		pList = Temp;
	}
}

// 将线性表中的第i个元素值返回给pOutNode
template<typename T>
T GetElem(Node<T> *pList, const int i)
{
	int index = 0;
	Node<T> Temp = pList;
	while(Temp != nullptr && i != index)
	{
		index++;	
		Temp = Temp->pNext;
	}

	return Temp->value;
}

// 将线性表中的查找value相等的元素, 返回序号
template<typename T>
int LocateElem(Node<T> *pList, const T &value)
{
	Node<T> *Temp = pList;
	int index = 0;
	while(Temp != nullptr)
	{
		index++;
		if (Temp->value == value)	
		{
			return index;	
		}
	}
	return 0;
}

// 在线性表中的第i个位置插入新元素e
template<typename T>
void ListInsert(Node<T> *pList, const int i, const T &value)
{
	if (i <= 0)
		return;
	Node<T> *Temp = pList;
	if (Temp == nullptr && i == 1)
	{
		Node<T>	*pElem = malloc(sizeof(Node<T>));
		pElem->value = value;
		pElem->pNext = pList;
		pList = pElem;
		return;
	}

	int index = 0;
	while(Temp != nullptr)
	{
		index++;
		if (i == index)
		{
				
		}
	}
}

// 删除线性表中的第i个元素，返回删除的值
template<typename T>
void ListDelete(Node<T> *pList, const int i, T &value);

// 返回线性表元素的个数
template<typename T>
std::size_t ListLength(Node<T> *pList);


int main()
{



}
