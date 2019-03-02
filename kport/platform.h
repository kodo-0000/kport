
#ifndef KPORT_PLATFORM_H_
#define KPORT_PLATFORM_H_


#if defined(__linux) || defined(__linux__)
    #define KPT_PLATFORM_LINUX 1
    #define KPT_PLATFORM_UNIX 1
    #define KPT_PLATFORM_POSIX 1
    #define KPT_PLATFORM_NAME "linux"
#elif defined(__MINGW64__) || defined(__MINGW32__)
    #define KPT_PLATFORM_MINGW 1
    #define KPT_PLATFORM_UNIX 1
    #define KPT_PLATFORM_POSIX 1
    #define KPT_PLATFORM_NAME "mingw"
#elif defined(__APPLE__) && __APPLE__
    #include <TargetConditionals.h>
    #define KPT_PLATFORM_UNIX 1
    #define KPT_PLATFORM_POSIX 1
    #if defined(__MACH__) || (defined(__MSL__) && (__dest_os == __mac_osx))
        #define KPT_PLATFORM_OSX 1
        #define KPT_PLATFORM_NAME "osx"
    #else
        #error "unknown apple PLATFORM"
    #endif
#else
    #error "unkown PLATFORM"
#endif

#if defined(__x86_64__)
    #define KPT_PROCESSOR_X86_64 1
    #define KPT_PROCESSOR_DES "x86_64"
    #define KPT_SYSTEM_LITTLE_ENDIAN 1
#elif defined(__i386__)
    #define KPT_PROCESSOR_X86 1
    #define KPT_PROCESSOR_DES "x86"
    #define KPT_SYSTEM_LITTLE_ENDIAN 1
#else
    #error "only x86 PLATFORM"
#endif


#endif //KPORT_PLATFORM_H_
