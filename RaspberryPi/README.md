### raspberry pi get token 구현하기
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
C#에서는 쉽게 구현할 수 있었던 Split 함수를 직접 C언어를 이용해 하나하나 구현해 보았습니다. 
char ** 으로 메모리 주소 자체를 수정하면서 숫자와 콤마로 구성된 문자열을 ss라는 문자열에 콤마를 제거한 뒤 대입하고 get Token 함수를 통해 진행합니다. 

### 초음파 센서(HC-SR04)를 이용한 거리 측정하기

```
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

int main()
{
	int wTrig=25;
	int wEcho=24;
	wiringPiSetup();
	pinMode(wTrig, OUTPUT);	//측정 신호 발사
	pinMode(wEcho, INPUT);	//반사 신호 검출
	while(1)
	{
		digitalWrite(wTrig, LOW); //트리거 신호를 위한 초기화
		delayMicroseconds(100);
		
		
		digitalWrite(wTrig, HIGH);
		delayMicroseconds(10);	//10us 의 트리거 신호
		digitalWrite(wTrig, LOW);
		delayMicroseconds(200);	//실제 신호발사까지 지연시간
		
		while(digitalRead(wEcho)==LOW);	//until high
		long start=micros(); 	//현재 시간의 마이크로초 단위 카운트
		while(digitalRead(wEcho)==HIGH);	//until low
		long end=micros();
		
		double dist=(end-start)*0.17;
		printf("Distance: %f\n",dist);
		delay(1000);
	}
	
}

```
초음파 센서의 특징인 trig와 echo를 이용했다. 발신부에서 보낸 신호가 반사되어 수신부에 돌아오는 시간을 토대로 거리를 측정했다. 음속이 340m/s인 점을 이용해서 1mm를 이동하는데 0.29us의 시간이 소요되는 것을 알 수 있다. 따라서, 음파의 이동거리= 왕복시간/1mm이동시간/2인 것을 알 수 있다! 따라서 거리를 구할때 double dist=(end-start)*0.17 (1mm 이동시간/2) 로 구해주었다

### 자이로 센서를 이용해 x1, y1, z1, x2, y2, z2값 구하기
```
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

short i2cInt16(int hndl, int addr);

int main()
{
	int i2cAddr=0x68;
	int bufAddr=0x3b;// memory block
	int pwrAddr=0x6b;
	
	wiringPiSetup();
	int hndl = wiringPiI2CSetup(i2cAddr);
	
	wiringPiI2CWriteReg8(hndl, pwrAddr, 0);
	double x1, x2, y1, y2, z1, z2;
	while(1){
		x1=i2cInt16(hndl, bufAddr)/16384.;
		
		y1=i2cInt16(hndl, bufAddr+2)/16384.;
		z1=i2cInt16(hndl, bufAddr+4)/16384.;
		x2=i2cInt16(hndl, bufAddr+8)/131.;
		y2=i2cInt16(hndl, bufAddr+10)/131.;
		z2=i2cInt16(hndl, bufAddr+12)/131.;
		
		printf("x1= %f  y1=%f  z1=%f  x2=%f  y2=%f  z2=%f \n",x1,y1,z1,x2,y2,z2);
	}
	
	
}

short i2cInt16(int hndl, int addr)
{
	short d1=wiringPiI2CReadReg8(hndl, addr);
	short d2=wiringPiI2CReadReg8(hndl, addr+1);
	short d3=(d1 << 8) | d2;
}

```
### 쌍방 통신 구현하기
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <pthread.h>

short i2cInt16(int hndl, int addr);
void * readProc();

char *IP="192.168.0.68";
int PORT=9001;
int sock;

int main()
{
	int i2cAddr=0x68;
	int bufAddr=0x3b;// memory block
	int pwrAddr=0x6b;
	
	pthread_t readThread;
	
	wiringPiSetup();
	int hndl = wiringPiI2CSetup(i2cAddr);
	
	wiringPiI2CWriteReg8(hndl, pwrAddr, 0);
	double x1, x2, y1, y2, z1, z2;
	int i, j, k;
	//int sock; //socket handle
	struct sockaddr_in sockinfo;
	char buf[1024];
	
	sock=socket(AF_INET, SOCK_STREAM, 0);
	sockinfo.sin_family=AF_INET;
	inet_pton(AF_INET, IP, &sockinfo.sin_addr.s_addr);
	sockinfo.sin_port=htons(PORT);
	
	connect(sock, (struct sockaddr*)&sockinfo, sizeof(sockinfo));
	k = fcntl(sock, F_SETFL, 0);
	fcntl(sock, F_SETFL, k | FNONBLOCK);
	pthread_create(&readThread, NULL, readProc, NULL);
	
	while(1){
		
		//x1=i2cInt16(hndl, bufAddr)/16384.;
		
		//y1=i2cInt16(hndl, bufAddr+2)/16384.;
		//z1=i2cInt16(hndl, bufAddr+4)/16384.;
		//x2=i2cInt16(hndl, bufAddr+8)/131.;
		//y2=i2cInt16(hndl, bufAddr+10)/131.;
		//z2=i2cInt16(hndl, bufAddr+12)/131.;
		scanf("%s",buf);
		if(buf[0]=='q') break;
		//buf[0]=
		//sprintf(buf, " %f ", x1);    // %f를 지정하여 실수를 문자열로 저장
		//sprintf(buf, " %f ", y1); 
		send(sock, buf, strlen(buf), 0);
		//i= recv(sock, buf, 1024, 0);
		//if(i>0) buf[i]=0;
		//if(buf[0]=='q') break;
 		//printf("%s\n", buf);
 		//delay(100);
	}
	close(sock);
	pthread_join(readThread, NULL);
	
}

void * readProc(){
	int i;
	char buf[1024];;
	while(1)
	{
		i=recv(sock, buf, 1024, 0);
		if(i>0)
		{
			buf[i]=0;
			printf("%s\n",buf);
		}	 
		delay(500);
	}
	return NULL;
	
}


short i2cInt16(int hndl, int addr)
{
	short d1=wiringPiI2CReadReg8(hndl, addr);
	short d2=wiringPiI2CReadReg8(hndl, addr+1);
	short d3=(d1 << 8) | d2;
}


```

