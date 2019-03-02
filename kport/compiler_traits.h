
#ifndef KPORT_COMPILER_TRAITS_H_
#define KPORT_COMPILER_TRAITS_H_

#ifndef KPT_MAY_ALIAS_AVAILABLE
    #if defined(KPT_COMPILER_GNUC) && KPT_COMPILER_VERSION >= 3003
        #define KPT_MAY_ALIAS_AVAILABLE 2
    #else
        #define KPT_MAY_ALIAS_AVAILABLE 0
    #endif
#endif

#ifndef KPT_MAY_ALIAS
    #if KPT_MAY_ALIAS_AVAILABLE
        #define KPT_MAY_ALIAS __attribute__((__may_alias__))
    #else
        #define KPT_MAY_ALIAS
    #endif
#endif

#ifndef KPT_PURE
    #if defined(KPT_COMPILER_GNUC)
        #define KPT_PURE __attribute__((pure))
    #else
        #define KPT_PURE
    #endif
#endif

#ifndef KPT_WEAK
    #define KPT_WEAK __attribute__((weak))
#endif

#ifndef KPT_UNUSED
        #define KPT_UNUSED(x) (void)x
#endif

#ifndef KPT_EMPTY
    #define  KPT_EMPTY (void)0
#endif

#ifndef KPT_OVERRIDE
    #if KPT_COMPILER_NO_OVERRIDE
        #define KPT_OVERRIDE
    #else
        #define KPT_OVERRIDE override
    #endif
#endif

#ifndef KPT_INHERITANCE_FINAL
    #if KPT_COMPILER_NO_INHERITANCE_FINAL
        #define KPT_INHERITANCE_FINAL
    #else
        #define KPT_INHERITANCE_FINAL final
    #endif
#endif

#ifndef KPT_FINAL_OVERRIDE
    #define KPT_FINAL_OVERRIDE KPT_OVERRIDE KPT_INHERITANCE_FINAL
#endif

#ifndef KPT_CONSTEXPR
    #if KPT_COMPILER_NO_CONSTEXPR
        #define KPT_CONSTEXPR
    #else
        #define KPT_CONSTEXPR constexpr
    #endif
#endif

#ifndef KPT_FUNC_CONSTEXPR
    #if KPT_COMPILER_CPP14_ENABLED
        #define KPT_FUNC_CONSTEXPR constexpr
    #else
        #define KPT_FUNC_CONSTEXPR
    #endif
#endif

#ifndef KPT_CONSTEXPR_OR_CONST
    #if KPT_COMPILER_NO_CONSTEXPR
        #define KPT_CONSTEXPR_OR_CONST const
    #else
        #define KPT_CONSTEXPR_OR_CONST constexpr
    #endif
#endif

#ifndef KPT_EXTERN_TEMPLATE
    #if KPT_COMPILER_NO_EXTERN_TEMPLATE
        #define KPT_EXTERN_TEMPLATE(declaration)
    #else
        #define KPT_EXTERN_TEMPLATE(declaration)  extern template declaration
    #endif
#endif

#ifndef KPT_NOEXCEPT
    #if KPT_COMPILER_NO_NOEXCEPT
        #define KPT_NOEXCEPT
        #define KPT_NOEXCEPT_IF(predicate)
        #define KPT_NOEXCEPT_EXPR(expression) false
    #else
        #define KPT_NOEXCEPT noexcept
        #define KPT_NOEXCEPT_IF(predicate) noexcept((predicate))
        #define KPT_NOEXCEPT_EXPR(expression) noexcept((expression))
    #endif
#endif

#ifndef KPT_NORETURN
    #if KPT_COMPILER_NO_NORETURN
        #define KPT_NORETURN
    #else
        #define KPT_NORETURN [[noreturn]]
    #endif
#endif

#ifndef KPT_MAY_UNUSED
    #if KPT_COMPILER_NO_MAYBE_UNUSED
        #define KPT_MAY_UNUSED
    #else
        #define KPT_MAY_UNUSED [[maybe_unused]]
    #endif
#endif

#ifndef KPT_NON_COPYABLE
    #if KPT_COMPILER_NO_DELETED_FUNCTIONS
        #define KPT_NON_COPYABLE(ClassName_) \
            private:                                      \
				ClassName_(const ClassName_&);                  \
				void operator=(const ClassName_&);
    #else
        #define KPT_NON_COPYABLE(ClassName_) \
				ClassName_(const ClassName_&) = delete;         \
				void operator=(const ClassName_&) = delete;
    #endif
#endif

#ifndef KPT_FUNCTION_DELETE
    #if KPT_COMPILER_NO_DELETED_FUNCTIONS
        #define KPT_FUNCTION_DELETE
    #else
        #define KPT_FUNCTION_DELETE = delete
    #endif
#endif

#ifndef KPT_DISABLE_DEFAULT_CTOR
    #define KPT_DISABLE_DEFAULT_CTOR(ClassName) ClassName() KPT_FUNCTION_DELETE
    #define KPT_DISABLE_COPY_CTOR(ClassName) ClassName(const (ClassName) &) KPT_FUNCTION_DELETE
    #define KPT_DISABLE_MOVE_CTOR(ClassName) ClassName((ClassName)&&) KPT_FUNCTION_DELETE
    #define KPT_DISABLE_ASSIGNMENT_OPERATOR(ClassName) ClassName& operator=(const (ClassName) &) KPT_FUNCTION_DELETE
    #define KPT_DISABLE_MOVE_OPERATOR(ClassName) ClassName& operator=(ClassName&&) KPT_FUNCTION_DELETE
#endif

#endif //KPORT_COMPILER_TRAITS_H_
