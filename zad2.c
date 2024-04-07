#include<stdio.h>

int main() {
	int x = 0x39D;
	int y = 0;
	//y = x +x; -  tworzymy to w assemblerze
	asm (
		"mov eax, %1;"
		"xor ecx,ecx;"
		"xor ebx,ebx;"
	"petla:"
		"shl eax;"
		"jnc skok;"
		"inc ebx"
	"skok:"
		"and eax,eax;"
		"jnz petla;"
		"mov %0, ebx;"
		:"=r"(y) 
		:"r"(x) 
		:"eax","ebx","ecx" 
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
	
		cwiczenia 2
		SHL przesuwa w lewo co jednocześnie jest mnożeniem przed podstawe systemu liczbowego - w tym przypadku 2
		co robimy i po co?
		zerujemy rejestr w ktorym bedzie wynik czyli ecx oraz zerujemy rejestr z licznikiem czli ebx
		nastepnie robimy ifa czyli jesli carry flag nie jest 1 to robimy skok do skok, a jesli jest 1 to dodajemy do ebx
		nastepnie dodajemy 1 do ecx aby zaznaczyc ze zrobilismy porownanie
		musimy zrobic 32 porownania w 32 bitowej liczbie
		jnz petla - jesli wynik porownania nie jest zerem to idz do petla
		na koniec przenies do zmiennej %0 czyli 'y' wartosc z rejestru ebx 	
		* 
		"mov eax, %1;"
		"mov ecx, 0;"
		"xor ebx, 0;"
		"petla:"
			"shl eax;"
			"jnc skok;"
			"add ebx,1;"
		"skok:"
			"add ecx, 1;"
			"cmp ecx, 32;"
			"jnz petla;"
			"mov %0, ebx;"
		* 
		optymalizacja kodu
		xor ecx,ecx  - skoro porownujemy do siebie te same wartosci to wynik bedzie 0, a nie siega on do pamieci i nie wczytuje 0 ze zmiennej	
		inc ebx - zwieksza wartosc o 1
		dec ebx - zmniejsza wartosc o 1
		cmp eax,0 - porownuje czy eax jest 0, wtedy musi przestac sprawdzac ilosc jedynek w zmiennej ale zamiast tego mozemy napisac
		and eax,eax - sprawdzamy czy eax jest 0 bo tylko dwa zera dają 0, w innym wypadku da 1
		* 
		ZADANIE DOMOWE NA NASTĘPNE LABY do soboty 23.59
		piotr.szuca@ug.edu.pl
		
		rozwiazanie ma byc wklejone jako tresc maila
		* 
		Napisz program ktory znajdzie najdluzszy ciag jedynek w rozwinieciu dwojkowym liczby
		0x 0F0F F0F0
		0000111100001111 1111000011110000 - bedzie 8;
		
	*/
}
