Instalar gmp: sudo apt-get install libgmp3-dev

Para n = 10 000;  
Precisão arbitrária utilizada = 100 000 bits;  
Precisão Serial = 10 000 digitos corretos;  
Tempo de execução serial = 27.117s;  
Compilar Serial: gcc {nome arq} -o {nome exec} -lgmp

Paralelo:  
Para n = 10 000;  
Precisão arbitrária utilizada = 100 000 bits;  
Precisão Paralela = 10 000 digitos corretos;  
Tempo de execução = 4.156s;  
Speedup = 6.524  
Compilar Paralelo: gcc {nome arq} -o {nome exec} -fopenmp -lgmp
