#include <stdio.h>
#include "libs/color_print/color_print.h"
#include "libs/messages_to_console/messages_to_console.h"
#include "libs/memory/memory.h"

int main(int argc, char** argv) {
    PRINT_DBG("file name: '%s'", argv[0]);
    
    PRINT_DBG("");
    return 0;
}