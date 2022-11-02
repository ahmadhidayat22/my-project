import os
os.system('cls')
print("Sistem Pendataan Penyewaan Bus Pariwisata P.O Haryanto")
#========= akun admin ==========
admin_id = "admin"
admin_pass = "123"
#===============================
rute =  [{
    'asal' : 'Bogor',
    'tujuan' : 'Surabaya',
    'tarif' : 110},
    {'asal' :'Sampang',
    'tujuan' : 'Bogor',
    'tarif' : 320},
    {'asal':'Malang',
    'tujuan' : 'Jakarta',
    'tarif' : 125},
    {'asal' : 'Bogor',
    'tujuan' :'Surabaya',
    'tarif' : 110},
    {'asal' : 'Boyolali',
    'tujuan' : 'Madiun',
    'tarif' : 145}
]
# ============= buat form admin / program ==================
def data():
    print('NO | KOTA ASAL \t | KOTA TUJUAN \t | TARIF \t|')
    for i in range(len(rute)):
        print(' {} | {} \t | {} \t | {}.000\t|' .format(i+1, rute[i]['asal'], rute[i]['tujuan'],rute[i]['tarif']))
        continue

def data_trtntu(key):
    if key in range(len(rute)):
        print('NO | KOTA ASAL \t | KOTA TUJUAN \t | TARIF \t|')        
        print(' {} | {} \t | {} \t | {}.000\t|' .format(key+1, rute[key]['asal'], rute[key]['tujuan'],rute[key]['tarif']))

# =========== tampilkan data ================
def look():
    while(True):
        print('''
        ___________________________________
        List Data P.O Haryanto''')
        menu1 =  input('''
        Masukan pilihan anda:
        1. Data Seluruh Rute Dan Tarif
        2. Kembali ke Menu Utama
        Masukan Pilihan anda : ''')

        if menu1 == '1' :
            data()
        elif menu1 == '2':
            break
        else:
            continue

# ============= tambah data =================
def add():
        while True:
            menu1 = int(input('''
            Tambah data :
            1. menambah rute dan tarif
            2. kembali ke menu
            Pilih : 
            '''))
            if menu1 == 1 :
                asal = input('Tambahkan Asal Keberangkatan : ')
                tujuan = input('Tambahkan Tujuan Keberangkatan : ')
                tarif = int(input('Tambahkan Tarif : '))

                rute.append({'asal' : asal,'tujuan' : tujuan,'tarif' : tarif})
                
                print(data())

            elif menu1 == 2 :
                break
            else:
                continue

# ============= delete data =========
def delete():
    while True:
        menu2 = int(input('''
        Fitur Hapus data
        1. Hapus Data 
        2. Keluar
        Pilih : 
        '''))

        if menu2 == 1:
            print('Berikut Data Rute dan Tarif Bus Saat ini, Silahkan Hapus Sesuai Nomor.')
            data()
            hapus = int(input('Masukkan Nomor yang akan dihapus : '))-1
            if hapus not in range(len(rute)):
                print('Data Tidak ada...')
                continue
            elif hapus in range(len(rute)):
                del rute[hapus]
                
                print('Data terhapus...')
                break
        elif menu2 == 2:
            break
        else:
            continue

# ============= update Data =========
def update():
    while True:
        menu4 = input('''
        Fitur Update Data
        1. Ubah Data 
        2. kembali ke Menu
        Pilih : 
        ''')       
        if menu4 == '1':
            print(data())
            diUpdate = int(input('Masukkan Nomor Data yang Ingin diUbah : '))-1
            key = diUpdate

            print(data_trtntu(key))

            while diUpdate in range(len(rute)):
                opsi = input('''
                Apa Yang Ingin Anda Ubah :
                1. Kota Asal
                2. Kota Tujuan
                3. Tarif
                4. kembali ke menu
                Pilih :
                ''')
                if opsi == '1' :
                    asalbaru =input('Masukan Kota Asal Baru : ')
                    confirm = input('Simpan data? (Y/N) : ')
                    if confirm.lower() == 'n':
                        print('Data Tidak Ditambahkan')
                        break
                    elif confirm.lower() == 'y':
                        asalbaru = asalbaru.replace(' ','')
                        rute[diUpdate]['asal'] = asalbaru

                        print(data(),'Data Terupdate')
                    else :
                        print('Error')
                        continue
                elif opsi == '2':
                    tujuanbaru = input('Masukan Kota Tujuan Baru : ')
                    confirm = input('Simpan data? (Y/N) : ')
                    if confirm.lower() == 'n':
                        print('Data Tidak Ditambahkan')
                        break
                    elif confirm.lower() == 'y':
                        tujuanbaru = tujuanbaru.replace(' ','')
                        rute[diUpdate]['tujuan'] = tujuanbaru

                        print(data(),'Data Terupdate')
                    else :
                        print('Error')
                        continue
                elif opsi == '3':
                    tarifbaru = input('Masukan Tarif Baru : ')
                    confirm = input('Simpan data? (Y/N) : ')
                    if confirm.lower() == 'n':
                        print('Data Tidak Ditambahkan')
                        break
                    elif confirm.lower() == 'y':
                        tarifbaru = tarifbaru.replace(' ','')
                        rute[diUpdate]['tarif'] = int(tarifbaru)

                        print(data(),'Data Terupdate')
                    else :
                        print('Error')
                        continue
                elif opsi == '4':
                    break
                else:
                    print('Inputan Salah!!!')
                    continue
            else:
                print('Data Tidak ditemukan!!')
        elif menu4 == '2':
            break
        else:
            print('Input Salah!!')
            continue

# ============== buat form user/ program =====================
def user():
    print('\n\n\n\n============ Selamat Datang di Penyewaan Tiket Bus Pariwisata P.O Haryanto ===========')
    print('\nSilahkan Pesan Tiket Sesuai Daftar di Bawah Ini : \n')
    print(data())
    while True:   
        pilih1 = int(input('\npilih : '))-1
        # key = pilih1
        seat = int(input('Jumlah Orang : '))
        if pilih1 in range(len(rute)):
            print(f"\nAnda Memilih Rute : {rute[pilih1]['asal']} - {rute[pilih1]['tujuan']} dengan harga {rute[pilih1]['tarif']}.000 x {seat} Orang\n")
            tanya = input('Apakah Anda Ingin Melanjutkan? (Y/N) : ')
            if tanya.lower() == 'y':
                for i in range(len(rute)):
                    print(f"\nTotal Pembayaran anda : {rute[i]['tarif']*seat}.000")
                    print('='*43)
                    print('         Terimakasih Telah Memesan')
                    print('='*43)
                    print()
                    print()
                    print()
                    break
                break
                


            

        elif pilih1 not in range(len(rute)):
            print('Pilihan Salah !!')
            continue

users= {}
while True:
    print("""LOGIN SEBAGAI :
    1. ADMIN
    2. USER
    3. EXIT
    """)
    # login 
    option= input("PILIH : ")

    if option == '1' :
        username= input("Username : ")
        password= input("Password : ")
        if admin_id == username and admin_pass == password:
            while True:
                pilih = input('''Menu :
                1. Lihat Data
                2. Tambah Data
                3. Hapus Data
                4. Ubah Data
                5. keluar
                
                Masukkan Pilihan : ''')
                if pilih == '1' :
                    look()        
                elif pilih == '2':
                    add()
                elif pilih == '3':
                    delete()
                elif pilih == '4':
                    update()
                elif pilih == '5':
                    break
                else:
                    print('Input Salah!')
                    continue             
        else :
            print("LOGIN FAILED")

    elif option == '2':       
        status = ""
#Creates New User
        def New_User():
            Create_Login =input("Username Baru : ")
            if Create_Login in users :
                print ("Akun (username) Sudah Di daftarkan!")
            else:
                Create_Password =input("Password Baru : ")
                users[Create_Login] = Create_Password
                print("Akun Berhasil di Daftarkan!\n")
#Login if old user
        def Old_User():
            login =input("Username : ")
            Password =input("Password : ")

            if login in users and users[login] == Password:
                print("Login Sukses!")
                user()
            else:
                print("Username / Password Salah!")
        
        status =input("Sudah Punya Akun ? (Y/N) : ")
        print()
        if status.lower()== "y":
            if len(users) == 0:
                print('Anda Belum punya Akun, Silahkan Daftar Terlebih Dahulu..\n')
                New_User()
            else :      
                Old_User()
        elif status.lower() == "n":
            New_User()
        
    elif option == '3':
        print()
        print('='*43)
        print('\t\tTerimakasih')
        print('='*43)
        exit()
    else:
        print('Inputan Salah!!')
        continue