#include "pch.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
}
void LinkedList::insert(node*& n,std::string vr)
{
	//Ba�l� listede hi� d���m yoksa yani null ise ilk d���m� ekler.
	if (n == NULL) {
		 n = new node();
		 n->veri = vr;
		 n->next = NULL;
		
	}
	// Ba�l� listede bir d���m varsa ikinci d���m� ekler
	else if(n->next==NULL)
	{			
			node* r = new node();
			r->veri = vr;
			r->next = NULL;
			n->next = r;			
	}
	// listede birden fazla d���m varsa en sona gelerek d���m� ekler
	else {
		node* iter = n; // Liste �zerinde en sona gelmek i�in ba�ka bir i�aret�iye al�yoruz
		while (iter->next != NULL) // Liste �zerinde en son d���me geliyoruz
		{ 
			iter = iter->next;
		}
		node* r = new node(); // Yeni d���m olu�turuyoruz.
		r->next=NULL;
		r->veri = vr;
		iter->next = r;		
	}
	
}
void LinkedList::Write(node * n) 
{
	node* iter = n;
	std::cout << iter->veri + " "; // �lk d���m� yazd�r�yoruz.
	while (iter->next != NULL) // Liste �zerinde ilerleyerek tek tek yaz�yoruz 
	{
		iter = iter->next;
		std::cout << iter->veri+" ";			
	}
}
void LinkedList::DeleteList(node *& n) // Listenin d���mlerini siliyoruz
{
	// Liste bo� ise direkt d�n�youz
	if (n == NULL) {
		return;
	}
	// Listede bir d���m varsa onu siliyoruz
	else if (n->next == NULL)
	{
		node* temp = n;
		n = NULL;
		delete temp;
	}
	// E�er birden fazla d���m varsa ba�tan ba�lay�p silerek ilerliyoruz
	else {
		node* iter = n;
		while (iter->next != NULL) {
			node* temp = iter;
			iter = iter->next;
			delete temp;
		}
	}
}
LinkedList::~LinkedList()
{

}
