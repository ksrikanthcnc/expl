/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
