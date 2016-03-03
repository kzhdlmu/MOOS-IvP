/*****************************************************************/
/*    NAME: Michael Benjamin, Henrik Schmidt, and John Leonard   */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: IC_Model.h                                           */
/*    DATE: Apr 19th 2011                                        */
/*                                                               */
/* This file is part of MOOS-IvP                                 */
/*                                                               */
/* MOOS-IvP is free software: you can redistribute it and/or     */
/* modify it under the terms of the GNU General Public License   */
/* as published by the Free Software Foundation, either version  */
/* 3 of the License, or (at your option) any later version.      */
/*                                                               */
/* MOOS-IvP is distributed in the hope that it will be useful,   */
/* but WITHOUT ANY WARRANTY; without even the implied warranty   */
/* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See  */
/* the GNU General Public License for more details.              */
/*                                                               */
/* You should have received a copy of the GNU General Public     */
/* License along with MOOS-IvP.  If not, see                     */
/* <http://www.gnu.org/licenses/>.                               */
/*****************************************************************/

#ifndef IVP_CHECK_MODEL_HEADER
#define IVP_CHECK_MODEL_HEADER

#include "MOOSLock.h"
#include "QuadSet.h"
#include "FunctionQueue.h"
#include "FColorMap.h"

class IC_Model
{
public:
  IC_Model();
  ~IC_Model() {};

public:
  void     addIPF(std::string ipf_str);
  void     modColorMap(const std::string&);
  void     toggleCollective() {m_collective = !m_collective;};

  const QuadSet* getQuadSet(int index);

protected:
  std::vector<QueueEntry> m_queue_entries;
  bool                    m_collective;
};
#endif 





