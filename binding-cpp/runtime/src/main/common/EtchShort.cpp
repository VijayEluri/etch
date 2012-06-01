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

#include "common/EtchShort.h"

const EtchObjectType* EtchShort::TYPE() {
  const static EtchObjectType TYPE(EOTID_SHORT, NULL);
  return &TYPE;
}

EtchShort::EtchShort()
: EtchObject(EtchShort::TYPE())
, mValue(0){
}

EtchShort::EtchShort(capu::int16_t value)
: EtchObject(EtchShort::TYPE())
, mValue(value){
}

void EtchShort::set(capu::int16_t value){
  mValue = value;
}

capu::int16_t EtchShort::get(){
  return mValue;
}

capu::uint64_t EtchShort::getHashCode() const{
  //for better distribution
  capu::uint64_t result = (capu::uint64_t) ((capu::int64_t) mValue + 32768);
  return result;
}

capu::bool_t EtchShort::equals(const EtchObject * other) const{
  if (other == NULL)
    return false;
  else if (!other->getObjectType()->equals(EtchShort::TYPE()))
    return false;
  EtchShort * a = (EtchShort*) other;
  return (a->mValue == this->mValue);
}
