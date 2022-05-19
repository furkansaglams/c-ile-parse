#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
AD:FURKAN
SOYAD:SA�LAM
NUMARA:02200201017
1.��RET�M 2.SINIF
*/
// KODUN CAL�SMAS�: KOD PARSE ED�L�R EGER KOD DOGRU �SE KODUN DOGRU OLDUGUNA DA�R B�R �IKTI YAZILIR EGER KOD HATAL� �SE KODUN DOGRU
//OLAN KISMINA KADAR YAZILIR �LK HATALI KEL�MEN�N  BULUNDUGU YERE DE HATAL� KEL�ME BURDA D�YE B�R �IKTI YAZILIR O DA HATALI KEL�MEN�N BASLANGICINI BEL�RT�R.
//ORNEK:if(a=b) EKRAN CIKTISI:if(a -->burdan sonraki ilk kelime hatali BOYLEL�KLE HATALI KEL�MEN�N YER� TESP�T ED�LM�S OLUR. 
//NOT: ; KONTROLUNU  KODA DAH�L ETMED�M AL� HOCA EKLEMEZSEN�Z PROBLEM OLMAZ DED�G� �C�N
//NOT:HATA ACIKLAMASI GRAMER YAPISINA GORE ACIKLANMISTIR.
//NOT: kelimelestirmenin yazd�r�lmas� { } aras�na yap�lmaktad�r koddaki } ile kar�st�rmay�n�z.
//kodda hem tokenizer hem parse oldugunda parser ile alakal� olan k�s�mlara parser diye ekledim daha rahata anlasilmasi icin
//yorum sat�rlar�n� numaraland�r�rak yapt�m her numara "//" aras�n� ifade edicek tokenizer icin boyle parse icin direk yorum satiri ekledim

void yanlis(char dizigonder[],int son) //parse bu k�s�mda kodda herhangi bir hata olmas� durumunda yazd�rma islemi icin bu fonksiyonu yazd�m
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
void dogru()//parser bu k�s�mda kodda dogru olmas� durumunda yazd�rma islemi icin bu fonksiyonu yazd�m
{
	printf("\n***************************************************************************\n");
	printf("                   SONUC: KODUNUZ DOGRU");
	printf("\n***************************************************************************\n");
	
}
int elseifmi(char dizigonder[], int baslangic){//parser (else if) kelimesinin dogrulugunu kontrol etmek icin yazdim. (else if) yaz�m�nda hata var ise false degeri donmektedir. 
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
		return baslangic + 7;// parser 7 eklememin nedeni elseif kelimesinin 6 karakter olmas� 7.karakterin ( parantez olup olmad�g�n� anlamak icin bu degeri return ettim
	}
	else{
		return 0;
	}
}
int elsemi(char dizigonder[], int baslangic){//parser (else) kelimesinin dogrulugunu kontrol etmek icin yazdim.(else) yaz�m�nda hata var ise false degeri donmektedir.
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
		return baslangic + 5;// parser 5 eklememin nedeni else kelimesinin 4 karakter olmas� 5.karakterin { parantez olup olmad�g�n� anlamak icin bu degeri return ettim
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
			dogrumu = true;// parser hatal� harf yok ise dogrumu degeri true olavcakt�r.Aksi takdirde baslang�cta false oldugu icin false olarak kal�p if icine hic girmeyecektir boylelikle hatal� harf tespit edilmis olucakt�r.
		}
	}
	return dogrumu;
}
bool rakammi(char eleman){//parser Gramerdeki rakamlar�n dogrulugunu kontrol etmek icin yazdim.Eger hatali rakam var ise false donmektedir
	int j;
	bool dogrumu = false;
	char rakam[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	for (j = 0; j < 10; j++){
		if (eleman == rakam[j]){
			dogrumu = true;//parser hatal� harf yok ise dogrumu degeri true olavcakt�r.Aksi takdirde baslang�cta false oldugu icin false olarak kal�p if icine hic girmeyecektir boylelikle hatal� harf tespit edilmis olucakt�r.
		}
	}
	return dogrumu;
}
bool cumlekontrol(char dizigonder[], int baslangic, int son)// parser Gramerdeki cumle kural�n� test etmek icin bu fonksiyonu yazd�m.Cumle icerdindeki hatal� kelime olmas� durumunda false degeri donmektedir.
{
	int i;
	int cumlegecici;
	for (i = baslangic; i < son; i++){
		if (harfmi(dizigonder[baslangic]) == true){
			if (dizigonder[baslangic + 1] == '='){
				if (harfmi(dizigonder[baslangic + 2]) == true){
					if (dizigonder[baslangic + 3] == '+'){
						if (harfmi(dizigonder[baslangic + 4]) == true){//parser buras� cumle icerisindek {<id>(harf)=<id>(harf+  dan  sonra harfin dogruluguna bakmaktad�r asg�daki diger yap�larda benzer bicimde cal�smaktad�r.
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
							while (rakammi(dizigonder[cumlegecici]) == true){ //parser eger rakam geldiyse ne kadar geldigini belirlemek icin yaz�ld� (birden fazla basamak var ise son bsamaga kadar gitmek icin yap�ld�).
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
bool sartkontrol(char dizigonder[], int baslangic, int son) // parser Gramerdeki sart kural�n� test etmek icin bu fonksiyonu yazd�m.Sart icerdindeki hatal� kelime olmas� durumunda false degeri donmektedir.
{
	int i;
	bool forbitir = true;
	int gecici = baslangic;
	int gecicirakam;
	for (i = baslangic; i < son && forbitir == true; i++){
		if (harfmi(dizigonder[baslangic]) == true){
			if (dizigonder[baslangic + 1] == '<' || dizigonder[baslangic + 1] == '>' ||//<op> sart icersindeki olas� <op> degerleri.
				(dizigonder[baslangic + 1] == '<' && dizigonder[baslangic + 2] == '=') ||
				(dizigonder[baslangic + 1] == '>' && dizigonder[baslangic + 2] == '=') ||
				(dizigonder[baslangic + 1] == '=' && dizigonder[baslangic + 2] == '=')){
				if ((dizigonder[baslangic + 1] == '=' && dizigonder[baslangic + 2] == '>') || (dizigonder[baslangic + 1] == '=' && dizigonder[baslangic + 2] == '<')){ //<op> k�sm�nda ozel bir hata olan(=> ve =<) kullan�m olursa onu engellemek icin yazd�m.(ozel bir durumu kontrol ediyor)
					printf("\n\nHATA:noperand kullanimini dogru bir bicimde yapiniz(<= gibi).KODUNUZ HATALIDIR");
					return false;
				}
				else{
					if (dizigonder[baslangic + 2] == '='){// parser Bu kontrolu yapmam�n nedeni <= == >= gibi iki karakter bar�nd�ran durumlar� ayr� < > gibi durumlar� ayr� kontrol etmek icin yapt�m cunku birinde iki karakter var digerinde tek karakter bu ay�rd�m icin yap�ld�.Bu k�s�m <= >= == durumunu(iki karakter) kontrol etmekte.
						if (harfmi(dizigonder[baslangic + 3]) == true){ //parse buras� sart iceridindeki (<id>(harf)= den  sonra harfin dogruluguna bakmaktad�r asag�daki diger yap�larda benzer bicimde cal�smaktad�r.
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
						if (harfmi(dizigonder[baslangic + 2]) == true){//parser buras� <  > gibi (tek kelimelik) durum kontrolu icin yap�ld�.
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
void kaynakodyazdir(char dizi[], int diziboyut){ //txt di metindeki kaynak kodun yaz�m� icin yap�ld�.
	printf("  \nkaynak kodunuz:\n\n");
	int i;
	for (i = 0; i < diziboyut; i++){
		printf("%c", dizi[i]);
	}
	printf("\n\n");
	printf("kelimelestirilmis hali:\n\n");
}
//yorum sat�r� 1 alttaki kodda ++ -- gibi kontrolleri yapt�m ��nk� bunlar ayr� ayr� olucak kavramlar de�il
//c de beraber yaz�lan yap�lar oldugu i�in b�yle bir �ey yapt�m ayr�ca virg�l atarken dogru virg�l atabilmemi sa�lad�.
//bunlar �zel durumlar oldugu i�in diziye atmak daha fazla i�leme neden olaca�� i�i b�yle tercih ettim
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
//yorum sat�r� 1 bitti
//yorum sat�r� 2 alttaki kodda ayra� olup omad�g�n� kontrol ettim dogru bir bi�imde virg�l atabilmek i�in
//baz�lar�n� ascii olarak yazd�m "'" kodun okunurlugu a��s�ndan g�zel olmad�g�ndan bunun gibi �rnekleri ascii olarak yazd�m
//32=bosluk tusu   34="(�ift t�rnak)  39='(tekt�rnak)
int ayrac(char karakter){
	char dizi[26] = { '+', '-', '*', '/', ',', ';', '>', '<', '[', ']', '{', '}', ')', '(', '=', '|', '&', 34, 39, '!', 92, ':', '?', '^', '%', '.' };
	int i = 0, deger = 0;
	bool fonksiyondancik = true;	// iki nedeni var 1.neden eger terminal'i bulursa deger=1 olucak ama hala devam edicek bir sonrakinde bulamay�nca deger 0 olucak ve hatal� �al���cak 2.neden ise buldugu anda diziye deam etmemesini sa�lamak zaman kaybetmemesi i�in.
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
	//yorum sat�r� 3 bu kod sat�r�n� dosyan�n sonuna kadar okumam� ve fgetc fonksiyonu ile karakter karakter okuyup bir karakter dizisine
	//atmai�lemini ger�ekle�tirdim .dosyay� okurken EOF kavram�n� kulland�m EOF txt metinin son harfini g�steren bir i�aret�i
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
	// yorum sat�r� 3 bitti
	// yorum sat�r� 4 fgetc fonksiyonu bosluk tab enter tusunu da bir karakter olarak ald�g� i�in bunlar� dizide
	//kayd�rma yaparak bir nevi yok ettim yani karakter dizimde bosluk tab ve enter tu�lar�n� kald�rd�m
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
	//yorum sat�r� 4 bitti
	//yorum sat�r� 5 olas� bosluklar� garantilemek i�in yeni bir diziye bosluksuz halini att�m
	int diziboyut = 0;
	for (j = 0; j < i - 1 - bosluk; j++){
		if (kelime[j] != 32){
			diziboyut++;
			yenidizi[j] = kelime[j];
		}
	}
	//yorum sat�r� 5 bitti
	printf("{ ");	//dizi bi�iminde gozukmesi i�in kelimlestirilmis halinin bas�na ve sonuna {} eklemek icin yap�ld� yani g�runum icin yap�ld�
	bool ayracmi, ozel, ikisonrasiayracmi, birsonrasiayracmi;
	int l = 0;
	for (l = 0; l < diziboyut; l++){
		ayracmi = ayrac(yenidizi[l]);	//karakter dizisinde eger bir terminal(;, " gibi degerlerin olup olmad�g�n� kontrol ettim)
		birsonrasiayracmi = ayrac(yenidizi[l + 1]);	// virg�l atarken iki ayra� yanayana gelirse tek bir virg�l atmak gerekiyor sonras�n�n ayra�olup olmad�g�n� kontrol ettim
		ikisonrasiayracmi = ayrac(yenidizi[l + 2]);	// ++ -- gibi durumlarda bir sonras�n� kontrol etti�imde + ve sonars� da + y� kontrol etmi� olurum buna gerek yok iki sonarsa�n� yani ++ dan sonra bir terminal var m� ?
		if (l != diziboyut){
			ozel = ozeldurum(yenidizi[l], yenidizi[l + 1]);
		}
		if (ayracmi == 1){
			if (ozel == 1){
				if (ikisonrasiayracmi == 1){
					printf(",%c%c", yenidizi[l], yenidizi[l + 1]);	//�rne�in ,++ yap�p sonras� ayra� ise ,(, yapmal�y�z bunun i�in yazd�m ==> ,++,(,
					l++;
				}
				else{
					if (l == diziboyut - 1){
						printf(",%c%c", yenidizi[l], yenidizi[l + 1]);	//en sonda 1 virg�l fazladan atmamas� gerekti�inden yazd�m
						l++;
					}
					else{
						printf(",%c%c,", yenidizi[l], yenidizi[l + 1]);
						l++;
					}
				}
			}
			else if (birsonrasiayracmi == 1){
				printf(",%c", yenidizi[l]);	//�rnek); iki terminal yanyana gelirse ba��na ve sonuna virg�l atarsak ,),,;, olacag� i�in yapt�m
			}
			else{
				if (l == diziboyut - 1){
					printf(",%c", yenidizi[l]);	//sonda 1 virg�l fazla dan oldugu i�in yap�ld�
				}
				else{
					printf(",%c,", yenidizi[l]);
				}
			}
		}
		else{
			printf("%c", yenidizi[l]);	//eger terminal degilse oldugu gibi yazmas� i�in yap�ld�
		}
	}
	printf("}");
	int diziesasboyut = (sizeof yenidizi / sizeof(float));
	//parser i�lemi buradan baslamaktad�r gerekli fonksiyonlar� main in d�s�nda yazd�m
	int global;
	int kapananparantez;// parser son kapanan  parantezin degerini bulmak icin olusturuldu 
	int susluparantez;// parser son kapanan susluparantezin degerini bulmak icin olusturuldu
	bool forbitirr = true;//for dongusunde hata meydana gelmedigi ama for un  durmas� gereken anlar icin  boyle bir tan�mlama yapt�m.
	bool kapananparantezvarmi = false;
	int cik = 0;
	bool ifdogrumu = false;
	bool hata = true;// parser olas� hatalarda for dongusunun sona erdirilmesini saglamak amac� ile yaz�ld�
	int birkere = 0;
	for (j = 0; j < i - 1 - bosluk && (hata == true && forbitirr == true); j++){
		if (birkere < 1){ // parser if kontrolu bir kere yap�lmas� ve her for dondugunde bu kontrolun tekrar tekrar yapm�lmamas� icin yap�ld�.
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
								while (elseifmi(kelime, susluparantez) != 0 && hata == true){ // parser elseif degeri ya hic gelmeyecek ya da sonsuz defa gelebilecegi icin while dongusne ald�m her while dondugunde susluparantez degeri guncellenmektedir.
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
												if ((elsegeridon + 1) - (diziboyut - 1) == 0){//parser bu yap� eger else if(<sart>){<cumle>} k�sm�ndan sonras�n�n bos olup olmad�g�n� kontrol etmektedir(else if den sonra hicbir sey de gelmese hata olmayacag� icin boyle bir sey yap�ld�) eger dizinin boyutu(txt metinin icinde yaz�lanlar) ile else if in } parantez degeri esit ise bu demek olur ki else if den sonra bisey yaz�lmam�s.
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
