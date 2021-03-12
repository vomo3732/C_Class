# C_Class
KOSTA 2021-1 Class Resource
IoT Class daily report
### C 언어 1강

#### 03/02 
출력형식, 데이터 타입별 byte 

```
#include <stdio.h> 
int main(){
	printf("실수의 출력: %f %f\n\n", 3.14159265, 456.7891230);
	printf("실수의 출력: %8.2f %10.3f\n\n", 3.14159265, 456.7891230);
	printf("data type 별 byte 수(int): %d byte\n", sizeof(int));
	printf("(char): %d byte\n", sizeof(char));
	printf("(long): %d byte\n", sizeof(long));
	printf("(float): %d byte\n", sizeof(float));
	printf("(double): %d byte\n", sizeof(double));
	printf("(long long): %d byte\n", sizeof(long long));
	return 0;
}
```

#### 03/03 
switch-case문에 대한 내용

```
#include <stdio.h>
int main(void){
	while(1){
		int a;
		printf("숫자키를 누르세요. 끝내시려면 '0'키를 누르세요 ");
		scanf("%d", &a);
		switch(a){
			case 0:
				return 0;
			case 1:
				printf(">1 : One");
				break;
			case 2: 
				printf(">2 : Two");
				break;
			case 3: 
				printf(">3 : Three");
				break;
			case 4:
				printf(">4 : Four");
				break;
			case 5:
				printf(">5 : Five");
				break;
			case 6:
				printf(">6 : Six");
				break;
			case 7:
				printf(">7 : Seven");
				break;
			case 8: 
				printf(">8 : Eight");
				break;
			case 9:
				printf(">9 : Nine");
				break;
			default:
				printf("수고하셨습니다.");
				break; 
		}
		printf("\n");
	}
	return 0;
}
```

#### 03/04 
getch() 함수와 배열에 대한 내용

```
#include <stdio.h>
#include <conio.h>
char buf[10000];
void printlocation(int x){
	x=x-48;
	printf("%s (%d)  --> %c \n\n", buf, x, *(buf+x));
}

int main(){
	scanf("%s", &buf);//enter 키를 눌러서 값을 되돌림 
	printf("입력 문자열은 %s 입니다\n\n\n\n", buf);
	while(1){	
		int ch=getch();//단일 키값을 되돌림.
		if(ch<48||ch>57) break;
		printlocation(ch);
	}
	return 0;
}
```

#### 03/05
함수와 포인터를 사용해서 최대공약수를 구하는 내용
```
#include <stdio.h>

int GetCD(int num, int *arr){
   int i,j,k;
   for(i=1,j=0;i<=num;i++){
      if(num%i == 0){
         *(arr+j) = i;
         j++;
         // *arr++=i; 
      }
   }
   return j;
}

int GetGCD(int *arr1, int n1, int *arr2, int n2){
   int i,j,k;
   for(i=n1-1;i>=0;i--){ //for(i=0;i<n1;i++)
      for(j=0;j<n2;j++){
         if(*(arr1+i) == *(arr2+j)) return *(arr1+i);
      }
   }
   return -1; //error발생 고려 
}

int GetGCD2(int n1, int n2){   
   for(int i=n1;i>0;i--){
      if(n1%i == 0 && n2%1 == 0) return i;
   }   
}

int main(){
   int num1, num2;
   int n1, n2, MaxNum;
   int arr1[100],arr2[100];
   
   printf("2개의 숫자를 입력하세요.\n");
   scanf("%d %d",&num1,&num2);
   
   n1 = GetCD(num1, arr1); // n1 : 1st 수의 약수 갯수 
   n2 = GetCD(num2, arr2); // n2 : 2st 수의 약수 갯수 
   
   MaxNum = GetGCD(arr1,n1,arr2,n2);
   
   // num1의 약수와 num2의 약수 출력 
   printf("%d의 약수 : ", num1);
   for(int i=0;i<n1;i++){
      printf("%d ",arr1[i]);
   }
   printf("\n%d의 약수 : ", num2);
   for(int i=0;i<n2;i++){
      printf("%d ",arr2[i]);
   }
   printf("\n\n%d와 %d의 최대공약수는 %d입니다.\n", num1, num2, MaxNum);
   return 0;
} 
```
#### 03/08
strncmp를 활용한 함수를 통해 한 문자열에서 다른 문자열이 존재하는 위치 찾기
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int chrPos(char *str, char chr); 
int strPos(char *str, char *s1);

int main(){
	char *str="abcdefgacdbhijklmn";
	char *s1="acdb";
	printf("문자열 : %s\n", str);
	printf("%c의 위치는 %d입니다\n", 'e', chrPos(str, 'e'));//4
	printf("%s의 위치는 %d입니다\n",s1, strPos(str, s1));
	
}

int chrPos(char *str, char chr){
	int i, j, k;
	i=0;
	
	for(i; *(str+i); i++){
		if(*(str+i)==chr) return i;
	}
	return -1;
}

int strPos(char *str, char *s1){
	int i, j, k;
	int p=1;
	for(i=0; *(str+i); i+=p+1){
		p=chrPos(str+i, *s1);
		if(strncmp(str+p+i, s1, strlen(s1))==0){
			return p+i;
		}
	}
	return -1;
}

//함수의 정의:
//함수명: int chrPos(char *str, char chr);
//return type: int: chr 문자의 위 치, 없다면 -1 
//input: char *str: 대상 문자열 
//		char chr: 찾을 문자 
//기능: str로 전달된 문자열중에서 chr문자를 검색하여 해당 위치를 반환(zero base) 검색되지 않으면 -1을 반환 

//함수의 정의:
//함수명: int strPos(char *str, char *s1);
//return type: int: s1 문자의 위 치, 없다면 -1 
//input: char *str: 대상 문자열 
//		char *s1: 찾을 문자 
//기능: str로 전달된 문자열중에서 s1 문자열을 검색하여 해당 위치를 반환(zero base) 검색되지 않으면 -1을 반환 
//===로직 구현 ================================================ 
//1. str에서 s1의 첫 문자가 있는 위치를 검색
//2. 해당 위치에서 strncmp를 이용하여 비교/ 같으면 return i, 아니면 다시 1번 
//3. 만일 끝까지 없으면 -1
```
#### 03/09
텍스트 파일을 이용해서 freopen, fprintf, fscanf와 malloc에 대한 내용
```
#include <stdio.h>
#include <io.h>
#include <malloc.h>
#define PNUM 100
int main(){
	int i, j, k;
	int *eng, *kor, *san;
	
	eng=(int*)malloc(PNUM*sizeof(int));
	kor=(int*)malloc(PNUM*sizeof(int));
	san=(int*)malloc(PNUM*sizeof(int));
	
	FILE *fp=fopen("C:\\Users\\Owner\\Desktop\\AA\\test.txt", "rb");
	
	for(i=0; i<PNUM; i++){
		k= fscanf(fp, "%d %d %d", kor+i, eng+i, san+i);
		if(k!=3) break;
		//for문 종료되었을 때의 i값은 무엇을 가리키나요? : 데이터의 갯수 
	}
	int n=i;
	for(i=0; i<n; i++){
		printf("%d   %d   %d \n", *(kor+i), *(eng+i), *(san+i));
	}
	fclose(fp);
}
```
#### 03/11
getch()를 이용하여 사용자가 입력한 숫자에 따라 '|'를 출력하는 위치를 변경하는 내용
```
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
```
#### 03/12
C++에서 class를 사용한 연산자의 오버로딩 테스트와 두 점을 통해 원의 지름과 둘레와 넓이를 구하는 연산 및 두 점을 통한 사각형의 넓이를 구하는 
```
#include <iostream>
#define PI 3.14159265
class Point { //기본적으로 private: 외부 참조 불가
public:     //: 외부참조가능
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
    Point(){}
    int GetX() { return x; }
    int GetY() { return y; }
    void SetX(int a) { x = a; }
    void SetY(int b) { y = b; }
    Point operator+(int n)
    {
        Point p1;
        p1.x = x + n; p1.y = y + n;
        return p1;
    }
    Point operator+(Point p)
    {
        Point p1;
        p1.x = x + p.x; 
        p1.y = y + p.y;
        return p1;
    }
};
class Rect {
private:
    Point p1, p2;
public:
    Rect(Point pp1, Point pp2) :p1(pp1), p2(pp2)
    {
        p1 = pp1;
        p2 = pp2;//class 변수의 대입문
    }
    Rect() :p1(0, 0), p2(0, 0) {}
    //Rect(Point& pp1, Point& pp2)
    void SetP1(Point p) { p1 = p; }
    void SetP2(Point p) { p2 = p; }
    int GetX() { return abs(p1.x - p2.x); }
    int GetY() { return abs(p1.y - p2.y); }
    int area() {
        int x = p1.x - p2.x;
        int y = p1.y - p2.y;
        return abs(x * y);
    }
};
//  Point 클래스와 Rect 클래스는 은닉되어 있음
//  공개된 정보는 Point 생성자와 Rect 생성자가 알려져 있음
//  Rect 클래스에는 사각형의 면적을 구하는 area 함수가 존재
//
//  ---> Rect의 대각선 길이를 구하는 Distance 함수가 필요함
//  dist=sqrt(x*x+y*y)
class RectEx : public Rect //Rect class를 상속 private
{
public:
    RectEx(Point pp1, Point pp2, int a) : Rect(pp1, pp2)
    {
        /*SetP1(pp1);
        SetP2(pp2);*/
    }
    double distance() {
        int x = GetX();
        int y = GetY();
        return sqrt(x * x + y * y);
    }
};
//Mission : Circle 클래스를 정의하고 멤버 함수를 구현하세요
//Member Fuction: 지름(diameter), 원둘레(CLen), 원면적(area)
class Circle :public Rect
{
    // 원의 넓이 원의 둘레 원의 지름
public:
    Circle(Point pp1, Point pp2) : Rect(pp1, pp2)
    {
    }
    double diameter() {
        int x = GetX();
        int y = GetY();
        return sqrt(x * x + y * y);
    }
    double CLen() {
        int x = GetX();
        int y = GetY();
        double len = sqrt(x * x + y * y);
        return PI * len;
    }
    double Area() {
        int x = GetX();
        int y = GetY();
        double len = sqrt(x * x + y * y);
        len = len / 2;
        return PI * len * len;
    }
};

int func1(Rect* r);
int func2(Rect& r);

int main()
{
    int n1 = 10, n2 = 20;
    Point p1(n1, n1), p2(n2, n2);
    //Rect r1 = { {10, 10}, {20, 20} };//struct type 초기화
    Rect r1(p1, p2); //Rect class 생성자 이용 초기화
    Rect r2;
    Circle r3(p1, p2);
    p1.SetX(15); p1.SetY(15);
    Point p3 = p1 + 10;
    Point p4 = p1 + p3;
    Point* p5 = &p4;
    func1(&r1);//포인터 변수 전달을 위해 변수(클래스)의 주소 전달
    func2(r1);//레퍼런스 타입은 그냥 변수명 전달
    printf("여기는 main입니다: \n두 점 p1(10, 10)과 p2(20, 20)으로 이루어진 사각형의 면적은 %d 입니다\n", r2.area());
    printf("두 점 p1(10, 10)과 p2(20,20)을 지나는 원의 지름은 %lf입니다\n", r3.diameter());
    printf("두 점 p1(10, 10)과 p2(20,20)을 지나는 원의 둘레는 %lf입니다\n", r3.CLen());
    printf("두 점 p1(10, 10)과 p2(20,20)을 지나는 원의 넓이는 %lf입니다\n", r3.Area());
    printf("Point 클래스의 연산자 오버로딩 테스트1 (+): p1(%d, %d) +%d ---> (%d, %d)\n", p1.x, p1.y, 10, p3.x, p3.y);
    printf("Point 클래스의 연산자 오버로딩 테스트2 (+): p1(%d, %d) +p3(%d, %d) ---> (%d, %d)\n", p1.x, p1.y, p3.x, p3.y, p4.x, p4.y);
    printf("Point 클래스의 연산자 오버로딩 테스트2 (+): p1(%d, %d) +p3(%d, %d) ---> (%d, %d)\n", p1.x, p1.y, p3.x, p3.y, p5->x, p5->y);
}

int func1(Rect* r1) {
    printf("두 점 p1(10, 10)과 p2(20, 20)으로 이루어진 사각형의 면적은 %d 입니다\n", r1->area());
    return 0;
}

int func2(Rect& r1) {
    printf("두 점 p1(10, 10)과 p2(20, 20)으로 이루어진 사각형의 면적은 %d 입니다\n", r1.area());
    return 0;
}
```
