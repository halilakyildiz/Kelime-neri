#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include "LinkedList.h"

using namespace std;

// Aðacýn düðümlerini oluþturan class
static class tree {
public:
	std::string veri = ""; // Aðacýn 3 karakterli ismi(veri)
	int kToplam; // Düðümleri BST tipine uygun yerleþtirmek için karakterlerin ascii tablosu karþýlýðýndaki sayý deðerlerinin toplamý
	tree* sol; // Ana düðümün sol cocuðu
	tree* sag; // Ana düðümün sað çocuðu
	tree* parent; // düðümün ana düðümü

	node* node = NULL; // Her düðümün içerdiði kelimeleri tutan baðlý listenin referans düðümü
};
// Aðacý oluþturan,arama yapan ve program bitiminde silen calss
class BST
{
public:
	tree* first=NULL; // Aðacýn referans düðümünü deðiþkene alýyoruz çünkü silme iþlemi yapýcaz bu düðüm üzerinden
public:
	void AddWords(tree*&); // Düðümün sahip olduðu baðlý listeye kelimeleri ekler
	void insert(tree *&, int ktplm, std::string); // Aðaca düðüm ekler
	void ReadFile(); // Dosyadan verileri çeker
	void Search(tree*,std::string vri,int); // Aðaçta arama yapar
	string Smaller(string word); // Kullanýcý kelimeyi büyük harfle girerse bunlarý küçültür
	void Enter(tree* agac); // Kullanýcýdan girdi alýr
	void Delete(tree*&); // Aðacý yok eder
	void Postorder(tree*); // Aðacý postorder olarak dolaþýr silmek için.
	BST(tree*);
	~BST();
};

