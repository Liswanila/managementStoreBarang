#include <iostream>
#include <stdlib.h>
#include <string>
#define max 20

using namespace std;

void tampilkan_barang();
int main();

struct tumpukan
{
	int atas;
	int jumlahbarang[max];
	string namabarang[max];
	int hargabarang[max];
}T;

void awal()
{
	T.atas = -1;
}

int kosong()
{
	if(T.atas == -1)
		return 1;
	else
		return 0;
}

int penuh()
{
	if(T.atas == max-1)
		return 1;
	else
		return 0;
}

void input_barang(string namabarang, int hargabarang, int jumlahbarang)
{
	if(kosong() == 1)
	{
		T.atas++;
		T.jumlahbarang[T.atas] = jumlahbarang;
		T.namabarang[T.atas] = namabarang;
		T.hargabarang[T.atas] = hargabarang;
		cout << "\n" << T.namabarang[T.atas] << " sudah masuk ke rak no " << T.atas+1 <<endl;
	}
	else if(penuh() == 0)
	{
		T.atas++;
		T.jumlahbarang[T.atas] = jumlahbarang;
		T.namabarang[T.atas] = namabarang;
		T.hargabarang[T.atas] = hargabarang;
		cout << "\n" << T.namabarang[T.atas] << " sudah masuk ke rak no " << T.atas+1 << endl;
	}
	else
	{
		cout << "\nMaaf rak sudah penuh";
	}
}

void tampilkan_barang()
{
	if(kosong() == 0)
	{
		for(int i = 0; i <= T.atas; ++i)
		{
			cout << "\n Barang terletak di rak no " << i+1 << endl;
			cout << "Nama Barang	: " << T.namabarang[i] << endl;
			cout << "Harga Barang	: Rp. " << T.hargabarang[i] << endl;
			cout << "Jumlah Barang	: " << T.jumlahbarang[i] << endl;
		}
	}
	else
		cout << "\nRak masih kosong\n";
}

void edit_harga()
{
	if(kosong() == 0)
	{
		tampilkan_barang();
		
		string ganti, i;
		
		cout << "\nMasukkan Nama barang yang akan diubah : ";
		getline(cin, ganti);
		cin.ignore();
		
		for(int i = 0; i <= T.atas+1; ++i)
		{
			if(ganti == T.namabarang[i])
			{
				cout << "Masukkan harga barang baru : ";
				cin >> T.hargabarang[i];
				cout << "\n\nData berhasil diubah\n";
			}
			else if(i > T.atas)
				cout << "\nBarang tidak ditemukan" << endl;
		}
	}
	else
		cout << "\nRak masih kosong\n";
}

void edit_jumlah()
{
	if(kosong() == 0)
	{
		tampilkan_barang();
		
		string ganti, i;
		
		cout << "\nMasukkan Nama barang yang akan diubah : ";
		getline(cin, ganti);
		cin.ignore();
		
		for(int i = 0; i < T.atas+1; ++i)
		{
			if(ganti == T.namabarang[i])
			{
				cout << "Masukkan jumlah barang baru : ";
				cin >> T.jumlahbarang[i];
				cout << "\n\nData berhasil diubah\n";
			}
			else if(i >= T.atas)
				cout << "\nBarang tidak ditemukan" << endl;
		}
	}
	else
		cout << "\nRak masih kosong\n";
}

void sorting_nama()
{
	int i, j, tempjumlah;
	string tempnama;
	int tempharga;
	
	for(i = 0; i < T.atas; ++i)
	{
		for(j = 0; j < (T.atas-i); ++j)
		{
			if(T.namabarang[j] > T.namabarang[j+1])
			{
				tempnama = T.namabarang[j];
				T.namabarang[j] = T.namabarang[j+1];
				T.namabarang[j+1] = tempnama;
			}
		}
	}
	system("cls");
	cout << "\nBarang setelah diurutkan menurut Nama Barang " << endl;
	tampilkan_barang();
}

void sorting_jumlah()
{
	int i, j, tempjumlah;
	string tempnama;
	int tempharga;
	
	for(i = 0; i < T.atas; ++i)
	{
		for(j = 0; j < (T.atas-i); ++j)
		{
			if(T.jumlahbarang[j] > T.jumlahbarang[j+1])
			{
				tempjumlah = T.jumlahbarang[j];
				T.jumlahbarang[j] = T.jumlahbarang[j+1];
				T.jumlahbarang[j+1] = tempjumlah;
			}
		}
	}
	system("cls");
	cout << "\nBarang setelah diurutkan menurut Jumlah Barang " << endl;
	tampilkan_barang();
}

void sorting_harga()
{
	int i, j, tempjumlah;
	string tempnama;
	int tempharga;
	
	for(i = 0; i < T.atas; ++i)
	{
		for(j = 0; j < (T.atas-i); ++j)
		{
			if(T.hargabarang[j] > T.hargabarang[j+1])
			{
				tempharga = T.hargabarang[j];
				T.hargabarang[j] = T.hargabarang[j+1];
				T.hargabarang[j+1] = tempharga;
			}
		}
	}
	system("cls");
	cout << "\nBarang setelah diurutkan menurut Harga Barang " << endl;
	tampilkan_barang();
}

void search_nama()
{
	if(kosong() == 0)
	{
		string cari;
		
		cout << "Masukkan Nama barang yang dicari : ";
		getline(cin,cari);
		
		for(int i = 0; i <= T.atas+1; ++i)
		{
			if(cari == T.namabarang[i])
			{
				cout << "\nBarang ada pada rak no " << i+1 << endl;
				cout << "Nama Barang	: " << T.namabarang[i] << endl;
				cout << "Harga Barang	: Rp. " << T.hargabarang[i] << endl;
				cout << "Jumlah Barang	: " << T.jumlahbarang[i] << endl;
			}
			else if(i > T.atas)
			{
				cout << "\nPencarian selesai" << endl;
				break;
			}
		}
	}
	else
		cout << "\nRak masih kosong\n";
}

void search_jumlah()
{
	if(kosong() == 0)
	{
		int cari;
		
		cout << "Masukkan Kode barang yang dicari : ";
		cin >> cari;
		
		for(int i = 0; i <= T.atas+1; ++i)
		{
			if(cari == T.jumlahbarang[i])
			{
				cout << "\nBarang ada pada rak no " << i+1 << endl;
				cout << "Jumlah Barang	: " << T.jumlahbarang[i] << endl;
				cout << "Nama Barang	: " << T.namabarang[i] << endl;
				cout << "Harga Barang	: Rp. " << T.hargabarang[i] << endl;
			}
			else if(i > T.atas)
			{
				cout << "\nPencarian selesai" << endl;
				break;
			}
		}
	}
	else
		cout << "\nRak masih kosong\n";
}

void search_harga()
{
	if(kosong() == 0)
	{
		int cari;
		
		cout << "Masukkan Harga barang yang dicari : ";
		cin >> cari;
		
		for(int i = 0; i <= T.atas+1; ++i)
		{
			if(cari == T.hargabarang[i])
			{
				cout << "\nBarang ada pada rak no " << i+1 << endl;
				cout << "Harga Barang	: Rp. " << T.hargabarang[i] << endl;
				cout << "Nama Barang	: " << T.namabarang[i] << endl;	
				cout << "Jumlah Barang	: " << T.jumlahbarang[i] << endl;
			}
			else if(i > T.atas)
			{
				cout << "\nPencarian selesai" << endl;
				break;
			}
		}
	}
	else
		cout << "\nRak masih kosong\n";
}

void hapus()
{
	if(kosong() == 0)
	{
		tampilkan_barang();
		
		string tempnama, nama;
		int temp;
		int berhasil = 0;
		int i, j;
		
		cout << "\nMasukkan Nama barang yang akan dihapus : ";
		cin.ignore();
		getline(cin, nama);
		
		for(int i = 0; i < T.atas+1; ++i)
		{
			for(int j = 0; j < T.atas+1; ++j)
			{
				if(nama == T.namabarang[j])
				{		
					tempnama = T.namabarang[j];
					T.namabarang[j] = T.namabarang[j+1];
					T.namabarang[j+1] = temp;
								
					berhasil = 1;
				}
			}
		}
		if(berhasil == 1)
		{
			cout << "\nBarang berhasil dihapus\n";
			T.atas--;
		}
		else
		{
			cout << "\nMaaf barang tidak ditemukan" << endl;
		}
	}
	else
	{
		cout << "\nRak masih kosong\n";
	}
}

void menu_sorting()
{
	int pilihan;
	
	cout << "1. Urutkan Berdasarkan Nama Barang\n";
	cout << "2. Urutkan Berdasarkan Jumlah Barang\n";
	cout << "3. Urutkan Berdasarkan Harga Barang\n";
	cout << "4. Kembali ke Menu Awal\n";
	cout << "Masukkan pilihan : ";
	cin >> pilihan;
	
	switch(pilihan)
	{
		case 1:
		sorting_nama();
		break;
		
		case 2:
		sorting_jumlah();
		break;
		
		case 3:
		sorting_harga();
		break;
		
		case 4:
		int main();
		break;
	}
}

void menu_search()
{
	int pilihan;
	
	cout << "1. Cari Berdasarkan Nama Barang\n";
	cout << "2. Cari Berdasarkan Jumlah Barang\n";
	cout << "3. Cari Berdasarkan Harga Barang\n";
	cout << "4. Kembali ke Menu Awal\n";
	cout << "Masukkan pilihan : ";
	cin >> pilihan;
	cin.ignore();
	
	switch(pilihan)
	{
		case 1:
		search_nama();
		break;
		
		case 2:
		search_jumlah();
		break;
		
		case 3:
		search_harga();
		break;
		
		case 4:
		int main();
		break;
	}
}

void menu_edit()
{
	int pilihan;
	
	cout << "1. Edit Harga Barang\n";
	cout << "2. Edit Jumlah Barang\n";
	cout << "3. Kembali ke Menu Awal\n";
	cout << "Masukkan pilihan : ";
	cin >> pilihan;
	cin.ignore();
	
	switch(pilihan)
	{
		case 1:
		edit_harga();
		break;
		
		case 2:
		edit_jumlah();
		break;
		
		case 4:
		int main();
		break;
	}
}

int main()
{
	awal();
	system("cls");
	
	int pilihan, n, jumlahbarang[max];
	string namabarang[max];
	int hargabarang[max];
	
	do
	{
		cout << "\t\t===================================================" << endl;
		cout << "\t\t|             FINAL PROJECT KELOMPOK 3             |"  << endl;
		cout << "\t\t|          PROGRAM MANAGEMENT STOK BARANG          |"  << endl;
		cout << "\t\t===================================================" << endl;
		cout << "\t\t                    MENU UTAMA                    " << endl;
		cout << "\n 1. Input barang";
		cout << "\n 2. Tampilkan barang";
		cout << "\n 3. Edit barang";
		cout << "\n 4. Urutkan barang";
		cout << "\n 5. Cari barang";
		cout << "\n 6. Hapus barang";
		cout << "\n 7. Keluar";
		cout << "\nMasukkan pilihan : ";
		cin >> pilihan;
		
		switch(pilihan)
		{
			case 1:
			
			system("cls");
			
			cout << "\nINPUT BARANG" << endl;
			cout << "\nMasukkan banyak barang yang akan dimasukkan ke rak: ";
			cin >> n;
			
			for(int i = 0; i < n; ++i)
			{
				cin.ignore();
				cout << "\nMasukkan barang ke-" << i+1 << endl;
				cout <<"Nama barang	: ";
				getline(cin, namabarang[i]);
				
				cout << "Harga barang	: Rp. ";
				cin >> hargabarang[i];
				cin.ignore();
				
				cout << "Jumlah Barang	: ";
				cin >> jumlahbarang[i];
				
				input_barang(namabarang[i], hargabarang[i], jumlahbarang[i]);
			}
			break;
			
			case 2:
			
			system("cls");
			
			cout << "\nTAMPILKAN BARANG" << endl;
			tampilkan_barang();
			break;
			
			case 3:
			
			system("cls");
			
			cout << "\nMENGEDIT BARANG" << endl;
			menu_edit();
			break;
			
			case 4:
			
			system("cls");
			
			cout << "\nMENGURUTKAN BARANG" << endl;
			menu_sorting();
			break;
			
			case 5:
			
			system("cls");
			
			cout << "\nMENCARI BARANG" << endl;
			menu_search();
			break;
			
			case 6:
			
			system("cls");
			
			cout << "\nHAPUS BARANG" << endl;
			hapus();
			break;
			
			case 7:
			
			system("cls");
			
			cout << "\n\t\t===================================================" << endl;
			cout << "\t\t=================== TERIMAKASIH ===================" << endl;
			cout << "\t\t===================================================" << endl;
			cout << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	while(pilihan != 7);
}
