/* ctrMenuLib v0.1 by drsn0w
 * ctrMenuLib.h
*/

#include <stdio.h>
#include <3ds.h>


#ifndef CTRMENULIB_H
#define CTRMENULIB_H


// typedef for function pointers
typedef void(*p2function)();


void ctrmenu_register_function(char* option_title[], p2function function_pointer);
void ctrmenu_display_menu(gfxScreen_t gfxScreen, PrintConsole* menu_console, PrintConsole* output_console);
/*

void ctrmenu_destroy_menu();
void ctrmenu_hide_menu();
void ctrmenu_unhide_menu();
*/

void ctrmenu_selection_down();
void ctrmenu_selection_up();
void ctrmenu_selection_select();



 #endif
