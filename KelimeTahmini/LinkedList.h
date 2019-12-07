#pragma once

#include <iostream>
#include<string>

// Ba�l� listenin d���mlerini olu�turan class
class node {
public:
	std::string veri = "";
	node * next;
};

// Ba�l� liste �zerind i�lemler yapan class
class LinkedList
{
public:
	LinkedList();
	void insert(node*&,std::string); // Ba�l� listeye d���m ekler
	void Write(node *); // Ba�l� listenin i�eri�ini yazd�r�r
	void DeleteList(node*&); // Ba�l� listeyi temizler
	~LinkedList();
	
};

