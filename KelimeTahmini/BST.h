#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include "LinkedList.h"

using namespace std;

// A�ac�n d���mlerini olu�turan class
static class tree {
public:
	std::string veri = ""; // A�ac�n 3 karakterli ismi(veri)
	int kToplam; // D���mleri BST tipine uygun yerle�tirmek i�in karakterlerin ascii tablosu kar��l���ndaki say� de�erlerinin toplam�
	tree* sol; // Ana d���m�n sol cocu�u
	tree* sag; // Ana d���m�n sa� �ocu�u
	tree* parent; // d���m�n ana d���m�

	node* node = NULL; // Her d���m�n i�erdi�i kelimeleri tutan ba�l� listenin referans d���m�
};
// A�ac� olu�turan,arama yapan ve program bitiminde silen calss
class BST
{
public:
	tree* first=NULL; // A�ac�n referans d���m�n� de�i�kene al�yoruz ��nk� silme i�lemi yap�caz bu d���m �zerinden
public:
	void AddWords(tree*&); // D���m�n sahip oldu�u ba�l� listeye kelimeleri ekler
	void insert(tree *&, int ktplm, std::string); // A�aca d���m ekler
	void ReadFile(); // Dosyadan verileri �eker
	void Search(tree*,std::string vri,int); // A�a�ta arama yapar
	string Smaller(string word); // Kullan�c� kelimeyi b�y�k harfle girerse bunlar� k���lt�r
	void Enter(tree* agac); // Kullan�c�dan girdi al�r
	void Delete(tree*&); // A�ac� yok eder
	void Postorder(tree*); // A�ac� postorder olarak dola��r silmek i�in.
	BST(tree*);
	~BST();
};

