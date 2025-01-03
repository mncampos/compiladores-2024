/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison/parser.y"

// GRUPO O
// MATEUS NUNES CAMPOS - 00268613
// GUILHERME DE SOUSA CIRUMBOLO - 00330049
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stack.h"

int yylex(void);
void yyerror (char const *mensagem);
extern int yylineno;
extern char **ytext;
extern void *arvore;
extern Stack *table_stack;
DataType current_type = -1;

#line 89 "bison/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_PR_IF = 3,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_ELSE = 4,                 /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_WHILE = 5,                /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_RETURN = 6,               /* TK_PR_RETURN  */
  YYSYMBOL_TK_OC_LE = 7,                   /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 8,                   /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 9,                   /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 10,                  /* TK_OC_NE  */
  YYSYMBOL_TK_OC_AND = 11,                 /* TK_OC_AND  */
  YYSYMBOL_TK_OC_OR = 12,                  /* TK_OC_OR  */
  YYSYMBOL_TK_ERRO = 13,                   /* TK_ERRO  */
  YYSYMBOL_TK_IDENTIFICADOR = 14,          /* TK_IDENTIFICADOR  */
  YYSYMBOL_TK_LIT_INT = 15,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 16,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_PR_INT = 17,                 /* TK_PR_INT  */
  YYSYMBOL_TK_PR_FLOAT = 18,               /* TK_PR_FLOAT  */
  YYSYMBOL_19_ = 19,                       /* '='  */
  YYSYMBOL_20_ = 20,                       /* '>'  */
  YYSYMBOL_21_ = 21,                       /* '<'  */
  YYSYMBOL_22_ = 22,                       /* '-'  */
  YYSYMBOL_23_ = 23,                       /* '{'  */
  YYSYMBOL_24_ = 24,                       /* '}'  */
  YYSYMBOL_25_ = 25,                       /* ';'  */
  YYSYMBOL_26_ = 26,                       /* ','  */
  YYSYMBOL_27_ = 27,                       /* '('  */
  YYSYMBOL_28_ = 28,                       /* ')'  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_begin_program = 35,             /* begin_program  */
  YYSYMBOL_programa = 36,                  /* programa  */
  YYSYMBOL_criar_pilha_tabelas = 37,       /* criar_pilha_tabelas  */
  YYSYMBOL_empilha_tabela = 38,            /* empilha_tabela  */
  YYSYMBOL_desempilha_tabela = 39,         /* desempilha_tabela  */
  YYSYMBOL_lista_funcoes = 40,             /* lista_funcoes  */
  YYSYMBOL_funcao = 41,                    /* funcao  */
  YYSYMBOL_cabecalho = 42,                 /* cabecalho  */
  YYSYMBOL_lista_parametros = 43,          /* lista_parametros  */
  YYSYMBOL_corpo = 44,                     /* corpo  */
  YYSYMBOL_literal = 45,                   /* literal  */
  YYSYMBOL_tipo = 46,                      /* tipo  */
  YYSYMBOL_bloco_comandos = 47,            /* bloco_comandos  */
  YYSYMBOL_comando = 48,                   /* comando  */
  YYSYMBOL_comandos = 49,                  /* comandos  */
  YYSYMBOL_lista_de_comandos = 50,         /* lista_de_comandos  */
  YYSYMBOL_declaracao_variavel = 51,       /* declaracao_variavel  */
  YYSYMBOL_lista_variaveis = 52,           /* lista_variaveis  */
  YYSYMBOL_variavel = 53,                  /* variavel  */
  YYSYMBOL_atribuicao = 54,                /* atribuicao  */
  YYSYMBOL_chamada_funcao = 55,            /* chamada_funcao  */
  YYSYMBOL_lista_args = 56,                /* lista_args  */
  YYSYMBOL_retorno = 57,                   /* retorno  */
  YYSYMBOL_controle_fluxo = 58,            /* controle_fluxo  */
  YYSYMBOL_if = 59,                        /* if  */
  YYSYMBOL_while = 60,                     /* while  */
  YYSYMBOL_expr = 61,                      /* expr  */
  YYSYMBOL_expr_or = 62,                   /* expr_or  */
  YYSYMBOL_expr_and = 63,                  /* expr_and  */
  YYSYMBOL_expr_eq = 64,                   /* expr_eq  */
  YYSYMBOL_expr_cmp = 65,                  /* expr_cmp  */
  YYSYMBOL_expr_sum = 66,                  /* expr_sum  */
  YYSYMBOL_expr_mult = 67,                 /* expr_mult  */
  YYSYMBOL_expr_unaria = 68,               /* expr_unaria  */
  YYSYMBOL_parenteses = 69,                /* parenteses  */
  YYSYMBOL_op = 70                         /* op  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   102

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,     2,     2,    32,     2,     2,
      27,    28,    30,    29,    26,    22,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
      21,    19,    20,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,    24,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    96,   100,   106,   107,   108,   117,   121,
     126,   137,   147,   148,   149,   153,   161,   165,   171,   172,
     180,   188,   193,   198,   201,   204,   207,   212,   222,   238,
     248,   254,   257,   269,   274,   289,   313,   329,   332,   340,
     353,   356,   361,   377,   401,   426,   431,   438,   443,   450,
     455,   462,   469,   474,   481,   488,   495,   502,   507,   514,
     521,   526,   533,   540,   547,   552,   560,   568,   573,   576,
     581,   593,   598
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_PR_IF",
  "TK_PR_ELSE", "TK_PR_WHILE", "TK_PR_RETURN", "TK_OC_LE", "TK_OC_GE",
  "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR", "TK_ERRO",
  "TK_IDENTIFICADOR", "TK_LIT_INT", "TK_LIT_FLOAT", "TK_PR_INT",
  "TK_PR_FLOAT", "'='", "'>'", "'<'", "'-'", "'{'", "'}'", "';'", "','",
  "'('", "')'", "'+'", "'*'", "'/'", "'%'", "'!'", "$accept",
  "begin_program", "programa", "criar_pilha_tabelas", "empilha_tabela",
  "desempilha_tabela", "lista_funcoes", "funcao", "cabecalho",
  "lista_parametros", "corpo", "literal", "tipo", "bloco_comandos",
  "comando", "comandos", "lista_de_comandos", "declaracao_variavel",
  "lista_variaveis", "variavel", "atribuicao", "chamada_funcao",
  "lista_args", "retorno", "controle_fluxo", "if", "while", "expr",
  "expr_or", "expr_and", "expr_eq", "expr_cmp", "expr_sum", "expr_mult",
  "expr_unaria", "parenteses", "op", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -94,     4,   -94,   -94,    22,     3,   -94,   -94,    22,    32,
     -94,   -94,   -94,     7,   -94,    55,    43,    45,    38,   -10,
     -94,   -94,   -94,    59,   -94,     7,    49,    51,    52,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,    58,     6,    38,    38,
      53,   -94,   -94,    38,    38,    38,   -94,   -94,   -94,    64,
      70,    10,     8,    11,    36,   -94,   -94,   -94,    38,    38,
       7,    75,   -94,    57,   -94,   -94,   -94,     7,    62,    71,
      21,    60,    61,   -94,    63,   -94,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,   -94,
      65,    66,   -94,    26,    59,   -94,    21,    69,   -94,    72,
      72,   -94,    70,    10,     8,     8,    11,    11,    11,    11,
      36,    36,   -94,   -94,   -94,   -94,    38,    73,   -94,   -94,
     -94,    74,    82,   -94,   -94,   -94,    21,    72,   -94,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     6,     1,     4,     0,     2,     7,     9,     0,
       6,     3,     8,    29,     7,    14,     0,     0,     0,     0,
      18,    19,     6,     0,    22,    29,     0,     0,     0,    26,
      23,    24,    25,    40,    41,    10,     0,     0,     0,     0,
      70,    16,    17,     0,     0,     0,    71,    72,    39,    45,
      47,    49,    52,    57,    60,    64,    67,    69,     0,     0,
      29,    33,    30,    31,    27,    21,    15,    29,     0,     0,
       0,     0,     0,    66,     0,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,    37,     7,     0,     0,    28,     0,     0,    11,     0,
       0,    68,    46,    48,    50,    51,    55,    56,    54,    53,
      59,    58,    61,    62,    63,    36,     0,     0,    34,    32,
      13,     0,    42,    44,    38,    20,     0,     0,    12,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,   -94,    13,   -14,    79,   -94,   -94,   -94,
     -94,     1,   -69,   -93,   -94,   -94,   -17,   -94,     5,   -94,
     -94,   -11,   -18,   -94,   -94,   -94,   -94,    -7,   -94,    24,
      25,   -34,   -19,   -26,   -40,   -94,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     6,     2,     4,    11,     7,     8,     9,    37,
      14,    46,    23,    24,    25,    26,    27,    28,    62,    63,
      29,    47,    90,    31,    32,    33,    34,    91,    49,    50,
      51,    52,    53,    54,    55,    56,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    98,    30,    73,     3,    75,   122,   123,    64,    58,
      16,    48,    17,    18,    30,    80,    81,    59,    69,    78,
      79,    19,    10,    15,    20,    21,    70,   120,    82,    83,
      22,    71,    72,    84,   129,    60,     5,    74,    20,    21,
      85,    41,    42,    92,   104,   105,   112,   113,   114,    30,
      95,    89,    40,    41,    42,    13,    30,   128,   110,   111,
      43,   106,   107,   108,   109,    44,    86,    87,    88,    36,
      38,    45,    39,    61,    65,    66,    76,    67,   117,    68,
      59,    77,    93,    94,    96,    97,   127,    12,    99,   100,
     121,   101,   116,   115,   118,    22,   126,   125,   124,   119,
     102,     0,   103
};

static const yytype_int8 yycheck[] =
{
      14,    70,    13,    43,     0,    45,    99,   100,    25,    19,
       3,    18,     5,     6,    25,     7,     8,    27,    12,     9,
      10,    14,    19,    10,    17,    18,    20,    96,    20,    21,
      23,    38,    39,    22,   127,    22,    14,    44,    17,    18,
      29,    15,    16,    60,    78,    79,    86,    87,    88,    60,
      67,    58,    14,    15,    16,    23,    67,   126,    84,    85,
      22,    80,    81,    82,    83,    27,    30,    31,    32,    14,
      27,    33,    27,    14,    25,    24,    12,    25,    92,    21,
      27,    11,     7,    26,    22,    14,     4,     8,    28,    28,
      21,    28,    26,    28,    93,    23,    22,    24,   116,    94,
      76,    -1,    77
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    37,     0,    38,    14,    36,    40,    41,    42,
      19,    39,    40,    23,    44,    38,     3,     5,     6,    14,
      17,    18,    23,    46,    47,    48,    49,    50,    51,    54,
      55,    57,    58,    59,    60,    39,    14,    43,    27,    27,
      14,    15,    16,    22,    27,    33,    45,    55,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    19,    27,
      38,    14,    52,    53,    50,    25,    24,    25,    21,    12,
      20,    61,    61,    68,    61,    68,    12,    11,     9,    10,
       7,     8,    20,    21,    22,    29,    30,    31,    32,    61,
      56,    61,    50,     7,    26,    50,    22,    14,    46,    28,
      28,    28,    63,    64,    65,    65,    66,    66,    66,    66,
      67,    67,    68,    68,    68,    28,    26,    39,    45,    52,
      46,    21,    47,    47,    56,    24,    22,     4,    46,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    38,    39,    40,    40,
      41,    42,    43,    43,    43,    44,    45,    45,    46,    46,
      47,    48,    49,    49,    49,    49,    49,    50,    50,    50,
      51,    52,    52,    53,    53,    54,    55,    56,    56,    57,
      58,    58,    59,    59,    60,    61,    62,    62,    63,    63,
      64,    64,    64,    65,    65,    65,    65,    65,    66,    66,
      66,    67,    67,    67,    67,    68,    68,    68,    69,    69,
      70,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     0,     0,     0,     0,     2,     1,
       3,     6,     6,     4,     0,     3,     1,     1,     1,     1,
       5,     2,     1,     1,     1,     1,     1,     2,     3,     0,
       2,     1,     3,     1,     3,     3,     4,     1,     3,     2,
       1,     1,     5,     7,     5,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     1,     3,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* programa: lista_funcoes desempilha_tabela  */
#line 96 "bison/parser.y"
                                     {
        (yyval.tree) = (yyvsp[-1].tree);
        arvore = (yyval.tree);
    }
#line 1502 "bison/parser.tab.c"
    break;

  case 4: /* programa: %empty  */
#line 100 "bison/parser.y"
                  {
        (yyval.tree) = NULL;
        arvore = (yyval.tree);
    }
#line 1511 "bison/parser.tab.c"
    break;

  case 5: /* criar_pilha_tabelas: %empty  */
#line 106 "bison/parser.y"
                      {table_stack = create_stack(1);}
#line 1517 "bison/parser.tab.c"
    break;

  case 6: /* empilha_tabela: %empty  */
#line 107 "bison/parser.y"
                 {push_stack(table_stack, create_symbol_table(1));}
#line 1523 "bison/parser.tab.c"
    break;

  case 7: /* desempilha_tabela: %empty  */
#line 108 "bison/parser.y"
                    {pop_stack(table_stack);}
#line 1529 "bison/parser.tab.c"
    break;

  case 8: /* lista_funcoes: funcao lista_funcoes  */
#line 117 "bison/parser.y"
                         {
        (yyval.tree) = (yyvsp[-1].tree);
        add_child((yyval.tree), (yyvsp[0].tree));
    }
#line 1538 "bison/parser.tab.c"
    break;

  case 9: /* lista_funcoes: funcao  */
#line 121 "bison/parser.y"
             {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1546 "bison/parser.tab.c"
    break;

  case 10: /* funcao: cabecalho corpo desempilha_tabela  */
#line 126 "bison/parser.y"
                                      {
        (yyval.tree) = (yyvsp[-2].tree);
        add_child((yyval.tree), (yyvsp[-1].tree));
    }
#line 1555 "bison/parser.tab.c"
    break;

  case 11: /* cabecalho: TK_IDENTIFICADOR '=' empilha_tabela lista_parametros '>' tipo  */
#line 137 "bison/parser.y"
                                                                  {
        
        (yyval.tree) = new_node((yyvsp[-5].valor_lexico));
        
        isAlreadyDeclared(peek_stack(table_stack,2), (yyvsp[-5].valor_lexico)->value, (yyvsp[-5].valor_lexico)->line);
        insert_symbol(peek_stack(table_stack, 2), (yyvsp[-5].valor_lexico)->line, FUNCTION, (yyvsp[0].valor_lexico)->type, (yyvsp[-5].valor_lexico)->value);
        (yyval.tree)->lex_value->type = (yyvsp[0].valor_lexico)->type;
    }
#line 1568 "bison/parser.tab.c"
    break;

  case 12: /* lista_parametros: lista_parametros TK_OC_OR TK_IDENTIFICADOR '<' '-' tipo  */
#line 147 "bison/parser.y"
                                                            { isAlreadyDeclared(peek_stack(table_stack,1), (yyvsp[-3].valor_lexico)->value, (yyvsp[-3].valor_lexico)->line); insert_symbol(peek_stack(table_stack,1), (yyvsp[-3].valor_lexico)->line, IDENTIFIER, (yyvsp[0].valor_lexico)->type, (yyvsp[-3].valor_lexico)->value ); }
#line 1574 "bison/parser.tab.c"
    break;

  case 13: /* lista_parametros: TK_IDENTIFICADOR '<' '-' tipo  */
#line 148 "bison/parser.y"
                                    {isAlreadyDeclared(peek_stack(table_stack,1), (yyvsp[-3].valor_lexico)->value, (yyvsp[-3].valor_lexico)->line); insert_symbol(peek_stack(table_stack,1), (yyvsp[-3].valor_lexico)->line, IDENTIFIER, (yyvsp[0].valor_lexico)->type, (yyvsp[-3].valor_lexico)->value );  }
#line 1580 "bison/parser.tab.c"
    break;

  case 15: /* corpo: '{' lista_de_comandos '}'  */
#line 153 "bison/parser.y"
                                 {
        (yyval.tree) = (yyvsp[-1].tree);
    }
#line 1588 "bison/parser.tab.c"
    break;

  case 16: /* literal: TK_LIT_INT  */
#line 161 "bison/parser.y"
               {
        (yyval.tree) = new_node((yyvsp[0].valor_lexico));
        (yyval.tree)->lex_value->type = LEX_LIT_INT;
    }
#line 1597 "bison/parser.tab.c"
    break;

  case 17: /* literal: TK_LIT_FLOAT  */
#line 165 "bison/parser.y"
                   {
        (yyval.tree) = new_node((yyvsp[0].valor_lexico));
        (yyval.tree)->lex_value->type = LEX_LIT_FLOAT;
    }
#line 1606 "bison/parser.tab.c"
    break;

  case 20: /* bloco_comandos: '{' empilha_tabela lista_de_comandos desempilha_tabela '}'  */
#line 180 "bison/parser.y"
                                                               {
        (yyval.tree) = (yyvsp[-2].tree);
    }
#line 1614 "bison/parser.tab.c"
    break;

  case 21: /* comando: comandos ';'  */
#line 188 "bison/parser.y"
                 {
        (yyval.tree) = (yyvsp[-1].tree);
    }
#line 1622 "bison/parser.tab.c"
    break;

  case 22: /* comandos: bloco_comandos  */
#line 193 "bison/parser.y"
                   {
        if ((yyvsp[0].tree) != NULL) {
            (yyval.tree) = (yyvsp[0].tree);
        }
    }
#line 1632 "bison/parser.tab.c"
    break;

  case 23: /* comandos: chamada_funcao  */
#line 198 "bison/parser.y"
                     {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1640 "bison/parser.tab.c"
    break;

  case 24: /* comandos: retorno  */
#line 201 "bison/parser.y"
              {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1648 "bison/parser.tab.c"
    break;

  case 25: /* comandos: controle_fluxo  */
#line 204 "bison/parser.y"
                     {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1656 "bison/parser.tab.c"
    break;

  case 26: /* comandos: atribuicao  */
#line 207 "bison/parser.y"
                 {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1664 "bison/parser.tab.c"
    break;

  case 27: /* lista_de_comandos: comando lista_de_comandos  */
#line 212 "bison/parser.y"
                              {
        if ((yyvsp[-1].tree) != NULL) {
            (yyval.tree) = (yyvsp[-1].tree);
            if ((yyvsp[0].tree) != NULL) {
                add_child((yyval.tree), (yyvsp[0].tree));
            }
        } else {
            (yyval.tree) = (yyvsp[0].tree);
        }
    }
#line 1679 "bison/parser.tab.c"
    break;

  case 28: /* lista_de_comandos: declaracao_variavel ';' lista_de_comandos  */
#line 222 "bison/parser.y"
                                                {
        if ((yyvsp[-2].tree) != NULL) {
            (yyval.tree) = (yyvsp[-2].tree);
            if ((yyvsp[-2].tree)->children_quantity == 3) {
                Node* aux = (yyvsp[-2].tree)->children[2];
                while (aux->children_quantity == 3) {
                    aux = aux->children[2];
                }
                add_child(aux, (yyvsp[0].tree));
            } else {
                add_child((yyval.tree), (yyvsp[0].tree));
            }
        } else {
            (yyval.tree) = (yyvsp[0].tree);
        }
    }
#line 1700 "bison/parser.tab.c"
    break;

  case 29: /* lista_de_comandos: %empty  */
#line 238 "bison/parser.y"
                  {
        (yyval.tree) = NULL;
    }
#line 1708 "bison/parser.tab.c"
    break;

  case 30: /* declaracao_variavel: tipo lista_variaveis  */
#line 248 "bison/parser.y"
                         {
        current_type = (yyvsp[-1].valor_lexico)->type;
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1717 "bison/parser.tab.c"
    break;

  case 31: /* lista_variaveis: variavel  */
#line 254 "bison/parser.y"
             {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1725 "bison/parser.tab.c"
    break;

  case 32: /* lista_variaveis: variavel ',' lista_variaveis  */
#line 257 "bison/parser.y"
                                   {
        if ((yyvsp[-2].tree) != NULL) {
            (yyval.tree) = (yyvsp[-2].tree);
            if ((yyvsp[0].tree) != NULL) {
                add_child((yyval.tree), (yyvsp[0].tree));
            }
        } else {
            (yyval.tree) = (yyvsp[0].tree);
        }
    }
#line 1740 "bison/parser.tab.c"
    break;

  case 33: /* variavel: TK_IDENTIFICADOR  */
#line 269 "bison/parser.y"
                     {
        (yyval.tree) = NULL;
        isAlreadyDeclared(peek_stack(table_stack,1), (yyvsp[0].valor_lexico)->value, (yyvsp[0].valor_lexico)->line);
        insert_symbol(peek_stack(table_stack, 1), (yyvsp[0].valor_lexico)->line, IDENTIFIER, current_type, (yyvsp[0].valor_lexico)->value);
    }
#line 1750 "bison/parser.tab.c"
    break;

  case 34: /* variavel: TK_IDENTIFICADOR TK_OC_LE literal  */
#line 274 "bison/parser.y"
                                        {
        (yyval.tree) = new_simple_node("<=");
        Node* new = new_node((yyvsp[-2].valor_lexico));
        new->lex_value->type = current_type;
        add_child((yyval.tree), new);
        add_child((yyval.tree), (yyvsp[0].tree));

        isAlreadyDeclared(peek_stack(table_stack,1), (yyvsp[-2].valor_lexico)->value, (yyvsp[-2].valor_lexico)->line);
        insert_symbol(peek_stack(table_stack, 1), (yyvsp[-2].valor_lexico)->line, IDENTIFIER, current_type, (yyvsp[-2].valor_lexico)->value);
    }
#line 1765 "bison/parser.tab.c"
    break;

  case 35: /* atribuicao: TK_IDENTIFICADOR '=' expr  */
#line 289 "bison/parser.y"
                              {

        
        isUndeclared(table_stack, (yyvsp[-2].valor_lexico)->value, (yyvsp[-2].valor_lexico)->line);
        isKindCorrect(table_stack, (yyvsp[-2].valor_lexico)->value, IDENTIFIER, (yyvsp[-2].valor_lexico)->line);

        (yyval.tree) = new_simple_node("=");
        Node* new = new_node((yyvsp[-2].valor_lexico));
        new->lex_value->type = (yyval.tree)->lex_value->type;
        add_child((yyval.tree), new);
        add_child((yyval.tree), (yyvsp[0].tree));

        TableData* data = find_stack_symbol(table_stack, (yyvsp[-2].valor_lexico)->value);
        (yyval.tree)->lex_value->type = data->symbol_type;
        (yyval.tree)->code = add_instruction((yyval.tree)->code, new_instruction("loadI", data->offset, data->temp_name, NULL));
        (yyval.tree)->code = add_instruction((yyval.tree)->code, new_instruction("storeAO", (yyvsp[0].tree)->temp_name, data->temp_name, "rfp"));



    }
#line 1790 "bison/parser.tab.c"
    break;

  case 36: /* chamada_funcao: TK_IDENTIFICADOR '(' lista_args ')'  */
#line 313 "bison/parser.y"
                                        {

        size_t new_length = strlen((yyvsp[-3].valor_lexico)->value) + strlen("call ") + 1;
        char* buffer = malloc(new_length);
        if (buffer) {
            snprintf(buffer, new_length, "call %s", (yyvsp[-3].valor_lexico)->value);
            (yyval.tree) = new_simple_node(buffer);
            add_child((yyval.tree), (yyvsp[-1].tree));
        }

        
        isUndeclared(table_stack, (yyvsp[-3].valor_lexico)->value, (yyvsp[-3].valor_lexico)->line);
        isKindCorrect(table_stack, (yyvsp[-3].valor_lexico)->value, FUNCTION, (yyvsp[-3].valor_lexico)->line);
    }
#line 1809 "bison/parser.tab.c"
    break;

  case 37: /* lista_args: expr  */
#line 329 "bison/parser.y"
         {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1817 "bison/parser.tab.c"
    break;

  case 38: /* lista_args: expr ',' lista_args  */
#line 332 "bison/parser.y"
                          {
        (yyval.tree) = (yyvsp[-2].tree);
        add_child((yyval.tree), (yyvsp[0].tree));
    }
#line 1826 "bison/parser.tab.c"
    break;

  case 39: /* retorno: TK_PR_RETURN expr  */
#line 340 "bison/parser.y"
                      {
        (yyval.tree) = new_simple_node("return");
        add_child((yyval.tree), (yyvsp[0].tree));
    }
#line 1835 "bison/parser.tab.c"
    break;

  case 40: /* controle_fluxo: if  */
#line 353 "bison/parser.y"
       {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1843 "bison/parser.tab.c"
    break;

  case 41: /* controle_fluxo: while  */
#line 356 "bison/parser.y"
            {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1851 "bison/parser.tab.c"
    break;

  case 42: /* if: TK_PR_IF '(' expr ')' bloco_comandos  */
#line 361 "bison/parser.y"
                                         {
        (yyval.tree) = new_simple_node("if");
        add_child((yyval.tree), (yyvsp[-2].tree));
        char* label1 = create_label();
        char* label2 = create_label();

        add_instruction((yyval.tree)->code, new_instruction("cbr", (yyvsp[-2].tree)->temp_name, label1, label2));
        add_instruction((yyval.tree)->code, new_instruction("label", label1, NULL, NULL));

        if ((yyvsp[0].tree) != NULL) {
            add_child((yyval.tree), (yyvsp[0].tree));
        }

        add_instruction((yyval.tree)->code, new_instruction("label", label2, NULL, NULL));

    }
#line 1872 "bison/parser.tab.c"
    break;

  case 43: /* if: TK_PR_IF '(' expr ')' bloco_comandos TK_PR_ELSE bloco_comandos  */
#line 377 "bison/parser.y"
                                                                     {
        (yyval.tree) = new_simple_node("if");
        add_child((yyval.tree), (yyvsp[-4].tree));
        char* label1 = create_label();
        char* label2 = create_label();
        char* label3 = create_label();

        add_instruction((yyval.tree)->code, new_instruction("cbr", (yyvsp[-4].tree)->temp_name, label1, label2));
        add_instruction((yyval.tree)->code, new_instruction("label", label1, NULL, NULL));
        if ((yyvsp[-2].tree) != NULL) {
            add_child((yyval.tree), (yyvsp[-2].tree));
        }

        add_instruction((yyval.tree)->code, new_instruction("jumpI", label3, NULL, NULL));
        add_instruction((yyval.tree)->code, new_instruction("label", label2, NULL, NULL));

        if ((yyvsp[0].tree) != NULL) {
            add_child((yyval.tree), (yyvsp[0].tree));
        }

        add_instruction((yyval.tree)->code, new_instruction("label", label3, NULL, NULL));
    }
#line 1899 "bison/parser.tab.c"
    break;

  case 44: /* while: TK_PR_WHILE '(' expr ')' bloco_comandos  */
#line 401 "bison/parser.y"
                                            {
        (yyval.tree) = new_simple_node("while");

        char* label1 = create_label();
        char* label2 = create_label();
        char* label3 = create_label();
        (yyval.tree)->code = add_instruction(new_list(), new_instruction("label", label3, NULL, NULL));
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_instruction((yyval.tree)->code, new_instruction("cbr", (yyvsp[-2].tree)->temp_name, label1, label2));
        add_instruction((yyval.tree)->code, new_instruction("label", label1, NULL, NULL));

        if ((yyvsp[0].tree) != NULL) {
            add_child((yyval.tree), (yyvsp[0].tree));
        }

        add_instruction((yyval.tree)->code, new_instruction("jumpI", label3, NULL, NULL));
        add_instruction((yyval.tree)->code, new_instruction("label", label2, NULL, NULL));
    }
#line 1922 "bison/parser.tab.c"
    break;

  case 45: /* expr: expr_or  */
#line 426 "bison/parser.y"
            {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1930 "bison/parser.tab.c"
    break;

  case 46: /* expr_or: expr_or TK_OC_OR expr_and  */
#line 431 "bison/parser.y"
                              {
        (yyval.tree) = new_simple_node("|");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 1942 "bison/parser.tab.c"
    break;

  case 47: /* expr_or: expr_and  */
#line 438 "bison/parser.y"
               {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1950 "bison/parser.tab.c"
    break;

  case 48: /* expr_and: expr_and TK_OC_AND expr_eq  */
#line 443 "bison/parser.y"
                               {
        (yyval.tree) = new_simple_node("&");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 1962 "bison/parser.tab.c"
    break;

  case 49: /* expr_and: expr_eq  */
#line 450 "bison/parser.y"
              {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 1970 "bison/parser.tab.c"
    break;

  case 50: /* expr_eq: expr_eq TK_OC_EQ expr_cmp  */
#line 455 "bison/parser.y"
                              {
        (yyval.tree) = new_simple_node("==");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 1982 "bison/parser.tab.c"
    break;

  case 51: /* expr_eq: expr_eq TK_OC_NE expr_cmp  */
#line 462 "bison/parser.y"
                                {
        (yyval.tree) = new_simple_node("!=");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 1994 "bison/parser.tab.c"
    break;

  case 52: /* expr_eq: expr_cmp  */
#line 469 "bison/parser.y"
               {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2002 "bison/parser.tab.c"
    break;

  case 53: /* expr_cmp: expr_cmp '<' expr_sum  */
#line 474 "bison/parser.y"
                          {
        (yyval.tree) = new_simple_node("<");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 2014 "bison/parser.tab.c"
    break;

  case 54: /* expr_cmp: expr_cmp '>' expr_sum  */
#line 481 "bison/parser.y"
                            {
        (yyval.tree) = new_simple_node(">");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 2026 "bison/parser.tab.c"
    break;

  case 55: /* expr_cmp: expr_cmp TK_OC_LE expr_sum  */
#line 488 "bison/parser.y"
                                 {
        (yyval.tree) = new_simple_node("<=");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 2038 "bison/parser.tab.c"
    break;

  case 56: /* expr_cmp: expr_cmp TK_OC_GE expr_sum  */
#line 495 "bison/parser.y"
                                 {
        (yyval.tree) = new_simple_node(">=");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 2050 "bison/parser.tab.c"
    break;

  case 57: /* expr_cmp: expr_sum  */
#line 502 "bison/parser.y"
               {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2058 "bison/parser.tab.c"
    break;

  case 58: /* expr_sum: expr_sum '+' expr_mult  */
#line 507 "bison/parser.y"
                           {
        (yyval.tree) = new_simple_node("+");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 2070 "bison/parser.tab.c"
    break;

  case 59: /* expr_sum: expr_sum '-' expr_mult  */
#line 514 "bison/parser.y"
                             {
        (yyval.tree) = new_simple_node("-");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 2082 "bison/parser.tab.c"
    break;

  case 60: /* expr_sum: expr_mult  */
#line 521 "bison/parser.y"
                {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2090 "bison/parser.tab.c"
    break;

  case 61: /* expr_mult: expr_mult '*' expr_unaria  */
#line 526 "bison/parser.y"
                              {
        (yyval.tree) = new_simple_node("*");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 2102 "bison/parser.tab.c"
    break;

  case 62: /* expr_mult: expr_mult '/' expr_unaria  */
#line 533 "bison/parser.y"
                                {
        (yyval.tree) = new_simple_node("/");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 2114 "bison/parser.tab.c"
    break;

  case 63: /* expr_mult: expr_mult '%' expr_unaria  */
#line 540 "bison/parser.y"
                                {
        (yyval.tree) = new_simple_node("%");
        (yyval.tree)->lex_value->type = typeInfer((yyvsp[-2].tree)->lex_value->type, (yyvsp[0].tree)->lex_value->type);
        add_child((yyval.tree), (yyvsp[-2].tree));
        add_child((yyval.tree), (yyvsp[0].tree));
        gen_code((yyval.tree), (yyvsp[-2].tree)->temp_name, (yyvsp[0].tree)->temp_name, 1);
    }
#line 2126 "bison/parser.tab.c"
    break;

  case 64: /* expr_mult: expr_unaria  */
#line 547 "bison/parser.y"
                  {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2134 "bison/parser.tab.c"
    break;

  case 65: /* expr_unaria: '!' expr_unaria  */
#line 552 "bison/parser.y"
                    {
        (yyval.tree) = new_simple_node("!");
        (yyval.tree)->lex_value->type = (yyvsp[0].tree)->lex_value->type;
        add_child((yyval.tree), (yyvsp[0].tree));
        char* temp_name = create_temporary();
        add_instruction((yyval.tree)->code, new_instruction("loadI", get_constant((yyval.tree)->lex_value->value), temp_name, NULL));
        gen_code((yyval.tree), (yyvsp[0].tree)->temp_name, temp_name, 0);
    }
#line 2147 "bison/parser.tab.c"
    break;

  case 66: /* expr_unaria: '-' expr_unaria  */
#line 560 "bison/parser.y"
                      {
        (yyval.tree) = new_simple_node("-");
        (yyval.tree)->lex_value->type = (yyvsp[0].tree)->lex_value->type;
        add_child((yyval.tree), (yyvsp[0].tree));
         char* temp_name = create_temporary();
        add_instruction((yyval.tree)->code, new_instruction("loadI", get_constant((yyval.tree)->lex_value->value), temp_name, NULL));
        gen_code((yyval.tree), (yyvsp[0].tree)->temp_name, temp_name, 0);
    }
#line 2160 "bison/parser.tab.c"
    break;

  case 67: /* expr_unaria: parenteses  */
#line 568 "bison/parser.y"
                 {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2168 "bison/parser.tab.c"
    break;

  case 68: /* parenteses: '(' expr ')'  */
#line 573 "bison/parser.y"
                 {
        (yyval.tree) = (yyvsp[-1].tree);
    }
#line 2176 "bison/parser.tab.c"
    break;

  case 69: /* parenteses: op  */
#line 576 "bison/parser.y"
         {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2184 "bison/parser.tab.c"
    break;

  case 70: /* op: TK_IDENTIFICADOR  */
#line 581 "bison/parser.y"
                     {
        
        isUndeclared(table_stack, (yyvsp[0].valor_lexico)->value, (yyvsp[0].valor_lexico)->line);
        isKindCorrect(table_stack,(yyvsp[0].valor_lexico)->value, IDENTIFIER, (yyvsp[0].valor_lexico)->line);
        (yyvsp[0].valor_lexico)->type = getType(peek_stack(table_stack, 1), (yyvsp[0].valor_lexico)->value);
        (yyval.tree) = new_node((yyvsp[0].valor_lexico));
        

        TableData* data = find_stack_symbol(table_stack, (yyvsp[0].valor_lexico)->value);
        (yyval.tree)->temp_name = create_temporary();
        (yyval.tree)->code = add_instruction(new_list(), new_instruction("loadAO", data->temp_name, "rfp", (yyval.tree)->temp_name));
    }
#line 2201 "bison/parser.tab.c"
    break;

  case 71: /* op: literal  */
#line 593 "bison/parser.y"
              {
        (yyval.tree) = (yyvsp[0].tree);
        (yyval.tree)->temp_name = create_temporary();
        (yyval.tree)->code = add_instruction(new_list(), new_instruction("loadI", (yyval.tree)->lex_value->value, (yyval.tree)->temp_name, NULL));
    }
#line 2211 "bison/parser.tab.c"
    break;

  case 72: /* op: chamada_funcao  */
#line 598 "bison/parser.y"
                     {
        (yyval.tree) = (yyvsp[0].tree);
    }
#line 2219 "bison/parser.tab.c"
    break;


#line 2223 "bison/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 603 "bison/parser.y"


// Função de erro
void yyerror(const char *mensagem) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno, mensagem);
}
