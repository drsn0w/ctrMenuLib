/* CtrMenuLib
 * v0.1 by drsn0w
 * ctrMenuLib.c
 */

#include <3ds.h>
#include <stdio.h>
#include "ctrMenuLib.h"

// Current position of the selection arrow
int controller_position = 0;

// array of function pointers (FIVE for now)
p2function menu_functions[5] = {NULL};
// Array of strings corresponding to function pointers
char* menu_titles[5];
// Length of menu arrays, used internally
int menu_length = 0;

// menu print console
PrintConsole* menuScreen;
// output print console
PrintConsole* outputScreen;
// Screen with menu (hope to phase this out later)
gfxScreen_t menuGfxScreen;

// (re)draws the menu options on screen
void _redrawMenu(int pointerPosition) {
  consoleInit(menuGfxScreen, menuScreen);
  printf("Menu\n");
  for(int i=0; i < menu_length; i++) {
    if(i == pointerPosition) printf("*%s\n", menu_titles[i]);
    else printf(" %s\n", menu_titles[i]);
  }
}

// Dummy for now, just sets controller_position for blind menu operation!
void ctrmenu_display_menu(gfxScreen_t gfxScreen, PrintConsole* menu_console, PrintConsole* output_console) {

  menuScreen = menu_console;
  outputScreen = output_console;
  menuGfxScreen = gfxScreen;
  _redrawMenu(controller_position);
  consoleSelect(outputScreen);
  printf("Hey look! A menu!\n");

}

// Register's function pointer in array with a title
void ctrmenu_register_function(char* option_title[], p2function function_pointer) {
  if (menu_length < 5) {
    menu_titles[menu_length] = option_title;
    menu_functions[menu_length] = function_pointer;
    menu_length++;
  } //failover else clause added later
}

void ctrmenu_selection_up() {
  // handle various cases that should NEVER EVER HAPPEN!
  if(menu_length == 0) printf("There are no menu options! Help!\n");
  else if(controller_position+1 > menu_length || controller_position < 0) printf("Controller is out of bounds! Help!\n");

  // if the controller arrow is at the top of the list, hop back down to the bottom
  else if(controller_position == 0) controller_position = menu_length-1;
  // otherwise, just decrease the counter (smaller == higher in menu)
  else controller_position--;
  consoleSelect(menuScreen);
  _redrawMenu(controller_position);
  consoleSelect(outputScreen);
}

void ctrmenu_selection_down() {
  // handle various cases that should NEVER EVER HAPPEN!
  if(menu_length == 0) printf("There are no menu options! Help!\n");
  else if(controller_position+1 > menu_length || controller_position < 0) printf("Controller is out of bounds! Help!\n");

  // if the controller arrow is at the bottom of the list, hop back up to the top
  else if(controller_position+1 == menu_length) controller_position = 0;
  // otherwise, just increase the counter
  else controller_position++;
  consoleSelect(menuScreen);
  _redrawMenu(controller_position);
  consoleSelect(outputScreen);
}

void ctrmenu_selection_select() {
  // handle various cases that should NEVER EVER HAPPEN!
  if(menu_length == 0) printf("There are no menu options! Help!\n");
  else if(controller_position+1 > menu_length || controller_position < 0) printf("Controller is out of bounds! Help!\n");
  // otherwise, run the selected option
  else (*menu_functions[controller_position])();
}
