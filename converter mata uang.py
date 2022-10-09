print("=========selamat datang di konverter mata uang=========")

def converter() :
    print ("Silahkan Pilih Menu : ")
    print ("1. IDR - USD")
    print ("2. IDR - EURO")
    print ("3. IDR - YEN")
    print ("4. IDR - SGD")
    print ("5. Keluar")

rupiah = 0
konversi = 0
b = 0
usd = 15250
euro = 14885.03
yen = 104.96
sgd = 10649.04

while True:
    converter()
    operator = str(input("Pilih Menu : "))

    if operator == '1':
        print('\nIDR - USD')
        rupiah = int(input("Nominal Rupiah : "))
        konversi = rupiah/(float(usd))
        konversi1 = round(konversi,b)
        print(f'hasilnya adalah : {float(konversi1)} USD')

    elif operator == '2':
        print("\nIDR - EURO")
        rupiah = float(input("Nominal Rupiah : "))
        konversi = rupiah / (float(euro))
        konversi1 = round(konversi,b)
        print(f"hasilnya adalah : {int(konversi1)} EURO")

    elif operator == '3':
        print("\nIDR - YEN")
        rupiah = float(input("Nominal Rupiah : "))
        konversi = rupiah / (float(yen))
        konversi1 = round(konversi,2)
        print(f"hasilnya adalah : {float(konversi1)} YEN")

    elif operator == '4':
        print("\nIDR - SGD")
        rupiah = float(input("Nominal Rupiah : "))
        konversi = rupiah / (float(sgd))
        konversi1 = round(konversi,b)
        print(f"hasilnya adalah : {int(konversi1)} SGD")
    
    elif operator == '5':
        print("\n\n========Terima Kasih=========")
        break





