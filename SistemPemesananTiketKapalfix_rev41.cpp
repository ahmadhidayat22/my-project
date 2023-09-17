#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <limits>
#include <conio.h>

using namespace std;

struct akun_admin{
    string username;
    string password;
};akun_admin ad;

struct akun_user{
    string username;
    string password;
};akun_user au[100];

typedef struct{
    string username, asal, tujuan, status;
    int harga, id, tiket;
}data_tiket_user;
data_tiket_user dtu[100];

struct datas{
	string asal,tujuan;
	int harga;
};
datas datap[100];
int n = sizeof(au)/sizeof(*au);
int n1 = sizeof(dtu)/sizeof(*dtu);
int jumlah_akun = 0;
int jumlah_tiket_user = 0;
int jumlah_pesan = 1001;
int jumlah_data = 0;

void login();
string cek_login(string pisah);
void regis();
string uppercase(string x);
void read_akun();
void menu_user(string user);
void selectionSort(string user);
void insertionsortId(string user);
void insertionsortHarga(string user);
void pesan_tiket(string user);
void hapus_tiket(string user);
void lihat_pesan(string user);
void bayar_tiket(string user);
void ganti_tiket_user();
void lihat_belum_pesan(string user);
void create();
void read_tiket_user(string user);
bool is_all_digits(const string& s);
void read_tiket();
void inti(string user);
void update();
void ganti();
void display();
void Delete();

int main(){
    ad = {"q", "q"};
    string pilih;
    while(true){
        system("cls");
        cout<<"SISTEM PEMESANAN TIKET KAPAL"<<endl;
        cout<<"    ================="<<endl;
        cout<<"    | 1. login      |"<<endl;
        cout<<"    | 2. registrasi |"<<endl;
        cout<<"    | 3. exit       |"<<endl;
        cout<<"    ================="<<endl;
        cout<<"silahkan pilih menu di atas > ";cin>>pilih;
        if(pilih == "1"){
            login();
        }else if(pilih == "2"){
            regis();
        }else if(pilih == "3"){
            return 0;
        }else{
            cout<<"masukkan pilihan sesuai dengan menu !!!\n\n"<<endl;
            cout<<"Tekan sembarang untuk melanjutkan\n";getch();
        }
    }
}
string cek_login(string pisah){
    string user, akun, login;
    ifstream file;
    file.open("data_akun.csv", ios::in);
    if(file.is_open()){
        while(getline(file, akun)){
            stringstream str(akun);
            getline(str, user);
            if(user == pisah){
                login = user;
            }
        }
    }
    file.close();
    return login;
}
void login(){
    string username, password, user;
    int salah = 0;
    while(true){
        system("cls");
        cout << " ======="<<endl;
        cout << "| LOGIN |"<<endl;
        cout << " ======="<<endl;
        cout << "Masukan username: "; fflush(stdin); getline(cin, username);
        cout << "Masukan password: "; fflush(stdin); getline(cin, password);
        string pisah = username + "|" + password;
        jumlah_data = 0;
        jumlah_tiket_user = 0;
        jumlah_akun = 0;
        read_tiket_user(username);
        read_tiket();
        user = cek_login(pisah);
        if (pisah == user){
            salah = 0;
            read_akun();
            menu_user(username);
        }
        else if(username == ad.username && password == ad.password){
            salah = 0;
            inti(username);
        }
        else{
            cout << "Username atau password salah"<<endl;
            salah++;
            if(salah == 3){
                cout << "Anda akan dikeluarkan"; getch();
                exit(0);
            }
            else{
                string pilih;
                cout << "Ingin Mengulang?(y/n)"; fflush(stdin); getline(cin, pilih);
                if(pilih != "y"){
                    salah = 0;
                    break;
                }
            }
        }
    }
}
void read_akun(){
    ifstream file;
	file.open("data_akun.csv", ios::in);
	string username, password, isi;
	int harga_int;
	if(file.is_open()){
		while(getline(file,isi)){
			stringstream str(isi);
			getline(str, username,'|');
			getline(str, password,'\n');
			au[jumlah_akun].username = username;
			au[jumlah_akun].password = password;
			jumlah_akun++;  
		}
	}
	file.close();
}
void regis(){
    string username, password, pilih, isi, user;
    bool found = false;
    ifstream infile;
    ofstream outfile;
    infile.open("data_akun.csv");
    outfile.open("data_akun.csv", ios::out | ios::app );
    while(true){
        system("cls");
        cout << " ================="<<endl;
        cout << "| REGISTRASI AKUN |"<<endl;
        cout << " ================="<<endl;
        cout<<"masukkan username anda   > ";fflush(stdin); getline(cin, username);
        while(getline(infile,isi)){
            stringstream str(isi);
            getline(str, user,'|');
            if(user == username){
                found = true;
            }
        }
        if (found){
            cout << "Nama tersebut sudah terdaftar"; getch();
            break;
        }
        else{
            cout<<"masukkan password anda   > ";fflush(stdin); getline(cin, password);  
            cout << "Apakah anda yakin ingin mendaftarkan akun tersebut?(y/n) "; fflush(stdin); getline(cin, pilih);
            if(pilih == "y"){
                outfile << username<<"|";
                outfile << password<<endl;
                au[jumlah_akun].username = username;
                au[jumlah_akun].password = password;
                jumlah_akun++;
            }
            break;
        }
    }
    infile.close();
    outfile.close();
    main();
}
void insertionsortId(string user){
    int i, key, j, key5, key6;
    string key1, key2, key3, key4, key7;
    for (i = 1; i < jumlah_tiket_user; i++){
        key = dtu[i].id;
        key1 = dtu[i].username;
        key3 = dtu[i].asal;
        key4 = dtu[i].tujuan;
        key5 = dtu[i].harga;
        key6 = dtu[i].tiket;
        key7 = dtu[i].status;
        j = i-1;
        while (j >= 0 && dtu[j].id > key){
            dtu[j+1].id = dtu[j].id;
            dtu[j+1].username = dtu[j].username;
            dtu[j+1].asal = dtu[j].asal;
            dtu[j+1].tujuan = dtu[j].tujuan;
            dtu[j+1].harga = dtu[j].harga;
            dtu[j+1].tiket = dtu[j].tiket;
            dtu[j+1].status = dtu[j].status;
            j = j-1;
        }
        dtu[j+1].id = key;
        dtu[j+1].username = key1;
        dtu[j+1].asal = key3;
        dtu[j+1].tujuan = key4;
        dtu[j+1].harga = key5;
        dtu[j+1].tiket = key6;
        dtu[j+1].status = key7;
    }
    ganti_tiket_user();
}
void read_tiket_user(string user){
    ifstream file;
	file.open("tiket_user.csv", ios::in);
	string isi,id, username,asal,tujuan,harga,tiket,harga_string, tiket_string, status;
	int harga_int, jumlah = 0, nomor_int, tiket_int;
	if(file.is_open()){
		while(getline(file,isi)){
			stringstream str(isi);
            getline(str, id, '|');
            getline(str, username, '|');
			getline(str, asal,'|');
			getline(str, tujuan,'|');
			getline(str, harga,'|');
            getline(str, tiket, '|');
            getline(str, status, '\n');
            stringstream nomor(id);
			stringstream harga_string(harga);
            stringstream tiket_string(tiket);
            nomor >> nomor_int;
			harga_string>> harga_int;
            tiket_string >> tiket_int;
            dtu[jumlah_tiket_user].id = nomor_int;
            dtu[jumlah_tiket_user].username = username;
            dtu[jumlah_tiket_user].asal = asal;
            dtu[jumlah_tiket_user].tujuan = tujuan;
            dtu[jumlah_tiket_user].harga = harga_int;
            dtu[jumlah_tiket_user].tiket = tiket_int;
            dtu[jumlah_tiket_user].status = status;
            jumlah_tiket_user++;
		}
	}
	file.close();
}
void pesan_tiket(string user){
    string pilih, berapa;
    int pilih1, berapa1;
    string ulang;
    ofstream file;
    file.open("tiket_user.csv", ios::out | ios::app);
    if(jumlah_tiket_user < n1 && jumlah_data > 0){
        while(true){
            system("cls");
            display();
            cout<<endl;
            cout << "KETIK 'kembali' JIKA SELESAI MEMESAN \n"<<endl;
            cout << "Pilih nomor tiket yang ingin anda pesan: "; cin >> pilih;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(is_all_digits(pilih)){
                pilih1 = stoi(pilih);
                if(pilih1 > 0 && pilih1 <= jumlah_data){
                    while(true){
                        system("cls");
                        cout << "KETIK 'kembali' JIKA TIDAK JADI MEMESAN"<<endl;
                        cout << "BATAS TIKET YANG DAPAT DIPESAN UNTUK SETIAP PESANAN ADALAH 15"<<endl;
                        cout << "Ingin pesan berapa tiket? "; cin >> berapa;
                        if(is_all_digits(berapa)){
                            berapa1 = stoi(berapa);
                            if(berapa1 > 0 && berapa1 <= 15){
                                for(int i = 0; i < jumlah_data; i++){
                                    if(pilih1 == i+1){
                                        for(int j = 0; j<jumlah_tiket_user; j++){
                                            if(jumlah_pesan == dtu[j].id){
                                                jumlah_pesan++;
                                                j = -1;
                                            }
                                        }
                                        dtu[jumlah_tiket_user].id = jumlah_pesan;
                                        dtu[jumlah_tiket_user].username = user;
                                        dtu[jumlah_tiket_user].asal = datap[i].asal;
                                        dtu[jumlah_tiket_user].tujuan = datap[i].tujuan;
                                        dtu[jumlah_tiket_user].harga = datap[i].harga;
                                        dtu[jumlah_tiket_user].tiket = berapa1;
                                        dtu[jumlah_tiket_user].status = "Belum dibayar";
                                        
                                        file << jumlah_pesan<<"|";
                                        file << user<<"|";
                                        file << datap[i].asal<<"|";
                                        file << datap[i].tujuan<<"|";
                                        file << datap[i].harga<<"|";
                                        file << berapa1<<"|";
                                        file << "Belum dibayar\n";
                                        jumlah_tiket_user++;
                                    }
                                }
                                cout << "TIKET BERHASIL DIPESAN"; getch();
                                break;
                            }
                            else{
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                        else if(berapa == "kembali"){
                            break;
                        }
                        else{
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                }
            }
            else if(pilih == "kembali"){
                break;
            }
            else{
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    else if(jumlah_tiket_user > n){
        cout << "MEMORI PENUH"; getch();
    }
    else if(jumlah_tiket_user < n && jumlah_data <= 0){
        cout << "MOHON MAAF KAMI BELUM ADA TIKET YANG TERSEDIA SAAT INI"; getch();
    }
    file.close();
}
string uppercase(string x){
    for(int i =0;i<x.size();i++){
        x[i] = toupper(x[i]);
    }
    return x;
}
void lihat_pesan(string user){
    int kali, jumlah = 0;
    insertionsortId(user);
    for (int i =0 ; i< jumlah_tiket_user; i++){
        if(user == dtu[i].username){
            cout << "======================================"<<endl;
            cout<<"ID Pesanan  : "<<dtu[i].id<<endl;
            cout<<"Asal        : "<< dtu[i].asal<<endl;
            cout<<"Tujuan      : " << dtu[i].tujuan<< endl;
            cout<<"Tarif       : " <<dtu[i].harga<<endl;
            cout<<"Jumlah Tiket: "<<dtu[i].tiket<<endl;
            cout<<"Status      : "<<dtu[i].status<<endl;
            if(dtu[i].status == "Belum dibayar"){
                kali = dtu[i].tiket * dtu[i].harga;
                jumlah = jumlah + kali;
            }
        }
        else if(user == "q" && dtu[i].status == "Telah dibayar"){
            cout << "======================================"<<endl;
            cout<<"ID Pesanan  : "<<dtu[i].id<<endl;
            cout<<"Username    : "<<dtu[i].username<<endl;
            cout<<"Asal        : "<< dtu[i].asal<<endl;
            cout<<"Tujuan      : " << dtu[i].tujuan<< endl;
            cout<<"Tarif       : " <<dtu[i].harga<<endl;
            cout<<"Jumlah Tiket: "<<dtu[i].tiket<<endl;
            cout<<"Status      : "<<dtu[i].status<<endl;
            kali = dtu[i].tiket * dtu[i].harga;
            jumlah = jumlah + kali;
        }
	}
    if(jumlah_pesan > 0){
        cout<<"Total yang harus dibayar : "<<jumlah<<endl;
    }
    else{
        cout<<"Anda Belum Memesan Apapun"<<endl;
    }
}
void lihat_belum_pesan(string username){
    insertionsortId(username);
    for(int j = 0; j < jumlah_tiket_user; j++){
        if(username == dtu[j].username && dtu[j].status == "Belum dibayar"){
            cout << "======================================"<<endl;
            cout<<"ID Pesanan  : "<<dtu[j].id<<endl;
            cout<<"Username    : "<<dtu[j].username<<endl;
            cout<<"Asal        : "<< dtu[j].asal<<endl;
            cout<<"Tujuan      : " << dtu[j].tujuan<< endl;
            cout<<"Tarif       : " <<dtu[j].harga<<endl;
            cout<<"Jumlah Tiket: "<<dtu[j].tiket<<endl;
            cout<<"Status      : "<<dtu[j].status<<endl;
        }
    }
}
void ganti_tiket_user(){
    ofstream file;
    file.open("tiket_user.csv", ios::out | ios::trunc);
    for(int i=0; i<jumlah_tiket_user; i++){
        file << dtu[i].id<<"|";
        file << dtu[i].username<<"|";
        file << dtu[i].asal<<"|";
        file << dtu[i].tujuan<<"|";
        file << dtu[i].harga<<"|";
        file << dtu[i].tiket<<"|";
        file << dtu[i].status<<"\n";
    }
    file.close();
}
void bayar_tiket(string username){
    string ulang, bayar, uang;
    int bayar_int, uang_int, total;
    if(jumlah_tiket_user > 0){
        while(true){
            lihat_belum_pesan(username);
            bool found = false;
            cout << endl;
            cout << "KETIK 'kembali' JIKA TIDAK JADI MEMBAYAR"<<endl;
            cout<<endl;
            cout << "Masukan ID tiket yang ingin anda bayar: "; cin >> bayar;
            if(is_all_digits(bayar)){
                bayar_int = stoi(bayar);
                for(int i=0; i<jumlah_tiket_user; i++){
                    if(bayar_int == dtu[i].id && username == dtu[i].username && dtu[i].status == "Belum dibayar"){
                        dtu[i].status = "Telah dibayar";
                        cout << "TIKET TELAH DIBAYAR TEKAN APAPUN UNTUK MELANJUTKAN"; getch();
                        found = true;
                        break;
                    }
                }
                if(found){
                    ganti_tiket_user();
                    break;
                }
            }
            else if(bayar == "kembali"){
                break;
            }
            else{
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    else{
        cout<<"Anda Belum Memesan Apapun"<<endl;
        cout << "TEKAN APA SAJA UNTUK LANJUT"; getch();
    }
}
void hapus_tiket(string username){
    string ulang, hapus;
    int hapus_int;
    if(jumlah_tiket_user > 0){
        while(true){
            lihat_belum_pesan(username);
            bool found = false;
            cout << "KETIK 'kembali' JIKA TIDAK INGIN MENGHAPUS"<<endl;
            cout << "Masukan ID tiket yang mana ingin anda hapus: "; cin >> hapus;
            if(is_all_digits(hapus)){
                hapus_int = stoi(hapus);
                for(int i=0; i<jumlah_tiket_user; i++){
                    if(hapus_int == dtu[i].id && username == dtu[i].username && dtu[i].status == "Belum dibayar"){
                        found = true;
                        for(int j = i; j < jumlah_tiket_user; j++){
                            dtu[j] = dtu[j+1];
                        }
                    }
                }
                if(found){
                    jumlah_tiket_user--;
                    ganti_tiket_user();
                    break;
                }
            }
            else if(hapus == "kembali"){
                break;
            }
            else{
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    else{
        cout<<"Anda Belum Memesan Apapun"<<endl;
        cout << "TEKAN APA SAJA UNTUK LANJUT"; getch();
    }
}
void menu_user(string user){
    string pilih;
    // belum manggi fungsi
    while(true){
        system("cls");
        cout << "Username: "<<user<<endl;
        cout<< "================================================================"<<endl;
        cout<< "1. PESAN TIKET"<<endl;
        cout<< "2. LIHAT RIWAYAT PESANAN"<<endl;
        cout<< "3. BAYAR TIKET"<<endl;
        cout<< "4. HAPUS TIKET"<<endl;
        cout<< "5. MENU LOGIN"<<endl;
        cout<< "6. EXIT"<<endl;
        cout<< "pilih : ";cin>>pilih;
        if(pilih == "1"){
            pesan_tiket(user);
        }
        else if(pilih == "2"){
            lihat_pesan(user);
            cout << "TEKAN APA SAJA UNTUK LANJUT"; getch();
        }
        else if(pilih == "3"){
            bayar_tiket(user);
        }
        else if(pilih == "4"){
            hapus_tiket(user);
        }
        else if(pilih == "5"){
            break;
        }
        else if(pilih == "6"){
            exit(0);
        }
        else{
            cin.clear();
            cin.ignore();
            continue;
        }
    }
}
void inti(string user){
    string pilih_menu,pilih_menu2;
    int Pilih_menu,Pilih_menu2;
    while (true){
        system("cls");
        cout<< "================================================================"<<endl;
        cout<< "1. CREATE"<<endl;
        cout<< "2. READ"<<endl;
        cout<< "3. LIHAT PEMESANAN"<<endl;
        cout<< "4. UPDATE"<<endl;
        cout<< "5. DELETE"<<endl;
        cout<< "6. BACK TO LOGIN"<<endl;
        cout<< "7. EXIT"<<endl;
        cout<< "pilih : ";cin>>pilih_menu;
		if(!is_all_digits(pilih_menu)){
			cout<< "Oopsss.... input invalid\n"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
		}	
		else {
			Pilih_menu = stoi(pilih_menu);
			
		}
		
        if (pilih_menu == "1"){
    		while (true){
		
        		cout<< "\t1. Create \n\t2. back\n"<< "\tpilih :";cin>> pilih_menu2;
        		if(!is_all_digits(pilih_menu2)){
					cout<< "Oopsss.... input invalid\n"<<endl;
			        cin.clear();
			        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			        continue;
				}	
				else {
					Pilih_menu2 = stoi(pilih_menu2);
					
				}
				
        		if (pilih_menu2 =="1")create();
        		else if (pilih_menu2=="2")break;
        		else continue;
        		
        	}
        }else if(pilih_menu =="2"){
            display();
            cout << "TEKAN APA SAJA UNTUK LANJUT"; getch();
        }
        else if(pilih_menu == "3"){
            insertionsortId(user);
            cout << "TEKAN APA SAJA UNTUK LANJUT"; getch();
        }
        else if(pilih_menu =="4"){
        	while (true){
			
	        	cout<< "\t1. Update \n\t2. back\n"<< "\tpilih :";cin>> pilih_menu2;
	        	if(!is_all_digits(pilih_menu2)){
					cout<< "Oopsss.... input invalid\n"<<endl;
			        cin.clear();
			        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			        continue;
				}	
				else {
					Pilih_menu2 = stoi(pilih_menu2);
					
				}
				
				
				
	        	if(pilih_menu2=="1"){
		            update();
		            cin.ignore(1000,'\n');
				}else if(pilih_menu2=="2")break;
				
				
			}
			cin.clear();
        
		}else if(pilih_menu == "5"){
        	while(true){
			
        	cout<< "\t1. Delete \n\t2. Back\n"<< "\tpilih :";cin>> pilih_menu2;
        	if(!is_all_digits(pilih_menu2)){
					cout<< "Oopsss.... input invalid\n"<<endl;
			        cin.clear();
			        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			        continue;
				}	
				else {
					Pilih_menu2 = stoi(pilih_menu2);
					
			}
	        	if(pilih_menu2=="1"){
	            Delete();
	            cin.ignore(1000,'\n');
	        	}else if(pilih_menu2=="2")break;
	        	else {
		        	cout<< "\tooops....\n";
					cin.clear();
					continue;	
	        		
				}
	    	}
		
        }
        else if(pilih_menu =="6"){
            break;   
        }
        else if(pilih_menu == "7"){
            exit(0);
        }
        else {
            cin.clear();
            cin.ignore();
            continue;
        }
}
}
bool isStringValid(string str) {
    return all_of(str.begin(), str.end(), [](unsigned char c) { 
		return isalpha(c) || isspace(c); 
	});
}
bool is_all_digits(const string& s){//akan mengembalikan nilai boolean (true jika seluruh karakter dalam string adalah digit, dan false jika terdapat karakter non-digit dalam string).
	return all_of(s.begin(), s.end(), [](char c){
        return isdigit(c);// akan mengembalikan true jika setiap karakter di dalam string adalah digit, dan false jika ada setidaknya satu karakter yang bukan digit.
	});
}
bool is_alpha =true;
void create(){
	string ulang;
	ofstream file;
	file.open("data_tiket.csv", ios::out | ios::app);
    while (ulang != "n"){
		while(is_alpha){
			cout<<"Masukkan Rute Asal : ";
            cin >> ws;
			getline(cin, datap[jumlah_data].asal);
            for(int i = 0;i< datap[jumlah_data].asal.length(); i++){
                if(isStringValid(datap[jumlah_data].asal)){
                    break;
                }
                if(!isalpha(datap[jumlah_data].asal[i]) ){
                    is_alpha = false;
                    break;
                }
            }
            if(!is_alpha){
                cout<<"inputan tidak boleh berupa angka\n\n";
                cin.clear();
                is_alpha = true;
                
            }else break;
		}
		while(is_alpha){
			cout<<"Masukkan Rute Tujuan : ";
            cin>>ws;
			getline(cin, datap[jumlah_data].tujuan);
				for(int i = 0;i< datap[jumlah_data].tujuan.length(); i++){
					if(isStringValid(datap[jumlah_data].tujuan)){
						break;
					}
					if(!isalpha(datap[jumlah_data].tujuan[i]) ){
						is_alpha = false;
						break;
					}
				}
				if(!is_alpha){
					cout<<"Oopsss.... input invalid\n\n";
					cin.clear();
					is_alpha = true;
				}else break;
		}
		string harga; // supaya nantinya bisa di cek dengan all_of
		while (true){
			cout << "masukkan Harga Tiket : Rp.";
            cin>>ws;
            cin>>harga;
            if (!is_all_digits(harga)){
                    cout<< "Oopsss.... input invalid\n"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');// numeric_limits<streamsize>::max() digunakan untuk memberikan jumlah karakter yang tidak terbatas pada n. Selanjutnya, karakter \n (new line) digunakan untuk menandakan akhir dari inputan yang diabaikan.
            }else {
                int harga1 = stoi(harga);
                if(harga1 > 0){
                    datap[jumlah_data].harga = harga1;// fungsi untuk mengubah string menjadi integer.
                    break;	
                }
                else{
                    cout << "Harga tidak boleh 0"<<endl;
                }
            }
		}
		
		
        file << datap[jumlah_data].asal<<",";
        file << datap[jumlah_data].tujuan<<",";
        file << datap[jumlah_data].harga<<"\n";
        cout<< "do yo want to add something again?(y/n)";cin>>ulang;
        jumlah_data++;
    }
	file.close();
}
void read_tiket(){
	ifstream file;
	file.open("data_tiket.csv", ios::in);
	string isi,asal,tujuan,harga,harga_string;
	int harga_int;
	if(file.is_open()){
		while(getline(file,isi)){
			stringstream str(isi);
			getline(str, asal,',');
			getline(str, tujuan,',');
			getline(str, harga,'\n');
			stringstream harga_string(harga);

			harga_string >> harga_int;
			datap[jumlah_data].asal =asal;
			datap[jumlah_data].tujuan = tujuan;
			datap[jumlah_data].harga= harga_int;
			jumlah_data++;  
		}
		
	}
	else cerr<<"gagal membuka file...\n";//cerr =cout eror , bedanya ini mengirimkan output ke standar eror,bukan ke output standar
	file.close();
}
void display(){
    if(jumlah_data > 0){
        for (int i =0 ; i< jumlah_data; i++){
            cout << "======================================"<<endl;
            cout<<"Nomor       : " << i+1<<endl;
            cout<<"Asal        : " << datap[i].asal<<endl;
            cout<<"Tujuan      : " << datap[i].tujuan<< endl;
            cout<<"Tarif       : Rp." << datap[i].harga<<endl;
        }
        cout << "======================================"<<endl;
    }
    else{
        cout << "DATA MASIH KOSONG"<<endl;
    }

}
void ganti(){
    ofstream file;
    file.open("data_tiket.csv", ios::out | ios::trunc);
    for (int i = 0; i< jumlah_data; i++) {
        file << datap[i].asal<<",";
        file << datap[i].tujuan<<",";
        file << datap[i].harga<<"\n";
    }
    file.close();
}
void update(){
    fstream file;
    int ubah;
    display();
    file.open("data_tiket.csv");
    if(!file.is_open()){
        cout<<"data belum di buat, silahkan create terlebih dahulu"<<endl;
    }
    else{
        cout << "Please enter a ticket id you want to update : ";
        cin >> ws;
        cin>>ubah;
        if (ubah > 0 && ubah <= jumlah_data ){
            while(is_alpha){
				cout<<"Masukkan Rute Asal : ";
                cin >> ws;
				getline(cin,datap[ubah-1].asal);
				for(int i = 0;i< datap[ubah-1].asal.length(); i++){
					
						if(isStringValid(datap[ubah-1].asal)){
							break;
						}
							if(!isalpha(datap[ubah-1].asal[i]) ){
								is_alpha = false;
								break;
							}
				}
				if(!is_alpha){
					cout<<"inputan tidak boleh berupa angka\n\n";
					cin.clear();
					is_alpha = true;
					
				}else break;
        	}
            
            
			while(is_alpha){
				cout<<"Masukkan Rute Tujuan : ";
				cin >> ws;
                getline(cin, datap[ubah-1].tujuan);
					for(int i = 0;i< datap[ubah-1].tujuan.length(); i++){
						if(isStringValid(datap[ubah-1].tujuan)){
							break;
						}
						if(!isalpha(datap[ubah-1].tujuan[i]) ){
							is_alpha = false;
							break;
						}
					}
					if(!is_alpha){
						cout<<"Oopsss.... input invalid\n\n";
						cin.clear();
						is_alpha = true;
					}else break;
			}
            
            
            string harga; // supaya nantinya bisa di cek dengan all_of
			while (true){
				cout << "masukkan Harga Tiket : ";
                cin >> ws;
                cin>>harga;
                if (!is_all_digits(harga)){
                        cout<< "Oopsss.... input invalid\n"<<endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');// numeric_limits<streamsize>::max() digunakan untuk memberikan jumlah karakter yang tidak terbatas pada n. Selanjutnya, karakter \n (new line) digunakan untuk menandakan akhir dari inputan yang diabaikan.
                }else {
                    int harga1 = stoi(harga);
                    if(harga1 >= 1){
                        datap[ubah-1].harga = harga1;// fungsi untuk mengubah string menjadi integer.
                        break;
                    }
                    else{
                        cout << "Harga tidak boleh 0"<<endl;
                    }
                }
			}
			ganti();
        }
        else{        
            cout<< ">>>>> data tidak ada <<<<<" <<endl;
            cout << "Tekan sembarang untuk melanjutkan..\n";getch();//input yang memungkinkan tanpa menunggu "enter" dari user
            
        }
    }
    cin.clear();
    file.close();
}
void Delete(){
    display();
    int hapus;
    // belum manggil fungsi
    cout<< "hapus nomor berapa : ";cin>>hapus;
    if (hapus <= jumlah_data && hapus > 0 ){    
        for(int i=hapus-1;i< jumlah_data;i++){
                datap[i]= datap[i+1];
            }
            jumlah_data--;
            ganti();
    }
    else {
        cout<< ">>>>> data tidak ada <<<<<" <<endl;
        cout << "Tekan sembarang untuk melanjutkan..\n";getch();
        cin.clear();
    }
}
