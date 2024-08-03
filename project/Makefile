# Definindo o compilador e as flags
CXX = g++
CXXFLAGS = -Wall -Iinclude

# Diretórios
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Arquivos fonte e objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp) \
          $(wildcard $(SRCDIR)/JogoDeTabuleiro/*.cpp) \
          $(wildcard $(SRCDIR)/Reversi/*.cpp) \
          $(wildcard $(SRCDIR)/Lig4/*.cpp) \
          $(wildcard $(SRCDIR)/Jogador/*.cpp)

OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
EXECUTABLE = $(BINDIR)/projeto_final

# Alvo padrão
all: $(BINDIR) $(OBJDIR) $(EXECUTABLE)

# Criação do diretório bin se não existir
$(BINDIR):
	mkdir -p $(BINDIR)

# Criação do diretório obj se não existir
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Linkagem do executável
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Compilação dos arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos compilados
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Remoção dos arquivos compilados, mas mantendo os diretórios
clean-objects:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE)

.PHONY: all clean clean-objects
