#include<stdio.h>
#include<string.h>

int main(){

	//Kode "burger" & 001 = Burger, Kode "milks" & 002 = Milkshake
	//Bisa pakai string, angka, atau kombinasi
	//DONE
	char itemcode[10], transaksidone[10];
	int burgerbought, milksbought, hargaburger = 0, hargamilks = 0, total, dibayarbrp, kembalian, price[2] = {15000, 10000}, stock[2] = {60, 100};
	
	total = 0;
	printf("Barang apa yang dibeli: ");
	scanf("%s", &itemcode); fflush(stdin);

	//Habis ngetik kode, minta jumlah yang dibeli, dgn jumlah tdk lebih besar dr stok; dan kalau ga ngisi (dienter), dianggap 1
	//Kondisi while buat variabel baru, dan hasil itemcodenya pakai if dgn do-while di dalamnya if
	//DONE
	bool comp;
	if (strcmp(itemcode, "burger") == 0){
		do{
			printf("\nBerapa banyak burger yang dibeli [1-60]: ");
			scanf("%d", &burgerbought); fflush(stdin);
		} while (burgerbought<1||burgerbought>60);
	}
	else if (strcmp(itemcode, "milks") == 0){
		do{
			printf("\nBerapa banyak milkshake yang dibeli [1-100]: ");
			scanf("%d", &milksbought); fflush(stdin);
		} while (milksbought<1||milksbought>100);
	}

	//Wrong type of code
	/*do{
		printf("\nMasukkan jumlah burger yang dibeli: ");
	} while (itemcode == "burger");
	do{
		printf("\nMasukkan jumlah milkshake yang dibeli: ");
	} while (itemcode == "milks");*/


	//Ketik apa gitu buat konfirmasi transaksi selesai, apanya terserah aku
	//Stlh selesai, nunjukin total sama ttn, diskon, dsbnya
	printf("\nApakah transaksi sudah selesai? ");
	scanf("%s", &transaksidone); fflush(stdin);

	if (strcmp(transaksidone, "belum") == 0){
		printf("\nAda pembelian barang apa lagi? ");
		scanf("%s", &itemcode); fflush(stdin);

		if (strcmp(itemcode, "burger") == 0){
			do{
				printf("\nBerapa banyak burger yang dibeli [1-60]: ");
				scanf("%d", &burgerbought); fflush(stdin);
			} while (burgerbought<1||burgerbought>60);
		}
		else if (strcmp(itemcode, "milks") == 0){
			do{
				printf("\nBerapa banyak milkshake yang dibeli [1-100]: ");
				scanf("%d", &milksbought); fflush(stdin);
			} while (milksbought<1||milksbought>100);
		}

		printf("\nApakah transaksi sudah selesai? ");
		scanf("%s", &transaksidone); fflush(stdin);

		if (strcmp(transaksidone, "sudah") == 0){
			hargaburger += burgerbought * price[0];
			hargamilks += milksbought * price[1];
			total += hargaburger + hargamilks;
			printf("\nHarga Total: %d", total);
		}
	}

	else if (strcmp(transaksidone, "sudah") == 0){
		hargaburger += burgerbought * price[0] + 4000;
		hargamilks += milksbought * price[1] + 8000;
		total += hargaburger + hargamilks;
		printf("\nHarga Total: %d", total);
	}

	//Stlh ditunjukin total, input dibayar brp, trus dikasih tahu kembaliannya, message thx, lalu kalau dienter kembali ke step awal



	getchar();
	return 0;
}