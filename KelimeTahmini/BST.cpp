#include "pch.h"
#include "BST.h"
#include<string>




BST::BST(tree* tr)
{
	first = tr;
	ReadFile();
}
LinkedList l1; // Ba�l� liste �zerinde i�lemler yapmak i�in kullan�lan nesne


void BST::AddWords(tree*& n) {
	ifstream ReadFile("words.txt");
	string line = "";

	if (ReadFile.is_open()) {
		while (getline(ReadFile, line)) {
			string three = line.substr(0, 3); // Okunan kelimenin ilk 3 harfini al�r
			if (three == n->veri) // Okunan ilk 3 harf e�er a�ac�n d���m�n�n verisiyle e�le�irse bu d���m�n ba�l�listesine kelimeyi ekler.
			{
				l1.insert(n->node, line);
			}
		}
	}
}
void BST::insert(tree *& agac, int ktplm, string vr) {

	// Eklenmek �zere gelen d���m�n karakterlerinin toplam�na g�re kar��la�t�rma yaparak a�a�ta ilerler.
	// En son a�ac�n bo� d���m�ne gelince oraya ilgili d���m� ekler.
	if (agac == NULL) {
		agac = new tree();
		agac->sag = NULL;
		agac->sol = NULL;
		agac->kToplam = ktplm;
		agac->veri = vr;
		AddWords(agac); // Olu�tuktan sonra Bu d���me ait kelimeler d���m�n blistesine eklenmek �zere g�nderilir.
	}

	// E�er karakter topam� ana d���m�nk�nden b�y�kse a�ac�n sa��na gider
	if (agac->kToplam < ktplm) {
		insert(agac->sag, ktplm, vr);
		agac->sag->parent = agac;
	}
	// E�er karakter topam� ana d���m�nk�nden k���kse a�ac�n soluna gider
	else if (agac->kToplam > ktplm)
	{
		insert(agac->sol, ktplm, vr);		
		agac->sol->parent = agac;
	}
}

// A�Aca eklenecek olan d���m�n verisindeki karakterlerinin ascii tablosundaki kar��l�klar�n� toplar ve int olarak d�nd�r�r
int SumChar(string word) {
	int sum = 0;
	for (int j = 0; j < word.size(); j++) {
		string s = word.substr(j, 1); // kelimenin ilk karkaterini al�yoruz
		const char* c = s.c_str(); // Bu karkateri char d�n��t�r�yoruz
		int b = (int)*c; // Sonrda char � int e d�n��t�r�yoruz
		sum += b; // Ve topluyoruz
	}
	return sum;
}
void BST::Enter(tree* agac) {
	string word;
	cout << "Enter word: ";
	cin >> word;
	word = Smaller(word); // Kullan�c� kelimeyi b�y�k harflerle girerse bunlar� k���k harfe d�n��t�r�r
	word = word.substr(0, 3);
	Search(agac, word, SumChar(word)); // Daha sonra bu girilen kelime a�acta arat�l�r
}
void BST::ReadFile() {

	ifstream ReadFile("words.txt");
	std::string line = "";

	if (ReadFile.is_open()) {
		while (getline(ReadFile, line)) {

			string firstThree = line.substr(0,3); 
			int ktplm = SumChar(firstThree); // ilk �� harfin karakter toplam�n� getirir

			insert(first, ktplm, firstThree); // Ve a�aca d���m� eklemek �zere g�nderiri
		}

		ReadFile.close();
	}
	Enter(first);
}
string BST::Smaller(string word) {
	string newLine = "";
	for (int i = 0; i < word.size(); i++) {
		string s = word.substr(i, 1); // ilke karaketri al�r
		const char* c = s.c_str(); // int e d�n���t�rmek �zere char a d�n��t�r�l�r
		int b = (int)*c; // daha sonra int e d�n��t�r�l�r
		if (b >= 65 && b <= 90) { // Ascii tablosuna g�re b�y�k harmi kontorl edilir.65-90 aras� b�y�k harftir.
			b = b + 32; // bunu o harf e denk gelen k���k harf yapmak �zere 32 ekle.��nk� ascii de aradaki fark 32 dir. 
		}
		char x = (char)b; // sonra tekrar char yap�l�r
		s = x; // ve stirnge d�n��t�r�l�r
		newLine += s;// Yeni sat�ra eklenir
	}
	return newLine;
}

void BST::Search(tree* tr,std::string vri,int kt) {
	
	// Gelen karakter toplam�na g�re a�ac�n sa��na ve soluna gidere preorder dola��r.  
	// En son d���me gelince ve ilgili d���m bulunursa o d���m�n ba�l� listesindeki kelimeleri yazar
	if (tr == NULL)
		return;
	else if (kt < tr->kToplam)
		Search(tr->sol, vri, kt);
	else if (kt > tr->kToplam)
		Search(tr->sag, vri, kt);
	else {
		if (tr->veri == vri)
		{
			cout << "Did you mean ";
			l1.Write(tr->node); // blistenin i�eri�i yaz�l�r
			cout << "?" << endl;
		} 
	}
			
}

// A�ac� yok etmek �zere postorder dola��r ve delete metodunu �a��rarak a�ac� siler.
void BST::Postorder(tree* tr) {
	if (tr == NULL)
		return;
	Postorder(tr->sol);
	Postorder(tr->sag);
	Delete(tr);
}
void BST::Delete(tree*& t) {
	l1.DeleteList(t->node);// �nce d���m�n ba�l� listesni silmek �zere g�nderilir.

	//Daha sonra d���m�n kendisi silinir

	//e�er d���m�n ait oldu�u ana d���m null ise bu k�k(yani ilk d���m)d�r.Oy�zden bunu kontrol ediyoruz
	if (t->parent != NULL) {
				
		if (t->parent->sol == t) // Gelen d���m,ait oldu�u ana d���m�n�n sa��ndam� yoksa solundami kontrol ediyoruz
			t->parent->sol = NULL;
		if (t->parent->sag == t) // Ve neresindeyse ana d���m�n oras�n� Null yap�yoruz.
			t->parent->sag = NULL;
	}
	
	delete t; // En sonunda d���m� siliyoruz
}
BST::~BST()
{
	Postorder(first); // Program bitiminde otomatik olarak y�k�c� metod �a�r�l�r ve a�a� silinir. 
}
