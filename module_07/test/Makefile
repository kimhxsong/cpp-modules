CR_LIB := -L ${shell brew --prefix criterion}/lib -lcriterion
CR_INCLUDE := -I ${shell brew --prefix criterion}/include/

SUITE_NAME = suite_00

all: test00

test00:
		c++ -o ${SUITE_NAME} *.cpp ${CR_LIB} ${CR_INCLUDE} -std=c++11

clean:
		${RM} ${SUITE_NAME}