ECHO = @echo
RM = rm
COMP = g++
EDL = g++
CPPFLAGS = -ansi -pedantic -Wall -Werror -std=c++11
PROGS = Exe TestEmployee
.O = CompanyOwner.o Employee.o Measure.o Sensor.o MeasureType.o User.o DataManager.o

all: $(PROGS)

CompanyOwner.o: CompanyOwner.cpp CompanyOwner.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

Employee.o: Employee.cpp Employee.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

Measure.o: Measure.cpp Measure.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

Sensor.o: Sensor.cpp Sensor.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

MeasureType.o: MeasureType.cpp MeasureType.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

User.o: User.cpp User.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

DataManager.o: DataManager.cpp DataManager.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

Main.o: Main.cpp
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

Exe: $(.O)
	$(ECHO) "edl de $^"
	$(COMP) -o $@ $^

TestEmployee : Main.o Employee.o
	$(ECHO) "edl de $^"
	$(COMP) -o $@ $^

efface:
	rm $(.O) $(PROGS) 