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

#ifndef __ETCHTAGGEDDATAINPUT_H__
#define	__ETCHTAGGEDDATAINPUT_H__
#include "transport/EtchFlexBuffer.h"
#include "transport/EtchMessage.h"
#include "capu/util/SmartPointer.h"

class EtchTaggedDataInput {
public:

  /**
   * Reads a message from the buf.
   * @param buf the flex buffer containing the message.
   * @param a message read from the buf.
   */
  virtual status_t readMessage(capu::SmartPointer<EtchFlexBuffer> buf, capu::SmartPointer<EtchMessage> &message) = 0;

  virtual ~EtchTaggedDataInput() {

  }

};

#endif /* ETCHTAGGEDDATAINPUT_H */
