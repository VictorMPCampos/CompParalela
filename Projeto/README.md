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

Melhor resultado:  
n = 100 000;  
Precisão arbitrária utilizada = 1 000 000 bits;  
Precisão obtida = 301 028 digitos corretos;  
Tempo de execução = 13m50.121s;  
