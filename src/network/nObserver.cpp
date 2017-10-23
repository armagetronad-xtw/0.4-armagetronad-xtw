/*

*************************************************************************

ArmageTron -- Just another Tron Lightcycle Game in 3D.
Copyright (C) 2000  Manuel Moos (manuel@moosnet.de)

**************************************************************************

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
  
***************************************************************************

*/

#include "nObserver.h"
#include "nNetObject.h"

#ifdef DEBUG
static const nObserver* sn_LastChecked = NULL;

void nObserver::SetLastChecked( const nObserver* checked )
{
    sn_LastChecked = checked;
}

bool nObserver::WasChecked( const nObserver* checked )
{
    return checked && checked == sn_LastChecked;
}
#endif

// returns the observed object
const nNetObject* nObserver::GetNetObject() 	const
{
    return this->object_;
}

// returns the observed object
void nObserver::SetObject( const nNetObject * o)
{
    this->object_ = o;
}


nObserver::nObserver()
{
    this->object_ = 0;
}

nObserver::~nObserver()
{
#ifdef DEBUG
    sn_LastChecked = NULL;
#endif
}
