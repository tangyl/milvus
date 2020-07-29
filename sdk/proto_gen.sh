#!/bin/bash

protoc --proto_path=../core/src/grpc/ --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` --grpc_out=grpc-gen/gen-status/ --cpp_out=grpc-gen/gen-status/ status.proto

protoc --proto_path=../core/src/grpc/ --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` --grpc_out=grpc-gen/gen-milvus/ --cpp_out=grpc-gen/gen-milvus/ milvus.proto
