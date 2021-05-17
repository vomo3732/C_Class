##raspberry pi get token 구현하기
```

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int chrFind(char *str, char chr);
//char GetToken(int index, char *str, char chr);
int StrLen(char *str);
int chrFind(char *str, char chr);
char **Split(char *str, char chr);
int chrCount(char *str, char chr);
char *GetToken(int index, char *str, char chr);

int main(){
	char buf[256];
	int a, b, c;
	/*
	printf("Input output File name : ");
	scanf("%s", buf);
	FILE *fp=fopen(buf, "ab");
	char *name;
    name = (char *)malloc(sizeof(char) * 20);
    printf("입력하세요 : ");
	while(1){
		
		scanf("%s",name);
		
		if(name[0]=='>') break;
		fprintf(fp, "%s", name);
	}
	fclose(fp);
	char *s1="abcdefghijkl";
	while(1){
		printf("Input search char : ");
	a=getchar();
	printf("[%c] 문자는 %d 번째에 있습니다 \n\n",a, chrFind(s1, a));
	}*/
	char *s1="abcdefghijkl";
	char *tt="1,2,3,4,5,6,7";
	char** ss=Split(tt, ',');
	while(1){
		
		printf("Input search num: ");
		scanf("%d",&a);
		printf("%d번째 아이템은 %s입니다", a, GetToken(a, tt, ','));
	}
	
	return 0;
    
}
int chrFind(char *str, char chr) //문자열 str에서 문자 chr의 위치를 반환
{
	int i=0;
	
	while(*str){
		i++;
		if(*str++==chr) return i;
		
	}
	return -1;
}


int StrLen(char *str){
	int i=0;
	while(*str++) i++;	return i;
}

char *GetToken(int index, char *str, char chr){
	char** ss=Split(str, chr);
	return *(ss+index);
} 

char **Split(char *str, char chr){
	char *s1=malloc(StrLen(str));
	char **s2=malloc((chrCount(str, chr)+1)*4);
	strcpy(s1,str);
	
	int i=1;
	*(s2+0)=s1;
	
	while(*s1){
		if(*s1==chr){
			*s1=0;
			*(s2+i++)=s1+1;	//s1+1; s1++;
			//for(int j=0; j<i; j++){
			//	printf("%s\n",*(s2+j));
			//}	
			
			
		}
		s1++;
		
	}
	return s2;
}

int chrCount(char *str, char chr){
	int i=0;
	while(*str)
	{
		if(*str++==chr) i++;
	}
	return i;
}

//string GetToken(int index, string str, char chr)
//{
//	strng[] sArr= str.Split(chr);
//	return sArr[index];
//}

```
