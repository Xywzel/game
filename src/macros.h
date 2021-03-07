#pragma once
// This file defines macros used in this project
// Macros defined in other headers should be undefined by the end of the header

// Get number of arguments for other macros
#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL(__VA_ARGS__, 5,4,3,2,1)
#define VA_NUM_ARGS_IMPL(_1,_2,_3,_4,_5,N,...) N

// Forward declarations for classes in namespaces
#define DECLARE_1(name) class name;
#define DECLARE_2(space, ...) namespace space { DECLARE_1(__VA_ARGS__)}
#define DECLARE_3(space, ...) namespace space { DECLARE_2(__VA_ARGS__)}
#define DECLARE_4(space, ...) namespace space { DECLARE_3(__VA_ARGS__)}
#define DECLARE_5(space, ...) namespace space { DECLARE_4(__VA_ARGS__)}

#define DECLARE_INDI(N, ...) DECLARE_ ## N (__VA_ARGS__)
#define DECLARE_IMPL(N, ...) DECLARE_INDI(N, __VA_ARGS__)
#define DECLARE(...) DECLARE_IMPL(VA_NUM_ARGS(__VA_ARGS__), __VA_ARGS__)

// Forward declaration for structs in namespaces
#define DECLARE_STRUCT_1(name) struct name;
#define DECLARE_STRUCT_2(space, ...) namespace space { DECLARE_STRUCT_1(__VA_ARGS__)}
#define DECLARE_STRUCT_3(space, ...) namespace space { DECLARE_STRUCT_2(__VA_ARGS__)}
#define DECLARE_STRUCT_4(space, ...) namespace space { DECLARE_STRUCT_3(__VA_ARGS__)}
#define DECLARE_STRUCT_5(space, ...) namespace space { DECLARE_STRUCT_4(__VA_ARGS__)}

#define DECLARE_STRUCT_INDI(N, ...) DECLARE_STRUCT_ ## N (__VA_ARGS__)
#define DECLARE_STRUCT_IMPL(N, ...) DECLARE_STRUCT_INDI(N, __VA_ARGS__)
#define DECLARE_STRUCT(...) DECLARE_STRUCT_IMPL(VA_NUM_ARGS(__VA_ARGS__), __VA_ARGS__)
