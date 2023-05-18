Instalar gmp: sudo apt-get install libgmp3-dev

Serial:
Para n = 100 000;  
Precisão arbitrária utilizada = 1 000 000 bits;  
Precisão Serial = 301 010 digitos corretos;  
Tempo de execução serial = 0.676s;  
Compilar Serial: gcc {nome arq} -o {nome exec} -lgmp

Paralelo:  
Para 2 threads;  
Para n = 100 000;  
Precisão arbitrária utilizada = 1 000 000 bits;  
Precisão Paralela = 301 010 digitos corretos;  
Tempo de execução = 0.296s;  
Speedup = 2.283;  
Compilar Paralelo: gcc {nome arq} -o {nome exec} -fopenmp -lgmp
