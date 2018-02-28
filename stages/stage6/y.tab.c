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
	int tint=1,ttint=1;

#line 86 "y.tab.c" /* yacc.c:339  */

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
    TRUE = 277,
    FALSE = 278,
    NOT = 279,
    WHILE = 280,
    DO = 281,
    ENDWHILE = 282,
    BREAK = 283,
    CONTINUE = 284,
    REPEAT = 285,
    UNTIL = 286,
    TYPE = 287,
    ENDTYPE = 288,
    DECL = 289,
    ENDDECL = 290,
    INT = 291,
    STR = 292,
    TUPLE = 293,
    MAIN = 294,
    RETURN = 295,
    BRKP = 296,
    EXIT = 297,
    AND = 298,
    OR = 299,
    INIT = 300,
    ALLOC = 301,
    FREE = 302,
    NUL = 303,
    CLASS = 304,
    ENDCLASS = 305,
    EXTENDS = 306,
    NEW = 307,
    DELETE = 308,
    SELF = 309,
    LT = 310,
    LE = 311,
    GT = 312,
    GE = 313,
    EE = 314,
    NE = 315
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
#define TRUE 277
#define FALSE 278
#define NOT 279
#define WHILE 280
#define DO 281
#define ENDWHILE 282
#define BREAK 283
#define CONTINUE 284
#define REPEAT 285
#define UNTIL 286
#define TYPE 287
#define ENDTYPE 288
#define DECL 289
#define ENDDECL 290
#define INT 291
#define STR 292
#define TUPLE 293
#define MAIN 294
#define RETURN 295
#define BRKP 296
#define EXIT 297
#define AND 298
#define OR 299
#define INIT 300
#define ALLOC 301
#define FREE 302
#define NUL 303
#define CLASS 304
#define ENDCLASS 305
#define EXTENDS 306
#define NEW 307
#define DELETE 308
#define SELF 309
#define LT 310
#define LE 311
#define GT 312
#define GE 313
#define EE 314
#define NE 315

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

#line 257 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   475

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,     2,
      67,    68,     2,     2,    64,     2,    70,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    63,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    45,    46,    47,    48,    49,    50,    51,
      60,    61,    62,    63,    64,    63,    67,    68,    70,    70,
      76,    77,    78,   107,   108,   110,   111,   112,   113,   137,
     138,   139,   144,   156,   157,   156,   161,   162,   161,   176,
     177,   179,   189,   212,   213,   179,   216,   217,   218,   219,
     220,   225,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   260,   261,   268,   260,   273,   286,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   343,   345,   348,   349,   359,   360,   364
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "STRING", "PLUS", "MINUS",
  "MUL", "DIV", "MOD", "EQ", "INC", "DEC", "BEG", "END", "READ", "WRITE",
  "IF", "THEN", "ELSE", "ENDIF", "TRUE", "FALSE", "NOT", "WHILE", "DO",
  "ENDWHILE", "BREAK", "CONTINUE", "REPEAT", "UNTIL", "TYPE", "ENDTYPE",
  "DECL", "ENDDECL", "INT", "STR", "TUPLE", "MAIN", "RETURN", "BRKP",
  "EXIT", "AND", "OR", "INIT", "ALLOC", "FREE", "NUL", "CLASS", "ENDCLASS",
  "EXTENDS", "NEW", "DELETE", "SELF", "LT", "LE", "GT", "GE", "EE", "NE",
  "'{'", "'}'", "';'", "','", "'['", "']'", "'('", "')'", "'&'", "'.'",
  "$accept", "start", "Program", "TDeclBlock", "TStructs", "TStruct",
  "$@1", "$@2", "TFields", "TField", "$@3", "VList", "Vid", "GDeclBlock",
  "GDeclList", "GDecl", "Type", "GidList", "Gid", "$@4", "$@5", "$@6",
  "$@7", "FDefBlock", "FDef", "$@8", "$@9", "$@10", "$@11", "ParamList",
  "Param", "Pid", "LDeclBlock", "LDecList", "LDecl", "IdList", "Lid",
  "MainBlock", "$@12", "$@13", "$@14", "Body", "Slist", "Stmt", "Expr",
  "ArgList", "Bool", "id", "Field", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   123,   125,    59,    44,    91,    93,    40,    41,    38,
      46
};
# endif

#define YYPACT_NINF -117

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-117)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      55,    12,     6,  -117,    39,  -117,    -4,    13,  -117,  -117,
      30,  -117,  -117,  -117,    23,  -117,   141,   -11,  -117,    13,
    -117,    58,    13,  -117,  -117,     4,  -117,  -117,  -117,  -117,
      37,    71,   164,  -117,    43,    13,  -117,    14,  -117,  -117,
    -117,    89,  -117,    46,  -117,   141,    67,  -117,  -117,   156,
     113,   156,  -117,  -117,  -117,   156,    -1,  -117,  -117,  -117,
     157,   139,  -117,   156,   153,   172,  -117,  -117,   200,  -117,
     202,  -117,   156,   151,   139,    24,  -117,  -117,  -117,   183,
    -117,  -117,  -117,  -117,   162,  -117,   237,    29,  -117,   234,
     193,  -117,   200,  -117,  -117,   187,  -117,  -117,  -117,   192,
     196,  -117,  -117,  -117,   237,    70,    -2,   195,     3,   197,
     198,   358,   210,   212,   358,   126,   213,   214,   219,   222,
      -2,   227,  -117,   248,   190,  -117,   153,  -117,   126,   259,
    -117,    -2,   231,   126,    21,    21,   390,  -117,  -117,   262,
    -117,   127,  -117,  -117,   126,   163,  -117,  -117,  -117,   229,
      -2,  -117,   126,  -117,    45,   291,  -117,   205,  -117,   232,
    -117,    76,  -117,  -117,    21,    21,   415,   -30,    73,   238,
     239,   115,   148,   126,   126,   126,   126,   126,   284,   245,
     233,   275,   251,   307,  -117,   234,  -117,   269,   270,  -117,
     383,   123,   126,   126,   126,   126,   126,   126,    21,    21,
     318,   314,    21,    21,  -117,   319,   174,  -117,   142,   142,
    -117,  -117,  -117,  -117,  -117,   282,   331,   280,  -117,   287,
    -117,  -117,  -117,   319,   319,   319,   319,   319,   319,  -117,
    -117,   358,   358,   155,   181,   126,  -117,  -117,  -117,   290,
    -117,   160,   294,   -17,   295,   319,  -117,   358,   296,   297,
    -117,  -117,   326,  -117,  -117,   298,  -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,    61,     0,     2,     0,     0,     9,    13,
       0,    12,    28,    24,     0,    26,     0,     0,     1,     0,
       6,     0,     0,    40,     8,     0,    10,    11,    23,    25,
      31,     0,     0,    30,     0,     0,     5,     0,    39,     7,
      14,     0,    33,     0,    27,     0,     0,     4,    41,     0,
       0,    48,    36,    29,    62,    48,     0,    17,    18,    32,
       0,    34,    47,    48,    54,     0,    15,    16,     0,    50,
       0,    49,     0,     0,    37,     0,    63,    42,    22,     0,
      21,    51,    46,    35,     0,    53,     0,     0,    56,     0,
       0,    19,     0,    38,    60,     0,    59,    52,    55,     0,
       0,    43,    20,    57,     0,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,     0,   115,    64,    54,    58,     0,     0,
     113,     0,     0,     0,     0,     0,     0,    78,    79,     0,
      91,   111,    92,    94,     0,     0,    93,    80,    81,     0,
       0,   114,     0,    67,     0,     0,    44,     0,   117,     0,
      71,     0,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,     0,   112,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    98,     0,    90,    85,    86,
      87,    88,    89,    66,    82,     0,     0,     0,    72,     0,
      69,    70,   107,    99,   100,   101,   102,   103,   104,   109,
     110,     0,     0,     0,     0,     0,    96,    84,    65,     0,
      45,     0,     0,     0,     0,    97,    83,     0,     0,     0,
      77,    76,     0,    74,    75,     0,    73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,  -117,  -117,  -117,   340,  -117,  -117,  -117,   301,
    -117,  -117,   272,   359,  -117,   355,    52,  -117,   327,  -117,
    -117,  -117,  -117,   360,    38,  -117,  -117,  -117,  -117,   -44,
     305,  -117,   252,  -117,   293,  -117,   277,   140,  -117,  -117,
    -117,   211,  -110,  -116,   -97,  -117,   -93,   -99,  -117
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    10,    11,    25,    49,    56,    57,
      68,    79,    80,     7,    14,    15,    21,    32,    33,    51,
      73,    63,    84,    22,    23,    55,    90,   126,   185,    61,
      62,    71,    76,    87,    88,    95,    96,     8,    17,    64,
      89,   100,   121,   122,   166,   206,   167,   146,   124
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     123,   136,   105,    12,   139,   153,   106,   130,   132,   232,
      12,    65,   123,   198,   199,   123,     9,    12,   145,    74,
     153,   151,   123,   153,   140,   141,   142,    12,    12,   106,
       2,   157,   159,    12,     9,     3,   161,   123,   200,    18,
     123,    13,   168,   162,   163,   164,   250,   172,   140,   141,
     142,   180,     3,   106,    16,   181,    34,   183,    28,    85,
      38,    66,    37,    26,    97,    40,    16,   120,   190,   143,
     133,   189,   191,    38,   205,    43,   208,   209,   210,   211,
     212,    48,   173,   174,   175,   176,   177,     1,   165,     2,
     120,   182,    50,   143,     3,   223,   224,   225,   226,   227,
     228,    58,    41,    60,    42,   229,   230,    60,    58,   233,
     234,    46,   144,    52,   120,    60,   198,   199,   140,   141,
     142,   241,   242,   106,    60,   153,   153,    86,    54,   140,
     141,   142,   123,   123,   106,   128,   153,   252,   245,    86,
     129,   201,   123,   123,   188,    30,    20,    24,   123,    31,
     175,   176,   177,   123,   173,   174,   175,   176,   177,    36,
      12,    69,    39,   143,   105,    70,   198,   199,   106,   173,
     174,   175,   176,   177,   143,    47,   107,   108,   109,    59,
     247,   248,   144,   204,   120,   110,   111,    75,   112,   113,
     114,   222,   128,   144,   171,   120,   105,   129,   198,   199,
     106,   116,   117,    72,    78,   118,    81,   119,   107,   108,
     109,   173,   174,   175,   176,   177,   207,   110,   111,    83,
     112,   113,   114,   243,   198,   199,   178,    44,    45,   120,
      93,   105,   115,   116,   117,   106,    72,   118,   235,   119,
      77,    94,   236,   107,   108,   109,    91,    92,    99,   244,
     103,   104,   110,   111,   101,   112,   113,   114,   125,   154,
     155,   120,   131,   158,   134,   135,   105,   152,   116,   117,
     106,   186,   118,   137,   119,   138,   147,   148,   107,   108,
     109,   173,   174,   175,   176,   177,   149,   110,   111,   150,
     112,   113,   114,   170,   160,   184,   120,   179,   105,   213,
     187,   215,   106,   116,   117,   202,   203,   118,   214,   119,
     107,   108,   109,   173,   174,   175,   176,   177,   217,   110,
     111,   249,   112,   113,   114,   173,   174,   175,   176,   177,
     105,   120,   220,   221,   106,   116,   117,   231,   216,   118,
     232,   119,   107,   108,   109,   237,   238,   255,   239,   240,
      27,   110,   111,   246,   112,   113,   114,    67,   251,   253,
     254,   256,   105,   120,   102,    19,   106,   116,   117,    29,
     218,   118,    53,   119,   107,   108,   109,    82,   156,    35,
      98,   127,     0,   110,   111,     0,   112,   113,   114,   173,
     174,   175,   176,   177,   105,   120,   219,     0,   106,   116,
     117,     0,     0,   118,     0,   119,   107,   108,   109,     0,
       0,     0,     0,     0,     0,   169,   111,     0,   112,   113,
     114,   173,   174,   175,   176,   177,     0,   120,     0,     0,
       0,   116,   117,     0,     0,   118,     0,   119,   192,   193,
     194,   195,   196,   197,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,     0,     0,     0,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,   194,   195,   196,   197
};

static const yytype_int16 yycheck[] =
{
      99,   111,     4,     4,   114,   121,     8,   106,     5,    26,
       4,    55,   111,    43,    44,   114,     4,     4,   115,    63,
     136,   120,   121,   139,     3,     4,     5,     4,     4,     8,
      34,   128,   131,     4,     4,    39,   133,   136,    68,     0,
     139,    35,   135,    22,    23,    24,    63,   144,     3,     4,
       5,   150,    39,     8,     2,   152,    67,   154,    35,    35,
      22,    62,     4,    33,    35,    61,    14,    69,   165,    48,
      67,   164,   165,    35,   171,     4,   173,   174,   175,   176,
     177,    67,     6,     7,     8,     9,    10,    32,    67,    34,
      69,    46,     3,    48,    39,   192,   193,   194,   195,   196,
     197,    49,    65,    51,    67,   198,   199,    55,    56,   202,
     203,    68,    67,    67,    69,    63,    43,    44,     3,     4,
       5,   231,   232,     8,    72,   241,   242,    75,    61,     3,
       4,     5,   231,   232,     8,    65,   252,   247,   235,    87,
      70,    68,   241,   242,    68,     4,     6,     7,   247,     8,
       8,     9,    10,   252,     6,     7,     8,     9,    10,    19,
       4,     4,    22,    48,     4,     8,    43,    44,     8,     6,
       7,     8,     9,    10,    48,    35,    16,    17,    18,    66,
      20,    21,    67,    68,    69,    25,    26,    34,    28,    29,
      30,    68,    65,    67,    67,    69,     4,    70,    43,    44,
       8,    41,    42,    64,     4,    45,     4,    47,    16,    17,
      18,     6,     7,     8,     9,    10,    68,    25,    26,    68,
      28,    29,    30,    68,    43,    44,    63,    63,    64,    69,
      68,     4,    40,    41,    42,     8,    64,    45,    64,    47,
      68,     4,    68,    16,    17,    18,    63,    64,    14,    68,
      63,    64,    25,    26,    61,    28,    29,    30,    62,    11,
      70,    69,    67,     4,    67,    67,     4,    40,    41,    42,
       8,    66,    45,    63,    47,    63,    63,    63,    16,    17,
      18,     6,     7,     8,     9,    10,    67,    25,    26,    67,
      28,    29,    30,    31,    63,     4,    69,    68,     4,    15,
      68,    68,     8,    41,    42,    67,    67,    45,    63,    47,
      16,    17,    18,     6,     7,     8,     9,    10,    67,    25,
      26,    27,    28,    29,    30,     6,     7,     8,     9,    10,
       4,    69,    63,    63,     8,    41,    42,    19,    63,    45,
      26,    47,    16,    17,    18,    63,    15,    21,    68,    62,
      10,    25,    26,    63,    28,    29,    30,    56,    63,    63,
      63,    63,     4,    69,    92,     6,     8,    41,    42,    14,
      63,    45,    45,    47,    16,    17,    18,    72,   126,    19,
      87,   104,    -1,    25,    26,    -1,    28,    29,    30,     6,
       7,     8,     9,    10,     4,    69,   185,    -1,     8,    41,
      42,    -1,    -1,    45,    -1,    47,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,     6,     7,     8,     9,    10,    -1,    69,    -1,    -1,
      -1,    41,    42,    -1,    -1,    45,    -1,    47,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    34,    39,    72,    73,    74,    84,   108,     4,
      75,    76,     4,    35,    85,    86,    87,   109,     0,    84,
     108,    87,    94,    95,   108,    77,    33,    76,    35,    86,
       4,     8,    88,    89,    67,    94,   108,     4,    95,   108,
      61,    65,    67,     4,    63,    64,    68,   108,    67,    78,
       3,    90,    67,    89,    61,    96,    79,    80,    87,    66,
      87,   100,   101,    92,   110,   100,    62,    80,    81,     4,
       8,   102,    64,    91,   100,    34,   103,    68,     4,    82,
      83,     4,   101,    68,    93,    35,    87,   104,   105,   111,
      97,    63,    64,    68,     4,   106,   107,    35,   105,    14,
     112,    61,    83,    63,    64,     4,     8,    16,    17,    18,
      25,    26,    28,    29,    30,    40,    41,    42,    45,    47,
      69,   113,   114,   118,   119,    62,    98,   107,    65,    70,
     118,    67,     5,    67,    67,    67,   113,    63,    63,   113,
       3,     4,     5,    48,    67,   115,   118,    63,    63,    67,
      67,   118,    40,   114,    11,    70,   103,   115,     4,   118,
      63,   115,    22,    23,    24,    67,   115,   117,   117,    25,
      31,    67,   115,     6,     7,     8,     9,    10,    63,    68,
     118,   115,    46,   115,     4,    99,    66,    68,    68,   117,
     115,   117,    55,    56,    57,    58,    59,    60,    43,    44,
      68,    68,    67,    67,    68,   115,   116,    68,   115,   115,
     115,   115,   115,    15,    63,    68,    63,    67,    63,   112,
      63,    63,    68,   115,   115,   115,   115,   115,   115,   117,
     117,    19,    26,   117,   117,    64,    68,    63,    15,    68,
      62,   113,   113,    68,    68,   115,    63,    20,    21,    27,
      63,    63,   113,    63,    63,    21,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    73,    73,    73,    73,    73,
      74,    75,    75,    77,    78,    76,    79,    79,    81,    80,
      82,    82,    83,    84,    84,    85,    85,    86,    87,    88,
      88,    89,    89,    90,    91,    89,    92,    93,    89,    94,
      94,    96,    97,    98,    99,    95,   100,   100,   100,   101,
     102,   102,   103,   103,   103,   104,   104,   105,   106,   106,
     107,   109,   110,   111,   108,   112,   112,   113,   113,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   118,   118,   118,   118,   118,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     4,     3,     2,     3,     2,     1,
       3,     2,     1,     0,     0,     6,     2,     1,     0,     4,
       3,     1,     1,     3,     2,     2,     1,     3,     1,     3,
       1,     1,     4,     0,     0,     6,     0,     0,     7,     2,
       1,     0,     0,     0,     0,    13,     3,     1,     0,     2,
       1,     2,     3,     2,     0,     2,     1,     3,     3,     1,
       1,     0,     0,     0,    10,     6,     5,     2,     1,     5,
       5,     3,     4,    10,     8,     8,     7,     7,     2,     2,
       2,     2,     4,     6,     5,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     3,     4,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     2,     3,
       3,     1,     4,     2,     2,     1,     3,     3
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
        case 4:
#line 46 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 47 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 48 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 49 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 50 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 51 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 60 "expr.y" /* yacc.c:1646  */
    {tprint();}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 63 "expr.y" /* yacc.c:1646  */
    {TInstall((yyvsp[0])->str,0,NULL);}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 64 "expr.y" /* yacc.c:1646  */
    {fhead=NULL;fieldindex=0;typesize=0;}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 65 "expr.y" /* yacc.c:1646  */
    {TLookup((yyvsp[-5])->str)->fields=fhead;TLookup((yyvsp[-5])->str)->size=typesize;}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 67 "expr.y" /* yacc.c:1646  */
    {}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 68 "expr.y" /* yacc.c:1646  */
    {}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 70 "expr.y" /* yacc.c:1646  */
    {	type=TLookup((yyvsp[0])->str);
						if(type==NULL){
							printf("line:'%d'\ttype:'%s' undeclared before this line\n",line,(yyvsp[0])->str);
							exit(1);
						}}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 78 "expr.y" /* yacc.c:1646  */
    {FInstall((yyvsp[0])->str,fieldindex++,type);typesize++;}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 107 "expr.y" /* yacc.c:1646  */
    {generate();gprint();}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 108 "expr.y" /* yacc.c:1646  */
    {generate();printf("No Globals declared!\n");}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 110 "expr.y" /* yacc.c:1646  */
    {}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 111 "expr.y" /* yacc.c:1646  */
    {}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 112 "expr.y" /* yacc.c:1646  */
    {}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 113 "expr.y" /* yacc.c:1646  */
    {	type=TLookup((yyvsp[0])->str);
												if(type==NULL){
													printf("line:'%d'\tundeclared type:'%s'\n",line,(yyvsp[0])->str);
													exit(1);}
												(yyval)=(yyvsp[0]);}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 139 "expr.y" /* yacc.c:1646  */
    {if(strcmp(type->name,"void")==0 || strcmp(type->name,"null")==0){
															printf("line:'%d'\tSorry, you cant declare that type...!\n",line);
															exit(1);}
														else
															GInstall((yyvsp[0])->str,type,1);}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 144 "expr.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3])->str,type,(yyvsp[-1])->num);}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 156 "expr.y" /* yacc.c:1646  */
    {phead=NULL;temptype=type;}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 157 "expr.y" /* yacc.c:1646  */
    {type=temptype;}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 158 "expr.y" /* yacc.c:1646  */
    {	GInstall((yyvsp[-5])->str,type,0);//-------------------------------------------------------
											GLookup((yyvsp[-5])->str)->paramlist=phead;
											GLookup((yyvsp[-5])->str)->flabel=flabel++;}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 161 "expr.y" /* yacc.c:1646  */
    {phead=NULL;temptype=type;}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 162 "expr.y" /* yacc.c:1646  */
    {type=temptype;}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 163 "expr.y" /* yacc.c:1646  */
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
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 179 "expr.y" /* yacc.c:1646  */
    {	checkid((yyvsp[-1]));
								funcname=(yyvsp[-1])->str;
								binding=-2;
								printf("\tDeallocating ltable...\n");
								ldealloc(lhead);
								printf("~~~~~~~~~~~~~~~~~~~~~~\n");
								lhead=NULL;
								phead=NULL;
								equiv=1;
								ttint=1;}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 189 "expr.y" /* yacc.c:1646  */
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
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 212 "expr.y" /* yacc.c:1646  */
    {	binding=0;}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 213 "expr.y" /* yacc.c:1646  */
    {lprint();initflag=allocflag=0;tint=1;}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 216 "expr.y" /* yacc.c:1646  */
    {}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 220 "expr.y" /* yacc.c:1646  */
    {if(equiv==1){
								binding--;
								LInstall((yyvsp[0])->str,type);}
							else
								PInstall((yyvsp[0])->str,type);}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 225 "expr.y" /* yacc.c:1646  */
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
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 258 "expr.y" /* yacc.c:1646  */
    {binding+=1;LInstall((yyvsp[0])->str,type);}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 260 "expr.y" /* yacc.c:1646  */
    {	binding=0;}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 261 "expr.y" /* yacc.c:1646  */
    {	funcname="main";
										printf("\tDeallocating ltable...\n");
										ldealloc(lhead);
										printf("~~~~~~~~~~~~~~~~~~~~~~\n");
										lhead=NULL;
										binding=0;
										GLookup("main")->type=TLookup("int");}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 268 "expr.y" /* yacc.c:1646  */
    {lprint();initflag=allocflag=0;}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 269 "expr.y" /* yacc.c:1646  */
    {ldealloc(lhead);}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 273 "expr.y" /* yacc.c:1646  */
    {//$$=$2;
												struct tnode *ret=createtree(GLookup(funcname)->type,0,NULL,nt_RET,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);
												struct tnode *body=createtree(TLookup("void"),0,NULL,nt_NODE,(yyvsp[-4]),NULL,ret,NULL,NULL,NULL);
												funcGen(GLookup(funcname));
												if(allocflag>0 && initflag==0){//--------------main:init other:alloc???
													printf("Using ALLOC without INIT... You may run into something...!\n");}
												printf("CodeGen-ing '%s'\n",funcname);
												codeGen(body);
												printf("Finished CodeGen-ing of '%s'\n",funcname);
												printf("\tDeallocating BODY...\n");
												bdealloc(body);
												printf("~~~~~~~~~~~~~~~~~~~~~~\n");
												printf("################################################################################################\n");}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 286 "expr.y" /* yacc.c:1646  */
    {struct tnode *ret=createtree(GLookup(funcname)->type,0,NULL,nt_RET,NULL,(yyvsp[-1]),NULL,NULL,NULL,NULL);
												funcGen(GLookup(funcname));
												printf("CodeGen-ing '%s'\n",funcname);
												codeGen(ret);
												printf("Finished CodeGen-ing of '%s'\n",funcname);
												printf("\tDeallocating BODY...\n");
												bdealloc(ret);
												printf("~~~~~~~~~~~~~~~~~~~~~~\n");
												printf("################################################################################################\n");}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 295 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_NODE,(yyvsp[-1]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 296 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 297 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_READ,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 298 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WRITE,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 299 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WRITE,NULL,(yyvsp[-1]),NULL,NULL,NULL,NULL);}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 300 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_ASGN,(yyvsp[-3]),NULL,(yyvsp[-1]),NULL,NULL,NULL);}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 301 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_IFELSE,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]),NULL,NULL,NULL);}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 302 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_IF,(yyvsp[-5]),NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 303 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WHILE,(yyvsp[-5]),NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 304 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WHILE,(yyvsp[-2]),NULL,(yyvsp[-5]),NULL,NULL,NULL);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 305 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WHILE,(yyvsp[-2]),NULL,(yyvsp[-5]),NULL,NULL,NULL);}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 306 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_BREAK,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 307 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_CONTINUE,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 308 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_BRKP,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 309 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_EXIT,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 310 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_INIT,NULL,NULL,NULL,NULL,NULL,NULL);initflag++;}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 311 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),8/*GetSize(TLookup($1->str))*/,NULL,nt_ALLOC,NULL,(yyvsp[-5]),NULL,NULL,NULL,NULL);allocflag++;}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 312 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_FREE,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 314 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_PLUS,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 315 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_MINUS,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 316 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_MUL,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 317 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_DIV,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 318 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_MOD,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 319 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 320 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 321 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 322 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 323 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 324 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[-2]));(yyval)=createtree(GLookup((yyvsp[-2])->str)->type,0,(yyvsp[-2])->str,nt_FUNC,NULL,NULL,NULL,GLookup((yyvsp[-2])->str),NULL,NULL);}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 325 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[-3]));(yyval)=createtree(GLookup((yyvsp[-3])->str)->type,0,(yyvsp[-3])->str,nt_FUNC,NULL,NULL,NULL,GLookup((yyvsp[-3])->str),(yyvsp[-1]),NULL);}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 326 "expr.y" /* yacc.c:1646  */
    {(yyvsp[0])->down=(yyvsp[-2]);(yyval)=(yyvsp[0]);}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 327 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 328 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_LT,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 329 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_LE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 330 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_GT,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 331 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_GE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 332 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_EE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 333 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_NE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 334 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_TRUE,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 335 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_FALSE,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 336 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 337 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_NOT,NULL,(yyvsp[0]),NULL,NULL,NULL,NULL);}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 338 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_AND,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 339 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_OR,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 343 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[0]));
											(yyval)=createtree(LLookup((yyvsp[0])->str)==NULL?GLookup((yyvsp[0])->str)->type:LLookup((yyvsp[0])->str)->type,0,(yyvsp[0])->str,nt_ID,NULL,NULL,NULL,GLookup((yyvsp[0])->str),NULL,LLookup((yyvsp[0])->str));}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 345 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[-3]));(yyval)=createtree(LLookup((yyvsp[-3])->str)==NULL?GLookup((yyvsp[-3])->str)->type:LLookup((yyvsp[-3])->str)->type,0,(yyvsp[-3])->str,nt_ARR,NULL,(yyvsp[-1]),NULL,GLookup((yyvsp[-3])->str),NULL,LLookup((yyvsp[-3])->str));}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 348 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(GLookup((yyvsp[0])->str)->type,(yyvsp[0])->num,(yyvsp[0])->str,nt_SPTR,NULL,NULL,NULL,GLookup((yyvsp[0])->str),NULL,LLookup((yyvsp[-1])->str));}
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 349 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(GLookup((yyvsp[0])->str)->type,(yyvsp[0])->num,(yyvsp[0])->str,nt_APTR,NULL,NULL,NULL,GLookup((yyvsp[0])->str),NULL,LLookup((yyvsp[-1])->str));}
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 359 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);(yyval)->nt=nt_USERROOT;}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 360 "expr.y" /* yacc.c:1646  */
    {struct Typetable *ttemp=(yyvsp[-2])->t;
											checktype(ttemp,(yyvsp[0])->str);
											struct Fieldlist *ftemp=FLookmember(ttemp,(yyvsp[0])->str);
											(yyval)=createtree(ftemp->type,ftemp->fieldIndex,(yyvsp[0])->str,nt_USERNODE,(yyvsp[-2]),NULL,NULL,(yyvsp[-2])->Gentry,NULL,(yyvsp[-2])->Lentry);}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 364 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[-2]));
											struct Typetable *ttemp=LLookup((yyvsp[-2])->str)==NULL?GLookup((yyvsp[-2])->str)->type:LLookup((yyvsp[-2])->str)->type;
											struct Fieldlist *ftemp=FLookup(ttemp,(yyvsp[0])->str);
											checktype(ttemp,(yyvsp[0])->str);
											struct tnode *node=createtree(ttemp,0,(yyvsp[-2])->str,nt_USERNODE,NULL,NULL,NULL,GLookup((yyvsp[-2])->str),NULL,LLookup((yyvsp[-2])->str));
											(yyval)=createtree(ftemp->type,ftemp->fieldIndex,(yyvsp[0])->str,nt_USERNODE,node,NULL,NULL,GLookup((yyvsp[-2])->str),NULL,LLookup((yyvsp[-2])->str));}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2230 "y.tab.c" /* yacc.c:1646  */
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
#line 371 "expr.y" /* yacc.c:1906  */

void checkid(struct tnode *t){
	if(LLookup(t->str)==NULL && GLookup(t->str)==NULL){
		printf("Undeclared identifier:'%s' at line:'%d'\n",t->str,line);
		exit(1);}}
/*void checkidid(struct tnode *t1,struct tnode *t3){
	struct Gsymbol *gtemp=GLookup(t1->str);
	struct Lsymbol *ltemp=LLookup(t1->str);
	struct Typetable *ttemp;
	if(gtemp==NULL && ltemp==NULL){
		printf("line:'%d'\tUndeclared type:'%s' in type:'%s'\n",line,t1->str,t3->str);
		exit(1);}
	if(ltemp==NULL)
		ttemp=gtemp->type;
	else
		ttemp=ltemp->type;
	struct Fieldlist *ftemp=t1->fields;
	if(FLookup(ttemp,t3->str)==NULL){
		printf("line:'%d'\tNo member '%s' in type '%s'\n",line,t3->str,t1->str);
		exit(1);}}*/
void checktype(struct Typetable *t1, char *member){
	if(FLookmember(t1,member)==NULL){
		printf("line:'%d'\tUndeclared type with name:'%s' in type:'%s'\n",line,member,t1->name);
		exit(1);
	return;}}
void yyerror(char const *s){
	printf("yyerror %s\nLine:%d at '%s'\n",s,line,yytext);
	if(strcmp(yytext,"end")==0)
		printf("Did you use a return statement...!\n");
	exit(1);}
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
void ldealloc(struct Lsymbol *lhead){
	if(lhead==NULL)
		return;
	printf("%d.funcname:'%s'\tname:'%s'\n",ttint++,funcname,lhead->name);
	ldealloc(lhead->next);
	free(lhead->next);}
void bdealloc(struct tnode *body){
	if(body==NULL)
		return;
	printf("%d.funcname:'%s'\tnt:'%d'\n",tint++,funcname,body->nt);
	bdealloc(body->left);
	free(body->left);
	bdealloc(body->down);
	free(body->down);
	bdealloc(body->right);
	free(body->right);}
int main(){
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

