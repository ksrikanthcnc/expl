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
	//#include "expr.h"
	#include "expr.c"
	#include "lex.yy.c"

	int yydebug=0;
	//int yylex(void);
	//void yyerror(char const *s);
	FILE *yyin;
	int reg;
	int flabel=1,mainflag=0,equiv=0,tuplesize=0,typesize=0,fieldindex,initflag=0,allocflag=0;
	struct Typetable *type,*temptype,*t;
	char *tuplename;

#line 85 "y.tab.c" /* yacc.c:339  */

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
    TYPE = 284,
    ENDTYPE = 285,
    DECL = 286,
    ENDDECL = 287,
    INT = 288,
    STR = 289,
    TUPLE = 290,
    MAIN = 291,
    RETURN = 292,
    BRKP = 293,
    EXIT = 294,
    AND = 295,
    OR = 296,
    INIT = 297,
    ALLOC = 298,
    FREE = 299,
    LT = 300,
    LE = 301,
    GT = 302,
    GE = 303,
    EE = 304,
    NE = 305
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
#define TYPE 284
#define ENDTYPE 285
#define DECL 286
#define ENDDECL 287
#define INT 288
#define STR 289
#define TUPLE 290
#define MAIN 291
#define RETURN 292
#define BRKP 293
#define EXIT 294
#define AND 295
#define OR 296
#define INIT 297
#define ALLOC 298
#define FREE 299
#define LT 300
#define LE 301
#define GT 302
#define GE 303
#define EE 304
#define NE 305

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

#line 236 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   431

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  244

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,     2,
      57,    58,     2,     2,    54,     2,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    39,    39,    40,    41,    42,    43,    44,    45,    48,
      49,    50,    51,    52,    51,    55,    56,    58,    58,    64,
      65,    66,    69,    70,    72,    73,    74,    75,    99,   100,
     101,   106,   118,   119,   118,   123,   124,   123,   138,   139,
     141,   147,   170,   171,   141,   174,   175,   176,   177,   178,
     183,   208,   209,   210,   211,   212,   213,   214,   215,   217,
     218,   222,   217,   227,   237,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   283,   285,   288,   289,   299,   300,   303
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
  "CONTINUE", "REPEAT", "UNTIL", "TYPE", "ENDTYPE", "DECL", "ENDDECL",
  "INT", "STR", "TUPLE", "MAIN", "RETURN", "BRKP", "EXIT", "AND", "OR",
  "INIT", "ALLOC", "FREE", "LT", "LE", "GT", "GE", "EE", "NE", "'{'",
  "'}'", "';'", "','", "'['", "']'", "'('", "')'", "'&'", "'.'", "$accept",
  "start", "Program", "TDeclBlock", "TStructs", "TStruct", "$@1", "$@2",
  "TFields", "TField", "$@3", "VList", "Vid", "GDeclBlock", "GDeclList",
  "GDecl", "Type", "GidList", "Gid", "$@4", "$@5", "$@6", "$@7",
  "FDefBlock", "FDef", "$@8", "$@9", "$@10", "$@11", "ParamList", "Param",
  "Pid", "LDeclBlock", "LDecList", "LDecl", "IdList", "Lid", "MainBlock",
  "$@12", "$@13", "$@14", "Body", "Slist", "Stmt", "Expr", "ArgList",
  "Bool", "id", "Field", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   123,   125,    59,    44,    91,    93,    40,    41,    38,
      46
};
# endif

#define YYPACT_NINF -134

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-134)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     138,    24,     4,  -134,    16,  -134,    -6,    10,  -134,  -134,
      22,  -134,  -134,  -134,   100,  -134,     5,     6,  -134,    10,
    -134,    82,    10,  -134,  -134,    20,  -134,  -134,  -134,  -134,
      91,   148,    47,  -134,    99,    10,  -134,   111,  -134,  -134,
    -134,   170,  -134,   119,  -134,     5,   135,  -134,  -134,   189,
     146,   189,  -134,  -134,  -134,   189,    -1,  -134,  -134,  -134,
      66,   149,  -134,   189,   176,    49,  -134,  -134,   204,  -134,
     216,  -134,   189,   152,   149,   101,  -134,  -134,  -134,    89,
    -134,  -134,  -134,  -134,   164,  -134,   221,   106,  -134,   220,
     184,  -134,   204,  -134,  -134,   137,  -134,  -134,  -134,   162,
     185,  -134,  -134,  -134,   221,    62,     2,   179,    12,   190,
     197,   327,   193,   202,   327,    88,   208,   211,   212,   213,
       2,   201,  -134,   231,   214,  -134,   176,  -134,    88,   267,
    -134,     2,   219,    88,    88,    88,   356,  -134,  -134,   240,
    -134,    79,  -134,    88,   188,  -134,  -134,  -134,   217,     2,
    -134,    88,  -134,    30,   276,  -134,   155,  -134,   225,  -134,
      48,   381,   230,   232,   224,   241,    40,    69,    88,    88,
      88,    88,    88,   274,   244,   242,   206,   246,   223,  -134,
     220,  -134,   248,   251,    88,    88,    88,    88,    88,    88,
     286,   287,    88,    88,  -134,   243,    67,  -134,   173,   173,
    -134,  -134,  -134,  -134,  -134,   256,   297,   259,  -134,   266,
    -134,  -134,   243,   243,   243,   243,   243,   243,   327,   327,
     264,   268,    88,  -134,  -134,  -134,   277,  -134,   133,   269,
      19,   279,   243,  -134,   327,   280,   281,  -134,  -134,   298,
    -134,  -134,   285,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    59,     0,     2,     0,     0,     8,    12,
       0,    11,    27,    23,     0,    25,     0,     0,     1,     0,
       5,     0,     0,    39,     7,     0,     9,    10,    22,    24,
      30,     0,     0,    29,     0,     0,     4,     0,    38,     6,
      13,     0,    32,     0,    26,     0,     0,     3,    40,     0,
       0,    47,    35,    28,    60,    47,     0,    16,    17,    31,
       0,    33,    46,    47,     0,     0,    14,    15,     0,    49,
       0,    48,     0,     0,    36,     0,    61,    41,    21,     0,
      20,    50,    45,    34,     0,    52,     0,     0,    54,     0,
       0,    18,     0,    37,    58,     0,    57,    51,    53,     0,
       0,    42,    19,    55,     0,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     0,   106,    62,     0,    56,     0,     0,
     104,     0,     0,     0,     0,     0,     0,    76,    77,     0,
      89,   102,    90,     0,     0,    91,    78,    79,     0,     0,
     105,     0,    65,     0,     0,    43,     0,   108,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    95,     0,    88,    83,    84,
      85,    86,    87,    64,    80,     0,     0,     0,    70,     0,
      67,    68,    96,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,    93,    82,    63,     0,    44,     0,     0,
       0,     0,    94,    81,     0,     0,     0,    75,    74,     0,
      72,    73,     0,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,  -134,  -134,   317,  -134,  -134,  -134,   273,
    -134,  -134,   247,   335,  -134,   332,    39,  -134,   302,  -134,
    -134,  -134,  -134,   329,    -4,  -134,  -134,  -134,  -134,   -36,
     283,  -134,   233,  -134,   271,  -134,   252,   109,  -134,  -134,
    -134,   171,  -110,  -116,  -104,  -134,  -133,   -99,  -134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    10,    11,    25,    49,    56,    57,
      68,    79,    80,     7,    14,    15,    21,    32,    33,    51,
      73,    63,    84,    22,    23,    55,    90,   126,   180,    61,
      62,    71,    76,    87,    88,    95,    96,     8,    17,    64,
      89,   100,   121,   122,   161,   196,   162,   145,   124
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     123,   136,   163,    12,   139,   152,   105,   130,    12,    30,
     106,   144,   123,    31,    12,   123,    18,   132,    38,    65,
     152,   150,   123,   152,   156,     2,     9,    74,     9,   160,
       3,    38,   158,   140,   141,   142,    13,   123,   106,   167,
     123,    16,   219,   140,   141,   142,     3,   176,   106,   178,
     175,    66,    26,    16,   168,   169,   170,   171,   172,   220,
     221,   120,   195,    34,   198,   199,   200,   201,   202,   133,
      69,    40,   237,   177,    70,   168,   169,   170,   171,   172,
     212,   213,   214,   215,   216,   217,    37,   143,    58,   120,
      60,   140,   141,   142,    60,    58,   106,   143,   194,   120,
      44,    45,    60,    72,    12,    12,   183,    77,   228,   229,
      12,    60,   152,   152,    86,    20,    24,   128,   232,   123,
     123,   222,   129,   152,   239,   223,    86,   197,    36,   123,
     123,    39,    28,    85,   128,   123,   166,   105,    97,   129,
     123,   106,    91,    92,    47,   143,    41,   120,    42,   107,
     108,   109,    43,   234,   235,   110,   111,    46,   112,   113,
     114,   168,   169,   170,   171,   172,   105,     1,    48,     2,
     106,   116,   117,    50,     3,   118,    52,   119,   107,   108,
     109,   170,   171,   172,   110,   111,    54,   112,   113,   114,
     103,   104,   120,    12,   168,   169,   170,   171,   172,   115,
     116,   117,    59,    72,   118,   105,   119,    75,    78,   106,
      83,   181,   168,   169,   170,   171,   172,   107,   108,   109,
      81,   120,    93,   110,   111,    94,   112,   113,   114,   168,
     169,   170,   171,   172,    99,   101,   131,   125,   151,   116,
     117,   173,   153,   118,   105,   119,   137,   134,   106,   168,
     169,   170,   171,   172,   135,   138,   107,   108,   109,   206,
     120,   146,   110,   111,   147,   112,   113,   114,   165,   148,
     149,   157,   159,   105,   154,   174,   208,   106,   116,   117,
     179,   192,   118,   182,   119,   107,   108,   109,   190,   203,
     191,   110,   111,   236,   112,   113,   114,   204,   193,   120,
     205,   210,   105,   207,   211,   218,   106,   116,   117,   224,
     219,   118,   225,   119,   107,   108,   109,   226,   227,   242,
     110,   111,   230,   112,   113,   114,   231,    27,   120,    67,
     233,   105,   238,   240,   241,   106,   116,   117,   243,   102,
     118,    19,   119,   107,   108,   109,    29,    53,    35,   110,
     111,   209,   112,   113,   114,    82,   127,   120,    98,   155,
     105,     0,     0,     0,   106,   116,   117,     0,     0,   118,
       0,   119,   107,   108,   109,     0,     0,     0,   164,   111,
       0,   112,   113,   114,     0,     0,   120,   168,   169,   170,
     171,   172,     0,     0,   116,   117,     0,     0,   118,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   186,   187,
     188,   189
};

static const yytype_int16 yycheck[] =
{
      99,   111,   135,     4,   114,   121,     4,   106,     4,     4,
       8,   115,   111,     8,     4,   114,     0,     5,    22,    55,
     136,   120,   121,   139,   128,    31,     4,    63,     4,   133,
      36,    35,   131,     3,     4,     5,    32,   136,     8,   143,
     139,     2,    23,     3,     4,     5,    36,   151,     8,   153,
     149,    52,    30,    14,     6,     7,     8,     9,    10,   192,
     193,    59,   166,    57,   168,   169,   170,   171,   172,    57,
       4,    51,    53,    43,     8,     6,     7,     8,     9,    10,
     184,   185,   186,   187,   188,   189,     4,    57,    49,    59,
      51,     3,     4,     5,    55,    56,     8,    57,    58,    59,
      53,    54,    63,    54,     4,     4,    58,    58,   218,   219,
       4,    72,   228,   229,    75,     6,     7,    55,   222,   218,
     219,    54,    60,   239,   234,    58,    87,    58,    19,   228,
     229,    22,    32,    32,    55,   234,    57,     4,    32,    60,
     239,     8,    53,    54,    35,    57,    55,    59,    57,    16,
      17,    18,     4,    20,    21,    22,    23,    58,    25,    26,
      27,     6,     7,     8,     9,    10,     4,    29,    57,    31,
       8,    38,    39,     3,    36,    42,    57,    44,    16,    17,
      18,     8,     9,    10,    22,    23,    51,    25,    26,    27,
      53,    54,    59,     4,     6,     7,     8,     9,    10,    37,
      38,    39,    56,    54,    42,     4,    44,    31,     4,     8,
      58,    56,     6,     7,     8,     9,    10,    16,    17,    18,
       4,    59,    58,    22,    23,     4,    25,    26,    27,     6,
       7,     8,     9,    10,    14,    51,    57,    52,    37,    38,
      39,    53,    11,    42,     4,    44,    53,    57,     8,     6,
       7,     8,     9,    10,    57,    53,    16,    17,    18,    53,
      59,    53,    22,    23,    53,    25,    26,    27,    28,    57,
      57,     4,    53,     4,    60,    58,    53,     8,    38,    39,
       4,    57,    42,    58,    44,    16,    17,    18,    58,    15,
      58,    22,    23,    24,    25,    26,    27,    53,    57,    59,
      58,    53,     4,    57,    53,    19,     8,    38,    39,    53,
      23,    42,    15,    44,    16,    17,    18,    58,    52,    21,
      22,    23,    58,    25,    26,    27,    58,    10,    59,    56,
      53,     4,    53,    53,    53,     8,    38,    39,    53,    92,
      42,     6,    44,    16,    17,    18,    14,    45,    19,    22,
      23,   180,    25,    26,    27,    72,   104,    59,    87,   126,
       4,    -1,    -1,    -1,     8,    38,    39,    -1,    -1,    42,
      -1,    44,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      -1,    25,    26,    27,    -1,    -1,    59,     6,     7,     8,
       9,    10,    -1,    -1,    38,    39,    -1,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    31,    36,    62,    63,    64,    74,    98,     4,
      65,    66,     4,    32,    75,    76,    77,    99,     0,    74,
      98,    77,    84,    85,    98,    67,    30,    66,    32,    76,
       4,     8,    78,    79,    57,    84,    98,     4,    85,    98,
      51,    55,    57,     4,    53,    54,    58,    98,    57,    68,
       3,    80,    57,    79,    51,    86,    69,    70,    77,    56,
      77,    90,    91,    82,   100,    90,    52,    70,    71,     4,
       8,    92,    54,    81,    90,    31,    93,    58,     4,    72,
      73,     4,    91,    58,    83,    32,    77,    94,    95,   101,
      87,    53,    54,    58,     4,    96,    97,    32,    95,    14,
     102,    51,    73,    53,    54,     4,     8,    16,    17,    18,
      22,    23,    25,    26,    27,    37,    38,    39,    42,    44,
      59,   103,   104,   108,   109,    52,    88,    97,    55,    60,
     108,    57,     5,    57,    57,    57,   103,    53,    53,   103,
       3,     4,     5,    57,   105,   108,    53,    53,    57,    57,
     108,    37,   104,    11,    60,    93,   105,     4,   108,    53,
     105,   105,   107,   107,    22,    28,    57,   105,     6,     7,
       8,     9,    10,    53,    58,   108,   105,    43,   105,     4,
      89,    56,    58,    58,    45,    46,    47,    48,    49,    50,
      58,    58,    57,    57,    58,   105,   106,    58,   105,   105,
     105,   105,   105,    15,    53,    58,    53,    57,    53,   102,
      53,    53,   105,   105,   105,   105,   105,   105,    19,    23,
     107,   107,    54,    58,    53,    15,    58,    52,   103,   103,
      58,    58,   105,    53,    20,    21,    24,    53,    53,   103,
      53,    53,    21,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    63,    63,    63,    63,    64,
      65,    65,    67,    68,    66,    69,    69,    71,    70,    72,
      72,    73,    74,    74,    75,    75,    76,    77,    78,    78,
      79,    79,    80,    81,    79,    82,    83,    79,    84,    84,
      86,    87,    88,    89,    85,    90,    90,    90,    91,    92,
      92,    93,    93,    94,    94,    95,    96,    96,    97,    99,
     100,   101,    98,   102,   102,   103,   103,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   106,   106,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   108,   109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     3,     2,     3,     2,     1,     3,
       2,     1,     0,     0,     6,     2,     1,     0,     4,     3,
       1,     1,     3,     2,     2,     1,     3,     1,     3,     1,
       1,     4,     0,     0,     6,     0,     0,     7,     2,     1,
       0,     0,     0,     0,    13,     3,     1,     0,     2,     1,
       2,     3,     2,     2,     1,     3,     3,     1,     1,     0,
       0,     0,    10,     6,     5,     2,     1,     5,     5,     3,
       4,    10,     8,     8,     7,     7,     2,     2,     2,     2,
       4,     6,     5,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     3,     4,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     4,     2,     2,     1,     3,     3
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
#line 40 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 41 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 42 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 43 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 44 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 45 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 48 "expr.y" /* yacc.c:1646  */
    {tprint();}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 51 "expr.y" /* yacc.c:1646  */
    {TInstall((yyvsp[0])->str,0,NULL);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 52 "expr.y" /* yacc.c:1646  */
    {fhead=NULL;fieldindex=0;typesize=0;}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 53 "expr.y" /* yacc.c:1646  */
    {TLookup((yyvsp[-5])->str)->fields=fhead;TLookup((yyvsp[-5])->str)->size=typesize;}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 55 "expr.y" /* yacc.c:1646  */
    {}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 56 "expr.y" /* yacc.c:1646  */
    {}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 58 "expr.y" /* yacc.c:1646  */
    {	type=TLookup((yyvsp[0])->str);
						if(type==NULL){
							printf("line:'%d'\ttype:'%s' undeclared before this line\n",line,(yyvsp[0])->str);
							exit(1);
						}}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 66 "expr.y" /* yacc.c:1646  */
    {FInstall((yyvsp[0])->str,fieldindex++,type);typesize++;}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 69 "expr.y" /* yacc.c:1646  */
    {generate();gprint();}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 70 "expr.y" /* yacc.c:1646  */
    {generate();printf("No Globals declared!\n");}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 72 "expr.y" /* yacc.c:1646  */
    {}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 73 "expr.y" /* yacc.c:1646  */
    {}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 74 "expr.y" /* yacc.c:1646  */
    {}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 75 "expr.y" /* yacc.c:1646  */
    {	type=TLookup((yyvsp[0])->str);
												if(type==NULL){
													printf("line:'%d'\tundeclared type:'%s'\n",line,(yyvsp[0])->str);
													exit(1);}
												(yyval)=(yyvsp[0]);}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 101 "expr.y" /* yacc.c:1646  */
    {if(strcmp(type->name,"void")==0 || strcmp(type->name,"null")==0){
															printf("line:'%d'\tSorry, you cant declare that type...!\n",line);
															exit(1);}
														else
															GInstall((yyvsp[0])->str,type,1);}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 106 "expr.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3])->str,type,(yyvsp[-1])->num);}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 118 "expr.y" /* yacc.c:1646  */
    {phead=NULL;temptype=type;}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 119 "expr.y" /* yacc.c:1646  */
    {type=temptype;}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 120 "expr.y" /* yacc.c:1646  */
    {	GInstall((yyvsp[-5])->str,type,0);//-------------------------------------------------------
											GLookup((yyvsp[-5])->str)->paramlist=phead;
											GLookup((yyvsp[-5])->str)->flabel=flabel++;}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 123 "expr.y" /* yacc.c:1646  */
    {phead=NULL;temptype=type;}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 124 "expr.y" /* yacc.c:1646  */
    {type=temptype;}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 125 "expr.y" /* yacc.c:1646  */
    {	t=type;
												if(strcmp(type->name,"int")==0)
													type=TLookup("intptr");
												else if(strcmp(type->name,"str")==0)
													type=TLookup("strptr");
												else{
													printf("line:'%d'\tpointer to neither int nor str for id:'%s'\n",line,(yyvsp[-5])->str);
													exit(1);}
												GInstall((yyvsp[-5])->str,type,0);
												GLookup((yyvsp[-5])->str)->paramlist=phead;
												GLookup((yyvsp[-5])->str)->flabel=flabel++;type=t;}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 141 "expr.y" /* yacc.c:1646  */
    {	checkid((yyvsp[-1]));
								funcname=(yyvsp[-1])->str;
								binding=-2;
								lhead=NULL;
								phead=NULL;
								equiv=1;}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 147 "expr.y" /* yacc.c:1646  */
    {	equiv=0;
											struct Lsymbol *ltemp;
											struct Paramstruct *ptemp;
											ptemp=GLookup((yyvsp[-4])->str)->paramlist;
											ltemp=lhead;
											while(ptemp && ltemp){
												if(ptemp->type!=ltemp->type || strcmp(ptemp->name,ltemp->name)!=0){//----------------------------------------------
													printf("line:%d\nParameter Globally Declared:\tname:'%s'\ttype:'%s'\nParameter Locally Declared:\tname:'%s'\ttype:'%s'\n",line,ptemp->name,ptemp->type->name,ltemp->name,ltemp->type->name);
													exit(1);}
												ptemp=ptemp->next;
												ltemp=ltemp->next;}
											if(ptemp!=NULL || ltemp!=NULL){
												if(ptemp!=NULL){
													printf("line:%d\tExtra Global Parameters Declared...\n",line);
													while(ptemp!=NULL){
														printf("name:'%s'\ttype:'%s'\n",ptemp->name,ptemp->type->name);
														ptemp=ptemp->next;}}
												else{
													printf("line:%d\tExtra Local Parameters Declared...\n",line);
													while(ltemp!=NULL){
														printf("name:'%s'\ttype:'%s'\n",ltemp->name,ltemp->type->name);
														ltemp=ltemp->next;}}
												exit(1);}}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 170 "expr.y" /* yacc.c:1646  */
    {	binding=0;}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 171 "expr.y" /* yacc.c:1646  */
    {lprint();initflag=allocflag=0;}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 174 "expr.y" /* yacc.c:1646  */
    {}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 178 "expr.y" /* yacc.c:1646  */
    {if(equiv==1){
								binding--;
								LInstall((yyvsp[0])->str,type);}
							else
								PInstall((yyvsp[0])->str,type);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 183 "expr.y" /* yacc.c:1646  */
    {if(equiv==1){
								binding--;
								t=type;
								if(strcmp(type->name,"int")==0)
									type=TLookup("intptr");
								else if(strcmp(type->name,"str")==0)
									type=TLookup("strptr");
								else{
									printf("line:'%d'\tpointer to neither int nor str for id:'%s'\n",line,(yyvsp[0])->str);
									exit(1);}
								LInstall((yyvsp[0])->str,type);
								type=t;}
							else{
								t=type;
								if(strcmp(type->name,"int")==0)
									type=TLookup("intptr");
								else if(strcmp(type->name,"str")==0)
									type=TLookup("strptr");
								else{
									printf("line:'%d'\tpointer to neither int nor str for id:'%s'\n",line,(yyvsp[0])->str);
									exit(1);}
								PInstall((yyvsp[0])->str,type);
								type=t;}}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 215 "expr.y" /* yacc.c:1646  */
    {binding+=1;LInstall((yyvsp[0])->str,type);}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 217 "expr.y" /* yacc.c:1646  */
    {	binding=0;}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 218 "expr.y" /* yacc.c:1646  */
    {	funcname="main";
										lhead=NULL;
										binding=0;
										GLookup("main")->type=TLookup("int");}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 222 "expr.y" /* yacc.c:1646  */
    {lprint();initflag=allocflag=0;}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 227 "expr.y" /* yacc.c:1646  */
    {//$$=$2;
												struct tnode *ret=createtree(GLookup(funcname)->type,0,NULL,nt_RET,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);
												struct tnode *body=createtree(TLookup("void"),0,NULL,nt_NODE,(yyvsp[-4]),NULL,ret,NULL,NULL,NULL);
												funcGen(GLookup(funcname));
												printf("CodeGen-ing '%s'\n",funcname);
												if(allocflag>0 && initflag==0){//--------------main:init other:alloc???
													printf("Using ALLOC without INIT... You may run into something...!\n");}
												codeGen(body);
												printf("Finished CodeGen-ing of '%s'\n",funcname);
												printf("################################################################################################\n");}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 237 "expr.y" /* yacc.c:1646  */
    {struct tnode *ret=createtree(GLookup(funcname)->type,0,NULL,nt_RET,NULL,(yyvsp[-1]),NULL,NULL,NULL,NULL);
												funcGen(GLookup(funcname));
												printf("CodeGen-ing '%s'\n",funcname);
												codeGen(ret);
												printf("Finished CodeGen-ing of '%s'\n",funcname);
												printf("################################################################################################\n");}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 243 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_NODE,(yyvsp[-1]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 244 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 245 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_READ,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 246 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WRITE,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 247 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WRITE,NULL,(yyvsp[-1]),NULL,NULL,NULL,NULL);}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 248 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_ASGN,(yyvsp[-3]),NULL,(yyvsp[-1]),NULL,NULL,NULL);}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 249 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_IFELSE,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]),NULL,NULL,NULL);}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 250 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_IF,(yyvsp[-5]),NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 251 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WHILE,(yyvsp[-5]),NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 252 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WHILE,(yyvsp[-2]),NULL,(yyvsp[-5]),NULL,NULL,NULL);}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 253 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WHILE,(yyvsp[-2]),NULL,(yyvsp[-5]),NULL,NULL,NULL);}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 254 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_BREAK,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 255 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_CONTINUE,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 256 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_BRKP,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 257 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_EXIT,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 258 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_INIT,NULL,NULL,NULL,NULL,NULL,NULL);initflag++;}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 259 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),8/*GetSize(TLookup($1->str))*/,NULL,nt_ALLOC,NULL,(yyvsp[-5]),NULL,NULL,NULL,NULL);allocflag++;}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 260 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_FREE,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 262 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_PLUS,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 263 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_MINUS,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 264 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_MUL,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 265 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_DIV,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 266 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_MOD,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 267 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 268 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 269 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 270 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 271 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[-2]));(yyval)=createtree(GLookup((yyvsp[-2])->str)->type,0,(yyvsp[-2])->str,nt_FUNC,NULL,NULL,NULL,GLookup((yyvsp[-2])->str),NULL,NULL);}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 272 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[-3]));(yyval)=createtree(GLookup((yyvsp[-3])->str)->type,0,(yyvsp[-3])->str,nt_FUNC,NULL,NULL,NULL,GLookup((yyvsp[-3])->str),(yyvsp[-1]),NULL);}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 273 "expr.y" /* yacc.c:1646  */
    {(yyvsp[0])->down=(yyvsp[-2]);(yyval)=(yyvsp[0]);}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 274 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 275 "expr.y" /* yacc.c:1646  */
    {(yyval) =createtree(TLookup("bool"),0,NULL,nt_LT,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 276 "expr.y" /* yacc.c:1646  */
    {(yyval) =createtree(TLookup("bool"),0,NULL,nt_LE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 277 "expr.y" /* yacc.c:1646  */
    {(yyval) =createtree(TLookup("bool"),0,NULL,nt_GT,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 278 "expr.y" /* yacc.c:1646  */
    {(yyval) =createtree(TLookup("bool"),0,NULL,nt_GE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 279 "expr.y" /* yacc.c:1646  */
    {(yyval) =createtree(TLookup("bool"),0,NULL,nt_EE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 280 "expr.y" /* yacc.c:1646  */
    {(yyval) =createtree(TLookup("bool"),0,NULL,nt_NE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 283 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[0]));
											(yyval)=createtree(LLookup((yyvsp[0])->str)==NULL?GLookup((yyvsp[0])->str)->type:LLookup((yyvsp[0])->str)->type,0,(yyvsp[0])->str,nt_ID,NULL,NULL,NULL,GLookup((yyvsp[0])->str),NULL,LLookup((yyvsp[0])->str));}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 285 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[-3]));(yyval)=createtree(LLookup((yyvsp[-3])->str)==NULL?GLookup((yyvsp[-3])->str)->type:LLookup((yyvsp[-3])->str)->type,0,(yyvsp[-3])->str,nt_ARR,NULL,(yyvsp[-1]),NULL,GLookup((yyvsp[-3])->str),NULL,LLookup((yyvsp[-3])->str));}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 288 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(GLookup((yyvsp[0])->str)->type,(yyvsp[0])->num,(yyvsp[0])->str,nt_SPTR,NULL,NULL,NULL,GLookup((yyvsp[0])->str),NULL,LLookup((yyvsp[-1])->str));}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 289 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(GLookup((yyvsp[0])->str)->type,(yyvsp[0])->num,(yyvsp[0])->str,nt_APTR,NULL,NULL,NULL,GLookup((yyvsp[0])->str),NULL,LLookup((yyvsp[-1])->str));}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 299 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);(yyval)->nt=nt_USERROOT;}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 300 "expr.y" /* yacc.c:1646  */
    {struct Typetable *ttemp=(yyvsp[-2])->t;
											struct Fieldlist *ftemp=FLookup(ttemp,(yyvsp[0])->str);
											(yyval)=createtree(ftemp->type,ftemp->fieldIndex,(yyvsp[0])->str,nt_USERNODE,NULL,(yyvsp[-2]),NULL,(yyvsp[-2])->Gentry,NULL,(yyvsp[-2])->Lentry);}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 303 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[-2]));
											checkidid((yyvsp[-2]),(yyvsp[0]));
											struct Typetable *ttemp=TLookup((yyvsp[-2])->str);
											struct Fieldlist *ftemp=FLookup(ttemp,(yyvsp[0])->str);
											struct tnode *node=createtree(ttemp,0,(yyvsp[-2])->str,nt_USERNODE,NULL,NULL,NULL,GLookup((yyvsp[-2])->str),NULL,LLookup((yyvsp[-2])->str));
											(yyval)=createtree(ftemp->type,ftemp->fieldIndex,(yyvsp[0])->str,nt_USERNODE,NULL,node,NULL,GLookup((yyvsp[-2])->str),NULL,LLookup((yyvsp[-2])->str));}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2130 "y.tab.c" /* yacc.c:1646  */
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
#line 310 "expr.y" /* yacc.c:1906  */

void checkid(struct tnode *t){
	if(LLookup(t->str)==NULL && GLookup(t->str)==NULL){
		printf("Undeclared identifier:'%s' at line:'%d'\n",t->str,line);
		exit(1);}}
void checkidid(struct tnode *t1,struct tnode *t3){
	struct Gsymbol *gtemp=GLookup(t1->str);
	struct Lsymbol *ltemp=LLookup(t1->str);
	struct Typetable *ttemp;
	if(gtemp==NULL && ltemp==NULL){
		printf("line:'%d'\tUndeclared type:'%s'\n",line,t1->str);
		exit(1);}
	if(ltemp==NULL)
		ttemp=gtemp->type;
	else
		ttemp=ltemp->type;
	struct Fieldlist *ftemp=ttemp->fields;
	if(FLookup(ttemp,t3->str)==NULL){
		printf("line:'%d'\tNo member '%s' in type '%s'\n",line,t3->str,t1->str);
		exit(1);}}
void yyerror(char const *s){
	printf("yyerror %s\nLine:%d at '%s'\n",s,line,yytext);
	if(strcmp(yytext,"end")==0)
		printf("Did you use a return statement...!\n");
	exit(1);}
void func(struct Paramstruct* phead){
	struct Paramstruct* temp=phead;
	while(temp!=NULL){
		printf("name:'%s'\ttype:'%s'\t\n",temp->type->name,temp->type->name);
		temp=temp->next;}}
void tprint(){
	printf("\t\tType Declarations\n");
	struct Typetable *ttemp;
	struct Fieldlist *ftemp;
	ttemp=thead;
	while(ttemp){
		printf("name:'%s'\tsize:'%d'\n",ttemp->name,ttemp->size);
		ftemp=ttemp->fields;
		if(ftemp)
			printf("\tFields...\n");
		while(ftemp){
			if(ftemp->type!=NULL)
				printf("\tname:'%s'\tfieldIndex:'%d'\ttype:'%s'\n",ftemp->name,ftemp->fieldIndex,ftemp->type->name);
			ftemp=ftemp->next;}
		ttemp=ttemp->next;}
	printf("######################################################\n");}
void gprint(){
	int i,j;
	printf("\t\tGlobal Table(Static size:'%d')\n",gbinding-4096);
	struct Gsymbol* gtemp=ghead;
	struct Paramstruct* ptemp;
	printf("GLOBALS...\n");
	i=1;
	while(gtemp!=NULL){
		if(gtemp->size>0){
			printf("%d.name:'%s'\ttype:'%s'\tsize:'%d'\tbase:'%d'\tarr:%d\n",i++,gtemp->name,gtemp->type->name,gtemp->size,gtemp->binding,gtemp->arr);
		if(gtemp->paramlist){
			ptemp=gtemp->paramlist;
			printf("\tContent of type...\n");
			while(ptemp){
				printf("\tname:'%s'\ttype:'%s'\n",ptemp->name,ptemp->type->name);
				ptemp=ptemp->next;}}
			if(gtemp->paramlist)
				printf("\n");}
		gtemp=gtemp->next;}
	gtemp=ghead;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("functions\n");
	i=1;
	while(gtemp!=NULL){
		if(gtemp->size==0 && gtemp->flabel!=1000){
			printf("%d.name:'%s'\ttype:'%s'\tflabel:'%d'\n",i++,gtemp->name,gtemp->type->name,gtemp->flabel);
			ptemp=gtemp->paramlist;
			printf("\tparameters\n");
			j=1;
			while(ptemp){
				printf("\t%d.name:'%s'\ttype:'%s'\n",j,ptemp->name,ptemp->type->name);
				ptemp=ptemp->next;}
			printf("\n");}
		gtemp=gtemp->next;}
	printf("######################################################\n");}
void lprint(){
	int i;
	printf("\t\tLocal Table('%s')\n",funcname);
	int count=0;
	struct Lsymbol* ltemp=lhead;
	printf("LOCALS...\n");
	i=1;
	while(ltemp!=NULL){
		count++;
		printf("%d.name:'%s'\ttype:'%s'\tbinding:'%d'\n",i++,ltemp->name,ltemp->type->name,ltemp->binding);
		if(ltemp->binding==1){printf("\narguments\n");i=1;}
		ltemp=ltemp->next;}
	printf("######################################################\n");}
/*
	void n(int n){printf("~~~%d~~~\n",n);}
	void c(char c){printf("~~~%c~~~\n",c);}
	void s(char *s){printf("~~~%s~~~\n",s);}*/
int main(void){
	ghead=NULL;
	FILE *fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else{
		printf("Input file error\n");
		exit(1);}
	target_file=fopen("intermediate.xsm","w+");//comment for consoling
	GInstall("main",TLookup("int"),0);
	GLookup("main")->flabel=1000;
	TypeTableCreate();
	yyparse();
	//print();
	return 0;}
//
