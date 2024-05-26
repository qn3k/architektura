.intel_syntax noprefix
.global main
.text
main:
mov eax, OFFSET mesg
push eax
call printf
pop eax
mov eax,0
ret

.data
mesg:
.asciz "Hello, world!\n"


	# gcc -masm=intel zad1.c          masm - macro assembler
	# gcc -masm=intel -save-temps zad1.c   zapisuje pliki .i .o .s
	# gcc -m32 a.s     -m32 compiler 32 bitowy

	
	#cwiczenia 3
	#zadanie ktore odwraca litery w slowie
	#al - dodatkowa magistrala z 8bitami z dolu
	#[reg] - wartosc z pamieci gdzie jest wskaznik reg
	 
	#STOSY
	#esp - stack pointer - wskaznik wierzcholka stosu
	#numerowanie jest od 0, ale wskaznik zaczyna zapisywac od x i zapisuje do 0
	 
	#na dole pamieci jest zapisany kod programu , dane sa zapisane nad nim
	#w efekcie stosy rosna w dol
	 
	#. kropki zaczynaja dyrektywy, poczatek pliku bedzie zawsze taki sam
	#.text zaznacza ze bedziemy pisac kod - teraz beda mnemoniki
	
	#chcemy napisac hello world w assemblerze
	
	#.data tu umieszczamy lancuch znakow, dajemy to po calym wlasciwym kodzie
	#.asciz to standardowy format dla jezyka C z /0 na koncu
	#mesg: nazwa zmiennej/etykiety
	#OFFSET mesg -wskaznik na pierwszy znak lancucha  
	
	#push umieszcza dane na stosie
	
	#gdy push eax zapisze wartosc to wskaźnik esp wskazuje koniec tego lancucha
	
	#call robi jumpa ale zapamietuje gdzie wrocic, zapisuje ta informacje na stosie
	#miejsce powrotu zajmuje 4 bajty 
	
	#pop zabiera ze stosu wartosc eax
	#esp wraca na miejsce poczatkowe
	#jesli chcemy aby funkcja (w tym wypadku printf) zwrocila 0 to eax musimy ustawic na 0
