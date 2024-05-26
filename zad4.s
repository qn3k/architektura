.intel_syntax noprefix
.global main
.text
main:
mov eax, [esp+8]
mov eax, [eax+4]
push eax
call atoi
add esp,4
push eax
call f
add esp,4
push eax
mov eax, OFFSET msg
push eax
call printf
add esp,8
mov eax,0
ret
f:
mov eax,[esp+4]
cmp eax,1
jne skok
mov eax,1 
ret
skok:
dec eax
push eax
call f
add esp,4
add eax,[esp+4]
ret

.data
msg:
.asciz "Wynik = %i \n"


	# gcc -masm=intel zad1.c          masm - macro assembler
	# gcc -masm=intel -save-temps zad1.c   zapisuje pliki .i .o .s
	# gcc -m32 a.s     -m32 compiler 32 bitowy

	
	#cwiczenia 4
	#argumenty funkcji
	#int main(int ARCC, char **ARCV)
	#ARCV jest wskaznikiem na inne miejsce w pamieci, w ktorym jest tablica
	#wskaznikow ktora pokazuje gdzie sa poszczegolne znaki
	#
	#piszemy program ktory pobierze znaki, przeksztalci na liczbe i wypisze
	#
	#mov eax,[esp+8]  - odniesienie do miejsca na ktore wskazuje wskaznik esp + 8bit
	#mov eax,[eax+4]  - odniesienie do miejsca na ktore wskazuje wskaznik przechowany w eax + 4bit
	#taka operacja pozwala nam na dostanie sie do faktycznej wartosci przechowywanej w argumencie ARCV 
	#
	#atoi zamienia znaki na liczbe
	#w 9 linii add esp,4 pobiera faktyczne 4bity liczby z argumentu, tak dzialaja wskazniki 
	#
	#musimy dac argument uruchamiajac program, w przeciwnym wypadku jest naruszenie pamieci
	#
	#robimy funkcje
	#
	#zamiast add eax,eax w 10linii tworzymy
	#funkcja moze byc gdziekowiek, wyzej lub nizej, ale przed .data
	#
	#call atoi
	#add esp,4 - to jest dlatego ze call f daje na stos adres powrotu
	#
	#funkcja f dodajaca do siebie 2 razy wartosc z eax
	#f:
	#mov eax,[esp+4]
	#add eax,eax
	#add eax,eax
	#
	#
	#robimy funkcje rekurencyjna
	#f(n) = 1 dla n = 1
	#f(n-1)+n dla n>1
