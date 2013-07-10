/*
 * main.c
 *
 *  Created on: Jun 24, 2013
 *      Author: aalwatta
 */

#include <stdio.h>
#include <stdlib.h>

#include  "rcsSimulator.h"
#include  "common_interfaces.h"

int main()
{
    Common_Interface input_data;
    Hardware hardware;
    
    initArchLibrary("/home/jennifer/work/common_interfaces/src/conf/arch.conf", &(input_data.archlib));
    initDFG("/home/jennifer/work/common_interfaces/src/conf/dfg.conf", &(input_data.dfg));
    initHardwareLibrary("/home/jennifer/work/common_interfaces/src/conf/prr.conf", &hardware);
    input_data.setup = hardware.setups[i];
    
	struct SimData simData={.typeData={1,1,1,1,1,1,1,1,1,1}};
	struct SimResults simResults;

	simData.dFGID = 0;
	simData.noGPP = 0;
	simData.noPRR = 5;
	simData.noOfNodes = 10;
    
	InitSimulator(input_data);
	RunSimulator(&simData,&simResults);
	CleanSimulator();


	fprintf(stdout, "Process complete in {%d} cycles \n", simResults.totalTime);
	fprintf(stdout,
			"Number of configuration= %u SW Busy [%u] HW Busy [%u]\n",
			simResults.noOfConfiguration, simResults.noSWBusyCounter,
			simResults.noHWBusyCounter);
	fprintf(stdout,
			"SW2HW MIG [%u]  HW2SW Mig [%u] #of Reuse [%u]  #SW tasks [%u]\n",
			simResults.noSW2HWMigration, simResults.noHW2SWMigration, simResults.noOfReuse,
			simResults.noOfSWTasks);
    
    
    freeArchLibrary(&(input_data.archlib));
    freeDFG(&(input_data.setup));
    freeHardwareLibrary(&hardware);

	return (EXIT_SUCCESS);
}
