#=========
# Makefile
#=========


APP		=	project4
INC		=	
CC++		=	g++
C++FLAGS	=	$(INC)
HFILES		=	InsurancePolicy.h Auto.h Home.h Life.h \
			Employee.h Salesperson.h Manager.h
OBJECTS		=	$(APP).o InsurancePolicy.o Auto.o Home.o Life.o \
			Employee.o Salesperson.o Manager.o

$(APP): $(OBJECTS)
	$(CC++) $(C++FLAGS) -o $@ $(OBJECTS) $(LIBS)


.C.o: $(HFILES)
	$(CC++) $(C++FLAGS) -c $<


clean:
	rm -rf $(OBJECTS)
	rm -rf $(APPS)