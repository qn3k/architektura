.intel_syntax noprefix
.global main
.text
main:
    mov eax, [esp+8]      # Pobierz pierwszy argument (adres łańcucha znaków)
    mov eax, [eax+4]      # Pobierz drugi argument (liczba jako łańcuch znaków)
    push eax              # Umieść na stosie
    call atoi             # Zamień na liczbę całkowitą
    add esp,4             # Usuń argument ze stosu
    push eax              # Umieść liczbę na stosie
    call f                # Wywołaj funkcję f
    add esp,4             # Usuń argument ze stosu
    push eax              # Umieść wynik na stosie
    mov eax, OFFSET msg   # Pobierz adres komunikatu
    push eax              # Umieść adres komunikatu na stosie
    call printf           # Wywołaj funkcję printf
    add esp,8             # Usuń dwa argumenty ze stosu
    mov eax,0             # Zakończ program z kodem powrotu 0
    ret                   # Powrót

f:
    mov eax, [esp+4]      # Pobierz argument funkcji f
    cmp eax, 1            # Sprawdź, czy eax <= 1
    jbe base_case         # Jeśli tak, przejdź do base_case
    push eax              # Zachowaj wartość eax na stosie
    
    dec eax               # Oblicz n-1
    push eax              # Umieść n-1 na stosie
    call f                # Wywołaj f(n-1)
    add esp, 4            # Usuń n-1 ze stosu
    mov ebx, eax          # Zachowaj wynik f(n-1) w ebx
    
    mov eax, [esp+4]      # Pobierz n ze stosu ponownie
    sub eax, 2            # Oblicz n-2
    push eax              # Umieść n-2 na stosie
    call f                # Wywołaj f(n-2)
    add esp, 4            # Usuń n-2 ze stosu
    add eax, ebx          # Dodaj wynik f(n-2) do wyniku f(n-1)
    
    ret                   # Powrót z wynikiem
    
base_case:
    mov eax, 1            # Jeśli n <= 1, zwróć 1
    ret                   # Powrót

.data
msg:
.asciz "Wynik = %i \n"
