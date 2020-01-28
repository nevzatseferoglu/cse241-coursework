#OBJS specifies which files to compile as part of the project
OBJS = driver.cpp ./src/AbstractBoard.cpp ./src/BoardArray1D.cpp ./src/BoardArray2D.cpp ./src/BoardVector.cpp ./src/Global.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
COMPILER_FLAGS = -w --std=c++11

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = output

#This is the target that compiles our executable
all :	$(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
