
#ifndef KPORT_COMPILER_CHAR_H_
#define KPORT_COMPILER_CHAR_H_

#include <kob/profile/platform.h>
#include <kob/profile/compiler.h>
#include <kob/profile/compiler_functionality.h>

#ifndef KPT_WCHAR_T_NON_NATIVE
    #define KPT_WCHAR_T_NON_NATIVE 0
#endif

#ifndef KPT_WCHAR_MAX
    #if defined(__WCHAR_MAX__)
        #if (__WCHAR_MAX__ == 2147483647) || (__WCHAR_MAX__ == 4294967295)
            #define KPT_WCHAR_MAX 4
        #elif (__WCHAR_MAX__ == 32767) || (__WCHAR_MAX__ == 65535)
            #define KPT_WCHAR_MAX 2
        #elif (__WCHAR_MAX__ == 127) || (__WCHAR_MAX__ == 255)
            #define KPT_WCHAR_MAX 1
        #else
            #define KPT_WCHAR_MAX 4
        #endif
    #elif defined(KPT_PLATEFORM_UNIX)
        #define KPT_WCHAR_MAX 4
    #else
        #define KPT_WCHAR_MAX 2
    #endif
#endif

#ifdef KPT_PLATFORM_OSX
    #define char8_t char
#else
    typedef char char8_t;
#endif

#ifndef KPT_CHAR16_NATIVE
    #if defined(KPT_COMPILER_CLANG) && KPT_COMPILER_CPP11_ENABLED
        #define KPT_CHAR16_NATIVE 1
        #define KPT_CHAR32_NATIVE 1
    #elif defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION > 4004
        #define KPT_CHAR16_NATIVE 1
        #define KPT_CHAR32_NATIVE 1
    #else
        #define KPT_CHAR16_NATIVE 0
        #define KPT_CHAR32_NATIVE 0
    #endif
#endif

#if KPT_CHAR16_NATIVE && KPT_CHAR32_NATIVE
    #define KPT_WCHAR_UNIQUE 1
#else
    #define KPT_WCHAR_UNIQUE 0
#endif

#endif //KPORT_COMPILER_CHAR_H_
