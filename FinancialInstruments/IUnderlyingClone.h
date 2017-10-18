#pragma once

#include <boost/uuid/uuid.hpp>
#include <string>

__interface IUnderlyingClone
{

	virtual const std::string &GetTicket() const;
	virtual const boost::uuids::uuid &GetUUID() const;

};