# Copyright (c) 2020 vesoft inc. All rights reserved.
#
# This source code is licensed under Apache 2.0 License,
# attached with Common Clause Condition 1.0, found in the LICENSES directory.

nebula_add_library(
    validator_obj OBJECT
    Validator.cpp
    AssignmentValidator.cpp
    ASTValidator.cpp
    GoValidator.cpp
    PipeValidator.cpp
    SequentialValidator.cpp
    SetValidator.cpp
    UseValidator.cpp
    GetSubgraphValidator.cpp
    AdminValidator.cpp
    BalanceValidator.cpp
    AdminJobValidator.cpp
    MaintainValidator.cpp
    MutateValidator.cpp
    ACLValidator.cpp
    FetchEdgesValidator.cpp
    FetchVerticesValidator.cpp
    LimitValidator.cpp
    OrderByValidator.cpp
    YieldValidator.cpp
    ExplainValidator.cpp
    GroupByValidator.cpp
)

nebula_add_subdirectory(test)
