
#ifndef KPORT_COMPILER_H_
#define KPORT_COMPILER_H_

#ifndef KPT_COMPILER_HAS_FEATURE
    #if defined(__clang__)
        #define KPT_COMPILER_HAS_FEATURE(x) __has_feature(x)
    #else
        #define KPT_COMPILER_HAS_FEATURE(x) 0
    #endif
#endif

#ifndef KPT_COMPILER_HAS_BUILDIN
    #if defined(__clang__)
        #define KPT_COMPILER_HAS_BUILDIN(x) __buildin(x)
    #else
        #define KPT_COMPILER_HAS_BUILDIN(x) 0
    #endif
#endif

#if !defined(KPT_COMPILER_CPP11_ENABLED) && defined(__cplusplus)
    #if (__cplusplus >= 201103L)
        #define KPT_COMPILER_CPP11_ENABLED 1
    #elif (__GNUC__) && defined(__GXX_EXPERIMENTAL_CXX0X__)
        #define KPT_COMPILER_CPP11_ENABLED 1
    #else
        #define KPT_COMPILER_CPP11_ENABLED 0
    #endif
#endif

#if !defined(KPT_COMPILER_CPP14_ENABLED) && defined(__cplusplus)
    #if (__cplusplus >= 201402L)
        #define KPT_COMPILER_CPP14_ENABLED 1
    #else
        #define KPT_COMPILER_CPP14_ENABLED 0
    #endif
#endif

#if !defined(KPT_COMPILER_CPP17_ENABLED) && defined(__cplusplus)
    #if (__cplusplus >= 201703L)
        #define KPT_COMPILER_CPP17_ENABLED 1
    #else
        #define KPT_COMPILER_CPP17_ENABLED 0
    #endif
#endif

#if defined(__clang__)
    #define KPT_COMPILER_CLANG 1
    #define KPT_COMPILER_VERSION (__clang_major__ * 100 + __clang_minor__)
    #define KPT_COMPILER_NAME "clang"
#elif defined(__GNUC__)
    #define KPT_COMPILER_GNUC 1
    #define KPT_COMPILER_VERSION (__GNUC__ * 1000 + __GNUC_MINOR__)
    #define KPT_COMPILER_NAME "gnuc"
#else
    #error "unkown compiler"
#endif


#endif //KPORT_COMPILER_H_
