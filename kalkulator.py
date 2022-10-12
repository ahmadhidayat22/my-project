print('=============KALKULATOR SEDERHANA==========')
print('=============BY-Informatika B==========')


def menu():
    print("""
    1. penjumlahan (+)
    2. pengurangan (-)
    3. perkalian (*)
    4. pembagian (/)
    5. keluar

    """)

while True:
    menu()
    pilih = int(input('Masukkan pilihan : '))
    

    if pilih ==1 :
        print('\nPenjumlahan')
        bil1 = int(input('Bilangan 1 : '))
        bil2 = int(input('Bilangan 2 : '))
        hasil = bil1 + bil2
        print(f'hasil = {bil1} + {bil2} = {hasil}')
        
    elif pilih ==2:
        print('\nPengurangan')
        bil1 = int(input('Bilangan 1 : '))
        bil2 = int(input('Bilangan 2 : '))
        hasil = bil1 - bil2
        print(f"hasil = {bil1} - {bil2} = {hasil}")

    elif pilih == 3:
        print('\nPerkalian')
        bil1 = int(input('Bilangan 1 : '))
        bil2 = int(input('Bilangan 2 : '))
        hasil = bil1 * bil2
        print(f'hasil = {bil1} X {bil2} = {hasil}')
    elif pilih == 4:
        print('\nPembagian')
        bil1 = int(input('Bilangan 1 : '))
        bil2 = int(input('Bilangan 2 : '))
        hasil = bil1 / bil2
        print(f'hasil = {bil1} / {bil2} = {hasil}')
    

    elif pilih == 5:    
        break

print('\n\n\n-----------Terima kasih-----------')