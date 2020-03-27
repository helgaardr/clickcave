/* 
  Copyright (C) 2020- Simone Fedele <simo@esseemme.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include <stdlib.h>

#include <clickhouse/client.h>

#include "clickcave.h"

#ifndef __CLICKCAVE_C__
#define __CLICKCAVE_C__

#ifdef __cplusplus
extern "C" {
#endif

struct clickcave
{
  void *object;
};

clickcave_t *clickcave_create(char *host, int port, char *defaultdb, char *user, char *password) {
  clickcave_t *c;
  clickhouse::Client *client;

  clickhouse::ClientOptions co;
  co.SetHost(host);
  co.SetPort(9000);
  co.SetDefaultDatabase(defaultdb);
  co.SetUser(user);
  co.SetPassword(password);
  // co.SetRethrowException(true);
  // co.SetPingBeforeQuery(false);
  // co.SetSendRetries(1);
  // co.SetRetryTimeout(5);
  // co.SetCompressionMethod(CompressionMethod::None);
  // co.TcpKeepAlive(false);
  // co.SetTcpKeepAliveIdle(60);
  // co.SetTcpKeepAliveInterval(5);
  // co.SetTcpKeepAliveCount(3);

  c = (clickcave_t *)malloc(sizeof(c));
  client = new clickhouse::Client(co);

  c->object = (void *)client;

  return c;
};

void clickcave_destroy(clickcave_t *c)
{
  if (c == NULL)
    return;
  delete static_cast<clickhouse::Client *>(c->object);
  free(c);
}

void clickcave_execute(clickcave_t *c, const char *query)
{
  clickhouse::Client *obj = static_cast<clickhouse::Client *>(c->object);
  obj->Execute(query);
};
/*
void clickcave_select(clickcave_t *c, const char *query);
void clickcave_selectcallback(clickcave_t *c, const char *table);
void clickcave_selectcancelable(clickcave_t *c, const char *table, ***callback***);
void clickcave_insert(clickcave_t *c, const char *table,);
*/
void clickcave_ping(clickcave_t *c){
  clickhouse::Client *obj = static_cast<clickhouse::Client *>(c->object);
  obj->Ping();
};

void clickcave_resetconnection(clickcave_t *c)
{
  clickhouse::Client *obj = static_cast<clickhouse::Client *>(c->object);
  obj->ResetConnection();
};

#ifdef __cplusplus
}
#endif

#endif /* __CLICKCAVE_C__ */
