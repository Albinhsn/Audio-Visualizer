FILES = main.c

LIBS = -I. -L. -lraylib -lglfw3 -lGL -lopenal -lm -lpthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor

MUSIC_FILE = ./music/EQ.mp3

b:
	gcc -o main  $(FILES) $(LIBS)

r:
	./main $(MUSIC_FILE)

br:
	gcc -o main $(FILES) $(LIBS) && ./main $(MUSIC_FILE)
