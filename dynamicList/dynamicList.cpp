#include <iostream>
#include <vector>
using namespace std;

class List
{
public:
	List();
	~List();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в начало списка
	void push_front(int data);

	//удаление последнего элемента в списке
	void pop_back();

	//добавление элемента в конец списка
	void push_back(int data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	int& operator[](const int index);

	//добавление элемента в список по указанному индексу
	void insert(int data, int index);

	//удаление элемента в списке по указанному индексу
	void removeAt(int index);

	void BubbleSort();

	class Node
	{
	public:
		Node* pNext;
		int data;

		Node(int data = NULL, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node* head;
};

List::List()
{
	Size = 0;
	head = nullptr;
}


List::~List() { clear(); }


void List::pop_front()
{
	Node* temp = head;

	head = head->pNext;

	delete temp;

	Size--;
}

void List::push_back(int data)
{
	if (head == nullptr) head = new Node(data);
	else
	{
		Node* current = this->head;

		while (current->pNext != nullptr) current = current->pNext;

		current->pNext = new Node(data);
	}
	Size++;
}

void List::clear() { while(Size) pop_front(); }

int& List::operator[](const int index)
{
	int counter = 0;

	Node* current = this->head;

	while (current != nullptr)
	{
		if (counter == index) return current->data;

		current = current->pNext;
		counter++;
	}
}

void List::push_front(int data)
{
	head = new Node(data, head);
	Size++;
}

void List::insert(int data, int index)
{
	if (index == 0) push_front(data);
	else
	{
		Node* previous = this->head;

		for (int i = 0; i < index - 1; i++) previous = previous->pNext;

		Node* newNode = new Node(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}
}

void List::removeAt(int index)
{
	if (index == 0) pop_front();
	else
	{
		Node* previous = this->head;

		for (int i = 0; i < index - 1; i++) previous = previous->pNext;

		Node* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

void List::pop_back() { removeAt(Size - 1); }

void List::BubbleSort() {

	Node* p1 = nullptr;
	Node* p2 = this->head;
	Node* p3 = p2->pNext;

	for (int i = 1; i < this->GetSize(); i++) {

		for (int j = 0; j < this->GetSize() - i; j++) {
			
			if (p2->data > p3->data) {

				p2->pNext = p3->pNext;

				if(p1 != nullptr) p1->pNext = p3;

				p3->pNext = p2;

				p1 = p3;
				p3 = p2->pNext;
			}
			else {
				p1 = p2;
				p2 = p3;
				p3 = p2->pNext;

			}
			if (j == 0) head = p1;
		}
		p1 = nullptr;
		p2 = head;
		p3 = p2->pNext;
	}
}

int main()
{
	List lst;

	int N;
	cout << "What is the size of massive: " << endl;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		lst.push_back(rand() % 2001 - 1000);
		cout << lst[i] << " ";
	}
	cout << "\n\n\n" << endl;

	lst.BubbleSort();

	for (int i = 0; i < lst.GetSize(); i++) cout << lst[i] << " ";

	return 0;
}