/* 
	Copyright 2010 Mona - mathieu.poux[a]gmail.com
 
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License received along this program for more
	details (or else see http://www.gnu.org/licenses/).

	This file is a part of Mona.
*/

#pragma once


#include "Mona/Mona.h"
#include "Mona/DatagramSocket.h"
#include "Mona/Buffer.h"

namespace Mona {

class UDPSocket : protected DatagramSocket, virtual Object {
public:
	UDPSocket(const SocketManager& manager,bool allowBroadcast=false);

	bool					bind(Exception& ex, const SocketAddress& address);
	bool					connect(Exception& ex, const SocketAddress& address);
	void					close();

	bool					send(Exception& ex, const UInt8* data, UInt32 size);
	bool					send(Exception& ex, const UInt8* data, UInt32 size, const SocketAddress& address);

	const SocketAddress&	address();
	const SocketAddress&	peerAddress();

private:
	virtual void			onReception(const UInt8* data, UInt32 size, const SocketAddress& address) = 0;
	void					onReadable(Exception& ex);

	Buffer<UInt8>			_buffer;
	bool					_allowBroadcast;
	bool					_broadcasting;

	SocketAddress			_address;
	SocketAddress			_peerAddress;
};



} // namespace Mona