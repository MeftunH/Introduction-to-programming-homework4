/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: 4
**				ÖÐRENCÝ ADI...............: ODEV NUMARASI
**				ÖÐRENCÝ NUMARASI.: G-181210554
**				DERS GRUBU…………: B
****************************************************************************/

#include<iostream>
#include<string>

using namespace std;
string mesaj;
string sifrenintablodakiyeri;
void mesajvesifre()
{

	string msj;
	cout << " kelime girin :";
	getline(cin, msj);
	cin.ignore();


	//MESAJI BUYUK HARFE CEVÝRME
	for (int i = 0; i < msj.length(); i++)
	{

		msj[i] = toupper(msj[i]);
	}
	string sifre;
	cout << "sifre girin: ";
	getline(cin, sifre);
	cin.ignore();

	//SÝFREYÝ BUYUK HARFE CEVÝRME
	for (int i = 0; i < sifre.length(); i++)
	{

		sifre[i] == toupper(sifre[i]);
	}
	//sifreyi mesaja ekleme (bsmbsmbsmbsmbsmbsm) gibi
	string sifreyeri = "";
	for (int i = 0, j = 0; i < msj.length(); i++)
	{
		if (msj[i] == 32)
		{

			sifreyeri += 32;
		}
		else {

			if (j < sifre.length())
			{
				sifreyeri += sifre[j];
				j++;
			}

			else {

				j = 0;
				sifreyeri += sifre[j];
				j++;
			}
		}//if else
	}//for
	cout << msj << endl << sifreyeri << endl;
	mesaj = msj;
	sifrenintablodakiyeri = sifreyeri;




}

int tabloArr[26][26];
void VigenereTabloyarat()
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			int temp;
			if ((i + 65) + j > 90)
			{
				temp = ((i + 65) + j) - 26;
				//HARFLERÝN ASCÝÝDEKÝ YERÝNÝ TABLOYA AKTARMA
				tabloArr[i][j] = temp;
			}
			else
			{
				temp = (i + 65) + j;
				//HARFLERÝN ASCÝÝDEKÝ YERÝNÝ TABLOYA AKTARMA
				tabloArr[i][j] = temp;

			}
		}//for j loop
	}//for i loop
	// TABLOYU TEST ETME 
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			cout << (char)tabloArr[i][j] << " ";
		}
		cout << endl;
	}
}


void sifreleme(string mesaj, string sifrenintablodakiyeri)
{
	VigenereTabloyarat();
	string sifrelememetin = "";
	for (int i = 0; i < mesaj.length(); i++)
	{
		if (mesaj[i] == 32 && sifrenintablodakiyeri[i] == 32)
		{
			sifrelememetin += " ";
		}
		else {
			int x = (int)mesaj[i] - 65;
			int y = (int)sifrenintablodakiyeri[i] - 65;
			sifrelememetin += (char)tabloArr[x][y];
		}

	}

	cout << "sifrelenmis metin :" << sifrelememetin;

}

int isayac(int sifre, int msj)
{
	int sayac = 0;
	string sonuc = "";
	for (int i = 0; i < 26; i++)
	{
		if (sifre + i > 90)
		{
			sonuc += (char)(sifre + (i - 26));
		}
		else {

			sonuc += (char)(sifre + 1);
		}
	}
	for (int i = 0; i < sonuc.length(); i++)
	{
		if (sonuc[i] == msj)
		{

			break;
		}
		else
		{
			sayac++;
		}


	}
	return 0;
}
void sifrecoz(string mesaj, string sifreyeri)

{
	string sifrelenmemismetin = "";
	for (int i = 0; i < mesaj.length(); i++)
	{
		if (mesaj[i] == 32 && sifreyeri[i] == 32)
		{
			sifrelenmemismetin += " ";

		}
		else {
			int temp = isayac((int)sifrenintablodakiyeri[i], (int)mesaj[i]);
			sifrelenmemismetin += (char)(65 + temp);
		}
	}

	cout << "sifrelenmemis metin : " << sifrelenmemismetin;

}

int main()
{
	cout << "mesaj ve sifre (sadece alfabetik)" << endl;
	int secim;
	cout << "1. sifrele/n 2.sifrecoz/n Sec(1,2)";
	cin >> secim;
	cin.ignore();
	if (secim == 1)
	{

		cout << "sifrele" << endl;
		mesajvesifre();
		sifreleme(mesaj, sifrenintablodakiyeri);
	}
	else if (secim = 2)
	{
		mesajvesifre();
		sifrecoz(mesaj, sifrenintablodakiyeri);
		cout << "sifrecoz" << endl;
	}
	else { cout << "Yanlis secim" << endl; }
	system("pause");
	return 0;
}