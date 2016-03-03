/*****************************************************************/
/*    NAME: Michael Benjamin                                     */
/*    ORGN: NAVSEA Newport RI and MIT Cambridge MA               */
/*    FILE: main.cpp                                             */
/*    DATE: June 3rd, 2008                                       */
/*                                                               */
/* This is unreleased BETA code. No permission is granted or     */
/* implied to use, copy, modify, and distribute this software    */
/* except by the author(s).                                      */
/*****************************************************************/

#include <string>
#include <cstdlib>
#include <iostream>
#include "MBUtils.h"
#include "HelmReporter.h"

using namespace std;

//--------------------------------------------------------
// Procedure: main

int main(int argc, char *argv[])
{
  // Look for a request for version information
  if(scanArgs(argc, argv, "-v", "--version", "-version")) {
    vector<string> svector = getReleaseInfo("aloghelm");
    for(unsigned int j=0; j<svector.size(); j++)
      cout << svector[j] << endl;    
    return(0);
  }

  bool use_colors  = true;
  bool report_life = false;
  if(scanArgs(argc, argv, "--life", "-l"))
    report_life = true;
  if(scanArgs(argc, argv, "--nocolor"))
    use_colors = false;
  
  bool file_overwrite = false;
  if(scanArgs(argc, argv, "-f", "--force", "-force"))
    file_overwrite = true;
  
  // Look for a request for usage information
  if(scanArgs(argc, argv, "-h", "--help", "-help")) {
    cout << "Usage: " << endl;
    cout << "  aloghelm file.alog  [OPTIONS]        " << endl;
    cout << "                                                           " << endl;
    cout << "Synopsis:                                                  " << endl;
    cout << "  Perform one of several optional helm reports based on    " << endl;
    cout << "  helm output logged in the given .alog file.              " << endl;
    cout << "                                                           " << endl;
    cout << "Options:                                                   " << endl;
    cout << "  -h,--help     Displays this help message                 " << endl;
    cout << "  -v,--version  Displays the current release version       " << endl;
    cout << "  -l,--life     Show report on IvP Helm Life Events        " << endl;
    cout << "  --nocolor     Turn off use of color coding               " << endl;
    cout << "                                                           " << endl;
    cout << "Further Notes:                                             " << endl;
    cout << "  (1) The order of arguments is irrelevent.                " << endl;
    cout << "  (2) Only the first specified .alog file is reported on.  " << endl;
    cout << endl;
    return(0);
  }

  vector<string> keys;
  string alogfile_in;

  for(int i=1; i<argc; i++) {
    string sarg = argv[i];
    if(strEnds(sarg, ".alog") && (alogfile_in == ""))
      alogfile_in = sarg;
  }
 
  if(alogfile_in == "") {
    cout << "No alog file given - exiting" << endl;
    exit(0);
  }
  cout << "Processing on file : " << alogfile_in << endl;
  
  HelmReporter hreporter;
  hreporter.setReportType("life");
  hreporter.setColorActive(use_colors);

  bool handled = hreporter.handle(alogfile_in);
  
  if(handled)
    hreporter.printReport();
}
