#include "PlotterR.h"

#include <cstdlib>
#include <string>
#include <iostream>

#include "resultFileHelper.h"


PlotterR::PlotterR()
{
    _plotterName = "R gplot2";
    _plotterFileEnding = ".r";
}

void PlotterR::callPlot(std::string resultDir, std::string plotterScript, std::string systemScript, std::string benchName, std::string benchId)
{
	std::string resultFile = getResultFile(benchName, benchId, resultDir);

	std::cout << "Benchmark: \"" + benchName + "\", ID: " + benchId << std::endl;

	std::string command = "R CMD BATCH --no-save '--args " + resultFile + " " + plotterScript + "' " + systemScript + " /dev/null"; // redirect console output to /dev/null

    if (int err = std::system(command.c_str()))
    {
        std::cerr << "Error during system call: " << err << std::endl;
    }
}
