/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ART_SRC_INTERPRETER_INTERPRETER_H_
#define ART_SRC_INTERPRETER_INTERPRETER_H_

#include "locks.h"

namespace art {

class AbstractMethod;
union JValue;
class Object;
class ShadowFrame;
class Thread;

namespace interpreter {

extern void EnterInterpreterFromInvoke(Thread* self, AbstractMethod* method, Object* receiver,
                                       JValue* args, JValue* result)
    SHARED_LOCKS_REQUIRED(Locks::mutator_lock_);

extern JValue EnterInterpreterFromDeoptimize(Thread* self, ShadowFrame& shadow_frame,
                                             JValue ret_val)
    SHARED_LOCKS_REQUIRED(Locks::mutator_lock_);

}  // namespace interpreter
}  // namespace art

#endif  // ART_SRC_INTERPRETER_INTERPRETER_H_
