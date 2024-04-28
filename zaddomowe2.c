#include<stdio.h>

int main() {
	char s[] = "Abc xyz";
	asm (
		"mov rbx, %0;"
		"mov rcx, rbx;"
	"petla:"
		"mov al,[rcx];"
		"cmp al,0;"
		"je skok;"
		"inc rcx;"
		"jmp petla;"
	"skok:"	
		"dec rcx;"
	"petla2:"	
		"cmp rcx, rbx;"
		"jbe koniec;"
		"mov al,[rcx];"
		"mov ah,[rbx];"
		
		//tu daj kod zamiany
		"mov [rcx],ah;"
		"mov [rbx],al;"
		"inc rbx;"
		"dec rcx;"
		"jmp petla2;"
	"koniec:"
		:
		:"r"(s) 
		:"rax","rbx","rcx" 
	);
	printf("%s\n", s);
	return 0;
	
	// gcc -masm=intel zad1.c          masm - macro assembler
	// gcc -masm=intel -save-temps zad1.c   zapisuje pliki .i .o .s
	/*

	
		cwiczenia 3
		zadanie ktore odwraca litery w slowie
		al - dodatkowa magistrala z 8bitami z dolu
		[reg] - wartosc z pamieci gdzie jest wskaznik reg
		
		
		zadanie domowe
		zamieniamy litery na duze, jak jest duza to zostawiamy
		* 
		* 
	*/
}
