
#ifndef KPORT_OPTIMIZATION_H_
#define KPORT_OPTIMIZATION_H_
#include <kport/compiler.h>
#include <kport/compiler_warning.h>

#ifndef KPT_LIKELY
    #if defined(KPT_COMPILER_GNUC)
        #if defined(__cplusplus)
            #define KPT_LIKELY(x) __builtin_expect(!!(x), true)
            #define KPT_UNLIKELY(x) __builtin_expect(!!(x), false)
        #else
            #define KPT_LIKELY(x) __builtin_expect(!!(x), 1)
            #define KPT_UNLIKELY(x) __builtin_expect(!!(x), 0)
        #endif
    #else
        #define KPT_LIKELY(x) (x)
        #define KPT_UNLIKELY(x) (x)
    #endif
#endif

#ifndef KPT_RESTRICT
    #if defined(KPT_COMPILER_GNUC)
        #define KPT_RESTRICT __restrict
    #elif defined(KPT_COMPILER_CLANG)
        #define KPT_RESTRICT __restrict
    #else
        #define KPT_RESTRICT
    #endif
#endif

#ifndef KPT_DEPRECATED
    #if KPT_COMPILER_CPP14_ENABLED
        #define KPT_DEPRECATED [[deprecated]]
    #elif defined(KPT_COMPILER_GNUC) || defined(KPT_COMPILER_CLANG)
        #define KPT_DEPRECATED __attribute__((deprecated))
    #else
        #define KPT_DEPRECATED
    #endif
#endif

#ifndef KPT_DEPRECATED_MSG
#if KPT_COMPILER_CPP14_ENABLED
        #define KPT_DEPRECATED_MSG(m) [[deprecated(#m)]]
    #else
        #define KPT_DEPRECATED_MSG(m)
    #endif
#endif

#ifndef KPT_FORCE_INLINE
    #if (defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >=3001) || defined(KPT_COMPILER_CLANG)
        #if defined(__cplusplus)
            #define KPT_FORCE_INLINE inline __attribute__((always_inline))
        #else
            #define KPT_FORCE_INLINE __inline__ __attribute__((always_inline))
        #endif
    #else
        #if defined(_cplusplus)
            #define KPT_FORCE_INLINE inline
        #else
            #define #define KPT_FORCE_INLINE __inline
        #endif
    #endif
#endif

#ifndef KPT_NO_INLINE
    #if defined(KPT_COMPILER_GNUC) || defined(KPT_COMPILER_CLANG)
        #define KPT_NO_INLINE __atttribute__((noinline))
    #else
        #define KPT_NO_INLINE
    #endif
#endif

#ifndef KPT_OPTIMIZE_OFF
    #if defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION > 4004) && (defined(__i386__) || defined(__x86_64__))
        #define KPT_OPTIMIZE_OFF()            \
				_Pragma("GCC push_options")      \
				_Pragma("GCC optimize 0")
    #elif defined(KPT_COMPILER_CLANG) && (EA_COMPILER_VERSION >= 380)
            #define EA_OPTIMIZE_OFF() \
            KPT_DISABLE_CLANG_WARNING(-Wunknown-pragmas) \
            _Pragma("clang optimize off") \
			KPT_RESTORE_CLANG_WARNING()
    #else
        #define KPT_OPTIMIZE_OFF()
    #endif
#endif

#ifndef KPT_OPTIMIZE_ON
    #if defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION > 4004) && (defined(__i386__) || defined(__x86_64__))
        #define KPT_OPTIMIZE_ON()  _Pragma("GCC pop_options")
    #elif defined(KPT_COMPILER_CLANG) && (EA_COMPILER_VERSION >= 380)
        #define KPT_OPTIMIZE_ON() \
            KPT_DISABLE_CLANG_WARNING(-Wunknown-pragmas) \
            _Pragma("clang optimize on") \
            KPT_RESTORE_CLANG_WARNING()
    #else
        #define KPT_OPTIMIZE_ON()
    #endif
#endif

#endif //KPORT_OPTIMIZATION_H_
