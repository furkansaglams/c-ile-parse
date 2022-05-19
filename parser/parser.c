#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
AD:FURKAN
SOYAD:SAÐLAM
NUMARA:02200201017
1.ÖÐRETÝM 2.SINIF
*/
// KODUN CALÝSMASÝ: KOD PARSE EDÝLÝR EGER KOD DOGRU ÝSE KODUN DOGRU OLDUGUNA DAÝR BÝR ÇIKTI YAZILIR EGER KOD HATALÝ ÝSE KODUN DOGRU
//OLAN KISMINA KADAR YAZILIR ÝLK HATALI KELÝMENÝN  BULUNDUGU YERE DE HATALÝ KELÝME BURDA DÝYE BÝR ÇIKTI YAZILIR O DA HATALI KELÝMENÝN BASLANGICINI BELÝRTÝR.
//ORNEK:if(a=b) EKRAN CIKTISI:if(a -->burdan sonraki ilk kelime hatali BOYLELÝKLE HATALI KELÝMENÝN YERÝ TESPÝT EDÝLMÝS OLUR. 
//NOT: ; KONTROLUNU  KODA DAHÝL ETMEDÝM ALÝ HOCA EKLEMEZSENÝZ PROBLEM OLMAZ DEDÝGÝ ÝCÝN
//NOT:HATA ACIKLAMASI GRAMER YAPISINA GORE ACIKLANMISTIR.
//NOT: kelimelestirmenin yazdýrýlmasý { } arasýna yapýlmaktadýr koddaki } ile karýstýrmayýnýz.
//kodda hem tokenizer hem parse oldugunda parser ile alakalý olan kýsýmlara parser diye ekledim daha rahata anlasilmasi icin
//yorum satýrlarýný numaralandýrýrak yaptým her numara "//" arasýný ifade edicek tokenizer icin boyle parse icin direk yorum satiri ekledim

void yanlis(char dizigonder[],int son) //parse bu kýsýmda kodda herhangi bir hata olmasý durumunda yazdýrma islemi icin bu fonksiyonu yazdým
{
	int i;
	printf("\n\n***************************************************************************\n\n");
	for(i=0;i<son;i++)
	{
		printf("%c",dizigonder[i]);
	}
	printf(" --> burdan sonraki ilk kelime hatali");
	printf("\n\n***************************************************************************\n");
}
void dogru()//parser bu kýsýmda kodda dogru olmasý durumunda yazdýrma islemi icin bu fonksiyonu yazdým
{
	printf("\n***************************************************************************\n");
	printf("                   SONUC: KODUNUZ DOGRU");
	printf("\n***************************************************************************\n");
	
}
int elseifmi(char dizigonder[], int baslangic){//parser (else if) kelimesinin dogrulugunu kontrol etmek icin yazdim. (else if) yazýmýnda hata var ise false degeri donmektedir. 
	int i;
	int j = 0;
	bool deger = true;
	char elseifdizisi[6] = { 'e', 'l', 's', 'e', 'i', 'f' };
	for (i = 0; i < 6; i++){
		if (elseifdizisi[i] != dizigonder[baslangic + i + 1]){
			deger = false;
		}
	}
	if (deger == true){
		return baslangic + 7;// parser 7 eklememin nedeni elseif kelimesinin 6 karakter olmasý 7.karakterin ( parantez olup olmadýgýný anlamak icin bu degeri return ettim
	}
	else{
		return 0;
	}
}
int elsemi(char dizigonder[], int baslangic){//parser (else) kelimesinin dogrulugunu kontrol etmek icin yazdim.(else) yazýmýnda hata var ise false degeri donmektedir.
	int i;
	int j = 0;
	bool deger = true;
	char elsedizisi[4] = { 'e', 'l', 's', 'e' };
	for (i = 0; i < 4; i++){
		if (elsedizisi[i] != dizigonder[baslangic + i + 1]){
			deger = false;
		}
	}
	if (deger == true){
		return baslangic + 5;// parser 5 eklememin nedeni else kelimesinin 4 karakter olmasý 5.karakterin { parantez olup olmadýgýný anlamak icin bu degeri return ettim
	}
	else{
		return 0;
	}
}
bool harfmi(char eleman){//parser Gramerdeki harflerin dogrulugunu kontrol etmek icin yazdim.Eger hatali harf var ise false donmektedir
	int j;
	bool dogrumu = false;
	char id[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	for (j = 0; j < 6; j++){
		if (eleman == id[j]){
			dogrumu = true;// parser hatalý harf yok ise dogrumu degeri true olavcaktýr.Aksi takdirde baslangýcta false oldugu icin false olarak kalýp if icine hic girmeyecektir boylelikle hatalý harf tespit edilmis olucaktýr.
		}
	}
	return dogrumu;
}
bool rakammi(char eleman){//parser Gramerdeki rakamlarýn dogrulugunu kontrol etmek icin yazdim.Eger hatali rakam var ise false donmektedir
	int j;
	bool dogrumu = false;
	char rakam[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	for (j = 0; j < 10; j++){
		if (eleman == rakam[j]){
			dogrumu = true;//parser hatalý harf yok ise dogrumu degeri true olavcaktýr.Aksi takdirde baslangýcta false oldugu icin false olarak kalýp if icine hic girmeyecektir boylelikle hatalý harf tespit edilmis olucaktýr.
		}
	}
	return dogrumu;
}
bool cumlekontrol(char dizigonder[], int baslangic, int son)// parser Gramerdeki cumle kuralýný test etmek icin bu fonksiyonu yazdým.Cumle icerdindeki hatalý kelime olmasý durumunda false degeri donmektedir.
{
	int i;
	int cumlegecici;
	for (i = baslangic; i < son; i++){
		if (harfmi(dizigonder[baslangic]) == true){
			if (dizigonder[baslangic + 1] == '='){
				if (harfmi(dizigonder[baslangic + 2]) == true){
					if (dizigonder[baslangic + 3] == '+'){
						if (harfmi(dizigonder[baslangic + 4]) == true){//parser burasý cumle icerisindek {<id>(harf)=<id>(harf+  dan  sonra harfin dogruluguna bakmaktadýr asgýdaki diger yapýlarda benzer bicimde calýsmaktadýr.
							if (dizigonder[baslangic + 5] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(harf)+<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALI");
								yanlis(dizigonder,baslangic+5);
								return false;
							}
						}
						else if (rakammi(dizigonder[baslangic + 4]) == true){
							cumlegecici = baslangic + 4;
							while (rakammi(dizigonder[cumlegecici]) == true){ //parser eger rakam geldiyse ne kadar geldigini belirlemek icin yazýldý (birden fazla basamak var ise son bsamaga kadar gitmek icin yapýldý).
								cumlegecici++;
							}
							if (dizigonder[cumlegecici] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(harf)+<id>(sayi) den sonra } parantez olmak zorundadir.KODUNUZ HATALI");
								yanlis(dizigonder,cumlegecici);
								return false;
							}
						}
						else if ((harfmi(dizigonder[baslangic + 4]) != true) && (rakammi(dizigonder[baslangic + 4]) != true)){
							printf("\n\nHATA:<id>(harf)=<id>(harf)+ dan sonra <id> kullanmalisiniz.KODUNUZ HATALI ");
							yanlis(dizigonder,baslangic+4);
							return false;
						}
					}
					else if (dizigonder[baslangic + 3] == '-'){
						if (harfmi(dizigonder[baslangic + 4]) == true){
							if (dizigonder[baslangic + 5] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(harf)-<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALI");
								yanlis(dizigonder,baslangic+5);
								return false;
							}
						}
						else if (rakammi(dizigonder[baslangic + 4]) == true){
							cumlegecici = baslangic + 4;
							while (rakammi(dizigonder[cumlegecici]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(harf)-<id>(sayi) den sonra } parantez olmak zorundadir.KODUNUZ HATALI");
								yanlis(dizigonder,cumlegecici);
								return false;
							}
						}
						else if ((harfmi(dizigonder[baslangic + 4]) != true) && (rakammi(dizigonder[baslangic + 4]) != true)){
							printf("\n\nHATA:<id>(harf)=<id>(harf)- dan sonra <id> kullanmalisiniz.KODUNUZ HATALI ");
							yanlis(dizigonder,baslangic+4);
							return false;
						}
					}
					else if (dizigonder[baslangic + 3] == '*'){
						if (harfmi(dizigonder[baslangic + 4]) == true){
							if (dizigonder[baslangic + 5] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(harf)*<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALI");
								yanlis(dizigonder,baslangic+5);
								return false;
							}
						}
						else if (rakammi(dizigonder[baslangic + 4]) == true){
							cumlegecici = baslangic + 4;
							while (rakammi(dizigonder[cumlegecici]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici] == '}'){
								return true;
							}
							else{
						     	printf("\n\nHATA:<id>(harf)=<id>(harf)*<id>(sayi) den sonra } parantez olmak zorundadir.KODUNUZ HATALI");
								yanlis(dizigonder,cumlegecici);
								return false;
							}
						}
						else if ((harfmi(dizigonder[baslangic + 4]) != true) && (rakammi(dizigonder[baslangic + 4]) != true)){
							printf("\n\nHATA:<id>(harf)=<id>(harf)* dan sonra <id> kullanmalisiniz.KODUNUZ HATALI ");
							yanlis(dizigonder,baslangic+4);
							return false;
						}
					}
					else if (dizigonder[baslangic + 3] == '/'){
						if (harfmi(dizigonder[baslangic + 4]) == true){
							if (dizigonder[baslangic + 5] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(harf)/<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALI");
								yanlis(dizigonder,baslangic+5);
								return false;
							}
						}
						else if (rakammi(dizigonder[baslangic + 4]) == true){
							cumlegecici = baslangic + 4;
							while (rakammi(dizigonder[cumlegecici]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(harf)/<id>(sayi) den sonra } parantez olmak zorundadir.KODUNUZ HATALI");
								yanlis(dizigonder,cumlegecici);
								return false;
							}
						}
						else if ((harfmi(dizigonder[baslangic + 4]) != true) && (rakammi(dizigonder[baslangic + 4]) != true)){
							printf("\n\nHATA:<id>(harf)=<id>(harf)/ dan sonra <id> kullanmalisiniz.KODUNUZ HATALI ");
							yanlis(dizigonder,baslangic+4);
							return false;
						}
					}
					else if (dizigonder[baslangic + 3] == '}'){
						return true;
					}
					else{
						printf("\n\nHATA:<id>(harf)=<id>(harf) den sonra } parantez kullanmak zorundasiniz.KODUNUZ HATALI");
						yanlis(dizigonder,baslangic+3);
						return false;
					}
				}
				else if (rakammi(dizigonder[baslangic + 2]) == true){
					cumlegecici = baslangic + 2;
					while (rakammi(dizigonder[cumlegecici]) == true){
						cumlegecici++;
					}
					if (dizigonder[cumlegecici] == '+'){
						if (harfmi(dizigonder[cumlegecici + 1]) == true){
							if (dizigonder[cumlegecici + 2] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(sayi)+<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+2);
								return false;
							}
						}
						else if (rakammi(dizigonder[cumlegecici + 1]) == true){
							while (rakammi(dizigonder[cumlegecici + 1]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici + 1] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(sayi)+<id>(sayi) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+1);
								return false;
							}
						}
						else if ((harfmi(dizigonder[cumlegecici + 1]) != true) && (rakammi(dizigonder[cumlegecici + 1]) != true)){
							printf("\n\nHATA:<id>(harf)=<id>(sayi)+ dan sonra <id> kullanmalisiniz.KODUNUZ HATALIDIR ");
							yanlis(dizigonder,cumlegecici+1);
							return false;
						}
					}
					else if (dizigonder[cumlegecici] == '-'){
						if (harfmi(dizigonder[cumlegecici + 1]) == true){
							if (dizigonder[cumlegecici + 2] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(sayi)-<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+2);
								return false;
							}
						}
						else if (rakammi(dizigonder[cumlegecici + 1]) == true){
							while (rakammi(dizigonder[cumlegecici + 1]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici + 1] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(sayi)-<id>(sayi) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+1);
								return false;
							}
						}
						else if ((harfmi(dizigonder[cumlegecici + 1]) != true) && (rakammi(dizigonder[cumlegecici + 1]) != true)){
							printf("\n\nHATA:<id>(harf)=<id>(sayi)- dan sonra <id> kullanmalisiniz.KODUNUZ HATALIDIR ");
							yanlis(dizigonder,cumlegecici+1);
							return false;
						}
					}
					else if (dizigonder[cumlegecici] == '*'){
						if (harfmi(dizigonder[cumlegecici + 1]) == true){
							if (dizigonder[cumlegecici + 2] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(sayi)*<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+2);
								return false;
							}
						}
						else if (rakammi(dizigonder[cumlegecici + 1]) == true){
							while (rakammi(dizigonder[cumlegecici + 1]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici + 1] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(sayi)*<id>(sayi) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+1);
								return false;
							}
						}
						else if ((harfmi(dizigonder[cumlegecici + 1]) != true) && (rakammi(dizigonder[cumlegecici + 1]) != true)){
							printf("\n\nHATA:<id>(harf)=<id>(sayi)* dan sonra <id> kullanmalisiniz.KODUNUZ HATALIDIR ");
							yanlis(dizigonder,cumlegecici+1);
							return false;
						}
					}
					else if (dizigonder[cumlegecici] == '/'){
						if (harfmi(dizigonder[cumlegecici + 1]) == true){
							if (dizigonder[cumlegecici + 2] == '}'){
								return true;
							}
							else{
							    printf("\n\nHATA:<id>(harf)=<id>(sayi)/<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+2);
								return false;
							}
						}
						else if (rakammi(dizigonder[cumlegecici + 1]) == true){
							while (rakammi(dizigonder[cumlegecici + 1]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici + 1] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)=<id>(sayi)/<id>(sayi) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+1);
								return false;
							}
						}
						else if ((harfmi(dizigonder[cumlegecici + 1]) != true) && (rakammi(dizigonder[cumlegecici + 1]) != true)){
							printf("\n\nHATA:<id>(harf)=<id>(sayi)/ dan sonra <id> kullanmalisiniz.KODUNUZ HATALIDIR ");
							yanlis(dizigonder,cumlegecici+1);
							return false;
						}
					}
					else if (dizigonder[cumlegecici] == '}'){
						return true;
					}
					else{
						printf("\n\nHATA:<id>(harf)=<id>(sayi) den sonra } parantez kullanmak zorundasiniz.KODUNUZ HATALIDIR");
						yanlis(dizigonder,cumlegecici);
						return false;
					}
				}
				else if ((harfmi(dizigonder[baslangic + 2]) != true && (rakammi(dizigonder[baslangic + 2]) != true))){
					printf("\n\nHATA:<id>(harf)= esittirden sonra rakam ya da harf kullanmak zorundasiniz.KODUNUZ HATALIDIR ");
					yanlis(dizigonder,baslangic+2);
					return false;
				}
			}
			else{
				printf("\n\nHATA: {  parantezden sonraki <id> den sonra = gelmek zorunda");
				yanlis(dizigonder,baslangic+1);
				return false;
			}
		}
		else if (rakammi(dizigonder[baslangic]) == true){
			cumlegecici = baslangic;
			while (rakammi(dizigonder[cumlegecici]) == true){
				cumlegecici++;
			}
			if (dizigonder[cumlegecici] == '='){
				if (harfmi(dizigonder[cumlegecici + 1]) == true){
					if (dizigonder[cumlegecici + 2] == '+'){
						if (harfmi(dizigonder[cumlegecici + 3]) == true){
							if (dizigonder[cumlegecici + 4] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(harf)+<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+4);
								return false;
							}
						}
						else if (rakammi(dizigonder[cumlegecici + 3]) == true){
							while (rakammi(dizigonder[cumlegecici + 3]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici + 3] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(harf)+<id>(sayi) den sonra } parantez kullanmak zorundasiniz.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+3);
								return false;
							}
						}
						else if ((harfmi(dizigonder[cumlegecici + 3]) != true) && (rakammi(dizigonder[cumlegecici + 3]) != true)){
							printf("\n\nHATA: <id>(sayi)=<id>(harf)+ dan sonra <id> kullanmalisiniz.KODUNUZ HATALIDIR");
							yanlis(dizigonder,cumlegecici+3);
							return false;
						}
					}
					else if (dizigonder[cumlegecici + 2] == '-'){
						if (harfmi(dizigonder[cumlegecici + 3]) == true){
							if (dizigonder[cumlegecici + 4] == '}'){
								return true;
							}
							else{
							    printf("\n\nHATA:<id>(sayi)=<id>(harf)-<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+4);
								return false;
							}
						}
						else if (rakammi(dizigonder[cumlegecici + 3]) == true){
							while (rakammi(dizigonder[cumlegecici + 3]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici + 3] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(harf)-<id>(sayi) den sonra } parantez kullanmak zorundasiniz.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+3);
								return false;
							}
						}
						else if ((harfmi(dizigonder[cumlegecici + 3]) != true) && (rakammi(dizigonder[cumlegecici + 3]) != true)){
							printf("\n\nHATA: <id>(sayi)=<id>(harf)- dan sonra <id> kullanmalisiniz.KODUNUZ HATALIDIR");
							yanlis(dizigonder,cumlegecici+3);
							return false;
						}
					}
					else if (dizigonder[cumlegecici + 2] == '*'){
						if (harfmi(dizigonder[cumlegecici + 3]) == true){
							if (dizigonder[cumlegecici + 4] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(harf)*<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+4);
								return false;
							}
						}
						else if (rakammi(dizigonder[cumlegecici + 3]) == true){
							while (rakammi(dizigonder[cumlegecici + 3]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici + 3] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(harf)*<id>(sayi) den sonra } parantez kullanmak zorundasiniz.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+3);
								return false;
							}
						}
						else if ((harfmi(dizigonder[cumlegecici + 3]) != true) && (rakammi(dizigonder[cumlegecici + 3]) != true)){
							printf("\n\nHATA: <id>(sayi)=<id>(harf)* dan sonra <id> kullanmalisiniz.KODUNUZ HATALIDIR");
							yanlis(dizigonder,cumlegecici+3);
							return false;
						}
					}
					else if (dizigonder[cumlegecici + 2] == '/'){
						if (harfmi(dizigonder[cumlegecici + 3]) == true){
							if (dizigonder[cumlegecici + 4] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(harf)/<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+4);
								return false;
							}
						}
						else if (rakammi(dizigonder[cumlegecici + 3]) == true){
							while (rakammi(dizigonder[cumlegecici + 3]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici + 3] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(harf)/<id>(sayi) den sonra } parantez kullanmak zorundasiniz.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+3);
								return false;
							}
						}
						else if ((harfmi(dizigonder[cumlegecici + 3]) != true) && (rakammi(dizigonder[cumlegecici + 3]) != true)){
							printf("\n\nHATA: <id>(sayi)=<id>(harf)/ dan sonra <id> kullanmalisiniz.KODUNUZ HATALIDIR");
							yanlis(dizigonder,cumlegecici+3);
							return false;
						}
					}
					else if (dizigonder[cumlegecici + 2] == '}'){
						return true;
					}
					else{
						printf("\n\nHATA:<id>(sayi)=<id>(harf) den sonra } parantez kullanmak zorundasiniz.KODUNUZ HATALIDIR");
						yanlis(dizigonder,cumlegecici+2);
						return false;
					}
				}
				else if (rakammi(dizigonder[cumlegecici + 1]) == true){
					while (rakammi(dizigonder[cumlegecici + 1]) == true){
						cumlegecici++;
					}
					if (dizigonder[cumlegecici + 1] == '+'){
						if (harfmi(dizigonder[cumlegecici + 2]) == true){
							if (dizigonder[cumlegecici + 3] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(sayi)+<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+3);
								return false;
							}
						}
						else if (rakammi(dizigonder[cumlegecici + 2]) == true){
							while (rakammi(dizigonder[cumlegecici + 2]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici + 2] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(sayi)+<id>(sayi) den sonra } parantez kullanmak zorundasiniz.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+2);
								return false;
							}
						}
						else if ((harfmi(dizigonder[cumlegecici + 2]) != true) && (rakammi(dizigonder[cumlegecici + 2]) != true)){
							printf("\n\nHATA:<id>(sayi)=<id>(sayi)+ dan sonra <id> kullanmalisiniz.KODUNUZ HATALIDIR ");
							yanlis(dizigonder,cumlegecici+2);
							return false;
						}
					}
					else if (dizigonder[cumlegecici + 1] == '-'){
						if (harfmi(dizigonder[cumlegecici + 2]) == true){
							if (dizigonder[cumlegecici + 3] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(sayi)-<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+3);
								return false;
							}
						}
						else if (rakammi(dizigonder[cumlegecici + 2]) == true){
							while (rakammi(dizigonder[cumlegecici + 2]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici + 2] == '}'){
								return true;
							}
							else{
						     	printf("\n\nHATA:<id>(sayi)=<id>(sayi)-<id>(sayi) den sonra } parantez kullanmak zorundasiniz.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+2);
								return false;
							}
						}
						else if ((harfmi(dizigonder[cumlegecici + 2]) != true) && (rakammi(dizigonder[cumlegecici + 2]) != true)){
							printf("\n\nHATA:<id>(sayi)=<id>(sayi)- dan sonra <id> kullanmalisiniz.KODUNUZ HATALIDIR ");
							yanlis(dizigonder,cumlegecici+2);
							return false;
						}
					}
					else if (dizigonder[cumlegecici + 1] == '*'){
						if (harfmi(dizigonder[cumlegecici + 2]) == true){
							if (dizigonder[cumlegecici + 3] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(sayi)*<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+3);
								return false;
							}
						}
						else if (rakammi(dizigonder[cumlegecici + 2]) == true){
							while (rakammi(dizigonder[cumlegecici + 2]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici + 2] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(sayi)*<id>(sayi) den sonra } parantez kullanmak zorundasiniz.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+2);
								return false;
							}
						}
						else if ((harfmi(dizigonder[cumlegecici + 2]) != true) && (rakammi(dizigonder[cumlegecici + 2]) != true)){
							printf("\n\nHATA:<id>(sayi)=<id>(sayi)* dan sonra <id> kullanmalisiniz.KODUNUZ HATALIDIR ");
							yanlis(dizigonder,cumlegecici+2);
							return false;
						}
					}
					else if (dizigonder[cumlegecici + 1] == '/'){
						if (harfmi(dizigonder[cumlegecici + 2]) == true){
							if (dizigonder[cumlegecici + 3] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(sayi)/<id>(harf) den sonra } parantez olmak zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+3);
								return false;
							}
						}
						else if (rakammi(dizigonder[cumlegecici + 2]) == true){
							while (rakammi(dizigonder[cumlegecici + 2]) == true){
								cumlegecici++;
							}
							if (dizigonder[cumlegecici + 2] == '}'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(sayi)=<id>(sayi)/<id>(sayi) den sonra } parantez kullanmak zorundasiniz.KODUNUZ HATALIDIR");
								yanlis(dizigonder,cumlegecici+2);
								return false;
							}
						}
						else if ((harfmi(dizigonder[cumlegecici + 2]) != true) && (rakammi(dizigonder[cumlegecici + 2]) != true)){
						    printf("\n\nHATA:<id>(sayi)=<id>(sayi)/ dan sonra <id> kullanmalisiniz.KODUNUZ HATALIDIR ");
							yanlis(dizigonder,cumlegecici+2);
							return false;
						}
					}
					else if (dizigonder[cumlegecici + 1] == '}'){
						return true;
					}
					else{
						printf("\n\nHATA:<id>(sayi)=<id>(sayi) den sonra } parantez kullanmak zorundasiniz.KODUNUZ HATALIDIR");
						yanlis(dizigonder,cumlegecici+1);
						return false;
					}
				}
				else if ((rakammi(dizigonder[cumlegecici + 1]) != true) && ((harfmi(dizigonder[cumlegecici + 1]) != true))){
					printf("\n\nHATA: <id>(sayi)= den sonra id kullanmak zorundasiniz.KODUNUZ HATALIDIR");
					yanlis(dizigonder,cumlegecici+1);
					return false;
				}
			}
			else{
				printf("\nHATA: {  parantezden sonraki<id> den sonra = gelmek zorunda.KODUNUZ HATALIDIR");
				yanlis(dizigonder,cumlegecici);
				return false;
			}
		}
		else if ((harfmi(dizigonder[baslangic]) != true) && (rakammi(dizigonder[baslangic]) != true)){
			printf("\nHATA:{ parantezden sonra ya harf ya da sayi kullanmalisiniz.KODUNUZ HATALIDIR");
			yanlis(dizigonder,baslangic);
			return false;
		}
	}
}
bool sartkontrol(char dizigonder[], int baslangic, int son) // parser Gramerdeki sart kuralýný test etmek icin bu fonksiyonu yazdým.Sart icerdindeki hatalý kelime olmasý durumunda false degeri donmektedir.
{
	int i;
	bool forbitir = true;
	int gecici = baslangic;
	int gecicirakam;
	for (i = baslangic; i < son && forbitir == true; i++){
		if (harfmi(dizigonder[baslangic]) == true){
			if (dizigonder[baslangic + 1] == '<' || dizigonder[baslangic + 1] == '>' ||//<op> sart icersindeki olasý <op> degerleri.
				(dizigonder[baslangic + 1] == '<' && dizigonder[baslangic + 2] == '=') ||
				(dizigonder[baslangic + 1] == '>' && dizigonder[baslangic + 2] == '=') ||
				(dizigonder[baslangic + 1] == '=' && dizigonder[baslangic + 2] == '=')){
				if ((dizigonder[baslangic + 1] == '=' && dizigonder[baslangic + 2] == '>') || (dizigonder[baslangic + 1] == '=' && dizigonder[baslangic + 2] == '<')){ //<op> kýsmýnda ozel bir hata olan(=> ve =<) kullaným olursa onu engellemek icin yazdým.(ozel bir durumu kontrol ediyor)
					printf("\n\nHATA:noperand kullanimini dogru bir bicimde yapiniz(<= gibi).KODUNUZ HATALIDIR");
					return false;
				}
				else{
					if (dizigonder[baslangic + 2] == '='){// parser Bu kontrolu yapmamýn nedeni <= == >= gibi iki karakter barýndýran durumlarý ayrý < > gibi durumlarý ayrý kontrol etmek icin yaptým cunku birinde iki karakter var digerinde tek karakter bu ayýrdým icin yapýldý.Bu kýsým <= >= == durumunu(iki karakter) kontrol etmekte.
						if (harfmi(dizigonder[baslangic + 3]) == true){ //parse burasý sart iceridindeki (<id>(harf)= den  sonra harfin dogruluguna bakmaktadýr asagýdaki diger yapýlarda benzer bicimde calýsmaktadýr.
							if (dizigonder[baslangic + 4] == ')'){
								return true;
							}
							else{
								printf("\n\nHATA:\<id>(harf)<op><id>(harf) den sonra ) parantez gelmek zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,baslangic+4);
								return false;
							}
						}
						else if (rakammi(dizigonder[baslangic + 3]) == true){
							gecici = baslangic + 3;
							while (rakammi(dizigonder[gecici]) == true){
								gecici++;
							}
							if (dizigonder[gecici] == ')'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)<op><id>(sayi)  dan sonra ) parantez gelmek zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,gecici);
								return false;
							}
						}
						else if ((harfmi(dizigonder[baslangic + 3]) != true) && (rakammi(dizigonder[baslangic + 3]) != true)){
							printf("\n\nHATA: <id>(harf)<op> dan sonra rakam veya harf gelmeli.KODUNUZ HATALIDIR");
							yanlis(dizigonder,baslangic+3);
							return false;
						}
					}
					else{
						if (harfmi(dizigonder[baslangic + 2]) == true){//parser burasý <  > gibi (tek kelimelik) durum kontrolu icin yapýldý.
							if (dizigonder[baslangic + 3] == ')'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)<op><id>(harf) den sonra ) parantez gelmek zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,baslangic+3);
								return false;
							}
						}
						else if (rakammi(dizigonder[baslangic + 2]) == true){
							gecici = baslangic + 2;
							while (rakammi(dizigonder[gecici]) == true){
								gecici++;
							}
							if (dizigonder[gecici] == ')'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(harf)<op><id>(sayi)  dan sonra ) parantez gelmek zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,gecici);
								return false;
							}
						}
						else if ((harfmi(dizigonder[baslangic + 2]) != true) && (rakammi(dizigonder[baslangic + 2]) != true)){
							printf("\n\nHATA:<id>(harf)<op> dan sonra rakam veya harf gelmeli.KODUNUZ HATALIDIR");
							yanlis(dizigonder,baslangic+2);
							return false;
						}
					}
				}
			}
			else{
				printf("\n\nHATA:<id>(harf) den sonra<op> kullanilmamis.KODUNUZ HATALIDIR");
				yanlis(dizigonder,baslangic+1);
				return false;
				forbitir = false;
			}
		}
		else if (rakammi(dizigonder[baslangic]) == true){
			while (rakammi(dizigonder[gecici]) == true){
				gecici++;
			}
			gecicirakam = gecici;
			if (dizigonder[gecicirakam] == '<' || dizigonder[gecicirakam] == '>' ||
				(dizigonder[gecicirakam] == '<' && dizigonder[gecicirakam + 1] == '=') ||
				(dizigonder[gecicirakam] == '>' && dizigonder[gecicirakam + 1] == '=') ||
				(dizigonder[gecicirakam] == '=' && dizigonder[gecicirakam + 1] == '=')){
				if ((dizigonder[gecicirakam] == '=' && dizigonder[gecicirakam + 1] == '>') || (dizigonder[gecicirakam] == '=' && dizigonder[gecicirakam + 1] == '<')){
					printf("\noperand kullanimini dogru bir bicimde yapiniz(<= gibi)");
					return false;
				}
				else{
					gecicirakam = gecici + 1;
					if (dizigonder[gecicirakam] == '='){
						if (rakammi(dizigonder[gecicirakam + 1]) == true){
							while (rakammi(dizigonder[gecicirakam + 1]) == true){
								gecicirakam++;
							}
							if (dizigonder[gecicirakam + 1] == ')'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(rakam)<op><id>(rakam) den sonra ) parantez gelmek zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,gecicirakam+1);
								return false;
							}
						}
						else if (harfmi(dizigonder[gecicirakam + 1]) == true){
							if (dizigonder[gecicirakam + 2] == ')'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(rakam)<op><id>(harf) den sonra ) parantez gelmek zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,gecicirakam+2);
								return false;
							}
						}
						else if (((harfmi(dizigonder[gecicirakam + 1]) != true) && (rakammi(dizigonder[gecicirakam + 1]) != true))){
							printf("\n\nHATA: <id>(rakam)<op> dan sonra rakam veya harf gelmeli.KODUNUZ HATALIDIR");
							yanlis(dizigonder,gecicirakam+1);
							return false;
						}
					}
					else{
						if (rakammi(dizigonder[gecicirakam]) == true){
							while (rakammi(dizigonder[gecicirakam]) == true){
								gecicirakam++;
							}
							if (dizigonder[gecicirakam] == ')'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(rakam)<op><id>(rakam) den sonra ) parantez gelmek zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,gecicirakam);
								return false;
							}
						}
						else if (harfmi(dizigonder[gecicirakam]) == true){
							if (dizigonder[gecicirakam + 1] == ')'){
								return true;
							}
							else{
								printf("\n\nHATA:<id>(rakam)<op><id>(harf) den sonra ) parantez gelmek zorundadir.KODUNUZ HATALIDIR");
								yanlis(dizigonder,gecicirakam+1);
								return false;
							}
						}
						else if (((harfmi(dizigonder[gecicirakam]) != true) && (rakammi(dizigonder[gecicirakam]) != true))){
							printf("\n\nHATA: <id>(rakam)<op> dan sonra rakam veya harf gelmeli.KODUNUZ HATALIDIR");
							yanlis(dizigonder,gecicirakam);
							return false;
						}
					}
				}
			}
			else{
				printf("\n\nHATA: <id>(rakam) dan sonra <op> kullanilmamis.KODUNUZ HATALIDIR");
				yanlis(dizigonder,gecicirakam);
				return false;
			}
			forbitir = false;
		}
		else if ((harfmi(dizigonder[baslangic]) != true) && (rakammi(dizigonder[baslangic]) != true)){
			printf("\n\nHATA: ( den sonra rakam veya harf kullanilmamis.KODUNUZ HATALIDIR");
			yanlis(dizigonder,baslangic);
			return false; 
		}
	}
}
void kaynakodyazdir(char dizi[], int diziboyut){ //txt di metindeki kaynak kodun yazýmý icin yapýldý.
	printf("  \nkaynak kodunuz:\n\n");
	int i;
	for (i = 0; i < diziboyut; i++){
		printf("%c", dizi[i]);
	}
	printf("\n\n");
	printf("kelimelestirilmis hali:\n\n");
}
//yorum satýrý 1 alttaki kodda ++ -- gibi kontrolleri yaptým çünkü bunlar ayrý ayrý olucak kavramlar deðil
//c de beraber yazýlan yapýlar oldugu için böyle bir þey yaptým ayrýca virgül atarken dogru virgül atabilmemi saðladý.
//bunlar özel durumlar oldugu için diziye atmak daha fazla iþleme neden olacaðý içi böyle tercih ettim
int ozeldurum(char karakter1, char karakter2)
{
	if (

		(karakter1 == '+' && karakter2 == '+') ||
		(karakter1 == '-' && karakter2 == '-') ||
		(karakter1 == '=' && karakter2 == '=') ||
		(karakter1 == '+' && karakter2 == '=') ||
		(karakter1 == '-' && karakter2 == '=') ||
		(karakter1 == '/' && karakter2 == '=') ||
		(karakter1 == '*' && karakter2 == '=') ||
		(karakter1 == '<' && karakter2 == '=') ||
		(karakter1 == '>' && karakter2 == '=') ||
		(karakter1 == '|' && karakter2 == '|') ||
		(karakter1 == '&' && karakter2 == '&') ||
		(karakter1 == '!' && karakter2 == '=') ||
		(karakter1 == '%' && karakter2 == '=') ||
		(karakter1 == '?' && karakter2 == '=')

){
		return (1);
	}
	else{
		return (0);
	}
}
//yorum satýrý 1 bitti
//yorum satýrý 2 alttaki kodda ayraç olup omadýgýný kontrol ettim dogru bir biçimde virgül atabilmek için
//bazýlarýný ascii olarak yazdým "'" kodun okunurlugu açýsýndan güzel olmadýgýndan bunun gibi örnekleri ascii olarak yazdým
//32=bosluk tusu   34="(çift týrnak)  39='(tektýrnak)
int ayrac(char karakter){
	char dizi[26] = { '+', '-', '*', '/', ',', ';', '>', '<', '[', ']', '{', '}', ')', '(', '=', '|', '&', 34, 39, '!', 92, ':', '?', '^', '%', '.' };
	int i = 0, deger = 0;
	bool fonksiyondancik = true;	// iki nedeni var 1.neden eger terminal'i bulursa deger=1 olucak ama hala devam edicek bir sonrakinde bulamayýnca deger 0 olucak ve hatalý çalýþýcak 2.neden ise buldugu anda diziye deam etmemesini saðlamak zaman kaybetmemesi için.
	while (i < 26 && fonksiyondancik == true){
		if (dizi[i] == karakter){
			deger = 1;
			fonksiyondancik = false;
		}
		else{
			deger = 0;
		}
		i++;
	}
	return deger;
}
int main(int argc, char *argv[]){
	FILE * okunacakdosya;
	char dosyayolu[100] = "";
	printf("---------------------------------------------------------------------------------\n");
	printf("NOT:Lutfen dosya yolunu girerken arada bosluk veya turkce karakter kullanmayin!!!\n");
	printf("---------------------------------------------------------------------------------\n");
	dongu:
	printf("Okunacak olan dosyanizin dosya yolunu giriniz: ");
	scanf("%s", &dosyayolu);
	okunacakdosya = fopen(dosyayolu, "r");
	char kelime[1000000], yenidizi[1000000];
	char karakter;
	int i = 0;
	//yorum satýrý 3 bu kod satýrýný dosyanýn sonuna kadar okumamý ve fgetc fonksiyonu ile karakter karakter okuyup bir karakter dizisine
	//atmaiþlemini gerçekleþtirdim .dosyayý okurken EOF kavramýný kullandým EOF txt metinin son harfini gösteren bir iþaretçi
	if (okunacakdosya != NULL){
		while (karakter != EOF){
			karakter = fgetc(okunacakdosya);
			kelime[i] = karakter;
			i += 1;
		}
	}
	else{
		printf("Dosya bulunamadi. \n");
		goto dongu;
	}
	kaynakodyazdir(kelime, i);
	// yorum satýrý 3 bitti
	// yorum satýrý 4 fgetc fonksiyonu bosluk tab enter tusunu da bir karakter olarak aldýgý için bunlarý dizide
	//kaydýrma yaparak bir nevi yok ettim yani karakter dizimde bosluk tab ve enter tuþlarýný kaldýrdým
	int k, j, bosluk = 0;
	for (k = 0; k < i - 1; k++){
		for (j = 0; j < i - 1; j++){
			if (kelime[j] == 32 || kelime[j] == 10 || kelime[j] == 9){
				bosluk++;
				while (j < i - 1){
					kelime[j] = kelime[j + 1];
					j++;
				}
			}
		}
	}
	//yorum satýrý 4 bitti
	//yorum satýrý 5 olasý bosluklarý garantilemek için yeni bir diziye bosluksuz halini attým
	int diziboyut = 0;
	for (j = 0; j < i - 1 - bosluk; j++){
		if (kelime[j] != 32){
			diziboyut++;
			yenidizi[j] = kelime[j];
		}
	}
	//yorum satýrý 5 bitti
	printf("{ ");	//dizi biçiminde gozukmesi için kelimlestirilmis halinin basýna ve sonuna {} eklemek icin yapýldý yani görunum icin yapýldý
	bool ayracmi, ozel, ikisonrasiayracmi, birsonrasiayracmi;
	int l = 0;
	for (l = 0; l < diziboyut; l++){
		ayracmi = ayrac(yenidizi[l]);	//karakter dizisinde eger bir terminal(;, " gibi degerlerin olup olmadýgýný kontrol ettim)
		birsonrasiayracmi = ayrac(yenidizi[l + 1]);	// virgül atarken iki ayraç yanayana gelirse tek bir virgül atmak gerekiyor sonrasýnýn ayraçolup olmadýgýný kontrol ettim
		ikisonrasiayracmi = ayrac(yenidizi[l + 2]);	// ++ -- gibi durumlarda bir sonrasýný kontrol ettiðimde + ve sonarsý da + yý kontrol etmiþ olurum buna gerek yok iki sonarsaýný yani ++ dan sonra bir terminal var mý ?
		if (l != diziboyut){
			ozel = ozeldurum(yenidizi[l], yenidizi[l + 1]);
		}
		if (ayracmi == 1){
			if (ozel == 1){
				if (ikisonrasiayracmi == 1){
					printf(",%c%c", yenidizi[l], yenidizi[l + 1]);	//örneðin ,++ yapýp sonrasý ayraç ise ,(, yapmalýyýz bunun için yazdým ==> ,++,(,
					l++;
				}
				else{
					if (l == diziboyut - 1){
						printf(",%c%c", yenidizi[l], yenidizi[l + 1]);	//en sonda 1 virgül fazladan atmamasý gerektiðinden yazdým
						l++;
					}
					else{
						printf(",%c%c,", yenidizi[l], yenidizi[l + 1]);
						l++;
					}
				}
			}
			else if (birsonrasiayracmi == 1){
				printf(",%c", yenidizi[l]);	//örnek); iki terminal yanyana gelirse baþýna ve sonuna virgül atarsak ,),,;, olacagý için yaptým
			}
			else{
				if (l == diziboyut - 1){
					printf(",%c", yenidizi[l]);	//sonda 1 virgül fazla dan oldugu için yapýldý
				}
				else{
					printf(",%c,", yenidizi[l]);
				}
			}
		}
		else{
			printf("%c", yenidizi[l]);	//eger terminal degilse oldugu gibi yazmasý için yapýldý
		}
	}
	printf("}");
	int diziesasboyut = (sizeof yenidizi / sizeof(float));
	//parser iþlemi buradan baslamaktadýr gerekli fonksiyonlarý main in dýsýnda yazdým
	int global;
	int kapananparantez;// parser son kapanan  parantezin degerini bulmak icin olusturuldu 
	int susluparantez;// parser son kapanan susluparantezin degerini bulmak icin olusturuldu
	bool forbitirr = true;//for dongusunde hata meydana gelmedigi ama for un  durmasý gereken anlar icin  boyle bir tanýmlama yaptým.
	bool kapananparantezvarmi = false;
	int cik = 0;
	bool ifdogrumu = false;
	bool hata = true;// parser olasý hatalarda for dongusunun sona erdirilmesini saglamak amacý ile yazýldý
	int birkere = 0;
	for (j = 0; j < i - 1 - bosluk && (hata == true && forbitirr == true); j++){
		if (birkere < 1){ // parser if kontrolu bir kere yapýlmasý ve her for dondugunde bu kontrolun tekrar tekrar yapmýlmamasý icin yapýldý.
			birkere++;
			int i = 0;
			char ifdizisi[2] = { 'i', 'f' };
			if (kelime[i] == ifdizisi[i] && kelime[i + 1] == ifdizisi[i + 1]){
				if (kelime[i + 2] != '('){ 
					hata = false;
					printf("\n\nHATA:if den sonra ( gelmek zorundadir.KODUNUZ HATALIDIR");
					yanlis(kelime,i+2);
				}
				else if (kelime[i + 3] == ')'){
					printf("\n\nHATA: if in () parantezler arasi bos olamaz.KODUNUZ HATALIDI");
					yanlis(kelime,i+3);
					hata = false;
				}
			
			}
			else{
				hata = false;
				printf("\n\nHATA:if yaziminda hata var.KODUNUZ HATALIDIR");
			}
		}
		
		else if (hata == true){
			kapananparantez = j;
			while (kelime[kapananparantez] != ')'){
				kapananparantez++;
			}
			if (sartkontrol(kelime, 3, kapananparantez) == true){
				if (kelime[kapananparantez + 1] == '{'){
					if (kelime[kapananparantez + 2] != '}'){
						susluparantez = kapananparantez + 1;
						while (kelime[susluparantez] != '}'){
							susluparantez++;
						}
						if (cumlekontrol(kelime, kapananparantez + 2, susluparantez) == true){
							if (elsemi(kelime, susluparantez) != 0 && elseifmi(kelime, susluparantez) == 0){
								int elsegeridon = elsemi(kelime, susluparantez);
								int gecicielsegeridon = elsegeridon + 1;
								if (kelime[elsegeridon] == '{'){
									if (kelime[elsegeridon + 1] != '}'){
										int gecicielsegeridon2 = elsegeridon + 1;
										while (kelime[elsegeridon + 1] != '}'){
											elsegeridon++;
										}
										if (cumlekontrol(kelime, gecicielsegeridon2, elsegeridon + 1) == true){
											if ((elsegeridon + 1) - (diziboyut - 1) == 0){
												dogru();
												forbitirr = false;
											}
											else{
												printf("\n\nHATA:elseden sonra bisey gelemez.KODUNUZ HATALIDIR");
												yanlis(kelime,elsegeridon+2);
												hata = false;
											}
										}
										else{
											hata = false;
										}
									}
									else{
										printf("\n\nHATA:else nin {} parantezler arasi bos kalamaz.KODUNUZ HATALIDIR");
										yanlis(kelime,elsegeridon+1);
										hata = false;
									}
								}
								else{
									printf("\n\nHATA:else den sonra { 	gelmeli.KODUNUZ HATALIDIR ");
									yanlis(kelime,elsegeridon);
									hata = false;
								}
								forbitirr = false;
							}
							else if (elseifmi(kelime, susluparantez) != 0){
								while (elseifmi(kelime, susluparantez) != 0 && hata == true){ // parser elseif degeri ya hic gelmeyecek ya da sonsuz defa gelebilecegi icin while dongusne aldým her while dondugunde susluparantez degeri guncellenmektedir.
									if (elseifmi(kelime, susluparantez) != 0){
										int bos = elseifmi(kelime, susluparantez);
										int geciciels = bos + 1;
										if (kelime[bos] == '('){
											if (kelime[bos + 1] != ')'){
												while (kelime[bos] != ')'){
													bos++;
												}
												if (sartkontrol(kelime, geciciels, bos) == true){
													if (kelime[bos + 1] == '{'){
														if (kelime[bos + 2] != '}'){
															int bas = bos + 2;
															while (kelime[bos + 2] != '}'){
																bos++;
															}
															if (cumlekontrol(kelime, bas, bos + 2) == true){
																susluparantez = bos + 2;// parser susluparantez degeri burada guncellenmektedir.
																global = susluparantez;
															}
															else{
																hata = false;
															}
														}
														else{
															printf("\n\nHATA:else if in {} arasi bos olamaz.KODUNUZ HATALIDIR");
															yanlis(kelime,bos+2);
															hata = false;
														}
													}
													else{
														printf("\n\nHATA:nelseif(<sart>) dan sonra {  parantez gelmek zorundadir.KODUNUZ HATALIDIR");
														yanlis(kelime,bos+1);
														hata = false;
													}
												}
												else{
													hata = false;
												}
											}
											else{
												printf("\n\nHATA:nelse if in () arasi bos olamaz.KODUNUZ HATALIDIR");
												yanlis(kelime,bos+1);
												hata = false;
											}
										}
										else{
											printf("\n\nHATA:elseif den sonra ( gelmek zorundadir.KODUNUZ HATALIDIR");
											yanlis(kelime,bos);
											hata = false;
										}
									}
								}
								if (elsemi(kelime, global) != 0 && hata == true){
									int elsegeridon = elsemi(kelime, susluparantez);
									int gecicielsegeridon = elsegeridon + 1;
									if (kelime[elsegeridon] == '{'){
										if (kelime[elsegeridon + 1] != '}'){
											int gecicielsegeridon2 = elsegeridon + 1;
											while (kelime[elsegeridon + 1] != '}'){
												elsegeridon++;
											}
											if (cumlekontrol(kelime, gecicielsegeridon2, elsegeridon + 1) == true){
												if ((elsegeridon + 1) - (diziboyut - 1) == 0){//parser bu yapý eger else if(<sart>){<cumle>} kýsmýndan sonrasýnýn bos olup olmadýgýný kontrol etmektedir(else if den sonra hicbir sey de gelmese hata olmayacagý icin boyle bir sey yapýldý) eger dizinin boyutu(txt metinin icinde yazýlanlar) ile else if in } parantez degeri esit ise bu demek olur ki else if den sonra bisey yazýlmamýs.
													dogru();
													forbitirr = false;
												}
												else{
													printf("\n\nHATA:elseden sonra bisey gelemez.KODUNUZ HATALIDIR");
													yanlis(kelime,elsegeridon+2);
													hata = false;
												}
											}
											else{
												hata = false;
											}
										}
										else{
											printf("\n\nHATA:else nin {} parantezler arasi bos kalamaz.KODUNUZ HATALIDIR");
											yanlis(kelime,elsegeridon+1);
											hata = false;
										}
									}
									else{
										printf("\n\nHATA:else den sonra { 	gelmeli.KODUNUZ HATALIDIR ");
									    yanlis(kelime,elsegeridon);
										hata = false;
									}
								}
								else if ((global) - (diziboyut - 1) == 0){
									dogru();
									forbitirr = false;
								}
								else if (hata == true){
									printf("\n\nHATA:elseif den sonra ya hicbirsey gelmez ya da else gelebilir baska bir sey gelemez.KODUNUZ HATALIDIR");
									yanlis(kelime,global+1);
									hata = false;
								}
							}
							else if ((susluparantez) - (diziboyut - 1) == 0){
								dogru();
								forbitirr = false;
							}
							else{
								printf("\n\nHATA:if den sonra ya hicbirsey gelmez ya da elseif veya else gelmeli.KODUNUZ HATALIDIR");
								yanlis(kelime,susluparantez+1);
								hata = false;
							}
						}
						else{
							hata = false;
						}
					}
					else{
						printf("\n\nHATA:if in {} parantezler arasi bos olamaz.KODUNUZ HATALIDIR");
						yanlis(kelime,kapananparantez+2);
						hata = false;
					}
				}
				else{
					printf("\n\nHATA: if in ) parantezinden sonra {  gelmek zorundadir.");
					yanlis(kelime,kapananparantez+1);
					hata = false;
				}
				forbitirr = false;
			}
			else{
				hata = false;
			}
		}
	}
	fclose(okunacakdosya);
	return 0;
}
