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
	ifstream stream; // file-kezelõ objektum létrehozása 
	stream.open(nev); // file-megnyitás karakteres olvasásra 
	if (stream) //vagyif(stream.good()) vagyif(!stream.fail()) ha sikeresa file-megnyitás
	{
		int db = 0; // darabszám meghatározása 
		int szam;
		while (!stream.eof()) // file-végjelig 
		{
			stream >> szam;
			db++;
		}
		stream.clear(); // hibaállapot törlése 
		stream.seekg(0, ios::beg); // állomány elejére pozicionálás
		int* p = new int[db]; // dinamikus tömbnek tárfoglalás  

		if (p) // f(p!=NULL) ha sikeres a tárfoglalás 
		{ // dinamikus tömbbe beolvasás 
			register int i;
			for (i = 0; i < db; i++) stream >> p[i];
			stream.close(); // állomány bezárása 
			cout << endl << "A beolvasott szamok:" << endl;
			double s = 0.0;
			for (i = 0; i < db; i++)
			{
				cout << setw(8) << p[i];
				s += p[i];
			}
			cout << endl << "Szamtaniatlaguk: " << s / db << endl;
			system("pause");
			delete[] p; // dinamikus tömb tárfelszabadítása 
			return 0;
		}
		else // ha sikertelen a tárfoglalás 
		{
			cerr << "\nKeves a dinamikus memoria!\a\n\n";
			stream.close(); // állomány bezárása 
			system("pause");
			return 2;
		}
	}
	else // ha sikertelen a file-megnyitás 
	{
		cerr << "\nA(z) " << nev << " allomany nem letezik!\a\n\n";
		system("pause"); return 1;
	}
}
