
import datetime

now = datetime.datetime.now().time().strftime("%a %I:%M:%S %p")


print("====== SELAMAT DATANG DI PROGRAM WAKTU =======")
print("silahkan masukkan rentang waktu dari jam 00-23 ")
ulang = "y"
while ulang == "y":

        waktu = float(input("\nmasukkan waktu : "))
        if (waktu >= 23 and waktu <24 or waktu <=2.59):
            print("Tengah Malam")
            ulang = input("\ningin coba lagi ? (y/n)")
        elif ( waktu >=3.00 and waktu <=5.59):
            print("Subuh")
            ulang = input("\ningin coba lagi ? (y/n)")
        elif ( waktu >= 6.00 and waktu <= 9.00):
            print("Pagi")
            ulang = input("\ningin coba lagi ? (y/n)")
        elif  (waktu >=9.01 and waktu <= 14.59):
            print("Siang")
            ulang = input("\ningin coba lagi ? (y/n)")
        elif ( waktu >= 15.00 and waktu <= 18.00):
            print("Sore")
            ulang = input("\ningin coba lagi ? (y/n)")
        elif ( waktu >= 18.01 and waktu <= 22.59):
            print("Malam")
            ulang = input("\ningin coba lagi ? (y/n)")
        else :
            ulang= input("error!!! Ingin Mencoba Lagi ? (y/n)")

print("\n\n\nWaktu Sekarang : ")
print(now)
print("==================Terimakasih=================")

