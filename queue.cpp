#include <iostream>

using namespace std;

const int max_antrian = 5;
int front = 0, back = 0;

string antrianAtm[max_antrian];


// cek data antrian penuh atau tidak
bool isFull(){
	if( back == max_antrian ){
		return true;
	}
	else{
		return false;
	}
}

//is empty
bool isEmpty(){
	
	if (back == 0){
		return true;
	}
	else{
		return false;
	}
}


// enqueue / penambahan data

void enqueue(string data){
	
	if( isFull() ){
		cout << "antrian penuh "<<endl;
		
		return;
	}
	else{
		
		//cek data kosong atau tidak
		if( isEmpty() ){
			// antrian kosong
			antrianAtm[0] = data;
			back++;
			front++;
		}else{
			// antrian tidak kosong
			antrianAtm[back] = data;
			back++;
		}
		cout << "berhasil ditambahkan..."<<endl;
		system("pause");
	}
	system("cls");
}

void display(){

	for (int i = 0; i<max_antrian;i++){
		if (isEmpty()){
			cout << "antrian kosong"<<endl<<endl;
			return;
		}
	
		//cek apakah ruang kosong atau tidak
		if (antrianAtm[i] != ""){
			// ruang tidak kosong
			cout << i+1 << ". "<< antrianAtm[i]<<endl;
		}
		else{
			cout <<i+1<<". "<< " (kosong)"<<endl;
		}
	}
	
	
}

void dequeue(){
	if ( isEmpty() ){
		cout << "Antrian kosong"<<endl;
	}
	else{
		for(int i = 0; i < back;i++){
			antrianAtm[i] = antrianAtm[i+1];	
		}
		back--;
		
	}
	system("pause");
	system("cls");
}

// clear data

void destroy(){
	if ( isEmpty() ){
		cout << "Antrian kosong"<<endl;
	}
	else{
		for(int i = 0; i < max_antrian;i++){
			if (back > 1){
				//hapus semua
				antrianAtm[back-1] = "";
				back--;
			}
			else if (back == 1){
				// hapus data pertama
				antrianAtm[back-1] = "";
				back = 0;
				front = 0;
			}
		}
		
		
	}
	system("cls");
}

int main(){
	int pilih;
	string data;
	
	while (true){
	
	cout << "menu"<<endl;
	cout << "1. enqueue"<<endl;
	cout << "2. dequeue" << endl;
	cout << "3. display" << endl;
	cout << "4. clear" << endl;
	cout << "5. exit" << endl;
 	cout<<"pilih : ";cin >> pilih;
	
	switch (pilih){
		case 1 : 
			cout<<"masukkan data : ";fflush(stdin);getline(cin,data);
			enqueue(data);
			break;
		
		case 2 :
			dequeue();
			break;
		
		case 3:
			display();
			break;
		
		case 4 :
			
			destroy();
			break;
			
		case 5 :
			return 0;	
			
		}
	}
}












//#include <iostream>
//#include <queue>
//using namespace std;
//
//
//
//int main(){
//	queue<string> antrianAtm;
//	antrianAtm.push("hello");
//	antrianAtm.push("ahmad");
//	
//	cout<<endl<<"queue : "<<endl;
//	
//	while (!antrianAtm.empty()){
//		cout << antrianAtm.front()<<", ";
//		
//		antrianAtm.pop();
//	}
//}



