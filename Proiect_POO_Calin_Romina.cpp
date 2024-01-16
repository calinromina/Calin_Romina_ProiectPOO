#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Cititor
{
private:
	const int id;
	static string tipBiblioteca;
	char* numeCititor;
	int varsta;
	string preferinte;


	
public:
	Cititor() : id(0)  ///constructor fara param
	{
		this->numeCititor = new char[strlen("anonim") + 1];
		strcpy(this->numeCititor, "anonim");
		this->varsta = 0;
		this->preferinte = "Necunoscut";
	}

	Cititor(char* numeCititor, int varsta) : id(1)  //constructor cu 2 parametrii
	{
		this->numeCititor = new char[strlen(numeCititor) + 1];
		strcpy(this->numeCititor, numeCititor);
		this->varsta = varsta;
		this->preferinte = "Necunoscut";
	}

	Cititor(int id, char* numeCititor, int varsta, string preferinte) : id(id) ///constructor cu toti parametrii
	{
		this->numeCititor = new char[strlen(numeCititor) + 1];
		strcpy(this->numeCititor, numeCititor);
		this->varsta = varsta;
		this->preferinte = preferinte;
	}
	Cititor(int varsta) : id(11)  //constructor cu 1 parametrii
	{
		this->numeCititor = new char[strlen("anonim") + 1];
		strcpy(this->numeCititor, "anonim");
		this->varsta = varsta;
		this->preferinte = "Necunoscut";
	}

	~Cititor()
	{
		if (this->numeCititor != NULL)
		{
			delete[]numeCititor;
		}
	}

	Cititor(const Cititor& c) :id(c.id)
	{
		this->numeCititor = new char[strlen(c.numeCititor) + 1];
		strcpy(this->numeCititor, c.numeCititor);
		this->varsta = c.varsta;
		this->preferinte = c.preferinte;

	}

	Cititor& operator=(const Cititor& c)
	{
		if (this != &c)
		{

			//if (this->preferinte != NULL)
			//{
			//	delete[]this->preferinte;
			//}
			this->numeCititor = new char[strlen(c.numeCititor) + 1];
			strcpy(this->numeCititor, c.numeCititor);
			this->varsta = c.varsta;
			this->preferinte = c.preferinte;
		}
		return *this;
	}

	friend ostream& operator <<(ostream& out, const Cititor& c)
	{
		out << "Nume Cititor: " << c.numeCititor << endl;
		out << "Varsta Cititor: " << c.varsta << endl;
		out << "Preferintele cititorului: " << c.preferinte << endl;
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Cititor& c)
	{
		cout << "Nume cititor: ";
		delete[]c.numeCititor;
		char buffer[30];
		cin >> buffer;
		c.numeCititor = new char[strlen(buffer) + 1];
		strcpy(c.numeCititor, buffer);
		cout << "Varsta Cititor: ";
		in >> c.varsta;
		cout << "Preferintele cititorului: ";
		in >> c.preferinte;
		return in;
	}

	void setNumeCititor(char* numeCititor)
	{
		if (this->numeCititor != NULL)
		{
			delete[]this->numeCititor;
		}
		this->numeCititor = numeCititor;
	}
	string getNumeCititor()
	{
		return this->numeCititor;
	}

	void setVarsta(int varsta)
	{
		this->varsta = varsta;
	}
	int getVarsta()
	{
		return this->varsta;

	}

	void setPreferinte(string preferinte)
	{
		this->preferinte = preferinte;
	}
	string getPreferinte()
	{
		return this->preferinte;

	}


	///OPERATORI

	//1. OPERATORUL == (INTRE 2 OBIECTE)

	bool operator == (Cititor c)
	{
		return (this->preferinte == c.preferinte);
	}

	//2. OPERATORUL + OBJ +OBJ

	Cititor operator + (Cititor c)
	{
		Cititor aux = *this;
		aux.varsta = this->varsta + c.varsta;
		return aux;

	}

	//3.OPERATOR ++ POST-INCREEMENTARE

	Cititor operator ++(int)
	{
		Cititor copie = *this;
		this->varsta++;
		return copie;
	}


};
string Cititor::tipBiblioteca = "Publica";

class Carte
{
private:
	const int id;
	static int secolCarte;
	string titlu;
	string autor;
	float medieCerereCititor;
	int numarCititori;
	int* recenzii;


public:
	Carte() : id(1)
	{
		this->titlu = "Necunoscut";
		this->autor = "Necunoscut";
		this->medieCerereCititor = 0;
		this->numarCititori = 0;
		this->recenzii = NULL;

	}

	Carte(string titlu) :id(2)
	{
		this->titlu = titlu;
		this->autor = "Necunoscut";
		this->medieCerereCititor = 0;
		this->numarCititori = 0;
		this->recenzii = NULL;
	}


	Carte(string titlu, string autor, float medieCerereCititor, int numarCititori, int* recenzii) :id(101)
	{
		this->titlu = titlu;
		this->autor = autor;
		this->medieCerereCititor = medieCerereCititor;
		this->numarCititori = numarCititori;
		this->recenzii = new int[this->numarCititori];
		for (int i = 0; i < this->numarCititori; i++)
		{
			this->recenzii[i] = recenzii[i];
		}
	}

	Carte(int numarCititori, int* recenzii) :id(id)
	{
		this->titlu = "anonim";
		this->autor = "anonim";
		this->medieCerereCititor = 0;
		this->numarCititori = numarCititori;
		this->recenzii = new int[this->numarCititori];
		for (int i = 0; i < this->numarCititori; i++)
		{
			this->recenzii[i] = recenzii[i];
		}
	}
	~Carte()
	{
		if (this->recenzii != NULL)
		{
			delete[] this->recenzii;
		}
	}

	Carte(const Carte& carte) :id(carte.id)
	{
		this->titlu = carte.titlu;
		this->autor = carte.autor;
		this->medieCerereCititor = carte.medieCerereCititor;
		this->numarCititori = carte.numarCititori;
		this->recenzii = new int[this->numarCititori];
		for (int i = 0; i < this->numarCititori; i++)
		{
			this->recenzii[i] = carte.recenzii[i];
		}
	}

	Carte& operator=(const Carte& carte)
	{
		if (this != &carte)
		{
			if (this->recenzii != NULL)
			{
				delete[] this->recenzii;
			}
			this->titlu = carte.titlu;
			this->autor = carte.autor;
			this->medieCerereCititor = carte.medieCerereCititor;
			this->numarCititori = carte.numarCititori;
			this->recenzii = new int[this->numarCititori];
			for (int i = 0; i < this->numarCititori; i++)
			{
				this->recenzii[i] = carte.recenzii[i];
			}
		}
		return *this;
	}

	friend ostream& operator << (ostream& out, const Carte& carte)
	{
		out << "ID carte:" << carte.id << endl;
		out << "Secol carte:" << carte.secolCarte << endl;
		out << "Titlul cartii: " << carte.titlu << endl;
		out << "Autorul cartii: " << carte.autor << endl;
		out << "media cererii de carti dorite de cititori: " << carte.medieCerereCititor << endl;
		out << "Numarul cititorilor: " << carte.numarCititori << endl;
		out << "Rating carte: ";
		for (int i = 0; i < carte.numarCititori; i++)
		{
			out << carte.recenzii[i] << " ";
		}
		return out;
	}

	friend istream& operator>>(istream& in, Carte& carte)
	{
		cout << "Secolul cartii:";
		in >> carte.secolCarte;
		cout << "Titlul cartii: ";
		in >> carte.titlu;
		getline(in, carte.titlu);
		cout << "Autorul cartii: ";
		in >> carte.autor;
		getline(in, carte.autor);
		cout << "Media cererii de carti dorite de cititori: ";
		in >> carte.medieCerereCititor;
		cout << "Numarul cititorilor: ";
		in >> carte.numarCititori;
		cout << "Rating carte: ";
		if (carte.recenzii != NULL) {
			delete[]carte.recenzii;
		}
		carte.recenzii = new int[carte.numarCititori];
		for (int i = 0; i < carte.numarCititori; i++)
		{
			in >> carte.recenzii[i];
		}
		return in;
	}

	void setTitlu(string titlu)
	{
		this->titlu = titlu;
	}
	string getTitlu()
	{
		return this->titlu;
	}

	void setAutor(string autor)
	{
		this->autor = autor;
	}
	string getAutor()
	{
		return this->autor;
	}

	void setMedie(float medieCerereCititori)
	{
		this->medieCerereCititor = medieCerereCititor;
	}
	float getMedie()
	{
		return this->medieCerereCititor;
	}

	void setNumarCititori(int numarCititori)
	{
		this->numarCititori = numarCititori;
	}
	int getNumarCititori()
	{
		return this->numarCititori;
	}

	void setRecenzii(int* recenzii)
	{
		if (this->recenzii != NULL)
		{
			delete[]this->recenzii;
		}
		this->recenzii = new int[this->numarCititori];
		for (int i = 0; i < this->numarCititori; i++)
		{
			this->recenzii[i] = recenzii[i];
		}
	}
	int* getRecenzii()
	{
		return this->recenzii;
	}

	//OPERATORUL += INTRE OBJ OBJ
	Carte& operator += (Carte cr)
	{
		Carte copie = *this;
		delete[]recenzii;
		this->numarCititori = copie.numarCititori + cr.numarCititori;
		this->recenzii = new int[this->numarCititori];
		for (int i = 0; i < this->numarCititori; i++)
		{
			this->recenzii[i] = copie.recenzii[i];
			for (int i = copie.numarCititori; i < this->numarCititori; i++)
			{
				this->recenzii[i] = cr.recenzii[i - copie.numarCititori];

			}
		}
		return *this;

	}

	//2.OPERATORUL --
	Carte operator --(int)
	{
		Carte copie = *this;
		this->numarCititori--;
		return copie;
	}

	//3.OPERATOR+
	Carte operator+(float valoare)
	{
		Carte copie = *this;
		copie.medieCerereCititor += valoare;
		return copie;
	}


};
int Carte::secolCarte = 21;


class Abonament
{
private:
	const int id;
	static int TVA;
	string numeClient;
	int durataAbonament;
	bool valabilitate;
	float* cost;
public:
	Abonament() :id(0)
	{
		this->numeClient = "Necunoscut";
		this->durataAbonament = 0;
		this->valabilitate = 0;
		this->cost = NULL;

	}

	Abonament(int id, string numeClient, int durataAbonament, bool valabilitate, float* cost) :id(2)
	{
		this->numeClient = numeClient;
		this->durataAbonament = durataAbonament;
		this->valabilitate = valabilitate;
		this->cost = new float[this->durataAbonament];
		for (int i = 0; i < this->durataAbonament; i++)
		{
			this->cost[i] = cost[i];
		}

	}

	~Abonament()
	{
		if (this->cost != NULL)
		{
			delete[]this->cost;
		}
	}

	Abonament(const Abonament& a) :id(a.id)
	{

		this->numeClient = a.numeClient;
		this->durataAbonament = a.durataAbonament;
		this->cost = new float[this->durataAbonament];
		for (int i = 0; i < this->durataAbonament; i++)
		{
			this->cost[i] = a.cost[i];
		}
		this->valabilitate = a.valabilitate;
	}

	Abonament& operator=(const Abonament& a)
	{
		if (this != &a)
		{

			if (this->cost != NULL)
			{
				delete[]this->cost;
			}
			this->numeClient = a.numeClient;
			this->durataAbonament = a.durataAbonament;
			this->cost = new float[this->durataAbonament];
			for (int i = 0; i < this->durataAbonament; i++)
			{
				this->cost[i] = a.cost[i];
			}
			this->valabilitate = a.valabilitate;
		}
		return *this;
	}

	friend ostream& operator <<(ostream& out, const Abonament& a)
	{
		out << "ID abonament: " << a.id << endl;
		out << "TVA abonament: " << a.TVA << endl;
		out << "Numele clientului: " << a.numeClient << endl;
		out << "Durata abonamentului: " << a.durataAbonament << endl;
		out << "Valabilitatea abonamentului: " << a.valabilitate << endl;
		out << "Costul abonamentului: ";
		for (int i = 0; i < a.durataAbonament; i++)
		{
			out << a.cost[i] << " ";
		}

		return out;

	}

	friend istream& operator>>(istream& in, Abonament& a)
	{
		cout << "TVA abonament: ";
		in >> a.TVA;
		cout << "Numele clientului: ";
		in >> a.numeClient;
		getline(in, a.numeClient);
		cout << "Durata abonamentului: ";
		in >> a.durataAbonament;
		cout << "Valabilitatea abonamentului: ";
		in >> a.valabilitate;
		cout << "Costul abonamentului: ";
		delete[]a.cost;
		a.cost = new float[a.durataAbonament];
		for (int i = 0; i < a.durataAbonament; i++)
		{
			in >> a.cost[i];

		}
		return in;
	}

	void setNumeClient(string numeClient)
	{
		this->numeClient = numeClient;
	}
	string getNumeClient()
	{
		return this->numeClient;
	}

	void setDurataAbonamentului(int durataAbonament)
	{
		this->durataAbonament = durataAbonament;

	}
	int getDurataAbonament()
	{
		return this->durataAbonament;
	}

	void setCost(float* cost)
	{
		if (this->cost != NULL)
		{
			delete[]this->cost;
		}
		this->cost = new float[this->durataAbonament];
		for (int i = 0; i < this->durataAbonament; i++)
		{
			this->cost[i] = cost[i];
		}
	}

	float* getCost()
	{
		return this->cost;
	}

	void setValabilitate(bool valabilitate)
	{
		this->valabilitate = valabilitate;

	}
	bool getValabilitate()
	{
		return this->valabilitate;
	}

	bool operator<(const Abonament& a) {
		return this->durataAbonament < a.durataAbonament;
	}

	float& operator[] (int poz)
	{
		if (poz >= 0 && poz < this->durataAbonament)
			return this->cost[poz];
	}

	bool operator ==(Abonament a)
	{
		return this->durataAbonament == a.durataAbonament;
	}
};
int Abonament::TVA = 10;

int main()
{
	cout << "Constructorul fara parametrii - clasa Cititor:" << endl;
	Cititor c1;
	cout << "Cititor 1:\n" << c1 << endl;


	cout << "Constructorul cu toti parametrii - clasa Cititor:" << endl;
	char* nume = new char[20]{ "Pavel Andrei" };
	Cititor c2(nume, 46);
	cout << "Cititor 2:\n" << c2 << endl << endl;

	char* nume1 = new char[20]{ "Alexandra Mihai" };
	Cititor c3(3, nume1, 18, "Roman de dragoste");
	cout << "Cititor 3:\n" << c3 << endl << endl;

	cout << "Getteri si setteri - clasa Cititor:" << endl;
	cout << c3.getNumeCititor() << endl;
	c3.setPreferinte("actiune");
	cout << endl;
	cout << "Noua preferinta este: " << c3.getPreferinte();
	cout << endl << endl;

	cout << "Constructorul fara parametrii - clasa Carte:" << endl;
	Carte carte1;
	cout << "Carte 1:\n" << carte1 << endl << endl;

	cout << "Constructorul cu toti parametrii - clasa Carte:" << endl;
	int* recenziiCarte;
	recenziiCarte = new int[7]{ 4, 3, 5, 9, 10, 6, 9 };
	Carte carte2("Insomnii", "Irina Binder", 4.8f, 7, recenziiCarte);
	cout << "Carte2:\n" << carte2 << endl << endl;
	// cin >> carte2; 

		cout << "Constructorul fara parametrii - clasa Abonament:" << endl;
	Abonament a1;
	cout << "Abonament 1:\n" << a1 << endl << endl;
	cout << "Testare operator de citire: " << endl;
	// cin >> a1; 

		cout << "Constructorul cu toti parametrii - clasa Abonament:" << endl;
	float* costAbonament;
	costAbonament = new float[3]{ 22.5f, 30.0f, 45.7f };
	Abonament a3(2, "Radu Andreea", 3, true, costAbonament);
	cout << "Abonament 3:\n" << a3 << endl << endl;


	//TESTARE OPERATOR == se creeaza alte 2 obiecte 
	cout << "Operatorul ==: " << endl;
	char* nume4 = new char[20]{ "Vasile Marian" };
	char* nume5 = new char[20]{ "Petre Stefania" };
	Cititor c4(4, nume4, 27, "Fictiune");
	Cititor c5(5, nume5, 60, "Fictiune");
	if (c4 == c5)
	{
		cout << "Cele doua persoane coincid cu preferintele" << endl;
	}
	else {
		cout << "Cele doua persoane nu au aceleasi preferinte" << endl << endl;
	}
	cout << endl;

	//OPERATORUL + obj obj intre constructori cu un singur parametru
	cout << "Operatorul +: " << endl;
	Cititor c7(39);
	Cititor c8(33);
	cout << "Valoarea varstelor insumate:\n";
	Cititor c9 = c7 + c8;
	cout << c9;
	int* recenzii2;
	int* recenzii3;
	recenzii2 = new int[10]{ 4, 4, 3, 10, 10, 6, 1,8,9,3 };
	recenzii3 = new int[10]{ 4, 5, 7, 9, 10, 1, 3, 7, 5, 9 };

	//OPERATORUL +=
	cout << "Operatorul +=: " << endl;
	Carte cc2(4, recenzii2);
	Carte cc3(2, recenzii3);
	cc3 += cc2;
	cout << cc3 << endl << endl;
	Carte cc5("Never Never", "Colleen Hoover", 5.5f, 3, recenzii2);
	Carte cc6("Turnul Zorilor", "Sarah J. Maas", 6.7f, 6, recenzii3);
	cc5 += cc6;
	cout << cc5;
	cout << endl << endl;

	//operatorul ++ pot-incrementare
	cout << "Operator ++: (post-incrementare)" << endl;
	Cititor c10 = c4++;
	cout << c10 << endl;
	cout << c4 << endl; //c4 este incrementat
	cout << endl << endl;

	//operatorul --
	cout << "Operator --: (post-decrementare)" << endl;
	Carte carte3 = carte2--;
	cout << carte3 << endl;
	cout << endl;
	cout << carte2 << endl << endl; //c2 este decrementat

	//operatorul +
	cout << "Operator +(intre obiect si valoare): " << endl;
	Carte carte4 = carte2 + 25.7;
	cout << carte2 << endl;
	cout << endl;
	cout << carte4 << endl << endl;

	//operatorul <
	cout << "Operator < : " << endl;
	bool b;
	b = a3 < a1;
	cout << b << endl;

	//operatorul index
	cout << "Operator index: " << endl;
	int index = a3[1];
	cout << index << endl;
}
