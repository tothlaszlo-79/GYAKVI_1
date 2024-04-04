#include <iostream> 
#include <fstream> 
#include <iomanip> 
using namespace std;

int main(int ArgDb, char* ArgTmb[])
{
	const int maxhossz = 80;
	char nev[maxhossz] = "";
	if (ArgDb == 2)
	{
		strcpy_s(nev, ArgTmb[1]);
	}
	else
	{
		cout << "Az allomanyneve: ";
		cin >> nev;
	}
	ifstream stream; // file-kezel� objektum l�trehoz�sa 
	stream.open(nev); // file-megnyit�s karakteres olvas�sra 
	if (stream) //vagyif(stream.good()) vagyif(!stream.fail()) ha sikeresa file-megnyit�s
	{
		int db = 0; // darabsz�m meghat�roz�sa 
		int szam;
		while (!stream.eof()) // file-v�gjelig 
		{
			stream >> szam;
			db++;
		}
		stream.clear(); // hiba�llapot t�rl�se 
		stream.seekg(0, ios::beg); // �llom�ny elej�re pozicion�l�s
		int* p = new int[db]; // dinamikus t�mbnek t�rfoglal�s  

		if (p) // f(p!=NULL) ha sikeres a t�rfoglal�s 
		{ // dinamikus t�mbbe beolvas�s 
			register int i;
			for (i = 0; i < db; i++) stream >> p[i];
			stream.close(); // �llom�ny bez�r�sa 
			cout << endl << "A beolvasott szamok:" << endl;
			double s = 0.0;
			for (i = 0; i < db; i++)
			{
				cout << setw(8) << p[i];
				s += p[i];
			}
			cout << endl << "Szamtaniatlaguk: " << s / db << endl;
			system("pause");
			delete[] p; // dinamikus t�mb t�rfelszabad�t�sa 
			return 0;
		}
		else // ha sikertelen a t�rfoglal�s 
		{
			cerr << "\nKeves a dinamikus memoria!\a\n\n";
			stream.close(); // �llom�ny bez�r�sa 
			system("pause");
			return 2;
		}
	}
	else // ha sikertelen a file-megnyit�s 
	{
		cerr << "\nA(z) " << nev << " allomany nem letezik!\a\n\n";
		system("pause"); return 1;
	}
}
