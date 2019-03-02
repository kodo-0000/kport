
#ifndef KPORT_STRING_H_
#define KPORT_STRING_H_

#ifndef KPT_JION
    #define KPT_JION_HELP0(a, b) a##b
    #define KPT_JION_HELP1(a, b) KPT_JION_HELP0(a, b)
    #define KPT_JION(a, b)  KPT_JION_HELP1(a, b)
#endif

#ifndef KPT_STRINGIF
    #define KPT_STRINGIF_HELP(x) #x
    #define KPT_STRINGIF(x) KPT_STRINGIF_HELP(x)
#endif

#ifndef KPT_LPAREN
    #define KPT_LPAREN() (
#endif

#ifndef KPT_RPAREN
    #define KPT_RPAREN() )
#endif

#ifndef KPT_COMMA
    #define KPT_COMMA() ,
#endif

#ifndef KPT_SEMI
    #define KPT_SEMI ;
#endif

#endif //KPORT_STRING_H_
