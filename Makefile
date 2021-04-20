#OBJS specifies which files to compile as part of the project
OBJS = Main.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = Mogue

SDL_INCLUDE = "C:\\Users\\finnm\\Desktop\\CSCWork\\Libraries\\SDL\\include"
SDL_LINK = 	  "C:\\Users\\finnm\\Desktop\\CSCWork\\Libraries\\SDL\\lib"
#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) -I$(SDL_INCLUDE) -L$(SDL_LINK) -lSDL2 -o $(OBJ_NAME)