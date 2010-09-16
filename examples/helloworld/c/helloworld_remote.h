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
 * $helper.getRemoteFileNameH($intf, $mc)
 * helloworld remote.
 * combines java bindings's RemotePerf, Perf, and RemoteBase.
 */

#ifndef HELLOWORLD_REMOTE_H
#define HELLOWORLD_REMOTE_H

#include "helloworld_interface.h"
#include "etch_remote.h"
#include "etch_transport.h"

#ifdef __cplusplus
extern "C" {
#endif

extern unsigned short CLASSID_HELLOWORLD_REMOTE;

/**
 * helloworld_remote
 */
typedef struct helloworld_remote
{
    etch_object object;    

    i_helloworld*  ihelloworld; /* possibly owned */
    i_delivery_service*  dsvc;  /* not owned */
    etch_value_factory*  vf;    /* not owned */
    unsigned char  remote_type; /* client or server */
    unsigned char  is_service_interface_owned;
    unsigned short unused;      /* alignment */

    etch_message* (*new_message) (void*, etch_type*);
    int   (*send)   (void*, etch_message*);
    void* (*sendex) (void*, etch_message*);
    etch_delivsvc_begincall begin_call;  /* i_mailbox** out */
    etch_delvisvc_endcall   end_call;    /* etch_object** out */

    int (*start_waitup)  (void*, const int waitms);
    int (*stop_waitdown) (void*, const int waitms);

    /* - - - - - - - - - - - - -
     * transport functionality
     * - - - - - - - - - - - - -
     */
    etch_transport_control transport_control;  
    etch_transport_notify  transport_notify;   
    etch_transport_query   transport_query; 
    etch_transport_get_session get_session;  
    etch_transport_set_session set_session; 

    /* - - - - - - - - - - -
     * service virtuals
     * - - - - - - - - - - -
     */
    helloworld_say_hello say_hello;

    helloworld_user* user;

    /* - - - - - - - - - - -
     * private instance data
     * - - - - - - - - - - -
     */    

} helloworld_remote;


helloworld_remote* new_helloworld_remote (void*, i_delivery_service*, etch_value_factory*, i_helloworld*);

#ifdef __cplusplus
} //extern "C"
#endif
#endif /* HELLOWORLD_REMOTE_H */