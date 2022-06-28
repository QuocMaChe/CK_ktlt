#include<iostream>
using namespace std;


//Cau 1
void Cau01() {
	int N;
	int* arr;
	cout << "Nhap so luong coc: " ;
	cin >> N;
	arr = new int[N];
	cout << "--->Nhap do dai cua cac coc " << endl ;
	for (int i = 0; i < N; i++) {
		cout << "Coc " << i << " :";
		cin >> arr[i];
	}
	cout << endl;
	cout << "[";
	for (int i = 0; i < N; i++) {
		cout << arr[i]<<"	";
	}
	cout << "]" << endl;
	int* arr1 = new int[N/2];
	int j = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] < arr[i + 1]) {
			arr1[j] = arr[i];
		}
		else {
			arr1[j] = arr[i+1];
		}
		i = i + 1;
		j++;
	}
	int max = 0;
	for (int i = 0; i < N/2; i++) {
		for (int j = i; j < N/2; j++) {
			if (arr1[j] > max) {
				max = arr1[j];
			}
		}
	}
	cout << "\nRanh co do cao nhat la: " << max << endl;
}
//Khai bao danh sach lien ket cho cau 2 su dung
struct Node {
	Node* pNext;
	int data;
};
struct LinkedList {
	Node* pHead;
	Node* pTail;
};
void init(LinkedList& l) {
	l.pHead = l.pTail = NULL;
}
Node* create_node(int data) {
	Node* p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->pNext = NULL;
	p->data = data;
	return p;
}
void add_tail(LinkedList& l,Node* new_node) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = new_node;
	}
	else {
		l.pTail->pNext = new_node;
		l.pTail = new_node;
	}
}
void add_head(LinkedList& l, Node* new_node) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = new_node;
	}
	else {
		new_node->pNext = l.pHead;
		l.pHead = new_node;
	}
}
//Cau 2
void yeucau1_2(LinkedList& l) {
	//
	if (l.pHead == NULL) {
		return;
	}
	Node* i_prev = l.pHead;
	for (Node* i = l.pHead->pNext; i != NULL; i = i->pNext) {
		for (Node* j = i->pNext; j != NULL; j = j->pNext) {
			if (i->data % 2 == 0 && i_prev->data % 2 == 0 || i->data % 2 != 0 && i_prev->data % 2 != 0) {
				int temp =i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
		i_prev = i;
	}
	//
	for (Node* i = l.pHead; i != NULL; i = i->pNext) {
		cout << i->data << "--->";
	}
}
bool is_songuyento(int n) {
	if (n < 2) {
		return false;
	}
	else {
		int i, j = 1;
		for (i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				j = 0;
				break;
			}
		}
		if (j == 1) {
			return true;
		}
		else {
			return false;
		}

	}
}
void yeucau2_2(LinkedList& l) {
	if (l.pHead == NULL) {
		return;
	}
	int count = 0;
	for (Node* i = l.pHead->pNext; i != NULL; i = i->pNext) {
		if (is_songuyento(i->data)  == true) {
			count++;
		}
	}
	int* arr = new int[count + 1];
	int k = 0;
	for (Node* i = l.pHead->pNext; i != NULL; i = i->pNext) {
		if (is_songuyento(i->data) == true) {
			arr[k] = i->data;
			k++;
		}
	}
	k = 0;
	Node* current = l.pHead;
	Node* i_prev = l.pHead;
	for (Node* i = l.pHead->pNext; i != NULL; i = i->pNext) {
		if (i->data==arr[k]) {
			Node* new_node = create_node(i->data);
			current->pNext = new_node;
			new_node->pNext = i_prev;
			i_prev->pNext = i->pNext;

			i = i_prev->pNext;
			current = i_prev;
			k++;
		}
		i_prev = i;
	}
	cout << endl;
	for (Node* i = l.pHead; i != NULL; i = i->pNext) {
		cout << i->data << "--->";
	}
}
void Cau02() {
	int luachon;
	LinkedList l;
	init(l);
	int N, n;
	cout << "Nhap so luong phan tu: ";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cout << "n" << i << " :";
		cin >> n;
		Node* new_node = create_node(n);
		add_tail(l, new_node);
	}
	cout << endl;
	do {
		cout << "1. Yeu cau 1" << endl;
		cout << "2. Yeu cau 2 " << endl;
		cout << "0. Thoat" << endl;
		cout << "--->Nhap lua chon:";
		cin >> luachon;
		if (luachon == 1) {
			yeucau1_2(l);
			cout << endl;
			system("pause");
			system("cls");
		}
		if (luachon == 2) {
			yeucau2_2(l);
			system("pause");
			system("cls");
		}
		if (luachon == 0 || cin.fail()) {
			break;
		}
	} while (true);
}
//Khai bao danh sach lien ket cho cau 3 su dung
struct NODE {
	NODE* pNext;
	double data;
};
struct LinkedList_3 {
	NODE* pHead;
	NODE* pTail;
};
void init3(LinkedList_3& l) {
	l.pHead = l.pTail = NULL;
}
NODE* create_node_3(float data) {
	NODE* p = new NODE;
	if (p == NULL) {
		return NULL;
	}
	p->pNext = NULL;
	p->data = data;
	return p;
}
void add_tail_3(LinkedList_3& l, NODE* new_node) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = new_node;
	}
	else {
		l.pTail->pNext = new_node;
		l.pTail = new_node;
	}
}
//Cau 3
void Cau03() {
	//int arr[][4] = { 3,1,6,7,8,4,5,2,1,9,2,9,4,2,10,12 };
	LinkedList_3 l3;
	init3(l3);
	float** arr;
	int n;
	cout << "Nhap so dong va so cot (NxN): ";
	cin >> n;
	arr = new float* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new float[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "arr[" << i << "][" << j << "]: ";
			cin >> arr[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
	//
	int row = n - 1, collumn = n - 1, i = 0, j = 0, count = 0;
	do {
		for (int k = j; k <= collumn; k++) {
			NODE* new_node = create_node_3(arr[i][k]);
			add_tail_3(l3, new_node);
		}
		i++;
		for (int k = row; k > i - 1; k--) {
			NODE* new_node = create_node_3(arr[k][collumn]);
			add_tail_3(l3, new_node);
		}
		collumn--;
		for (int k = collumn; k >= j; k--) {
			NODE* new_node = create_node_3(arr[row][k]);
			add_tail_3(l3, new_node);
		}
		row--;
		for (int k = i; k <= row; k++) {
			NODE* new_node = create_node_3(arr[k][j]);
			add_tail_3(l3, new_node);
		}
		j++;
		count++;
		if (count == 2 * n - 1) {
			break;
		}
	} while (true);
	cout << endl;
	cout << "So nhom: " << count << endl;
	cout << "---->Danh sach lien ket" << endl;
	for (NODE* i = l3.pHead; i != NULL; i = i->pNext) {
		cout << i->data << "--->";
	}
	cout << endl;
}
//
int main() {
	Cau01();
	cout << endl;
	Cau02();
	cout << endl;
	Cau03();
	return 0;
}