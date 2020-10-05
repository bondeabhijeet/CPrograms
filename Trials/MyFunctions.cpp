#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
// C Implementation for setcolor()
#include <stdio.h>
#include<windows.h>

// driver code
int main()
{
	// gm is Graphics mode which is
	// a computer display mode that
	// generates image using pixels.
	// DETECT is a macro defined in
	// "graphics.h" header file
	int gd = DETECT, gm, color;

	// initgraph initializes the
	// graphics system by loading a
	// graphics driver from disk
	initgraph(&gd, &gm, "DETECT");

	// Draws circle in white color
	// center at (100, 100) and radius
	// as 50
	circle(100, 100, 50);

	// setcolor function
	setcolor(GREEN);

	// Draws circle in green color
	// center at (200, 200) and radius
	// as 50
	circle(200, 200, 50);

	getch();

	// closegraph function closes the
	// graphics mode and deallocates
	// all memory allocated by
	// graphics system .
	closegraph();

	return 0;
}
