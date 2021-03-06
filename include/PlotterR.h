/** @file PlotterR.h
 *
 * Contains the class definition of PlotterR.
 * For any undocumented method see AbstractPlotter.
 * @see AbstractPlotter
 *
 */

#ifndef PLOTTERR_H
#define PLOTTERR_H


#include "AbstractPlotter.h"


/**
 * @brief Class for plotting results with R ggplot2.
 *
 * PlotterR is derived from AbstractPlotter
 * and serves as a plotter class for plotting results with R ggplot2.
 */
class PlotterR : public AbstractPlotter
{
public:
	PlotterR();
	
private:

	/**
	 * Calls the command for executing the plotting with R.
	 *
	 * @param resultDir Directory where result files of the benchmark are stored.
	 * @param plotterScript Relative path to the individual plotting script for the benchmark.
	 * @param systemScript Relative path to the general plotting script for the plotter.
	 * @param benchName Name of the benchmark that will be plotted.
	 * @param benchId Id of the benchmark that will be plotted.
	 */
	void callPlot(std::string resultDir, std::string plotterScript, std::string systemScript, std::string benchName, std::string benchId);
};


#endif //PLOTTERR_H
