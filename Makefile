GTKMM = `pkg-config gtkmm-3.0 --cflags --libs`
CC = g++ # le compilateur a utiliser
CFLAGS = $(GTKMM) -Wall -std=c++14
LDFLAGS = $(GTKMM)
SRC = Controleur.cpp VueGraphique.cpp Modele.cpp drawArea.cpp main.cpp # les fichiers sources
PROG = projet  # nom de l’exécutable
OBJS =  $(SRC:.cpp=.o) # les .o qui en d ́ecoulent
.SUFFIXES: .cpp .o    # lien entre les suffixes

all: $(PROG)

#  ́etapes de compilation et d’ ́edition de liens
$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

Modele.o: Modele.hpp
VueGraphique.o: VueGraphique.hpp
Controleur.o: Controleur.hpp
drawArea.o: drawArea.hpp
Observable.o: Observable.hpp
Observateur.o: Observateur.hpp

# le lien entre .o et .c
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

# pour faire propre
.PHONY: clean
clean:
	rm -f *.o *~ core a.out $(PROG)
