/*****************************************************************/
/*    NAME: Michael Benjamin, Henrik Schmidt, and John Leonard   */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: BRS_MOOSApp.h                                        */
/*    DATE: Feb 1st, 2011                                        */
/*                                                               */
/* This program is free software; you can redistribute it and/or */
/* modify it under the terms of the GNU General Public License   */
/* as published by the Free Software Foundation; either version  */
/* 2 of the License, or (at your option) any later version.      */
/*                                                               */
/* This program is distributed in the hope that it will be       */
/* useful, but WITHOUT ANY WARRANTY; without even the implied    */
/* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR       */
/* PURPOSE. See the GNU General Public License for more details. */
/*                                                               */
/* You should have received a copy of the GNU General Public     */
/* License along with this program; if not, write to the Free    */
/* Software Foundation, Inc., 59 Temple Place - Suite 330,       */
/* Boston, MA 02111-1307, USA.                                   */
/*****************************************************************/

#ifndef UFLD_BEACON_RANGE_SENSOR_HEADER
#define UFLD_BEACON_RANGE_SENSOR_HEADER

#include "MOOSLib.h"
#include "BRS_Model.h"
#include "VarDataPair.h"

class BRS_MOOSApp : public CMOOSApp
{
 public:
  BRS_MOOSApp() {};
  virtual ~BRS_MOOSApp() {};

  bool OnNewMail(MOOSMSG_LIST &NewMail);
  bool Iterate();
  bool OnConnectToServer();
  bool OnStartUp();
  void RegisterVariables();

  void setVerbose(std::string s) {m_model.setParam("verbose",s);}

 protected:
  void postMessages(std::vector<VarDataPair>);

 protected:
  BRS_Model  m_model;
};

#endif 
