#include <stdio.h>
#include "function.c"

int main(){
	int  stopMenu = 0, i = 0, pilih = 0;
	char pilihMenu;
	
	//fungsi opening
    opening();

	do {
		system("CLS");
    	printf(	"\n\n\t+---------------------------------+\n"
    			"\t|         E-NEWS MANAGEMENT       |\n"
    			"\t|          >> MAIN MENU <<        |\n"
				"\t+---------------------------------+\n\n"
    			"\t  MENU 1 Halaman Berita              \n"
    			"\t  MENU 2 Login Admin        	        \n"
    			"\t  MENU 3 Exit                        \n" 
				"\t  MENU 4 Panduan                     \n"
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
	  		case '4' : 
			  	system("CLS");
			  	panduan(); 
    		default :
    			stopMenu = 1;
    			break;
   		 }
  	}while(stopMenu = 1);  

	return 0;
	}
