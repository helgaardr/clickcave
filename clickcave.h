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

#ifndef __CLICKCAVE_H__
#define __CLICKCAVE_H__

#ifdef __cplusplus
extern "C" {
#endif

enum clickcave_compression { None = -1, LZ4 = 1 };
typedef enum clickcave_compression clickcave_compression_t;

struct clickcave;
typedef struct clickcave clickcave_t;

clickcave_t *clickcave_create(char *host, int port, char *defaultdb, char *user, char *password);

void clickcave_destroy(clickcave_t *c);

void clickcave_execute(clickcave_t *c, const char *table);

void clickcave_select(clickcave_t *c, const char *table);

/* void clickcave_selectcallback(clickcave_t *c, const char *table);

void clickcave_selectcancelable(clickcave_t *c, const char *table, ***callback***);

void clickcave_insert(clickcave_t *c, const char *table);*/

void clickcave_ping(clickcave_t *c);

void clickcave_resetconnection(clickcave_t *c);

#ifdef __cplusplus
}
#endif

#endif /* __CLICKCAVE_H__ */
