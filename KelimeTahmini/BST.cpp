#include "pch.h"
#include "BST.h"
#include<string>




BST::BST(tree* tr)
{
	first = tr;
	ReadFile();
}
LinkedList l1; // Baðlý liste üzerinde iþlemler yapmak için kullanýlan nesne


void BST::AddWords(tree*& n) {
	ifstream ReadFile("words.txt");
	string line = "";

	if (ReadFile.is_open()) {
		while (getline(ReadFile, line)) {
			string three = line.substr(0, 3); // Okunan kelimenin ilk 3 harfini alýr
			if (three == n->veri) // Okunan ilk 3 harf eðer aðacýn düðümünün verisiyle eþleþirse bu düðümün baðlýlistesine kelimeyi ekler.
			{
				l1.insert(n->node, line);
			}
		}
	}
}
void BST::insert(tree *& agac, int ktplm, string vr) {

	// Eklenmek üzere gelen düðümün karakterlerinin toplamýna göre karþýlaþtýrma yaparak aðaçta ilerler.
	// En son aðacýn boþ düðümüne gelince oraya ilgili düðümü ekler.
	if (agac == NULL) {
		agac = new tree();
		agac->sag = NULL;
		agac->sol = NULL;
		agac->kToplam = ktplm;
		agac->veri = vr;
		AddWords(agac); // Oluþtuktan sonra Bu düðüme ait kelimeler düðümün blistesine eklenmek üzere gönderilir.
	}

	// Eðer karakter topamý ana düðümünkünden büyükse aðacýn saðýna gider
	if (agac->kToplam < ktplm) {
		insert(agac->sag, ktplm, vr);
		agac->sag->parent = agac;
	}
	// Eðer karakter topamý ana düðümünkünden küçükse aðacýn soluna gider
	else if (agac->kToplam > ktplm)
	{
		insert(agac->sol, ktplm, vr);		
		agac->sol->parent = agac;
	}
}

// AðAca eklenecek olan düðümün verisindeki karakterlerinin ascii tablosundaki karþýlýklarýný toplar ve int olarak döndürür
int SumChar(string word) {
	int sum = 0;
	for (int j = 0; j < word.size(); j++) {
		string s = word.substr(j, 1); // kelimenin ilk karkaterini alýyoruz
		const char* c = s.c_str(); // Bu karkateri char dönüþtürüyoruz
		int b = (int)*c; // Sonrda char ý int e dönüþtürüyoruz
		sum += b; // Ve topluyoruz
	}
	return sum;
}
void BST::Enter(tree* agac) {
	string word;
	cout << "Enter word: ";
	cin >> word;
	word = Smaller(word); // Kullanýcý kelimeyi büyük harflerle girerse bunlarý küçük harfe dönüþtürür
	word = word.substr(0, 3);
	Search(agac, word, SumChar(word)); // Daha sonra bu girilen kelime aðacta aratýlýr
}
void BST::ReadFile() {

	ifstream ReadFile("words.txt");
	std::string line = "";

	if (ReadFile.is_open()) {
		while (getline(ReadFile, line)) {

			string firstThree = line.substr(0,3); 
			int ktplm = SumChar(firstThree); // ilk üç harfin karakter toplamýný getirir

			insert(first, ktplm, firstThree); // Ve aðaca düðümü eklemek üzere gönderiri
		}

		ReadFile.close();
	}
	Enter(first);
}
string BST::Smaller(string word) {
	string newLine = "";
	for (int i = 0; i < word.size(); i++) {
		string s = word.substr(i, 1); // ilke karaketri alýr
		const char* c = s.c_str(); // int e dönüþütürmek üzere char a dönüþtürülür
		int b = (int)*c; // daha sonra int e dünüþtürülür
		if (b >= 65 && b <= 90) { // Ascii tablosuna göre büyük harmi kontorl edilir.65-90 arasý büyük harftir.
			b = b + 32; // bunu o harf e denk gelen küçük harf yapmak üzere 32 ekle.Çünkü ascii de aradaki fark 32 dir. 
		}
		char x = (char)b; // sonra tekrar char yapýlýr
		s = x; // ve stirnge dönüþtürülür
		newLine += s;// Yeni satýra eklenir
	}
	return newLine;
}

void BST::Search(tree* tr,std::string vri,int kt) {
	
	// Gelen karakter toplamýna göre aðacýn saðýna ve soluna gidere preorder dolaþýr.  
	// En son düðüme gelince ve ilgili düðüm bulunursa o düðümün baðlý listesindeki kelimeleri yazar
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
			l1.Write(tr->node); // blistenin içeriði yazýlýr
			cout << "?" << endl;
		} 
	}
			
}

// Aðacý yok etmek üzere postorder dolaþýr ve delete metodunu çaðýrarak aðacý siler.
void BST::Postorder(tree* tr) {
	if (tr == NULL)
		return;
	Postorder(tr->sol);
	Postorder(tr->sag);
	Delete(tr);
}
void BST::Delete(tree*& t) {
	l1.DeleteList(t->node);// Önce düðümün baðlý listesni silmek üzere gönderilir.

	//Daha sonra düðümün kendisi silinir

	//eðer düðümün ait olduðu ana düðüm null ise bu kök(yani ilk düðüm)dür.Oyüzden bunu kontrol ediyoruz
	if (t->parent != NULL) {
				
		if (t->parent->sol == t) // Gelen düðüm,ait olduðu ana düðümünün saðýndamý yoksa solundami kontrol ediyoruz
			t->parent->sol = NULL;
		if (t->parent->sag == t) // Ve neresindeyse ana düðümün orasýný Null yapýyoruz.
			t->parent->sag = NULL;
	}
	
	delete t; // En sonunda düðümü siliyoruz
}
BST::~BST()
{
	Postorder(first); // Program bitiminde otomatik olarak yýkýcý metod çaðrýlýr ve aðaç silinir. 
}
