#include<stdio.h>
#include<string.h>

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
		if (strcmp(itemcode, "001") == 0){
			do{
				printf("\nMasukkan jumlah Burger yang ingin dibeli [1-%d]: ",stock[0]);
				scanf("%d", &bought[0]); fflush(stdin);
			} while (bought[0]<1||bought[0]>stock[0]);
		}
		else if (strcmp(itemcode, "002") == 0){
			do{
				printf("Masukkan jumlah Milkshake yang ingin dibeli [1-%d]: ",stock[1]);
				scanf("%d", &bought[1]); fflush(stdin);
			} while (bought[1]<1||bought[1]>stock[1]);
		}

		//Hitung kembali stok berdasarkan total yang dibeli
		for(int i = 0; i < 3; i++)
		{
			stock[i] -= bought[i];
			subtotalbayar[i] = bought[i] * price[i];
		}

		//Ketik apa gitu buat konfirmasi transaksi selesai, apanya terserah aku
		//Stlh selesai, nunjukin total sama ttn, diskon, dsbnya
		
		printf("\nApakah transaksi sudah selesai? ");
		scanf("%s", &transaksidone); fflush(stdin);

	} while (strcmp(transaksidone, "sudah") != 0);

	//Stlh ditunjukin total, input dibayar brp, trus dikasih tahu kembaliannya, message thx, lalu kalau dienter kembali ke step awal



	getchar();
	return 0;
}
