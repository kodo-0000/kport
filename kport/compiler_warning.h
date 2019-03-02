
#ifndef KPORT_COMPILER_WARNING_H_
#define KPORT_COMPILER_WARNING_H_

#include <kport/compiler.h>

#ifndef KPT_DISABLE_GCC_WARNING
    #if defined(KPT_COMPILER_GNUC)
        #define KPT_GCC_HELP0(x) #x
        #define KPT_GCC_HELP1(x) KPT_GCC_HELP0(GCC diagnostic ignored x)
        #define KPT_GCC_HELP(x) KPT_GCC_HELP1(#x)
    #endif

    #if defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4006)
        #define KPT_DISABLE_GCC_WARNING(w) \
            _Pragma("GCC diagnostic push")  \
            _Pragma(KPT_GCC_HELP(w))
    #elif defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4004)
        #define KPT_DISABLE_GCC_WARNING(w) \
            _Pragma(KPT_GCC_HELP(w))
    #else
        #define KPT_DISABLE_GCC_WARNING(w)
    #endif
#endif

#ifndef KPT_RESTORE_GCC_WARNING
    #if defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4006)
        #define KPT_RESTORE_GCC_WARNING() \
            _Pragma("GCC diagnostic pop")
    #else
        #define KPT_RESTORE_GCC_WARNING()
    #endif
#endif

#ifndef KPT_DISABLE_CLANG_WARNING
    #if defined(KPT_COMPILER_CLANG)
        #define KPT_CLANG_HELP0(x) #x
        #define KPT_CLANG_HELP1(x) KPT_CLANG_HELP0(clang diagnostic ignored x)
        #define KPT_CLANG_HELP(x) KPT_CLANG_HELP1(#x)

        #define KPT_DISABLE_CLANG_WARNING(w) \
            _Pragma("clang diagnostic push")  \
            _Pragma(KPT_CLANG_HELP(w))
    #else
        #define KPT_DISABLE_CLANG_WARNING(w)
    #endif
#endif

#ifndef KPT_RESTORE_CLANG_WARNING
    #if defined(KPT_COMPILER_CLANG)
        #define KPT_RESTORE_CLANG_WARNING() \
            _Pragma("clang diagnostic pop")
    #else
        #define KPT_RESTORE_CLANG_WARNING()
    #endif
#endif

#ifndef KPT_DISABLE_WARNING
    #if defined(KPT_COMPILER_GNUC)
        #define KPT_DISABLE_WARNING(w) KPT_DISABLE_GCC_WARNING(w)
    #elif defined(KPT_COMPILER_CLANG)
        #define KPT_DISABLE_WARNING(w) KPT_DISABLE_CLANG_WARNING(w)
    #else
        #define KPT_DISABLE_WARNING(w)
    #endif
#endif

#ifndef KPT_RESTORE_WARNING
    #if defined(KPT_COMPILER_GNUC)
        #define KPT_RESTORE_WARNING() KPT_RESTORE_GCC_WARNING()
    #elif defined(KPT_COMPILER_CLANG)
        #define KPT_RESTORE_WARNING() KPT_RESTORE_CLANG_WARNING()
    #else
        #define KPT_RESTORE_WARNING()
    #endif
#endif


#endif //KPORT_COMPILER_WARNING_H_
