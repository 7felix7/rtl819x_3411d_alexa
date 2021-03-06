/*

logging.c

Message logging plugin for webserver.

gSOAP XML Web services tools
Copyright (C) 2004-2005, Robert van Engelen, Genivia, Inc. All Rights Reserved.

--------------------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

Author contact information:
engelen@genivia.com / engelen@acm.org
--------------------------------------------------------------------------------
*/

#include "logging.h"

const char logging_id[] = LOGGING_ID;

static int logging_init(struct soap *soap, struct logging_data *data);
static void logging_delete(struct soap *soap, struct soap_plugin *p);
static int logging_send(struct soap *soap, const char *buf, size_t len);
static size_t logging_recv(struct soap *soap, char *buf, size_t len);

int logging(struct soap *soap, struct soap_plugin *p, void *arg)
{ p->id = logging_id;
  p->data = (void*)malloc(sizeof(struct logging_data));
  p->fdelete = logging_delete;
  if (p->data)
    if (logging_init(soap, (struct logging_data*)p->data))
    { free(p->data); /* error: could not init */
      return SOAP_EOM; /* return error */
    }
  return SOAP_OK;
}

static int logging_init(struct soap *soap, struct logging_data *data)
{ data->inbound = NULL;
  data->outbound = NULL;
  data->stat_sent = 0;
  data->stat_recv = 0;
  data->fsend = soap->fsend; /* save old recv callback */
  data->frecv = soap->frecv; /* save old send callback */
  soap->fsend = logging_send; /* replace send callback with ours */
  soap->frecv = logging_recv; /* replace recv callback with ours */
  return SOAP_OK;
}

static void logging_delete(struct soap *soap, struct soap_plugin *p)
{ free(p->data); /* free allocated plugin data. If fcopy() is not set, then this function is not called for all copies of the plugin created with soap_copy(). In this example, the fcopy() callback is omitted and the plugin data is shared by the soap copies created with soap_copy() */
}

static size_t logging_recv(struct soap *soap, char *buf, size_t len)
{ struct logging_data *data = (struct logging_data*)soap_lookup_plugin(soap, logging_id);
  size_t res = data->frecv(soap, buf, len); /* get data from old recv callback */
  data->stat_recv += res;
  /* update should be in mutex, but we don't mind some inaccuracy in the count */
  if (data->inbound)
    fwrite(buf, res, 1, data->inbound);
  return res;
}

static int logging_send(struct soap *soap, const char *buf, size_t len)
{ struct logging_data *data = (struct logging_data*)soap_lookup_plugin(soap, logging_id);
  /* update should be in mutex, but we don't mind some inaccuracy in the count */
  data->stat_sent += len;
  if (data->outbound)
    fwrite(buf, len, 1, data->outbound);
  return data->fsend(soap, buf, len); /* pass data on to old send callback */
}

