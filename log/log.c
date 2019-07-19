#include "log.h"


/*
 *   打印logo信息
*/

     // _           
    // | | _____  __
 // _  | |/ _ \ \/ /
// | |_| | (_) >  < 
 // \___/ \___/_/\_\
// apt-get install sysvbanner toilet figlet
// figlet JOX

void print_logo()
{
    printf("_______________________\n");
    printf("     _            \n");
    printf("    | | _____  __ \n");
    printf(" _  | |/ _ \\ \\/ / \n");
    printf("| |_| | (_) >  <  \n");
    printf(" \\___/ \\___/_/\\_\\\n");
    printf("                  \n");
    printf("Compile Time: %s,%s\n",__DATE__,__TIME__);
    printf("Version     : %s\n",LOGDEBUGVERSION);
    printf("_______________________\n");
}

int main()
{
    print_logo();
	
	
	
	DEBUG_MSG("TEST DEBUG_MSG\r\n");
	DEBUG_MSG_LINE("TEST DEBUG_MSG_LINE\r\n");
	LOG_INFO("TEST LOG_INFO\r\n");
	
	LOG_ERR("TEST LOG_ERR\r\n");
    return 0;
}


