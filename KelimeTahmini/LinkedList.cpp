#include "pch.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
}
void LinkedList::insert(node*& n,std::string vr)
{
	//Baðlý listede hiç düðüm yoksa yani null ise ilk düðümü ekler.
	if (n == NULL) {
		 n = new node();
		 n->veri = vr;
		 n->next = NULL;
		
	}
	// Baðlý listede bir düðüm varsa ikinci düðümü ekler
	else if(n->next==NULL)
	{			
			node* r = new node();
			r->veri = vr;
			r->next = NULL;
			n->next = r;			
	}
	// listede birden fazla düðüm varsa en sona gelerek düðümü ekler
	else {
		node* iter = n; // Liste üzerinde en sona gelmek için baþka bir iþaretçiye alýyoruz
		while (iter->next != NULL) // Liste üzerinde en son düðüme geliyoruz
		{ 
			iter = iter->next;
		}
		node* r = new node(); // Yeni düðüm oluþturuyoruz.
		r->next=NULL;
		r->veri = vr;
		iter->next = r;		
	}
	
}
void LinkedList::Write(node * n) 
{
	node* iter = n;
	std::cout << iter->veri + " "; // Ýlk düðümü yazdýrýyoruz.
	while (iter->next != NULL) // Liste üzerinde ilerleyerek tek tek yazýyoruz 
	{
		iter = iter->next;
		std::cout << iter->veri+" ";			
	}
}
void LinkedList::DeleteList(node *& n) // Listenin düðümlerini siliyoruz
{
	// Liste boþ ise direkt dönüyouz
	if (n == NULL) {
		return;
	}
	// Listede bir düðüm varsa onu siliyoruz
	else if (n->next == NULL)
	{
		node* temp = n;
		n = NULL;
		delete temp;
	}
	// Eðer birden fazla düðüm varsa baþtan baþlayýp silerek ilerliyoruz
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
