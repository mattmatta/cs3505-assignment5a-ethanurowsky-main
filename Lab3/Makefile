CARDIR = /root/cs3505/Lab3/Carlib

car: Car.h Car.cpp Main.cpp
	g++ -o car Car.cpp Main.cpp

car2: $(CARDIR)/lib/libCar.a Main.cpp
	g++ -I $(CARDIR)/include -L $(CARDIR)/lib -lCar -o car2 Car.cpp Main.cpp

main.o: Main.cpp
	g++ -c Main.cpp
