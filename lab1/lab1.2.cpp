#include <iostream>
using namespace std;
class celltype;
class List
{
public:
	List();
	~List();
	void Printlist();
	void Next(int position);
	void Previous(int position);
	int Retrieve(int position);
	int Locate(int data);
	void push_head(int data);
	void Insert(int data, int position);
	void Delete(int position);
	int End();
	int First();
	void pop_front();
	void push_forward(int data);
private:
	class celltype
	{
	public:
		celltype* next;
		celltype* prev;
		int data;
		celltype(int data = 0, celltype* next = nullptr, celltype*
			prev = nullptr)
		{
			this->data = data;
		}

		this->next = next;
		this->prev = prev;
	}
};
celltype* head;
celltype* tail;
};
List::List()
{
	head = nullptr;
	tail = nullptr;
}
List::~List()
{
}
void List::Printlist()
{
	celltype* current = this->head;
	while (current->next != nullptr)
	{
		cout << current->data << endl;
		current = current->next;
	}
	cout << current->data << endl << endl;
}
void List::Next(int position)
{
	if (position == 0)
	{
		cout << "NEXT()\t\t" << head->next << endl << endl;
	}
	else
	{
		celltype* current = this->head;
		for (int i = 0; i < position; i++)
		{
			current = current->next;
		}
		cout << "NEXT()\t\t" << current->next << endl << endl;
	}
}
void List::Previous(int position)
{
	if (position == 0)
	{
		cout << "PREVIOUS()\t" << NULL << endl << endl;
	}
	else
	{
		celltype* current = this->head;
		for (int i = 0; i < position; i++)
		{
			current = current->next;
		}
		cout << "PREVIOUS()\t" << current->prev << endl << endl;
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
	int position = 0;
	celltype* current = this->head;
	celltype* find = this->head;
	while (current->next != nullptr)
	{
		current = current->next;
	}

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
void List::pop_front()
{
	celltype* temp = head;
	head = head->next;
	delete temp;
}
void List::push_forward(int data)
{
	celltype* temp = new celltype;
	temp->next = nullptr;
	temp->data = data;
	if (head != nullptr)
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}

}
else
{
temp->prev = nullptr;
head = tail = temp;
}
}
int main()
{
	List lst;
	lst.push_forward(12);
	lst.push_forward(36);
	lst.push_forward(11);
	lst.push_forward(132);
	lst.Printlist();
	lst.Insert(256, 2);
	lst.Printlist();
	lst.Delete(0);
	cout << "End - " << lst.End() << endl << endl;
	cout << "First - " << lst.First() << endl << endl;
	cout << "Locate - " << lst.Locate(256) << endl << endl;
	cout << "Retrieve - " << lst.Retrieve(1) << endl << endl;
	lst.Next(1);
	lst.Previous(3);
	cout << endl;
	lst.Printlist();
}