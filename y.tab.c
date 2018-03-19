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
	int mainflag=0,tolocal=0,tuplesize=0,typesize=0,initflag=0,allocflag=0,genflag=1;
	struct Typetable *type,*temptype,*t;
	char *tuplename;
	int tint=1,ttint=1;
	struct Classtable *class;

#line 87 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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

#line 258 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   572

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  281

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
      65,    66,     2,     2,    64,     2,    70,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    63,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,     2,    68,     2,     2,     2,     2,     2,     2,
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
       0,    46,    46,    47,    47,    50,    51,    52,    53,    54,
      54,    57,    58,    60,    60,    66,    67,    68,    71,    71,
      71,    72,    73,    74,    75,    75,    83,    84,   112,   113,
     114,   116,   117,   118,   118,   126,   127,   129,   130,   132,
     133,   134,   135,   141,   142,   143,   151,   152,   153,   152,
     159,   160,   162,   172,   195,   196,   162,   199,   200,   201,
     202,   203,   210,   211,   212,   213,   214,   215,   216,   217,
     219,   220,   227,   219,   231,   249,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   293,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   312,   315,   317,   318,   319,   320,   339,   363
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
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
  "'{'", "'}'", "';'", "','", "'('", "')'", "'['", "']'", "'&'", "'.'",
  "$accept", "start", "Program", "$@1", "TDeclBlock", "TStructs",
  "TStruct", "$@2", "TFields", "TField", "$@3", "VList", "Vid",
  "CDeclBlock", "$@4", "$@5", "CDefList", "CDef", "$@6", "Cname",
  "Fieldlists", "Fld", "MethodDecl", "MDecl", "$@7", "MethodDefns",
  "GDeclBlock", "GDeclList", "GDecl", "Type", "GidList", "Gid", "$@8",
  "$@9", "FDefBlock", "FDef", "$@10", "$@11", "$@12", "$@13", "ParamList",
  "Param", "Pid", "LDeclBlock", "LDecList", "LDecl", "IdList", "Lid",
  "MainBlock", "$@14", "$@15", "$@16", "Body", "Slist", "Stmt", "Expr",
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
     315,   123,   125,    59,    44,    40,    41,    91,    93,    38,
      46
};
# endif

#define YYPACT_NINF -150

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-150)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,  -150,    35,  -150,   -20,    15,  -150,  -150,    12,   -19,
    -150,  -150,    62,  -150,  -150,  -150,    31,    62,  -150,    25,
       8,    68,    68,   118,    73,  -150,    96,  -150,  -150,  -150,
     132,   103,   142,  -150,     6,  -150,  -150,  -150,  -150,  -150,
     -10,    29,  -150,  -150,  -150,    82,  -150,  -150,   146,   150,
    -150,   154,  -150,   132,    93,  -150,  -150,    34,  -150,   157,
    -150,     9,  -150,    68,   106,  -150,   105,    68,  -150,   146,
      48,   168,  -150,  -150,   177,   119,  -150,  -150,   123,    54,
    -150,  -150,  -150,   120,    68,  -150,  -150,    68,   122,  -150,
    -150,    68,    11,  -150,  -150,  -150,   153,   128,    98,  -150,
    -150,    68,  -150,  -150,   134,   194,    14,  -150,   187,   153,
    -150,  -150,    45,  -150,  -150,  -150,   248,   137,  -150,  -150,
     194,   -40,    37,   138,     2,   139,   140,   438,   143,   149,
     438,   174,   152,   155,   151,   156,   159,    37,   290,  -150,
     208,   160,  -150,   187,  -150,   174,   219,  -150,    37,   162,
     174,   111,   111,   470,  -150,  -150,   332,  -150,  -150,  -150,
     166,   174,   303,   170,  -150,  -150,    37,    37,   223,  -150,
     174,  -150,   121,   234,   178,    53,  -150,   181,  -150,   185,
    -150,  -150,   111,   111,   512,    10,    21,   183,   184,   246,
     201,   174,   174,   174,   174,   174,   238,   148,   188,   189,
    -150,   315,   195,   196,   345,  -150,  -150,  -150,   199,   205,
    -150,   495,    41,   174,   174,   174,   174,   174,   174,   111,
     111,   240,   245,   111,   111,   206,  -150,   131,   131,  -150,
    -150,  -150,  -150,  -150,   273,   104,   212,  -150,   269,   220,
     221,  -150,  -150,  -150,  -150,   273,   273,   273,   273,   273,
     273,  -150,  -150,   438,   438,    46,    51,  -150,   174,  -150,
    -150,  -150,   228,   229,   216,   364,   -24,   230,   273,  -150,
    -150,   438,   233,   236,  -150,  -150,   406,  -150,  -150,   237,
    -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     8,     0,     2,    21,     0,     1,    18,    38,     0,
       5,     7,     0,    40,    51,     9,    26,    19,    23,     0,
       0,     3,     0,     0,     0,    22,     0,    42,    37,    39,
       0,     0,     0,    50,     0,    12,    13,    27,    20,    29,
      45,     0,    44,    70,     4,     0,    10,    11,     0,     0,
      47,     0,    41,     0,     0,    52,    17,     0,    16,     0,
      28,     0,    32,    59,     0,    43,     0,    59,    14,     0,
       0,     0,    24,    31,     0,    48,    58,    46,     0,     0,
      15,    30,    33,     0,     0,    61,    60,     0,     0,    71,
      53,    59,     0,    36,    57,    49,    63,     0,     0,    25,
      35,     0,    72,    54,     0,     0,     0,    65,     0,    63,
      34,    69,     0,    68,    62,    64,     0,     0,    55,    66,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,   126,    73,     0,    67,     0,     0,   124,     0,     0,
       0,     0,     0,     0,    87,    88,     0,   101,   102,   104,
       0,     0,     0,   103,    89,    90,     0,     0,     0,   125,
       0,    76,     0,     0,     0,     0,   128,     0,    80,     0,
     116,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,     0,     0,   127,    56,   123,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,    95,    96,    97,
      98,    99,    75,   105,   109,     0,     0,    94,     0,     0,
       0,    81,    78,    79,   118,   110,   111,   112,   113,   114,
     115,   120,   121,     0,     0,     0,     0,   107,     0,   106,
      93,    74,     0,     0,     0,     0,     0,     0,   108,    91,
      92,     0,     0,     0,    86,    85,     0,    83,    84,     0,
      82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   263,
    -150,  -150,   235,  -150,  -150,  -150,  -150,   286,  -150,  -150,
    -150,  -150,  -150,   244,  -150,  -150,  -150,  -150,  -150,     4,
    -150,   261,  -150,  -150,  -150,   -76,  -150,  -150,  -150,  -150,
     -39,   239,  -150,   218,  -150,   222,  -150,   209,  -150,  -150,
    -150,  -150,   190,  -126,  -133,  -114,  -150,  -149,  -116,  -150
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    31,     4,     5,    11,    22,    34,    35,
      48,    57,    58,     8,    12,    24,    17,    18,    84,    19,
      49,    60,    61,    62,    91,    92,    14,    20,    29,    74,
      41,    42,    63,    88,    21,    33,    67,    97,   109,   143,
      75,    76,    86,   102,   106,   107,   112,   113,    44,    54,
      96,   108,   117,   138,   139,   184,   235,   185,   163,   141
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     140,   153,   254,   186,   156,   171,   147,   149,    93,     1,
      27,   140,    27,    71,   140,    27,   100,   162,    27,     9,
     171,   169,   140,   171,    30,    32,    36,   145,    79,     7,
     146,   175,   177,   210,   212,     6,   179,   140,    36,   274,
     140,   121,    15,    28,    72,   122,    13,   190,    10,   114,
     198,   199,    98,   219,   220,    50,   201,    51,   204,   191,
     192,   193,   194,   195,   219,   220,    16,   150,    46,   211,
     251,   252,    27,    99,   255,   256,   221,   227,   228,   229,
     230,   231,    23,   234,   219,   220,    26,   222,    32,   219,
     220,   136,    52,    53,   219,   220,    32,    68,    69,   245,
     246,   247,   248,   249,   250,   105,   137,   244,   119,   120,
     105,    81,   266,    82,   157,   121,   158,   267,    87,   122,
      90,   207,    37,    38,   157,   121,   158,   264,   265,   122,
      39,   171,   171,   180,   181,   182,    40,   140,   140,   193,
     194,   195,    43,   171,   268,   276,    45,    55,   140,   140,
      56,   157,   121,   158,    59,   140,   122,    64,    66,   159,
     140,    70,    87,   160,   104,   136,   202,   203,   258,   159,
     259,    78,    83,   160,    77,   136,   183,   157,   121,   158,
     137,    85,   122,    87,    89,    82,   161,   101,    95,   103,
     137,   191,   192,   193,   194,   195,   159,   110,   111,   142,
     160,   116,   136,   148,   151,   152,   154,   191,   192,   193,
     194,   195,   155,   161,   233,   164,   166,   137,   165,   172,
     121,   167,   159,   176,   122,   178,   160,   200,   136,   168,
     173,   189,   123,   124,   125,   197,   271,   272,   205,   161,
     206,   126,   127,   137,   128,   129,   130,   208,   223,   224,
     225,   209,   121,   232,   236,   237,   122,   132,   133,   253,
     239,   240,   242,   134,   123,   124,   125,   226,   243,   135,
     136,   254,   257,   126,   127,   260,   128,   129,   130,   191,
     192,   193,   194,   195,   261,   137,   262,   263,   131,   132,
     133,   269,   270,   275,   121,   134,   277,    47,   122,   278,
     280,   135,   136,    25,    80,    73,   123,   124,   125,   191,
     192,   193,   194,   195,    65,   126,   127,   137,   128,   129,
     130,   191,   192,   193,   194,   195,    94,   118,   115,   144,
     170,   132,   133,   174,     0,     0,   121,   134,     0,     0,
     122,     0,     0,   135,   136,     0,     0,     0,   123,   124,
     125,   191,   192,   193,   194,   195,     0,   126,   127,   137,
     128,   129,   130,   188,     0,     0,   196,     0,   121,     0,
       0,     0,   122,   132,   133,     0,     0,     0,   238,   134,
     123,   124,   125,     0,     0,   135,   136,     0,     0,   126,
     127,   273,   128,   129,   130,     0,     0,     0,     0,     0,
       0,   137,     0,     0,     0,   132,   133,     0,   241,     0,
     121,   134,     0,     0,   122,     0,     0,   135,   136,     0,
       0,     0,   123,   124,   125,     0,     0,   279,     0,     0,
       0,   126,   127,   137,   128,   129,   130,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,   132,   133,     0,
       0,     0,     0,   134,   123,   124,   125,     0,     0,   135,
     136,     0,     0,   126,   127,     0,   128,   129,   130,     0,
       0,     0,     0,     0,   121,   137,     0,     0,   122,   132,
     133,     0,     0,     0,     0,   134,   123,   124,   125,     0,
       0,   135,   136,     0,     0,   187,   127,     0,   128,   129,
     130,   191,   192,   193,   194,   195,     0,   137,     0,     0,
       0,   132,   133,     0,     0,     0,     0,   134,   191,   192,
     193,   194,   195,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     213,   214,   215,   216,   217,   218,     0,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,   213,   214,   215,
     216,   217,   218
};

static const yytype_int16 yycheck[] =
{
     116,   127,    26,   152,   130,   138,   122,     5,    84,    32,
       4,   127,     4,     4,   130,     4,    92,   131,     4,     4,
     153,   137,   138,   156,    20,    21,    22,    67,    67,    49,
      70,   145,   148,   182,   183,     0,   150,   153,    34,    63,
     156,     4,    61,    35,    35,     8,    34,   161,    33,    35,
     166,   167,    91,    43,    44,    65,   170,    67,   172,     6,
       7,     8,     9,    10,    43,    44,     4,    65,    62,   183,
     219,   220,     4,    62,   223,   224,    66,   191,   192,   193,
     194,   195,    51,   197,    43,    44,    61,    66,    84,    43,
      44,    54,    63,    64,    43,    44,    92,    63,    64,   213,
     214,   215,   216,   217,   218,   101,    69,    66,    63,    64,
     106,    63,    66,    65,     3,     4,     5,    66,    64,     8,
      66,    68,     4,    50,     3,     4,     5,   253,   254,     8,
      34,   264,   265,    22,    23,    24,     4,   253,   254,     8,
       9,    10,    39,   276,   258,   271,     4,    65,   264,   265,
       4,     3,     4,     5,     4,   271,     8,     3,    65,    48,
     276,     4,    64,    52,    66,    54,    45,    46,    64,    48,
      66,    66,     4,    52,    68,    54,    65,     3,     4,     5,
      69,     4,     8,    64,    61,    65,    65,    34,    66,    61,
      69,     6,     7,     8,     9,    10,    48,    63,     4,    62,
      52,    14,    54,    65,    65,    65,    63,     6,     7,     8,
       9,    10,    63,    65,    66,    63,    65,    69,    63,    11,
       4,    65,    48,     4,     8,    63,    52,     4,    54,    70,
      70,    65,    16,    17,    18,    65,    20,    21,     4,    65,
      62,    25,    26,    69,    28,    29,    30,    66,    65,    65,
       4,    66,     4,    15,    66,    66,     8,    41,    42,    19,
      65,    65,    63,    47,    16,    17,    18,    66,    63,    53,
      54,    26,    66,    25,    26,    63,    28,    29,    30,     6,
       7,     8,     9,    10,    15,    69,    66,    66,    40,    41,
      42,    63,    63,    63,     4,    47,    63,    34,     8,    63,
      63,    53,    54,    17,    69,    61,    16,    17,    18,     6,
       7,     8,     9,    10,    53,    25,    26,    69,    28,    29,
      30,     6,     7,     8,     9,    10,    87,   109,   106,   120,
      40,    41,    42,   143,    -1,    -1,     4,    47,    -1,    -1,
       8,    -1,    -1,    53,    54,    -1,    -1,    -1,    16,    17,
      18,     6,     7,     8,     9,    10,    -1,    25,    26,    69,
      28,    29,    30,    31,    -1,    -1,    63,    -1,     4,    -1,
      -1,    -1,     8,    41,    42,    -1,    -1,    -1,    63,    47,
      16,    17,    18,    -1,    -1,    53,    54,    -1,    -1,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    41,    42,    -1,    63,    -1,
       4,    47,    -1,    -1,     8,    -1,    -1,    53,    54,    -1,
      -1,    -1,    16,    17,    18,    -1,    -1,    21,    -1,    -1,
      -1,    25,    26,    69,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,     4,    -1,    -1,    -1,     8,    41,    42,    -1,
      -1,    -1,    -1,    47,    16,    17,    18,    -1,    -1,    53,
      54,    -1,    -1,    25,    26,    -1,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,     4,    69,    -1,    -1,     8,    41,
      42,    -1,    -1,    -1,    -1,    47,    16,    17,    18,    -1,
      -1,    53,    54,    -1,    -1,    25,    26,    -1,    28,    29,
      30,     6,     7,     8,     9,    10,    -1,    69,    -1,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,    47,     6,     7,
       8,     9,    10,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    72,    73,    75,    76,     0,    49,    84,     4,
      33,    77,    85,    34,    97,    61,     4,    87,    88,    90,
      98,   105,    78,    51,    86,    88,    61,     4,    35,    99,
     100,    74,   100,   106,    79,    80,   100,     4,    50,    34,
       4,   101,   102,    39,   119,     4,    62,    80,    81,    91,
      65,    67,    63,    64,   120,    65,     4,    82,    83,     4,
      92,    93,    94,   103,     3,   102,    65,   107,    63,    64,
       4,     4,    35,    94,   100,   111,   112,    68,    66,   111,
      83,    63,    65,     4,    89,     4,   113,    64,   104,    61,
      66,    95,    96,   106,   112,    66,   121,   108,   111,    62,
     106,    34,   114,    61,    66,   100,   115,   116,   122,   109,
      63,     4,   117,   118,    35,   116,    14,   123,   114,    63,
      64,     4,     8,    16,    17,    18,    25,    26,    28,    29,
      30,    40,    41,    42,    47,    53,    54,    69,   124,   125,
     129,   130,    62,   110,   118,    67,    70,   129,    65,     5,
      65,    65,    65,   124,    63,    63,   124,     3,     5,    48,
      52,    65,   126,   129,    63,    63,    65,    65,    70,   129,
      40,   125,    11,    70,   123,   126,     4,   129,    63,   126,
      22,    23,    24,    65,   126,   128,   128,    25,    31,    65,
     126,     6,     7,     8,     9,    10,    63,    65,   129,   129,
       4,   126,    45,    46,   126,     4,    62,    68,    66,    66,
     128,   126,   128,    55,    56,    57,    58,    59,    60,    43,
      44,    66,    66,    65,    65,     4,    66,   126,   126,   126,
     126,   126,    15,    66,   126,   127,    66,    66,    63,    65,
      65,    63,    63,    63,    66,   126,   126,   126,   126,   126,
     126,   128,   128,    19,    26,   128,   128,    66,    64,    66,
      63,    15,    66,    66,   124,   124,    66,    66,   126,    63,
      63,    20,    21,    27,    63,    63,   124,    63,    63,    21,
      63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    74,    73,    75,    75,    76,    76,    78,
      77,    79,    79,    81,    80,    82,    82,    83,    85,    86,
      84,    84,    87,    87,    89,    88,    90,    90,    91,    91,
      92,    93,    93,    95,    94,    96,    96,    97,    97,    98,
      98,    99,   100,   101,   101,   102,   102,   103,   104,   102,
     105,   105,   107,   108,   109,   110,   106,   111,   111,   111,
     112,   113,   114,   114,   115,   115,   116,   117,   117,   118,
     120,   121,   122,   119,   123,   123,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   127,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   129,   130,   130,   130
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     6,     3,     0,     2,     0,     0,
       5,     2,     1,     0,     4,     3,     1,     1,     0,     0,
       5,     0,     2,     1,     0,     9,     1,     3,     2,     0,
       3,     2,     1,     0,     7,     2,     1,     3,     0,     2,
       0,     3,     1,     3,     1,     1,     4,     0,     0,     6,
       2,     0,     0,     0,     0,     0,    13,     3,     1,     0,
       2,     1,     3,     0,     2,     1,     3,     3,     1,     1,
       0,     0,     0,    10,     6,     5,     2,     1,     5,     5,
       3,     4,    10,     8,     8,     7,     7,     2,     2,     2,
       2,     6,     6,     5,     4,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     3,     4,     4,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     3,     2,
       3,     3,     1,     4,     2,     2,     1,     3,     3,     3
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
#line 47 "expr.y" /* yacc.c:1646  */
    {generate();}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 47 "expr.y" /* yacc.c:1646  */
    {printf("Syntax Matched\n");}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 50 "expr.y" /* yacc.c:1646  */
    {tprint();}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 54 "expr.y" /* yacc.c:1646  */
    {TInstall((yyvsp[-1])->str,0,NULL);fhead=NULL;fieldindex=0;typesize=0;}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 55 "expr.y" /* yacc.c:1646  */
    {TLookup((yyvsp[-4])->str)->fields=fhead;TLookup((yyvsp[-4])->str)->size=typesize;}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 60 "expr.y" /* yacc.c:1646  */
    {	type=TLookup((yyvsp[0])->str);
											if(type==NULL){
												printf("line:'%d'\ttype:'%s' undeclared\n",line,(yyvsp[0])->str);
												exit(1);}}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 68 "expr.y" /* yacc.c:1646  */
    {FInstall((yyvsp[0])->str,fieldindex++,type);typesize++;}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 71 "expr.y" /* yacc.c:1646  */
    {classflag=1;cindex=0;}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 71 "expr.y" /* yacc.c:1646  */
    {classflag=0;}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 71 "expr.y" /* yacc.c:1646  */
    {cprint();}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 75 "expr.y" /* yacc.c:1646  */
    {CLookup((yyvsp[-5])->str)->memberfield=fhead;
							 									CLookup((yyvsp[-5])->str)->memberfunc=mhead;}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 77 "expr.y" /* yacc.c:1646  */
    {if(class->fieldcount>7) {printf("line:'%d'\t>7 fields declared in class:'%s'\n",line,(yyvsp[-8])->str); exit(1);}
							 													if(class->methodcount>7) {printf("line:'%d'\t>7 methods declared in class:'%s'\n",line,(yyvsp[-8])->str);exit(1);}
							 													class->fieldcount=fieldcount;
							 													class->methodcount=methodcount;
																				fhead=NULL;mhead=NULL;funcposition=0;fieldindex=0;gbinding+=8;fieldcount=methodcount=0;}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 83 "expr.y" /* yacc.c:1646  */
    {class=CInstall((yyvsp[0])->str,NULL);(yyval)=(yyvsp[0]);}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 84 "expr.y" /* yacc.c:1646  */
    {struct Classtable *parent=CLookup((yyvsp[0])->str);
									struct Classtable *new=malloc(sizeof(struct Classtable));
									new->name=(yyvsp[-2])->str;
									if(parent==NULL){
										printf("line:'%d'\tNo parent class:'%s' to extend from\n",line,(yyvsp[0])->str);
										exit(1);}
									fhead=new->memberfield=parent->memberfield;
									if(fhead!=NULL){
										fieldindex=fhead->fieldindex;fieldindex++;}
									else{
										fieldindex=0;
									}
									mhead=new->memberfunc=parent->memberfunc;
									if(mhead!=NULL){
										funcposition=mhead->funcposition;funcposition++;}
									else{
										funcposition=0;
									}
									new->parent=parent;
									new->index=cindex++;
									fieldcount=new->fieldcount=parent->fieldcount;
									methodcount=new->methodcount=parent->methodcount;
									new->next=chead;
									chead=new;
									class=new;
									(yyval)=(yyvsp[-2]);}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 114 "expr.y" /* yacc.c:1646  */
    {CFInstall((yyvsp[-2])->str,(yyvsp[-1])->str);fieldcount++;}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 118 "expr.y" /* yacc.c:1646  */
    {phead=NULL;}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 119 "expr.y" /* yacc.c:1646  */
    {CMInstall((yyvsp[-5])->str,TLookup((yyvsp[-6])->str),phead);methodcount++;
												if(class->parent!=NULL && CMLookup(class->parent,(yyvsp[-5])->str)!=NULL){
													funcposition--;
													methodcount--;
													mhead->funcposition=CMLookup(class->parent,(yyvsp[-5])->str)->funcposition;
												}}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 129 "expr.y" /* yacc.c:1646  */
    {gprint();}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 130 "expr.y" /* yacc.c:1646  */
    {printf("No Globals declared!\n");}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 135 "expr.y" /* yacc.c:1646  */
    {	type=TLookup((yyvsp[0])->str);
												ctype=CLookup((yyvsp[0])->str);
												if(type==NULL && ctype==NULL){
													printf("line:'%d'\tno type or class:'%s'\n",line,(yyvsp[0])->str);
													exit(1);}
												(yyval)=(yyvsp[0]);}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 143 "expr.y" /* yacc.c:1646  */
    {if(type!=NULL){//type
															if(strcmp(type->name,"void")==0 || strcmp(type->name,"null")==0){
																	printf("line:'%d'\tSorry, you cant declare that type...!\n",line);
																	exit(1);}
															GInstall((yyvsp[0])->str,type,1);}
														else{//class
															GInstall((yyvsp[0])->str,NULL,2);
															GLookup((yyvsp[0])->str)->class=ctype;}}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 151 "expr.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3])->str,type,(yyvsp[-1])->num);}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 152 "expr.y" /* yacc.c:1646  */
    {phead=NULL;temptype=type;}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 153 "expr.y" /* yacc.c:1646  */
    {type=temptype;}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 154 "expr.y" /* yacc.c:1646  */
    {	GInstall((yyvsp[-5])->str,type,0);//-------------------------------------------------------
											GLookup((yyvsp[-5])->str)->paramlist=phead;
											GLookup((yyvsp[-5])->str)->flabel=flabel++;}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 162 "expr.y" /* yacc.c:1646  */
    {	checkid((yyvsp[-1]));
								funcname=(yyvsp[-1])->str;
								binding=-2;
								printf("\tDeallocating ltable...\n");
								ldealloc(lhead);
								printf("~~~~~~~~~~~~~~~~~~~~~~\n");
								lhead=NULL;
								phead=NULL;
								tolocal=1;
								ttint=1;}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 172 "expr.y" /* yacc.c:1646  */
    {	tolocal=0;
											struct Lsymbol *ltemp;
											struct Paramstruct *ptemp;
											ptemp=ghead->flabel==FMAIN?CMLookup(class,funcname)->paramlist:GLookup((yyvsp[-4])->str)->paramlist;
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
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 195 "expr.y" /* yacc.c:1646  */
    {	heapbinding=binding-1;binding=0;}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 196 "expr.y" /* yacc.c:1646  */
    {lprint();initflag=allocflag=0;tint=1;}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 203 "expr.y" /* yacc.c:1646  */
    {if(tolocal==1){
								binding--;
								LInstall((yyvsp[0])->str,type);}
							else
								PInstall((yyvsp[0])->str,type);}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 217 "expr.y" /* yacc.c:1646  */
    {binding+=1;LInstall((yyvsp[0])->str,type);}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 219 "expr.y" /* yacc.c:1646  */
    {	binding=0;}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 220 "expr.y" /* yacc.c:1646  */
    {	funcname="main";
										printf("\tDeallocating ltable...\n");
										ldealloc(lhead);
										printf("~~~~~~~~~~~~~~~~~~~~~~\n");
										lhead=NULL;
										binding=0;
										GLookup("main")->type=TLookup("int");}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 227 "expr.y" /* yacc.c:1646  */
    {lprint();initflag=allocflag=0;}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 228 "expr.y" /* yacc.c:1646  */
    {ldealloc(lhead);}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 231 "expr.y" /* yacc.c:1646  */
    {//$$=$2;
												struct tnode *ret=createtree(ghead->flabel==FMAIN?CMLookup(class,funcname)->type:GLookup(funcname)->type,0,NULL,nt_RET,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);
												struct tnode *body=createtree(TLookup("void"),0,NULL,nt_NODE,(yyvsp[-4]),NULL,ret,NULL,NULL,NULL);
											
											
											
												funcGen(funcname);
												if(allocflag>0 && initflag==0){//--------------main:init other:alloc???
													printf("Using ALLOC without INIT... You may run into something...!\n");}
												printf("CodeGen-ing '%s'\n",funcname);
												codeGen(body);
												printf("Finished CodeGen-ing of '%s'\n",funcname);
												printf("\tDeallocating BODY...\n");
												bdealloc(body);
												printf("~~~~~~~~~~~~~~~~~~~~~~\n");
												printf("################################################################################################\n");}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 249 "expr.y" /* yacc.c:1646  */
    {struct tnode *ret=createtree(ghead->flabel==FMAIN?CMLookup(class,funcname)->type:GLookup(funcname)->type,0,NULL,nt_RET,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);
												funcGen(funcname);
												printf("CodeGen-ing '%s'\n",funcname);
												codeGen(ret);
												printf("Finished CodeGen-ing of '%s'\n",funcname);
												printf("\tDeallocating BODY...\n");
												bdealloc(ret);
												printf("~~~~~~~~~~~~~~~~~~~~~~\n");
												printf("################################################################################################\n");}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 258 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_NODE,(yyvsp[-1]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 259 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 260 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_READ,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 261 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WRITE,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 262 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WRITE,NULL,(yyvsp[-1]),NULL,NULL,NULL,NULL);}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 263 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_ASGN,(yyvsp[-3]),NULL,(yyvsp[-1]),NULL,NULL,NULL);}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 264 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_IFELSE,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]),NULL,NULL,NULL);}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 265 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_IF,(yyvsp[-5]),NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 266 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WHILE,(yyvsp[-5]),NULL,(yyvsp[-2]),NULL,NULL,NULL);}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 267 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WHILE,(yyvsp[-2]),NULL,(yyvsp[-5]),NULL,NULL,NULL);}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 268 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_WHILE,(yyvsp[-2]),NULL,(yyvsp[-5]),NULL,NULL,NULL);}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 269 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_BREAK,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 270 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_CONTINUE,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 271 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_BRKP,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 272 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_EXIT,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 273 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_INIT,NULL,(yyvsp[-5]),NULL,NULL,NULL,NULL);initflag++;}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 274 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),8/*GetSize(TLookup($1->str))*/,NULL,nt_ALLOC,NULL,(yyvsp[-5]),NULL,NULL,NULL,NULL);allocflag++;}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 275 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_FREE,NULL,(yyvsp[-2]),NULL,NULL,NULL,NULL);}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 276 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("void"),0,NULL,nt_DELETE,NULL,(yyvsp[-1]),NULL,NULL,NULL,NULL);}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 278 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_PLUS,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 279 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_MINUS,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 280 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_MUL,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 281 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_DIV,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 282 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("int"),0,NULL,nt_MOD,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 283 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 284 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 285 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 286 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 287 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 288 "expr.y" /* yacc.c:1646  */
    {/*checkid($1);$$=createtree($1->t,0,$1->str,nt_FUNC,NULL,NULL,NULL,GLookup($1->str),NULL,NULL);*/(yyval)=(yyvsp[-2]);(yyval)->nt=nt_FUNC;}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 289 "expr.y" /* yacc.c:1646  */
    {/*checkid($1);*/
										//$$=createtree($1->t,0,$1->str,nt_FUNC,NULL,NULL,NULL,GLookup($1->str),$3,NULL);
										(yyval)=(yyvsp[-3]);(yyval)->nt=nt_FUNC;(yyval)->arglist=(yyvsp[-1]);
										}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 293 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(NULL,0,NULL,nt_NEW,NULL,(yyvsp[-1]),NULL,NULL,NULL,NULL);}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 295 "expr.y" /* yacc.c:1646  */
    {(yyvsp[0])->down=(yyvsp[-2]);(yyval)=(yyvsp[0]);}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 296 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 297 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_LT,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 298 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_LE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 299 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_GT,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 300 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_GE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 301 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_EE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 302 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_NE,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 303 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_TRUE,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 304 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_FALSE,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 305 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 306 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_NOT,NULL,(yyvsp[0]),NULL,NULL,NULL,NULL);}
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 307 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_AND,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 308 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(TLookup("bool"),0,NULL,nt_OR,(yyvsp[-2]),NULL,(yyvsp[0]),NULL,NULL,NULL);}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 312 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[0]));
											(yyval)=createtree(LLookup((yyvsp[0])->str)==NULL?GLookup((yyvsp[0])->str)->type:LLookup((yyvsp[0])->str)->type,0,(yyvsp[0])->str,nt_ID,NULL,NULL,NULL,GLookup((yyvsp[0])->str),NULL,LLookup((yyvsp[0])->str));
											if(classflag==0) (yyval)->class=LLookup((yyvsp[0])->str)==NULL?GLookup((yyvsp[0])->str)->class:NULL;}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 315 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[-3]));
											(yyval)=createtree(LLookup((yyvsp[-3])->str)==NULL?GLookup((yyvsp[-3])->str)->type:LLookup((yyvsp[-3])->str)->type,0,(yyvsp[-3])->str,nt_ARR,NULL,(yyvsp[-1]),NULL,GLookup((yyvsp[-3])->str),NULL,LLookup((yyvsp[-3])->str));}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 317 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(GLookup((yyvsp[0])->str)->type,(yyvsp[0])->num,(yyvsp[0])->str,nt_SPTR,NULL,NULL,NULL,GLookup((yyvsp[0])->str),NULL,LLookup((yyvsp[-1])->str));}
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 318 "expr.y" /* yacc.c:1646  */
    {(yyval)=createtree(GLookup((yyvsp[0])->str)->type,(yyvsp[0])->num,(yyvsp[0])->str,nt_APTR,NULL,NULL,NULL,GLookup((yyvsp[0])->str),NULL,LLookup((yyvsp[-1])->str));}
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 319 "expr.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 320 "expr.y" /* yacc.c:1646  */
    {struct Typetable *ttemp=(yyvsp[-2])->t;
											struct Typetable *tttemp;
											int findex;
											struct Fieldlist *ftemp;
											struct Classtable *classs;
											struct Memberfunclist *mtemp;
											if(ttemp!=NULL){//type
												checktype(ttemp,(yyvsp[0])->str);
												ftemp=FLookmember(ttemp,(yyvsp[0])->str);
												tttemp=ftemp->type;findex=ftemp->fieldindex;}
											else{//class
												if(CFLookup((yyvsp[-2])->class,(yyvsp[0])->str)==NULL){//method	ol.findfact()
													mtemp=CMLookup(CFLookup((yyvsp[-2])->class,(yyvsp[-2])->str)->ctype,(yyvsp[0])->str);
													tttemp=mtemp->type;findex=mtemp->funcposition;}
												else{//field	ol.x
													ftemp=CFLookup(GLookup((yyvsp[-2])->str)->class,(yyvsp[0])->str);
													tttemp=ftemp->type;findex=ftemp->fieldindex;}}
											(yyvsp[-2])->nt=nt_USERNODE;
											(yyval)=createtree(tttemp,findex,(yyvsp[0])->str,nt_USERROOT,(yyvsp[-2]),NULL,NULL,(yyvsp[-2])->Gentry,NULL,(yyvsp[-2])->Lentry);}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 339 "expr.y" /* yacc.c:1646  */
    {checkid((yyvsp[-2]));
											checkmember((yyvsp[-2]),(yyvsp[0]));
											if(classflag==0) (yyvsp[-2])->class=LLookup((yyvsp[-2])->str)==NULL?GLookup((yyvsp[-2])->str)->class:NULL;
											struct Typetable *ttemp=LLookup((yyvsp[-2])->str)==NULL?GLookup((yyvsp[-2])->str)->type:LLookup((yyvsp[-2])->str)->type;
											struct Fieldlist *ftemp;
											struct Memberfunclist *mtemp;
											int findex;
											if(ttemp!=NULL){//type
												checktype(ttemp,(yyvsp[0])->str);
												ftemp=FLookmember(ttemp,(yyvsp[0])->str);
												ttemp=ftemp->type;findex=ftemp->fieldindex;}
											else{//class obj.init()
												if(CFLookup(GLookup((yyvsp[-2])->str)->class,(yyvsp[0])->str)==NULL){//method
													;
													/*mtemp=CMLookup(CFLookup($1->class,$3->str)->ctype,$3->str);
													ttemp=mtemp->type;findex=mtemp->funcposition;*/
													//ftemp=CMLookup(GLookup($1->str)->class,$3->str)->type;
													}
												else{//field
													ftemp=CFLookup(GLookup((yyvsp[-2])->str)->class,(yyvsp[0])->str);
													ttemp=ftemp->type;findex=ftemp->fieldindex;}}
											struct tnode *node=createtree(ttemp,0,(yyvsp[-2])->str,nt_USERNODE,NULL,NULL,NULL,GLookup((yyvsp[-2])->str),NULL,LLookup((yyvsp[-2])->str));
											(yyval)=createtree(ttemp,findex,(yyvsp[0])->str,nt_USERROOT,node,NULL,NULL,GLookup((yyvsp[-2])->str),NULL,LLookup((yyvsp[-2])->str));
											if(classflag==0) (yyval)->class=LLookup((yyvsp[-2])->str)==NULL?GLookup((yyvsp[-2])->str)->class:NULL;}
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 363 "expr.y" /* yacc.c:1646  */
    {struct tnode *self=createtree((yyvsp[0])->t,heapbinding,(yyvsp[0])->str,nt_SELF,NULL,NULL,NULL,NULL,NULL,NULL);self->class=class;
											struct Typetable *typ;
											int field;
											if(CFLookup(class,(yyvsp[0])->str)!=NULL){//Field
												typ=CFLookup(class,(yyvsp[0])->str)->type;
												field=CFLookup(class,(yyvsp[0])->str)->fieldindex;}
											else{//Method
												typ=CMLookup(class,(yyvsp[0])->str)->type;
												field=CMLookup(class,(yyvsp[0])->str)->funcposition;}
											(yyval)=createtree(typ,field,(yyvsp[0])->str,nt_USERROOT,self,NULL,NULL,NULL,NULL,LLookup((yyvsp[0])->str));
											(yyval)->class=class;}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2312 "y.tab.c" /* yacc.c:1646  */
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
#line 375 "expr.y" /* yacc.c:1906  */

void checkid(struct tnode *t){
	if(classflag==1){
		if(CFLookup(class,t->str)==NULL && CMLookup(class,t->str)==NULL && LLookup(t->str)==NULL){
			printf("Undeclared identifier:'%s' at line:'%d'\n",t->str,line);
			exit(1);}}
	else{
		if(LLookup(t->str)==NULL && GLookup(t->str)==NULL && CLookup(t->str)==NULL){
			printf("Undeclared identifier:'%s' at line:'%d'\n",t->str,line);
			exit(1);}}}
void checkmember(struct tnode *parent, struct tnode *member){
	struct Classtable *ctemp;
	if(LLookup(parent->str)==NULL){
		ctemp=GLookup(parent->str)->class;
		if(ctemp!=NULL && CFLookup(ctemp,member->str)==NULL && CMLookup(ctemp,member->str)==NULL){
			printf("line:'%d'\tno field or method:'%s' in class:'%s'\n",line,member->str,ctemp->name);
			exit(1);}}}
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
	fprintf(types,"\t\tType Declarations\n");
	struct Typetable *ttemp;
	struct Fieldlist *ftemp;
	ttemp=thead;
	while(ttemp){
		printf("name:'%s'\tsize:'%d'\n",ttemp->name,ttemp->size);
		fprintf(types,"name:'%s'\tsize:'%d'\n",ttemp->name,ttemp->size);
		ftemp=ttemp->fields;
		if(ftemp)
			printf("\tFields...\n");
			fprintf(types,"\tFields...\n");
		while(ftemp){
			if(ftemp->type!=NULL)
				printf("\tname:'%s'\tfieldIndex:'%d'\ttype:'%s'\n",ftemp->name,ftemp->fieldindex,ftemp->type->name);
				fprintf(types,"\tname:'%s'\tfieldIndex:'%d'\ttype:'%s'\n",ftemp->name,ftemp->fieldindex,ftemp->type->name);
			ftemp=ftemp->next;}
		ttemp=ttemp->next;}
	printf("######################################################\n");}
void gprint(){
	int i,j;
	printf("\t\tGlobal Table(Static size:'%d')\tgbinding:'%d'\n",gbinding-4096-8*(1+(chead==NULL?-1:chead->index)),gbinding);
	fprintf(globals,"\t\tGlobal Table(Static size:'%d')\n",gbinding-4096-8*(1+(chead==NULL?-1:chead->index)));
	struct Gsymbol* gtemp=ghead;
	struct Paramstruct* ptemp;
	printf("GLOBALS...\n");
	fprintf(globals,"GLOBALS...\n");
	i=1;
	while(gtemp!=NULL){
		if(gtemp->size>0){
			if(gtemp->type!=NULL){
				printf("%d.name:'%s'\ttype:'%s'\tsize:'%d'\tbase:'%d'\tarr:%d\n",i++,gtemp->name,gtemp->type->name,gtemp->size,gtemp->binding,gtemp->arr);
				fprintf(globals,"%d.name:'%s'\ttype:'%s'\tsize:'%d'\tbase:'%d'\tarr:%d\n",i++,gtemp->name,gtemp->type->name,gtemp->size,gtemp->binding,gtemp->arr);}
			else{
				printf("%d.name:'%s'\tclass:'%s'\tsize:'%d'\tbase:'%d'\tarr:%d\n",i++,gtemp->name,gtemp->class->name,gtemp->size,gtemp->binding,gtemp->arr);
				fprintf(globals,"%d.name:'%s'\tclass:'%s'\tsize:'%d'\tbase:'%d'\tarr:%d\n",i++,gtemp->name,gtemp->class->name,gtemp->size,gtemp->binding,gtemp->arr);}
		if(gtemp->paramlist){
			ptemp=gtemp->paramlist;
			printf("\tContent of type...\n");
			fprintf(globals,"\tContent of type...\n");
			while(ptemp){
				printf("\tname:'%s'\ttype:'%s'\n",ptemp->name,ptemp->type->name);
				fprintf(globals,"\tname:'%s'\ttype:'%s'\n",ptemp->name,ptemp->type->name);
				ptemp=ptemp->next;}}
			if(gtemp->paramlist)
				printf("\n");
				fprintf(globals,"\n");}
		gtemp=gtemp->next;}
	gtemp=ghead;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	fprintf(globals,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\n\n\n");
	printf("functions\n");
	fprintf(globals,"functions\n");
	i=1;
	while(gtemp!=NULL){
		if(gtemp->size==0 && gtemp->flabel!=FMAIN){
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
void cprint(){
	int i,j;
	struct Classtable *ctemp;
	ctemp=chead;
	printf("\t\tClass Table\n");
	while(ctemp){
		ctemp=ctemp;
		printf("Class:'%s'\tParent:'%s'\tindex:'%d'\tfieldcount:'%d'\tmethodcount:'%d'\n",ctemp->name,ctemp->parent!=NULL?ctemp->parent->name:"(null)",ctemp->index,ctemp->fieldcount,ctemp->methodcount);
		struct Fieldlist *ftemp;
		struct Memberfunclist *mtemp;
		struct Paramstruct *ptemp;
		printf("Members:\n");
		printf("\tFields\n");
		ftemp=ctemp->memberfield;
		i=1;
		while(ftemp){
			printf("\t%d.name:'%s'\tfieldindex:'%d'\t",i++,ftemp->name,ftemp->fieldindex);
			if(ftemp->type!=NULL)
				printf("type:'%s'\t",ftemp->type->name);
			else
				printf("type:'---'\t");
			if(ftemp->ctype!=NULL)
				printf("ctype:'%s'\n",ftemp->ctype->name);
			else
				printf("ctype:---\n");
			ftemp=ftemp->next;}
		printf("\tMethods\n");
		i=1;
		mtemp=ctemp->memberfunc;
		while(mtemp){
			printf("\t%d.name:'%s'\ttype:'%s'\tfuncposition:'%d'\tflabel:F'%d'\n",i++,mtemp->name,mtemp->type->name,mtemp->funcposition,mtemp->flabel);
			printf("\t\tparamters...\n");
			j=1;
			ptemp=mtemp->paramlist;
			while(ptemp){
				printf("\t\t%d.name:'%s'\ttype:'%s'\n",j,ptemp->name,ptemp->type->name);
				ptemp=ptemp->next;}
			printf("\n");
			mtemp=mtemp->next;}
		ctemp=ctemp->next;}
	printf("\n\n\n\n");}
void ldealloc(struct Lsymbol *lhead){
	if(lhead==NULL)
		return;
	//printf("%d.funcname:'%s'\tname:'%s'\n",ttint++,funcname,lhead->name);
	ldealloc(lhead->next);
	free(lhead->next);}
void bdealloc(struct tnode *body){
	if(body==NULL)
		return;
	//printf("%d.funcname:'%s'\tnt:'%d'\n",tint++,funcname,body->nt);
	bdealloc(body->left);
	free(body->left);
	bdealloc(body->down);
	free(body->down);
	bdealloc(body->right);
	free(body->right);}
void sigint_handler(int num){
	printf("\n\n\nSegmentation occured at line:'%d'\n",line);
	signal(SIGSEGV, SIG_DFL);
	raise(SIGSEGV);}
int main(){
	signal(SIGSEGV, sigint_handler);
	locals=fopen("locals","w+");
	globals=fopen("globals","w+");
	types=fopen("types","w+");
	classes=fopen("classes","w+");
	ghead=NULL;
	chead=NULL;
	FILE *fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else{
		printf("Input file error\n");
		exit(1);}
	#ifndef BUG
		target_file=fopen("intermediate.xsm","w+");
	#endif
	GInstall("main",TLookup("int"),0);
	GLookup("main")->flabel=FMAIN;
	TypeTableCreate();
	fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(target_file,"JMP F%d\n",TMAIN);
	yyparse();
	//print();
	return 0;}
//

