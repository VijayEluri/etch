/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */


// This file automatically generated by:
//   Apache Etch 1.1.0-incubating (LOCAL-0) / c 1.1.0-incubating (LOCAL-0)
//   Fri Aug 28 15:58:20 CEST 2009
// This file is automatically created and should not be edited!

/*
 * helloworld_remote_client.h 
 */

#ifndef HELLOWORLD_REMOTE_CLIENT_H
#define HELLOWORLD_REMOTE_CLIENT_H

#include "helloworld_remote.h"
#include "helloworld_client.h"
#include "etch_transport.h"

#ifdef __cplusplus
extern "C" {
#endif

extern unsigned short CLASSID_HELLOWORLD_REMOTE_CLIENT;

/**
 * helloworld_remote_client
 */
typedef struct helloworld_remote_client
{
    etch_object object;  

    i_helloworld_client* client_base;     /* owned */
    helloworld_remote* remote_base;     /* owned */
    etch_client_factory* client_factory; /* owned */
    default_value_factory* vf;   /* owned by base */
    int session_id;

    /* toward-client virtuals go here */
    
/*
    helloworld_user* user;
*/


    /* private, generally. since unit tests invoke async begin and end,
     * we must expose them either as virtuals or as external references.
     */
     

    
    
} helloworld_remote_client;

/* constructor */
helloworld_remote_client* new_helloworld_remote_client (void*, etch_session*, etch_value_factory*);

#ifdef __cplusplus
} //extern "C"
#endif

#endif /* HELLOWORLD_REMOTE_CLIENT_H */