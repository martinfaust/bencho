#include "PlotterPython.h"

#include <cstdlib>
#include <string>
#include <iostream>

#include "resultFileHelper.h"


PlotterPython::PlotterPython()
{
    _plotterName = "python matplotlib";
    _plotterFileEnding = ".py";
}

void PlotterPython::callPlot(std::string resultDir, std::string plotterScript, std::string /*systemScript*/, std::string benchName, std::string benchId)
{
	std::string resultFile = getResultFile(benchName, benchId, resultDir);

	std::cout << "Benchmark: \"" + benchName + "\", ID: " + benchId << std::endl;

    std::string command = "export PYTHONPATH=$PYTHONPATH:" + getSystemScriptDir() + " && python " + plotterScript + " -f " + resultFile + " -n " + benchName;
    
    if (int err = std::system(command.c_str()))
    {
        std::cerr << "Error during system call: " << err << std::endl;
    }
}
