/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#include "validator/OrderByValidator.h"
#include "parser/TraverseSentences.h"
#include "planner/Query.h"

namespace nebula {
namespace graph {
Status OrderByValidator::validateImpl() {
    auto sentence = static_cast<OrderBySentence*>(sentence_);
    outputs_ = inputCols();
    auto factors = sentence->factors();
    for (auto &factor : factors) {
        if (factor->expr()->kind() != Expression::Kind::kInputProperty) {
            return Status::SemanticError("Order by with invalid expression `%s'",
                                          factor->expr()->toString().c_str());
        }
        auto expr = static_cast<InputPropertyExpression*>(factor->expr());
        auto *name = expr->prop();
        NG_RETURN_IF_ERROR(checkPropNonexistOrDuplicate(outputs_, *name, "Order by"));
        colOrderTypes_.emplace_back(std::make_pair(*name, factor->orderType()));
    }

    return Status::OK();
}

Status OrderByValidator::toPlan() {
    auto* plan = qctx_->plan();
    auto *sortNode = Sort::make(plan, plan->root(), std::move(colOrderTypes_));
    std::vector<std::string> colNames;
    for (auto &col : outputs_) {
        colNames.emplace_back(col.first);
    }
    sortNode->setColNames(std::move(colNames));
    root_ = sortNode;
    tail_ = root_;
    return Status::OK();
}
}  // namespace graph
}  // namespace nebula
