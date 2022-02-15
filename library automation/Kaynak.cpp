
				/****************************************************************************
				**				    	SAKARYA ÜNÝVERSÝTESÝ                             **
				**			    BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ                **
				**				   BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ                        **
				**			         PROGRAMLAMAYA GÝRÝÞÝ DERSÝ                          **
				**                                                                       **
				**				ÖDEV NUMARASI…...:P_G PROJE ÖDEVÝ                        **
				**				ÖÐRENCÝ ADI...............:AZÝZ ÞÝMÞEK                   **
				**				ÖÐRENCÝ NUMARASI.:b201210394                             **
				**				DERS GRUBU…………: 1A GRUBU                                 **
				****************************************************************************/





#include <iostream> // cout,cin vs. için
#include <conio.h> //getch(); fonksiyonu için
#include <fstream> // dosyalama iþlemleri için
#include <string> // string türü için
#include <clocale> // Türkçe karakter için
#include <iomanip> //setw() için eklenen kütüphane
#include <stdio.h>//içinde kullanýlacak fonksiyonlar tanýmlýdýr 
#include <chrono> // kodun daha kolay,tür kullanýmý ve bakým güvenliði için Kullanýcý tanýmlý sabit deðerleri tanýmlar.
#include <ctime>//tarih ve saat türünde degiþkenler saklanýr 

using namespace std;
int main()
{
	setlocale(LC_ALL, "turkish"); //Türkçe karakter ekliyoruz

	auto start = chrono::system_clock::now();
	auto simdibasla = chrono::system_clock::to_time_t(start);
	char girisSaat[30];
	ctime_s(girisSaat, sizeof(girisSaat), &simdibasla);
	cout << "\n Giriþ Saati:" << girisSaat << "\n";



	int secim;


	string Adi; //Deðiþkenleri tanýmladýk
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

	ifstream kullanOku("Kullanýcýlar.txt");
	
	

	cout <<"  |  Lütfen Kullanýcý Adinizi Giriniz   |="; cin >> tekSeferlikAd;	
	cout <<"  |  Lütfen Kullanýcý Þifrenizi Giriniz |="; cin >> tekSeferlikSifre;
	cout << endl;



	int sonuc = 0;

	while (kullanOku >> kullaniciAdi >> kullaniciSifre) //dosyadan veriler okumak için
	{
		if (kullaniciAdi == tekSeferlikAd && kullaniciSifre == tekSeferlikSifre)
		{
			cout << "\n  {* DEÐERLÝ OKURUMUZ SÝSTEME BAÞARALI GÝRÝÞ YAPTINIZ *}\n" << endl;

			do {
				cout << "      =   Hangi Ýþlemi Yapmak Ýstiyorsnuz ? =        " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      1- Yeni Okuyucu Kaydý.                  | " << endl;        
				cout << "    |______________________________________________| " << endl;
				cout << "    |      2- Okuyucu Kaydý Güncelleme.            | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      3- Okuyucu Kaydý Silme .                | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      4- Okuyucu Kitap Ödünç Alma.            | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      5- Okuyucu kitap Geri Döndürme .        | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      6- Okuyucu Üzerindeki Kitaplar listesi. | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      7- Kitap ekleme.                        | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      8- Kitap silme.                         | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << "    |      9- Kitap düzeltme.                      | " << endl;
				cout << "    |______________________________________________| " << endl;
				cout << endl;

				cout << "    ((Lütfen Yapmak Ýstediginiz Ýþlemin Sayýsýný Yazýnýz)) :  "; cin >> secim;
				cout << endl;
				
				switch (secim) //Seçim yapýyoruz
				{
				case 1:
				{
					cout << "  ((1-YENÝ OKUYUCU KAYDINI SEÇTÝNÝZ))" << endl; //Menüden numara seçerken önce kayýt ekleme yapýyoruz

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
							cout << "adiniz iki isimli ise boþluk býrakmadan araya (_) karakterini giriniz" << endl;
							cout << "\n  Adi :" << endl; cin >> Adi;
							cout << "\n Soyadi :" << endl; cin >> Soyadi;
							cout << "\n Uye numarasý:" << endl; cin >> UyeNumarasi;
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

					cout << " ((2-OKUYCU KAYIT DÜZENLEMEYÝ SEÇTÝNÝZ)) " << endl;

					cout << " TC. Kimlik Numarasi...:"; cin >> OkuyucuSorgu_TC; //düzenlenecek kimlik numarasýný sorgulattým.

					int gcc = 0;

					ifstream DosyaOku("Okuyucu.txt"); //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.
					ofstream DosyaYaz("gecici.tmp");	// DosyaYaz.open("gecici.tmp",ios::app); //gecici.tmp adýmda dosya oluþturup dosya ekleme modunda açtým

					while (DosyaOku >> TcNo >> Adi >> Soyadi >> UyeNumarasi >> DogumTarihi >> Telefon >> Meslegi >> AlabilecegiKitapSayisi) //DosyaOku da belirttiðim okuycu.txt dosyasýný sonuna kadar okuttum.
					{

						if (OkuyucuSorgu_TC == TcNo)//Sorgulanan TC. Kimlik numarasý varsa okuyucu bilgilerini gösterir.
						{

							cout << "\n Okuyucu TC :" << endl;
							cout << " Okuyucunun Tc'si :" << TcNo << endl;
							cout << "Okuyucunun Adi :" << Adi << endl;
							cout << "Okuyucunun Soyadý :" << Soyadi << endl;
							cout << "Okuyucunun Üye Numarasý:" << UyeNumarasi << endl;
							cout << "Okuyucunun Doðum Tarihi :" << DogumTarihi << endl;
							cout << "Okuyucunun Telefon Numarasý :" << Telefon << endl;
							cout << "Okuyucunun Mesleði:" << Meslegi << endl;
							cout << "Okuyucunun Alabilecegi Kitap Sayýsý:" << AlabilecegiKitapSayisi << endl;

							cout << "\n Düzenlenecek Okuyucu TC :"; cin >> TcNo;
							cout << "\n  Adi :"; cin >> Adi;
							cout << "\n Soyadi :"; cin >> Soyadi;
							cout << "\n Uye numarasý:"; cin >> UyeNumarasi;
							cout << "\n  DogumTarihi :"; cin >> DogumTarihi;
							cout << "\n Telefonu :"; cin >> Telefon;
							cout << "\n Meslegi :"; cin >> Meslegi;
							cout << "\n Alabilecegi Kitap Sayisi :"; cin >> AlabilecegiKitapSayisi;

							DosyaYaz << TcNo << " " << Adi << ' ' << Soyadi << ' '
								<< UyeNumarasi << ' ' << DogumTarihi << ' ' << Telefon << ' '
								<< Meslegi << ' ' << AlabilecegiKitapSayisi << "\n";  //Düzenlenen dosya bilgileri yazdýrýlýr

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
					remove("Okuyucu.txt");                 // Okuyucu.txt dosyasý silinirken
					rename("gecici.tmp", "Okuyucu.txt");  //gecici.tmp dosyasý okuyucu.txt dosyasý olarak deðiþtirirlir.

					break;
				}
				case 3:
				{
					cout << "((3-OKUYCU KAYIDINI SÝLMEYÝ SEÇTÝNÝZ))" << endl;
					long long  TC;
					cout << "Silinecek okuyucu Tc Numarasini Giriniz :"; cin >> TC;
					ifstream DosyaOku("Okuyucu.txt");
					ofstream DosyaYaz("gecici.txt");//Gecici bir dosya açýlýr
					while (DosyaOku >> TcNo >> Adi >> Soyadi >> UyeNumarasi >> DogumTarihi >> Telefon >> Meslegi >> AlabilecegiKitapSayisi) //DosyaOku da belirttiðim  dosyasýný sonuna kadar okuttum.
					{

						if (TcNo == TC)//Girilen TC. Kimlik nosu kayýtlarda var ise okuyucu kaydýný görüntüler.
						{
							cout << " = Okuycunun Bilgileri = " << endl << endl;
							cout << " Okuyucunun Tc'si :" << TcNo << endl;
							cout << "Okuyucunun Adi :" << Adi << endl;
							cout << "Okuyucunun Soyadý :" << Soyadi << endl;
							cout << "Okuyucunun Üye Numarasý:" << UyeNumarasi << endl;
							cout << "Okuyucunun Doðum Tarihi :" << DogumTarihi << endl;
							cout << "Okuyucunun Telefon Numarasý :" << Telefon << endl;
							cout << "Okuyucunun Mesleði:" << Meslegi << endl;
							cout << "Okuyucunun Alabilecegi Kitap Sayýsý:" << AlabilecegiKitapSayisi << endl; "\n";  //Eðer koþulu saðlayan bilgi varsa onu ekranda gösterir
							cout << "Silme Isleminiz Gerceklesmistir..." << endl;

						}
						else
							DosyaYaz << TcNo << " " << Adi << " " << Soyadi << " " << UyeNumarasi
							<< " " << DogumTarihi << " " << Telefon << " " << Meslegi << " " << AlabilecegiKitapSayisi << "\n";
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove("Okuyucu.txt"); //dosyayi sildim.
					rename("gecici.txt", "Okuyucu.txt"); //Gecici dosyalar kayýt silindikten tmp dosyasi txt dosyasina aktarýlýr.			
					break;
				}


				case 4:
				{
					long long TC;
					cout << "  ((4 -OKUYCU KÝTAP ALMAYI SEÇTÝNÝZ)) "<< endl;
					do
					{
						cout << "kitap alacak okuyucu TC'si "; cin >> TC;
						ifstream DosyaOku("Okuyucu.txt");

						while (!DosyaOku.eof())//dosyayý sonuna okutulur 
						{
							DosyaOku >> TcNo >> Adi >> Soyadi >> UyeNumarasi
								>> DogumTarihi >> Telefon >> Meslegi >> AlabilecegiKitapSayisi;

							if (TC == TcNo) //sistemdeki tc ile dýþarýdan alýnan tc ile uyuþuyorsa if blogu içine giriþ yapýlýr 
							{
								cout << "\n Okuyucu Bilgileri \n";
								cout << "TC no :" << TcNo << endl;
								cout << "Adý :" << Adi << endl;
								cout << "Soyadý :" << Soyadi << endl;
								cout << "Uye Numarasý:" << UyeNumarasi << endl;
								cout << " Dogum Tarihi :" << DogumTarihi << endl;
								cout << "Telefonu :" << Telefon << endl;
								cout << "Cinsiyeti:" << Meslegi << endl;
								cout << "Alabilecegi Kitap Sayisi:" << AlabilecegiKitapSayisi << endl;

								cout << "kitap almak istiyor musunuz ? (e/h)" << endl;
								cin >> cevap;
								if (cevap == 'e')//eger sisteme devam edilmek isteniyorsa e harfi girilince if blogu içine giriþ yapýlýr 
								{
									DosyaOku.close();
									ofstream DosyaYaz;
									DosyaYaz.open("Odunc.txt", ios::app);
									
									cout << "\n Kitap Bilgileri \n";
									cout << "\n Kitap ISBN NO"; cin >> ISBN;
									cout << "\nTC no :"; cin >> TcNo;
									cout << "Kitabý ödünç aldýðýnýz tarihi giriniz(GG/AA/YY)"; cin >> oduncTarihi;
									cout << "\nKitabý  1 ay içerisnde sonra iade ediniz.\nÝade edeceðiniz tarihini giriniz(GG/AA/YY)"; cin >> donusTarihi;

									DosyaYaz << ISBN << "  " << TcNo << " " << oduncTarihi << " " << donusTarihi << "\n";

									DosyaYaz.close();
									
									string ISBNNo;
									cout << "aldýgýnýz KÝTABIN ISBN NUMARASINI GÝRÝNÝZ:"; cin >> ISBNNo;
									
									ifstream DosyaOku("Kitaplýk.txt");
									ofstream DosyaYazalým("GEÇÝÇÝ KÝTAPLIK.tmp");//Gecici bir dosya açýlýr
									
									while (DosyaOku >> ISBN >> KitapIsmi >> YazarAdi >> YazarSoyadi >> Tur >> Konusu >> SayfaSayisi) //DosyaOku da belirttiðim Kitaplýk.txt dosyasýný sonuna kadar okuttum.
									{

										if (ISBNNo == ISBN) // Girilen ISBN NO kayýtlarda var ise kitabýn bilgilerini görüntüler.
										{
											cout << "\n KÝTAP ISBN :" << ISBN << endl;;
											cout << "\n  KÝTAP ÝSMÝ :" << KitapIsmi << endl;;
											cout << "\n YAZAR ADI :" << YazarAdi << endl;;
											cout << "\n YAZAR SOYADI:" << YazarSoyadi << endl;;
											cout << "\n  TÜR :" << Tur << endl;;
											cout << "\n KONUSU :" << Konusu << endl;;
											cout << "\n  KÝTABIN SAYFA SAYISI :" << SayfaSayisi << endl;  "\n";  //Eðer koþulu saðlayan bilgi varsa onu ekranda gösterir
											cout << "KÝTAPLIKTAN SÝLME ÝÞLEMÝ GERÇEKLEÞMÝÞTÝR" << endl;
											
											
										}
										else
											DosyaYazalým << "\n" << ISBN << " " << KitapIsmi << " " << YazarAdi << " " << Tur << " " << Konusu << " " << SayfaSayisi;
									}
									DosyaYazalým.close();
									DosyaOku.close();
									remove("Kitaplýk.txt");//dosyayi sildim.
									rename("GEÇÝÇÝ KÝTAPLIK.tmp", "Kitaplýk.txt");//Gecici dosyalar kayýt silindikten tmp dosyasi txt dosyasina aktarýlýr.

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
					cout << "((5-OKUYCU KÝTAP GERÝ DÖNDÜRMEYÝ SEÇTÝNÝZ))" << endl;
					string ISBNNo;
					cout << "VERÝLECEK KÝTABIN ISBN NO'su "; cin >> ISBNNo;
					ifstream DosyaOku("Kitaplýk.txt");
					while (!DosyaOku.eof())//dosyayý sonunda kadar okunur 
					{
						DosyaOku >> ISBN >> KitapIsmi >> YazarAdi >>
							YazarSoyadi >> Tur >> Konusu >> SayfaSayisi;
					
						if (ISBNNo == ISBN)//girilen ISBN NO ile sistemdeki veri uyuþtugu takdirde if blogu içine giriþ saglanýr 
						{
							cout << "\n KÝTAP ISBN :" << ISBN << endl;;
							cout << "\n  KÝTAP ÝSMÝ :" << KitapIsmi << endl;;
							cout << "\n YAZAR ADI :" << YazarAdi << endl;;
							cout << "\n YAZAR SOYADI:" << YazarSoyadi << endl;;
							cout << "\n  TÜR :" << Tur << endl;;
							cout << "\n KONUSU :" << Konusu << endl;;
							cout << "\n  KÝTABIN SAYFA SAYISI :" << SayfaSayisi << endl;  "\n";  //Eðerkoþulu saðlayan bilgi varsa onu ekranda gösterir

							cout << "kitap bilgileri dogru mu? (e/h)" << endl;
							cin >> cevap;
							if (cevap == 'e')
							{
								string ISBNNo;
								cout << "GERÝ VERMEK ÝSTEDÝGÝNÝZ KÝTABIN ISBN NUMARASINI TEKRAR GÝRÝNÝZ:"; cin >> ISBNNo;
							
								ifstream DosyaOku("Odunc.txt");
								ofstream DosyaYaz("Odunc veren.tmp");//Gecici bir dosya açýlýr
								
								while (DosyaOku >> ISBN >> TcNo >> oduncTarihi >> donusTarihi) //DosyaOku da belirttiðim Kitaplýk.txt dosyasýný sonuna kadar okuttum.
								{
									if (ISBNNo == ISBN) //Girilen ISBN NO kayýtlarda var ise kitap kaydýný görüntüler.
									{
										cout << "\n Kitap Ve Okuyucu Bilgileri \n";
										cout << " KÝTAP ISBN :" << ISBN << endl;
										cout << " Kitap Geri Veren Okuyucu TC no :" << TcNo << endl;
										cout << "Kitabý Ödünç Aldýðýnýz Tarih Bilgisi (GG/AA/YY)" << oduncTarihi << endl;
										cout << "Kitabý Ýade Etmeniz Gereken Tarih (GG/AA/YY)" << donusTarihi << endl;  //Eðer koþulu saðlayan bilgi varsa onu ekranda gösterir

										cout << "KÝTAP Geri Verme ÝÞLEMÝ GERÇEKLEÞMÝÞTÝR" << endl;

									}
									else
										DosyaYaz << ISBN << " " << TcNo << " " << oduncTarihi << " " << donusTarihi << "\n";
								}
								DosyaYaz.close();
								DosyaOku.close();
								remove("Odunc.txt");//dosyayi sildim.
								rename("Odunc veren.tmp", "Odunc.txt");//Gecici dosyalar kayýt silindikten tmp dosyasi txt dosyasina aktarýlýr.

								cout << "\n Baska Silme yapacak misiniz?(e/E) (h/H) "; cin >> cevap;

							} while (cevap == 'e' || cevap == 'E');

							cout << "DosyaDAN SÝLME tamamlandi." << endl;
							break;
						}
						else
							cout << "Boyle Bir Kayit Bulunamamistir..." << endl;
					}
					break;
				}
				case 6:
				{
					cout << "  ((6- OKUYUCU ÜZERÝNDEKÝ KÝTAP LÝSTESÝNÝ SEÇTÝNÝZ)) " << endl;

					long long TC;

					cout << "Kitap Listesi Görüntüleneçek Okuyucu TC'si "; cin >> TC;

					ifstream DosyaOku("Okuyucu.txt");

					while (!DosyaOku.eof())//dosyayý sonunda kadar okunur 
					{
						DosyaOku >> TcNo >> Adi >> Soyadi >> UyeNumarasi
							>> DogumTarihi >> Telefon >> Meslegi >> AlabilecegiKitapSayisi;

						if (TC == TcNo)//girilen tc sistemdeki tc ile eþit ise okuyucunun sistemde mevcut olan bilgileri görüntülenir.
						{
							cout << "\n Okuyucu Bilgileri \n";
							cout << "TC no :" << TcNo << endl;
							cout << "Adý :" << Adi << endl;
							cout << "Soyadý :" << Soyadi << endl;
							cout << "Uye Numarasý:" << UyeNumarasi << endl;
							cout << " Dogum Tarihi :" << DogumTarihi << endl;
							cout << "Telefonu :" << Telefon << endl;
							cout << "Cinsiyeti:" << Meslegi << endl;
							cout << "Alabilecegi Kitap Sayisi:" << AlabilecegiKitapSayisi << endl;

							DosyaOku.close();

							ofstream DosyaYaz;
							DosyaOku.open("Odunc.txt", ios::in);
							cout << "\n Odunc Aldðý Kitap listesi \n " << endl;

							cout << setw(10) << " ISBN "<< setw(10) <<"TcNo " << setw(12) << "oduncTarihi" << setw(12) << "donusTarihi" << endl;

							while (!DosyaOku.eof())//dosyayý sonunda kadar okur 
							{
								DosyaOku >> ISBN >> TcNo >> oduncTarihi >> donusTarihi;

								if (TC == TcNo)//girilen tc ile sistemde mevcut olan tc var ise ekrana cout baskýsý alýnýr sütün þeklinde 
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

					cout << " ((7- KÝTAP EKLEMEYÝ SEÇTÝNÝZ.)) " << endl; 

					//menüden seçilen 7 sayýsý ile kitaplýga yeni kitap eklemesi yapýlabilir .
					do
					{
						ofstream DosyaYaz;
						DosyaYaz.open("Kitaplýk.txt", ios::app | ios::out | ios::in);

						cout << "\n KÝTAP ISBN :" << endl; cin >> ISBN;
						cout << "\n  KÝTAP ÝSMÝ :" << endl; cin >> KitapIsmi;
						cout << "\n YAZAR ADI :" << endl; cin >> YazarAdi;
						cout << "\n YAZAR SOYADI:" << endl; cin >> YazarSoyadi;
						cout << "\n  TÜR :" << endl; cin >> Tur;
						cout << "\n KONUSU :" << endl; cin >> Konusu;
						cout << "\n  KÝTABIN SAYFA SAYISI :" << endl; cin >> SayfaSayisi;
					
						DosyaYaz << ISBN << ' ' << KitapIsmi << ' ' << YazarAdi << ' '
							<< YazarSoyadi << ' ' << Tur << ' ' << Konusu << ' ' << SayfaSayisi << endl;
						
						cout << "\n BAÞKA KÝTAP KAYIDI YAPACAK MISINIZ ?(e/E) (h/H) "; cin >> cevap;
						DosyaYaz.close();
					} while (cevap == 'e' || cevap == 'E');

					cout << "KÝTAP EKLEME TAMAMLANDI." << endl;
					break;
				}
				case 8:
				{
					cout << "  ((8- KÝTAP KAYDI SÝLMEYÝ SEÇTÝNÝZ.))" << endl;
					string ISBNNo;
					cout << "SÝLMEK ÝSTEDÝGÝNÝZ KÝTABIN ISBN NUMARASINI GÝRÝNÝZ:"; cin >> ISBNNo;
					ifstream DosyaOku("Kitaplýk.txt");
					ofstream DosyaYaz("GEÇÝÇÝ KÝTAPLIK.tmp"); //Gecici bir dosya açýlýr
					while (DosyaOku >> ISBN >> KitapIsmi >> YazarAdi >> YazarSoyadi >> Tur >> Konusu >> SayfaSayisi) //DosyaOku da belirttiðim Kitaplýk.txt dosyasýný sonuna kadar okuttum.
					{

						if (ISBNNo == ISBN) //Girilen ISBN no  kayýtlarda var ise kitap kaydýný görüntüler.
						{
							cout << "\n KÝTAP ISBN :" << ISBN << endl;;
							cout << "\n  KÝTAP ÝSMÝ :" << KitapIsmi << endl;;
							cout << "\n YAZAR ADI :" << YazarAdi << endl;;
							cout << "\n YAZAR SOYADI:" << YazarSoyadi << endl;;
							cout << "\n  TÜR :" << Tur << endl;;
							cout << "\n KONUSU :" << Konusu << endl;;
							cout << "\n  KÝTABIN SAYFA SAYISI :" << SayfaSayisi << endl;  "\n";  //Eðer Koþulu Saðlayan Bilgi Varsa Onu Ekranda Gösterir
							cout << "KÝTAP SÝLME ÝÞLEMÝ GERÇEKLEÞMÝÞTÝR" << endl;

						}
						else
							DosyaYaz << "\n" << ISBN << " " << KitapIsmi << " " << YazarAdi << " " << Tur << " " << Konusu << " " << SayfaSayisi;
					}
					DosyaYaz.close();
					DosyaOku.close();
					remove ("Kitaplýk.txt"); //dosyayi sildim.
					rename ("GEÇÝÇÝ KÝTAPLIK.tmp", "Kitaplýk.txt"); //Gecici dosyalar kayýt silindikten tmp dosyasi txt dosyasina aktarýlýr.
					break;
				}
				case 9:
				{
					string KitapSorgu_ISBN;
					cout << " ((9- KÝTAP DÜZENLEMEYÝ SEÇTÝNÝZ ))" << endl;

					cout << " ISBN Numarasi:"; cin >> KitapSorgu_ISBN; // Düzenlenecek ISBN Nosunu sorgulattým.
					int gcc = 0;

					ifstream DosyaOku("Kitaplýk.txt"); //Dosya çýkýþý yapabilmek için gerekli kodu yazdým.
					ofstream DosyaYaz("geçiçi.tmp");//gecici.tmp adýmda dosya oluþturup dosya ekleme modunda açtým
					

					while (DosyaOku >> ISBN >> KitapIsmi >> YazarAdi >> YazarSoyadi >> Tur >> Konusu >> SayfaSayisi) //DosyaOku da belirttiðim Kitaplýk.txt dosyasýný sonuna kadar okuttum.
					{

						if (KitapSorgu_ISBN == ISBN ) //Sorgulanan ISBN numarasý varsa Kitap bilgilerini gösterir.
						{
							cout << "\n KÝTAP ISBN :" << ISBN << endl;;
							cout << "\n  KÝTAP ÝSMÝ :" << KitapIsmi << endl;;
							cout << "\n YAZAR ADI :" << YazarAdi << endl;;
							cout << "\n YAZAR SOYADI:" << YazarSoyadi << endl;;
							cout << "\n  TÜR :" << Tur << endl;;
							cout << "\n KONUSU :" << Konusu << endl;;
							cout << "\n  KÝTABIN SAYFA SAYISI :" << SayfaSayisi << endl;

							cout << "\n KÝTAP ISBN :" << endl; cin >> ISBN;
							cout << "\n  KÝTAP ÝSMÝ :" << endl; cin >> KitapIsmi;
							cout << "\n YAZAR ADI :" << endl; cin >> YazarAdi;
							cout << "\n YAZAR SOYADI:" << endl; cin >> YazarSoyadi;
							cout << "\n  TÜR :" << endl; cin >> Tur;
							cout << "\n KONUSU :" << endl; cin >> Konusu;
							cout << "\n KÝTABIN SAYFA SAYISI :" << endl; cin >> SayfaSayisi;

							DosyaYaz << ISBN << " " << KitapIsmi << ' ' << YazarAdi << ' ' << YazarSoyadi << ' '
								<< Tur << ' ' << Konusu << ' ' << SayfaSayisi << "\n"; //Düzenlenen dosya bilgileri yazdýrýlýr.

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
					remove("Kitaplýk.txt");// Kitaplýk.txt dosyasý silinirken
					rename("geçiçi.tmp", "Kitaplýk.txt");//gecici.tmp dosyasý Kitaplýk.txt dosyasý olarak deðiþtirirlir.
					break;
				}
				}
				cout << "Ýslem yapmaya devam etmek istiyor musunuz? (e/E) (h/H)";
				cin >> islem;
			} while (islem == 'e' || islem == 'E'); //Ýþlemi yaptýktan sonra karþýmýza tekrar menü çýkmasýný saðlýyor	
			cout << endl;

			sonuc = 1;
		}


	}

	if (sonuc == 0)
	{
		//Sonuç ilk önce 0 a eþit .Ancak Kullanýcý Adi ve Þifresi girilen degerler eþit ise koþul sonunda sonuç =1 olur ve kullanýcý sisteme giriþ yapar
		//Eðer eþit degilse kullanýcý bu if bloguna yönlendirilir.
		cout << "Degerli Okurumuz Kullanýcý Adýnýzý veya Kullanýcý Þifrenizi Hatalý Giridiniz\n " << endl;

	}
	kullanOku.close();



	auto finish = chrono::system_clock::now();
	auto simdibitis = chrono::system_clock::to_time_t(finish);
	char cikisSaat[30];
	ctime_s(cikisSaat, sizeof(cikisSaat), &simdibitis);
	cout << "\n Çýkýþ Saati:" << cikisSaat << "\n";

}


