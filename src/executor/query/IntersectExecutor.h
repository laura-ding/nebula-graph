/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#ifndef EXECUTOR_QUERY_INTERSECTEXECUTOR_H_
#define EXECUTOR_QUERY_INTERSECTEXECUTOR_H_

#include "executor/query/SetExecutor.h"

namespace nebula {
namespace graph {

class IntersectExecutor : public SetExecutor {
public:
    IntersectExecutor(const PlanNode *node, QueryContext *qctx)
        : SetExecutor("IntersectExecutor", node, qctx) {}

    folly::Future<Status> execute() override;
};

}   // namespace graph
}   // namespace nebula

#endif   // EXECUTOR_QUERY_INTERSECTEXECUTOR_H_
