# /bin/bash

if [ -z $1 ]
then
	PROJECT_NAME="temp"
else
	PROJECT_NAME=$1
fi

if [ -d $PROJECT_NAME ]
then
	echo "project [$PROJECT_NAME] have been existed, please change another project name!"
	exit
fi

mkdir -p $PROJECT_NAME/src $PROJECT_NAME/include $PROJECT_NAME/bin
SRC_DIR=$PROJECT_NAME/src
BIN_DIR=$PROJECT_NAME/bin
WORKSPACE=`pwd`

cd $SRC_DIR && cat >> Main.cpp << EOF
#include <iostream>
int main(int argc, char *argv[]) {
    return 0;
}
EOF

cd $WORKSPACE && cd $PROJECT_NAME
cat >> Makefile << EOF
CXX = g++
RM = rm -f 
CXXFLAGS = -std=c++11 -Wall -Wextra
ifdef DEBUG
	CXXFLAGS += -DDEBUG
endif
SRC_DIR = src
BIN_DIR = bin
INC_DIR = include

TARGET = \$(BIN_DIR)/$PROJECT_NAME
SRC = \$(wildcard \$(SRC_DIR)/*.cpp \$(SRC_DIR)/*/*.cpp)
OBJECTS = \$(patsubst %.cpp,%.o,\$(SRC))
ALL : clean \$(TARGET)

\$(TARGET) : \$(OBJECTS)
	\$(CXX) \$(CXXFLAGS) $^ -o \$@ 

\$(OBJECTS) : %.o : %.cpp
	\$(CXX) \$(CXXFLAGS) -c $< -o \$@ -I./\$(INC_DIR) -I./\$(SRC_DIR)

.PHONY : clean
clean:
	\$(RM) \$(OBJECTS)
	\$(RM) \$(TARGET)
EOF
