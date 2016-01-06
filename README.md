# ctrMenuLib
Very simple library for displaying very basic menus on 3DS.

## Usage
Make sure to import ctrMenuLib.h into your source file.

```
void ctrmenu_register_function(char* option_title[], p2function function_pointer);
```
Takes a character array (string) and a pointer to a function (&function_name). Adds item called option_title to the menu which will execute function_pointer when selected. At current stages, function pointers passed to this function must have a return type of void and take no parameters. Menu items will be displayed in the order they are registered with this function.

```
void ctrmenu_display_menu(gfxScreen_t gfxScreen, PrintConsole* menu_console, PrintConsole* output_console);
```
Takes gfxScreen_t (enum provided by libctru, either GFX_TOP or GFX_BOTTOM) for the menu screen, and two PrintConsole pointers, the first one for the menu screen, the second for the output screen. Note that it is currently required to pass gfxScreen_t as well as the menu PrintConsole pointer due to a limitation  in libctru that I haven't figured out how to overcome. If gfxScreen and menuConsole are not the same screen (top, or bottom) you will recieve strange results.
This function displays the menu. This should be run right before the main loop of your application
