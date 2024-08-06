# Definindo o compilador e as flags
CXX = g++
CXXFLAGS = -g -Wall -Iinclude

# Diretórios
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Arquivos fonte e objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp) \
          $(wildcard $(SRCDIR)/Tabuleiro/*.cpp) \
          $(wildcard $(SRCDIR)/Reversi/*.cpp) \
          $(wildcard $(SRCDIR)/Lig4/*.cpp) \
          $(wildcard $(SRCDIR)/Jogador/*.cpp)

OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
EXECUTABLE = $(BINDIR)/teste

# Alvo padrão
all: $(BINDIR) $(OBJDIR) $(OBJDIR)\Tabuleiro $(OBJDIR)\Reversi $(OBJDIR)\Lig4 $(OBJDIR)\Jogador $(EXECUTABLE)

# Criação dos diretórios bin e obj se não existirem
$(BINDIR):
	if not exist $(BINDIR) mkdir $(BINDIR)

$(OBJDIR):
	if not exist $(OBJDIR) mkdir $(OBJDIR)

$(OBJDIR)\Tabuleiro:
	if not exist $(OBJDIR)\Tabuleiro mkdir $(OBJDIR)\Tabuleiro

$(OBJDIR)\Reversi:
	if not exist $(OBJDIR)\Reversi mkdir $(OBJDIR)\Reversi

$(OBJDIR)\Lig4:
	if not exist $(OBJDIR)\Lig4 mkdir $(OBJDIR)\Lig4

$(OBJDIR)\Jogador:
	if not exist $(OBJDIR)\Jogador mkdir $(OBJDIR)\Jogador

# Linkagem do executável
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Compilação dos arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos compilados
clean:
	if exist $(OBJDIR) rmdir /S /Q $(OBJDIR)
	if exist $(BINDIR) rmdir /S /Q $(BINDIR)

# Remoção dos arquivos compilados, mas mantendo os diretórios
clean-objects:
	del /Q $(OBJDIR)\*.o
	del /Q $(EXECUTABLE)

.PHONY: all clean clean-objects
