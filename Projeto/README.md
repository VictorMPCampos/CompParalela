Instalar gmp: sudo apt-get install libgmp3-dev

Para n = 10 000;  
Precisão arbitrária utilizada = 100 000 bits;  
Precisão Serial = 30 110 digitos corretos;  
Tempo de execução serial = 4.417s;  
Compilar Serial: gcc {nome arq} -o {nome exec} -lgmp

Paralelo:  
Para n = 10 000;  
Precisão arbitrária utilizada = 100 000 bits;  
Precisão Paralela = 30 110 digitos corretos;  
Tempo de execução = 4.083s;  
Speedup = 1.082;  
Compilar Paralelo: gcc {nome arq} -o {nome exec} -fopenmp -lgmp

Melhor resultado (32 threads):  
n = 1 000 000;  
Precisão arbitrária utilizada = 10 000 000 bits;  
Precisão obtida = 3 010 297 digitos corretos;  
Tempo de execução = 1h 26m 40.688s;  
