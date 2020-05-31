ECHO = @echo
RM = rm
COMP = g++
EDL = g++
CPPFLAGS = ##-ansi -pedantic -Wall -Wextra -std=c++11
PROGS = Exe
.O = CompanyOwner.o Cleaning.o DataManager.o Employee.o Measure.o Sensor.o MeasureType.o User.o Main.o

all: $(PROGS)

CompanyOwner.o: CompanyOwner.cpp CompanyOwner.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

Cleaning.o: Cleaning.cpp Cleaning.h
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

DataManager.o: DataManager.cpp DataManager.h
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

Main.o: Main.cpp
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

PrivateUser.o: PrivateUser.cpp
	$(ECHO) "compilation de $<"
	$(COMP) $(CPPFLAGS) -c -o $@ $<

Exe: $(.O)
	$(ECHO) "edl de $^"
	$(COMP) -o $@ $^

##TestEmployee : Main.o User.o Employee.o DataManager.o Measure.o
##	$(ECHO) "edl de $^"
##	$(COMP) -o $@ $^

efface:
	rm $(.O) $(PROGS) 