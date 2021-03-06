#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include "Database.h"

//function prototype
void opening();
void mainMenu();
void menu_1();
void menu_2();
void login();
void printBerita(int page);
int searchNews (int size, news b[], char *mstype, int type);
void cariBerita ();
void halamanSelanjutnya();
void pilihBerita(int index);
void OpenlinkWeb(int index);
void sortNews();
void sortforUser(int size, news b[], int urut);
void swap(int j, news b[]);
void readNews(int size, news b[]);
void menuTambahBerita();
void addNews(char *arr, char *cmp);
int cekDataBerita(char *arr);
int getSize();
void low (char str[], char temp[]);
void editNews();
void sortNewsData();
int cariIndexNomor(char *arr);
void restoreNews();
void panduan ();

void opening(){
	int i;
	char arr [15][300] =
		{
		   " ",
		   " ",
    	   " 	-==========================================================================================-",
		   " 	|                                 E-NEWS MANAGEMENT                                        |",
		   " 	|                         MAHASISWA DEPARTEMEN TEKNIK ELEKTRO                              |",
		   " 	|------------------------------------------------------------------------------------------|",
		   " 	|                                                                                          |",
		   " 	| MENU 1 Halaman Berita                                                                    |",
    	   " 	| MENU 2 Login Admin                                                                       |",
		   " 	| MENU 3 Panduan                                                                           |",
		   " 	| MENU 4 EXIT                                                                              |",
		   " 	|                                                                                          |",
		   " 	-==========================================================================================-  ",
		   " ",
		   " "
		};

		for ( i = 0; i < 15; i++){
    	printf("%s\n", arr[i]);
	}

  	printf("	Press any key to continue . . . "); 
  	getch(); 

}

void mainMenu(){
	int  stopMenu = 0, i = 0, pilih = 0;
	char pilihMenu;
	
	do {
	system("CLS");
    printf(	"\n\n\t+---------------------------------+\n"
    		"\t|         E-NEWS MANAGEMENT       |\n"
    		"\t|          >> MAIN MENU <<        |\n"
			"\t+---------------------------------+\n\n"
    		"\t  MENU 1 Halaman Berita              \n"
    		"\t  MENU 2 Login Admin        	        \n"
    		"\t  MENU 3 Panduan                     \n" 
			"\t  MENU 4 EXIT                        \n"
    		"\t                            	        \n");
    printf("\tPilihan anda? ");
    scanf("%c", &pilihMenu);
    
	
	switch(pilihMenu){
      case '1': menu_1(); break;
      case '2': login(); break;
      case '3':
	  	system("CLS");
        printf("\n\n Terima kasih, semoga harimu menyenangkan! ^_^");
        Sleep(200);
        exit(0);
	  case '4' : panduan(); break;
    	default :
    		stopMenu = 1;
    		break;
    }
  	}while(stopMenu = 1);  
}

void menu_1(){
	int page = 0, error;
	int pilih = 0;

    do {
		system("CLS");
    	printBerita(page);
        printf("\n  1. Halaman Selanjutnya");
        printf("\n  2. Halaman Sebelumnya");
        printf("\n  3. Pencarian Berita");
		printf("\n  4. Pengurutan Berita");
 		printf("\n  5. Kembali ke menu utama");
  		printf("\n  Pilihan anda? ");
        scanf("%d", &pilih);
        
        switch(pilih){
            case 1:
            	page = (page+1);
            	if(page > getSize()/10){
            		page = getSize()/10;
			      	}
            	printBerita(page);
            	break;
            case 2:
            	page = (page-1)*(page<0);
           		printBerita(page);
            	break;
            case 3:
				cariBerita();
				break;
			case 4:
				sortNews();
				break;
            case 5: break;
        }
  	}while(pilih != 5);
        
    printf("\n  Menuju halaman utama . . . ");
    Sleep(1000);
    system("CLS");
}

void menu_2(){
	int pilih, cek;

	do{
		system("cls");
		printf(	" \n  +----------------------------------+\n"
				"  |         E-NEWS MANAGEMENT        |\n"
				"  |       >> EDITORIAL MENU <<       |\n"
				"  +----------------------------------+\n\n"
				"  1. Tambah Berita                 \n"
				"  2. Edit Berita                   \n"
				"  3. Restore Data                  \n"
				"  4. Kembali ke menu utama         \n");
		printf("\n  Pilihan anda? ");
		scanf("%d", &pilih);
			
		switch(pilih){
			case 1 : {
				menuTambahBerita();
				break;
			}
			case 2 : {
				editNews();
				break;
			}
			case 3 : {
				restoreNews();
				break;
			}
			case 4 : break;
		}	
		if (pilih > 4 && pilih < 0){
			printf("\n  Invalid Menu! Ulang Kembali ");
			Sleep(500);
		}
	}while(pilih != 4);	
}

void login(){ 
  	char username[20], userpwd[10], pilih[3];
 	int i, salah; 
 	system("CLS");
 	printf(	" \n  +----------------------------------+\n"
 			"  |         E-NEWS MANAGEMENT        |\n"
			"  |         >> LOGIN ADMIN <<        |\n"
			"  +----------------------------------+\n");
  	printf("\n  Username: "); 
  	scanf("%s", username); 
  	printf("  Password: "); 
  	for(i = 0; i < 3; i++){ 
    	userpwd[i] = getch();
    	printf("*");
 	} 
  	userpwd[i]='\0';  
  	if(strcmp(username, "admin") == 0){ 
    	if(strcmp(userpwd, "123") == 0){ 
			printf("\n\n  Login Berhasil. Selamat datang admin!");
			menu_2();
    	}else{ 
			printf("\n\n  Password yang dimasukkan salah.");
			do{
			printf ("\n  Apakah anda ingin kembali ke menu utama (yes/no)? ");
			scanf ("%s", &pilih);
			if( strcmp( pilih, "yes") == 0 ){
				system("CLS");
				mainMenu();
			}else if (strcmp( pilih, "no") == 0){
				system("CLS");
				login();
			}else {
				printf("\n  Input yang ada masukkan tidak ada");
				salah = 1;
			}
			}while(salah == 1);
    	}
	}else {
    	printf("\n\n  User tidak ditemukan.");
			do{
			printf ("\n  Apakah anda ingin kembali ke menu utama (yes/no)?");
			scanf ("%s", &pilih);
			if( strcmp( pilih, "yes") == 0 ){
				system("CLS");
				mainMenu();
			}else if (strcmp( pilih, "no") == 0){
				system("CLS");
				login();
			}else {
				printf("\n  Input yang ada masukkan tidak ada");
				salah = 1;
			}
			}while(salah == 1);
    
    }
}

void printBerita(int page){
	int i = page*10, end = (page+1)*10;
	sortNewsData();
  	int size = getSize();
  	if(end > size){
  		end = size;
	}
  	news b[size];
  	readNews(size, b);
  	printf("\n %*s%s%*s\n\n", 60, " ", "E - N E W S   M A N A G E M E N T", 60, " ");
  	printf(" ========================================================================================");
	printf("============================================================================= \n");
  	printf(" | %-10s  %-88s  %-14s  %-16s  %-20s%7s\n","No. ", "Judul", "Topik", "Tanggal", "Penulis", "|");
  	printf(" ========================================================================================");
	printf("============================================================================= \n");
  	for(; i < end; i++){
			printf(" | %.45s  %-90s	%-15s	%-15s	%-20s%10s\n", b[i].nomor, b[i].judul, b[i].topik, b[i].tanggal, b[i].penulis, "|");
  	}
 	printf(" ========================================================================================");
	printf("============================================================================= \n");
}

void cariBerita (){
	int size = getSize ();
	news b[size];
	readNews(size, b);
	int pilih, found, i;

	do {
		printf( "\n  Pencarian berdasarkan: "
		   		"\n  1. Judul"
		   		"\n  2. Topik"
		   		"\n  3. Tanggal"
		    	"\n  4. Penulis"
		    	"\n  0. back\n"
		   	 	"\n  Pilihan anda? ");
		scanf("%d", &pilih);
		
		switch (pilih){
			case 0 : break;
			case 1 : {
				found = searchNews (size, b, (char *) "Judul", 1);
				break;
			}
			case 2 : {
				found = searchNews (size, b, (char *) "Topik", 2);
				break;
			}
			case 3 : {
				found = searchNews (size, b, (char *) "Tanggal", 3);
				break;
			}
			case 4 : {
				found = searchNews (size, b, (char *) "Penulis", 4);
				break;
			}
			default : printf("\n  Invalid Choice"); break;	
		}
		if (found == 0) printf("\n  News not found!");
		
	} while (pilih > 4 && pilih < 0);
	
	if (pilih != 0) {
		printf("\n  ");
		system("pause");	
	}
}

int searchNews (int size, news b[], char *mstype, int type){
	int i;
	int found = 0;
	char key[300];
	char temp1[300], temp2[300];
	
	printf("\n  Enter %-8s -> ", mstype);
	if(!strcmp(mstype, "Tanggal")){
    printf("(dd/mm/yyyy) : ");
	}
	scanf(" %70[^\n]s", &key);
	system("cls");
	printf(" -==============================");
	printf("\n   Result for %-8s \"%s\" :", mstype, key);
	printf("\n -==============================\n\n");
	
	switch (type){
		case 1 : {
			for (i = 0; i < size; i++){
				low(b[i].judul, temp1);
				low(key, temp2);
				if (strstr(temp1, temp2) != NULL){
					found = 1;
					OpenlinkWeb(i);
					printf("\n");
				}
			} break;
		}
		case 2 : {
			for (i = 0; i < size; i++){
				low(b[i].topik, temp1);
				low(key, temp2);
				if (strstr(temp1, temp2) != NULL){
					found = 1;
					OpenlinkWeb(i);
					printf("\n");
				}
			} break;
		}
		case 3 : {
			for (i = 0; i < size; i++){
				low(b[i].tanggal, temp1);
				low(key, temp2);
				if (strstr(temp1, temp2) != NULL){
					found = 1;
					OpenlinkWeb(i);
					printf("\n");
				} 
			} break;
		}
		case 4 : {
			for (i = 0; i < size; i++){
				if (strstr(b[i].penulis, key) != NULL){
					found = 1;
					OpenlinkWeb(i);
					printf("\n");
				} 
			} break;
		}
	}
	
	return found;
}
void pilihBerita(int index){
	FILE *fp = fopen ("newsData.dat", "r");
	int size = getSize();
	news b[size]; 
	int i;
	fseek(fp, 0, SEEK_SET);
	for(i = 0; i < size; i++){
		fread(&b[i], sizeof(news), 1, fp);
	}

	printf("  >> Data Berita %s <<\n\n", b[index].nomor);
	printf("  Judul    : %s\n", b[index].judul);
	printf("  Topik    : %s\n", b[index].topik);
	printf("  Tanggal  : %s\n", b[index].tanggal);
	printf("  Penulis  : %s\n", b[index].penulis);
	printf("  Link     : %s\n", b[index].link);

	fclose(fp);
}


void OpenlinkWeb(int index){
	FILE *fp = fopen ("newsData.dat", "r");
	int size = getSize();
	news b[size]; 
	int  i, counter;
	char pilih [3];
	char temp[300];

	fseek(fp, 0, SEEK_SET);
	for(i = 0; i < size; i++){
		fread(&b[i], sizeof(news), 1, fp);
	}

	printf("  >> Data Berita %s <<\n\n", b[index].nomor);
	printf("  Judul    : %s\n", b[index].judul);
	printf("  Topik    : %s\n", b[index].topik);
	printf("  Tanggal  : %s\n", b[index].tanggal);
	printf("  Penulis  : %s\n", b[index].penulis);
	printf("  Link     : %s\n", b[index].link);

	do{
		printf ("\n  Apakah anda ingin membukanya di website (yes/no) : ");
		scanf("%s", &pilih);
		if( strcmp( pilih, "yes") == 0 ){	
			counter = 1;
			strcpy(temp, "start ");
			strcat(temp, b[index].link);
			system(temp);
			break;
		}else if ( strcmp( pilih, "no") == 0){
				counter = 2;	
				printf ("  Baik, Terima Kasih \n");
				break;
		}else
	 			printf("  Error!!!\n"); 
	}while ((counter != 1) || (counter != 2));
	fclose(fp);
}

void sortNews(){
	int i, urut;
	int size = getSize ();
	news b[size];
	readNews(size, b);
	
	do {
		system("cls");
		printf("\n %*s%s%*s\n\n", 60, " ", "E - N E W S   M A N A G E M E N T", 60, " ");
  		printf(" ========================================================================================");
		printf("============================================================================= \n");
  		printf(" | %-10s  %-88s  %-14s  %-16s  %-20s%7s\n","No. ", "Judul", "Topik", "Tanggal", "Penulis", "|");
  		printf(" ========================================================================================");
		printf("============================================================================= \n");	
		for(i = 0; i < size; i++){
			printf(" | %.45s  %-90s	%-15s	%-15s	%-20s%10s\n", b[i].nomor, b[i].judul, b[i].topik, b[i].tanggal, b[i].penulis, "|");
  		}
		printf(" ========================================================================================");
		printf("============================================================================= \n");
		printf("\n  Pengurutan berdasarkan:"
				   "\n  1. Judul"
				   "\n  2. Topik"
		    	   "\n  3. Tanggal"
				   "\n  4. Penulis"
				   "\n  5. Kembali\n"
		  		   "\n  Pilihan anda? ");
		scanf("%d", &urut);
			
		switch (urut){
			case 1 : 
				sortforUser(size, b, 1);
				break;
			case 2 :
				sortforUser(size, b, 2);
				break;
			case 3 :
				sortforUser(size, b, 3);
				break;
			case 4 :
				sortforUser(size, b, 4);
				break;
			case 5 : break;
			default : printf("\n  Invalid Choice!");
		}
	} while(urut != 5);	
}

void sortforUser(int size, news b[], int urut){
	int i, j;
	
	switch (urut) {
		case 1 : {
			for (i = 0; i < size - 1; i++){
				for (j = 0; j < size-1-i; j++){
					if(strcmp(b[j].judul, b[j+1].judul) > 0) {
						swap(j, b);
					}			
				}
			}
			break;
		}
		case 2 : {
			for (i = 0; i < size - 1; i++){
				for (j = 0; j < size-1-i; j++){
					if(strcmp(b[j].topik, b[j+1].topik) > 0) {
						swap(j, b);
	    			}			
				}
			}
			break;
		}
		case 3 : {
			for (i = 0; i < size - 1; i++){
				for (j = 0; j < size-1-i; j++){
					if(strcmp(b[j].tanggal, b[j+1].tanggal) > 0) {
						swap(j, b);
					}			
				}
			}
			break;
		}
		case 4 : {
			for (i = 0; i < size - 1; i++){
				for (j = 0; j < size-1-i; j++){
					if(strcmp(b[j].penulis, b[j+1].penulis) > 0) {
						swap(j, b);
					}			
				}
			}
			break;
		}	
		default : break;	
	} 	
}

void swap(int j, news b[]){
	char tempNo[5], tempJdl[100], tempTpk[15], tempTgl[50], tempPen[10], tempLn[200];
	
	strcpy(tempNo, b[j].nomor); 
    strcpy(b[j].nomor, b[j+1].nomor); 
    strcpy(b[j+1].nomor, tempNo); 
    
	strcpy(tempJdl, b[j].judul); 
    strcpy(b[j].judul, b[j+1].judul); 
    strcpy(b[j+1].judul, tempJdl); 

	strcpy(tempTpk, b[j].topik); 
    strcpy(b[j].topik, b[j+1].topik); 
    strcpy(b[j+1].topik, tempTpk);

	strcpy(tempTgl, b[j].tanggal); 
    strcpy(b[j].tanggal, b[j+1].tanggal); 
    strcpy(b[j+1].tanggal, tempTgl); 

	strcpy(tempPen, b[j].penulis); 
    strcpy(b[j].penulis, b[j+1].penulis); 
    strcpy(b[j+1].penulis, tempPen);

	strcpy(tempLn, b[j].link); 
    strcpy(b[j].link, b[j+1].link); 
    strcpy(b[j+1].link, tempLn);	
}

void low (char str[], char temp[]){
	int i;
	
	for (i = 0; i < strlen(str); i++){
		temp[i] = tolower(str[i]);
	}
}

void readNews(int size, news b[]){
	int i;
	FILE *fp = fopen ("newsData.dat", "r");
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < size; i++){
		fread(&b[i], sizeof(news), 1, fp);
	}
	fclose(fp);
}

int getSize(){
	FILE *fp = fopen ("newsData.dat", "r");
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp)/sizeof(news);
	fclose(fp);
	return size;
}

void menuTambahBerita(){
	int i, index;
	FILE *fp;
	fp = fopen ("newsData.dat", "a"); //dipakai append
	index = getSize();
	char pilih;
	news b;//ditambahkan 1 per satu makanya bukan menggunakan array
	
	do {
		system("cls");
		printf(	" \n  +----------------------------------+\n"
				"  |         E-NEWS MANAGEMENT        |\n"
				"  |      >> MENU TAMBAH BERITA <<    |\n"
				"  +----------------------------------+\n\n");
		printf("\n  Ingin tambah berita? [yes/no] ");
		scanf(" %[^\n]c", &pilih);
		if(pilih == 'y'){
			printf("\n  Data Berita Ke-%d", index+1);
			printf("\n  -----------------------------------\n");	
			addNews(b.nomor, (char *) "Nomor");
			addNews(b.judul, (char *) "Judul");
			addNews(b.topik, (char *) "Topik");
			addNews(b.tanggal, (char *) "Tanggal");
			addNews(b.penulis, (char *) "Penulis");
			addNews(b.link, (char *) "Link");
			
			int cek = fwrite(&b, sizeof(news), 1, fp);
			
			if (cek != 0)
				printf("\n  Add news success!\n  ");
				system("pause");
				index++;
			} else printf("\n  Add news failed!\n  ");
			
	} while (pilih != 'n');
	
	fclose(fp);
}

void addNews(char *arr, char *cmp){
	int cek;
	char temp[100];
	
	do {
		printf("  %-8s : ", cmp);		
		scanf(" %100[^\n]s", &temp);
		cek = cekDataBerita(temp);
	} while (cek == 0);
	strcpy(arr, temp);
}

int cekDataBerita(char *arr){
//pengecekan apakah ada data buku yang sama	
	int cek = 1;
	int i;
	int size = getSize(); //mengambil jumlah data buku
	
	news b[size]; //array buku
	readNews(size, b); //membaca data buku dari file
	
	for(i = 0; i < size; i++){ //cek data buku yang sama
		if (stricmp(arr, b[i].nomor) == 0) { //
			cek = 0;
			break;	
		}
		if (stricmp(arr, b[i].judul) == 0) { //cek judul
			cek = 0;
			break;	
		}else cek = 1;	
	}
	
	if (cek == 1) return 1; //jika tidak ada yang sama
	if (cek == 0) {
		printf("  Already Exist!\n"); 
		return 0; //jika ada yang sama
	}
}

void sortNewsData(){
	FILE *fp;
	int i,j;
	int size = getSize (); //mencari banyaknya buku dalam data
	news b[size];
	readNews(size, b); //membuat b dapat mengakses data
//dilakukan sortir berdasarkan ID book	
	for (i = 0; i < size - 1; i++){
		for (j = 0; j < size-1-i; j++){
			if(strcmp(b[j].nomor, b[j+1].nomor) > 0) {
				swap(j, b);
	    	}			
		}
	}
//selanjutnya data yang sudah terurut dimasukkan dalam data	
	fp = fopen("bookNews.dat", "r+");
	for (i = 0; i < size; i++){
		fwrite(&b[i],sizeof(news), 1, fp);
	}
	fclose(fp);
}

void editNews(){	
	FILE *fp;
	int size = getSize();
	news b[size]; 
	readNews(size, b);
	int index = 0, i, page, cek, berita, pilih;
	char temp[100];
	fseek(fp, 1, SEEK_SET);
	char nomor[5]; 
	int cmp = -1; //cmp dipilih tdk 0
	do {
		system("CLS");
		printBerita(page);
		printf("\n  1. Halaman Selanjutnya"); 
        printf("\n  2. Halaman Sebelumnya");
        printf("\n  0. Lanjut Edit\n\n  >> ");
        scanf("%d", &pilih);
        
        switch(pilih){
        	case 0: break;
            case 1:
            	page = (page+1);
            	if(page > getSize()/10){
            		page = getSize()/10;
			      	}
            	printBerita(page);
            	break;
            case 2:
        		page = (page-1)*(page<0);
           		printBerita(page);
            	break;	
        }
    }while(pilih != 0);
    
	do{
		printf("\n  Masukkan nomor berita (Contoh : 001) [7. Kembali] : ");
		scanf(" %3[^\n]s", &nomor);
		if (strcmp(nomor, "7") == 0) index = -2; //untuk back
		else index = cariIndexNomor(nomor);
		
		while (index != -1 && index != -2){ //-1 bila id tidak ditemukan
			system("cls");
			printf(	" \n  +----------------------------------+\n"
					"  |         E-NEWS MANAGEMENT        |\n"
					"  |       >> MENU EDIT BERITA <<     |\n"
					"  +----------------------------------+\n\n"
					"  1. Edit Nomor                   \n"
					"  2. Edit Judul                   \n"
					"  3. Edit Topik                   \n"
					"  4. Edit Tanggal                 \n"
					"  5. Edit Penulis                 \n"
					"  6. Edit Link                    \n\n"
					"  7. Kembali                      \n");
			printf("\n  Pilihan anda? ");
			pilihBerita(index);
			
			do {
				printf("\n  => : ");
				scanf("%d", &cmp);
			} while (cmp > 6 && cmp < 0);
			
			if (cmp == 7) break;
			else {
				fp = fopen ("newsData.dat", "r+");
				do {
					printf("\n  Change : ");
					scanf(" %100[^\n]s", &temp);
					cek = cekDataBerita(temp);
					if (cek == 1){
						switch (cmp){
							case 1 : strcpy(b[index].nomor, temp); break;
							case 2 : strcpy(b[index].judul, temp); break;
							case 3 : strcpy(b[index].topik, temp); break;
							case 4 : strcpy(b[index].tanggal, temp); break;
							case 5 : strcpy(b[index].penulis, temp); break;
							case 6 : strcpy(b[index].link, temp); break;
						}	
					}		
				} while (cek == 0);
				
				for (i = 0; i < size; i++){
					fwrite(&b[i],sizeof(news), 1, fp);
				}	

				if(fwrite != 0) printf("\n  Data has been succesfully updated!\n  ");
    			else printf("\n  Error writing file !\n");	
			}
			fclose(fp);
		}
	} while (index != -2);
}

int cariIndexNomor(char *arr){
	FILE *fp = fopen ("newsData.dat", "r");
	news b;
	int cek = 0;
	int i = 0;
	
	while(fread(&b, sizeof(news), 1, fp )){
		if(strcmp(arr, b.nomor) == 0) {
			cek = 1;
			break;
		}
		else i++;
	}
	
	if (cek == 1) {
		fclose(fp);	
		return i;	
	}else {
		printf("\n  Nomor berita tidak ditemukan!\n  ");
		system("pause");
		return -1;
		fclose(fp);		
	}
}

void restoreNews(){
	char inputKey[5];
	char restoreKey[] = "12345"; int cekKey = 0;
	char pilih;
	
	system("cls");
	printf(	" \n  +----------------------------------------------+\n"
			"  |               E-NEWS MANAGEMENT                 |\n"
			"  |            >> MENU RESTORE DATA <<              |\n"
			"  | Fungsi ini akan me-restore data menjadi default |\n"
			"  +-------------------------------------------------+\n\n");
	while (cekKey == 0){
		printf("\n  Masukkan kunci untuk me-restore : ");
		scanf(" %8[^\n]s", &inputKey);
		
		if (strcmp(restoreKey, inputKey) == 0) cekKey = 1;
		else {
			printf("  Invalid!\n");
			Sleep(750);
			break;
		}
	}
	
	if (cekKey == 1){
		do {
			printf("  Apakah anda yakin? [y/n] ");
			scanf(" %[^\n]c", &pilih);
			if (pilih == 'y') {
				gudangBerita();
				printf("\n\n  ");
				system("pause");
			}
		} while (pilih != 'y' && pilih != 'n');
	}
}

void panduan(){
	int i;
	char arr [35][300] = 
	{"  >> Menu Utama <<",
	 "  1. Pilihlah menu yang diinginkan sesuai nomor ",
	 "    - Menu 1 adalah halaman kumpulan berita ",
	 "    - Menu 2 adalah halaman login untuk admin ",
	 "    - Menu 3 adalah halaman panduan program",
	 "    - Menu 4 program akan keluar ",
	 " ",
	 "  >> Menu 1 <<",
	 "  1. Pilihlah menu yang diinginkan sesuai nomor ",
	 "  2. Program akan menampilkan kumpulan berita ",
	 "  3. Terdapat fungsi untuk berpindah halaman, mencari berita, dan mengurutkan berita ",
	 "  4. Pilihlah fungsi yang diinginkan sesuai nomor ",
	 "	  - Pilihan 1 untuk berpindah halaman selanjutnya ",
	 "	  - Pilihan 2 untuk berpindah halaman sebelumnya ",
	 "	  - Pilihan 3 untuk mencari berita berdasarkan judul, topik, tanggal, dan penulis. Lalu dapat menuju link yang dituju ",
	 "	  - Pilihan 4 untuk mengurutkan (Angka-Kapital-Huruf Kecil) berita berdasarkan judul, topik, tanggal, dan penulis ",
	 "	  - Pilihan 5 untuk kembali pada menu utama ",
	 " ",
	 "  >> Menu 2 <<",
	 "  Username : admin ; Password : 123 ",
	 "  1. Program akan meminta untuk memasukkan username dan password ",
	 "  2. Jika sesuai maka akan berpindah pada halaman editorial ",
	 "  3. Terdapat 5 pilihan fungsi. Pilihlah fungsi yang diinginkan sesuai nomor ",
	 "	  - Pilihan 1 berfungsi untuk menambah berita ",
	 "	  - Pilihan 2 berfungsi untuk mengedit berita ",
	 "	  - Pilihan 3 berfungsi untuk menghapus berita ",
	 "	  - Pilihan 4 berfungsi untuk mengembalikan berita yang ada ke default ",
	 "	  - Pilihan 5 untuk kembali pada menu utama ",
	 " ",
	 "  >> Menu 3 <<",
	 "  Program akan menampilkan panduan program E-News Management",
	 " ",
	 "  >> Menu 4 <<",
	 "  Program akan keluar. ",
	};

	printf(	" \n  +----------------------------------+\n"
				"  |         E-NEWS MANAGEMENT        |\n"
				"  |         >> MENU PANDUAN <<       |\n"
				"  +----------------------------------+\n\n");

	for ( i = 0; i < 35; i++){
    	printf("%s\n", arr[i]);
	}
  				
	printf("  Press any key to continue . . . "); 
  	getch(); 
}
