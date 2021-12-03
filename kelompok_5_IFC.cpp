# include <iostream>
# include <conio.h>
# include <windows.h>
# include <fstream>

using namespace std;

struct admin {	// struct untuk menu admin
	int nomer;
	string plat;
	string merk;
	string warna;
	int harga;
	char keluaran[20];
	struct admin * prev;
	struct admin * next;
};
struct akun {	// struct untuk menu user
	string nama;
	string pekerjaan;
	string alamat;
	int username;
	int no;
	int password;
	struct akun * next;
};
akun *front = NULL, *rear = NULL, *temp;
admin *head = NULL, *tail = NULL, *top, *del;
// PROCESSING ADMIN
// fungsi untuk menambahkan data di awal dengan linked list
void insertfirst(admin**head, admin**tail){
	admin *newnode = new admin();
	cout << "Nomer Mobil         : "; cin >> newnode->nomer;
	cout << "Plat Mobil          : "; fflush(stdin);getline(cin,newnode->plat);
    cout << "Merk Mobil          : "; fflush(stdin);getline(cin,newnode->merk);
    cout << "Warna Mobil         : "; fflush(stdin);getline(cin,newnode->warna);
    cout << "Tahun Keluaran      : "; cin >> newnode->keluaran;
    cout << "Harga Mobil         : "; cin >> newnode->harga;
    cout << endl;
    if (*head == NULL){
    	*head = newnode;
    	*tail = newnode;
	}
	else {
		newnode->prev = NULL;
		newnode->next = *head;
		(*head)->prev = newnode;
		(*head)= newnode;
	}
}
// fungsi untuk menambahkan data sesuai posisi yang diinginkan dengan linked list
void insertmid(admin**head, admin**tail){
	int tengah;
	admin *newnode = new admin();
	admin *bantu, *bantu2;
	if (*head != NULL){
		cout << "Tambah Data Setelah Nomer Mobil Ke- ? "; cin >> tengah;
		cout << "Nomer Mobil         : "; cin >> newnode->nomer;
		cout << "Plat Mobil          : "; fflush(stdin);getline(cin,newnode->plat);
	    cout << "Merk Mobil          : "; fflush(stdin);getline(cin,newnode->merk);
	    cout << "Warna Mobil         : "; fflush(stdin);getline(cin,newnode->warna);
	    cout << "Tahun Keluaran      : "; cin >> newnode->keluaran;
	    cout << "Harga Mobil         : "; cin >> newnode->harga;
	    cout << endl;
	    newnode->next = NULL;
	    newnode->prev = NULL;
	    bantu = *head;
	    while (bantu->nomer != tengah){
	    	bantu = bantu->next;
	    	cout << "tidak ada kode tersebut\n" << endl;
	    	return;
		}
		bantu2 = bantu->next;
		newnode->next = bantu2;
		bantu2->prev = newnode;
		bantu->next = newnode;
		newnode->prev = bantu;
	}
	else {
		cout << "Nomer Mobil         : "; cin >> newnode->nomer;
		cout << "Plat Mobil          : "; fflush(stdin);getline(cin,newnode->plat);
	    cout << "Merk Mobil          : "; fflush(stdin);getline(cin,newnode->merk);
	    cout << "Warna Mobil         : "; fflush(stdin);getline(cin,newnode->warna);
	    cout << "Tahun Keluaran      : "; cin >> newnode->keluaran;
	    cout << "Harga Mobil         : "; cin >> newnode->harga;
	    cout << endl;
	    if (*head == NULL){
	    	*head = newnode;
	    	*tail = newnode;
	    }
	}
}
// fungsi untuk menambahkan data di akhir dengan linked list
void insertlast(admin**head, admin**tail){
	admin *newnode = new admin();
	cout << "Nomer Mobil         : "; cin >> newnode->nomer;
	cout << "Plat Mobil          : "; fflush(stdin);getline(cin,newnode->plat);
    cout << "Merk Mobil          : "; fflush(stdin);getline(cin,newnode->merk);
    cout << "Warna Mobil         : "; fflush(stdin);getline(cin,newnode->warna);
    cout << "Tahun Keluaran      : "; cin >> newnode->keluaran;
    cout << "Harga Mobil         : "; cin >> newnode->harga;
    cout << endl;
    if (*head == NULL){
    	*head = newnode;
    	*tail = newnode;
	}
	else {
		newnode->prev = *tail;
		newnode->next = NULL;
		(*tail)->next = newnode;
		*tail = newnode;
	}
}
// fungsi untuk menampilkan data mobil dari awal input
void forward(admin *head){
	if(head== NULL){
		cout << "\n   BELUM ADA DATA YANG DITAMBAHKAN    \n" << endl;
		cout << "silahkan masukkan data terlebih dahulu\n";
		return;
		system("pause");
	}
	else {
		while (head != NULL) {
			cout << " \nTAMPILAN DATA MOBIL DI SHOWROOM " << endl;
			cout << "----------------------------------------------" << endl;
			cout << "Nomer Mobil          : " << head->nomer << endl;
			cout << "Plat Mobil           : " << head->plat << endl;
		    cout << "Merk Mobil           : " << head->merk << endl;
		    cout << "Warna Mobil          : " << head->warna << endl;
		    cout << "Tahun Keluaran       : Tahun " << head->keluaran << endl;
		    cout << "Harga Mobil          : Rp." << head->harga << endl;    
			head = head->next;
		}
		cout << endl;
	}
}
// fungsi untuk mengupdate / mengganti data mobil
void update(admin**head){
	bool ketemu = false;
	int old;
	admin *temp = *head;
	cout << "Nomer Mobil Yang Ingin Anda Update ? "; cin >> old;
	while (temp != NULL){
		if  (temp->nomer == old){
			ketemu = true;
			cout << "\nEDIT DATA MOBIL" << endl;
			cout << "Nomer Mobil         : "; cin >> temp->nomer;
			cout << "Plat Mobil          : "; fflush(stdin);getline(cin,temp->plat);
		    cout << "Merk Mobil          : "; fflush(stdin);getline(cin,temp->merk);
		    cout << "Warna Mobil         : "; fflush(stdin);getline(cin,temp->warna);
		    cout << "Tahun Keluaran      : "; cin >> temp->keluaran;
		    cout << "Harga Mobil         : "; cin >> temp->harga;  
			cout<<"\nDATA BERHASIL DI EDIT\n" << endl;
		}
	temp = temp->next;
	}
	if (ketemu == false){
		cout << "\nMAAF DATA MOBIL " << old << " TIDAK DITEMUKAN\nTEKAN ENTER UNTUK MELANJUTKAN\n"<< endl;
	}
}
// fungsi untuk menghapus data mobil diawal dengan linked list
void delfirst(admin**head, admin**tail){
	if (*head == NULL){
		cout << "\n   BELUM ADA DATA YANG DITAMBAHKAN    \n" << endl;
		cout << "silahkan masukkan data terlebih dahulu\n";
		return;
		system("pause");
	}
	else {
		if (*head == *tail){
			*head = NULL;
			*tail = NULL;
			cout << "\nData Telah Terhapus !\n";
		}
		else {
			del = *head;
			*head = (*head)->next;
			(*head)->prev = NULL;
			delete del;
			cout << "\nData Telah Terhapus !\n";
		}
	}
}
// fungsi untuk menghapus data mobil dengan posisi tertentu dengan linked list
void delmid(admin**head, admin**tail){
	int old;
	admin *bantu = *head;
	if (*head == NULL){
		cout << "\n   BELUM ADA DATA YANG DITAMBAHKAN    \n" << endl;
		cout << "silahkan masukkan data terlebih dahulu\n";
		return;
		system("pause");
	}
	else {
		if (*head == *tail){
			*head = NULL;
			*tail = NULL;
			return;
			cout << "\nData Telah Terhapus !\n";
		}
		else {
			cout << "Hapus Nomer Mobil Setelah Plat Mobil Ke- "; cin >> old;
			if ((*head)->nomer == old){
				del = bantu->next;
				bantu->next = del->next;
				delete del;
				cout << "\nData Telah Terhapus !\n";
				return;
			}
			bantu = bantu->next;
			cout << "\nTidak Ada Kode Tersebut\n" << endl;
			return;
		}
	}
}
// fungsi untuk menghapus data mobil diakhir dengan linked list
void dellast(admin**head, admin**tail){
	if (*head == NULL){
		cout << "\n   BELUM ADA DATA YANG DITAMBAHKAN    \n" << endl;
		cout << "silahkan masukkan data terlebih dahulu\n";
		return;
		system("pause");
	}
	else {
		if (*head == *tail){
			*head = NULL;
			*tail = NULL;
			cout << "\nData Telah Terhapus !\n";
		}
		else {
			del = *tail;
			*tail = (*tail)->prev;
			(*tail)->next = NULL;
			delete del;
			cout << "\nData Telah Terhapus !\n";
		}
	}
}
// fungsi untuk mengecek list untuk melakukan merge sort
admin* mergeList(admin*x, admin*y) {
   admin* newhead = NULL;
   if(x == NULL)
      return y;
   if(y == NULL)
      return x;
   if(x->nomer <= y->nomer) {
      newhead = x;
      newhead->next = mergeList(x->next,y);
   } else {
      newhead = y;
      newhead->next = mergeList(x,y->next);
   }
   return newhead;
}
void splitList(admin* start, admin** x,admin** y) {
   admin* slow = start;
   admin* fast = start->next;
   while(fast!= NULL) {
      fast = fast->next;
      if(fast!= NULL) {
         slow = slow->next;
         fast = fast->next;
      }
   }
   *x = start;
   *y = slow->next;
   slow->next = NULL;
}
// fungsi untuk melakukan sorting dengan metode merge sort
void mergeSort(admin** start) {
   admin* head = *start;
   admin* x,*y;
   if(head == NULL || head->next == NULL) {
      return;
   }
   splitList(head,&x,&y);
   mergeSort(&x);
   mergeSort(&y);
   *start = mergeList(x,y);
   cout << "\nDATA TELAH DI SORTING\nSILAHKAN LIHAT MENU TAMPIL DATA\n" << endl;
   return;
}
int searchlist(admin**head, int x){
	admin *temp = *head;
	int found = 0;
	int i = 0;
	if (temp != NULL){
		while(temp != NULL){
			i++;
			if (temp->nomer == x){
				found++;
				break;
			}
			temp = temp->next;
		}
		if (found == 1){
			return i;
		}
	}
}
int searching(admin**head, int x){
	admin *temp = *head;
	int i = 0;
	int found = 0;
	int fibM2 = 0;
	int fibM1 = 1;
	int fibM = fibM2 + fibM1;
	
	if (temp != NULL){
		while (temp != NULL){
			i++;
			if (temp == (*head)->next){
				found++;
				break;
			}
			temp = temp->next;
		}
	
		while(fibM < i){
			fibM2 = fibM1;
			fibM1 = fibM;
			fibM = fibM2 + fibM1;
		}
		
		int offset = -1;
		
		while (fibM > 1){
			int i = min(offset + fibM2, i-1);
			
			if (i < x){
				fibM = fibM1;
				fibM1 = fibM2;
				fibM2 = fibM - fibM1;
				offset = i;
			}
			else if (i > x){
				fibM = fibM2;
				fibM1 = fibM1 - fibM2;
				fibM2 = fibM - fibM1;
			}
			else return i;
		}
		return i;
	}
}
// fungsi menu histori pengunjung
void histori_pengunjung(akun*front){
	if(front == NULL){
		cout << "\n   BELUM ADA DATA YANG DITAMBAHKAN    \n" << endl;
		cout << "silahkan masukkan data terlebih dahulu\n";
		return;
		system("pause");
	}
	while( front != NULL){
		cout << "---DAFTAR AKUN USER---" << endl;
		cout << "======================" << endl;
		cout << "Nama Pengguna    : " << front->nama << endl;
		cout << "No. KTP          : " << front->no << endl;
		cout << "Pekerjaan        : " << front->pekerjaan << endl;
		cout << "Alamat           : " << front->alamat << endl;
		cout << "======================\n" << endl;
		front = front->next;
	}
	cout << endl;
}
// fungsi Dequeue pada menu akun
void dequeue(akun**front){
	if(*front == NULL){
		cout << "Tidak Ada Antrian Pengiriman" << endl;
		return;
	}
	while(*front != NULL){
		akun *temp = *front;
		*front = (*front)->next;
		delete temp;
	}
	cout << "Pesanan Pelanggan Telah Terkirim\nPer 20 Desember 2021" << endl;
}
// fungsi untuk login ke menu admin
bool login(){
	string username; // deklarasi type data username
	string password; // deklarasi type data password
	system("color 1F"); // untuk memberikan tampilan warna untuk background dan text di output
	for (int i = 0; i <= 2; i++){ // melakukan perulangan
		cout << "------LOGIN ADMIN------" << endl;
		cout << "=======================" << endl;
		cout << " >> Username  : "; cin >> username;
		cout << " >> Password  : "; cin >> password;
		if (username == "admin" && password == "123"){ // jika username dan password true maka akan dilanjutkan ke menu selanjutnya
			return true;
		}
		else { // jika username atau password ada yang salah masuk ke menu ini
			if ((3-(i+1)) == 0){
				cout << "\nBatas Percobaan Telah Habis ! \n\n"; // tampilan yang akan di tampilkan jika percobaan sudah 3x
				system("pause");
				system("cls");
			}
			else {
				cout << "\nUsername atau Password salah!\n> Batas Percobaan Tersisa  "<< 3-(i+1) <<"\n\n"; // tampilan untuk jika percobaan
				cout << "\n ! Silahkan Coba Lagi !\n! Silahkan tekan ENTER ! "; getch();				   // kurang dari 3x
				system("cls");
			}
		}
	}
	return false;
}
// fungsi untuk menu admin
void Admin(){
	int x;
	int pilih; // deklarasi type data pilih
	bool ulang = true; // pendeklarasian variabel ulang sebagai true
	while(ulang){ // perulangan
		system("cls"); // fungsi untuk menghapus terminal
		system("color 4F"); // untuk memberikan tampilan warna untuk background dan text di output
		cout << "\nSHOWROOM PENJUALAN MOBIL" << endl;
		cout << "--------------------------" << endl;
		cout << "[1]  Tambah Data Mobil di Awal" << endl;
		cout << "[2]  Tambah Data Mobil di tengah" << endl;
		cout << "[3]  Tambah Data Mobil di Akhir" << endl;
		cout << "[4]  Tampilkan Data Mobil" << endl;
		cout << "[5]  Ubah Pesanan Mobil" << endl;
		cout << "[6]  Hapus Data Mobil di awal" << endl;
		cout << "[7]  Hapus Data Mobil di tengah" << endl;
		cout << "[8]  Hapus Data Mobil di akhir" << endl;
		cout << "[9]  Sorting Data Mobil" << endl;
		cout << "[10] Searching data Mobil" << endl;
		cout << "[11] Histori Akun User" << endl;
		cout << "[12] Kirim Pesanan Pelanggan" << endl;
		cout << "[13] Tentang Program" << endl;
		cout << "[0]  Keluar\n" << endl;
		cout << "PILIH [0-13] : "; cin >> pilih;system("cls");
		switch (pilih){ 										// percabangan sesuai dengan menu yang dipilih
			case 13:
				cout << "TENTANG PROGRAM\n" << endl;
				cout << "JUDUL ( SHOWROOM PENJUALAN MOBIL )" << endl;
				cout << "NAMA ANGGOTA : " << endl;
				cout << "	ANGGOTA 1 -> GILANG YUDA PRATAMA       -- 2009106119" << endl;
				cout << "	ANGGOTA 2 -> MUHAMMAD AZADIN NOOR      -- 2009106129" << endl;
				cout << "	ANGGOTA 3 -> MUHAMMAD NUR ACHWAN PASLA -- 2009106133" << endl;
				cout << "KELAS        : INFORMATIKA C 2020" << endl;
				cout << "MATA KULIAH  : PRAKTIKUM STRUKTUR DATA DAN ANALISIS ALGORITMA \n" << endl;
				system("pause");
				break;
			case 1:
				insertfirst(&head, &tail);
				system("pause");
				break;
			case 2:
				insertmid(&head, &tail);
				system("pause");
				break;
			case 3:
				insertlast(&head, &tail);
				system("pause");
				break;
			case 4:
				forward(head);
				system("pause");
				break;
			case 5:
				update(&head);
				system("pause");
				break;
			case 6:
				delfirst(&head, &tail);
				system("pause");
				break;
			case 7:
				delmid(&head, &tail);
				system("pause");
				break;
			case 8:
				dellast(&head, &tail);
				system("pause");
				break;
			case 9:
				mergeSort(&head);
				system("pause");
				break;
			case 10:
				cout << "Nomer Mobil Yang Anda Cari = "; cin >> x;
				cout << "Ditemukan di Index : " << (searching(&head, x) - searchlist(&head,x) ) << endl;
				system("pause");
				break;
			case 11:
				histori_pengunjung(front);
				system("pause");
				break;
			case 12:
				dequeue(&front);
				system("pause");
				break;
			case 0:
				cout << " " << endl;
				return;
			default :
				cout << "Anda Memasukkan selain Angka diatas\nSilahkan Inputkan Kembali\n" << endl;
				system("pause");
				break;
		}
	}
}

// PROCESSING USER
// fungsi untuk login user
bool login_user(akun**front){
	akun *temp = *front;
	int Username; // deklarasi type data username
	int Password; // deklarasi type data password
	system("color 1F"); // untuk memberikan tampilan warna untuk background dan text di output
	if (*front == NULL){
		cout << "\n   BELUM ADA DATA YANG DITAMBAHKAN    \n" << endl;
		cout << "silahkan masukkan data terlebih dahulu\n";
		system("pause"); system("cls");
		return false;
	}
	for (int i = 0; i <= 2; i++){ // melakukan perulangan
		cout << "------LOGIN USER------" << endl;
		cout << "=======================" << endl;
		cout << " >> Username  : "; cin >> Username;
		cout << " >> Password  : "; cin >> Password;
		if (temp->username == Username && temp->password == Password){ // jika username dan password true maka akan dilanjutkan ke menu selanjutnya
			return true;
		}
		else { // jika username atau password ada yang salah masuk ke menu ini
			if ((3-(i+1)) == 0){
				cout << "\nBatas Percobaan Telah Habis ! \n\n"; // tampilan yang akan di tampilkan jika percobaan sudah 3x
				system("pause");
				system("cls");
			}
			else {
				cout << "\nUsername atau Password salah!\n> Batas Percobaan Tersisa  "<< 3-(i+1) <<"\n\n"; // tampilan untuk jika percobaan
				cout << "\n ! Silahkan Coba Lagi !\n! Silahkan tekan ENTER ! "; getch();				   // kurang dari 3x
				system("cls");
			}
		}
	}
	return false;
}
// fungsi Enqueue pada menu akun
void enqueue(akun **front, akun **rear){
	akun * data = new akun();
	cout << "---DAFTAR AKUN USER---" << endl;
	cout << "======================" << endl;
	cout << "Nama Pengguna    : "; fflush(stdin);getline(cin,data->nama);
	cout << "No. KTP          : "; cin >> data->no;
	cout << "Pekerjaan        : "; fflush(stdin);getline(cin,data->pekerjaan);
	cout << "Alamat           : "; fflush(stdin);getline(cin,data->alamat);
	cout << "Username         : "; cin >> data->username;
	cout << "Password (angka) : "; cin >> data->password;
	cout << "======================\n" << endl;
	cout << "Anda Telah Terdaftar Sebagai Pelanggan\nShowroom Mobil Samarinda\n" << endl;
	if(*front == NULL){
		*front = data;
	}
	else {
		(*rear)->next = data;
	}
	*rear = data;
}
// fungsi transaksi pelanggan
void transaksi(admin *head){
	admin *temp = head;
	int fee, norek;
	string nohp;
	bool test = true;
	bool ketemu = false;
	int found = 0;
	float pajak;
	float total;
	char lanjut;
	string in;
	cout << " \nDAFTAR MOBIL & TAHUN KELUARAN" << endl;
	cout << "--------------------------------" << endl;
	while (head != NULL) {
		cout << "- " << head->merk << "\t Tahun " << head->keluaran << endl; 
		head = head->next;
	}
	cout << " " << endl;
	cout << "Silahkan Pilih Mobil " << endl;
	cout << "(Pilihan sesuai nama merk mobil)\n=================================\n >> "; fflush(stdin);getline(cin,in);
	while(temp != NULL){
		if (temp->merk == in){
			found++;
			break;
		}
		temp = temp->next;
	}
	if (found == 1){
		cout << "===================================================" << endl;
		cout << "\nTRANSAKSI PEMBELIAN MOBIL DI SHOWROOM" << endl;
		cout << "=============+=====================" << endl;
		cout << " Merk Mobil  | " << temp->merk << endl;
		cout << "=============+=====================" << endl;
		cout << " Plat Polisi | " << temp->plat << endl;
		cout << "=============+=====================" << endl;
		cout << " Tahun       | " << temp->keluaran << endl;
		cout << "=============+=====================" << endl;
		cout << " Warna Mobil | " << temp->warna << endl;
		cout << "===================================\n" << endl;
		
		pajak = temp->harga * 0.001;
		total = temp->harga + pajak;
		cout << "Harga Mobil    : Rp. " << temp->harga << endl;
		cout << "Pajak 1%       : Rp. " << pajak << endl;
		cout << "---------------------------------- +" << endl;
		cout << "TOTAL          : Rp. " << total << endl;
		cout << "\n\n Apakah Ingin Melanjutkan Pembayaran ?\n (y/n)\n >> "; cin >> lanjut; system("cls");
		while (test){
			cout << "    MENU TAHAP PEMBAYARAN" << endl;
			cout << " ---------------------------" << endl;
			cout << " 1. COD (Cash On Deal)\n 2. Via BCA\n 3. Via BNI\n 4. Via BRI\n PILIH [1-4] : "; cin >> fee; 
			if (fee == 2 && fee == 3 && fee == 4 ){
				cout << "\n\n Masukkan No Rekening : "; cin >> norek;
				cout << "\n Nomer Handphone      : "; cin >> nohp;
				cout << "\n\n      Permintaan Anda Sedang di Proses" << endl;
				cout << " Untuk informasi Pengiriman Akan di hubungi" << endl;
				cout << "============================================" << endl; system("pause"); system("cls");
				cout << "========================================================================================================" << endl;
				cout << "||                                                                                                    ||" << endl;
				cout << "||        <<<<<<<>>>>>>>   <<<<<<>>>>>>   <<<<<<>>>>>>    <>    <>          <>   <<<<<<>>>>>>         ||" << endl;
				cout << "||              <>         <>             <>        <>          <><>      <><>   <>        <>         ||" << endl;
				cout << "||              <>         <>             <>        <>    <>    <>  <>  <>  <>   <>        <>         ||" << endl;
				cout << "||              <>         <<<<<<>>>>>>   <<<<<<>>>>>>    <>    <>    <>    <>   <<<<<<>>>>>>         ||" << endl;
				cout << "||              <>         <>             <>   <>         <>    <>          <>   <>        <>         ||" << endl;
				cout << "||              <>         <>             <>      <>      <>    <>          <>   <>        <>         ||" << endl;
				cout << "||              <>         <<<<<<>>>>>>   <>        <>    <>    <>          <>   <>        <>         ||" << endl;
				cout << "||                                                                                                    ||" << endl;
				cout << "||                    <>       <>   <<<<<<>>>>>>   <<<<<<>>>>>>    <>    <>        <>                 ||" << endl;
				cout << "||                    <>     <>     <>        <>   <>                    <>        <>                 ||" << endl;
				cout << "||                    <>   <>       <>        <>   <>              <>    <>        <>                 ||" << endl;
				cout << "||                    <> <>         <<<<<<>>>>>>   <<<<<<>>>>>>    <>    <<<<<<>>>>>>                 ||" << endl;
				cout << "||                    <>   <>       <>        <>             <>    <>    <>        <>                 ||" << endl;
				cout << "||                    <>     <>     <>        <>             <>    <>    <>        <>                 ||" << endl;
				cout << "||                    <>      <>    <>        <>   <<<<<<>>>>>>    <>    <>        <>                 ||" << endl;
				cout << "||                                                                                                    ||" << endl;
				cout << "========================================================================================================" << endl; system("pause"); system("cls");
				return;
				return;
			}
			else if (fee == 1){
				cout << "\n\n          Permintaan Anda Sedang di Proses" << endl;
				cout << "        Untuk informasi Pengiriman Akan di hubungi" << endl;
				cout << " Silahkan Tinggalkan Nomer Handphone Yang Bisa di Hubungi\n >> "; cin >> nohp;
				cout << "\n ==========================================================\n"; system("pause"); system("cls");
				cout << "========================================================================================================" << endl;
				cout << "||                                                                                                    ||" << endl;
				cout << "||        <<<<<<<>>>>>>>   <<<<<<>>>>>>   <<<<<<>>>>>>    <>    <>          <>   <<<<<<>>>>>>         ||" << endl;
				cout << "||              <>         <>             <>        <>          <><>      <><>   <>        <>         ||" << endl;
				cout << "||              <>         <>             <>        <>    <>    <>  <>  <>  <>   <>        <>         ||" << endl;
				cout << "||              <>         <<<<<<>>>>>>   <<<<<<>>>>>>    <>    <>    <>    <>   <<<<<<>>>>>>         ||" << endl;
				cout << "||              <>         <>             <>   <>         <>    <>          <>   <>        <>         ||" << endl;
				cout << "||              <>         <>             <>      <>      <>    <>          <>   <>        <>         ||" << endl;
				cout << "||              <>         <<<<<<>>>>>>   <>        <>    <>    <>          <>   <>        <>         ||" << endl;
				cout << "||                                                                                                    ||" << endl;
				cout << "||                    <>       <>   <<<<<<>>>>>>   <<<<<<>>>>>>    <>    <>        <>                 ||" << endl;
				cout << "||                    <>     <>     <>        <>   <>                    <>        <>                 ||" << endl;
				cout << "||                    <>   <>       <>        <>   <>              <>    <>        <>                 ||" << endl;
				cout << "||                    <> <>         <<<<<<>>>>>>   <<<<<<>>>>>>    <>    <<<<<<>>>>>>                 ||" << endl;
				cout << "||                    <>   <>       <>        <>             <>    <>    <>        <>                 ||" << endl;
				cout << "||                    <>     <>     <>        <>             <>    <>    <>        <>                 ||" << endl;
				cout << "||                    <>      <>    <>        <>   <<<<<<>>>>>>    <>    <>        <>                 ||" << endl;
				cout << "||                                                                                                    ||" << endl;
				cout << "========================================================================================================" << endl; system("pause"); system("cls");
				return;
				return;
			}
			else {
				cout << "\n\n Pilihan Tersebut tidak ada di menu\nSilahkan Masukkan Pilihan yang Benar !" << endl; system("cls");
				
			}
		}
		
	}
	else {
		cout << "\nMAAF DATA MOBIL " << in << " TIDAK DITEMUKAN\nTEKAN ENTER UNTUK MELANJUTKAN\n"<< endl;
	}
}
void isi(){
	char p;
	bool bisa = true; // pendeklarasian variabel ulang sebagai true
	system("color 74");
	while(bisa){ // perulangan
		cout << "========================================================" << endl;
		cout << "| SELAMAT DATANG DI SHOWROOM PENJUALAN MOBIL SAMARINDA |" << endl;
		cout << "|       Penjualan Mobil Mobil Second Berkualitas       |" << endl;
		cout << "========================================================\n\n" << endl;
		cout << "1. Lihat Daftar Mobil" << endl;
		cout << "2. Transaksi Pembelian" << endl;
		cout << "0. Keluar" << endl;
		cout << "PILIH [0-2] : "; cin >> p;system("cls");
		switch (p){
			case '0':
				system("cls");
				return;
				break;
			case '1':
				forward(head);
				system("pause"); system("cls");
				break;
			case '2':
				transaksi(head);
				system("pause"); system("cls");
				break;
			default :
				cout << "Menu tersebut Tidak ada \n" << endl;
				system("pause");
				system("cls");
				system("color F0");
		}
	}
}
// fungsi menu utama pelanggan
void pelanggan(){
	char q;
	bool coba = true;
	system("color F0");
	while(coba){
		cout << "========================================================" << endl;
		cout << "| SELAMAT DATANG DI SHOWROOM PENJUALAN MOBIL SAMARINDA |" << endl;
		cout << "|       Penjualan Mobil Mobil Second Berkualitas       |" << endl;
		cout << "========================================================\n\n" << endl;
		cout << "\n[1] Daftar" << endl;
		cout << "[2] Login\n[0] Keluar\n" << endl;
		cout <<"Pilihan [0-2]	: "; cin >> q; system("cls");
		switch (q){
			case '0':
				system("cls");
				return ;
				break;
			case '1':
				enqueue(&front,&rear);
				system("pause"); system("cls");
				break;
			case '2':
				if (login_user(&front)){
					system("pause");
					system("cls");
					isi();
				}
				break;
			default :
				cout << "Menu tersebut Tidak ada \n" << endl;
				system("pause");
				system("cls");
		}
	}
}
// menu utama program
void menu_utama(){
	char pilihan;
	system("color 0F");
	cout << "-----MENU UTAMA-----" << endl;
	cout << "====================" << endl;
	cout << "1. Admin\n2. User\n3. Exit" << endl;
	cout << "Pilih [1-2] : "; cin >> pilihan; 
	if (pilihan == '1'){
		system("cls");
		if (login()){
			Admin();	
		}
		menu_utama();
	}
	else if (pilihan == '2'){
		system("cls");
		pelanggan();
		system("cls");
		menu_utama();
	}
	else if (pilihan == '3'){
		system("exit");
	}
	else {
		cout << "\nMasukkan Anda Salah\nSilahkan Coba Lagi !\n" << endl;
		system("pause");
		system("cls");
		menu_utama();
	}
}
// int main()
int main(){
	menu_utama();
}
