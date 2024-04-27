#include<stdio.h>

int main() {
	int x = 0x0F0FF0F0;
	int y = 0;
	//y = x +x; -  tworzymy to w assemblerze
	asm (
		"mov eax, %1;"
		"xor ecx,ecx;"
		"xor ebx,ebx;"
	"petla:"	
		"shl eax;"
		"jnc skok;" //jesli nie ma jedynki
		"inc ebx;"
		"cmp ebx,ecx;"
		"ja skok1;" 
	"skok1:"
		"mov ecx,ebx;"	
	"skok:"
		"mov ebx,0;"	
		"and eax,eax;"
		"jnz petla;" //jesli liczba wejsciowa jest rozna od 0
		"mov %0, ecx;"
		:"=r"(y) 
		:"r"(x) 
		:"eax","ebx","ecx" 
	);
	printf("x = %i y = %i\n", x,y);
	return 0;
	
	//eax wejsciowa liczba
	//ebx licznik jedynek obecnie
	//ecx liczba maks przechowywana w pamieci ktora na koniec idzie na output
	/*	
		cwiczenia 2
		SHL przesuwa w lewo co jednocześnie jest mnożeniem przed podstawe systemu liczbowego - w tym przypadku 2
		co robimy i po co?
		zerujemy rejestr w ktorym bedzie wynik czyli ecx oraz zerujemy rejestr z licznikiem czli ebx
		nastepnie robimy ifa czyli jesli carry flag nie jest 1 to robimy skok do skok, a jesli jest 1 to dodajemy do ebx
		nastepnie dodajemy 1 do ecx aby zaznaczyc ze zrobilismy porownanie
		musimy zrobic 32 porownania w 32 bitowej liczbie
		jnc skok //if (cf!=0) to pomin nastepne linie
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
		* 
		* 
		operacje bez znakow
		ja - skocz jesli pierwszy argument jest wiekszy od drugiego - jump above
		jna - skocz jesli pierwszy argument jest mniejszy/rowny - jump not above
		jb	- skocz jesli pierwszy argument jest mniejszy - jump below
		jnb - skocz jesli pierwszy argument jest wiekszy lub rowny
		
		jae - skocz jesli pierwszy argument jest wiekszy lub rowny
		* 
		operacje ze znakami
		
		jg - jump greater
		jl - jump lower
		i dalej analogicznie
		* 
		* 
		TRZEBA sprawdzic przyklad losowy i skrajne
	*/
}
