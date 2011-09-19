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

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


namespace capu
{
   #ifdef _WIN32
    typedef char int8_t;
    typedef short int16_t;
    typedef int int32_t;
    typedef signed __int64 int64_t;
    typedef unsigned int uint32_t;
    #else //other OS should be C99 compliant
    typedef signed char int8_t;
    typedef short int int16_t;
    typedef int int32_t;
    typedef long long int int64_t;
    typedef unsigned long int uint32_t;
    #endif //_WIN32 
}

#endif