
#include <3ds.h>
#include <stdio.h>
#include "ctrMenuLib.h"

void dummyFunction() {
  printf("iAmDummy1\n");
}

void dummyFunction2() {
  printf("iAmDummy2\n");
}

void dummyFunction3() {
  printf("iAmDummy3\n");
}

void clearTopScreen() {
  consoleClear();
}

int main(int argc, char **argv) {
  PrintConsole topScreen, bottomScreen;
  gfxInitDefault();
  consoleInit(GFX_TOP, &topScreen);
  consoleInit(GFX_BOTTOM, &bottomScreen);
  ctrmenu_register_function("Test Option 1", &dummyFunction);
  ctrmenu_register_function("Test Option 2", &dummyFunction2);
  ctrmenu_register_function("Test Option 3", &dummyFunction3);
  ctrmenu_register_function("Clear Output Screen", &clearTopScreen);
  ctrmenu_display_menu(GFX_BOTTOM, &bottomScreen, &topScreen);
  printf("Press START to exit at any time");
  while(aptMainLoop()) {
    hidScanInput();
    u32 kDown = hidKeysDown();
    if (kDown & KEY_DUP) ctrmenu_selection_up();
    if (kDown & KEY_DDOWN) ctrmenu_selection_down();
    if (kDown & KEY_A) ctrmenu_selection_select();
    if (kDown & KEY_START) break;

    //Flush and swap framebuffers
    gfxFlushBuffers();
    gfxSwapBuffers();
    gspWaitForVBlank();
  }
  cfguExit();
  gfxExit();
  return 0;
}
