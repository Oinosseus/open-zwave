//-----------------------------------------------------------------------------
//
//	Protection.h
//
//	Implementation of the Z-Wave COMMAND_CLASS_PROTECTION
//
//	Copyright (c) 2010 Mal Lansell <openzwave@lansell.org>
//
//	SOFTWARE NOTICE AND LICENSE
//
//	This file is part of OpenZWave.
//
//	OpenZWave is free software: you can redistribute it and/or modify
//	it under the terms of the GNU Lesser General Public License as published
//	by the Free Software Foundation, either version 3 of the License,
//	or (at your option) any later version.
//
//	OpenZWave is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU Lesser General Public License for more details.
//
//	You should have received a copy of the GNU Lesser General Public License
//	along with OpenZWave.  If not, see <http://www.gnu.org/licenses/>.
//
//-----------------------------------------------------------------------------

#ifndef _Protection_H
#define _Protection_H

#include "CommandClass.h"

namespace OpenZWave
{
	namespace Internal
	{
		namespace CC
		{

			/** \brief Implements COMMAND_CLASS_PROTECTION (0x75), a Z-Wave device command class.
			 * \ingroup CommandClass
			 */
			class Protection: public CommandClass
			{
				public:
					enum ProtectionEnum
					{
						Protection_Unprotected = 0,
						Protection_Sequence,
						Protection_NOP
					};

					static CommandClass* Create(uint32 const _homeId, uint8 const _nodeId)
					{
						return new Protection(_homeId, _nodeId);
					}
					virtual ~Protection()
					{
					}

					static uint8 const StaticGetCommandClassId()
					{
						return 0x75;
					}
					static string const StaticGetCommandClassName()
					{
						return "COMMAND_CLASS_PROTECTION";
					}

					// From CommandClass
					virtual bool RequestState(uint32 const _requestFlags, uint8 const _instance, Driver::MsgQueue const _queue) override;
					virtual bool RequestValue(uint32 const _requestFlags, uint16 const _index, uint8 const _instance, Driver::MsgQueue const _queue) override;
					virtual uint8 const GetCommandClassId() const override
					{
						return StaticGetCommandClassId();
					}
					virtual string const GetCommandClassName() const override
					{
						return StaticGetCommandClassName();
					}
					virtual bool HandleMsg(uint8 const* _data, uint32 const _length, uint32 const _instance = 1) override;
					virtual bool SetValue(Internal::VC::Value const& _value) override;

				protected:
					virtual void CreateVars(uint8 const _instance) override;

				private:
					Protection(uint32 const _homeId, uint8 const _nodeId) :
							CommandClass(_homeId, _nodeId)
					{
					}
			};
		} // namespace CC
	} // namespace Internal
} // namespace OpenZWave

#endif

