
				/****************************************************************************
				**				    	SAKARYA �N�VERS�TES�                             **
				**			    B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�                **
				**				   B�LG�SAYAR M�HEND�SL��� B�L�M�                        **
				**			         PROGRAMLAMAYA G�R��� DERS�                          **
				**                                                                       **
				**				�DEV NUMARASI�...:P_G PROJE �DEV�                        **
				**				��RENC� ADI...............:AZ�Z ��M�EK                   **
				**				��RENC� NUMARASI.:b201210394                             **
				**				DERS GRUBU����: 1A GRUBU                                 **
				****************************************************************************/





#include <iostream> // cout,cin vs. i�in
#include <conio.h> //getch(); fonksiyonu i�in
#include <fstream> // dosyalama i�lemleri i�in
#include <string> // string t�r� i�in
#include <clocale> // T�rk�e karakter i�in
#include <iomanip> //setw() i�in eklenen k�t�phane
#include <stdio.h>//i�inde kullan�lacak fonksiyonlar tan�ml�d�r 
#include <chrono> // kodun daha kolay,t�r kullan�m� ve bak�m g�venli�i i�in Kullan�c� tan�ml� sabit de�erleri tan�mlar.
#include <ctime>//tarih ve saat t�r�nde degi�kenler saklan�r 

using namespace std;
int main()
{
	setlocale(LC_ALL, "turkish"); //T�rk�e karakter ekliyoruz

	auto start = chrono::system_clock::now();
	auto simdibasla = chrono::system_clock::to_time_t(start);
	char girisSaat[30];
	ctime_s(girisSaat, sizeof(girisSaat), &simdibasla);
	cout << "\n Giri� Saati:" << girisSaat << "\n";



	int secim;


	string Adi; //De�i�kenleri tan�mlad�k
	string Soyadi;
	long long  TcNo;
	string Telefon;
	string UyeNumarasi;
	string DogumTarihi;
	string Meslegi;
	string AlabilecegiKitapSayisi;

	long long  TC;

	string ISBN;
	string KitapIsmi;
	string YazarAdi;
	string YazarSoyadi;
	string Tur;
	string Konusu;
	string SayfaSayisi;

	string oduncTarihi;
	string donusTarihi;

	char islem;
	char cevap;

	
	ofstream DosyaYaz;
	ifstream DosyaOku;

	string kullaniciAdi, kullaniciSifre;
	string tekSeferlikAd;
	string tekSeferlikSifre; 

	ifstream kullanOku("Kullan�c�lar.txt");
	
	

	cout <<"  |  L�tfen Kullan�c� Adinizi Giriniz   |="; cin >> tekSeferlikAd;	
	cout <<"  |  L�tfen Kullan�c� �ifrenizi Giriniz |="; cin >> tekSeferlikSifre;
	cout << endl;



	int sonuc = 0;

	while (kullanOku >> kullaniciAdi >> kullaniciSifre) //dosyadan veriler okumak i�in
	{
		if (kullaniciAdi == tekSeferlikAd && kullaniciSifre == tekSeferlikSifre)
		{
			cout << "\n  {* DE�ERL� OKURUMUZ S�STEME BA�ARALI G�R�� YAPTINIZ *}\n" << endl;

			do {
				cout << "      =   Hangi ��lemi Yapmak �stiyorsnuz ? =        " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      1- Yeni Okuyucu Kayd�.                  | " << endl;        
				cout << "    |______________________________________________| " << endl;
				cout << "    |      2- Okuyucu Kayd� G�ncelleme.            | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      3- Okuyucu Kayd� Silme .                | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      4- Okuyucu Kitap �d�n� Alma.            | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      5- Okuyucu kitap Geri D�nd�rme .        | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      6- Okuyucu �zerindeki Kitaplar listesi. | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      7- Kitap ekleme.                        | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      8- Kitap silme.                         | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      9- Kitap d�zeltme.                      | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << endl;

				cout << "    ((L�tfen Yapmak �stediginiz ��lemin Say�s�n� Yaz�n�z)) :  "; cin >> secim;
				cout << endl;
				
				switch (secim) //Se�im yap�yoruz
				{
				case 1:
				{
					cout << "  ((1-YEN� OKUYUCU KAYDINI SE�T�N�Z))" << endl; //Men�den numara se�erken �nce kay�t ekleme yap�yoruz

					do
					{
						
						
						long long TcNo,gecici;
						int tcBoyutu;
						ofstream DosyaYaz;
						
						DosyaYaz.open("Okuyucu.txt", ios::app | ios::out | ios::in);
						cout << "\n Okuyucu TC :" << endl; cin >> TcNo;				
						gecici = TcNo;

						for (tcBoyutu = 1; gecici > 10; tcBoyutu++)
						{
							gecici = gecici / 10;

						}
						if (tcBoyutu == 11)
						{
							cout << "adiniz iki isimli ise bo�luk b�rakmadan araya (_) karakterini giriniz" << endl;
							cout << "\n  Adi :" << endl; cin >> Adi;
							cout << "\n Soyadi :" << endl; cin >> Soyadi;
							cout << "\n Uye numaras�:" << endl; cin >> UyeNumarasi;
							cout << "\n  DogumTarihi :" << endl; cin >> DogumTarihi;
							cout << "\n Telefonu :" << endl; cin >> Telefon;
							cout << "\n Meslegi :" << endl; cin >> Meslegi;
							cout << "\n Alabilecegi Kitap Sayisi :" << endl; cin >> AlabilecegiKitapSayisi;
							
							DosyaYaz << TcNo << " " << Adi << ' ' << Soyadi << ' ' << ' ' << UyeNumarasi << ' '
								<< DogumTarihi << ' ' << Telefon << ' ' << Meslegi << ' ' << AlabilecegiKitapSayisi << endl;

						}
						else
						{
							cout << "girilen TC 11 haneli degil !" << tcBoyutu << "haneli olamaz " << endl;
						}
						
						cout << "\n Baska kayit yapacak misiniz?(e/E) (h/H) "; cin >> cevap;					

					} while (cevap == 'e' || cevap == 'E');
					DosyaYaz.close();
					cout << "Dosyaya yazim tamamlandi." << endl;
					break;
				}
				case 2:
				{
					long long  OkuyucuSorgu_TC;

					cout << " ((2-OKUYCU KAYIT D�ZENLEMEY� SE�T�N�Z)) " << endl;

					cout << " TC. Kimlik Numarasi...:"; cin >> OkuyucuSorgu_TC; //d�zenlenecek kimlik numaras�n� sorgulatt�m.

					int gcc = 0;

					ifstream DosyaOku("Okuyucu.txt"); //Dosya ��k��� yapabilmek i�in gerekli kodu yazd�m.
					ofstream DosyaYaz("gecici.tmp");	// DosyaYaz.open("gecici.tmp",ios::app); //gecici.tmp ad�mda dosya olu�turup dosya ekleme modunda a�t�m

					while (DosyaOku >> TcNo >> Adi >> Soyadi >> UyeNumarasi >> DogumTarihi >> Telefon >> Meslegi >> AlabilecegiKitapSayisi) //DosyaOku da belirtti�im okuycu.txt dosyas�n� sonuna kadar okuttum.
					{

						if (OkuyucuSorgu_TC == TcNo)//Sorgulanan TC. Kimlik numaras� varsa okuyucu bilgilerini g�sterir.
						{

							cout << "\n Okuyucu TC :" << endl;
							cout << " Okuyucunun Tc'si :" << TcNo << endl;
							cout << "Okuyucunun Adi :" << Adi << endl;
							cout << "Okuyucunun Soyad� :" << Soyadi << endl;
							cout << "Okuyucunun �ye Numaras�:" << UyeNumarasi << endl;
							cout << "Okuyucunun Do�um Tarihi :" << DogumTarihi << endl;
							cout << "Okuyucunun Telefon Numaras� :" << Telefon << endl;
							cout << "Okuyucunun Mesle�i:" << Meslegi << endl;
							cout << "Okuyucunun Alabilecegi Kitap Say�s�:" << AlabilecegiKitapSayisi << endl;

							cout << "\n D�zenlenecek Okuyucu TC :"; cin >> TcNo;
							cout << "\n  Adi :"; cin >> Adi;
							cout << "\n Soyadi :"; cin >> Soyadi;
							cout << "\n Uye numaras�:"; cin >> UyeNumarasi;
							cout << "\n  DogumTarihi :"; cin >> DogumTarihi;
							cout << "\n Telefonu :"; cin >> Telefon;
							cout << "\n Meslegi :"; cin >> Meslegi;
							cout << "\n Alabilecegi Kitap Sayisi :"; cin >> AlabilecegiKitapSayisi;

							DosyaYaz << TcNo << " " << Adi << ' ' << Soyadi << ' '
								<< UyeNumarasi << ' ' << DogumTarihi << ' ' << Telefon << ' '
								<< Meslegi << ' ' << AlabilecegiKitapSayisi << "\n";  //D�zenlenen dosya bilgileri yazd�r�l�r

							gcc = 1;
						}

						else
							DosyaYaz << TcNo << " " << Adi << ' ' << Soyadi << ' '
							<< UyeNumarasi << ' ' << DogumTarihi << ' ' << Telefon << ' '
							<< Meslegi << ' ' << AlabilecegiKitapSayisi << "\n";
					}
					if (gcc == 0)
						cout << "Boyle Bir Kayit Bulunamamistir..." << endl;
					DosyaYaz.close();
					DosyaOku.close();
					remove("Okuyucu.txt");                 // Okuyucu.txt dosyas� silinirken
					rename("gecici.tmp", "Okuyucu.txt");  //gecici.tmp dosyas� okuyucu.txt dosyas� olarak de�i�tirirlir.

					break;
				}
				case 3:
				{
					cout << "((3-OKUYCU KAYIDINI S�LMEY� SE�T�N�Z))" << endl;
					long long  TC;
					cout << "Silinecek okuyucu Tc Numarasini Giriniz :"; cin >> TC;
					ifstream DosyaOku("Okuyucu.txt");
					ofstream DosyaYaz("gecici.txt");//Gecici bir dosya a��l�r
					while (DosyaOku >> TcNo >> Adi >> Soyadi >> UyeNumarasi >> DogumTarihi >> Telefon >> Meslegi >> AlabilecegiKitapSayisi) //DosyaOku da belirtti�im  dosyas�n� sonuna kadar okuttum.
					{

						if (TcNo == TC)//Girilen TC. Kimlik nosu kay�tlarda var ise okuyucu kayd�n� g�r�nt�ler.
						{
							cout << " = Okuycunun Bilgileri = " << endl << endl;
							cout << " Okuyucunun Tc'si :" << TcNo << endl;
							cout << "Okuyucunun Adi :" << Adi << endl;
							cout << "Okuyucunun Soyad� :" << Soyadi << endl;
							cout << "Okuyucunun �ye Numaras�:" << UyeNumarasi << endl;
							cout << "Okuyucunun Do�um Tarihi :" << DogumTarihi << endl;
							cout << "Okuyucunun Telefon Numaras� :" << Telefon << endl;
							cout << "Okuyucunun Mesle�i:" << Meslegi << endl;
							cout << "Okuyucunun Alabilecegi Kitap Say�s�:" << AlabilecegiKitapSayisi << endl; "\n";  //E�er ko�ulu sa�layan bilgi varsa onu ekranda g�sterir
							cout << "Silme Isleminiz Gerceklesmistir..." << endl;

						}
						else
							DosyaYaz << TcNo << " " << Adi << " " << Soyadi << " " << UyeNumarasi
							<< " " << DogumTarihi << " " << Telefon << " " << Meslegi << " " << AlabilecegiKitapSayisi << "\n";
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove("Okuyucu.txt"); //dosyayi sildim.
					rename("gecici.txt", "Okuyucu.txt"); //Gecici dosyalar kay�t silindikten tmp dosyasi txt dosyasina aktar�l�r.			
					break;
				}


				case 4:
				{
					long long TC;
					cout << "  ((4 -OKUYCU K�TAP ALMAYI SE�T�N�Z)) "<< endl;
					do
					{
						cout << "kitap alacak okuyucu TC'si "; cin >> TC;
						ifstream DosyaOku("Okuyucu.txt");

						while (!DosyaOku.eof())//dosyay� sonuna okutulur 
						{
							DosyaOku >> TcNo >> Adi >> Soyadi >> UyeNumarasi
								>> DogumTarihi >> Telefon >> Meslegi >> AlabilecegiKitapSayisi;

							if (TC == TcNo) //sistemdeki tc ile d��ar�dan al�nan tc ile uyu�uyorsa if blogu i�ine giri� yap�l�r 
							{
								cout << "\n Okuyucu Bilgileri \n";
								cout << "TC no :" << TcNo << endl;
								cout << "Ad� :" << Adi << endl;
								cout << "Soyad� :" << Soyadi << endl;
								cout << "Uye Numaras�:" << UyeNumarasi << endl;
								cout << " Dogum Tarihi :" << DogumTarihi << endl;
								cout << "Telefonu :" << Telefon << endl;
								cout << "Cinsiyeti:" << Meslegi << endl;
								cout << "Alabilecegi Kitap Sayisi:" << AlabilecegiKitapSayisi << endl;

								cout << "kitap almak istiyor musunuz ? (e/h)" << endl;
								cin >> cevap;
								if (cevap == 'e')//eger sisteme devam edilmek isteniyorsa e harfi girilince if blogu i�ine giri� yap�l�r 
								{
									DosyaOku.close();
									ofstream DosyaYaz;
									DosyaYaz.open("Odunc.txt", ios::app);
									
									cout << "\n Kitap Bilgileri \n";
									cout << "\n Kitap ISBN NO"; cin >> ISBN;
									cout << "\nTC no :"; cin >> TcNo;
									cout << "Kitab� �d�n� ald���n�z tarihi giriniz(GG/AA/YY)"; cin >> oduncTarihi;
									cout << "\nKitab�  1 ay i�erisnde sonra iade ediniz.\n�ade edece�iniz tarihini giriniz(GG/AA/YY)"; cin >> donusTarihi;

									DosyaYaz << ISBN << "  " << TcNo << " " << oduncTarihi << " " << donusTarihi << "\n";

									DosyaYaz.close();
									
									string ISBNNo;
									cout << "ald�g�n�z K�TABIN ISBN NUMARASINI G�R�N�Z:"; cin >> ISBNNo;
									
									ifstream DosyaOku("Kitapl�k.txt");
									ofstream DosyaYazal�m("GE���� K�TAPLIK.tmp");//Gecici bir dosya a��l�r
									
									while (DosyaOku >> ISBN >> KitapIsmi >> YazarAdi >> YazarSoyadi >> Tur >> Konusu >> SayfaSayisi) //DosyaOku da belirtti�im Kitapl�k.txt dosyas�n� sonuna kadar okuttum.
									{

										if (ISBNNo == ISBN) // Girilen ISBN NO kay�tlarda var ise kitab�n bilgilerini g�r�nt�ler.
										{
											cout << "\n K�TAP ISBN :" << ISBN << endl;;
											cout << "\n  K�TAP �SM� :" << KitapIsmi << endl;;
											cout << "\n YAZAR ADI :" << YazarAdi << endl;;
											cout << "\n YAZAR SOYADI:" << YazarSoyadi << endl;;
											cout << "\n  T�R :" << Tur << endl;;
											cout << "\n KONUSU :" << Konusu << endl;;
											cout << "\n  K�TABIN SAYFA SAYISI :" << SayfaSayisi << endl;  "\n";  //E�er ko�ulu sa�layan bilgi varsa onu ekranda g�sterir
											cout << "K�TAPLIKTAN S�LME ��LEM� GER�EKLE�M��T�R" << endl;
											
											
										}
										else
											DosyaYazal�m << "\n" << ISBN << " " << KitapIsmi << " " << YazarAdi << " " << Tur << " " << Konusu << " " << SayfaSayisi;
									}
									DosyaYazal�m.close();
									DosyaOku.close();
									remove("Kitapl�k.txt");//dosyayi sildim.
									rename("GE���� K�TAPLIK.tmp", "Kitapl�k.txt");//Gecici dosyalar kay�t silindikten tmp dosyasi txt dosyasina aktar�l�r.

									cout << "\n Baska kayit yapacak misiniz?(e/E) (h/H) ";
									cin >> cevap;

								}
								else
									cout << "Boyle Bir Kayit Bulunamamistir..." << endl;

							}

						}

					} while (cevap == 'e' || cevap == 'E');

					cout << "Dosyaya yazim tamamlandi." << endl;
					break;


				}
				case 5:
				{
					cout << "((5-OKUYCU K�TAP GER� D�ND�RMEY� SE�T�N�Z))" << endl;
					string ISBNNo;
					cout << "VER�LECEK K�TABIN ISBN NO'su "; cin >> ISBNNo;
					ifstream DosyaOku("Kitapl�k.txt");
					while (!DosyaOku.eof())//dosyay� sonunda kadar okunur 
					{
						DosyaOku >> ISBN >> KitapIsmi >> YazarAdi >>
							YazarSoyadi >> Tur >> Konusu >> SayfaSayisi;
					
						if (ISBNNo == ISBN)//girilen ISBN NO ile sistemdeki veri uyu�tugu takdirde if blogu i�ine giri� saglan�r 
						{
							cout << "\n K�TAP ISBN :" << ISBN << endl;;
							cout << "\n  K�TAP �SM� :" << KitapIsmi << endl;;
							cout << "\n YAZAR ADI :" << YazarAdi << endl;;
							cout << "\n YAZAR SOYADI:" << YazarSoyadi << endl;;
							cout << "\n  T�R :" << Tur << endl;;
							cout << "\n KONUSU :" << Konusu << endl;;
							cout << "\n  K�TABIN SAYFA SAYISI :" << SayfaSayisi << endl;  "\n";  //E�erko�ulu sa�layan bilgi varsa onu ekranda g�sterir

							cout << "kitap bilgileri dogru mu? (e/h)" << endl;
							cin >> cevap;
							if (cevap == 'e')
							{
								string ISBNNo;
								cout << "GER� VERMEK �STED�G�N�Z K�TABIN ISBN NUMARASINI TEKRAR G�R�N�Z:"; cin >> ISBNNo;
							
								ifstream DosyaOku("Odunc.txt");
								ofstream DosyaYaz("Odunc veren.tmp");//Gecici bir dosya a��l�r
								
								while (DosyaOku >> ISBN >> TcNo >> oduncTarihi >> donusTarihi) //DosyaOku da belirtti�im Kitapl�k.txt dosyas�n� sonuna kadar okuttum.
								{
									if (ISBNNo == ISBN) //Girilen ISBN NO kay�tlarda var ise kitap kayd�n� g�r�nt�ler.
									{
										cout << "\n Kitap Ve Okuyucu Bilgileri \n";
										cout << " K�TAP ISBN :" << ISBN << endl;
										cout << " Kitap Geri Veren Okuyucu TC no :" << TcNo << endl;
										cout << "Kitab� �d�n� Ald���n�z Tarih Bilgisi (GG/AA/YY)" << oduncTarihi << endl;
										cout << "Kitab� �ade Etmeniz Gereken Tarih (GG/AA/YY)" << donusTarihi << endl;  //E�er ko�ulu sa�layan bilgi varsa onu ekranda g�sterir

										cout << "K�TAP Geri Verme ��LEM� GER�EKLE�M��T�R" << endl;

									}
									else
										DosyaYaz << ISBN << " " << TcNo << " " << oduncTarihi << " " << donusTarihi << "\n";
								}
								DosyaYaz.close();
								DosyaOku.close();
								remove("Odunc.txt");//dosyayi sildim.
								rename("Odunc veren.tmp", "Odunc.txt");//Gecici dosyalar kay�t silindikten tmp dosyasi txt dosyasina aktar�l�r.

								cout << "\n Baska Silme yapacak misiniz?(e/E) (h/H) "; cin >> cevap;

							} while (cevap == 'e' || cevap == 'E');

							cout << "DosyaDAN S�LME tamamlandi." << endl;
							break;
						}
						else
							cout << "Boyle Bir Kayit Bulunamamistir..." << endl;
					}
					break;
				}
				case 6:
				{
					cout << "  ((6- OKUYUCU �ZER�NDEK� K�TAP L�STES�N� SE�T�N�Z)) " << endl;

					long long TC;

					cout << "Kitap Listesi G�r�nt�lene�ek Okuyucu TC'si "; cin >> TC;

					ifstream DosyaOku("Okuyucu.txt");

					while (!DosyaOku.eof())//dosyay� sonunda kadar okunur 
					{
						DosyaOku >> TcNo >> Adi >> Soyadi >> UyeNumarasi
							>> DogumTarihi >> Telefon >> Meslegi >> AlabilecegiKitapSayisi;

						if (TC == TcNo)//girilen tc sistemdeki tc ile e�it ise okuyucunun sistemde mevcut olan bilgileri g�r�nt�lenir.
						{
							cout << "\n Okuyucu Bilgileri \n";
							cout << "TC no :" << TcNo << endl;
							cout << "Ad� :" << Adi << endl;
							cout << "Soyad� :" << Soyadi << endl;
							cout << "Uye Numaras�:" << UyeNumarasi << endl;
							cout << " Dogum Tarihi :" << DogumTarihi << endl;
							cout << "Telefonu :" << Telefon << endl;
							cout << "Cinsiyeti:" << Meslegi << endl;
							cout << "Alabilecegi Kitap Sayisi:" << AlabilecegiKitapSayisi << endl;

							DosyaOku.close();

							ofstream DosyaYaz;
							DosyaOku.open("Odunc.txt", ios::in);
							cout << "\n Odunc Ald�� Kitap listesi \n " << endl;

							cout << setw(10) << " ISBN "<< setw(10) <<"TcNo " << setw(12) << "oduncTarihi" << setw(12) << "donusTarihi" << endl;

							while (!DosyaOku.eof())//dosyay� sonunda kadar okur 
							{
								DosyaOku >> ISBN >> TcNo >> oduncTarihi >> donusTarihi;

								if (TC == TcNo)//girilen tc ile sistemde mevcut olan tc var ise ekrana cout bask�s� al�n�r s�t�n �eklinde 
								{
									cout << setw(10) << ISBN << setw(13) << TcNo << setw(12) << oduncTarihi << setw(12) << donusTarihi << endl;
								}
							}
							DosyaYaz.close();


						}
						else
							cout << "Boyle Bir Kayit Bulunamamistir..." << endl;
					}
					break;
				}
				case 7:
				{

					cout << " ((7- K�TAP EKLEMEY� SE�T�N�Z.)) " << endl; 

					//men�den se�ilen 7 say�s� ile kitapl�ga yeni kitap eklemesi yap�labilir .
					do
					{
						ofstream DosyaYaz;
						DosyaYaz.open("Kitapl�k.txt", ios::app | ios::out | ios::in);

						cout << "\n K�TAP ISBN :" << endl; cin >> ISBN;
						cout << "\n  K�TAP �SM� :" << endl; cin >> KitapIsmi;
						cout << "\n YAZAR ADI :" << endl; cin >> YazarAdi;
						cout << "\n YAZAR SOYADI:" << endl; cin >> YazarSoyadi;
						cout << "\n  T�R :" << endl; cin >> Tur;
						cout << "\n KONUSU :" << endl; cin >> Konusu;
						cout << "\n  K�TABIN SAYFA SAYISI :" << endl; cin >> SayfaSayisi;
					
						DosyaYaz << ISBN << ' ' << KitapIsmi << ' ' << YazarAdi << ' '
							<< YazarSoyadi << ' ' << Tur << ' ' << Konusu << ' ' << SayfaSayisi << endl;
						
						cout << "\n BA�KA K�TAP KAYIDI YAPACAK MISINIZ ?(e/E) (h/H) "; cin >> cevap;
						DosyaYaz.close();
					} while (cevap == 'e' || cevap == 'E');

					cout << "K�TAP EKLEME TAMAMLANDI." << endl;
					break;
				}
				case 8:
				{
					cout << "  ((8- K�TAP KAYDI S�LMEY� SE�T�N�Z.))" << endl;
					string ISBNNo;
					cout << "S�LMEK �STED�G�N�Z K�TABIN ISBN NUMARASINI G�R�N�Z:"; cin >> ISBNNo;
					ifstream DosyaOku("Kitapl�k.txt");
					ofstream DosyaYaz("GE���� K�TAPLIK.tmp"); //Gecici bir dosya a��l�r
					while (DosyaOku >> ISBN >> KitapIsmi >> YazarAdi >> YazarSoyadi >> Tur >> Konusu >> SayfaSayisi) //DosyaOku da belirtti�im Kitapl�k.txt dosyas�n� sonuna kadar okuttum.
					{

						if (ISBNNo == ISBN) //Girilen ISBN no  kay�tlarda var ise kitap kayd�n� g�r�nt�ler.
						{
							cout << "\n K�TAP ISBN :" << ISBN << endl;;
							cout << "\n  K�TAP �SM� :" << KitapIsmi << endl;;
							cout << "\n YAZAR ADI :" << YazarAdi << endl;;
							cout << "\n YAZAR SOYADI:" << YazarSoyadi << endl;;
							cout << "\n  T�R :" << Tur << endl;;
							cout << "\n KONUSU :" << Konusu << endl;;
							cout << "\n  K�TABIN SAYFA SAYISI :" << SayfaSayisi << endl;  "\n";  //E�er Ko�ulu Sa�layan Bilgi Varsa Onu Ekranda G�sterir
							cout << "K�TAP S�LME ��LEM� GER�EKLE�M��T�R" << endl;

						}
						else
							DosyaYaz << "\n" << ISBN << " " << KitapIsmi << " " << YazarAdi << " " << Tur << " " << Konusu << " " << SayfaSayisi;
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove ("Kitapl�k.txt"); //dosyayi sildim.
					rename ("GE���� K�TAPLIK.tmp", "Kitapl�k.txt"); //Gecici dosyalar kay�t silindikten tmp dosyasi txt dosyasina aktar�l�r.
					break;
				}
				case 9:
				{
					string KitapSorgu_ISBN;
					cout << " ((9- K�TAP D�ZENLEMEY� SE�T�N�Z ))" << endl;

					cout << " ISBN Numarasi:"; cin >> KitapSorgu_ISBN; // D�zenlenecek ISBN Nosunu sorgulatt�m.
					int gcc = 0;

					ifstream DosyaOku("Kitapl�k.txt"); //Dosya ��k��� yapabilmek i�in gerekli kodu yazd�m.
					ofstream DosyaYaz("ge�i�i.tmp");//gecici.tmp ad�mda dosya olu�turup dosya ekleme modunda a�t�m
					

					while (DosyaOku >> ISBN >> KitapIsmi >> YazarAdi >> YazarSoyadi >> Tur >> Konusu >> SayfaSayisi) //DosyaOku da belirtti�im Kitapl�k.txt dosyas�n� sonuna kadar okuttum.
					{

						if (KitapSorgu_ISBN == ISBN ) //Sorgulanan ISBN numaras� varsa Kitap bilgilerini g�sterir.
						{
							cout << "\n K�TAP ISBN :" << ISBN << endl;;
							cout << "\n  K�TAP �SM� :" << KitapIsmi << endl;;
							cout << "\n YAZAR ADI :" << YazarAdi << endl;;
							cout << "\n YAZAR SOYADI:" << YazarSoyadi << endl;;
							cout << "\n  T�R :" << Tur << endl;;
							cout << "\n KONUSU :" << Konusu << endl;;
							cout << "\n  K�TABIN SAYFA SAYISI :" << SayfaSayisi << endl;

							cout << "\n K�TAP ISBN :" << endl; cin >> ISBN;
							cout << "\n  K�TAP �SM� :" << endl; cin >> KitapIsmi;
							cout << "\n YAZAR ADI :" << endl; cin >> YazarAdi;
							cout << "\n YAZAR SOYADI:" << endl; cin >> YazarSoyadi;
							cout << "\n  T�R :" << endl; cin >> Tur;
							cout << "\n KONUSU :" << endl; cin >> Konusu;
							cout << "\n K�TABIN SAYFA SAYISI :" << endl; cin >> SayfaSayisi;

							DosyaYaz << ISBN << " " << KitapIsmi << ' ' << YazarAdi << ' ' << YazarSoyadi << ' '
								<< Tur << ' ' << Konusu << ' ' << SayfaSayisi << "\n"; //D�zenlenen dosya bilgileri yazd�r�l�r.

							gcc = 1;
						}
						else
							DosyaYaz << ISBN << " " << KitapIsmi << ' ' << YazarAdi << ' '
							<< YazarSoyadi << ' ' << Tur << ' ' << Konusu << ' ' << SayfaSayisi << "\n";

					}
					if (gcc == 0)
						cout << "Boyle Bir Kayit Bulunamamistir..." << endl;
					DosyaYaz.close();
					DosyaOku.close();
					remove("Kitapl�k.txt");// Kitapl�k.txt dosyas� silinirken
					rename("ge�i�i.tmp", "Kitapl�k.txt");//gecici.tmp dosyas� Kitapl�k.txt dosyas� olarak de�i�tirirlir.
					break;
				}
				}
				cout << "�slem yapmaya devam etmek istiyor musunuz? (e/E) (h/H)";
				cin >> islem;
			} while (islem == 'e' || islem == 'E'); //��lemi yapt�ktan sonra kar��m�za tekrar men� ��kmas�n� sa�l�yor	
			cout << endl;

			sonuc = 1;
		}


	}

	if (sonuc == 0)
	{
		//Sonu� ilk �nce 0 a e�it .Ancak Kullan�c� Adi ve �ifresi girilen degerler e�it ise ko�ul sonunda sonu� =1 olur ve kullan�c� sisteme giri� yapar
		//E�er e�it degilse kullan�c� bu if bloguna y�nlendirilir.
		cout << "Degerli Okurumuz Kullan�c� Ad�n�z� veya Kullan�c� �ifrenizi Hatal� Giridiniz\n " << endl;

	}
	kullanOku.close();



	auto finish = chrono::system_clock::now();
	auto simdibitis = chrono::system_clock::to_time_t(finish);
	char cikisSaat[30];
	ctime_s(cikisSaat, sizeof(cikisSaat), &simdibitis);
	cout << "\n ��k�� Saati:" << cikisSaat << "\n";

}


