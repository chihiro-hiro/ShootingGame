#include "InputControl.h"

char InputControl::NowKey[BUTTONS];
char InputControl::OldKey[BUTTONS];
XINPUT_STATE InputControl::Input;
Stick InputControl::Rstick;
Stick InputControl::Lstick;