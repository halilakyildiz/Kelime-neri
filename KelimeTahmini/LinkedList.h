#pragma once

#include <iostream>
#include<string>

// Baðlý listenin düðümlerini oluþturan class
class node {
public:
	std::string veri = "";
	node * next;
};

// Baðlý liste üzerind iþlemler yapan class
class LinkedList
{
public:
	LinkedList();
	void insert(node*&,std::string); // Baðlý listeye düðüm ekler
	void Write(node *); // Baðlý listenin içeriðini yazdýrýr
	void DeleteList(node*&); // Baðlý listeyi temizler
	~LinkedList();
	
};

