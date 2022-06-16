#include <iostream>
using namespace std;
class celltype;
class List
{
public:
	List();
	~List();
	void Next(int position);
	int Retrieve(int position);
	int Locate(int data);
	void push_head(int data);
	void Insert(int data, int position);
	void Delete(int position);
	int End();
	int First();
	void pop_front();
	void push_forward(int data);
	void delete_dis();
private:
	class celltype
	{
	public:
		celltype* next;
		int data;
		celltype(int data = 0, celltype* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	celltype* head;
	int size;
};
List::List()
{
	head = nullptr;
	size = 0;
}
List::~List()
{
	delete_dis();
}
void List::Next(int position)
{
	if (position == 0)
	{
		cout << "Next() - " << head->next << endl << endl;
	}
	else
	{
		celltype* current = this->head;
		for (int i = 0; i < position; i++)
		{
			current = current->next;
		}
		cout << "Next() - " << current->next << endl << endl;
	}
}
int List::Retrieve(int position)
{
	if (position == 0)
	{
		return head->data;
	}
	else
	{
		celltype* current = this->head;
		for (int i = 0; i < position; i++)
		{
			current = current->next;
		}
		return current->data;
	}
}
int List::Locate(int data)
{
	int position = 0; celltype*
		current = this->head;
	celltype* find = this->head;
	while (current->next != nullptr)
	{
		current = current->next;
		position++;
		if (current->data == data)
		{
			return position;
		}
	}
}
void List::push_head(int data)
{
	head = new celltype(data, head);
	size++;
}
void List::Insert(int data, int position)
{
	if (position == 0)
	{
		push_head(data);
	}
	else
	{
		celltype* previous = this->head;
		for (int i = 0; i < position - 1; i++)
		{
			previous = previous->next;
		}
		celltype* New = new celltype(data, previous->next);
		previous->next = New;
		size++;
	}
}
void List::Delete(int position)
{
	if (position == 0)
	{
		pop_front();
	}
	else
	{
		celltype* previous = this->head;
		for (int i = 0; i < position - 1; i++)
		{
			previous = previous->next;
		}
		celltype* Delete = previous->next;
		previous->next = Delete->next;
		delete Delete;
		size--;
	}
}
int List::End()
{
	celltype* current = this->head;
	int Last;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	Last = current->data;
	return Last;
}
int List::First()
{
	return head->data;
}
void List::delete_dis()
{
	while (size > 0)
	{
		pop_front();
	}
}
void List::pop_front()
{
	celltype* temp = head;
	head = head->next;
	delete temp;
	size--;
}
void List::push_forward(int data)
{
	if (this->head == nullptr)
	{
		this->head = new celltype(data);
	}
	else
	{
		celltype* current = this->head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new celltype(data);
	}
	size++;
}
int main()
{
	List lst;
	lst.push_forward(12);
	lst.push_forward(36);
	lst.push_forward(11);
	lst.push_forward(132);
	lst.Insert(256, 2);
	lst.Delete(0);
	cout << "End() - " << lst.End() << endl << endl;
	cout << "First() - " << lst.First() << endl << endl;
	cout << "Locate() - " << lst.Locate(256) << endl << endl;
	cout << "Retreive() - " << lst.Retrieve(0) << endl << endl;
	lst.Next(1);
}