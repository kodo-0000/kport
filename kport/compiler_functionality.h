

#ifndef KPORT_COMPILER_FUNCTIONALITY_H_
#define KPORT_COMPILER_FUNCTIONALITY_H_
#include <kport/compiler.h>

#ifndef KPT_COMPILER_NO_RTII
    #define KPT_COMPILER_NO_RTII 0
#endif

#ifndef KPT_COMPILER_NO_EXCEPTIONS
    #if (defined(KPT_COMPILER_GNUC) || defined(KPT_COMPILER_CLANG)) && !defined(__EXCEPTIONS)
        #define KPT_COMPILER_NO_EXCEPTIONS 0
    #else
        #define KPT_COMPILER_NO_EXCEPTIONS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_UNWIND
    #define KPT_COMPILER_NO_UNWIND 0
#endif

#ifndef KPT_COMPILER_NO_RVALUE_REFERENCES
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4005
        #define KPT_COMPILER_NO_RVALUE_REFERENCES 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && (KPT_COMPILER_HAS_FEATURE(cxx_rvalue_references))
        #define KPT_COMPILER_NO_RVALUE_REFERENCES 0
    #else
        #define KPT_COMPILER_NO_RVALUE_REFERENCES 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_EXTERN_TEMPALTE
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4006
        #define KPT_COMPILER_NO_EXTERN_TEMPALTE 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && defined(__apple_build_version__) && KPT_COMPILER_VERSION >= 401
        #define KPT_COMPILER_NO_EXTERN_TEMPALTE 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_EXTERN_TEMPALTE 0
    #else
        #define KPT_COMPILER_NO_EXTERN_TEMPALTE 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_BASED_FOR_LOOP
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4006
        #define KPT_COMPILER_NO_BASED_FOR_LOOP 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 300
        #define KPT_COMPILER_NO_BASED_FOR_LOOP 0
    #else
         #define KPT_COMPILER_NO_BASED_FOR_LOOP 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_CONSTEXPR
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4006
        #define KPT_COMPILER_NO_CONSTEXPR 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_HAS_FEATURE(cxx_constexpr)
        #define KPT_COMPILER_NO_CONSTEXPR 0
    #else
        #define KPT_COMPILER_NO_CONSTEXPR 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_OVERRIDE
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4007
        #define KPT_COMPILER_NO_OVERRIDE 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 209
        #define KPT_COMPILER_NO_OVERRIDE 0
    #else
        #define KPT_COMPILER_NO_OVERRIDE 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_INHERITANCE_FINAL
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4007
        #define KPT_COMPILER_NO_INHERITANCE_FINAL 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 209
        #define KPT_COMPILER_NO_INHERITANCE_FINAL 0
    #else
        #define KPT_COMPILER_NO_INHERITANCE_FINAL 1
    #endif

#endif

#ifndef KPT_COMPILER_NO_AUTO
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4004
        #define KPT_COMPILER_NO_AUTO 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 209
        #define KPT_COMPILER_NO_AUTO 0
    #else
        #define KPT_COMPILER_NO_AUTO 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_NULLPTR
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4006
        #define KPT_COMPILER_NO_NULLPTR 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG)
        #define KPT_COMPILER_NO_NULLPTR 0
    #else
        #define KPT_COMPILER_NO_NULLPTR 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_DECLTYPE
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4003
        #define KPT_COMPILER_NO_DECLTYPE 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 209
        #define KPT_COMPILER_NO_DECLTYPE 0
    #else
        #define KPT_COMPILER_NO_DECLTYPE 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_DEFAULTED_FUNCTIONS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4004
        #define KPT_COMPILER_NO_DEFAULTED_FUNCTIONS 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 300
        #define KPT_COMPILER_NO_DEFAULTED_FUNCTIONS 0
    #else
        #define KPT_COMPILER_NO_DEFAULTED_FUNCTIONS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_DELETED_FUNCTIONS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4004
        #define KPT_COMPILER_NO_DELETED_FUNCTIONS 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 300
        #define KPT_COMPILER_NO_DELETED_FUNCTIONS 0
    #else
        #define KPT_COMPILER_NO_DELETED_FUNCTIONS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_LAMBDA_EXPRESSION
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4004
        #define KPT_COMPILER_NO_LAMBDA_EXPRESSION 1
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_LAMBDA_EXPRESSION 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 301 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_LAMBDA_EXPRESSION 0
    #else
        #define KPT_COMPILER_NO_LAMBDA_EXPRESSION 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_TRAILING_RETURN_TYPES
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4004
        #define KPT_COMPILER_NO_TRAILING_RETURN_TYPES 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_TRAILING_RETURN_TYPES 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 301 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_TRAILING_RETURN_TYPES 0
    #else
        #define KPT_COMPILER_NO_TRAILING_RETURN_TYPES 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_STRONGLY_TYPED_ENUMS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4004
        #define KPT_COMPILER_NO_STRONGLY_TYPED_ENUMS 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 209
        #define KPT_COMPILER_NO_STRONGLY_TYPED_ENUMS 0
    #else
        #define KPT_COMPILER_NO_STRONGLY_TYPED_ENUMS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_FORWARD_DECLARED_ENUMS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4006
        #define KPT_COMPILER_NO_FORWARD_DECLARED_ENUMS 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_FORWARD_DECLARED_ENUMS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 301 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_FORWARD_DECLARED_ENUMS 0
    #else
        #define KPT_COMPILER_NO_FORWARD_DECLARED_ENUMS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_VARIADIC_TEMPLATES
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4004
        #define KPT_COMPILER_NO_VARIADIC_TEMPLATES 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 209
        #define KPT_COMPILER_NO_VARIADIC_TEMPLATES 0
    #else
        #define KPT_COMPILER_NO_VARIADIC_TEMPLATES 1
    #endif
#endif

#ifndef  KPT_COMPILER_NO_TEMPLATE_ALIASES
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 4007
        #define KPT_COMPILER_NO_TEMPLATE_ALIASES 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_TEMPLATE_ALIASES 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 301 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_TEMPLATE_ALIASES 0
    #else
        #define KPT_COMPILER_NO_TEMPLATE_ALIASES 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_VARIABLE_TEMPLATES
    #if  KPT_COMPILER_CPP14_ENABLED &&  defined(KPT_COMPILER_CLANG) && (KPT_COMPILER_VERSION >= 304) && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_VARIABLE_TEMPLATES 0
    #elif KPT_COMPILER_CPP14_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 5000)
        #define KPT_COMPILER_NO_VARIABLE_TEMPLATES 0
    #else
        #define KPT_COMPILER_NO_VARIABLE_TEMPLATES 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_INLINE_VARIABLE
    #if KPT_COMPILER_CPP17_ENABLED
        #define KPT_COMPILER_NO_INLINE_VARIABLE 0
    #else
        #define KPT_COMPILER_NO_INLINE_VARIABLE 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_NORETURN
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4008)
        #define KPT_COMPILER_NO_NORETURN 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_NORETURN 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 301 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_NORETURN 0
    #else
        #define KPT_COMPILER_NO_NORETURN 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_MAYBE_UNUSED
    #if KPT_COMPILER_CPP17_ENABLED
        #define KPT_COMPILER_NO_MAYBE_UNUSED 0
    #else
        #define KPT_COMPILER_NO_MAYBE_UNUSED 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_NODISCARD
    #if KPT_COMPILER_CPP17_ENABLED
        #define KPT_COMPILER_NO_NODISCARD 0
    #else
        #define KPT_COMPILER_NO_NODISCARD 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_FALLTHROUGH
    #if KPT_COMPILER_CPP17_ENABLED
        #define KPT_COMPILER_NO_FALLTHROUGH 0
    #else
        #define KPT_COMPILER_NO_FALLTHROUGH 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_NONSTATIC_MEMBER_INITIALIZERS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4007)
        #define KPT_COMPILER_NO_NONSTATIC_MEMBER_INITIALIZERS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_NONSTATIC_MEMBER_INITIALIZERS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 301 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_NONSTATIC_MEMBER_INITIALIZERS 0
    #else
        #define KPT_COMPILER_NO_NONSTATIC_MEMBER_INITIALIZERS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_RIGHT_ANGLE_BRACKETS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4003)
        #define KPT_COMPILER_NO_RIGHT_ANGLE_BRACKETS 0
    #elif KPT_COMPILER_CPP11_ENABLED &&  defined(KPT_COMPILER_CLANG) && (KPT_COMPILER_VERSION >= 304)
        #define KPT_COMPILER_NO_RIGHT_ANGLE_BRACKETS 0
    #else
        #define KPT_COMPILER_NO_RIGHT_ANGLE_BRACKETS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_ALIGNOF
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4005)
        #define KPT_COMPILER_NO_ALIGNOF 0
    #elif KPT_COMPILER_CPP11_ENABLED &&  defined(KPT_COMPILER_CLANG) && (KPT_COMPILER_VERSION >= 209)
        #define KPT_COMPILER_NO_ALIGNOF 0
    #else
        #define KPT_COMPILER_NO_ALIGNOF 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_ALIGNAS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4008)
        #define KPT_COMPILER_NO_ALIGNAS 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_ALIGNAS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 300 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_ALIGNAS 0
    #else
        #define KPT_COMPILER_NO_ALIGNAS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_DELEGATING_CONSTRUCTORS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4007)
        #define KPT_COMPILER_NO_DELEGATING_CONSTRUCTORS 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_DELEGATING_CONSTRUCTORS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 300 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_DELEGATING_CONSTRUCTORS 0
    #else
        #define KPT_COMPILER_NO_DELEGATING_CONSTRUCTORS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_INHERITING_CONSTRUCTORS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4008)
        #define KPT_COMPILER_NO_INHERITING_CONSTRUCTORS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_HAS_FEATURE(cxx_inheriting_constructors)
        #define KPT_COMPILER_NO_INHERITING_CONSTRUCTORS 0
    #else
        #define KPT_COMPILER_NO_INHERITING_CONSTRUCTORS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_USER_DEFINED_LITERALS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4007)
        #define KPT_COMPILER_NO_USER_DEFINED_LITERALS 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_USER_DEFINED_LITERALS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 301 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_USER_DEFINED_LITERALS 0
    #else
        #define KPT_COMPILER_NO_USER_DEFINED_LITERALS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_STANDARD_LAYOUT_TYPES
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4005)
        #define KPT_COMPILER_NO_STANDARD_LAYOUT_TYPES 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_STANDARD_LAYOUT_TYPES 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 300 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_STANDARD_LAYOUT_TYPES 0
    #else
        #define KPT_COMPILER_NO_STANDARD_LAYOUT_TYPES 1
    #endif
#endif


#ifndef KPT_COMPILER_NO_EXTENDED_SIZEOF
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4005)
        #define KPT_COMPILER_NO_EXTENDED_SIZEOF 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_EXTENDED_SIZEOF 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 301 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_EXTENDED_SIZEOF 0
    #else
        #define KPT_COMPILER_NO_EXTENDED_SIZEOF 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_INLINE_NAMESPACES
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4004)
        #define KPT_COMPILER_NO_INLINE_NAMESPACES 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 209
        #define KPT_COMPILER_NO_INLINE_NAMESPACES 0
    #else
        #define KPT_COMPILER_NO_INLINE_NAMESPACES 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_UNRESTRICTED_UNIONS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4006)
        #define KPT_COMPILER_NO_UNRESTRICTED_UNIONS 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_UNRESTRICTED_UNIONS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 301 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_UNRESTRICTED_UNIONS 0
    #else
        #define KPT_COMPILER_NO_UNRESTRICTED_UNIONS 1
    #endif
#endif


#ifndef KPT_COMPILER_NO_EXPLICIT_CONVERSION_OPERATORS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4005)
        #define KPT_COMPILER_NO_EXPLICIT_CONVERSION_OPERATORS 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_EXPLICIT_CONVERSION_OPERATORS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 300 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_EXPLICIT_CONVERSION_OPERATORS 0
    #else
        #define KPT_COMPILER_NO_EXPLICIT_CONVERSION_OPERATORS 1
    #endif
#endif


#ifndef KPT_COMPILER_NO_FUNCTION_TEMPLATE_DEFAULT_ARGS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4003)
        #define KPT_COMPILER_NO_FUNCTION_TEMPLATE_DEFAULT_ARGS 0
    #elif KPT_COMPILER_CPP11_ENABLED &&  defined(KPT_COMPILER_CLANG) && (KPT_COMPILER_VERSION >= 209)
        #define KPT_COMPILER_NO_FUNCTION_TEMPLATE_DEFAULT_ARGS 0
    #else
        #define KPT_COMPILER_NO_FUNCTION_TEMPLATE_DEFAULT_ARGS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_LOCAL_CLASS_TEMPLATE_PARAMETERS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4005)
        #define KPT_COMPILER_NO_LOCAL_CLASS_TEMPLATE_PARAMETERS 0
    #elif KPT_COMPILER_CPP11_ENABLED &&  defined(KPT_COMPILER_CLANG) && (KPT_COMPILER_VERSION >= 209)
        #define KPT_COMPILER_NO_LOCAL_CLASS_TEMPLATE_PARAMETERS 0
    #else
        #define KPT_COMPILER_NO_LOCAL_CLASS_TEMPLATE_PARAMETERS 1
    #endif
#endif


#ifndef KPT_COMPILER_NO_NOEXCEPT
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4006)
        #define KPT_COMPILER_NO_NOEXCEPT 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_NOEXCEPT 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 300 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_NOEXCEPT 0
    #else
        #define KPT_COMPILER_NO_NOEXCEPT 1
    #endif
#endif


#ifndef KPT_COMPILER_NO_RAW_LITERALS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4005)
        #define KPT_COMPILER_NO_RAW_LITERALS 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_RAW_LITERALS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 300 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_RAW_LITERALS 0
    #else
        #define KPT_COMPILER_NO_RAW_LITERALS 1
    #endif
#endif


#ifndef KPT_COMPILER_NO_UNICODE_STRING_LITERALS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4004)
        #define KPT_COMPILER_NO_UNICODE_STRING_LITERALS 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_UNICODE_STRING_LITERALS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 300 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_UNICODE_STRING_LITERALS 0
    #else
        #define KPT_COMPILER_NO_UNICODE_STRING_LITERALS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_NEW_CHARACTER_TYPES
    #if KPT_COMPILER_NO_UNICODE_STRING_LITERALS
        #define KPT_COMPILER_NO_NEW_CHARACTER_TYPES 1
    #else
        #define KPT_COMPILER_NO_NEW_CHARACTER_TYPES 0
    #endif
#endif

#ifndef KPT_COMPILER_NO_UNICODE_CHAR_NAME_LITERALS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4005)
        #define KPT_COMPILER_NO_UNICODE_CHAR_NAME_LITERALS 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_UNICODE_CHAR_NAME_LITERALS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 301 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_UNICODE_CHAR_NAME_LITERALS 0
    #else
        #define KPT_COMPILER_NO_UNICODE_CHAR_NAME_LITERALS 1
    #endif
#endif

#ifndef KPT_COMPILER_NO_UNIFIED_INITIALIZATION_SYNTAX
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4004)
        #define KPT_COMPILER_NO_UNIFIED_INITIALIZATION_SYNTAX 0
    #elif KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 401 && defined(__apple_build_version__)
        #define KPT_COMPILER_NO_UNIFIED_INITIALIZATION_SYNTAX 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 301 && !defined(__apple_build_version__)
        #define KPT_COMPILER_NO_UNIFIED_INITIALIZATION_SYNTAX 0
    #else
        #define KPT_COMPILER_NO_UNIFIED_INITIALIZATION_SYNTAX 1
    #endif
#endif


#ifndef KPT_COMPILER_NO_EXTENDED_FRIEND_DECLARATIONS
    #if KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_GNUC) && (KPT_COMPILER_VERSION >= 4007)
        #define KPT_COMPILER_NO_EXTENDED_FRIEND_DECLARATIONS 0
    #elif  KPT_COMPILER_CPP11_ENABLED && defined(KPT_COMPILER_CLANG) && KPT_COMPILER_VERSION >= 209
        #define KPT_COMPILER_NO_EXTENDED_FRIEND_DECLARATIONS 0
    #else
        #define KPT_COMPILER_NO_EXTENDED_FRIEND_DECLARATIONS 1
    #endif
#endif

#endif //KPORT_COMPILER_FUNCTIONALITY_H_