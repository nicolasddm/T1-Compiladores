/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compilador.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "tabelaSimbolos.c"
#include "pilha.c"
#define TAM_COMANDO 64
#define TAM_ROTULO 16
#define TAM_MAX 128


char comando[TAM_COMANDO];
char rotulo[TAM_ROTULO];
char ident_proc_funcao[TAM_COMANDO];

int num_vars;
int tamAmem;
int nivelLexico = 0;
int deslocamento = 0;
int numTipo;
int tipo;
int elemTipo;
int elemAtribuicaoTipo;
int rotulosTam = -1;
int rotuloDesviaTrue;
int rotuloDesviaFalse;
int numParams = 0;
int paramsPorTipo = 0;
int valor = 0;
int referencia = 1;
int paramsPassados = 0;

TabelaSimbolos *tabelaSimbolos;
Simbolo elemento;
Simbolo simboloElem;
Simbolo elemAtribuicao;
Pilha *pilhaExpressao;
Pilha *pilhaRotulos;
Pilha *pilhaDmem;
Pilha *pilhaParametros;
Pilha *pilhaParamsPassados;


#line 116 "compilador.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    ABRE_PARENTESES = 259,
    FECHA_PARENTESES = 260,
    VIRGULA = 261,
    PONTO_E_VIRGULA = 262,
    DOIS_PONTOS = 263,
    PONTO = 264,
    T_BEGIN = 265,
    T_END = 266,
    VAR = 267,
    ATRIBUICAO = 268,
    WRITE = 269,
    READ = 270,
    LABEL = 271,
    TYPE = 272,
    ARRAY = 273,
    OF = 274,
    PROCEDURE = 275,
    FUNCTION = 276,
    GOTO = 277,
    IF = 278,
    THEN = 279,
    ELSE = 280,
    WHILE = 281,
    DO = 282,
    IGUAL = 283,
    DIFERENTE = 284,
    MENOR_IGUAL = 285,
    MAIOR_IGUAL = 286,
    MENOR = 287,
    MAIOR = 288,
    MAIS = 289,
    MENOS = 290,
    OR = 291,
    MULTI = 292,
    DIV = 293,
    AND = 294,
    NOT = 295,
    NUMERO = 296,
    IDENT = 297,
    LOWER_THAN_ELSE = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

#define YYUNDEFTOK  2
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    59,    71,    84,    86,    86,   105,   106,
     109,   110,   115,   123,   134,   115,   149,   149,   150,   154,
     155,   159,   159,   168,   170,   174,   189,   191,   191,   197,
     200,   201,   204,   207,   204,   214,   224,   237,   251,   252,
     256,   258,   259,   263,   264,   267,   266,   272,   273,   274,
     275,   276,   280,   281,   286,   295,   285,   310,   316,   319,
     330,   343,   346,   351,   362,   369,   361,   390,   398,   399,
     403,   403,   418,   419,   424,   430,   438,   451,   452,   456,
     458,   460,   462,   464,   466,   468,   472,   473,   474,   475,
     476,   477,   481,   482,   483,   484,   489,   499,   500,   501,
     502,   507,   514,   517
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA", "DOIS_PONTOS", "PONTO",
  "T_BEGIN", "T_END", "VAR", "ATRIBUICAO", "WRITE", "READ", "LABEL",
  "TYPE", "ARRAY", "OF", "PROCEDURE", "FUNCTION", "GOTO", "IF", "THEN",
  "ELSE", "WHILE", "DO", "IGUAL", "DIFERENTE", "MENOR_IGUAL",
  "MAIOR_IGUAL", "MENOR", "MAIOR", "MAIS", "MENOS", "OR", "MULTI", "DIV",
  "AND", "NOT", "NUMERO", "IDENT", "LOWER_THAN_ELSE", "$accept",
  "programa", "$@1", "bloco", "parte_declara_algo_ou_nada", "$@2",
  "parte_declara_funcoes_ou_procedimentos",
  "declara_procedimento_ou_funcao", "declara_procedimento", "$@3", "$@4",
  "$@5", "tem_parametro_ou_nada", "$@6", "todos_parametros_formais",
  "parametros_formais_tipo", "$@7", "idents_params_formais",
  "parametro_formal", "parte_declara_vars", "var", "$@8", "declara_vars",
  "declara_var", "$@9", "$@10", "tipo", "lista_id_var", "lista_idents",
  "comando_composto", "comandos", "ponto_e_virgula_ou_vazio", "comando",
  "$@11", "comando_condicional", "parte_if_then", "$@12", "$@13",
  "parte_else", "read", "le_idents", "write", "escreve_expressoes",
  "comando_repetitivo", "$@14", "$@15", "variavel_atribuicao",
  "atribuicao_ou_procedimento", "chama_procedimento", "$@16",
  "lista_expressoes_ou_nada", "lista_expressoes_proc_function",
  "atribuicao", "lista_expressoes", "expressao", "expressao_simples",
  "termo", "fator", "variavel", "numero", "chamada_funcao", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-77)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -66,     5,     8,   -66,   -24,    15,   -21,   -66,    24,    19,
     -20,    26,   -66,    33,    43,   -66,    62,   -66,    66,    58,
     -66,    13,   -66,   -66,    58,   -66,    89,    53,   -66,    56,
      95,    96,    16,   -66,   -66,   -66,    94,   -66,   -66,    77,
     -66,   -66,   -66,   -66,    61,   -66,   -66,   -66,   -66,    29,
      16,    63,    16,    12,    12,    12,   -66,   -66,   -66,    52,
     -30,   -66,   -66,   -66,   -66,    16,    13,    93,    13,   -66,
      97,   -66,    64,    65,    84,   -66,    86,   -66,   103,   -30,
     -30,   -66,    85,    16,    16,    16,    16,    16,    16,    12,
      12,    12,    12,    12,    12,   -66,   -66,   -66,   -66,    16,
     -66,   -66,   107,   -66,   108,   -66,   -66,   -66,   -66,    16,
     -66,    63,   -66,   -66,    -2,    -2,    -2,    -2,    -2,    -2,
     -30,   -30,   -30,   -66,   -66,   -66,    87,     6,   -66,    16,
     -66,   -66,   106,   109,   -66,   -66,    13,    13,   -66,    88,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,    16,     7,   -66,
      73,    26,   -66,   -66,   -66,   -66,    67,   -66,   -66,   -66,
      73,    65,   -66,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,    39,     0,     0,
       0,    29,    38,     0,     5,    26,     0,     3,     0,    10,
      32,     0,     4,    12,     7,     9,     0,    28,    31,     0,
       0,     0,   103,    64,    67,    47,    44,    42,    49,    53,
      50,    51,    48,    45,     0,     8,    11,    30,    37,     0,
     103,     0,   103,   103,   103,   103,   102,   101,    54,    85,
      91,    95,    96,    98,    99,   103,    43,     0,     0,    52,
      70,    13,     0,     0,     0,    63,     0,    60,     0,    89,
      90,    97,     0,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,    65,    41,    40,    57,   103,
      46,    69,    73,    68,    18,    36,    35,    33,    61,   103,
      58,     0,   100,    55,    83,    84,    79,    80,    81,    82,
      86,    87,    88,    92,    93,    94,     0,   103,    78,   103,
      71,    16,     0,     0,    62,    59,     0,     0,    77,     0,
      75,    21,    14,    34,    56,    66,    72,   103,     0,    20,
       0,    29,    74,    17,    21,    25,     0,    24,    15,    19,
       0,     0,    23,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,   -66,   -34,   -66,   -66,   -66,    98,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -36,   -66,   -66,   -41,   -66,
     -66,   -66,   -66,    99,   -66,   -66,   -40,   -66,   -66,   102,
     -66,   -66,   -65,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -50,   -18,   -29,   -49,   -47,   -66,
     -66
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    13,    18,    19,    24,    25,    26,    44,
     104,   151,   132,   141,   148,   149,   150,   156,   157,    14,
      15,    16,    27,    28,    29,   133,   107,    49,     8,    35,
      36,    67,    37,    70,    38,    39,    82,   136,    69,    40,
      76,    41,    74,    42,    65,   126,    43,   100,   101,   102,
     130,   139,   103,   127,    58,    59,    60,    61,    62,    63,
      64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    96,    78,    98,    77,     3,    81,    92,    93,    94,
      52,     4,   153,   -76,   154,    95,    52,   -76,     5,     6,
      52,     7,    12,    21,    79,    80,    11,    30,    31,     9,
      10,   -76,    89,    90,    91,    72,    32,    73,   -27,    33,
      53,    54,    17,   123,   124,   125,    55,    56,    57,   128,
      53,    54,    55,    56,    57,    34,    55,    56,    57,   134,
     120,   121,   122,    -6,   135,   114,   115,   116,   117,   118,
     119,   144,   145,   160,    20,   161,    21,   138,    23,   140,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   108,
     109,   110,   111,   146,   147,   -32,    46,   152,    48,    50,
      51,    66,    68,    71,    97,    57,   105,   106,   112,   113,
      99,   129,   131,   142,   137,   155,   143,   158,   159,   162,
      22,   163,    45,     0,     0,     0,    47
};

static const yytype_int16 yycheck[] =
{
      50,    66,    52,    68,    51,     0,    55,    37,    38,    39,
       4,     3,     5,     7,     7,    65,     4,    11,    42,     4,
       4,    42,    42,    10,    53,    54,     7,    14,    15,     5,
       6,    25,    34,    35,    36,     6,    23,     8,    12,    26,
      34,    35,     9,    92,    93,    94,    40,    41,    42,    99,
      34,    35,    40,    41,    42,    42,    40,    41,    42,   109,
      89,    90,    91,    20,   111,    83,    84,    85,    86,    87,
      88,   136,   137,     6,    12,     8,    10,   127,    20,   129,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     5,
       6,     5,     6,     5,     6,    42,     7,   147,    42,     4,
       4,     7,    25,    42,    11,    42,    42,    42,     5,    24,
      13,     4,     4,     7,    27,    42,     7,   151,   154,   160,
      18,   161,    24,    -1,    -1,    -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,     0,     3,    42,     4,    42,    72,     5,
       6,     7,    42,    47,    63,    64,    65,     9,    48,    49,
      12,    10,    73,    20,    50,    51,    52,    66,    67,    68,
      14,    15,    23,    26,    42,    73,    74,    76,    78,    79,
      83,    85,    87,    90,    53,    51,     7,    67,    42,    71,
       4,     4,     4,    34,    35,    40,    41,    42,    98,    99,
     100,   101,   102,   103,   104,    88,     7,    75,    25,    82,
      77,    42,     6,     8,    86,    98,    84,   102,    98,   100,
     100,   101,    80,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    98,    76,    11,    76,    13,
      91,    92,    93,    96,    54,    42,    42,    70,     5,     6,
       5,     6,     5,    24,    99,    99,    99,    99,    99,    99,
     100,   100,   100,   101,   101,   101,    89,    97,    98,     4,
      94,     4,    56,    69,    98,   102,    81,    27,    98,    95,
      98,    57,     7,     7,    76,    76,     5,     6,    58,    59,
      60,    55,    98,     5,     7,    42,    61,    62,    47,    59,
       6,     8,    62,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    46,    45,    47,    48,    49,    48,    50,    50,
      51,    51,    53,    54,    55,    52,    57,    56,    56,    58,
      58,    60,    59,    61,    61,    62,    63,    65,    64,    64,
      66,    66,    68,    69,    67,    70,    71,    71,    72,    72,
      73,    74,    74,    75,    75,    77,    76,    76,    76,    76,
      76,    76,    78,    78,    80,    81,    79,    82,    83,    84,
      84,    85,    86,    86,    88,    89,    87,    90,    91,    91,
      93,    92,    94,    94,    95,    95,    96,    97,    97,    98,
      98,    98,    98,    98,    98,    98,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   100,   101,   101,   101,   101,
     101,   102,   103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     3,     0,     0,     2,     2,     1,
       0,     2,     0,     0,     0,     8,     0,     4,     0,     3,
       1,     0,     4,     3,     1,     1,     1,     0,     3,     0,
       2,     1,     0,     0,     6,     1,     3,     1,     3,     1,
       4,     3,     1,     1,     0,     0,     3,     1,     1,     1,
       1,     1,     2,     1,     0,     0,     6,     2,     4,     3,
       1,     4,     3,     1,     0,     0,     6,     1,     1,     1,
       0,     2,     3,     0,     3,     1,     2,     2,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     2,
       2,     1,     3,     3,     3,     1,     1,     2,     1,     1,
       3,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 59 "compilador.y"
             {
             geraCodigo (NULL, "INPP");
             }
#line 1513 "compilador.tab.c"
    break;

  case 3:
#line 64 "compilador.y"
                         {
             imprimeTabela(tabelaSimbolos);
             geraCodigo (NULL, "PARA");
             }
#line 1522 "compilador.tab.c"
    break;

  case 4:
#line 75 "compilador.y"
                     {
        imprimeTabela(tabelaSimbolos);
        int tamDmem = retiraElemPilha(pilhaDmem);
        retiraSimbolos(tabelaSimbolos, tamDmem);
        sprintf(comando, "DMEM %d", tamDmem);
        geraCodigo (NULL, comando);
    }
#line 1534 "compilador.tab.c"
    break;

  case 6:
#line 86 "compilador.y"
      {
        rotulosTam++;
        insereElemPilha(pilhaRotulos, rotulosTam);
        sprintf(comando, "DSVS R%02d", rotulosTam);
        geraCodigo(NULL, comando);
    }
#line 1545 "compilador.tab.c"
    break;

  case 7:
#line 93 "compilador.y"
    {   
        printf("pilhaRotulos: %d\n", pilhaRotulos->topo);
        if (pilhaRotulos->topo >= 0) {
            rotuloDesviaTrue = retiraElemPilha(pilhaRotulos);
            sprintf(comando, "R%02d:NADA", rotuloDesviaTrue);
            geraCodigo(NULL, comando);
        }
    }
#line 1558 "compilador.tab.c"
    break;

  case 12:
#line 115 "compilador.y"
              {
        deslocamento = 0;
        nivelLexico++;
        rotulosTam++;
        sprintf(comando, "R%02d:ENPR %d", rotulosTam, nivelLexico);
        geraCodigo(NULL, comando);
        
    }
#line 1571 "compilador.tab.c"
    break;

  case 13:
#line 123 "compilador.y"
          { 
        strncpy(ident_proc_funcao, token, TAM_MAX);
        Atributos *atributos = (Atributos*) malloc(sizeof(Atributos));
        strncpy(atributos->categoria, "proc", TAM_MAX);
        atributos->nivelLexico = nivelLexico;
        atributos->rotulo = rotulosTam;
        atributos->passagem = -1;
        insereSimbolo(tabelaSimbolos, ident_proc_funcao, atributos);

    }
#line 1586 "compilador.tab.c"
    break;

  case 14:
#line 134 "compilador.y"
    {
        insereElemPilha(pilhaParametros, numParams);
        atualizaDeslocamento(tabelaSimbolos, numParams);
        atualizaParametros(tabelaSimbolos, numParams, ident_proc_funcao);
    }
#line 1596 "compilador.tab.c"
    break;

  case 15:
#line 140 "compilador.y"
    {
        retiraSimbolos(tabelaSimbolos, retiraElemPilha(pilhaParametros));
        sprintf(comando, "RTPR %d, %d", nivelLexico, numParams);
        geraCodigo(NULL, comando);
        nivelLexico--;
    }
#line 1607 "compilador.tab.c"
    break;

  case 16:
#line 149 "compilador.y"
                    { numParams = 0; }
#line 1613 "compilador.tab.c"
    break;

  case 21:
#line 159 "compilador.y"
    { paramsPorTipo = 0; }
#line 1619 "compilador.tab.c"
    break;

  case 22:
#line 161 "compilador.y"
    {
        attParamsFormais(tabelaSimbolos, numTipo, valor, paramsPorTipo);
        imprimeTabela(tabelaSimbolos);
    }
#line 1628 "compilador.tab.c"
    break;

  case 23:
#line 169 "compilador.y"
    { numParams++; paramsPorTipo++; }
#line 1634 "compilador.tab.c"
    break;

  case 24:
#line 170 "compilador.y"
                       { numParams++; paramsPorTipo++; }
#line 1640 "compilador.tab.c"
    break;

  case 25:
#line 175 "compilador.y"
    {
        if (verificaExistencia(tabelaSimbolos, token)) {
            printf("Esse nome j?? est?? sendo usado!\n");
            exit(-1);
        }

        Atributos *atributos = (Atributos*) malloc(sizeof(Atributos));
        atributos->nivelLexico = nivelLexico;
        atributos->tipo = -1;
        atributos->passagem = -1;
        insereSimbolo(tabelaSimbolos, token, atributos);
    }
#line 1657 "compilador.tab.c"
    break;

  case 27:
#line 191 "compilador.y"
              { tamAmem = 0; }
#line 1663 "compilador.tab.c"
    break;

  case 28:
#line 192 "compilador.y"
            { /* AMEM */
                  sprintf(comando, "AMEM %d", tamAmem);
                  geraCodigo (NULL, comando);
                  insereElemPilha(pilhaDmem, tamAmem);
            }
#line 1673 "compilador.tab.c"
    break;

  case 32:
#line 204 "compilador.y"
              { }
#line 1679 "compilador.tab.c"
    break;

  case 33:
#line 207 "compilador.y"
              { 
                imprimeTabela(tabelaSimbolos);
                atualizaTipo(tabelaSimbolos, numTipo, tamAmem);
              }
#line 1688 "compilador.tab.c"
    break;

  case 35:
#line 215 "compilador.y"
              {
                if (!strcmp(token, "integer")){
                    numTipo = 0;
                } else if(!strcmp(token, "boolean")) {
                    numTipo = 1;
                }
              }
#line 1700 "compilador.tab.c"
    break;

  case 36:
#line 225 "compilador.y"
            { /* insere ???ltima vars na tabela de s???mbolos */
               Atributos *atributos = (Atributos*) malloc(sizeof(Atributos));
               strncpy(atributos->categoria, "vs", TAM_MAX);
               atributos->tipo = -1;
               atributos->nivelLexico = nivelLexico;
               atributos->deslocamento = deslocamento;
               atributos->passagem = -1;
               insereSimbolo(tabelaSimbolos, token, atributos);
               deslocamento++;
               tamAmem++;

            }
#line 1717 "compilador.tab.c"
    break;

  case 37:
#line 237 "compilador.y"
                    { /* insere vars na tabela de s???mbolos */
                Atributos *atributos = (Atributos*) malloc(sizeof(Atributos));
                strncpy(atributos->categoria, "vs", TAM_MAX);
                atributos->tipo = -1;
                atributos->nivelLexico = nivelLexico;
                atributos->deslocamento = deslocamento;
                atributos->passagem = -1;
                insereSimbolo(tabelaSimbolos, token, atributos);
                deslocamento++;
                tamAmem++;
            }
#line 1733 "compilador.tab.c"
    break;

  case 45:
#line 267 "compilador.y"
    {
        elemAtribuicao = simboloElem;
        elemAtribuicaoTipo = elemTipo;
    }
#line 1742 "compilador.tab.c"
    break;

  case 54:
#line 286 "compilador.y"
    {
        if (retiraElemPilha(pilhaExpressao) != 1) {
            printf("A express??o da condicional deve sempre retornar booleano!");
        }
        rotulosTam++;
        insereElemPilha(pilhaRotulos, rotulosTam);
        sprintf(comando, "DSVF R%02d", rotulosTam);
        geraCodigo(NULL, comando);
    }
#line 1756 "compilador.tab.c"
    break;

  case 55:
#line 295 "compilador.y"
         {
        rotulosTam++;
        insereElemPilha(pilhaRotulos, rotulosTam);
    }
#line 1765 "compilador.tab.c"
    break;

  case 56:
#line 298 "compilador.y"
              {
        rotuloDesviaTrue = retiraElemPilha(pilhaRotulos);
        rotuloDesviaFalse =  retiraElemPilha(pilhaRotulos);
        sprintf(comando, "DSVS R%02d", rotuloDesviaTrue);
        geraCodigo(NULL, comando);
        sprintf(comando, "R%02d:NADA", rotuloDesviaFalse);
        geraCodigo(NULL, comando);
        insereElemPilha(pilhaRotulos, rotuloDesviaTrue);
    }
#line 1779 "compilador.tab.c"
    break;

  case 57:
#line 310 "compilador.y"
                 {
        rotuloDesviaTrue = retiraElemPilha(pilhaRotulos);
        sprintf(comando, "R%02d:NADA", rotuloDesviaTrue);
        geraCodigo(NULL, comando);
    }
#line 1789 "compilador.tab.c"
    break;

  case 59:
#line 320 "compilador.y"
    {
        if (strcmp(elemento.atributos->categoria, "vs") == 0) {
            geraCodigo (NULL, "LEIT");
            sprintf(comando, "ARMZ %d, %d", elemento.atributos->nivelLexico, elemento.atributos->deslocamento);
            geraCodigo (NULL, comando);
        } else {
            printf("Esta vari??vel n??o ?? uma vari??vel simples para realizar leitura!");
            exit(-1);
        }
    }
#line 1804 "compilador.tab.c"
    break;

  case 60:
#line 331 "compilador.y"
    {
        if (strcmp(elemento.atributos->categoria, "vs") == 0) {
            geraCodigo (NULL, "LEIT");
            sprintf(comando, "ARMZ %d, %d", elemento.atributos->nivelLexico, elemento.atributos->deslocamento);
            geraCodigo (NULL, comando);
        } else {
            printf("Esta vari??vel n??o ?? uma vari??vel simples para realizar leitura!");
            exit(-1);
        }
    }
#line 1819 "compilador.tab.c"
    break;

  case 62:
#line 347 "compilador.y"
    {
        geraCodigo (NULL, "IMPR");
        retiraElemPilha(pilhaExpressao);
    }
#line 1828 "compilador.tab.c"
    break;

  case 63:
#line 352 "compilador.y"
    {
        geraCodigo (NULL, "IMPR");
        retiraElemPilha(pilhaExpressao);
    }
#line 1837 "compilador.tab.c"
    break;

  case 64:
#line 362 "compilador.y"
    {
        rotulosTam++;
        insereElemPilha(pilhaRotulos, rotulosTam);
        sprintf(rotulo, "R%02d:NADA", rotulosTam);
        geraCodigo(NULL, rotulo);
    }
#line 1848 "compilador.tab.c"
    break;

  case 65:
#line 369 "compilador.y"
    {
        if (retiraElemPilha(pilhaExpressao) != 1) {
            printf("Tipo da express??o condicional deve ser booleano\n");
        }
        rotulosTam++;
        insereElemPilha(pilhaRotulos, rotulosTam);
        sprintf(rotulo, "DSVF R%02d", rotulosTam);
        geraCodigo(NULL, rotulo);
    }
#line 1862 "compilador.tab.c"
    break;

  case 66:
#line 379 "compilador.y"
    {
        rotuloDesviaFalse = retiraElemPilha(pilhaRotulos);
        rotuloDesviaTrue = retiraElemPilha(pilhaRotulos);
        sprintf(comando, "DSVS R%02d", rotuloDesviaTrue);
        geraCodigo(NULL, comando);
        sprintf(comando, "R%02d:NADA", rotuloDesviaFalse);
        geraCodigo(NULL, comando);
    }
#line 1875 "compilador.tab.c"
    break;

  case 67:
#line 390 "compilador.y"
          {
        simboloElem = buscaSimbolo(tabelaSimbolos, token);
        elemTipo = simboloElem.atributos->tipo;
        imprimeSimbolo(simboloElem);
    }
#line 1885 "compilador.tab.c"
    break;

  case 70:
#line 403 "compilador.y"
    {
        if (strcmp(elemAtribuicao.atributos->categoria, "proc") != 0) {
            printf("A vari??vel precisa ser um procedimento\n");
            exit(-1);
        }
        insereElemPilha(pilhaRotulos, elemAtribuicao.atributos->rotulo);
    }
#line 1897 "compilador.tab.c"
    break;

  case 71:
#line 411 "compilador.y"
    {
        sprintf(comando, "CHPR R%02d, %d", retiraElemPilha(pilhaRotulos), nivelLexico);
        geraCodigo (NULL, comando);
    }
#line 1906 "compilador.tab.c"
    break;

  case 74:
#line 425 "compilador.y"
    {
        paramsPassados = retiraElemPilha(pilhaParamsPassados);
        insereElemPilha(pilhaParamsPassados, paramsPassados+1);
    }
#line 1915 "compilador.tab.c"
    break;

  case 75:
#line 431 "compilador.y"
    {
        paramsPassados = retiraElemPilha(pilhaParamsPassados);
        insereElemPilha(pilhaParamsPassados, paramsPassados+1);
    }
#line 1924 "compilador.tab.c"
    break;

  case 76:
#line 439 "compilador.y"
    {
        if (elemAtribuicaoTipo == retiraElemPilha(pilhaExpressao)) {
            sprintf(comando, "ARMZ %d, %d", elemAtribuicao.atributos->nivelLexico, elemAtribuicao.atributos->deslocamento);
            geraCodigo (NULL, comando);
        } else {
            printf("Tipo da vari??vel de atribui????o e valor a ser atribuido s??o diferentes!");
            exit(-1);
        }
    }
#line 1938 "compilador.tab.c"
    break;

  case 79:
#line 457 "compilador.y"
    { geraCodigo (NULL, "CMEG"); verificaTiposReturnBool(pilhaExpressao); }
#line 1944 "compilador.tab.c"
    break;

  case 80:
#line 459 "compilador.y"
    { geraCodigo (NULL, "CMAG"); verificaTiposReturnBool(pilhaExpressao); }
#line 1950 "compilador.tab.c"
    break;

  case 81:
#line 461 "compilador.y"
    { geraCodigo (NULL, "CMME"); verificaTiposReturnBool(pilhaExpressao); }
#line 1956 "compilador.tab.c"
    break;

  case 82:
#line 463 "compilador.y"
    { geraCodigo (NULL, "CMMA"); verificaTiposReturnBool(pilhaExpressao); }
#line 1962 "compilador.tab.c"
    break;

  case 83:
#line 465 "compilador.y"
    { geraCodigo (NULL, "CMIG"); verificaTiposReturnBool(pilhaExpressao); }
#line 1968 "compilador.tab.c"
    break;

  case 84:
#line 467 "compilador.y"
    { geraCodigo (NULL, "CMDG"); verificaTiposReturnBool(pilhaExpressao); }
#line 1974 "compilador.tab.c"
    break;

  case 86:
#line 472 "compilador.y"
                                 { geraCodigo (NULL, "SOMA");  verificaTipos(pilhaExpressao);  }
#line 1980 "compilador.tab.c"
    break;

  case 87:
#line 473 "compilador.y"
                                    { geraCodigo (NULL, "SUBT");  verificaTipos(pilhaExpressao); }
#line 1986 "compilador.tab.c"
    break;

  case 88:
#line 474 "compilador.y"
                                 { geraCodigo (NULL, "DISJ");  verificaTiposReturnBool(pilhaExpressao); }
#line 1992 "compilador.tab.c"
    break;

  case 89:
#line 475 "compilador.y"
                 { verificaTipos(pilhaExpressao); }
#line 1998 "compilador.tab.c"
    break;

  case 90:
#line 476 "compilador.y"
                  { geraCodigo (NULL, "INVR");  verificaTipos(pilhaExpressao); }
#line 2004 "compilador.tab.c"
    break;

  case 92:
#line 481 "compilador.y"
                      { geraCodigo (NULL, "MULT");  verificaTipos(pilhaExpressao); }
#line 2010 "compilador.tab.c"
    break;

  case 93:
#line 482 "compilador.y"
                      { geraCodigo (NULL, "DIVI");  verificaTipos(pilhaExpressao); }
#line 2016 "compilador.tab.c"
    break;

  case 94:
#line 483 "compilador.y"
                      { geraCodigo (NULL, "CONJ");  verificaTiposReturnBool(pilhaExpressao); }
#line 2022 "compilador.tab.c"
    break;

  case 96:
#line 490 "compilador.y"
    { 
        insereElemPilha(pilhaExpressao, elemTipo); 
        if ((strcmp(elemento.atributos->categoria, "vs") == 0) || (elemento.atributos->passagem == valor)) {
            sprintf(comando, "CRVL %d, %d", elemento.atributos->nivelLexico, elemento.atributos->deslocamento);
        }

        
        geraCodigo (NULL, comando);
    }
#line 2036 "compilador.tab.c"
    break;

  case 98:
#line 500 "compilador.y"
             { insereElemPilha(pilhaExpressao, 0); imprimePilha(pilhaExpressao); }
#line 2042 "compilador.tab.c"
    break;

  case 99:
#line 501 "compilador.y"
                     { }
#line 2048 "compilador.tab.c"
    break;

  case 101:
#line 507 "compilador.y"
              {
            elemento = buscaSimbolo(tabelaSimbolos, token);
            imprimeSimbolo(elemento);
            elemTipo = elemento.atributos->tipo;
        }
#line 2058 "compilador.tab.c"
    break;

  case 102:
#line 514 "compilador.y"
           { sprintf(comando, "CRCT %s", token); geraCodigo(NULL, comando); }
#line 2064 "compilador.tab.c"
    break;


#line 2068 "compilador.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 520 "compilador.y"


int main (int argc, char** argv) {
    FILE* fp;
    extern FILE* yyin;

    if (argc<2 || argc>2) {
            printf("usage compilador <arq>a %d\n", argc);
            return(-1);
        }

    fp=fopen (argv[1], "r");
    if (fp == NULL) {
        printf("usage compilador <arq>b\n");
        return(-1);
    }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S???mbolos
 * ------------------------------------------------------------------- */
    tabelaSimbolos = initTabela();
    pilhaExpressao = initPilha();
    pilhaRotulos = initPilha();
    pilhaDmem = initPilha();
    pilhaParametros = initPilha();
    pilhaParamsPassados = initPilha();

    yyin=fp;
    yyparse();

    return 0;
}
