#!/bin/sh
NUM_EXPECTED_ARGS=1

PROGRAM=`basename $0`

if [ $# -lt $NUM_EXPECTED_ARGS ]; then
	echo "usage: $PROGRAM <SCRIPT> [args..]";
	echo "example: $PROGRAM hello.k arg0 arg1"
	exit 1;
fi

FILE=$1

export LLVM_OS_ARCH="dylib"
#export LLVM_OS_ARCH="so"
#export LLVM_DEBUG=true
#export LLVM_ENABLE_VERIFY_EACH=true
#export LLVM_ENABLE_PRINT_STATICS=true
#export LLVM_ENABLE_MODULE_DUMP=true
export LLVM_ENABLE_OPT=true
export LLVM_ENABLE_OPT_METHOD_INLINING=false
export LLVM_ENABLE_OPT_INTRINSIC_METHOD=true
export LLVM_ENABLE_OPT_LOAD_LIBRARY_MODULE=false
export LLVM_ENABLE_OPT_SAFEPOINT=true
export LLVM_ENABLE_OPT_ARRAY_ACCESS=true
export LLVM_ENABLE_OPT_OBJECT_NEW=true
export LLVM_ENABLE_OPT_FIELD_ACCESS=true
#export LLVM_ENABLE_OPT_LAZY_COMPILATION=true
export LLVM_ENABLE_OPT_REMOVE_SFP=true
if [ "$LLVM_DEBUG" = "true" ]; then
/usr/bin/gdb -arg `which konohac` --emit-llvm --run $FILE
else
`which konohac` --emit-llvm --run $FILE
fi
