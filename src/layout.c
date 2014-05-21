//#include "layout.h"
#include <stdlib.h>
#include <stdio.h>

#include "util.h"


void loadMainLogo(void) {
	printTo(((WINDOW_WIDTH-40)/2),16,"   _____           _       _          ");
	printTo(((WINDOW_WIDTH-40)/2),17,"  / ____|         | |     | |         ");
	printTo(((WINDOW_WIDTH-40)/2),18," | (___  _   _  __| | ___ | | ___   _ ");
	printTo(((WINDOW_WIDTH-40)/2),19,"  \\___ \\| | | |/ _` |/ _ \\| |/ / | | |");
	printTo(((WINDOW_WIDTH-40)/2),20,"  ____) | |_| | (_| | (_) |   <| |_| |");
	printTo(((WINDOW_WIDTH-40)/2),21," |_____/ \\__,_|\\__,_|\\___/|_|\\_\\__,__|");
}
