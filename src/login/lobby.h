/*
===========================================================================

  Copyright (c) 2010-2017 Darkstar Dev Teams

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see http://www.gnu.org/licenses/

  This file is part of DarkStar-server source code.

===========================================================================
*/

#ifndef _LOBBY_H
#define _LOBBY_H

/**
@file
@brief Contains methods for lobby connection, parsing and character creation.
*/

#include "../common/cbasetypes.h"
#include "../common/mmo.h"

#include "login_session.h"

/**
@brief  file descriptor (socket) to lobby data
*/
extern int32 login_lobbydata_fd;
/**
@brief  file descriptor (socket) to lobby view
*/
extern int32 login_lobbyview_fd;

/**
*   @brief  Handles lobby data socket connection.
*
*   @param  listenfd is a file descriptor (socket)
*   @return int32 (unused) bytes read from the socket
*/
int32 connect_client_lobbydata(int32 listenfd);

/**
*   @brief  Handles lobby view socket connection.
*
*   @param  listenfd is a file descriptor (socket)
*   @return int32 (unused) bytes read from the socket
*/
int32 connect_client_lobbyview(int32 listenfd);

/**
*   @brief  Parses lobby data from a socket.
*
*   @param  fd is a file descriptor (socket)
*   @return int32 (unused) bytes read from the socket
*/
int32 lobbydata_parse(int32 fd);

/**
*   @brief  Parses lobby view data from a socket.
*
*   @param  fd is a file descriptor (socket)
*   @return int32 (unused) bytes read from the socket
*/
int32 lobbyview_parse(int32 fd);

/**
*   @brief  Closes the lobby data socket.
*
*   @param  loginsd is a login_session_data_t* to be closed
*   @param  fd is a file descriptor (socket)
*   @return int32 either 0 (success) or -1 (failure)
*/
int32 do_close_lobbydata(login_session_data_t* loginsd, int32 fd);

/**
*   @brief  Closes the lobby view socket.
*
*   @param  loginsd is a login_session_data_t* to be closed
*   @param  fd is a file descriptor (socket)
*   @return int32 either 0 (success)
*/
int32 do_close_lobbyview(login_session_data_t* loginsd, int32 fd);

/**
*   @brief  Creates a new character.
*
*   @param  loginsd is character data
*   @param  buf is packet-level character data
*   @return int32 either 0 (success) or -1 (failure)
*/
int32 lobby_createchar(login_session_data_t* loginsd, int8* buf);

/**
*   @brief  Saves character data to the various database tables.
*
*   @param  accid is the account id
*   @param  charid is the character id
*   @param  createchar contains character data
*   @return int32 either 0 (success)
*/
int32 lobby_createchar_save(uint32 accid, uint32 charid, char_mini* createchar);

#endif
