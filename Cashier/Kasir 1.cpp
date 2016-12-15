#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"fitos.h"

const int EXP_VAL = 3; //Expected no. of menu to read
char itemnames[3][40] = {};
int price[3]={}, stock[3] ={};

int load()
{
	int i;
	FILE * f = fopen("data.txt","r");
	if(f == NULL)
	{
		f = fopen("data.txt","w+");
		fprintf(f,"Burger,10,10000\nMilkshake,10,10000\nBurger + Milkshake,10,10000\n\nHint: %s,%s,%s //DO NOT CHANGE THE NO. OF ITEMS! JANGAN MENGUBAH JUMLAH ITEM!","Nama Produk","Stok", "Harga");
		fclose(f);
		printf("ERROR: File not found for data.txt. Dummy data have been saved to the disk.\nPlease modify data.txt with the correct data, then run the application again\n\n");
		getchar();
		exit(1);
	}
	for (i = 0; i<EXP_VAL;i++)
	{
		if(fscanf(f,"%[^,],%d,%d\n",itemnames[i],&stock[i],&price[i]) == EOF) break;
	}
	fclose(f);
	return i;
}

void save()
{
	FILE * f = fopen("data.txt","w");
	
	for(int i = 0; i<EXP_VAL;i++)
	{
		fprintf(f,"%s,%d,%d\n",itemnames[i],stock[i],price[i]);
	}
	fprintf(f,"\nHint: %s,%s,%s //DO NOT CHANGE THE NO. OF ITEMS! JANGAN MENGUBAH JUMLAH ITEM!\n","Nama Produk","Stok", "Harga");
	fclose(f);
}

int main(){

	//Kode "burger" & 001 = Burger
	//Kode "milk" & 002 = Milkshake
	//Kode "b+m" & 003 = Burger + Milk
	//Bisa pakai string, angka, atau kombinasi
	//DONE
	
	int bought[3] = {};
	int subtotalbayar[3] = {};

	int total = 0, dibayarbrp, kembalian;
	char transaksidone;
	load();
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
		


		//Habis ngetik kode, minta jumlah yang dibeli, dgn jumlah tdk lebih besar dr stok; dan kalau ga ngisi (dienter), dianggap 1
		//Kondisi while buat variabel baru, dan hasil itemcodenya pakai if dgn do-while di dalamnya if
		//DONE
		do
		{		
			char itemcode[10];
			printf("\nMasukkan Kode Barang: ");
			scanf("%s", &itemcode); fflush(stdin);
			int tempbought;
			if (strcmp(itemcode, "001") == 0)
			{
				do
				{
					printf("Masukkan jumlah %s yang ingin dibeli [1-%d]: ",itemnames[0],stock[0]);
					scanf("%d", &tempbought); fflush(stdin);
					if (tempbought<1||tempbought>stock[0]) printf("Jumlah %s yang dimasukkan salah. Jumlahnya harus diantara 1 dan %d\n", itemnames[0], stock[0]);
				} 
				while (tempbought<1||tempbought>stock[0]);
				bought[0] += tempbought;
				stock[0] -= bought[0];
				subtotalbayar[0] = bought[0] * price[0];
				break;
			}
			else if (strcmp(itemcode, "002") == 0)
			{
				do
				{
					printf("Masukkan jumlah %s yang ingin dibeli [1-%d]: ",itemnames[1],stock[1]);
					scanf("%d", &tempbought); fflush(stdin);
					if (tempbought<1||tempbought>stock[1]) printf("Jumlah %s yang dimasukkan salah. Jumlahnya harus diantara 1 dan %d\n", itemnames[1], stock[1]);
				} 
				while (tempbought<1||tempbought>stock[1]);
				bought[1] += tempbought;
				stock[1] -= bought[1];
				subtotalbayar[1] = bought[1] * price[1];
				break;
			}
			else if (strcmp(itemcode, "003") == 0)
			{
				do
				{
					printf("Masukkan jumlah %s yang ingin dibeli [1-%d]: ",itemnames[2],stock[2]);
					scanf("%d", &tempbought); fflush(stdin);
					if (tempbought<1||tempbought>stock[2]) printf("Jumlah %s yang dimasukkan salah. Jumlahnya harus diantara 1 dan %d\n", itemnames[2], stock[2]);
				} 
				while (tempbought<1||tempbought>stock[2]);
				bought[2] += tempbought;
				stock[2] -= bought[2];
				subtotalbayar[2] = bought[2] * price[2];
				break;
			}
			else printf("Kode yang diminta tidak tersedia\n");
		} 
		while(true);


		//Hitung kembali stok berdasarkan total yang dibeli

		//Ketik apa gitu buat konfirmasi transaksi selesai, apanya terserah aku
		//Stlh selesai, nunjukin total sama ttn, diskon, dsbnya
		
		printf("Apakah transaksi sudah selesai? (Y/N) ");
		scanf("%c", &transaksidone); fflush(stdin);
		if(transaksidone == 'y' || transaksidone == 'Y') break;
		printf("\n");
	} 
	while (true);
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
	getchar();
	save();
	return 0;
}
