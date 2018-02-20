/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "expr.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE tnode *
#include "expr.h"
#include "expr.c"
#include "lex.yy.c"

yydebug=0;
int yylex(void);
void yyerror(char const *s);
FILE *yyin,*target_file;
int type,temptype,retcount=0,flabel=1,mainflag=0,equiv=0,tuplesize=0;
char *tuplename;

#line 83 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    ID = 259,
    STRING = 260,
    PLUS = 261,
    MINUS = 262,
    MUL = 263,
    DIV = 264,
    MOD = 265,
    EQ = 266,
    INC = 267,
    DEC = 268,
    BEG = 269,
    END = 270,
    READ = 271,
    WRITE = 272,
    IF = 273,
    THEN = 274,
    ELSE = 275,
    ENDIF = 276,
    WHILE = 277,
    DO = 278,
    ENDWHILE = 279,
    BREAK = 280,
    CONTINUE = 281,
    REPEAT = 282,
    UNTIL = 283,
    DECL = 284,
    ENDDECL = 285,
    INT = 286,
    STR = 287,
    TUPLE = 288,
    MAIN = 289,
    RETURN = 290,
    BRKP = 291,
    EXIT = 292,
    AND = 293,
    OR = 294,
    LT = 295,
    LE = 296,
    GT = 297,
    GE = 298,
    EE = 299,
    NE = 300
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define STRING 260
#define PLUS 261
#define MINUS 262
#define MUL 263
#define DIV 264
#define MOD 265
#define EQ 266
#define INC 267
#define DEC 268
#define BEG 269
#define END 270
#define READ 271
#define WRITE 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define WHILE 277
#define DO 278
#define ENDWHILE 279
#define BREAK 280
#define CONTINUE 281
#define REPEAT 282
#define UNTIL 283
#define DECL 284
#define ENDDECL 285
#define INT 286
#define STR 287
#define TUPLE 288
#define MAIN 289
#define RETURN 290
#define BRKP 291
#define EXIT 292
#define AND 293
#define OR 294
#define LT 295
#define LE 296
#define GT 297
#define GE 298
#define EE 299
#define NE 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   367

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,     2,
      47,    48,     2,     2,    49,     2,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    39,    40,    41,    44,    45,    47,    48,
      49,    50,    51,    52,    53,    54,    52,    62,    63,    65,
      68,    71,    72,    73,    74,    75,    76,    78,    79,    78,
      83,    84,    83,    91,    92,    94,   100,   123,   124,    94,
     127,   128,   129,   130,   131,   136,   146,   147,   148,   149,
     150,   151,   152,   153,   155,   156,   159,   155,   168,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   202,   211,   212,
     213,   214,   215,   216,   217,   219,   230,   235,   240,   249,
     258
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "STRING", "PLUS", "MINUS",
  "MUL", "DIV", "MOD", "EQ", "INC", "DEC", "BEG", "END", "READ", "WRITE",
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "BREAK",
  "CONTINUE", "REPEAT", "UNTIL", "DECL", "ENDDECL", "INT", "STR", "TUPLE",
  "MAIN", "RETURN", "BRKP", "EXIT", "AND", "OR", "LT", "LE", "GT", "GE",
  "EE", "NE", "';'", "'('", "')'", "','", "'['", "']'", "'{'", "'}'",
  "'&'", "'.'", "$accept", "start", "Program", "GDeclBlock", "GDeclList",
  "GDecl", "Type", "$@1", "$@2", "$@3", "Tid", "tid", "GidList", "Gid",
  "$@4", "$@5", "$@6", "$@7", "FDefBlock", "FDef", "$@8", "$@9", "$@10",
  "$@11", "ParamList", "Param", "Pid", "LDeclBlock", "LDecList", "LDecl",
  "IdList", "Lid", "MainBlock", "$@12", "$@13", "$@14", "Body", "Slist",
  "Stmt", "Arth", "ArgList", "Bool", "id", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    59,    40,    41,    44,
      91,    93,   123,   125,    38,    46
};
# endif

#define YYPACT_NINF -133

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-133)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      99,    61,   -25,    37,  -133,    93,  -133,    -4,  -133,  -133,
      56,    73,  -133,    53,  -133,  -133,   -25,    65,    93,  -133,
    -133,  -133,  -133,    63,  -133,   -32,    97,   -20,  -133,    91,
      96,  -133,  -133,   110,  -133,  -133,   107,   115,  -133,    53,
      69,  -133,  -133,   121,   113,  -133,  -133,   131,   121,   121,
      55,   149,  -133,   152,   121,  -133,   123,   149,  -133,   200,
    -133,   121,   164,   211,   149,   201,  -133,   181,  -133,  -133,
    -133,   177,   184,   102,  -133,   186,    66,  -133,  -133,   187,
     238,   118,  -133,   237,  -133,  -133,   248,    51,  -133,  -133,
    -133,    70,  -133,   208,  -133,   143,   210,   201,  -133,  -133,
      66,  -133,   238,  -133,   -33,     4,   222,   225,     1,   226,
     231,   239,   224,   236,   239,    48,   241,   245,     4,   159,
    -133,   258,  -133,  -133,  -133,  -133,    68,   279,  -133,  -133,
       4,   246,    48,    48,    48,   263,  -133,  -133,   183,  -133,
     -11,  -133,    48,   305,  -133,  -133,  -133,  -133,   249,  -133,
      48,   237,   233,    78,  -133,   268,  -133,   295,   319,   275,
     276,   247,   250,    42,   300,    48,    48,    48,    48,    48,
    -133,  -133,   312,   243,   285,  -133,   290,   291,    48,    48,
      48,    48,    48,    48,   320,   315,    48,    48,  -133,   324,
     144,  -133,   180,   180,  -133,  -133,  -133,  -133,  -133,   337,
    -133,  -133,   324,   324,   324,   324,   324,   324,   239,   239,
     293,   294,  -133,    48,   296,   119,   199,   -18,   298,   324,
    -133,   239,   299,   303,  -133,  -133,   223,  -133,  -133,   304,
    -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     0,     5,     0,    11,    12,
       0,     0,     9,     0,    54,     1,    11,     0,     0,    34,
       4,     7,    13,     0,     8,    23,     0,     0,    22,     0,
       0,    33,     3,     0,     6,    27,     0,    26,    10,     0,
       0,    35,    14,    42,     0,    30,    21,     0,    42,    42,
       0,    28,    41,    24,    42,    55,     0,    15,    44,     0,
      43,     0,     0,     0,    31,     0,    36,     0,    45,    40,
      29,     0,     0,     0,    56,     0,     0,    25,    32,     0,
       0,     0,    49,     0,    37,    19,     0,     0,    18,    47,
      53,     0,    52,     0,    48,     0,     0,     0,    20,    16,
       0,    50,     0,    46,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,    57,    38,    17,    51,     0,     0,    98,    59,
       0,     0,     0,     0,     0,     0,    71,    72,     0,    82,
      95,    83,     0,     0,    84,    74,    75,    99,     0,    60,
       0,     0,    82,     0,   100,     0,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    58,     0,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    88,
       0,    81,    76,    77,    78,    79,    80,    65,    39,     0,
      62,    63,    89,    90,    91,    92,    93,    94,     0,     0,
       0,     0,    86,     0,     0,     0,     0,     0,     0,    87,
      97,     0,     0,     0,    70,    69,     0,    67,    68,     0,
      66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,  -133,  -133,   335,     2,  -133,  -133,  -133,
    -133,   252,  -133,   314,  -133,  -133,  -133,  -133,  -133,   336,
    -133,  -133,  -133,  -133,   -16,   306,  -133,   259,  -133,   274,
    -133,   255,    16,  -133,  -133,  -133,   214,  -110,  -108,  -101,
    -133,  -132,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    11,    12,    50,    33,    49,    67,
      87,    88,    27,    28,    43,    62,    54,    72,    18,    19,
      48,    75,    97,   151,    51,    52,    60,    74,    81,    82,
      91,    92,     6,    29,    65,    83,    96,   119,   120,   158,
     190,   159,   144
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     121,   135,   160,    13,   138,   209,   131,    17,   104,    14,
     128,   149,   105,    13,   143,    35,   121,   126,    36,   121,
      17,    20,   127,   147,   121,   153,    38,   149,   224,    39,
     149,   157,    56,    57,    32,   155,   163,    15,    64,   126,
     121,   164,    21,   121,   127,   139,   140,   141,   132,   172,
     105,   139,   140,   141,   210,   211,   105,    25,   118,    58,
      22,    26,   189,    59,   192,   193,   194,   195,   196,    30,
      85,   152,   140,   141,    86,    80,   105,   202,   203,   204,
     205,   206,   207,    80,   165,   166,   167,   168,   169,   142,
     188,     7,     8,     9,    10,   142,   118,    99,   215,   216,
     100,    37,   118,    23,     8,     9,    10,   149,   149,    34,
      44,   226,   219,   121,   121,   142,   101,    47,   149,   102,
     121,   121,   118,   104,    16,     9,   121,   105,     1,   175,
       2,   121,    79,     8,     9,   107,   108,   109,    40,   221,
     222,   110,   111,    41,   112,   113,   114,   104,    93,     8,
       9,   105,     8,     9,   115,   116,   117,    42,   106,   107,
     108,   109,    45,   104,    53,   110,   111,   105,   112,   113,
     114,    66,    61,   118,   148,   107,   108,   109,   115,   116,
     117,   110,   111,    55,   112,   113,   114,   104,   167,   168,
     169,   105,   212,   213,   115,   116,   117,   118,    61,   107,
     108,   109,    63,   104,    68,   110,   111,   105,   112,   113,
     114,   162,    70,   118,    71,   107,   108,   109,   115,   116,
     117,   110,   111,   223,   112,   113,   114,   104,    77,    76,
      73,   105,    78,    89,   115,   116,   117,   118,    84,   107,
     108,   109,    90,   104,   229,   110,   111,   105,   112,   113,
     114,    95,    98,   118,   103,   107,   108,   109,   115,   116,
     117,   110,   111,   122,   112,   113,   114,   104,   129,   150,
     136,   105,   130,   133,   115,   116,   117,   118,   134,   107,
     108,   109,   137,   154,   174,   161,   111,   145,   112,   113,
     114,   146,   156,   118,   186,   171,   198,   187,   115,   116,
     117,   165,   166,   167,   168,   169,   165,   166,   167,   168,
     169,   165,   166,   167,   168,   169,   176,   118,   165,   166,
     167,   168,   169,   184,   185,   165,   166,   167,   168,   169,
     165,   166,   167,   168,   169,   199,   200,   201,   209,   208,
     214,   217,   218,   177,   225,   227,    24,   220,   191,   228,
     230,   170,   124,    46,    31,    94,   123,   125,   197,   178,
     179,   180,   181,   182,   183,   173,     0,    69
};

static const yytype_int16 yycheck[] =
{
      95,   111,   134,     1,   114,    23,     5,     5,     4,    34,
     105,   119,     8,    11,   115,    47,   111,    50,    50,   114,
      18,     5,    55,   118,   119,   126,    46,   135,    46,    49,
     138,   132,    48,    49,    18,   130,    47,     0,    54,    50,
     135,   142,    46,   138,    55,     3,     4,     5,    47,   150,
       8,     3,     4,     5,   186,   187,     8,     4,    54,     4,
       4,     8,   163,     8,   165,   166,   167,   168,   169,     4,
       4,     3,     4,     5,     8,    73,     8,   178,   179,   180,
     181,   182,   183,    81,     6,     7,     8,     9,    10,    47,
      48,    30,    31,    32,    33,    47,    54,    46,   208,   209,
      49,     4,    54,    30,    31,    32,    33,   215,   216,    46,
       3,   221,   213,   208,   209,    47,    46,    48,   226,    49,
     215,   216,    54,     4,    31,    32,   221,     8,    29,    51,
      31,   226,    30,    31,    32,    16,    17,    18,    47,    20,
      21,    22,    23,    47,    25,    26,    27,     4,    30,    31,
      32,     8,    31,    32,    35,    36,    37,    47,    15,    16,
      17,    18,    47,     4,    51,    22,    23,     8,    25,    26,
      27,    48,    49,    54,    15,    16,    17,    18,    35,    36,
      37,    22,    23,    52,    25,    26,    27,     4,     8,     9,
      10,     8,    48,    49,    35,    36,    37,    54,    49,    16,
      17,    18,    50,     4,     4,    22,    23,     8,    25,    26,
      27,    28,    48,    54,     3,    16,    17,    18,    35,    36,
      37,    22,    23,    24,    25,    26,    27,     4,    51,    48,
      29,     8,    48,    46,    35,    36,    37,    54,    52,    16,
      17,    18,     4,     4,    21,    22,    23,     8,    25,    26,
      27,    14,     4,    54,    46,    16,    17,    18,    35,    36,
      37,    22,    23,    53,    25,    26,    27,     4,    46,    11,
      46,     8,    47,    47,    35,    36,    37,    54,    47,    16,
      17,    18,    46,     4,    51,    22,    23,    46,    25,    26,
      27,    46,    46,    54,    47,    46,    53,    47,    35,    36,
      37,     6,     7,     8,     9,    10,     6,     7,     8,     9,
      10,     6,     7,     8,     9,    10,    48,    54,     6,     7,
       8,     9,    10,    48,    48,     6,     7,     8,     9,    10,
       6,     7,     8,     9,    10,    50,    46,    46,    23,    19,
       3,    48,    48,    48,    46,    46,    11,    51,    48,    46,
      46,    46,   100,    39,    18,    81,    97,   102,    46,    40,
      41,    42,    43,    44,    45,   151,    -1,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    31,    57,    58,    59,    88,    30,    31,    32,
      33,    60,    61,    62,    34,     0,    31,    62,    74,    75,
      88,    46,     4,    30,    61,     4,     8,    68,    69,    89,
       4,    75,    88,    63,    46,    47,    50,     4,    46,    49,
      47,    47,    47,    70,     3,    47,    69,    48,    76,    64,
      62,    80,    81,    51,    72,    52,    80,    80,     4,     8,
      82,    49,    71,    50,    80,    90,    48,    65,     4,    81,
      48,     3,    73,    29,    83,    77,    48,    51,    48,    30,
      62,    84,    85,    91,    52,     4,     8,    66,    67,    46,
       4,    86,    87,    30,    85,    14,    92,    78,     4,    46,
      49,    46,    49,    46,     4,     8,    15,    16,    17,    18,
      22,    23,    25,    26,    27,    35,    36,    37,    54,    93,
      94,    98,    53,    83,    67,    87,    50,    55,    98,    46,
      47,     5,    47,    47,    47,    93,    46,    46,    93,     3,
       4,     5,    47,    95,    98,    46,    46,    98,    15,    94,
      11,    79,     3,    95,     4,    98,    46,    95,    95,    97,
      97,    22,    28,    47,    95,     6,     7,     8,     9,    10,
      46,    46,    95,    92,    51,    51,    48,    48,    40,    41,
      42,    43,    44,    45,    48,    48,    47,    47,    48,    95,
      96,    48,    95,    95,    95,    95,    95,    46,    53,    50,
      46,    46,    95,    95,    95,    95,    95,    95,    19,    23,
      97,    97,    48,    49,     3,    93,    93,    48,    48,    95,
      51,    20,    21,    24,    46,    46,    93,    46,    46,    21,
      46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    59,    59,    60,    60,
      61,    62,    62,    63,    64,    65,    61,    66,    66,    67,
      67,    68,    68,    69,    69,    69,    69,    70,    71,    69,
      72,    73,    69,    74,    74,    76,    77,    78,    79,    75,
      80,    80,    80,    81,    82,    82,    83,    83,    84,    84,
      85,    86,    86,    87,    89,    90,    91,    88,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    96,    96,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    98,    98,
      98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     1,     4,     3,     2,     1,
       3,     1,     1,     0,     0,     0,    10,     3,     1,     1,
       2,     3,     1,     1,     4,     7,     2,     0,     0,     6,
       0,     0,     7,     2,     1,     0,     0,     0,     0,    13,
       3,     1,     0,     2,     1,     2,     4,     3,     2,     1,
       3,     3,     1,     1,     0,     0,     0,    11,     4,     3,
       2,     1,     5,     5,     3,     4,    10,     8,     8,     7,
       7,     2,     2,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     3,     4,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     4,     7,     2,     2,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 3:
#line 39 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 40 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 41 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 44 "expr.y" /* yacc.c:1646  */
    {generate(target_file);gother();}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 45 "expr.y" /* yacc.c:1646  */
    {generate(target_file);puts("No Global declared!");}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 47 "expr.y" /* yacc.c:1646  */
    {}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 48 "expr.y" /* yacc.c:1646  */
    {}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 49 "expr.y" /* yacc.c:1646  */
    {}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 50 "expr.y" /* yacc.c:1646  */
    {type=t_INT;}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 51 "expr.y" /* yacc.c:1646  */
    {type=t_CHAR;}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 52 "expr.y" /* yacc.c:1646  */
    {tuplename=(yyvsp[0])->str;}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 53 "expr.y" /* yacc.c:1646  */
    {phead=NULL;}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 54 "expr.y" /* yacc.c:1646  */
    {	struct Paramstruct* ptemp=phead;
										tuplesize=0;
										while(ptemp){
											tuplesize++;
											ptemp=ptemp->next;
										}}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 65 "expr.y" /* yacc.c:1646  */
    {	GInstall((yyvsp[0])->str,t_TUPLE,tuplesize);
										GLookup((yyvsp[0])->str)->paramlist=phead;
										GLookup((yyvsp[0])->str)->tuplename=strdup(tuplename);}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 68 "expr.y" /* yacc.c:1646  */
    {	GInstall((yyvsp[0])->str,t_TUPPTR,tuplesize);
										GLookup((yyvsp[0])->str)->paramlist=phead;
										GLookup((yyvsp[0])->str)->tuplename=strdup(tuplename);}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 73 "expr.y" /* yacc.c:1646  */
    {GInstall((yyvsp[0])->str,type,1);}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 74 "expr.y" /* yacc.c:1646  */
    {int t=type;type=type==t_INT?t_INARR:t_CHARR;GInstall((yyvsp[-3])->str,type,(yyvsp[-1])->num);type=t;}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 75 "expr.y" /* yacc.c:1646  */
    {int t=type;type=type==t_INT?t_INARR:t_CHARR;GInstall((yyvsp[-6])->str,type,(yyvsp[-4])->num*(yyvsp[-1])->num);type=t;GLookup((yyvsp[-6])->str)->arr=(yyvsp[-4])->num;}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 76 "expr.y" /* yacc.c:1646  */
    {int t=type;type=type==t_INT?t_INPTR:t_CHPTR;GInstall((yyvsp[0])->str,type,1);type=t;}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 78 "expr.y" /* yacc.c:1646  */
    {phead=NULL;temptype=type;}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 79 "expr.y" /* yacc.c:1646  */
    {type=temptype;}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 80 "expr.y" /* yacc.c:1646  */
    {	GInstall((yyvsp[-5])->str,type,0);
										GLookup((yyvsp[-5])->str)->paramlist=phead;
										GLookup((yyvsp[-5])->str)->flabel=flabel++;}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 83 "expr.y" /* yacc.c:1646  */
    {phead=NULL;temptype=type;}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 84 "expr.y" /* yacc.c:1646  */
    {type=temptype;}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 85 "expr.y" /* yacc.c:1646  */
    {	int t=type;type=type==t_INT?t_INPTR:t_CHPTR;
											GInstall((yyvsp[-5])->str,type,0);
											GLookup((yyvsp[-5])->str)->paramlist=phead;
											GLookup((yyvsp[-5])->str)->flabel=flabel++;type=t;}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 94 "expr.y" /* yacc.c:1646  */
    {	check((yyvsp[-1]));
							funcname=(yyvsp[-1])->str;
							binding=-2;
							lhead=NULL;
							phead=NULL;
							equiv=1;}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 100 "expr.y" /* yacc.c:1646  */
    {	equiv=0;
										struct Lsymbol *ltemp;
										struct Paramstruct *ptemp;
										ptemp=GLookup((yyvsp[-4])->str)->paramlist;
										ltemp=lhead;
										while(ptemp && ltemp){
											if(/*ptemp->type!=ltemp->type || */strcmp(ptemp->name,ltemp->name)!=0){
												printf("line:%d\nParameter Globally Declared:\tname:'%s'\ttype:'%d'\nParameter Locally Declared:\tname:'%s'\ttype:'%d'\n",line,ptemp->name,ptemp->type,ltemp->name,ltemp->type);
												exit(1);}
											ptemp=ptemp->next;
											ltemp=ltemp->next;}
										if(ptemp!=NULL || ltemp!=NULL){
											if(ptemp!=NULL){
												printf("line:%d\tExtra Global Parameters Declared...\n",line);
												while(ptemp!=NULL){
													printf("name:'%s'\ttype:'%d'\n",ptemp->name,ptemp->type);
													ptemp=ptemp->next;}}
											else{
												printf("line:%d\tExtra Local Parameters Declared...\n",line);
												while(ltemp!=NULL){
													printf("name:'%s'\ttype:'%d'\n",ltemp->name,ltemp->type);
													ltemp=ltemp->next;}}
											exit(1);}}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 123 "expr.y" /* yacc.c:1646  */
    {	binding=0;}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 124 "expr.y" /* yacc.c:1646  */
    {lother();}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 127 "expr.y" /* yacc.c:1646  */
    {}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 131 "expr.y" /* yacc.c:1646  */
    {if(equiv==1){
							binding--;
							LInstall((yyvsp[0])->str,type);}
						else
							PInstall((yyvsp[0])->str,type);}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 136 "expr.y" /* yacc.c:1646  */
    {if(equiv==1){
							binding--;
							int t=type;
							type=type==t_INT?t_INPTR:t_CHPTR;
							LInstall((yyvsp[0])->str,type);
							type=t;}
						else
							{int t=type;type=type==t_INT?t_INPTR:t_CHPTR;PInstall((yyvsp[0])->str,type);type=t;}}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 153 "expr.y" /* yacc.c:1646  */
    {binding++;LInstall((yyvsp[0])->str,type);}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 155 "expr.y" /* yacc.c:1646  */
    {	binding=0;}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 156 "expr.y" /* yacc.c:1646  */
    {	funcname="main";
												lhead=NULL;
		 										binding=0;}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 159 "expr.y" /* yacc.c:1646  */
    {lother();}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 168 "expr.y" /* yacc.c:1646  */
    {//$$=$2;
									if(retcount==0){
										printf("No return statements found!\n");}
									funcGen(GLookup(funcname),target_file);
 									codeGen((yyvsp[-2]),target_file);retcount=0;}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 173 "expr.y" /* yacc.c:1646  */
    {(yyval)=NULL;printf("No Body!\n");}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 174 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_NODE,(yyvsp[-1]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 175 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 176 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_READ,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 177 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_WRITE,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 178 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_WRITE,NULL,(yyvsp[-1]),NULL,NULL,NULL,NULL);}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 179 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_ASGN,(yyvsp[-3]),NULL,(yyvsp[-1]),NULL,NULL,NULL);}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 180 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_IFELSE,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]),NULL,NULL,NULL);}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 181 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_IF,(yyvsp[-5]),NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 182 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_WHILE,(yyvsp[-5]),NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 183 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_WHILE,(yyvsp[-2]),NULL,(yyvsp[-5]),NULL,NULL,NULL);}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 184 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_WHILE,(yyvsp[-2]),NULL,(yyvsp[-5]),NULL,NULL,NULL);}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 185 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_BREAK,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 186 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_CONTINUE,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 187 "expr.y" /* yacc.c:1646  */
    {retcount++;(yyval)=createtree(GLookup(funcname)->type,NULL,NULL,nt_RET,NULL,(yyvsp[-1]),NULL,NULL,NULL,NULL);}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 188 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_BRKP,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 189 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_NULL,NULL,NULL,nt_EXIT,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 190 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_INT,NULL,NULL,nt_PLUS,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 191 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_INT,NULL,NULL,nt_MINUS,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 192 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_INT,NULL,NULL,nt_MUL,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 193 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_INT,NULL,NULL,nt_DIV,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 194 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(t_INT,NULL,NULL,nt_MOD,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 195 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 196 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 197 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 198 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 199 "expr.y" /* yacc.c:1646  */
    {check((yyvsp[-2]));(yyval)=createtree(GLookup((yyvsp[-2])->str)->type,NULL,(yyvsp[-2])->str,nt_FUNC,NULL,NULL,NULL,GLookup((yyvsp[-2])->str),NULL,NULL);q=(yyval);}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 200 "expr.y" /* yacc.c:1646  */
    {check((yyvsp[-3]));
									(yyval)=createtree(GLookup((yyvsp[-3])->str)->type,NULL,(yyvsp[-3])->str,nt_FUNC,NULL,NULL,NULL,GLookup((yyvsp[-3])->str),(yyvsp[-1]),NULL);}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 202 "expr.y" /* yacc.c:1646  */
    {	(yyvsp[0])->down=(yyvsp[-2]);
										(yyval)=(yyvsp[0]);
										/*
										struct tnode *t=$1;
										while(t->down!=NULL)
											t=t->down;
										t->down=$3;
										$$=$1;
										*/}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 211 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 212 "expr.y" /* yacc.c:1646  */
    {(yyval) =createtree(t_BOOL,NULL,NULL,nt_LT,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 213 "expr.y" /* yacc.c:1646  */
    {(yyval) =createtree(t_BOOL,NULL,NULL,nt_LE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 214 "expr.y" /* yacc.c:1646  */
    {(yyval) =createtree(t_BOOL,NULL,NULL,nt_GT,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 215 "expr.y" /* yacc.c:1646  */
    {(yyval) =createtree(t_BOOL,NULL,NULL,nt_GE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 216 "expr.y" /* yacc.c:1646  */
    {(yyval) =createtree(t_BOOL,NULL,NULL,nt_EE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 217 "expr.y" /* yacc.c:1646  */
    {(yyval) =createtree(t_BOOL,NULL,NULL,nt_NE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 219 "expr.y" /* yacc.c:1646  */
    {check((yyvsp[0]));
										if(LLookup((yyvsp[0])->str)==NULL){//Global
											int t=GLookup((yyvsp[0])->str)->type,nt;
											if(t==t_INPTR || t==t_CHPTR){t=t==t_INPTR?t_INT:t_CHAR;nt=nt_PTR;}
											else nt=nt_ID;
											(yyval)=createtree(t,NULL,(yyvsp[0])->str,nt,NULL,NULL,NULL,GLookup((yyvsp[0])->str),NULL,NULL);}
										else{//Local
											int t=LLookup((yyvsp[0])->str)->type,nt;
											if(t==t_INPTR || t==t_CHPTR){t=t==t_INPTR?t_INT:t_CHAR;nt=nt_PTR;}
											else nt=nt_ID;
											(yyval)=createtree(t,NULL,(yyvsp[0])->str,nt,NULL,NULL,NULL,NULL,NULL,LLookup((yyvsp[0])->str));}}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 230 "expr.y" /* yacc.c:1646  */
    {check((yyvsp[-3]));
										int t=GLookup((yyvsp[-2])->str)->type;
										if(t!=t_INARR && t!=t_CHARR)printf("\tSomething's wrong!--arr[1D]\tline:%d\tt=t_%d\n",line,t);
										t=t==t_INARR?t_INT:t_CHAR;
										(yyval)=createtree(t,(yyvsp[-1])->num,(yyvsp[-3])->str,nt_ARR,NULL,(yyvsp[-1]),NULL,GLookup((yyvsp[-3])->str),NULL,NULL);}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 235 "expr.y" /* yacc.c:1646  */
    {check((yyvsp[-6]));
										int t=GLookup((yyvsp[-5])->str)->type;
										if(t!=t_INARR && t!=t_CHARR)printf("\tSomething's wrong!--arr[2D]\tline:%d\tt=t_%d\n",line,t);
										t=t_INARR?t_INT:t_CHAR;
										(yyval)=createtree(t,(GLookup((yyvsp[-6])->str)->arr)*((yyvsp[-4])->num)+((yyvsp[-1])->num),(yyvsp[-6])->str,nt_ARR,NULL,NULL,NULL,GLookup((yyvsp[-6])->str),NULL,NULL);}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 240 "expr.y" /* yacc.c:1646  */
    {if(LLookup((yyvsp[0])->str)==NULL){
											int t=GLookup((yyvsp[0])->str)->type;
											if(t!=t_INPTR && t!=t_CHPTR)printf("\tSomething's wrong!--*\tline:%d\tt=t_%d\n",line,t);
											t=t_INPTR?t_INT:t_CHAR;
											(yyval)=createtree(t,(yyvsp[0])->num,(yyvsp[0])->str,nt_SPTR,NULL,NULL,NULL,GLookup((yyvsp[0])->str),NULL,NULL);}
										else{int t=LLookup((yyvsp[0])->str)->type;
											if(t!=t_INPTR && t!=t_CHPTR)printf("\tSomething's wrong!--*\tline:%d\tt=t_%d\n",line,t);
											t=t_INPTR?t_INT:t_CHAR;
											(yyval)=createtree(t,(yyvsp[0])->num,(yyvsp[0])->str,nt_SPTR,NULL,NULL,NULL,NULL,NULL,LLookup((yyvsp[-1])->str));}}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 249 "expr.y" /* yacc.c:1646  */
    {if(LLookup((yyvsp[0])->str)==NULL){
											int t=GLookup((yyvsp[0])->str)->type;
											if(t==t_INARR || t==t_CHARR)t=t==t_INARR?t_INT:t_CHAR;
											else if(t!=t_INT && t!=t_CHAR)printf("\tSomething's wrong!--&\tline:%d\tt=t_%d\n",line,t);
											(yyval)=createtree(t,(yyvsp[0])->num,(yyvsp[0])->str,nt_APTR,NULL,NULL,NULL,GLookup((yyvsp[0])->str),NULL,NULL);}
										else{int t=LLookup((yyvsp[0])->str)->type;
											if(t==t_INARR || t==t_CHARR)t=t==t_INARR?t_INT:t_CHAR;
											else if(t!=t_INT && t!=t_CHAR)printf("\tSomething's wrong!--&\tline:%d\tt=t_%d\n",line,t);
											(yyval)=createtree(t,(yyvsp[0])->num,(yyvsp[0])->str,nt_APTR,NULL,NULL,NULL,NULL,NULL,LLookup((yyvsp[-1])->str));}}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 258 "expr.y" /* yacc.c:1646  */
    {check1((yyvsp[-2]),(yyvsp[0]));
										struct  Paramstruct *ptemp=GLookup((yyvsp[-2])->str)->paramlist;
										int t,count=0;
										while(ptemp){
											if(strcmp(ptemp->name,(yyvsp[0])->str)==0){
													t=ptemp->type;}
											count++;
											ptemp=ptemp->next;}
										(yyval)=createtree(t,GLookup((yyvsp[-2])->str)->size-count,(yyvsp[0])->str,nt_ID,NULL,NULL,NULL,GLookup((yyvsp[-2])->str),NULL,NULL);}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2069 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 267 "expr.y" /* yacc.c:1906  */


void check(struct tnode *t){
	if(LLookup(t->str)==NULL && GLookup(t->str)==NULL){
		printf("Undeclared identifier:'%s' at line:'%d'\n",t->str,line);
		exit(1);}
}

void check1(struct tnode *t1,struct tnode *t3){
	if(GLookup(t1->str)==NULL){
		printf("Undeclared tuple identifier:'%s' at line:'%d'\n",t1->str,line);
		exit(1);}
	struct Paramstruct *ptemp;
	ptemp=GLookup(t1->str)->paramlist;
	while(ptemp){
		if(strcmp(ptemp->name,t3->str)==0)
			return;
		ptemp=ptemp->next;}
	if(!ptemp){
		printf("No member '%s' in tuple '%s' at line:'%d'\n",t3->str,t1->str,line);
		exit(1);}}

void yyerror(char const *s)
{
	printf("yyerror %s\nLine:%d at '%s'\n",s,line,yytext);
	exit(1);
}

void func(struct Paramstruct* phead){
	struct Paramstruct* temp=phead;
	while(temp!=NULL){
		printf("name:'%s'\ttype:'%d'\t\n",temp->name,temp->type);
		temp=temp->next;}
}

void gother(){
	int i,j;
	printf("\t\tGlobal Table(Static size:'%d')\n",gbinding-4096);
	struct Gsymbol* gtemp=ghead;
	struct Paramstruct* ptemp;
	puts("GLOBALS...");
	i=1;
	while(gtemp!=NULL){
		if(gtemp->size>0){
			printf("%d.name:'%s'\ttype:'%d'\tsize:'%d'\tarr:%d\n",i++,gtemp->name,gtemp->type,gtemp->size,gtemp->arr);
		if(gtemp->paramlist){
			ptemp=gtemp->paramlist;
			printf("\tContent of tuple...\n");
			while(ptemp){
				printf("\tname:'%s'\ttype:'%d'\n",ptemp->name,ptemp->type);
				ptemp=ptemp->next;}}}
			puts("");
		gtemp=gtemp->next;}
	gtemp=ghead;
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	puts("functions");
	i=1;
	while(gtemp!=NULL){
		if(gtemp->size==0){
			printf("%d.name:'%s'\ttype:'%d'\tflabel:'%d'\n",i++,gtemp->name,gtemp->type,gtemp->flabel);
			ptemp=gtemp->paramlist;
			puts("\tparameters");
			j=1;
			while(ptemp){
				printf("\t%d.name:'%s'\ttype:'%d'\n",j,ptemp->name,ptemp->type);
				ptemp=ptemp->next;}
			puts("");}
		gtemp=gtemp->next;}
	puts("######################################################");
}

void lother(){
	int i;
	printf("\t\tLocal Table('%s')\n",funcname);
	int count=0;
	struct Lsymbol* ltemp=lhead;
	puts("LOCALS...");
	i=1;
	while(ltemp!=NULL){
		count++;
		printf("%d.name:'%s'\ttype:'%d'\tbinding:'%d'\n",i++,ltemp->name,ltemp->type,ltemp->binding);
		if(ltemp->binding==1){puts("\narguments");i=1;}
		ltemp=ltemp->next;}
	puts("######################################################");
}

void n(int n){printf("~~~%d~~~\n",n);}
void c(char c){printf("~~~%c~~~\n",c);}
void s(char *s){printf("~~~%s~~~\n",s);}

int main(void)
{
	ghead=NULL;
	FILE *fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else
		printf("Input file error\n");
	target_file=fopen("intermediate.xsm","w+");
	GInstall("main",t_INT,0);
	GLookup("main")->flabel=1000;
	yyparse();

//	other();
	return 0;
}

