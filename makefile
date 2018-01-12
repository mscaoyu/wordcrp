CC:=g++
FLAGS:=
OBJECTS:=test.o Vocabulary.o Sampler.o FileReader.o Parameter.o
SRC:=test.cc Vocabulary.cc Sampler.cc FileReader.cc Parameter.cc
INCLUDES:=./
STD:=-std=c++14
client:${OBJECTS}
	${CC} -o test ${OBJECTS} ${FLAGS}
test.o:
	${CC} -c test.cc -I ${INCLUDES} ${STD}
Vocabulary.o:
	${CC} -c Vocabulary.cc -I ${INCLUDES} ${STD}
Sampler.o:
	${CC} -c Sampler.cc -I ${INCLUDES} ${STD}
FileReader.o:
	${CC} -c FileReader.cc -I ${INCLUDES} ${STD}
Parameter.o:
	${CC} -c Parameter.cc -I ${INCLUDES} ${STD}
.PHONY:clean
clean:
	rm -f *.o
