#include<stdio.h>
#include<string.h>
#include"fitos.h"

int main(){

	//Kode "burger" & 001 = Burger
	//Kode "milk" & 002 = Milkshake
	//Kode "b+m" & 003 = Burger + Milk
	//Bisa pakai string, angka, atau kombinasi
	//DONE
	char itemnames[3][40] = {"Burger", "Milkshake", "Burger + Milkshake"};
	int price[3] = {15000, 10000, 22000}, stock[3] = {60, 100, 45};
	int bought[3] = {};
	int subtotalbayar[3] = {};

	int total = 0, dibayarbrp, kembalian;
	char transaksidone[10];
	do
	{
		printf("%-5s|%-25s|%-5s|%-8s|%-8s|%s","Kode","Nama Produk","Stok", "Harga", "Dibeli", "Subtotal");
		for(int i = 0; i < 3; i++)
		{
			char fit[100], sub[100];
			fitos(price[i],fit);
			fitos(subtotalbayar[i],sub);
			printf("\n%03d  |%-25s|%-5d|%-8s|%-8d|%-8s",i+1,itemnames[i],stock[i],fit, bought[i], sub);
		}
		char itemcode[10];
		printf("\nMasukkan Kode Barang: ");
		scanf("%s", &itemcode); fflush(stdin);

		//Habis ngetik kode, minta jumlah yang dibeli, dgn jumlah tdk lebih besar dr stok; dan kalau ga ngisi (dienter), dianggap 1
		//Kondisi while buat variabel baru, dan hasil itemcodenya pakai if dgn do-while di dalamnya if
		//DONE
	
		bool comp;
		int tempbought;
		if (strcmp(itemcode, "001") == 0){
			do{
				printf("Masukkan jumlah %s yang ingin dibeli [1-%d]: ",itemnames[0],stock[0]);
				scanf("%d", &tempbought); fflush(stdin);
				if (tempbought<1||tempbought>stock[0]) printf("Jumlah %s yang dimasukkan salah. Jumlahnya harus diantara 1 dan %d\n", itemnames[0], stock[0]);
			} while (tempbought<1||tempbought>stock[0]);
			bought[0] += tempbought;
			stock[0] -= bought[0];
			subtotalbayar[0] = bought[0] * price[0];
		}
		else if (strcmp(itemcode, "002") == 0){
			do{
				printf("Masukkan jumlah %s yang ingin dibeli [1-%d]: ",itemnames[1],stock[1]);
				scanf("%d", &tempbought); fflush(stdin);
				if (tempbought<1||tempbought>stock[1]) printf("Jumlah %s yang dimasukkan salah. Jumlahnya harus diantara 1 dan %d\n", itemnames[1], stock[1]);
			} while (tempbought<1||tempbought>stock[1]);
			bought[1] += tempbought;
			stock[1] -= bought[1];
			subtotalbayar[1] = bought[1] * price[1];
		}
		else if (strcmp(itemcode, "003") == 0){
			do{
				printf("Masukkan jumlah %s yang ingin dibeli [1-%d]: ",itemnames[2],stock[2]);
				scanf("%d", &tempbought); fflush(stdin);
				if (tempbought<1||tempbought>stock[2]) printf("Jumlah %s yang dimasukkan salah. Jumlahnya harus diantara 1 dan %d\n", itemnames[2], stock[2]);
			} while (tempbought<1||tempbought>stock[2]);
			bought[2] += tempbought;
			stock[2] -= bought[2];
			subtotalbayar[2] = bought[2] * price[2];
		}
		else printf("Kode yang diminta tidak tersedia\n");
		//Hitung kembali stok berdasarkan total yang dibeli

		//Ketik apa gitu buat konfirmasi transaksi selesai, apanya terserah aku
		//Stlh selesai, nunjukin total sama ttn, diskon, dsbnya
		
		printf("Apakah transaksi sudah selesai? ");
		scanf("%s", &transaksidone); fflush(stdin);
		printf("\n");
	} while (strcmp(transaksidone, "sudah") != 0);

	//Hitung total
	
	printf("\n\n%-25s|%-8s|%s","Nama Produk", "Dibeli", "Subtotal");
	for(int i = 0; i < 3; i++)
	{
		if (bought[i] == 0) continue;
		char sub[100];
		fitos(subtotalbayar[i],sub);
		printf("\n%-25s|%-8d|%-8s",itemnames[i], bought[i], sub);
		total += subtotalbayar[i];
	}
	char tot[12];
	do
	{
		fitos(total,tot);
		printf("\n\nHarga Total: %s\nMasukkan jumlah uang yang dibayar pelanggan: ", tot);
		scanf("%d",&dibayarbrp); fflush(stdin);
		if (dibayarbrp < total) printf("Uang yang dibayar tidak bisa lebih kecil dari harga total\n\n");
	} while (dibayarbrp < total);
	char kmb[12];
	kembalian = dibayarbrp-total;
	fitos(kembalian,kmb);
	printf("\n\nKembalian: %s\nTerima kasih", kmb);
		//Stlh ditunjukin total, input dibayar brp, trus dikasih tahu kembaliannya, message thx, lalu kalau dienter kembali ke step awal
	getchar();
	return 0;
}
