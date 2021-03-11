#include <stdio.h>
#include <conio.h>
int main(){
	char *str="...................";
	char ch='|';
	
	while(1){
		int k=getch()-0x30;
		if(k<0||k>9) break;
		for(int i=0; i<10; i++){
			if(i==k) printf("%c", ch);
			else printf("%c", *(str+i));
		}
		printf("\r");
	}
}
