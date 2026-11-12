#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include"string.h"

using namespace std;

typedef struct Node* Nodeptr;

struct Student
{
	char id[10];
	char fullname[30];
	float score;
};

struct Node {
	Student data;
	Nodeptr link;
};


void init(Nodeptr& list);
int isEmpty(Nodeptr list);
void freeList(Nodeptr& list);
Nodeptr createStudent(Student x);
Nodeptr addFirst(Nodeptr& list, Student x);
bool isDuplicate(Nodeptr& list, char* id);
void createList(Nodeptr& list);
void printList(Nodeptr list);

Nodeptr addLast(Nodeptr& list, Student x);
Nodeptr findStudent(Nodeptr list, char* id);
Nodeptr findHighScore(Nodeptr list);



