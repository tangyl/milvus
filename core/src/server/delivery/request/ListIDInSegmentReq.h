// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

#include "server/delivery/request/BaseReq.h"

#include <memory>
#include <string>
#include <vector>

namespace milvus {
namespace server {

class ListIDInSegmentReq : public BaseReq {
 public:
    static BaseReqPtr
    Create(const std::shared_ptr<milvus::server::Context>& context, const std::string& collection_name,
           int64_t segment_id, engine::IDNumbers& ids);

 protected:
    ListIDInSegmentReq(const std::shared_ptr<milvus::server::Context>& context, const std::string& collection_name,
                       int64_t segment_id, engine::IDNumbers& ids);

    Status
    OnExecute() override;

 private:
    std::string collection_name_;
    int64_t segment_id_;
    engine::IDNumbers& ids_;
};

}  // namespace server
}  // namespace milvus
