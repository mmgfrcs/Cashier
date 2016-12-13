#include<stdio.h>
#include<string.h>

int main(){
	char itemnames[3][40] = {"Burger", "Milkshake", "Burger + Milkshake"};
	int price[3] = {15000, 10000, 22000}, stock[3] = {60, 100, 45};
	int bought[3];
	int subtotalbayar[3];

	int total = 0, dibayarbrp, kembalian;

	printf("%-5s|%-25s|%-5s|%s","Kode","Nama Produk","Stok", "Harga");
	for(int i = 0; i < 3; i++)
	{
		printf("\n%03d  |%-25s|%-5d|%d",i+1,itemnames[i],stock[i],price[i]);
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
