#include"thuvien_lab4.h"
void main() {
	

	char id[10];
	Nodeptr list;
	createList(list);
	printList(list);
	/*freeList(list);*/
	system("pause");

	cout << "\nNhap id sinh vien can tim: ";
	cin.getline(id, 10);

	Nodeptr kq = findStudent(list, id);
	if (kq == NULL)
		cout << "Ko tim thay sinh vien";
	else {
		cout << "\nTim thay sinh vien!" <<endl;
		cout << setw(0) << "ID" << setw(15) << "Ten" << setw(20) << "Diem" << endl;
		cout << setw(0) << kq->data.id << setw(15) << kq->data.fullname << setw(20) << kq->data.score << endl;
	}

	Nodeptr kq1 = findHighScore(list);
	cout << "\nSinh vien co diem cao nhat: " << endl;
	cout << setw(0) << "ID" << setw(15) << "Ten" << setw(20) << "Diem" << endl;
	cout << setw(0) << kq1->data.id << setw(15) << kq1->data.fullname << setw(20) << kq1->data.score << endl;



	
}