/*
 ============================================================================
 Name        : fileRead.c
 Author      : Ahmed Al-Wattar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Parses and prints the configuration options for a function ftp client
 */

#include "common_interfaces.h"

int main(void){
    Architecture_Library arch_lib;
    DFG dfg;
    Hardware hardware;
    
    initArchLibrary("/home/jennifer/work/common_interfaces/src/conf/arch.conf", &arch_lib);
    printArchLibrary(&arch_lib);
    freeArchLibrary(&arch_lib);
    
    
    initHardwareLibrary("/home/jennifer/work/common_interfaces/src/conf/prr.conf", &hardware);
    printHardwareLibrary(&hardware);
    freeHardwareLibrary(&hardware);
    
    initDFG("/home/jennifer/work/common_interfaces/src/conf/dfg.conf", &dfg);
    printDFG(&dfg);
    freeDFG(&dfg);
    
    
    

    return 0;
}
