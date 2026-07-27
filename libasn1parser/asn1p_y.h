/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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

#ifndef YY_ASN1P_ASN1P_Y_H_INCLUDED
# define YY_ASN1P_ASN1P_Y_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int asn1p_debug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_PPEQ = 258,
     TOK_VBracketLeft = 259,
     TOK_VBracketRight = 260,
     TOK_whitespace = 261,
     TOK_opaque = 262,
     TOK_bstring = 263,
     TOK_cstring = 264,
     TOK_hstring = 265,
     TOK_identifier = 266,
     TOK_number = 267,
     TOK_number_negative = 268,
     TOK_realnumber = 269,
     TOK_tuple = 270,
     TOK_quadruple = 271,
     TOK_typereference = 272,
     TOK_capitalreference = 273,
     TOK_typefieldreference = 274,
     TOK_valuefieldreference = 275,
     TOK_Literal = 276,
     TOK_ExtValue_BIT_STRING = 277,
     TOK_ABSENT = 278,
     TOK_ABSTRACT_SYNTAX = 279,
     TOK_ALL = 280,
     TOK_ANY = 281,
     TOK_APPLICATION = 282,
     TOK_AUTOMATIC = 283,
     TOK_BEGIN = 284,
     TOK_BIT = 285,
     TOK_BMPString = 286,
     TOK_BOOLEAN = 287,
     TOK_BY = 288,
     TOK_CHARACTER = 289,
     TOK_CHOICE = 290,
     TOK_CLASS = 291,
     TOK_COMPONENT = 292,
     TOK_COMPONENTS = 293,
     TOK_CONSTRAINED = 294,
     TOK_CONTAINING = 295,
     TOK_DEFAULT = 296,
     TOK_DEFINITIONS = 297,
     TOK_DEFINED = 298,
     TOK_EMBEDDED = 299,
     TOK_ENCODED = 300,
     TOK_ENCODING_CONTROL = 301,
     TOK_END = 302,
     TOK_ENUMERATED = 303,
     TOK_EXPLICIT = 304,
     TOK_EXPORTS = 305,
     TOK_EXTENSIBILITY = 306,
     TOK_EXTERNAL = 307,
     TOK_FALSE = 308,
     TOK_FROM = 309,
     TOK_GeneralizedTime = 310,
     TOK_GeneralString = 311,
     TOK_GraphicString = 312,
     TOK_IA5String = 313,
     TOK_IDENTIFIER = 314,
     TOK_IMPLICIT = 315,
     TOK_IMPLIED = 316,
     TOK_IMPORTS = 317,
     TOK_INCLUDES = 318,
     TOK_INSTANCE = 319,
     TOK_INSTRUCTIONS = 320,
     TOK_INTEGER = 321,
     TOK_ISO646String = 322,
     TOK_MAX = 323,
     TOK_MIN = 324,
     TOK_MINUS_INFINITY = 325,
     TOK_NULL = 326,
     TOK_NumericString = 327,
     TOK_OBJECT = 328,
     TOK_ObjectDescriptor = 329,
     TOK_OCTET = 330,
     TOK_OF = 331,
     TOK_OPTIONAL = 332,
     TOK_PATTERN = 333,
     TOK_PDV = 334,
     TOK_PLUS_INFINITY = 335,
     TOK_PRESENT = 336,
     TOK_PrintableString = 337,
     TOK_PRIVATE = 338,
     TOK_REAL = 339,
     TOK_RELATIVE_OID = 340,
     TOK_SEQUENCE = 341,
     TOK_SET = 342,
     TOK_SIZE = 343,
     TOK_STRING = 344,
     TOK_SYNTAX = 345,
     TOK_T61String = 346,
     TOK_TAGS = 347,
     TOK_TeletexString = 348,
     TOK_TRUE = 349,
     TOK_TYPE_IDENTIFIER = 350,
     TOK_UNIQUE = 351,
     TOK_UNIVERSAL = 352,
     TOK_UniversalString = 353,
     TOK_UTCTime = 354,
     TOK_UTF8String = 355,
     TOK_VideotexString = 356,
     TOK_VisibleString = 357,
     TOK_WITH = 358,
     UTF8_BOM = 359,
     TOK_EXCEPT = 360,
     TOK_INTERSECTION = 361,
     TOK_UNION = 362,
     TOK_TwoDots = 363,
     TOK_ThreeDots = 364
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 112 "asn1p_y.y"

	asn1p_t			*a_grammar;
	asn1p_module_flags_e	 a_module_flags;
	asn1p_module_t		*a_module;
	asn1p_expr_type_e	 a_type;	/* ASN.1 Type */
	asn1p_expr_t		*a_expr;	/* Constructed collection */
	asn1p_constraint_t	*a_constr;	/* Constraint */
	enum asn1p_constraint_type_e	a_ctype;/* Constraint type */
	asn1p_xports_t		*a_xports;	/* IMports/EXports */
	struct AssignedIdentifier a_aid;	/* Assigned Identifier */
	asn1p_oid_t		*a_oid;		/* Object Identifier */
	asn1p_oid_arc_t		 a_oid_arc;	/* Single OID's arc */
	struct asn1p_type_tag_s	 a_tag;		/* A tag */
	asn1p_ref_t		*a_ref;		/* Reference to custom type */
	asn1p_wsyntx_t		*a_wsynt;	/* WITH SYNTAX contents */
	asn1p_wsyntx_chunk_t	*a_wchunk;	/* WITH SYNTAX chunk */
	struct asn1p_ref_component_s a_refcomp;	/* Component of a reference */
	asn1p_value_t		*a_value;	/* Number, DefinedValue, etc */
	struct asn1p_param_s	 a_parg;	/* A parameter argument */
	asn1p_paramlist_t	*a_plist;	/* A pargs list */
	struct asn1p_expr_marker_s a_marker;	/* OPTIONAL/DEFAULT */
	enum asn1p_constr_pres_e a_pres;	/* PRESENT/ABSENT/OPTIONAL */
	asn1c_integer_t		 a_int;
	double			 a_dbl;
	char	*tv_str;
	struct {
		char *buf;
		int len;
	}	tv_opaque;
	struct {
		char *name;
		struct asn1p_type_tag_s tag;
	} tv_nametag;


/* Line 2053 of yacc.c  */
#line 202 "asn1p_y.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE asn1p_lval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int asn1p_parse (void *YYPARSE_PARAM);
#else
int asn1p_parse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int asn1p_parse (void **param);
#else
int asn1p_parse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_ASN1P_ASN1P_Y_H_INCLUDED  */
