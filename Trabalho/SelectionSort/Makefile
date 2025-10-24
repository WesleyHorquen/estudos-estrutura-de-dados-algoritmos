# Define o nome do executável
TARGET = exec

# Lista todos os arquivos objeto (gerados dos .c)
OBJS = main.o ordenar.o

# Compila o executável final (o target)
# Depende dos arquivos objeto listados em OBJS
$(TARGET): $(OBJS)
	gcc $(OBJS) -o $(TARGET)

# Regra para compilar main.c em main.o
main.o: main.c ordenar.h
	gcc -c main.c

# Regra para compilar ordenar.c em ordenar.o
ordenar.o: ordenar.c ordenar.h
	gcc -c ordenar.c

# Regra 'clean' para remover arquivos temporários
clean:
	rm -f $(TARGET) $(OBJS)