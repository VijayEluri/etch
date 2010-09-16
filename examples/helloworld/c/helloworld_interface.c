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

#include "helloworld_interface.h"
#include "etch_url.h"  
#include "etch_objecttypes.h"
#include "etch_general.h"
#include "etch_cache.h"



unsigned short CLASSID_HELLOWORLD_SERVICE_INTERFACE;
unsigned short CLASSID_HELLOWORLD_USER;
unsigned short CLASSID_HELLOWORLD_USERUNKNOWNEXCEPTION;
	
	
etch_string* helloworld_def_say_hello(void* thisx, helloworld_user* to_whom);

int destroy_helloworld_service_interface (void*);


/*
 * destructors
 */
/**
 * destroy_helloworld_user()
 * user object destructor
 */
int destroy_helloworld_user(void* data)
{
    helloworld_user* this = (helloworld_user*)data;
    if(!((etch_object*)this)->is_static && this->name)
        etch_object_destroy(this->name); 
    destroy_object(this);
    return 0;
}
/**
 * destroy_helloworld_UserUnknownException()
 * userunknownexception object destructor
 */
int destroy_helloworld_UserUnknownException(void* data)
{
    helloworld_UserUnknownException* this = (helloworld_UserUnknownException*)data;
	if(!((etch_object*)this)->is_static)
    	etch_object_destroy(this->message);
    if(!((etch_object*)this)->is_static && this->mes)
        etch_object_destroy(this->mes); 
    destroy_object(this);
    return 0;
}

/* - - - - - - - - - - - - - -  
 * constructors
 * - - - - - - - - - - - - - -  
 */

/**
 * new_helloworld_user()
 * user object constructor.
 */
helloworld_user* new_helloworld_user() 
{
    helloworld_user* user = (helloworld_user*) new_object(sizeof(helloworld_user), 
        ETCHTYPEB_USER, get_dynamic_classid_unique(&CLASSID_HELLOWORLD_USER));
		
	((etch_object*)user)->destroy = destroy_helloworld_user;

    return user;
}





/**
 * clone_helloworld_user()
 * user object copy constructor.
 */
helloworld_user* clone_helloworld_user(helloworld_user* other) 
{
    helloworld_user* user = (helloworld_user*) new_object(sizeof(helloworld_user), 
        ETCHTYPEB_USER, get_dynamic_classid_unique(&CLASSID_HELLOWORLD_USER));
		
    user->id = other->id; 
    user->name = other->name; 

	((etch_object*)user)->destroy = destroy_helloworld_user;

    return user;
}


/**
 * is_helloworld_user()
 */
int is_helloworld_user(void* x) 
{
    return x && ((etch_object*)x)->class_id == CLASSID_HELLOWORLD_USER;
}

/**
 * new_helloworld_UserUnknownException()
 * userunknownexception object constructor.
 */
helloworld_UserUnknownException* new_helloworld_UserUnknownException() 
{

	helloworld_UserUnknownException* userunknownexception  = (helloworld_UserUnknownException*) new_object(sizeof(helloworld_UserUnknownException), 
        ETCHTYPEB_EXCEPTION, get_dynamic_classid_unique(&CLASSID_HELLOWORLD_USERUNKNOWNEXCEPTION));
    
    userunknownexception->message = new_stringw(L"user generated exception, no default exception message.");
    userunknownexception->errorcode = ETCH_ERROR;
    userunknownexception->excptype = EXCPTYPE_USERDEFINED;
        
		
	((etch_object*)userunknownexception)->destroy = destroy_helloworld_UserUnknownException;

    return userunknownexception;
}





/**
 * clone_helloworld_UserUnknownException()
 * userunknownexception object copy constructor.
 */
helloworld_UserUnknownException* clone_helloworld_UserUnknownException(helloworld_UserUnknownException* other) 
{
	helloworld_UserUnknownException* userunknownexception = (helloworld_UserUnknownException*) new_object(sizeof(helloworld_UserUnknownException), 
        ETCHTYPEB_EXCEPTION, get_dynamic_classid_unique(&CLASSID_HELLOWORLD_USERUNKNOWNEXCEPTION));
		
    userunknownexception->mes = other->mes; 

	((etch_object*)userunknownexception)->destroy = destroy_helloworld_UserUnknownException;

    return userunknownexception;
}


/**
 * is_helloworld_UserUnknownException()
 */
int is_helloworld_UserUnknownException(void* x) 
{
    return x && ((etch_object*)x)->class_id == CLASSID_HELLOWORLD_USERUNKNOWNEXCEPTION;
}


/**
 * new_helloworld_service_interface
 */
i_helloworld* new_helloworld_service_interface ()
{
    i_helloworld* isvc = (i_helloworld*) new_object (sizeof(i_helloworld), ETCHTYPEB_SVCINTERFACE, 
        get_dynamic_classid_unique(&CLASSID_HELLOWORLD_SERVICE_INTERFACE));

    ((etch_object*)isvc)->destroy = destroy_helloworld_service_interface;

    isvc->say_hello = helloworld_def_say_hello;

    isvc->user = new_helloworld_user();

    return isvc;
}

/**
 * destroy_helloworld_service_interface()
 * i_helloworld destructor.
 */
int destroy_helloworld_service_interface (void* data)
{
    i_helloworld* isvc = (i_helloworld*)data;
    if (NULL == isvc) return -1;  

    if (!is_etchobj_static_content(isvc))
    {    
        etch_object_destroy(isvc->user);
    }
    
    return destroy_objectex((etch_object*)isvc);
}


/* - - - - - - - - - - - - - -  
 * service method stubs
 * - - - - - - - - - - - - - -  
 */

etch_string* helloworld_def_say_hello(void* thisx, helloworld_user* to_whom)
{
    etch_free(to_whom);
    return NULL;
}
