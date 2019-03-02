
#ifndef KPORT_ALIGN_H_
#define KPORT_ALIGN_H_
#include <kport/compiler.h>
#include <kport/compiler_functionality.h>

#ifndef KPT_COMPILER_NO_ALIGNED_NEW
    #if KPT_COMPILER_CPP17_ENABLED
        #define KPT_COMPILER_NO_ALIGNED_NEW 0
    #else
        #define KPT_COMPILER_NO_ALIGNED_NEW 1
    #endif
#endif

#ifndef KPT_OFFSETOF
    #if defined(KPT_COMPILER_GNUC)
        #define KPT_OFFSETOF(struct_, member_) ((size_t)(((uintptr_t)&reinterpret_cast<const volatile char&>((((struct_*)65536)->member_))) - 65536))
    #else
        #define KPT_OFFSETOF(struct_, member_) offsetof(struct_, member_)
    #endif
#endif

#ifndef KPT_SIZEOF_MEMBER
    #if KPT_COMPILER_NO_EXTENDED_SIZEOF
        #define KPT_SIZEOF_MEMBER(struct_, member_) (sizeof(((struct_*)0)->member_))
    #else
        #define KPT_SIZEOF_MEMBER(struct_, member_) (sizeof(struct_::member_))
    #endif
#endif

#ifndef KPT_ALIGN_OF
    #if (defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION > 4003) || defined(KPT_COMPILER_CLANG)
        #define KPT_ALIGN_OF(type) ((size_t)__alignof__(type))
        #define KPT_ALIGN(n)
        #define KPT_PREFIX_ALIGN(n)
        #define KPT_POSTFIX_ALIGN(n) __attribute__((aligned(n)))
        #define KPT_ALIGNED(variable_type, variable, n) variable_type variable __attribute__((aligned(n)))
        #define KPT_PACKED  __attribute__((packed))
    #else
        #define KPT_ALIGN(n)
        #define KPT_PREFIX_ALIGN(n)
        #define KPT_POSTFIX_ALIGN(n)
        #define KPT_ALIGNED(variable_type, variable, n) variable_type variable
        #define KPT_PACKED
    #endif

#endif

#endif //KPORT_ALIGN_H_
