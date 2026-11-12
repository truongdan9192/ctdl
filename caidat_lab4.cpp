#include"thuvien_lab4.h"
void init(Nodeptr& list) {
	list = NULL;
}

int isEmpty(Nodeptr list) {
	return list == NULL ? 1 : 0;
}

void freeList(Nodeptr& list) {
	Nodeptr p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}
Nodeptr createStudent(Student x) {
	Nodeptr p;
	p = new Node;
	p->data = x;
	p->link = NULL;
	return p;
}


//ham them 1 sinh vien (them dau)
Nodeptr addFirst(Nodeptr& list, Student x) {
	Nodeptr p = createStudent(x);
	p->link = list;
	list = p;
	return p;
}

//them cuoi 
Nodeptr addLast(Nodeptr& list, Student x) {
	Nodeptr newNode = createStudent(x);
	if (list == NULL) {
		list = newNode;
		return newNode;
	}
	Nodeptr p = list;
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = newNode;
	return newNode;
}

bool isDuplicate(Nodeptr& list, char* id) {
	Nodeptr p = list;
	while (p != NULL) {
		if (strcmp(p->data.id, id) == 0)
			return true;
		p = p->link;
	}
	return false;
}

//nhap DSSV
void createList(Nodeptr& list) {
	Student student;
	init(list);
	do {
		cout << "\nNhap id (Nhap 0 de thoat): ";
		cin.getline(student.id, 10);
		while (isDuplicate(list, student.id)) {
			cout << "\nDa co id sinh vien";
			cout << "\nNhap lai id: ";
			cin.getline(student.id, 10);
		}
		if (strcmp(student.id, "0")==0)
		{
			break;
		}
		cout << "\nNhap ten sinh vien: ";
		cin.getline(student.fullname, 30);
		cout << "\nNhap diem: ";
		cin >> student.score;
		cin.ignore();
		addFirst(list, student);

	} while (1);
}

//xuat dssv

void printList(Nodeptr list) {
	cout << setw(0) << "ID" << setw(15) << "Ten" << setw(20) << "Diem" << endl;
	while (list != NULL) {
		cout << setw(0) << list->data.id << setw(15) << list->data.fullname << setw(20) << list->data.score << endl;
		list = list->link;
	}

}


// ham tim sinh vien 
Nodeptr findStudent(Nodeptr list, char* id) {
	Nodeptr p = list;
	while (p != NULL) {
		if (strcmp(p->data.id, id) == 0) {
			return p;
		}
		p = p->link;
	}
	return NULL;
}

//tim sinh vien co diem cao nhat
Nodeptr findHighScore(Nodeptr list) {
	Nodeptr max = list;
	Nodeptr p = list->link;
	
	while (p != NULL) {
		if (p->data.score > max->data.score) {
			max = p;
		}
		p = p->link;
	}
	return max;
}