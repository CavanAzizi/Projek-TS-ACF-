#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include "Database.h"

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
void sortNews();
void sortforUser(int size, news b[], int urut);
void swap(int j, news b[]);
void readNews(int size, news b[]);
int getSize();
void low (char str[], char temp[]);

void opening(){
    printf("\n\n 	-==========================================================================================-\n"
		   " 	|                                 E-NEWS MANAGEMENT                                        |\n"
		   " 	|                         MAHASISWA DEPARTEMEN TEKNIK ELEKTRO                              |\n"
		   " 	|------------------------------------------------------------------------------------------|\n"
		   " 	|                                                                                          |\n"
		   " 	| MENU 1 Halaman Berita                                                                    |\n"
    	   " 	| MENU 2 Login Admin                                                                       |\n"
		   " 	| MENU 3 Exit                                                                              |\n"
		   " 	|                                                                                          |\n"
		   " 	-==========================================================================================-\n\n  ");
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
    		"\t  MENU 3 Exit                        \n"
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
    	default :
    		stopMenu = 1;
    		break;
    }
  	}while(stopMenu = 1);  
}

void menu_1(){
	int page = 0, pilih = 0;
	system("CLS");
    printBerita(page);
    do {
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
				"  3. Hapus Berita                  \n"
				"  4. Restore Data                  \n"
				"  5. Kembali ke menu utama         \n");
		printf("\n  Pilihan anda? ");
		scanf("%d", &pilih);
			
		switch(pilih){
			case 1 : {
				
				break;
			}
			case 2 : {
				
				break;
			}
			case 3 : {
				
				break;
			}
			case 4 : {
				
				break;
			}
			case 5 :
				break;
		}	
		if (pilih > 5 && pilih < 0){
			printf("\n  Invalid Menu! Ulang Kembali ");
			Sleep(500);
		}
	}while(pilih != 5);	
}

void login(){ 
  	char username[20], userpwd[3];
 	int i; 
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
			Sleep(1500);
			menu_2();
    	}else if(strcmp(userpwd, "123") == 0){ 
			printf("\n\n  Password yang dimasukkan salah.");
			Sleep(1500);
			system("CLS");
			mainMenu();
    	}
	}else if(strcmp(username, "admin") == 1){
    	printf("\n\n  User tidak ditemukan.");
    	Sleep(1500);
    	system("CLS");
    	mainMenu();
    }
}

void printBerita(int page){
	int i = page*10, end = (page+1)*10;
  	int size = getSize();
  	if(end > size){
  		end = size;
	}
  	gudangBerita();
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
	news b1[size];
	readNews(size, b1);
	int choice, found, i;

	do {
		printf("\n  SEARCH BY"
		   "\n  1. Judul"
		   "\n  2. Topik"
		   "\n  3. Tanggal"
		   "\n  4. Penulis"
		   "\n  0. back\n"
		   "\n  Choice : ");
		scanf("%d", &choice);
		
		switch (choice){
			case 0 : break;
			case 1 : {
				found = searchNews (size, b1, (char *) "Judul", 1);
				break;
			}
			case 2 : {
				found = searchNews (size, b1, (char *) "Topik", 2);
				break;
			}
			case 3 : {
				found = searchNews (size, b1, (char *) "Tanggal", 3);
				break;
			}
			case 4 : {
				found = searchNews (size, b1, (char *) "Penulis", 4);
				break;
			}
			default : printf("\n  Invalid Choice"); break;	
		}
		if (found == 0) printf("\n  News not found!");
		
	} while (choice > 4 && choice < 0);
	
	if (choice != 0) {
		printf("\n  ");
		system("pause");	
	}
}

int searchNews (int size, news b1[], char *mstype, int type){
	int i;
	int found = 0;
	char key[70];
	char temp1[70], temp2[70];
	
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
				low(b1[i].judul, temp1);
				low(key, temp2);
				if (strstr(temp1, temp2) != NULL){
					found = 1;
					pilihBerita(i);
					printf("\n");
				}
			} break;
		}
		case 2 : {
			for (i = 0; i < size; i++){
				low(b1[i].topik, temp1);
				low(key, temp2);
				if (strstr(temp1, temp2) != NULL){
					found = 1;
					pilihBerita(i);
					printf("\n");
				}
			} break;
		}
		case 3 : {
			for (i = 0; i < size; i++){
				low(b1[i].tanggal, temp1);
				low(key, temp2);
				if (strstr(temp1, temp2) != NULL){
					found = 1;
					pilihBerita(i);
					printf("\n");
				} 
			} break;
		}
		case 4 : {
			for (i = 0; i < size; i++){
				if (strstr(b1[i].penulis, key) != NULL){
					found = 1;
					pilihBerita(i);
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
	int i, counter;
	char pilih[3];
	fseek(fp, 0, SEEK_SET);
	for(i = 0; i < size; i++){
		fread(&b[i], sizeof(news), 1, fp);
	}

	printf(">> Data Berita %s <<\n\n", b[index].nomor);
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
			switch (index){
				case 0 :
					system("start https://nasional.kompas.com/read/2022/03/26/18023771/jokowi-transformasi-ekonomi-indonesia-tentu-tak-menyenangkan-bagi-yang-suka");
					break;
				case 1 :
					system("start https://www.kompas.com/edu/read/2022/03/25/183950071/guru-besar-ipb-99-persen-kebakaran-hutan-dan-lahan-ulah-manusia");
					break;
				case 2:
					system("start https://health.kompas.com/read/2022/03/24/100046268/membongkar-deretan-mitos-tbc-serta-faktanya-biar-tidak-salah-kaprah-lagi");
					break;
				case 3:
					system("start https://www.kompas.com/global/read/2022/03/26/183200470/tujuh-jenderal-diklaim-tewas-rusia-turunkan-ambisi-dalam-serangan-ke");
					break;
				case 4:
					system("start https://megapolitan.kompas.com/read/2022/03/20/22223601/anies-motogp-mandalika-sukses-harumkan-indonesia");
					break;
				case 5:
					system("start https://www.kompas.com/edu/read/2022/03/18/155505171/15-jurusan-kuliah-ui-dengan-persaingan-tertinggi-di-sbmptn-2021");
					break;
				case 6:
					system("start https://health.kompas.com/read/2022/03/25/190219068/catat-ini-4-tips-persiapkan-tubuh-jalani-puasa-ramadhan");
					break;
				case 7:
					system("start https://www.kompas.com/global/read/2022/03/22/182640670/fakta-dan-misteri-137-detik-kecelakaan-boeing-737-800-ng-china-eastern");
					break;
				case 8:
					system("start https://www.kompas.com/edu/read/2022/03/26/122314071/sekolah-didorong-gelar-ptm-terbatas-oleh-kemendikbud-ristek");	
					break;
				case 9:
					system("start https://www.kompas.com/properti/read/2022/03/23/194500221/infrastruktur-jalan-dan-air-mulai-dibangun-di-ikn-nusantara");
					break;
			}
				break;
		}else if ( strcmp( pilih, "no") == 0){
				counter = 2;	
				printf ("  Baik, Terima Kasih ");
				break;
		}else
	 			printf("  error!!!\n");
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
