print("==========> SELAMAT DATANG <=========")

mahasiswa = {
    "nama" : "",
    "nim" : "",
    "prodi" : "",
    "ipk" : "",
    "motto hidup" : "",
    
}
def data() :
    print("Silahkan Isi Data Dengan Benar Dibawah Ini : ")
    mahasiswa["nama"] = input ("NAMA : ")
    mahasiswa["nim"] = int(input ("NIM : "))
    mahasiswa["prodi"] = input ("PRODI : ")
    mahasiswa["ipk"] = float(input ("IPK : "))
    mahasiswa["motto hidup"] = input ("MOTTO HIDUP : ")
data()

repeat = "y"
while repeat == "y":
    print("""
        Pilih Menu Berikutnya : 
        1. Ubah Data
        2. Lihat Data
        3. keluar 
    """)
    pilih = input("Pilihan Menu : ")
    
    if pilih == "1":
        data()
    elif pilih == "2":
        print("NAMA : ",mahasiswa["nama"],type(mahasiswa["nama"]))
        print("NIM : ",mahasiswa["nim"],type(mahasiswa["nim"]))
        print("PRODI : ",mahasiswa["prodi"],type(mahasiswa["prodi"]))
        print("IPK : ",mahasiswa["ipk"],type(mahasiswa["ipk"]))
        print("MOTTO HIDUP : ",mahasiswa["motto hidup"],type(mahasiswa["motto hidup"]))
        repeat = input("Kembali Ke Menu? (y/n)")
    elif pilih == "3" :
        break
    else:
        print("\nPILIH DIANTARA 1-3!!!!")
    
print("\n\n\n===========TERIMA KASIH=========")


