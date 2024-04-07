#include<stdio.h>

int main() {
	int x = 2024;
	int y = 0;
	//y = x +x; -  tworzymy to w assemblerze
	asm (
		"mov eax, %1;"
		"add eax,eax;"
		"add eax,eax;"		
		"mov ebx,eax;"	
		"add eax,eax;"	
		"add eax,eax;"
		"add eax,ebx;"							
		"mov %0,eax;"
		:"=r"(y) 
		:"r"(x) 
		:"eax","ebx" 
	);
	printf("x = %i y = %i\n", x,y);
	return 0;
	//instrukcja mov eax, ebx kopiuje wartosc z ebx do eax
	//w at&t byloby movd ebx,eax
	//uzywamy skladni asm intela bo x86 ma dwa obowiazujace skladnie
	//:"=r"(y) //%0  pierwsza linia - output 
	//:"r"(x) //%1  linia druga - input ,r od register, x jako zmienna
	//:"eax","ebx" //trzecia linia - jakie rejestry uzyjemy
	//w c cudzyslow musi sie otwierac i zamykac w jednej linii
	//ale jednoczesnie automatycznie laczy cudzyslowy po sobie
	//numerujemy zmienne %0,%1 itd od lewej do prawej
	// gcc -masm=intel zad1.c          masm - macro assembler
	// gcc -masm=intel -save-temps zad1.c   zapisuje pliki .i .o .s
	/*
		"mov eax, %1;"
		"add eax,eax;"
		"add eax,eax;"		
		"add eax,%1;"	
		"add eax,eax;"	
		"add eax,eax;"							
		"mov %0,eax;" 
		 
		ALBO
		 
		"mov eax, %1;"
		"add eax,eax;"
		"add eax,eax;"		
		"mov ebx,eax;"	
		"add eax,eax;"	
		"add eax,eax;"
		"add eax,ebx;"							
		"mov %0,eax;"
		*/
}
