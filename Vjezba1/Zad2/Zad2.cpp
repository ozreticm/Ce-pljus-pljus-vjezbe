// Zad2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include <algorithm>

struct student {
	std::string ID, ime, spol;
	int kviz_1, kviz_2, ocjena_1, ocjena_2;
};

void izbornik()
{
	std::cout <<"IZBORNIK\n"<<"Upisite broj akcije koju zelite izvrsiti\n";
	std::cout << "1) Dodaj novi zapis \n2) Ukloni zapis \n3) Azuriraj zapis \n4) Prikazi sve zapise \n";
	std::cout << "5) Izracunaj prosjek bodovaza studenta \n6) Prikazi studenta s najvecim brojem bodova \n";
	std::cout << "7) Prikazi studenta s najmanjim brojem bodova \n8) Pronadi studenta po ID-u \n";
	std::cout << "9) Sortiraj zapise po broju bodova (total) \n10) Izlaz \n";
	return;
}


student novi_zapis(student razred, std::string id)
{
	razred.ID = id;
	std::cout << "Unesi ime i spol studenta:\n";
	std::cin >> razred.ime>>razred.spol;
	std::cout << "Unesi rezultate kviza 1 i kviza 2:\n";
	std::cin >> razred.kviz_1 >> razred.kviz_2;
	std::cout << "Unesi ocjene na sredini i kraju semestra\n";
	std::cin >> razred.ocjena_1 >> razred.ocjena_2;
	return razred;
}

student brisi_zapis(student a)
{
	a.ID = "";
	a.ime = "";
	a.spol = "";
	a.ocjena_1 = 0;
	a.ocjena_2 = 0;
	a.kviz_1 = 0;
	a.kviz_2 = 0;
	return a;
}

student azuriraj(student a)
{
	std::cout << "Trenutno ime je: " << a.ime << "\nUnesite azurirano ime:\n";
	std::cin >> a.ime;
	std::cout << "Trenutni broj bodova Kviza 1 je: " << a.kviz_1 << "\nUnesite azurirane bodove:\n";
	std::cin >> a.kviz_1;
	std::cout << "Trenutni broj bodova Kviza 2 je: " << a.kviz_2 << "\nUnesite azurirane bodove:\n";
	std::cin >> a.kviz_2;
	std::cout << "Trenutni broj bodova Ocjene 1 je: " << a.ocjena_1 << "\nUnesite azurirane bodove:\n";
	std::cin >> a.ocjena_1;
	std::cout << "Trenutni broj bodova Ocjene 2 je: " << a.ocjena_2 << "\nUnesite azurirane bodove:\n";
	std::cin >> a.ocjena_2;
	return a;
}

void prikazi_sve(student razred[], int br)
{
	for (int i = 0; i < br; i++)
	{
		std::cout << razred[i].ime << " " << razred[i].spol << " " << razred[i].ID << " " << razred[i].kviz_1 << " " << razred[i].kviz_2 << " " << razred[i].ocjena_1 << " " << razred[i].ocjena_2 << "\n";
	}
}

int pronadi(student razred[], int br, std::string ID)
{
	int naden = 0,pozicija;
	for (int i = 0; i < br; i++)
	{
		if (!razred[i].ID.compare(ID))
		{
			std::cout << razred[i].ime << " " << razred[i].spol << " " << razred[i].ID << " " << razred[i].kviz_1 << " "<<razred[i].kviz_2<<" " << razred[i].ocjena_1 << " " << razred[i].ocjena_2<<"\n";
			naden = 1;
			pozicija = i;
			break;
		}
	}
	if (naden == 0)
	{
		std::cout << "Nije pronaden student s navedenim ID-em!\n";
		return br;
	}
	else return pozicija;
}

void sort(student razred[],int br)
{
	int tempMin,total;
	student tempStudent;
	for (int i = 0; i < br - 1; i++)
	{
		total = razred[i].kviz_1 + razred[i].kviz_2 + razred[i].ocjena_1 + razred[i].ocjena_2;
		tempMin = i;
		for (int j = i; j < br; j++)
		{
			if (razred[j].kviz_1 + razred[j].kviz_2 + razred[j].ocjena_1 + razred[j].ocjena_2 < total)
				tempMin = j;
		}
		tempStudent = razred[i];
		razred[i] = razred[tempMin];
		razred[tempMin] = tempStudent;
	}
}

int main()
{
	student razred[20] = {"","","",0,0,0,0};
	izbornik();
	int unos,br=0,temp;
	bool eq = false;
	std::cin >> unos;
	while (unos != 10)
	{
		switch (unos)
		{
			case 1:
			{
				if (br < 20 && br!=0)
				{
					std::cout << "Unesite ID novog studenta\n";
					std::string id_temp;
					std::cin >> id_temp;
					eq = false;
					for (int i = 0; i < br; i++)
					{
						
						eq = !razred[i].ID.compare(id_temp);
						if (eq == true)
						{
							std::cout << "ID nije jedinstven!\n\n";
							break;
						}
					}
					if(eq==0) razred[br++] = novi_zapis(razred[br], id_temp);
					break;
					
				}
				else if (br == 0) {
					std::cout << "Unesite ID novog studenta\n";
					std::string id_temp;
					std::cin >> id_temp;
					razred[br++] = novi_zapis(razred[br], id_temp);
					break;
				}
				else
				{
					std::cout << "Razred je pun!\n";
				}
				break;
			}
			case 2:
			{
				if(br==1 || br==0)
				{
					std::cout << "Ne mozete izbrisati zapis jer ih je premalo!\n";
					break;
				}
				else
				{
					razred[br--]=brisi_zapis(razred[br]);
				}
				break;
			}
			case 3:
			{
				std::cout << "Upisite ID studenta kojem zelite azurirati podatke!\n";
				std::string ID;
				std::cin >> ID;
				temp = pronadi(razred, br, ID);
				razred[temp]=azuriraj(razred[temp]);
				break;
			}
			case 4:
			{
				prikazi_sve(razred, br);
				break;
			}
			case 5:
			{
				std::cout << "Upisite ID studenta kojem zelite izracunati prosjek bodova!\n";
				std::string ID;
				std::cin >> ID;
				temp=pronadi(razred, br, ID);
				if (temp != br)
					std::cout << "Prosjek bodova je: " << (razred[temp].kviz_1+razred[temp].kviz_2+razred[temp].ocjena_1+razred[temp].ocjena_2)/4<<"\n";
				break;
			}
			case 6:
			{
				sort(razred, br);
				std::cout << razred[br-1].ime << " " << razred[br-1].spol << " " << razred[br - 1].ID << " " << razred[br - 1].kviz_1 << " " << razred[br - 1].kviz_2 << " " << razred[br - 1].ocjena_1 << " " << razred[br - 1].ocjena_2 << "\n";
				break;
			}
			case 7:
			{
				sort(razred, br);
				std::cout << razred[0].ime << " " << razred[0].spol << " " << razred[0].ID << " " << razred[0].kviz_1 << " " << razred[0].kviz_2 << " " << razred[0].ocjena_1 << " " << razred[0].ocjena_2 << "\n";
				break;
			}
			case 8:
			{
				std::cout << "Upisite ID studenta kojeg zelite pronaci!\n";
				std::string ID;
				std::cin >> ID;
				pronadi(razred, br, ID);
				break;
			}
			case 9:
			{
				sort(razred,br);
				std::cout << "Studenti su sortirani po broju bodova!\n\n";
				break;
			}
			case 10:
			{
				break;
			}
		default:
			std::cout << "Neispravan unos!\n";
			break;
		}
		izbornik();
		std::cin >> unos;
	}
    return 0;
}

