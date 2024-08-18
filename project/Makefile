# Definindo o compilador e as flags
CXX = g++
CXXFLAGS = -g -Wall -pthread -Iinclude

# Diretórios
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
TESTDIR = tests

# Arquivos fonte e objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp) \
          $(wildcard $(SRCDIR)/Tabuleiro/*.cpp) \
          $(wildcard $(SRCDIR)/Reversi/*.cpp) \
          $(wildcard $(SRCDIR)/Lig4/*.cpp) \
          $(wildcard $(SRCDIR)/Jogador/*.cpp) \
          $(wildcard $(SRCDIR)/Partida/*.cpp)

OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(filter-out $(SRCDIR)/main.cpp, $(SOURCES)))
EXECUTABLE = $(BINDIR)/teste

# Arquivos de teste
TEST_SOURCES = $(wildcard $(TESTDIR)/*.cpp)
TEST_OBJECTS = $(patsubst $(TESTDIR)/%.cpp, $(OBJDIR)/%.o, $(TEST_SOURCES))
TEST_EXECUTABLE = $(BINDIR)/test_runner

# Alvo padrão
all: $(BINDIR) $(OBJDIR) $(OBJDIR)/Tabuleiro $(OBJDIR)/Reversi $(OBJDIR)/Lig4 $(OBJDIR)/Jogador $(OBJDIR)/Partida $(EXECUTABLE) $(TEST_EXECUTABLE)

# Criação dos diretórios bin e obj se não existirem
$(BINDIR):
	if not exist $(BINDIR) mkdir $(BINDIR)

$(OBJDIR):
	if not exist $(OBJDIR) mkdir $(OBJDIR)

$(OBJDIR)/Tabuleiro:
	if not exist $(OBJDIR)/Tabuleiro mkdir $(OBJDIR)\Tabuleiro

$(OBJDIR)/Reversi:
	if not exist $(OBJDIR)/Reversi mkdir $(OBJDIR)\Reversi

$(OBJDIR)/Lig4:
	if not exist $(OBJDIR)/Lig4 mkdir $(OBJDIR)\Lig4

$(OBJDIR)/Jogador:
	if not exist $(OBJDIR)/Jogador mkdir $(OBJDIR)\Jogador

$(OBJDIR)/Partida:
	if not exist $(OBJDIR)/Partida mkdir $(OBJDIR)\Partida

# Linkagem do executável principal (apenas aplicação)
$(EXECUTABLE): $(OBJECTS) $(OBJDIR)/main.o
	$(CXX) $(OBJECTS) $(OBJDIR)/main.o -o $@

# Linkagem do executável de teste (exclui o main.cpp da aplicação)
$(TEST_EXECUTABLE): $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(TEST_OBJECTS) $(OBJECTS) -o $@

# Compilação dos arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilação dos arquivos de teste
$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Alvo para rodar os testes
test: $(TEST_EXECUTABLE)
	$(TEST_EXECUTABLE)

# Limpeza dos arquivos compilados
clean:
	if exist $(OBJDIR) rmdir /S /Q $(OBJDIR)
	if exist $(BINDIR) rmdir /S /Q $(BINDIR)

# Remoção dos arquivos compilados, mas mantendo os diretórios
clean-objects:
	del /Q $(OBJDIR)\*.o
	del /Q $(EXECUTABLE)
	del /Q $(TEST_EXECUTABLE)

.PHONY: all clean clean-objects test
