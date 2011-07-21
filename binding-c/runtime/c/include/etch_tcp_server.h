/* $Id$ 
 * 
 * Licensed to the Apache Software Foundation (ASF) under one or more 
 * contributor license agreements. See the NOTICE file distributed with  
 * this work for additional information regarding copyright ownership. 
 * The ASF licenses this file to you under the Apache License, Version  
 * 2.0 (the "License"); you may not use this file except in compliance  
 * with the License. You may obtain a copy of the License at 
 * 
 * http://www.apache.org/licenses/LICENSE-2.0 
 * 
 * Unless required by applicable law or agreed to in writing, software 
 * distributed under the License is distributed on an "AS IS" BASIS, 
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and 
 * limitations under the License. 
 */ 

/*
 * etch_tcp_server.h
 */

#ifndef ETCHTCPSERVER_H
#define ETCHTCPSERVER_H

#include "apr_thread_proc.h"
#include "etch_tcp_connection.h"
#include "etch_resources.h"
#include "etch_session_listener.h"
#include "etch_mutex.h"
#include "etch_linked_list.h"
#include "etch_server.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ETCH_TCPSERVER_STATE_CLOSED   0
#define ETCH_TCPSERVER_STATE_CLOSING  1
#define ETCH_TCPSERVER_STATE_STOPPED  2
#define ETCH_TCPSERVER_STATE_STOPPING 3
#define ETCH_TCPSERVER_STATE_STARTING 4
#define ETCH_TCPSERVER_STATE_STARTED  5

/**
 * etch_tcp_server 
 * tcp listener class
 */
typedef struct etch_tcp_server
{
    ETCH_SERVER_COMMON_TYPES;

    etch_tcp_connection* cxlisten; /* owned */
    int  backlog;
} etch_tcp_server;

unsigned tcpserver_id_farm;

etch_tcp_server* new_tcp_server(etch_url*, etch_threadpool*, etch_threadpool*, etch_resources*, i_sessionlistener*);
int  etch_tcpsvr_open (etch_tcp_server*, const int is_reconnect);
int  etch_tcpsvr_start(etch_tcp_server*);
int  etch_tcpsvr_stop (etch_tcp_server*);
int  etch_tcpsvr_close(etch_tcp_server*);

#ifdef __cplusplus
}
#endif

#endif  /* ETCHTCPSERVER_H */
