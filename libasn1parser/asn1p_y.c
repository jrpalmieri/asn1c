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


/* Substitute the variable and function names.  */
#define yyparse         asn1p_parse
#define yylex           asn1p_lex
#define yyerror         asn1p_error
#define yydebug         asn1p_debug
#define yynerrs         asn1p_nerrs
#define yylval          asn1p_lval
#define yychar          asn1p_char

/* First part of user prologue.  */
#line 1 "asn1p_y.y"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

#define YYERROR_VERBOSE
#define YYDEBUG 1
#define YYFPRINTF   prefixed_fprintf

/*
 * Prefix parser debug with "PARSER: " for easier human eye scanning.
 */
static int
__attribute__((format(printf, 2, 3)))
prefixed_fprintf(FILE *f, const char *fmt, ...) {
    static int line_ended = 1;
    va_list ap;
    va_start(ap, fmt);
    if(line_ended) {
        fprintf(f, "PARSER: ");
        line_ended = 0;
    }
    size_t len = strlen(fmt);
    if(len && fmt[len-1] == '\n') {
        line_ended = 1;
    }
    int ret = vfprintf(f, fmt, ap);
    va_end(ap);
    return ret;
}

int yylex(void);
static int yyerror(void **param, const char *msg);

void asn1p_lexer_hack_push_opaque_state(void);
void asn1p_lexer_hack_enable_with_syntax(void);
void asn1p_lexer_hack_push_encoding_control(void);
#define	yylineno	asn1p_lineno
extern int asn1p_lineno;
const char *asn1p_parse_debug_filename;
#define ASN_FILENAME asn1p_parse_debug_filename

/*
 * Process directives as <ASN1C:RepresentAsPointer>
 */
extern int asn1p_as_pointer;

/*
 * This temporary variable is used to solve the shortcomings of 1-lookahead
 * parser.
 */
static struct AssignedIdentifier *saved_aid;

static asn1p_value_t *_convert_bitstring2binary(char *str, int base);
static void _fixup_anonymous_identifier(asn1p_expr_t *expr);

static asn1p_module_t *currentModule;
#define	NEW_EXPR()	(asn1p_expr_new(yylineno, currentModule))

#define	checkmem(ptr)	do {						\
		if(!(ptr))						\
		return yyerror(param, "Memory failure");		\
	} while(0)

#define	CONSTRAINT_INSERT(root, constr_type, arg1, arg2) do {		\
		if(arg1->type != constr_type) {				\
			int __ret;					\
			root = asn1p_constraint_new(yylineno, currentModule);	\
			checkmem(root);					\
			root->type = constr_type;			\
			__ret = asn1p_constraint_insert(root,		\
				arg1);					\
			checkmem(__ret == 0);				\
		} else {						\
			root = arg1;					\
		}							\
		if(arg2) {						\
			int __ret					\
			= asn1p_constraint_insert(root, arg2);		\
			checkmem(__ret == 0);				\
		}							\
	} while(0)

#ifdef	AL_IMPORT
#error	AL_IMPORT DEFINED ELSEWHERE!
#endif
#define AL_IMPORT(to, where, from, field)                                      \
    do {                                                                       \
        if(!(from)) break;                                                     \
        while(TQ_FIRST(&((from)->where))) {                                    \
            TQ_ADD(&((to)->where), TQ_REMOVE(&((from)->where), field), field); \
        }                                                                      \
        assert(TQ_FIRST(&((from)->where)) == 0);                               \
    } while(0)


#line 181 "asn1p_y.c"

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

#include "asn1p_y.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_PPEQ = 3,                   /* TOK_PPEQ  */
  YYSYMBOL_TOK_VBracketLeft = 4,           /* TOK_VBracketLeft  */
  YYSYMBOL_TOK_VBracketRight = 5,          /* TOK_VBracketRight  */
  YYSYMBOL_TOK_whitespace = 6,             /* TOK_whitespace  */
  YYSYMBOL_TOK_opaque = 7,                 /* TOK_opaque  */
  YYSYMBOL_TOK_bstring = 8,                /* TOK_bstring  */
  YYSYMBOL_TOK_cstring = 9,                /* TOK_cstring  */
  YYSYMBOL_TOK_hstring = 10,               /* TOK_hstring  */
  YYSYMBOL_TOK_identifier = 11,            /* "identifier"  */
  YYSYMBOL_TOK_number = 12,                /* "number"  */
  YYSYMBOL_TOK_number_negative = 13,       /* "negative number"  */
  YYSYMBOL_TOK_realnumber = 14,            /* TOK_realnumber  */
  YYSYMBOL_TOK_tuple = 15,                 /* TOK_tuple  */
  YYSYMBOL_TOK_quadruple = 16,             /* TOK_quadruple  */
  YYSYMBOL_TOK_typereference = 17,         /* TOK_typereference  */
  YYSYMBOL_TOK_capitalreference = 18,      /* TOK_capitalreference  */
  YYSYMBOL_TOK_typefieldreference = 19,    /* TOK_typefieldreference  */
  YYSYMBOL_TOK_valuefieldreference = 20,   /* TOK_valuefieldreference  */
  YYSYMBOL_TOK_Literal = 21,               /* TOK_Literal  */
  YYSYMBOL_TOK_ExtValue_BIT_STRING = 22,   /* TOK_ExtValue_BIT_STRING  */
  YYSYMBOL_TOK_ABSENT = 23,                /* TOK_ABSENT  */
  YYSYMBOL_TOK_ABSTRACT_SYNTAX = 24,       /* TOK_ABSTRACT_SYNTAX  */
  YYSYMBOL_TOK_ALL = 25,                   /* TOK_ALL  */
  YYSYMBOL_TOK_ANY = 26,                   /* TOK_ANY  */
  YYSYMBOL_TOK_APPLICATION = 27,           /* TOK_APPLICATION  */
  YYSYMBOL_TOK_AUTOMATIC = 28,             /* TOK_AUTOMATIC  */
  YYSYMBOL_TOK_BEGIN = 29,                 /* TOK_BEGIN  */
  YYSYMBOL_TOK_BIT = 30,                   /* TOK_BIT  */
  YYSYMBOL_TOK_BMPString = 31,             /* TOK_BMPString  */
  YYSYMBOL_TOK_BOOLEAN = 32,               /* TOK_BOOLEAN  */
  YYSYMBOL_TOK_BY = 33,                    /* TOK_BY  */
  YYSYMBOL_TOK_CHARACTER = 34,             /* TOK_CHARACTER  */
  YYSYMBOL_TOK_CHOICE = 35,                /* TOK_CHOICE  */
  YYSYMBOL_TOK_CLASS = 36,                 /* TOK_CLASS  */
  YYSYMBOL_TOK_COMPONENT = 37,             /* TOK_COMPONENT  */
  YYSYMBOL_TOK_COMPONENTS = 38,            /* TOK_COMPONENTS  */
  YYSYMBOL_TOK_CONSTRAINED = 39,           /* TOK_CONSTRAINED  */
  YYSYMBOL_TOK_CONTAINING = 40,            /* TOK_CONTAINING  */
  YYSYMBOL_TOK_DEFAULT = 41,               /* TOK_DEFAULT  */
  YYSYMBOL_TOK_DEFINITIONS = 42,           /* TOK_DEFINITIONS  */
  YYSYMBOL_TOK_DEFINED = 43,               /* TOK_DEFINED  */
  YYSYMBOL_TOK_EMBEDDED = 44,              /* TOK_EMBEDDED  */
  YYSYMBOL_TOK_ENCODED = 45,               /* TOK_ENCODED  */
  YYSYMBOL_TOK_ENCODING_CONTROL = 46,      /* TOK_ENCODING_CONTROL  */
  YYSYMBOL_TOK_END = 47,                   /* TOK_END  */
  YYSYMBOL_TOK_ENUMERATED = 48,            /* TOK_ENUMERATED  */
  YYSYMBOL_TOK_EXPLICIT = 49,              /* TOK_EXPLICIT  */
  YYSYMBOL_TOK_EXPORTS = 50,               /* TOK_EXPORTS  */
  YYSYMBOL_TOK_EXTENSIBILITY = 51,         /* TOK_EXTENSIBILITY  */
  YYSYMBOL_TOK_EXTERNAL = 52,              /* TOK_EXTERNAL  */
  YYSYMBOL_TOK_FALSE = 53,                 /* TOK_FALSE  */
  YYSYMBOL_TOK_FROM = 54,                  /* TOK_FROM  */
  YYSYMBOL_TOK_GeneralizedTime = 55,       /* TOK_GeneralizedTime  */
  YYSYMBOL_TOK_GeneralString = 56,         /* TOK_GeneralString  */
  YYSYMBOL_TOK_GraphicString = 57,         /* TOK_GraphicString  */
  YYSYMBOL_TOK_IA5String = 58,             /* TOK_IA5String  */
  YYSYMBOL_TOK_IDENTIFIER = 59,            /* TOK_IDENTIFIER  */
  YYSYMBOL_TOK_IMPLICIT = 60,              /* TOK_IMPLICIT  */
  YYSYMBOL_TOK_IMPLIED = 61,               /* TOK_IMPLIED  */
  YYSYMBOL_TOK_IMPORTS = 62,               /* TOK_IMPORTS  */
  YYSYMBOL_TOK_INCLUDES = 63,              /* TOK_INCLUDES  */
  YYSYMBOL_TOK_INSTANCE = 64,              /* TOK_INSTANCE  */
  YYSYMBOL_TOK_INSTRUCTIONS = 65,          /* TOK_INSTRUCTIONS  */
  YYSYMBOL_TOK_INTEGER = 66,               /* TOK_INTEGER  */
  YYSYMBOL_TOK_ISO646String = 67,          /* TOK_ISO646String  */
  YYSYMBOL_TOK_MAX = 68,                   /* TOK_MAX  */
  YYSYMBOL_TOK_MIN = 69,                   /* TOK_MIN  */
  YYSYMBOL_TOK_MINUS_INFINITY = 70,        /* TOK_MINUS_INFINITY  */
  YYSYMBOL_TOK_NULL = 71,                  /* TOK_NULL  */
  YYSYMBOL_TOK_NumericString = 72,         /* TOK_NumericString  */
  YYSYMBOL_TOK_OBJECT = 73,                /* TOK_OBJECT  */
  YYSYMBOL_TOK_ObjectDescriptor = 74,      /* TOK_ObjectDescriptor  */
  YYSYMBOL_TOK_OCTET = 75,                 /* TOK_OCTET  */
  YYSYMBOL_TOK_OF = 76,                    /* TOK_OF  */
  YYSYMBOL_TOK_OPTIONAL = 77,              /* TOK_OPTIONAL  */
  YYSYMBOL_TOK_PATTERN = 78,               /* TOK_PATTERN  */
  YYSYMBOL_TOK_PDV = 79,                   /* TOK_PDV  */
  YYSYMBOL_TOK_PLUS_INFINITY = 80,         /* TOK_PLUS_INFINITY  */
  YYSYMBOL_TOK_PRESENT = 81,               /* TOK_PRESENT  */
  YYSYMBOL_TOK_PrintableString = 82,       /* TOK_PrintableString  */
  YYSYMBOL_TOK_PRIVATE = 83,               /* TOK_PRIVATE  */
  YYSYMBOL_TOK_REAL = 84,                  /* TOK_REAL  */
  YYSYMBOL_TOK_RELATIVE_OID = 85,          /* TOK_RELATIVE_OID  */
  YYSYMBOL_TOK_SEQUENCE = 86,              /* TOK_SEQUENCE  */
  YYSYMBOL_TOK_SET = 87,                   /* TOK_SET  */
  YYSYMBOL_TOK_SIZE = 88,                  /* TOK_SIZE  */
  YYSYMBOL_TOK_STRING = 89,                /* TOK_STRING  */
  YYSYMBOL_TOK_SYNTAX = 90,                /* TOK_SYNTAX  */
  YYSYMBOL_TOK_T61String = 91,             /* TOK_T61String  */
  YYSYMBOL_TOK_TAGS = 92,                  /* TOK_TAGS  */
  YYSYMBOL_TOK_TeletexString = 93,         /* TOK_TeletexString  */
  YYSYMBOL_TOK_TRUE = 94,                  /* TOK_TRUE  */
  YYSYMBOL_TOK_TYPE_IDENTIFIER = 95,       /* TOK_TYPE_IDENTIFIER  */
  YYSYMBOL_TOK_UNIQUE = 96,                /* TOK_UNIQUE  */
  YYSYMBOL_TOK_UNIVERSAL = 97,             /* TOK_UNIVERSAL  */
  YYSYMBOL_TOK_UniversalString = 98,       /* TOK_UniversalString  */
  YYSYMBOL_TOK_UTCTime = 99,               /* TOK_UTCTime  */
  YYSYMBOL_TOK_UTF8String = 100,           /* TOK_UTF8String  */
  YYSYMBOL_TOK_VideotexString = 101,       /* TOK_VideotexString  */
  YYSYMBOL_TOK_VisibleString = 102,        /* TOK_VisibleString  */
  YYSYMBOL_TOK_WITH = 103,                 /* TOK_WITH  */
  YYSYMBOL_UTF8_BOM = 104,                 /* "UTF-8 byte order mark"  */
  YYSYMBOL_TOK_EXCEPT = 105,               /* TOK_EXCEPT  */
  YYSYMBOL_106_ = 106,                     /* '^'  */
  YYSYMBOL_TOK_INTERSECTION = 107,         /* TOK_INTERSECTION  */
  YYSYMBOL_108_ = 108,                     /* '|'  */
  YYSYMBOL_TOK_UNION = 109,                /* TOK_UNION  */
  YYSYMBOL_TOK_TwoDots = 110,              /* ".."  */
  YYSYMBOL_TOK_ThreeDots = 111,            /* "..."  */
  YYSYMBOL_112_concrete_TypeDeclaration_ = 112, /* "concrete TypeDeclaration"  */
  YYSYMBOL_113_ = 113,                     /* '{'  */
  YYSYMBOL_114_ = 114,                     /* '}'  */
  YYSYMBOL_115_ = 115,                     /* '('  */
  YYSYMBOL_116_ = 116,                     /* ')'  */
  YYSYMBOL_117_ = 117,                     /* ';'  */
  YYSYMBOL_118_ = 118,                     /* ','  */
  YYSYMBOL_119_ = 119,                     /* ':'  */
  YYSYMBOL_120_ = 120,                     /* '['  */
  YYSYMBOL_121_ = 121,                     /* ']'  */
  YYSYMBOL_122_ = 122,                     /* '!'  */
  YYSYMBOL_123_ = 123,                     /* '.'  */
  YYSYMBOL_124_ = 124,                     /* '<'  */
  YYSYMBOL_125_ = 125,                     /* '@'  */
  YYSYMBOL_YYACCEPT = 126,                 /* $accept  */
  YYSYMBOL_ParsedGrammar = 127,            /* ParsedGrammar  */
  YYSYMBOL_ModuleList = 128,               /* ModuleList  */
  YYSYMBOL_ModuleDefinition = 129,         /* ModuleDefinition  */
  YYSYMBOL_130_1 = 130,                    /* $@1  */
  YYSYMBOL_optObjectIdentifier = 131,      /* optObjectIdentifier  */
  YYSYMBOL_ObjectIdentifier = 132,         /* ObjectIdentifier  */
  YYSYMBOL_ObjectIdentifierBody = 133,     /* ObjectIdentifierBody  */
  YYSYMBOL_ObjectIdentifierElement = 134,  /* ObjectIdentifierElement  */
  YYSYMBOL_optModuleDefinitionFlags = 135, /* optModuleDefinitionFlags  */
  YYSYMBOL_ModuleDefinitionFlags = 136,    /* ModuleDefinitionFlags  */
  YYSYMBOL_ModuleDefinitionFlag = 137,     /* ModuleDefinitionFlag  */
  YYSYMBOL_optModuleBody = 138,            /* optModuleBody  */
  YYSYMBOL_ModuleBody = 139,               /* ModuleBody  */
  YYSYMBOL_AssignmentList = 140,           /* AssignmentList  */
  YYSYMBOL_Assignment = 141,               /* Assignment  */
  YYSYMBOL_142_2 = 142,                    /* $@2  */
  YYSYMBOL_143_3 = 143,                    /* $@3  */
  YYSYMBOL_optImports = 144,               /* optImports  */
  YYSYMBOL_ImportsDefinition = 145,        /* ImportsDefinition  */
  YYSYMBOL_optImportsBundleSet = 146,      /* optImportsBundleSet  */
  YYSYMBOL_ImportsBundleSet = 147,         /* ImportsBundleSet  */
  YYSYMBOL_AssignedIdentifier = 148,       /* AssignedIdentifier  */
  YYSYMBOL_ImportsBundle = 149,            /* ImportsBundle  */
  YYSYMBOL_ImportsList = 150,              /* ImportsList  */
  YYSYMBOL_ImportsElement = 151,           /* ImportsElement  */
  YYSYMBOL_optExports = 152,               /* optExports  */
  YYSYMBOL_ExportsDefinition = 153,        /* ExportsDefinition  */
  YYSYMBOL_ExportsBody = 154,              /* ExportsBody  */
  YYSYMBOL_ExportsElement = 155,           /* ExportsElement  */
  YYSYMBOL_ValueSet = 156,                 /* ValueSet  */
  YYSYMBOL_ValueSetTypeAssignment = 157,   /* ValueSetTypeAssignment  */
  YYSYMBOL_DefinedType = 158,              /* DefinedType  */
  YYSYMBOL_DataTypeReference = 159,        /* DataTypeReference  */
  YYSYMBOL_ParameterArgumentList = 160,    /* ParameterArgumentList  */
  YYSYMBOL_ParameterArgumentName = 161,    /* ParameterArgumentName  */
  YYSYMBOL_ActualParameterList = 162,      /* ActualParameterList  */
  YYSYMBOL_ActualParameter = 163,          /* ActualParameter  */
  YYSYMBOL_optComponentTypeLists = 164,    /* optComponentTypeLists  */
  YYSYMBOL_ComponentTypeLists = 165,       /* ComponentTypeLists  */
  YYSYMBOL_ComponentType = 166,            /* ComponentType  */
  YYSYMBOL_AlternativeTypeLists = 167,     /* AlternativeTypeLists  */
  YYSYMBOL_AlternativeType = 168,          /* AlternativeType  */
  YYSYMBOL_ObjectClass = 169,              /* ObjectClass  */
  YYSYMBOL_optUNIQUE = 170,                /* optUNIQUE  */
  YYSYMBOL_FieldSpec = 171,                /* FieldSpec  */
  YYSYMBOL_ClassField = 172,               /* ClassField  */
  YYSYMBOL_optWithSyntax = 173,            /* optWithSyntax  */
  YYSYMBOL_WithSyntax = 174,               /* WithSyntax  */
  YYSYMBOL_175_4 = 175,                    /* $@4  */
  YYSYMBOL_WithSyntaxList = 176,           /* WithSyntaxList  */
  YYSYMBOL_WithSyntaxToken = 177,          /* WithSyntaxToken  */
  YYSYMBOL_ExtensionAndException = 178,    /* ExtensionAndException  */
  YYSYMBOL_Type = 179,                     /* Type  */
  YYSYMBOL_TaggedType = 180,               /* TaggedType  */
  YYSYMBOL_DefinedUntaggedType = 181,      /* DefinedUntaggedType  */
  YYSYMBOL_UntaggedType = 182,             /* UntaggedType  */
  YYSYMBOL_MaybeIndirectTaggedType = 183,  /* MaybeIndirectTaggedType  */
  YYSYMBOL_NSTD_IndirectMarker = 184,      /* NSTD_IndirectMarker  */
  YYSYMBOL_MaybeIndirectTypeDeclaration = 185, /* MaybeIndirectTypeDeclaration  */
  YYSYMBOL_TypeDeclaration = 186,          /* TypeDeclaration  */
  YYSYMBOL_ConcreteTypeDeclaration = 187,  /* ConcreteTypeDeclaration  */
  YYSYMBOL_ComplexTypeReference = 188,     /* ComplexTypeReference  */
  YYSYMBOL_ComplexTypeReferenceAmpList = 189, /* ComplexTypeReferenceAmpList  */
  YYSYMBOL_ComplexTypeReferenceElement = 190, /* ComplexTypeReferenceElement  */
  YYSYMBOL_PrimitiveFieldReference = 191,  /* PrimitiveFieldReference  */
  YYSYMBOL_FieldName = 192,                /* FieldName  */
  YYSYMBOL_DefinedObjectClass = 193,       /* DefinedObjectClass  */
  YYSYMBOL_ValueAssignment = 194,          /* ValueAssignment  */
  YYSYMBOL_Value = 195,                    /* Value  */
  YYSYMBOL_196_5 = 196,                    /* $@5  */
  YYSYMBOL_SimpleValue = 197,              /* SimpleValue  */
  YYSYMBOL_DefinedValue = 198,             /* DefinedValue  */
  YYSYMBOL_RestrictedCharacterStringValue = 199, /* RestrictedCharacterStringValue  */
  YYSYMBOL_Opaque = 200,                   /* Opaque  */
  YYSYMBOL_OpaqueFirstToken = 201,         /* OpaqueFirstToken  */
  YYSYMBOL_BasicTypeId = 202,              /* BasicTypeId  */
  YYSYMBOL_BasicTypeId_UniverationCompatible = 203, /* BasicTypeId_UniverationCompatible  */
  YYSYMBOL_BuiltinType = 204,              /* BuiltinType  */
  YYSYMBOL_BasicString = 205,              /* BasicString  */
  YYSYMBOL_UnionMark = 206,                /* UnionMark  */
  YYSYMBOL_IntersectionMark = 207,         /* IntersectionMark  */
  YYSYMBOL_optConstraint = 208,            /* optConstraint  */
  YYSYMBOL_optManyConstraints = 209,       /* optManyConstraints  */
  YYSYMBOL_optSizeOrConstraint = 210,      /* optSizeOrConstraint  */
  YYSYMBOL_Constraint = 211,               /* Constraint  */
  YYSYMBOL_ManyConstraints = 212,          /* ManyConstraints  */
  YYSYMBOL_ConstraintSpec = 213,           /* ConstraintSpec  */
  YYSYMBOL_SubtypeConstraint = 214,        /* SubtypeConstraint  */
  YYSYMBOL_ElementSetSpecs = 215,          /* ElementSetSpecs  */
  YYSYMBOL_ElementSetSpec = 216,           /* ElementSetSpec  */
  YYSYMBOL_Unions = 217,                   /* Unions  */
  YYSYMBOL_Intersections = 218,            /* Intersections  */
  YYSYMBOL_IntersectionElements = 219,     /* IntersectionElements  */
  YYSYMBOL_Elements = 220,                 /* Elements  */
  YYSYMBOL_SubtypeElements = 221,          /* SubtypeElements  */
  YYSYMBOL_PermittedAlphabet = 222,        /* PermittedAlphabet  */
  YYSYMBOL_SizeConstraint = 223,           /* SizeConstraint  */
  YYSYMBOL_PatternConstraint = 224,        /* PatternConstraint  */
  YYSYMBOL_ValueRange = 225,               /* ValueRange  */
  YYSYMBOL_LowerEndValue = 226,            /* LowerEndValue  */
  YYSYMBOL_UpperEndValue = 227,            /* UpperEndValue  */
  YYSYMBOL_SingleValue = 228,              /* SingleValue  */
  YYSYMBOL_BitStringValue = 229,           /* BitStringValue  */
  YYSYMBOL_ContainedSubtype = 230,         /* ContainedSubtype  */
  YYSYMBOL_InnerTypeConstraints = 231,     /* InnerTypeConstraints  */
  YYSYMBOL_SingleTypeConstraint = 232,     /* SingleTypeConstraint  */
  YYSYMBOL_MultipleTypeConstraints = 233,  /* MultipleTypeConstraints  */
  YYSYMBOL_FullSpecification = 234,        /* FullSpecification  */
  YYSYMBOL_PartialSpecification = 235,     /* PartialSpecification  */
  YYSYMBOL_TypeConstraints = 236,          /* TypeConstraints  */
  YYSYMBOL_NamedConstraint = 237,          /* NamedConstraint  */
  YYSYMBOL_optPresenceConstraint = 238,    /* optPresenceConstraint  */
  YYSYMBOL_PresenceConstraint = 239,       /* PresenceConstraint  */
  YYSYMBOL_GeneralConstraint = 240,        /* GeneralConstraint  */
  YYSYMBOL_UserDefinedConstraint = 241,    /* UserDefinedConstraint  */
  YYSYMBOL_242_6 = 242,                    /* $@6  */
  YYSYMBOL_ContentsConstraint = 243,       /* ContentsConstraint  */
  YYSYMBOL_ConstraintRangeSpec = 244,      /* ConstraintRangeSpec  */
  YYSYMBOL_TableConstraint = 245,          /* TableConstraint  */
  YYSYMBOL_SimpleTableConstraint = 246,    /* SimpleTableConstraint  */
  YYSYMBOL_ComponentRelationConstraint = 247, /* ComponentRelationConstraint  */
  YYSYMBOL_AtNotationList = 248,           /* AtNotationList  */
  YYSYMBOL_AtNotationElement = 249,        /* AtNotationElement  */
  YYSYMBOL_ComponentIdList = 250,          /* ComponentIdList  */
  YYSYMBOL_optMarker = 251,                /* optMarker  */
  YYSYMBOL_Marker = 252,                   /* Marker  */
  YYSYMBOL_IdentifierList = 253,           /* IdentifierList  */
  YYSYMBOL_IdentifierElement = 254,        /* IdentifierElement  */
  YYSYMBOL_NamedNumberList = 255,          /* NamedNumberList  */
  YYSYMBOL_NamedNumber = 256,              /* NamedNumber  */
  YYSYMBOL_NamedBitList = 257,             /* NamedBitList  */
  YYSYMBOL_NamedBit = 258,                 /* NamedBit  */
  YYSYMBOL_Enumerations = 259,             /* Enumerations  */
  YYSYMBOL_UniverationList = 260,          /* UniverationList  */
  YYSYMBOL_UniverationElement = 261,       /* UniverationElement  */
  YYSYMBOL_SignedNumber = 262,             /* SignedNumber  */
  YYSYMBOL_RealValue = 263,                /* RealValue  */
  YYSYMBOL_optTag = 264,                   /* optTag  */
  YYSYMBOL_Tag = 265,                      /* Tag  */
  YYSYMBOL_TagTypeValue = 266,             /* TagTypeValue  */
  YYSYMBOL_TagClass = 267,                 /* TagClass  */
  YYSYMBOL_TagPlicit = 268,                /* TagPlicit  */
  YYSYMBOL_TypeRefName = 269,              /* TypeRefName  */
  YYSYMBOL_optIdentifier = 270,            /* optIdentifier  */
  YYSYMBOL_Identifier = 271,               /* Identifier  */
  YYSYMBOL_IdentifierAsReference = 272,    /* IdentifierAsReference  */
  YYSYMBOL_IdentifierAsValue = 273         /* IdentifierAsValue  */
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
typedef yytype_int16 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   936

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  126
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  148
/* YYNRULES -- Number of rules.  */
#define YYNRULES  345
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  530

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   365


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
       2,     2,     2,   122,     2,     2,     2,     2,     2,     2,
     115,   116,     2,     2,   118,     2,   123,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   119,   117,
     124,     2,     2,     2,   125,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   120,     2,   121,   106,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   113,   108,   114,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   107,   109,   110,   111,   112
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   411,   411,   414,   420,   425,   442,   442,   471,   472,
     476,   479,   485,   491,   500,   504,   508,   518,   519,   528,
     531,   540,   543,   546,   549,   553,   574,   575,   584,   597,
     600,   617,   624,   641,   640,   668,   676,   675,   689,   702,
     703,   706,   716,   722,   723,   726,   731,   738,   739,   743,
     754,   759,   766,   772,   778,   788,   789,   801,   804,   807,
     815,   820,   827,   833,   839,   848,   851,   871,   881,   901,
     907,   923,   929,   937,   946,   957,   961,   969,   977,   985,
     996,  1001,  1008,  1009,  1017,  1025,  1048,  1049,  1052,  1057,
    1061,  1069,  1076,  1082,  1089,  1095,  1100,  1104,  1111,  1116,
    1119,  1126,  1136,  1137,  1141,  1148,  1158,  1168,  1179,  1189,
    1200,  1210,  1221,  1233,  1234,  1241,  1240,  1249,  1253,  1260,
    1264,  1267,  1271,  1277,  1285,  1294,  1305,  1308,  1315,  1338,
    1361,  1385,  1392,  1411,  1412,  1415,  1416,  1422,  1428,  1434,
    1444,  1454,  1460,  1472,  1487,  1495,  1503,  1514,  1525,  1547,
    1555,  1564,  1568,  1573,  1582,  1587,  1592,  1600,  1623,  1633,
    1634,  1635,  1635,  1643,  1648,  1653,  1658,  1659,  1660,  1661,
    1665,  1666,  1684,  1688,  1693,  1701,  1710,  1725,  1726,  1732,
    1733,  1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,
    1743,  1744,  1751,  1752,  1753,  1757,  1763,  1768,  1773,  1778,
    1783,  1792,  1793,  1797,  1801,  1802,  1803,  1804,  1805,  1809,
    1810,  1811,  1812,  1816,  1817,  1824,  1824,  1825,  1825,  1829,
    1830,  1834,  1835,  1839,  1840,  1841,  1845,  1851,  1852,  1861,
    1861,  1863,  1866,  1870,  1871,  1877,  1888,  1889,  1895,  1896,
    1902,  1903,  1910,  1911,  1917,  1918,  1929,  1935,  1941,  1942,
    1944,  1945,  1946,  1951,  1956,  1961,  1966,  1978,  1987,  1988,
    1994,  1995,  2000,  2003,  2008,  2016,  2022,  2034,  2037,  2043,
    2044,  2044,  2045,  2047,  2060,  2065,  2071,  2085,  2086,  2090,
    2093,  2096,  2104,  2105,  2106,  2111,  2110,  2122,  2131,  2132,
    2133,  2134,  2137,  2140,  2149,  2165,  2171,  2177,  2191,  2202,
    2218,  2221,  2241,  2245,  2249,  2253,  2260,  2265,  2271,  2280,
    2285,  2292,  2300,  2310,  2315,  2322,  2330,  2340,  2355,  2360,
    2367,  2374,  2382,  2390,  2397,  2408,  2412,  2419,  2450,  2451,
    2455,  2462,  2468,  2469,  2470,  2471,  2475,  2476,  2477,  2481,
    2485,  2493,  2494,  2500,  2507,  2514
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOK_PPEQ",
  "TOK_VBracketLeft", "TOK_VBracketRight", "TOK_whitespace", "TOK_opaque",
  "TOK_bstring", "TOK_cstring", "TOK_hstring", "\"identifier\"",
  "\"number\"", "\"negative number\"", "TOK_realnumber", "TOK_tuple",
  "TOK_quadruple", "TOK_typereference", "TOK_capitalreference",
  "TOK_typefieldreference", "TOK_valuefieldreference", "TOK_Literal",
  "TOK_ExtValue_BIT_STRING", "TOK_ABSENT", "TOK_ABSTRACT_SYNTAX",
  "TOK_ALL", "TOK_ANY", "TOK_APPLICATION", "TOK_AUTOMATIC", "TOK_BEGIN",
  "TOK_BIT", "TOK_BMPString", "TOK_BOOLEAN", "TOK_BY", "TOK_CHARACTER",
  "TOK_CHOICE", "TOK_CLASS", "TOK_COMPONENT", "TOK_COMPONENTS",
  "TOK_CONSTRAINED", "TOK_CONTAINING", "TOK_DEFAULT", "TOK_DEFINITIONS",
  "TOK_DEFINED", "TOK_EMBEDDED", "TOK_ENCODED", "TOK_ENCODING_CONTROL",
  "TOK_END", "TOK_ENUMERATED", "TOK_EXPLICIT", "TOK_EXPORTS",
  "TOK_EXTENSIBILITY", "TOK_EXTERNAL", "TOK_FALSE", "TOK_FROM",
  "TOK_GeneralizedTime", "TOK_GeneralString", "TOK_GraphicString",
  "TOK_IA5String", "TOK_IDENTIFIER", "TOK_IMPLICIT", "TOK_IMPLIED",
  "TOK_IMPORTS", "TOK_INCLUDES", "TOK_INSTANCE", "TOK_INSTRUCTIONS",
  "TOK_INTEGER", "TOK_ISO646String", "TOK_MAX", "TOK_MIN",
  "TOK_MINUS_INFINITY", "TOK_NULL", "TOK_NumericString", "TOK_OBJECT",
  "TOK_ObjectDescriptor", "TOK_OCTET", "TOK_OF", "TOK_OPTIONAL",
  "TOK_PATTERN", "TOK_PDV", "TOK_PLUS_INFINITY", "TOK_PRESENT",
  "TOK_PrintableString", "TOK_PRIVATE", "TOK_REAL", "TOK_RELATIVE_OID",
  "TOK_SEQUENCE", "TOK_SET", "TOK_SIZE", "TOK_STRING", "TOK_SYNTAX",
  "TOK_T61String", "TOK_TAGS", "TOK_TeletexString", "TOK_TRUE",
  "TOK_TYPE_IDENTIFIER", "TOK_UNIQUE", "TOK_UNIVERSAL",
  "TOK_UniversalString", "TOK_UTCTime", "TOK_UTF8String",
  "TOK_VideotexString", "TOK_VisibleString", "TOK_WITH",
  "\"UTF-8 byte order mark\"", "TOK_EXCEPT", "'^'", "TOK_INTERSECTION",
  "'|'", "TOK_UNION", "\"..\"", "\"...\"", "\"concrete TypeDeclaration\"",
  "'{'", "'}'", "'('", "')'", "';'", "','", "':'", "'['", "']'", "'!'",
  "'.'", "'<'", "'@'", "$accept", "ParsedGrammar", "ModuleList",
  "ModuleDefinition", "$@1", "optObjectIdentifier", "ObjectIdentifier",
  "ObjectIdentifierBody", "ObjectIdentifierElement",
  "optModuleDefinitionFlags", "ModuleDefinitionFlags",
  "ModuleDefinitionFlag", "optModuleBody", "ModuleBody", "AssignmentList",
  "Assignment", "$@2", "$@3", "optImports", "ImportsDefinition",
  "optImportsBundleSet", "ImportsBundleSet", "AssignedIdentifier",
  "ImportsBundle", "ImportsList", "ImportsElement", "optExports",
  "ExportsDefinition", "ExportsBody", "ExportsElement", "ValueSet",
  "ValueSetTypeAssignment", "DefinedType", "DataTypeReference",
  "ParameterArgumentList", "ParameterArgumentName", "ActualParameterList",
  "ActualParameter", "optComponentTypeLists", "ComponentTypeLists",
  "ComponentType", "AlternativeTypeLists", "AlternativeType",
  "ObjectClass", "optUNIQUE", "FieldSpec", "ClassField", "optWithSyntax",
  "WithSyntax", "$@4", "WithSyntaxList", "WithSyntaxToken",
  "ExtensionAndException", "Type", "TaggedType", "DefinedUntaggedType",
  "UntaggedType", "MaybeIndirectTaggedType", "NSTD_IndirectMarker",
  "MaybeIndirectTypeDeclaration", "TypeDeclaration",
  "ConcreteTypeDeclaration", "ComplexTypeReference",
  "ComplexTypeReferenceAmpList", "ComplexTypeReferenceElement",
  "PrimitiveFieldReference", "FieldName", "DefinedObjectClass",
  "ValueAssignment", "Value", "$@5", "SimpleValue", "DefinedValue",
  "RestrictedCharacterStringValue", "Opaque", "OpaqueFirstToken",
  "BasicTypeId", "BasicTypeId_UniverationCompatible", "BuiltinType",
  "BasicString", "UnionMark", "IntersectionMark", "optConstraint",
  "optManyConstraints", "optSizeOrConstraint", "Constraint",
  "ManyConstraints", "ConstraintSpec", "SubtypeConstraint",
  "ElementSetSpecs", "ElementSetSpec", "Unions", "Intersections",
  "IntersectionElements", "Elements", "SubtypeElements",
  "PermittedAlphabet", "SizeConstraint", "PatternConstraint", "ValueRange",
  "LowerEndValue", "UpperEndValue", "SingleValue", "BitStringValue",
  "ContainedSubtype", "InnerTypeConstraints", "SingleTypeConstraint",
  "MultipleTypeConstraints", "FullSpecification", "PartialSpecification",
  "TypeConstraints", "NamedConstraint", "optPresenceConstraint",
  "PresenceConstraint", "GeneralConstraint", "UserDefinedConstraint",
  "$@6", "ContentsConstraint", "ConstraintRangeSpec", "TableConstraint",
  "SimpleTableConstraint", "ComponentRelationConstraint", "AtNotationList",
  "AtNotationElement", "ComponentIdList", "optMarker", "Marker",
  "IdentifierList", "IdentifierElement", "NamedNumberList", "NamedNumber",
  "NamedBitList", "NamedBit", "Enumerations", "UniverationList",
  "UniverationElement", "SignedNumber", "RealValue", "optTag", "Tag",
  "TagTypeValue", "TagClass", "TagPlicit", "TypeRefName", "optIdentifier",
  "Identifier", "IdentifierAsReference", "IdentifierAsValue", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-393)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-303)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      94,  -393,  -393,   221,    35,   221,  -393,  -393,   221,  -393,
    -393,   -43,    42,    61,  -393,  -393,  -393,  -393,    47,  -393,
       9,   272,  -393,  -393,   109,    66,    82,    95,   133,   108,
     203,   272,  -393,   107,  -393,  -393,  -393,  -393,  -393,   241,
    -393,  -393,    28,    90,   259,  -393,   229,  -393,   194,  -393,
     158,  -393,   201,  -393,  -393,   214,   671,  -393,  -393,  -393,
     197,   204,  -393,   208,   197,  -393,    -4,  -393,   218,  -393,
    -393,   309,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,   671,  -393,  -393,  -393,  -393,
    -393,    22,   209,  -393,  -393,  -393,  -393,   221,   197,   228,
    -393,  -393,     5,   357,   834,    44,   364,  -393,   757,  -393,
      30,   371,   -43,  -393,  -393,  -393,   231,  -393,  -393,   233,
     286,  -393,   289,   269,  -393,  -393,  -393,  -393,  -393,   318,
     290,  -393,  -393,  -393,    57,  -393,   277,  -393,  -393,   278,
    -393,  -393,  -393,   369,   285,   276,   279,   287,   339,   312,
     292,   293,   327,   294,     7,   122,  -393,  -393,   296,  -393,
     295,  -393,  -393,  -393,  -393,  -393,   683,  -393,  -393,   263,
    -393,  -393,  -393,  -393,  -393,  -393,   406,   834,   197,   197,
     297,   341,  -393,   221,   244,    19,   380,   301,    17,   106,
     316,   404,   296,    49,   232,   340,  -393,  -393,    49,   344,
    -393,  -393,   296,   577,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,   298,  -393,  -393,  -393,   210,    62,    74,
    -393,   151,     5,  -393,  -393,  -393,  -393,  -393,  -393,   276,
     279,   317,   296,   209,  -393,   288,   299,  -393,   449,   296,
    -393,  -393,   303,   305,   230,   234,  -393,   319,  -393,  -393,
    -393,  -393,  -393,   -36,    60,  -393,  -393,  -393,  -393,  -393,
     302,  -393,  -393,  -393,  -393,   116,  -393,  -393,   404,   404,
     304,   138,  -393,  -393,  -393,  -393,   209,  -393,   313,   314,
    -393,  -393,   321,  -393,   163,  -393,   322,  -393,   355,   324,
     315,  -393,  -393,    36,   209,   407,   209,   221,   323,  -393,
    -393,  -393,  -393,  -393,  -393,   328,  -393,   404,   333,   404,
    -393,   334,  -393,   170,  -393,  -393,  -393,  -393,   151,   404,
    -393,  -393,   683,  -393,    36,    55,    36,  -393,  -393,   346,
      55,    36,   348,   263,  -393,   441,  -393,  -393,  -393,  -393,
     469,  -393,  -393,  -393,  -393,   296,   342,   337,  -393,  -393,
     359,  -393,  -393,   469,  -393,  -393,   469,   469,   347,   358,
     375,   343,  -393,   404,  -393,   175,  -393,   374,   242,  -393,
      23,   757,   296,  -393,  -393,   106,   242,  -393,   404,   242,
     209,  -393,    18,  -393,    36,   360,  -393,   376,  -393,   366,
     209,  -393,  -393,   209,  -393,   577,   441,  -393,  -393,  -393,
     345,  -393,  -393,  -393,    36,  -393,  -393,   382,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,    15,  -393,  -393,  -393,  -393,
     377,   234,  -393,  -393,  -393,   368,  -393,  -393,  -393,  -393,
    -393,  -393,   404,   262,  -393,  -393,    17,  -393,  -393,  -393,
    -393,   378,   381,  -393,   383,   384,  -393,    25,  -393,  -393,
    -393,  -393,    31,   178,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,   385,   386,   180,  -393,   296,   449,  -393,  -393,   389,
     390,    32,  -393,  -393,  -393,  -393,    33,   151,   404,   370,
    -393,  -393,   366,  -393,  -393,  -393,   404,  -393,   404,   145,
    -393,  -393,  -393,  -393,  -393,  -393,   441,   370,   404,  -393,
      63,   190,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,    63,    45,  -393,  -393,  -393,    26,  -393,  -393,  -393
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   339,   340,     0,     0,     3,     4,     6,     2,     1,
       5,     8,     0,     0,     9,   343,    16,    11,     0,    12,
      14,    17,    10,    13,     0,     0,     0,     0,     0,     0,
       0,    18,    19,     0,    25,    23,    21,    24,    22,     0,
      20,    15,    55,     0,     0,    27,    39,    56,     0,    59,
       0,    60,    62,    64,     7,    43,     0,    40,    58,    57,
       0,     0,    42,     0,    44,    45,     0,    50,    52,    54,
     201,     0,   202,   203,   204,   205,   206,   214,   207,   208,
     209,   210,   211,   212,   213,    28,    29,    35,    31,    32,
      38,   328,   328,    61,    63,    41,    46,     0,     0,     0,
      36,    30,   328,     0,     0,   332,     0,   126,     0,   329,
     336,     0,    47,    51,    53,    37,     0,    70,    69,     0,
       0,   179,     0,     0,   193,   185,   189,   192,   180,     0,
       0,   181,   184,   188,     0,    73,     0,   191,   190,    75,
     334,   335,   333,     0,     0,   144,   145,     0,   141,     0,
       0,   193,     0,   192,   223,   223,   134,   127,   221,   133,
      67,   195,   135,   338,   337,   330,     0,    48,    49,     0,
      33,   194,   187,   186,   183,   182,     0,     0,     0,     0,
       0,     0,    66,     0,     0,     0,     0,   194,   328,     0,
       0,     0,     0,   328,     0,     0,   224,   225,   328,     0,
     129,   227,   222,     0,   263,   172,   264,   325,   326,   327,
     173,   174,   164,   163,   165,   161,   158,   159,   160,   168,
     169,   166,   167,     0,   344,   345,   170,   328,   328,     0,
     104,     0,   328,    74,    79,    78,    77,    76,   331,   144,
     145,     0,     0,   328,   259,     0,     0,   232,     0,   221,
     266,   262,     0,   233,   236,   238,   240,   242,   244,   248,
     249,   251,   252,     0,   246,   247,   250,   146,   152,   153,
     148,   149,   151,   147,   200,     0,   306,   308,     0,     0,
     123,     0,    95,    99,   100,   131,   328,   324,     0,   317,
     318,   323,   320,   143,     0,   309,     0,   254,     0,     0,
      87,    88,    94,   302,   328,     0,   328,   161,     0,   229,
     231,   230,   282,   284,   283,   292,   293,   341,     0,   341,
     228,   163,    85,     0,    80,    82,    83,    84,     0,     0,
     157,   154,     0,   304,   302,   302,   302,   106,   303,   102,
     302,   302,   113,     0,   177,    34,   175,   178,    72,    71,
       0,   253,   265,   255,   256,     0,     0,     0,   128,    65,
       0,   215,   216,     0,   217,   218,     0,     0,   288,     0,
       0,     0,   199,     0,   142,     0,   313,     0,     0,   136,
     328,     0,   221,    98,   197,     0,     0,   196,     0,     0,
     328,   137,   328,    92,   302,     0,   287,     0,   226,     0,
     328,   342,   138,   328,    68,     0,   162,   171,   305,   111,
       0,   110,   112,   103,   302,   108,   109,     0,   101,   114,
     105,   176,   237,   269,   267,     0,   268,   270,   271,   245,
     234,   239,   241,   243,   289,   290,   261,   257,   260,   150,
     307,   198,     0,     0,   124,   125,   328,    96,   132,   130,
     319,     0,     0,   310,     0,     0,    93,   328,    89,    91,
     285,   294,     0,     0,   296,   131,   131,    81,   155,   156,
     107,     0,     0,     0,   274,   219,     0,   291,   314,     0,
       0,     0,   322,   321,   312,   311,     0,     0,     0,   298,
     300,   295,     0,   139,   140,   115,     0,   272,     0,   277,
     220,   235,   315,   316,    97,    90,   286,   299,     0,   297,
       0,     0,   275,   280,   281,   279,   276,   278,   301,   119,
     120,     0,     0,   117,   121,   273,     0,   116,   118,   122
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -393,  -393,   498,   216,  -393,  -393,   395,  -393,   490,  -393,
    -393,   478,  -393,  -393,  -393,   425,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,   447,  -393,   415,  -393,  -393,  -393,   454,
     372,  -393,  -103,  -393,  -393,   338,  -393,   112,   326,    64,
     127,    79,   146,   307,  -393,  -393,   185,  -393,  -393,  -393,
       8,  -213,  -177,   -79,  -393,  -393,   422,  -181,  -393,   -96,
     150,  -393,   351,  -393,   162,  -174,   306,   308,  -393,  -147,
    -393,  -194,  -185,  -393,  -307,  -393,   -47,  -393,  -393,     6,
    -393,  -393,  -393,  -225,   387,  -153,  -393,  -393,  -393,   350,
    -240,  -393,   172,   179,  -265,  -393,  -393,   217,  -393,  -393,
    -393,  -393,   176,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
      52,    51,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,    58,    65,  -242,  -393,  -393,   181,  -393,
     167,  -393,   114,  -393,  -393,   166,  -173,  -393,   -88,  -393,
    -393,  -393,  -393,    12,   239,   -12,  -393,  -392
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,    11,    13,    14,    18,    19,    30,
      31,    32,    44,    45,    85,    86,   231,   115,    56,    57,
      63,    64,   168,    65,    66,    67,    46,    47,    50,    51,
     322,    87,   249,    88,   134,   135,   323,   324,   299,   300,
     301,   281,   282,   117,   414,   229,   230,   418,   419,   510,
     522,   523,   302,   106,   107,   250,   325,   303,   381,   382,
     158,   159,   160,   270,   271,   524,   335,   336,    89,   251,
     328,   217,   218,   219,   345,   346,   161,   137,   162,   138,
     363,   366,   499,   200,   195,   201,   202,   308,   309,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   437,   264,   220,   265,   266,   424,   426,   427,   428,
     473,   474,   516,   517,   311,   312,   487,   313,   370,   314,
     315,   316,   463,   464,   489,   337,   338,   275,   276,   294,
     295,   375,   376,   288,   289,   290,   221,   222,   285,   109,
     110,   143,   165,   223,   400,   224,   225,   226
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,   196,   196,   108,   108,   156,    20,   284,   357,   326,
     272,   283,     7,   111,   108,     7,   291,     7,   327,   216,
       7,   406,   457,   118,   358,   102,    15,   446,    15,    15,
      15,    53,   519,   475,    15,     9,    15,   504,   505,   297,
     103,   116,    15,    69,    92,   268,   269,   520,    53,   320,
      97,   519,    69,    15,    16,    52,   298,   136,    15,    16,
      15,   393,    90,   298,   268,   269,   520,    68,    91,   519,
      12,   140,    52,    92,   368,   -26,    68,   332,    43,   163,
     330,   331,   268,   269,   520,   422,    69,   298,   369,   351,
     164,    90,   409,   411,   412,   192,   332,    91,   415,   416,
     156,    15,   433,    21,   475,   383,   475,     1,     2,   112,
      68,     1,     2,   333,    98,    48,   139,    15,   207,   208,
     193,    33,   194,   394,    24,   105,   472,   141,   280,   280,
     136,    34,   333,   274,   280,   104,   280,   105,   105,   108,
     108,   142,   105,   105,   108,   105,   521,   529,   334,   339,
     380,   392,   459,   349,   488,   108,    17,   449,   344,   527,
     280,    22,    15,   -86,   352,   521,   235,   237,   513,   105,
    -258,   176,   470,   277,    35,   177,   286,   292,   410,   296,
     506,   304,   105,   521,  -258,   408,   304,    36,   342,   139,
     234,   236,   343,   444,    37,   267,   273,   272,     3,   284,
      38,   451,   423,   283,   454,   445,    39,    49,    15,   456,
     192,   326,   291,   452,     1,     2,   455,   287,   108,   347,
     327,    10,   514,    41,    10,    15,   515,   396,   330,   331,
     372,     1,     2,   354,   373,   198,   501,   194,     1,     2,
     204,   205,   206,    15,   207,   208,   209,   210,   211,   239,
     240,   332,   379,    15,   207,   208,   380,   241,   480,     1,
       2,     1,     2,   268,   269,   284,   374,   377,    62,   283,
      42,   305,   306,    15,   479,    59,    60,   387,   156,     1,
       2,   388,   227,   228,   404,   212,   242,   333,   405,   441,
      25,    55,   491,   442,   497,   243,   492,   353,   498,    15,
      26,   244,   156,   213,   525,   401,    54,   401,   498,   528,
     245,    58,   465,   528,    61,   466,   347,   407,    94,   397,
     192,    27,   500,    28,  -302,    95,   214,   100,  -302,   105,
     105,    99,    29,   145,   146,   246,   355,   356,   361,   362,
     364,   365,   114,   247,   169,   307,   170,   248,   173,   204,
     205,   206,    15,   207,   208,   209,   210,   211,   239,   240,
     119,   277,   268,   269,   468,   469,   241,   144,   286,   493,
     494,   197,   197,   292,   166,   171,   296,   174,   172,   175,
     304,   180,   186,   204,   205,   206,    15,   207,   208,   209,
     210,   211,     1,     2,   212,   242,   178,   179,   181,   183,
     185,   187,   184,   190,   243,   188,   189,   191,   203,   232,
     244,   194,   213,   278,   279,    15,   317,   359,   238,   245,
     319,   329,   350,   360,   367,   371,   378,   384,   212,   192,
     377,   390,   385,   392,   286,   214,   386,   389,   391,   398,
     395,   399,   413,   436,   246,   304,   213,   402,   421,  -180,
     490,   417,   247,   429,   215,   425,   248,   204,   205,   206,
      15,   207,   208,   209,   210,   211,   239,   240,   435,   214,
     430,   434,   471,   460,   241,   347,   490,   204,   205,   206,
      15,   207,   208,   209,   210,   211,   239,   240,   215,   443,
     461,   462,   477,   508,   482,   476,   518,   483,   495,   484,
     485,     8,   212,   242,   496,   502,   503,   167,    23,    40,
     101,    96,   243,   113,    93,   233,   182,   467,   244,   458,
     213,   486,   212,   242,   318,   481,   447,   245,   420,   526,
     157,   448,   243,   439,   340,   431,   341,   192,   244,   348,
     213,   293,   199,   214,   310,   432,   438,   245,   511,   512,
     509,   450,   246,   507,   440,   453,   478,   192,   403,     0,
       0,     0,   215,   214,   248,     0,     0,     0,     0,     0,
       0,     0,   246,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,     0,   248,   204,   205,   206,    15,   207,
     208,   209,   210,   211,   239,   240,     0,     0,     0,   147,
       0,     0,     0,   148,     0,     0,     0,   149,    70,   121,
       0,   122,   150,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,   151,     0,     0,     0,   125,
     212,     0,   126,    72,    73,    74,     0,     0,     0,     0,
       0,   152,     0,   153,    75,     0,     0,     0,   321,    76,
     129,    77,   130,     0,     0,     0,     0,     0,     0,    78,
       0,   131,   132,   154,   155,     0,     0,     0,    79,     0,
      80,   214,     0,     0,     0,    81,   133,    82,    83,    84,
       0,     0,    15,     0,     0,     0,     0,     0,     1,     2,
     181,   204,   205,   206,    15,   207,   208,   209,   210,   211,
       1,     2,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,    74,
       0,     0,     0,     0,     0,     0,   212,     0,    75,     0,
       0,     0,     0,    76,     0,    77,     0,     0,     0,     0,
       0,     0,     0,    78,   213,     0,     0,     0,     0,     0,
       0,     0,    79,     0,    80,     0,     0,     0,     0,    81,
       0,    82,    83,    84,   145,   146,     0,   214,     0,   147,
       0,     0,     0,   148,     0,     0,     0,   149,    70,   121,
       0,   122,   150,     0,     0,     0,   215,     0,     0,     0,
       0,   123,     0,     0,     0,   151,     0,     0,     0,   125,
       0,     0,   126,    72,    73,    74,     0,     0,     0,     0,
       0,   152,     0,   153,    75,     0,     0,     0,   128,    76,
     129,    77,   130,     0,     0,     0,     0,     0,     0,    78,
       0,   131,   132,   154,   155,     0,     0,     0,    79,     0,
      80,     1,     2,     0,     0,    81,   133,    82,    83,    84,
       0,     0,     0,     0,   120,    70,   121,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,     0,
       0,     0,   124,     0,     0,     0,   125,     0,     0,   126,
      72,    73,    74,     0,     0,     0,     0,     0,     0,     0,
     127,    75,     0,     0,     0,   128,    76,   129,    77,   130,
       0,     0,     0,     0,     0,     0,    78,     0,   131,   132,
       0,     0,     0,     0,     0,    79,     0,    80,     0,     0,
       0,     0,    81,   133,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      12,   154,   155,    91,    92,   108,    18,   188,   248,   203,
     184,   188,     0,    92,   102,     3,   189,     5,   203,   166,
       8,   328,     4,   102,   249,     3,    11,     4,    11,    11,
      11,    43,     6,   425,    11,     0,    11,     5,     5,   192,
      18,    36,    11,    55,    56,    19,    20,    21,    60,   202,
      54,     6,    64,    11,    12,    43,    38,   104,    11,    12,
      11,   303,    56,    38,    19,    20,    21,    55,    56,     6,
     113,    27,    60,    85,   110,    47,    64,    41,    50,    49,
      18,    19,    19,    20,    21,   350,    98,    38,   124,   242,
      60,    85,   334,   335,   336,    88,    41,    85,   340,   341,
     203,    11,   367,    42,   496,   286,   498,    17,    18,    97,
      98,    17,    18,    77,   118,    25,   104,    11,    12,    13,
     113,    12,   115,   304,   115,   120,   111,    83,   111,   111,
     177,    65,    77,   114,   111,   113,   111,   120,   120,   227,
     228,    97,   120,   120,   232,   120,   120,   121,   227,   228,
     118,   118,   394,   232,   123,   243,   114,   382,     7,   114,
     111,   114,    11,   114,   243,   120,   178,   179,    23,   120,
     110,   114,   414,   185,    92,   118,   188,   189,   123,   191,
     487,   193,   120,   120,   124,   332,   198,    92,   114,   177,
     178,   179,   118,   378,    61,   183,   184,   371,   104,   380,
      92,   386,   355,   380,   389,   378,     3,   117,    11,   390,
      88,   405,   385,   386,    17,    18,   389,   111,   306,   231,
     405,     5,    77,   116,     8,    11,    81,   306,    18,    19,
     114,    17,    18,   245,   118,   113,   476,   115,    17,    18,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    41,   114,    11,    12,    13,   118,    25,   443,    17,
      18,    17,    18,    19,    20,   446,   278,   279,    54,   446,
      29,    39,    40,    11,    12,   117,   118,   114,   381,    17,
      18,   118,    19,    20,   114,    53,    54,    77,   118,   114,
      18,    62,   114,   118,   114,    63,   118,     9,   118,    11,
      28,    69,   405,    71,   114,   317,    47,   319,   118,   522,
      78,   117,   400,   526,   113,   403,   328,   329,   114,   307,
      88,    49,   475,    51,   114,   117,    94,    18,   118,   120,
     120,   113,    60,    17,    18,   103,    37,    38,   108,   109,
     106,   107,   114,   111,   113,   113,   113,   115,    79,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       3,   373,    19,    20,    19,    20,    25,     3,   380,   465,
     466,   154,   155,   385,     3,    89,   388,    59,    89,    89,
     392,    12,    43,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    53,    54,   119,   119,   113,   123,
     113,    89,   123,    76,    63,   113,   113,   113,   113,     3,
      69,   115,    71,    33,   113,    11,    76,   114,   121,    78,
      76,   123,   105,   118,   105,   123,   122,   114,    53,    88,
     442,    76,   118,   118,   446,    94,   115,   115,   114,   116,
      33,   113,    96,    68,   103,   457,    71,   114,     7,   115,
     462,   103,   111,   116,   113,   113,   115,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   110,    94,
     111,   124,    90,   113,    25,   487,   488,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   113,   115,
     114,   125,   124,   123,   116,   118,   508,   116,   113,   116,
     116,     3,    53,    54,   118,   116,   116,   112,    18,    31,
      85,    64,    63,    98,    60,   177,   144,   405,    69,   392,
      71,   457,    53,    54,   198,   446,   380,    78,   343,   521,
     108,   381,    63,   371,   228,   363,   228,    88,    69,   232,
      71,   190,   155,    94,   194,   366,   370,    78,   496,   498,
     492,   385,   103,   488,   373,   388,   442,    88,   319,    -1,
      -1,    -1,   113,    94,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,   115,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52,
      53,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    66,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    91,    -1,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
     113,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    67,    -1,
      -1,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    93,    -1,    -1,    -1,    -1,    98,
      -1,   100,   101,   102,    17,    18,    -1,    94,    -1,    22,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,
      -1,    34,    35,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    66,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    91,    -1,
      93,    17,    18,    -1,    -1,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    84,    85,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    93,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,   102
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    17,    18,   104,   127,   128,   129,   269,   128,     0,
     129,   130,   113,   131,   132,    11,    12,   114,   133,   134,
     271,    42,   114,   134,   115,    18,    28,    49,    51,    60,
     135,   136,   137,    12,    65,    92,    92,    61,    92,     3,
     137,   116,    29,    50,   138,   139,   152,   153,    25,   117,
     154,   155,   269,   271,    47,    62,   144,   145,   117,   117,
     118,   113,    54,   146,   147,   149,   150,   151,   269,   271,
      31,    46,    56,    57,    58,    67,    72,    74,    82,    91,
      93,    98,   100,   101,   102,   140,   141,   157,   159,   194,
     205,   269,   271,   155,   114,   117,   149,    54,   118,   113,
      18,   141,     3,    18,   113,   120,   179,   180,   264,   265,
     266,   179,   269,   151,   114,   143,    36,   169,   179,     3,
      30,    32,    34,    44,    48,    52,    55,    66,    71,    73,
      75,    84,    85,    99,   160,   161,   202,   203,   205,   269,
      27,    83,    97,   267,     3,    17,    18,    22,    26,    30,
      35,    48,    64,    66,    86,    87,   158,   182,   186,   187,
     188,   202,   204,    49,    60,   268,     3,   132,   148,   113,
     113,    89,    89,    79,    59,    89,   114,   118,   119,   119,
      12,   113,   156,   123,   123,   113,    43,    89,   113,   113,
      76,   113,    88,   113,   115,   210,   211,   223,   113,   210,
     209,   211,   212,   113,     8,     9,    10,    12,    13,    14,
      15,    16,    53,    71,    94,   113,   195,   197,   198,   199,
     229,   262,   263,   269,   271,   272,   273,    19,    20,   171,
     172,   142,     3,   161,   269,   271,   269,   271,   121,    17,
      18,    25,    54,    63,    69,    78,   103,   111,   115,   158,
     181,   195,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   228,   230,   231,   269,    19,    20,
     189,   190,   191,   269,   114,   253,   254,   271,    33,   113,
     111,   167,   168,   178,   183,   264,   271,   111,   259,   260,
     261,   262,   271,   188,   255,   256,   271,   211,    38,   164,
     165,   166,   178,   183,   271,    39,    40,   113,   213,   214,
     215,   240,   241,   243,   245,   246,   247,    76,   164,    76,
     211,    71,   156,   162,   163,   182,   197,   198,   196,   123,
      18,    19,    41,    77,   179,   192,   193,   251,   252,   179,
     192,   193,   114,   118,     7,   200,   201,   271,   169,   179,
     105,   211,   179,     9,   271,    37,    38,   216,   209,   114,
     118,   108,   109,   206,   106,   107,   207,   105,   110,   124,
     244,   123,   114,   118,   271,   257,   258,   271,   122,   114,
     118,   184,   185,   183,   114,   118,   115,   114,   118,   115,
      76,   114,   118,   251,   183,    33,   179,   269,   116,   113,
     270,   271,   114,   270,   114,   118,   200,   271,   195,   251,
     123,   251,   251,    96,   170,   251,   251,   103,   173,   174,
     172,     7,   220,   211,   232,   113,   233,   234,   235,   116,
     111,   218,   219,   220,   124,   110,    68,   227,   228,   190,
     254,   114,   118,   115,   198,   262,     4,   168,   186,   209,
     261,   198,   262,   256,   198,   262,   183,     4,   166,   251,
     113,   114,   125,   248,   249,   264,   264,   163,    19,    20,
     251,    90,   111,   236,   237,   273,   118,   124,   258,    12,
     198,   167,   116,   116,   116,   116,   165,   242,   123,   250,
     271,   114,   118,   185,   185,   113,   118,   114,   118,   208,
     211,   216,   116,   116,     5,     5,   200,   250,   123,   249,
     175,   236,   237,    23,    77,    81,   238,   239,   271,     6,
      21,   120,   176,   177,   191,   114,   176,   114,   177,   121
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   126,   127,   127,   128,   128,   130,   129,   131,   131,
     132,   132,   133,   133,   134,   134,   134,   135,   135,   136,
     136,   137,   137,   137,   137,   137,   138,   138,   139,   140,
     140,   141,   141,   142,   141,   141,   143,   141,   141,   144,
     144,   145,   145,   146,   146,   147,   147,   148,   148,   149,
     150,   150,   151,   151,   151,   152,   152,   153,   153,   153,
     154,   154,   155,   155,   155,   156,   157,   158,   158,   159,
     159,   159,   159,   160,   160,   161,   161,   161,   161,   161,
     162,   162,   163,   163,   163,   163,   164,   164,   165,   165,
     165,   166,   166,   166,   166,   167,   167,   167,   168,   168,
     168,   169,   170,   170,   171,   171,   172,   172,   172,   172,
     172,   172,   172,   173,   173,   175,   174,   176,   176,   177,
     177,   177,   177,   178,   178,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   186,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   188,   188,   188,   188,   188,   189,
     189,   190,   191,   191,   192,   192,   192,   193,   194,   195,
     195,   196,   195,   197,   197,   197,   197,   197,   197,   197,
     198,   198,   199,   199,   199,   200,   200,   201,   201,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   203,   203,   203,   204,   204,   204,   204,   204,
     204,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   206,   206,   207,   207,   208,
     208,   209,   209,   210,   210,   210,   211,   212,   212,   213,
     213,   214,   215,   215,   215,   215,   216,   216,   217,   217,
     218,   218,   219,   219,   220,   220,   221,   221,   221,   221,
     221,   221,   221,   222,   223,   224,   224,   225,   226,   226,
     227,   227,   228,   229,   229,   230,   230,   231,   231,   232,
     233,   233,   234,   235,   236,   236,   237,   238,   238,   239,
     239,   239,   240,   240,   240,   242,   241,   243,   244,   244,
     244,   244,   245,   245,   246,   247,   248,   248,   249,   249,
     250,   250,   251,   251,   252,   252,   253,   253,   254,   255,
     255,   256,   256,   257,   257,   258,   258,   259,   260,   260,
     261,   261,   261,   261,   261,   262,   262,   263,   264,   264,
     265,   266,   267,   267,   267,   267,   268,   268,   268,   269,
     269,   270,   270,   271,   272,   273
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     0,     9,     0,     1,
       3,     2,     1,     2,     1,     4,     1,     0,     1,     1,
       2,     2,     2,     2,     2,     2,     0,     1,     3,     1,
       2,     1,     1,     0,     6,     1,     0,     3,     1,     0,
       1,     3,     2,     0,     1,     1,     2,     0,     1,     4,
       1,     3,     1,     3,     1,     0,     1,     3,     3,     2,
       1,     3,     1,     3,     1,     3,     4,     1,     4,     3,
       3,     6,     6,     1,     3,     1,     3,     3,     3,     3,
       1,     3,     1,     1,     1,     1,     0,     1,     1,     3,
       5,     3,     2,     3,     1,     1,     3,     5,     2,     1,
       1,     5,     0,     1,     1,     3,     2,     4,     3,     3,
       3,     3,     3,     0,     1,     0,     6,     1,     2,     1,
       1,     1,     3,     1,     3,     3,     1,     2,     2,     2,
       3,     0,     2,     1,     1,     1,     4,     4,     4,     6,
       6,     1,     4,     3,     1,     1,     3,     3,     3,     1,
       3,     1,     1,     1,     1,     3,     3,     1,     4,     1,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     4,     4,     5,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     0,     1,     0,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     3,     5,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     3,     1,
       1,     1,     3,     5,     1,     3,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     2,     1,     2,
       2,     3,     1,     1,     3,     4,     1,     3,     2,     3,
       1,     3,     0,     1,     1,     2,     1,     3,     1,     1,
       3,     4,     4,     1,     3,     4,     4,     1,     1,     3,
       1,     4,     4,     1,     1,     1,     1,     1,     0,     1,
       2,     4,     0,     1,     1,     1,     0,     1,     1,     1,
       1,     0,     1,     1,     1,     1
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
        yyerror (param, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, param); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void **param)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (param);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void **param)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, param);
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
                 int yyrule, void **param)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], param);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, param); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void **param)
{
  YY_USE (yyvaluep);
  YY_USE (param);
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
yyparse (void **param)
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
  case 2: /* ParsedGrammar: "UTF-8 byte order mark" ModuleList  */
#line 411 "asn1p_y.y"
                            {
		*param = (yyvsp[0].a_grammar);
	}
#line 1985 "asn1p_y.c"
    break;

  case 3: /* ParsedGrammar: ModuleList  */
#line 414 "asn1p_y.y"
                     {
		*param = (yyvsp[0].a_grammar);
	}
#line 1993 "asn1p_y.c"
    break;

  case 4: /* ModuleList: ModuleDefinition  */
#line 420 "asn1p_y.y"
                         {
		(yyval.a_grammar) = asn1p_new();
		checkmem((yyval.a_grammar));
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[0].a_module), mod_next);
	}
#line 2003 "asn1p_y.c"
    break;

  case 5: /* ModuleList: ModuleList ModuleDefinition  */
#line 425 "asn1p_y.y"
                                      {
		(yyval.a_grammar) = (yyvsp[-1].a_grammar);
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[0].a_module), mod_next);
	}
#line 2012 "asn1p_y.c"
    break;

  case 6: /* $@1: %empty  */
#line 442 "asn1p_y.y"
                    { currentModule = asn1p_module_new(); }
#line 2018 "asn1p_y.c"
    break;

  case 7: /* ModuleDefinition: TypeRefName $@1 optObjectIdentifier TOK_DEFINITIONS optModuleDefinitionFlags TOK_PPEQ TOK_BEGIN optModuleBody TOK_END  */
#line 447 "asn1p_y.y"
                        {

		(yyval.a_module) = currentModule;

		if((yyvsp[-1].a_module)) {
			asn1p_module_t tmp = *((yyval.a_module));
			*((yyval.a_module)) = *((yyvsp[-1].a_module));
			*((yyvsp[-1].a_module)) = tmp;
			asn1p_module_free((yyvsp[-1].a_module));
		} else {
			/* There's a chance that a module is just plain empty */
		}

		(yyval.a_module)->ModuleName = (yyvsp[-8].tv_str);
		(yyval.a_module)->module_oid = (yyvsp[-6].a_oid);
		(yyval.a_module)->module_flags = (yyvsp[-4].a_module_flags);
	}
#line 2040 "asn1p_y.c"
    break;

  case 8: /* optObjectIdentifier: %empty  */
#line 471 "asn1p_y.y"
        { (yyval.a_oid) = 0; }
#line 2046 "asn1p_y.c"
    break;

  case 9: /* optObjectIdentifier: ObjectIdentifier  */
#line 472 "asn1p_y.y"
                           { (yyval.a_oid) = (yyvsp[0].a_oid); }
#line 2052 "asn1p_y.c"
    break;

  case 10: /* ObjectIdentifier: '{' ObjectIdentifierBody '}'  */
#line 476 "asn1p_y.y"
                                     {
		(yyval.a_oid) = (yyvsp[-1].a_oid);
	}
#line 2060 "asn1p_y.c"
    break;

  case 11: /* ObjectIdentifier: '{' '}'  */
#line 479 "asn1p_y.y"
                  {
		(yyval.a_oid) = 0;
	}
#line 2068 "asn1p_y.c"
    break;

  case 12: /* ObjectIdentifierBody: ObjectIdentifierElement  */
#line 485 "asn1p_y.y"
                                {
		(yyval.a_oid) = asn1p_oid_new();
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[0].a_oid_arc));
		if((yyvsp[0].a_oid_arc).name)
			free((yyvsp[0].a_oid_arc).name);
	}
#line 2079 "asn1p_y.c"
    break;

  case 13: /* ObjectIdentifierBody: ObjectIdentifierBody ObjectIdentifierElement  */
#line 491 "asn1p_y.y"
                                                       {
		(yyval.a_oid) = (yyvsp[-1].a_oid);
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[0].a_oid_arc));
		if((yyvsp[0].a_oid_arc).name)
			free((yyvsp[0].a_oid_arc).name);
	}
#line 2090 "asn1p_y.c"
    break;

  case 14: /* ObjectIdentifierElement: Identifier  */
#line 500 "asn1p_y.y"
                   {					/* iso */
		(yyval.a_oid_arc).name = (yyvsp[0].tv_str);
		(yyval.a_oid_arc).number = -1;
	}
#line 2099 "asn1p_y.c"
    break;

  case 15: /* ObjectIdentifierElement: Identifier '(' "number" ')'  */
#line 504 "asn1p_y.y"
                                        {		/* iso(1) */
		(yyval.a_oid_arc).name = (yyvsp[-3].tv_str);
		(yyval.a_oid_arc).number = (yyvsp[-1].a_int);
	}
#line 2108 "asn1p_y.c"
    break;

  case 16: /* ObjectIdentifierElement: "number"  */
#line 508 "asn1p_y.y"
                     {					/* 1 */
		(yyval.a_oid_arc).name = 0;
		(yyval.a_oid_arc).number = (yyvsp[0].a_int);
	}
#line 2117 "asn1p_y.c"
    break;

  case 17: /* optModuleDefinitionFlags: %empty  */
#line 518 "asn1p_y.y"
        { (yyval.a_module_flags) = MSF_NOFLAGS; }
#line 2123 "asn1p_y.c"
    break;

  case 18: /* optModuleDefinitionFlags: ModuleDefinitionFlags  */
#line 519 "asn1p_y.y"
                                {
		(yyval.a_module_flags) = (yyvsp[0].a_module_flags);
	}
#line 2131 "asn1p_y.c"
    break;

  case 19: /* ModuleDefinitionFlags: ModuleDefinitionFlag  */
#line 528 "asn1p_y.y"
                             {
		(yyval.a_module_flags) = (yyvsp[0].a_module_flags);
	}
#line 2139 "asn1p_y.c"
    break;

  case 20: /* ModuleDefinitionFlags: ModuleDefinitionFlags ModuleDefinitionFlag  */
#line 531 "asn1p_y.y"
                                                     {
		(yyval.a_module_flags) = (yyvsp[-1].a_module_flags) | (yyvsp[0].a_module_flags);
	}
#line 2147 "asn1p_y.c"
    break;

  case 21: /* ModuleDefinitionFlag: TOK_EXPLICIT TOK_TAGS  */
#line 540 "asn1p_y.y"
                              {
		(yyval.a_module_flags) = MSF_EXPLICIT_TAGS;
	}
#line 2155 "asn1p_y.c"
    break;

  case 22: /* ModuleDefinitionFlag: TOK_IMPLICIT TOK_TAGS  */
#line 543 "asn1p_y.y"
                                {
		(yyval.a_module_flags) = MSF_IMPLICIT_TAGS;
	}
#line 2163 "asn1p_y.c"
    break;

  case 23: /* ModuleDefinitionFlag: TOK_AUTOMATIC TOK_TAGS  */
#line 546 "asn1p_y.y"
                                 {
		(yyval.a_module_flags) = MSF_AUTOMATIC_TAGS;
	}
#line 2171 "asn1p_y.c"
    break;

  case 24: /* ModuleDefinitionFlag: TOK_EXTENSIBILITY TOK_IMPLIED  */
#line 549 "asn1p_y.y"
                                        {
		(yyval.a_module_flags) = MSF_EXTENSIBILITY_IMPLIED;
	}
#line 2179 "asn1p_y.c"
    break;

  case 25: /* ModuleDefinitionFlag: TOK_capitalreference TOK_INSTRUCTIONS  */
#line 553 "asn1p_y.y"
                                                {
		/* X.680Amd1 specifies TAG and XER */
		if(strcmp((yyvsp[-1].tv_str), "TAG") == 0) {
		 	(yyval.a_module_flags) = MSF_TAG_INSTRUCTIONS;
		} else if(strcmp((yyvsp[-1].tv_str), "XER") == 0) {
		 	(yyval.a_module_flags) = MSF_XER_INSTRUCTIONS;
		} else {
			fprintf(stderr,
				"WARNING: %s INSTRUCTIONS at %s:%d: "
				"Unrecognized encoding reference\n",
				(yyvsp[-1].tv_str), ASN_FILENAME, yylineno);
		 	(yyval.a_module_flags) = MSF_unk_INSTRUCTIONS;
		}
		free((yyvsp[-1].tv_str));
	}
#line 2199 "asn1p_y.c"
    break;

  case 26: /* optModuleBody: %empty  */
#line 574 "asn1p_y.y"
        { (yyval.a_module) = 0; }
#line 2205 "asn1p_y.c"
    break;

  case 27: /* optModuleBody: ModuleBody  */
#line 575 "asn1p_y.y"
                     {
		(yyval.a_module) = (yyvsp[0].a_module);
	}
#line 2213 "asn1p_y.c"
    break;

  case 28: /* ModuleBody: optExports optImports AssignmentList  */
#line 584 "asn1p_y.y"
                                             {
		(yyval.a_module) = asn1p_module_new();
		AL_IMPORT((yyval.a_module), exports, (yyvsp[-2].a_module), xp_next);
		AL_IMPORT((yyval.a_module), imports, (yyvsp[-1].a_module), xp_next);
		asn1p_module_move_members((yyval.a_module), (yyvsp[0].a_module));

		asn1p_module_free((yyvsp[-2].a_module));
		asn1p_module_free((yyvsp[-1].a_module));
		asn1p_module_free((yyvsp[0].a_module));
	}
#line 2228 "asn1p_y.c"
    break;

  case 29: /* AssignmentList: Assignment  */
#line 597 "asn1p_y.y"
                   {
		(yyval.a_module) = (yyvsp[0].a_module);
	}
#line 2236 "asn1p_y.c"
    break;

  case 30: /* AssignmentList: AssignmentList Assignment  */
#line 600 "asn1p_y.y"
                                    {
		if((yyvsp[-1].a_module)) {
			(yyval.a_module) = (yyvsp[-1].a_module);
		} else {
			(yyval.a_module) = (yyvsp[0].a_module);
			break;
		}
        asn1p_module_move_members((yyval.a_module), (yyvsp[0].a_module));
		asn1p_module_free((yyvsp[0].a_module));
	}
#line 2251 "asn1p_y.c"
    break;

  case 31: /* Assignment: DataTypeReference  */
#line 617 "asn1p_y.y"
                          {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[0].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[0].a_expr)->meta_type != AMT_INVALID);
		asn1p_module_member_add((yyval.a_module), (yyvsp[0].a_expr));
	}
#line 2263 "asn1p_y.c"
    break;

  case 32: /* Assignment: ValueAssignment  */
#line 624 "asn1p_y.y"
                          {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[0].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[0].a_expr)->meta_type != AMT_INVALID);
		asn1p_module_member_add((yyval.a_module), (yyvsp[0].a_expr));
	}
#line 2275 "asn1p_y.c"
    break;

  case 33: /* $@2: %empty  */
#line 641 "asn1p_y.y"
                    { asn1p_lexer_hack_push_opaque_state(); }
#line 2281 "asn1p_y.c"
    break;

  case 34: /* Assignment: TypeRefName TOK_capitalreference TOK_PPEQ '{' $@2 Opaque  */
#line 641 "asn1p_y.y"
                                                                               {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		asn1p_expr_t *expr = NEW_EXPR();
		checkmem(expr);
		expr->Identifier = (yyvsp[-5].tv_str);
		expr->reference = asn1p_ref_new(yylineno, currentModule);
		checkmem(expr->reference);
		asn1p_ref_add_component(expr->reference, (yyvsp[-4].tv_str), RLT_CAPITALS);
		free((yyvsp[-4].tv_str));
		expr->meta_type = AMT_VALUESET;
		expr->expr_type = A1TC_REFERENCE;
		expr->constraints = asn1p_constraint_new(yylineno, currentModule);
		checkmem(expr->constraints);
		expr->constraints->type = ACT_EL_VALUE;
		expr->constraints->value = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem(expr->constraints->value);
		expr->constraints->value->type = ATV_UNPARSED;
		asn1p_module_member_add((yyval.a_module), expr);
	}
#line 2306 "asn1p_y.c"
    break;

  case 35: /* Assignment: ValueSetTypeAssignment  */
#line 668 "asn1p_y.y"
                                 {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[0].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[0].a_expr)->meta_type != AMT_INVALID);
		asn1p_module_member_add((yyval.a_module), (yyvsp[0].a_expr));
	}
#line 2318 "asn1p_y.c"
    break;

  case 36: /* $@3: %empty  */
#line 676 "asn1p_y.y"
                { asn1p_lexer_hack_push_encoding_control(); }
#line 2324 "asn1p_y.c"
    break;

  case 37: /* Assignment: TOK_ENCODING_CONTROL TOK_capitalreference $@3  */
#line 677 "asn1p_y.y"
                        {
		fprintf(stderr,
			"WARNING: ENCODING-CONTROL %s "
			"specification at %s:%d ignored\n",
			(yyvsp[-1].tv_str), ASN_FILENAME, yylineno);
		free((yyvsp[-1].tv_str));
		(yyval.a_module) = 0;
	}
#line 2337 "asn1p_y.c"
    break;

  case 38: /* Assignment: BasicString  */
#line 689 "asn1p_y.y"
                      {
		return yyerror(param,
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
#line 2347 "asn1p_y.c"
    break;

  case 39: /* optImports: %empty  */
#line 702 "asn1p_y.y"
        { (yyval.a_module) = 0; }
#line 2353 "asn1p_y.c"
    break;

  case 41: /* ImportsDefinition: TOK_IMPORTS optImportsBundleSet ';'  */
#line 706 "asn1p_y.y"
                                            {
		if(!saved_aid && 0)
			return yyerror(param, "Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		(yyval.a_module) = (yyvsp[-1].a_module);
	}
#line 2365 "asn1p_y.c"
    break;

  case 42: /* ImportsDefinition: TOK_IMPORTS TOK_FROM  */
#line 716 "asn1p_y.y"
                                         {
		return yyerror(param, "Empty IMPORTS list");
	}
#line 2373 "asn1p_y.c"
    break;

  case 43: /* optImportsBundleSet: %empty  */
#line 722 "asn1p_y.y"
        { (yyval.a_module) = asn1p_module_new(); }
#line 2379 "asn1p_y.c"
    break;

  case 45: /* ImportsBundleSet: ImportsBundle  */
#line 726 "asn1p_y.y"
                      {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[0].a_xports), xp_next);
	}
#line 2389 "asn1p_y.c"
    break;

  case 46: /* ImportsBundleSet: ImportsBundleSet ImportsBundle  */
#line 731 "asn1p_y.y"
                                         {
		(yyval.a_module) = (yyvsp[-1].a_module);
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[0].a_xports), xp_next);
	}
#line 2398 "asn1p_y.c"
    break;

  case 47: /* AssignedIdentifier: %empty  */
#line 738 "asn1p_y.y"
        { memset(&(yyval.a_aid), 0, sizeof((yyval.a_aid))); }
#line 2404 "asn1p_y.c"
    break;

  case 48: /* AssignedIdentifier: ObjectIdentifier  */
#line 739 "asn1p_y.y"
                           { (yyval.a_aid).oid = (yyvsp[0].a_oid); }
#line 2410 "asn1p_y.c"
    break;

  case 49: /* ImportsBundle: ImportsList TOK_FROM TypeRefName AssignedIdentifier  */
#line 743 "asn1p_y.y"
                                                            {
		(yyval.a_xports) = (yyvsp[-3].a_xports);
		(yyval.a_xports)->fromModuleName = (yyvsp[-1].tv_str);
		(yyval.a_xports)->identifier = (yyvsp[0].a_aid);
		/* This stupid thing is used for look-back hack. */
		saved_aid = (yyval.a_xports)->identifier.oid ? 0 : &((yyval.a_xports)->identifier);
		checkmem((yyval.a_xports));
	}
#line 2423 "asn1p_y.c"
    break;

  case 50: /* ImportsList: ImportsElement  */
#line 754 "asn1p_y.y"
                       {
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[0].a_expr), next);
	}
#line 2433 "asn1p_y.c"
    break;

  case 51: /* ImportsList: ImportsList ',' ImportsElement  */
#line 759 "asn1p_y.y"
                                         {
		(yyval.a_xports) = (yyvsp[-2].a_xports);
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[0].a_expr), next);
	}
#line 2442 "asn1p_y.c"
    break;

  case 52: /* ImportsElement: TypeRefName  */
#line 766 "asn1p_y.y"
                    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
#line 2453 "asn1p_y.c"
    break;

  case 53: /* ImportsElement: TypeRefName '{' '}'  */
#line 772 "asn1p_y.y"
                              {		/* Completely equivalent to above */
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
#line 2464 "asn1p_y.c"
    break;

  case 54: /* ImportsElement: Identifier  */
#line 778 "asn1p_y.y"
                     {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
#line 2475 "asn1p_y.c"
    break;

  case 55: /* optExports: %empty  */
#line 788 "asn1p_y.y"
        { (yyval.a_module) = 0; }
#line 2481 "asn1p_y.c"
    break;

  case 56: /* optExports: ExportsDefinition  */
#line 789 "asn1p_y.y"
                            {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		if((yyvsp[0].a_xports)) {
			TQ_ADD(&((yyval.a_module)->exports), (yyvsp[0].a_xports), xp_next);
		} else {
			/* "EXPORTS ALL;" */
		}
	}
#line 2495 "asn1p_y.c"
    break;

  case 57: /* ExportsDefinition: TOK_EXPORTS ExportsBody ';'  */
#line 801 "asn1p_y.y"
                                    {
		(yyval.a_xports) = (yyvsp[-1].a_xports);
	}
#line 2503 "asn1p_y.c"
    break;

  case 58: /* ExportsDefinition: TOK_EXPORTS TOK_ALL ';'  */
#line 804 "asn1p_y.y"
                                  {
		(yyval.a_xports) = 0;
	}
#line 2511 "asn1p_y.c"
    break;

  case 59: /* ExportsDefinition: TOK_EXPORTS ';'  */
#line 807 "asn1p_y.y"
                          {
		/* Empty EXPORTS clause effectively prohibits export. */
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
	}
#line 2521 "asn1p_y.c"
    break;

  case 60: /* ExportsBody: ExportsElement  */
#line 815 "asn1p_y.y"
                       {
		(yyval.a_xports) = asn1p_xports_new();
		assert((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[0].a_expr), next);
	}
#line 2531 "asn1p_y.c"
    break;

  case 61: /* ExportsBody: ExportsBody ',' ExportsElement  */
#line 820 "asn1p_y.y"
                                         {
		(yyval.a_xports) = (yyvsp[-2].a_xports);
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[0].a_expr), next);
	}
#line 2540 "asn1p_y.c"
    break;

  case 62: /* ExportsElement: TypeRefName  */
#line 827 "asn1p_y.y"
                    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
#line 2551 "asn1p_y.c"
    break;

  case 63: /* ExportsElement: TypeRefName '{' '}'  */
#line 833 "asn1p_y.y"
                              {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
#line 2562 "asn1p_y.c"
    break;

  case 64: /* ExportsElement: Identifier  */
#line 839 "asn1p_y.y"
                     {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
#line 2573 "asn1p_y.c"
    break;

  case 65: /* ValueSet: '{' ElementSetSpecs '}'  */
#line 848 "asn1p_y.y"
                                  { (yyval.a_constr) = (yyvsp[-1].a_constr); }
#line 2579 "asn1p_y.c"
    break;

  case 66: /* ValueSetTypeAssignment: TypeRefName Type TOK_PPEQ ValueSet  */
#line 851 "asn1p_y.y"
                                           {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
	}
#line 2591 "asn1p_y.c"
    break;

  case 67: /* DefinedType: ComplexTypeReference  */
#line 871 "asn1p_y.y"
                             {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[0].a_ref);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
#line 2603 "asn1p_y.c"
    break;

  case 68: /* DefinedType: ComplexTypeReference '{' ActualParameterList '}'  */
#line 881 "asn1p_y.y"
                                                           {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[-3].a_ref);
		(yyval.a_expr)->rhs_pspecs = (yyvsp[-1].a_expr);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
#line 2616 "asn1p_y.c"
    break;

  case 69: /* DataTypeReference: TypeRefName TOK_PPEQ Type  */
#line 901 "asn1p_y.y"
                                  {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		assert((yyval.a_expr)->expr_type);
		assert((yyval.a_expr)->meta_type);
	}
#line 2627 "asn1p_y.c"
    break;

  case 70: /* DataTypeReference: TypeRefName TOK_PPEQ ObjectClass  */
#line 907 "asn1p_y.y"
                                           {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
#line 2638 "asn1p_y.c"
    break;

  case 71: /* DataTypeReference: TypeRefName '{' ParameterArgumentList '}' TOK_PPEQ Type  */
#line 923 "asn1p_y.y"
                                                                  {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-5].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[-3].a_plist);
	}
#line 2648 "asn1p_y.c"
    break;

  case 72: /* DataTypeReference: TypeRefName '{' ParameterArgumentList '}' TOK_PPEQ ObjectClass  */
#line 929 "asn1p_y.y"
                                                                         {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-5].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[-3].a_plist);
	}
#line 2658 "asn1p_y.c"
    break;

  case 73: /* ParameterArgumentList: ParameterArgumentName  */
#line 937 "asn1p_y.y"
                              {
		int ret;
		(yyval.a_plist) = asn1p_paramlist_new(yylineno);
		checkmem((yyval.a_plist));
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[0].a_parg).governor, (yyvsp[0].a_parg).argument);
		checkmem(ret == 0);
		asn1p_ref_free((yyvsp[0].a_parg).governor);
		free((yyvsp[0].a_parg).argument);
	}
#line 2672 "asn1p_y.c"
    break;

  case 74: /* ParameterArgumentList: ParameterArgumentList ',' ParameterArgumentName  */
#line 946 "asn1p_y.y"
                                                          {
		int ret;
		(yyval.a_plist) = (yyvsp[-2].a_plist);
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[0].a_parg).governor, (yyvsp[0].a_parg).argument);
		checkmem(ret == 0);
		asn1p_ref_free((yyvsp[0].a_parg).governor);
		free((yyvsp[0].a_parg).argument);
	}
#line 2685 "asn1p_y.c"
    break;

  case 75: /* ParameterArgumentName: TypeRefName  */
#line 957 "asn1p_y.y"
                    {
		(yyval.a_parg).governor = NULL;
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
#line 2694 "asn1p_y.c"
    break;

  case 76: /* ParameterArgumentName: TypeRefName ':' Identifier  */
#line 961 "asn1p_y.y"
                                     {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[-2].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
		free((yyvsp[-2].tv_str));
	}
#line 2707 "asn1p_y.c"
    break;

  case 77: /* ParameterArgumentName: TypeRefName ':' TypeRefName  */
#line 969 "asn1p_y.y"
                                      {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[-2].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
		free((yyvsp[-2].tv_str));
	}
#line 2720 "asn1p_y.c"
    break;

  case 78: /* ParameterArgumentName: BasicTypeId ':' Identifier  */
#line 977 "asn1p_y.y"
                                     {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor,
			ASN_EXPR_TYPE2STR((yyvsp[-2].a_type)), 1);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
#line 2733 "asn1p_y.c"
    break;

  case 79: /* ParameterArgumentName: BasicTypeId ':' TypeRefName  */
#line 985 "asn1p_y.y"
                                      {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor,
			ASN_EXPR_TYPE2STR((yyvsp[-2].a_type)), 1);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
#line 2746 "asn1p_y.c"
    break;

  case 80: /* ActualParameterList: ActualParameter  */
#line 996 "asn1p_y.y"
                        {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2756 "asn1p_y.c"
    break;

  case 81: /* ActualParameterList: ActualParameterList ',' ActualParameter  */
#line 1001 "asn1p_y.y"
                                                  {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2765 "asn1p_y.c"
    break;

  case 83: /* ActualParameter: SimpleValue  */
#line 1009 "asn1p_y.y"
                      {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("?");
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
#line 2778 "asn1p_y.c"
    break;

  case 84: /* ActualParameter: DefinedValue  */
#line 1017 "asn1p_y.y"
                       {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("?");
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
#line 2791 "asn1p_y.c"
    break;

  case 85: /* ActualParameter: ValueSet  */
#line 1025 "asn1p_y.y"
                   {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->expr_type = A1TC_VALUESET;
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
	}
#line 2802 "asn1p_y.c"
    break;

  case 86: /* optComponentTypeLists: %empty  */
#line 1048 "asn1p_y.y"
        { (yyval.a_expr) = NEW_EXPR(); }
#line 2808 "asn1p_y.c"
    break;

  case 87: /* optComponentTypeLists: ComponentTypeLists  */
#line 1049 "asn1p_y.y"
                             { (yyval.a_expr) = (yyvsp[0].a_expr); }
#line 2814 "asn1p_y.c"
    break;

  case 88: /* ComponentTypeLists: ComponentType  */
#line 1052 "asn1p_y.y"
                      {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2824 "asn1p_y.c"
    break;

  case 89: /* ComponentTypeLists: ComponentTypeLists ',' ComponentType  */
#line 1057 "asn1p_y.y"
                                               {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2833 "asn1p_y.c"
    break;

  case 90: /* ComponentTypeLists: ComponentTypeLists ',' TOK_VBracketLeft ComponentTypeLists TOK_VBracketRight  */
#line 1061 "asn1p_y.y"
                                                                                       {
		(yyval.a_expr) = (yyvsp[-4].a_expr);
		asn1p_expr_add_many((yyval.a_expr), (yyvsp[-1].a_expr));
		asn1p_expr_free((yyvsp[-1].a_expr));
	}
#line 2843 "asn1p_y.c"
    break;

  case 91: /* ComponentType: Identifier MaybeIndirectTaggedType optMarker  */
#line 1069 "asn1p_y.y"
                                                     {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyvsp[0].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 2855 "asn1p_y.c"
    break;

  case 92: /* ComponentType: MaybeIndirectTaggedType optMarker  */
#line 1076 "asn1p_y.y"
                                            {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		(yyvsp[0].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
#line 2866 "asn1p_y.c"
    break;

  case 93: /* ComponentType: TOK_COMPONENTS TOK_OF MaybeIndirectTaggedType  */
#line 1082 "asn1p_y.y"
                                                        {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->meta_type = (yyvsp[0].a_expr)->meta_type;
		(yyval.a_expr)->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2878 "asn1p_y.c"
    break;

  case 94: /* ComponentType: ExtensionAndException  */
#line 1089 "asn1p_y.y"
                                {
		(yyval.a_expr) = (yyvsp[0].a_expr);
	}
#line 2886 "asn1p_y.c"
    break;

  case 95: /* AlternativeTypeLists: AlternativeType  */
#line 1095 "asn1p_y.y"
                        {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2896 "asn1p_y.c"
    break;

  case 96: /* AlternativeTypeLists: AlternativeTypeLists ',' AlternativeType  */
#line 1100 "asn1p_y.y"
                                                   {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2905 "asn1p_y.c"
    break;

  case 97: /* AlternativeTypeLists: AlternativeTypeLists ',' TOK_VBracketLeft AlternativeTypeLists TOK_VBracketRight  */
#line 1104 "asn1p_y.y"
                                                                                           {
		(yyval.a_expr) = (yyvsp[-4].a_expr);
		asn1p_expr_add_many((yyval.a_expr), (yyvsp[-1].a_expr));
	}
#line 2914 "asn1p_y.c"
    break;

  case 98: /* AlternativeType: Identifier MaybeIndirectTaggedType  */
#line 1111 "asn1p_y.y"
                                           {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-1].tv_str);
	}
#line 2924 "asn1p_y.c"
    break;

  case 99: /* AlternativeType: ExtensionAndException  */
#line 1116 "asn1p_y.y"
                                {
		(yyval.a_expr) = (yyvsp[0].a_expr);
	}
#line 2932 "asn1p_y.c"
    break;

  case 100: /* AlternativeType: MaybeIndirectTaggedType  */
#line 1119 "asn1p_y.y"
                                  {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
#line 2941 "asn1p_y.c"
    break;

  case 101: /* ObjectClass: TOK_CLASS '{' FieldSpec '}' optWithSyntax  */
#line 1126 "asn1p_y.y"
                                                  {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->with_syntax = (yyvsp[0].a_wsynt);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
#line 2953 "asn1p_y.c"
    break;

  case 102: /* optUNIQUE: %empty  */
#line 1136 "asn1p_y.y"
        { (yyval.a_int) = 0; }
#line 2959 "asn1p_y.c"
    break;

  case 103: /* optUNIQUE: TOK_UNIQUE  */
#line 1137 "asn1p_y.y"
                     { (yyval.a_int) = 1; }
#line 2965 "asn1p_y.c"
    break;

  case 104: /* FieldSpec: ClassField  */
#line 1141 "asn1p_y.y"
                   {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_CLASSDEF;
		(yyval.a_expr)->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2977 "asn1p_y.c"
    break;

  case 105: /* FieldSpec: FieldSpec ',' ClassField  */
#line 1148 "asn1p_y.y"
                                   {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2986 "asn1p_y.c"
    break;

  case 106: /* ClassField: TOK_typefieldreference optMarker  */
#line 1158 "asn1p_y.y"
                                         {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-1].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_TFS;	/* TypeFieldSpec */
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 2999 "asn1p_y.c"
    break;

  case 107: /* ClassField: TOK_valuefieldreference Type optUNIQUE optMarker  */
#line 1168 "asn1p_y.y"
                                                           {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_FTVFS;	/* FixedTypeValueFieldSpec */
		(yyval.a_expr)->unique = (yyvsp[-1].a_int);
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
		asn1p_expr_add((yyval.a_expr), (yyvsp[-2].a_expr));
	}
#line 3013 "asn1p_y.c"
    break;

  case 108: /* ClassField: TOK_valuefieldreference FieldName optMarker  */
#line 1179 "asn1p_y.y"
                                                      {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVFS;
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3026 "asn1p_y.c"
    break;

  case 109: /* ClassField: TOK_valuefieldreference DefinedObjectClass optMarker  */
#line 1189 "asn1p_y.y"
                                                               {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_OFS;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3040 "asn1p_y.c"
    break;

  case 110: /* ClassField: TOK_typefieldreference FieldName optMarker  */
#line 1200 "asn1p_y.y"
                                                     {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVSFS;
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3053 "asn1p_y.c"
    break;

  case 111: /* ClassField: TOK_typefieldreference Type optMarker  */
#line 1210 "asn1p_y.y"
                                                {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_FTVSFS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[-1].a_expr));
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3067 "asn1p_y.c"
    break;

  case 112: /* ClassField: TOK_typefieldreference DefinedObjectClass optMarker  */
#line 1221 "asn1p_y.y"
                                                              {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_OSFS;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3081 "asn1p_y.c"
    break;

  case 113: /* optWithSyntax: %empty  */
#line 1233 "asn1p_y.y"
        { (yyval.a_wsynt) = 0; }
#line 3087 "asn1p_y.c"
    break;

  case 114: /* optWithSyntax: WithSyntax  */
#line 1234 "asn1p_y.y"
                     {
		(yyval.a_wsynt) = (yyvsp[0].a_wsynt);
	}
#line 3095 "asn1p_y.c"
    break;

  case 115: /* $@4: %empty  */
#line 1241 "asn1p_y.y"
                { asn1p_lexer_hack_enable_with_syntax(); }
#line 3101 "asn1p_y.c"
    break;

  case 116: /* WithSyntax: TOK_WITH TOK_SYNTAX '{' $@4 WithSyntaxList '}'  */
#line 1243 "asn1p_y.y"
                    {
		(yyval.a_wsynt) = (yyvsp[-1].a_wsynt);
	}
#line 3109 "asn1p_y.c"
    break;

  case 117: /* WithSyntaxList: WithSyntaxToken  */
#line 1249 "asn1p_y.y"
                        {
		(yyval.a_wsynt) = asn1p_wsyntx_new();
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[0].a_wchunk), next);
	}
#line 3118 "asn1p_y.c"
    break;

  case 118: /* WithSyntaxList: WithSyntaxList WithSyntaxToken  */
#line 1253 "asn1p_y.y"
                                         {
		(yyval.a_wsynt) = (yyvsp[-1].a_wsynt);
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[0].a_wchunk), next);
	}
#line 3127 "asn1p_y.c"
    break;

  case 119: /* WithSyntaxToken: TOK_whitespace  */
#line 1260 "asn1p_y.y"
                       {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[0].tv_opaque).buf, 0);
		(yyval.a_wchunk)->type = WC_WHITESPACE;
	}
#line 3136 "asn1p_y.c"
    break;

  case 120: /* WithSyntaxToken: TOK_Literal  */
#line 1264 "asn1p_y.y"
                      {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[0].tv_str), 0);
	}
#line 3144 "asn1p_y.c"
    break;

  case 121: /* WithSyntaxToken: PrimitiveFieldReference  */
#line 1267 "asn1p_y.y"
                                  {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[0].a_refcomp).name, 0);
		(yyval.a_wchunk)->type = WC_FIELD;
	}
#line 3153 "asn1p_y.c"
    break;

  case 122: /* WithSyntaxToken: '[' WithSyntaxList ']'  */
#line 1271 "asn1p_y.y"
                                 {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromsyntax((yyvsp[-1].a_wsynt));
	}
#line 3161 "asn1p_y.c"
    break;

  case 123: /* ExtensionAndException: "..."  */
#line 1277 "asn1p_y.y"
                      {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3174 "asn1p_y.c"
    break;

  case 124: /* ExtensionAndException: "..." '!' DefinedValue  */
#line 1285 "asn1p_y.y"
                                         {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->value = (yyvsp[0].a_value);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3188 "asn1p_y.c"
    break;

  case 125: /* ExtensionAndException: "..." '!' SignedNumber  */
#line 1294 "asn1p_y.y"
                                         {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		(yyval.a_expr)->value = (yyvsp[0].a_value);
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3202 "asn1p_y.c"
    break;

  case 127: /* TaggedType: optTag UntaggedType  */
#line 1308 "asn1p_y.y"
                        {
        (yyval.a_expr) = (yyvsp[0].a_expr);
        (yyval.a_expr)->tag = (yyvsp[-1].a_tag);
    }
#line 3211 "asn1p_y.c"
    break;

  case 128: /* DefinedUntaggedType: DefinedType optManyConstraints  */
#line 1315 "asn1p_y.y"
                                       {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		/*
		 * Outer constraint for SEQUENCE OF and SET OF applies
		 * to the inner type.
		 */
		if((yyval.a_expr)->expr_type == ASN_CONSTR_SEQUENCE_OF
		|| (yyval.a_expr)->expr_type == ASN_CONSTR_SET_OF) {
			assert(!TQ_FIRST(&((yyval.a_expr)->members))->constraints);
			TQ_FIRST(&((yyval.a_expr)->members))->constraints = (yyvsp[0].a_constr);
		} else {
			if((yyval.a_expr)->constraints) {
				assert(!(yyvsp[0].a_constr));
				/* Check this : optManyConstraints is not used ?! */
				asn1p_constraint_free((yyvsp[0].a_constr));
			} else {
				(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
			}
		}
	}
#line 3236 "asn1p_y.c"
    break;

  case 129: /* UntaggedType: TypeDeclaration optManyConstraints  */
#line 1338 "asn1p_y.y"
                                           {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		/*
		 * Outer constraint for SEQUENCE OF and SET OF applies
		 * to the inner type.
		 */
		if((yyval.a_expr)->expr_type == ASN_CONSTR_SEQUENCE_OF
		|| (yyval.a_expr)->expr_type == ASN_CONSTR_SET_OF) {
			assert(!TQ_FIRST(&((yyval.a_expr)->members))->constraints);
			TQ_FIRST(&((yyval.a_expr)->members))->constraints = (yyvsp[0].a_constr);
		} else {
			if((yyval.a_expr)->constraints) {
				assert(!(yyvsp[0].a_constr));
				/* Check this : optManyConstraints is not used ?! */
				asn1p_constraint_free((yyvsp[0].a_constr));
			} else {
				(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
			}
		}
	}
#line 3261 "asn1p_y.c"
    break;

  case 130: /* MaybeIndirectTaggedType: optTag MaybeIndirectTypeDeclaration optManyConstraints  */
#line 1361 "asn1p_y.y"
                                                           {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		(yyval.a_expr)->tag = (yyvsp[-2].a_tag);
		/*
		 * Outer constraint for SEQUENCE OF and SET OF applies
		 * to the inner type.
		 */
		if((yyval.a_expr)->expr_type == ASN_CONSTR_SEQUENCE_OF
		|| (yyval.a_expr)->expr_type == ASN_CONSTR_SET_OF) {
			assert(!TQ_FIRST(&((yyval.a_expr)->members))->constraints);
			TQ_FIRST(&((yyval.a_expr)->members))->constraints = (yyvsp[0].a_constr);
		} else {
			if((yyval.a_expr)->constraints) {
				assert(!(yyvsp[-1].a_expr));
				/* Check this : optManyConstraints is not used ?! */
				asn1p_constraint_free((yyvsp[0].a_constr));
			} else {
				(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
			}
		}
	}
#line 3287 "asn1p_y.c"
    break;

  case 131: /* NSTD_IndirectMarker: %empty  */
#line 1385 "asn1p_y.y"
        {
		(yyval.a_int) = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
#line 3296 "asn1p_y.c"
    break;

  case 132: /* MaybeIndirectTypeDeclaration: NSTD_IndirectMarker TypeDeclaration  */
#line 1392 "asn1p_y.y"
                                        {
        (yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->marker.flags |= (yyvsp[-1].a_int);

		if(((yyval.a_expr)->marker.flags & EM_INDIRECT)
		&& ((yyval.a_expr)->marker.flags & EM_OPTIONAL) != EM_OPTIONAL) {
			fprintf(stderr,
				"INFO: Directive <ASN1C:RepresentAsPointer> "
				"applied to %s at %s:%d\n",
				ASN_EXPR_TYPE2STR((yyval.a_expr)->expr_type)
					?  ASN_EXPR_TYPE2STR((yyval.a_expr)->expr_type)
					: "member",
				ASN_FILENAME, (yyval.a_expr)->_lineno
			);
		}
    }
#line 3317 "asn1p_y.c"
    break;

  case 136: /* ConcreteTypeDeclaration: TOK_CHOICE '{' AlternativeTypeLists '}'  */
#line 1416 "asn1p_y.y"
                                                  {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_CHOICE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3328 "asn1p_y.c"
    break;

  case 137: /* ConcreteTypeDeclaration: TOK_SEQUENCE '{' optComponentTypeLists '}'  */
#line 1422 "asn1p_y.y"
                                                     {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3339 "asn1p_y.c"
    break;

  case 138: /* ConcreteTypeDeclaration: TOK_SET '{' optComponentTypeLists '}'  */
#line 1428 "asn1p_y.y"
                                                {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3350 "asn1p_y.c"
    break;

  case 139: /* ConcreteTypeDeclaration: TOK_SEQUENCE optSizeOrConstraint TOK_OF optIdentifier optTag MaybeIndirectTypeDeclaration  */
#line 1434 "asn1p_y.y"
                                                                                                    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->constraints = (yyvsp[-4].a_constr);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE_OF;
		(yyval.a_expr)->meta_type = AMT_TYPE;
		(yyvsp[0].a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyvsp[0].a_expr)->tag = (yyvsp[-1].a_tag);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 3365 "asn1p_y.c"
    break;

  case 140: /* ConcreteTypeDeclaration: TOK_SET optSizeOrConstraint TOK_OF optIdentifier optTag MaybeIndirectTypeDeclaration  */
#line 1444 "asn1p_y.y"
                                                                                               {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->constraints = (yyvsp[-4].a_constr);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET_OF;
		(yyval.a_expr)->meta_type = AMT_TYPE;
		(yyvsp[0].a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyvsp[0].a_expr)->tag = (yyvsp[-1].a_tag);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 3380 "asn1p_y.c"
    break;

  case 141: /* ConcreteTypeDeclaration: TOK_ANY  */
#line 1454 "asn1p_y.y"
                                                        {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3391 "asn1p_y.c"
    break;

  case 142: /* ConcreteTypeDeclaration: TOK_ANY TOK_DEFINED TOK_BY Identifier  */
#line 1460 "asn1p_y.y"
                                                        {
		int ret;
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_expr)->reference,
			(yyvsp[0].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
		free((yyvsp[0].tv_str));
	}
#line 3408 "asn1p_y.c"
    break;

  case 143: /* ConcreteTypeDeclaration: TOK_INSTANCE TOK_OF ComplexTypeReference  */
#line 1472 "asn1p_y.y"
                                                   {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[0].a_ref);
		(yyval.a_expr)->expr_type = A1TC_INSTANCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3420 "asn1p_y.c"
    break;

  case 144: /* ComplexTypeReference: TOK_typereference  */
#line 1487 "asn1p_y.y"
                          {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[0].tv_str));
	}
#line 3433 "asn1p_y.c"
    break;

  case 145: /* ComplexTypeReference: TOK_capitalreference  */
#line 1495 "asn1p_y.y"
                               {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_CAPITALS);
		free((yyvsp[0].tv_str));
		checkmem(ret == 0);
	}
#line 3446 "asn1p_y.c"
    break;

  case 146: /* ComplexTypeReference: TOK_typereference '.' TypeRefName  */
#line 1503 "asn1p_y.y"
                                            {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[-2].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[-2].tv_str));
		free((yyvsp[0].tv_str));
	}
#line 3462 "asn1p_y.c"
    break;

  case 147: /* ComplexTypeReference: TOK_capitalreference '.' TypeRefName  */
#line 1514 "asn1p_y.y"
                                               {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[-2].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[-2].tv_str));
		free((yyvsp[0].tv_str));
	}
#line 3478 "asn1p_y.c"
    break;

  case 148: /* ComplexTypeReference: TOK_capitalreference '.' ComplexTypeReferenceAmpList  */
#line 1525 "asn1p_y.y"
                                                               {
		int ret;
		(yyval.a_ref) = (yyvsp[0].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[-2].tv_str), RLT_CAPITALS);
		free((yyvsp[-2].tv_str));
		checkmem(ret == 0);
		/*
		 * Move the last element infront.
		 */
		{
			struct asn1p_ref_component_s tmp_comp;
			tmp_comp = (yyval.a_ref)->components[(yyval.a_ref)->comp_count-1];
			memmove(&(yyval.a_ref)->components[1],
				&(yyval.a_ref)->components[0],
				sizeof((yyval.a_ref)->components[0])
				* ((yyval.a_ref)->comp_count - 1));
			(yyval.a_ref)->components[0] = tmp_comp;
		}
	}
#line 3502 "asn1p_y.c"
    break;

  case 149: /* ComplexTypeReferenceAmpList: ComplexTypeReferenceElement  */
#line 1547 "asn1p_y.y"
                                    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].a_refcomp).name, (yyvsp[0].a_refcomp).lex_type);
		free((yyvsp[0].a_refcomp).name);
		checkmem(ret == 0);
	}
#line 3515 "asn1p_y.c"
    break;

  case 150: /* ComplexTypeReferenceAmpList: ComplexTypeReferenceAmpList '.' ComplexTypeReferenceElement  */
#line 1555 "asn1p_y.y"
                                                                      {
		int ret;
		(yyval.a_ref) = (yyvsp[-2].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].a_refcomp).name, (yyvsp[0].a_refcomp).lex_type);
		free((yyvsp[0].a_refcomp).name);
		checkmem(ret == 0);
	}
#line 3527 "asn1p_y.c"
    break;

  case 152: /* PrimitiveFieldReference: TOK_typefieldreference  */
#line 1568 "asn1p_y.y"
                               {
		(yyval.a_refcomp).lex_type = RLT_AmpUppercase;
		(yyval.a_refcomp).name = (yyvsp[0].tv_str);
	}
#line 3536 "asn1p_y.c"
    break;

  case 153: /* PrimitiveFieldReference: TOK_valuefieldreference  */
#line 1573 "asn1p_y.y"
                                  {
		(yyval.a_refcomp).lex_type = RLT_Amplowercase;
		(yyval.a_refcomp).name = (yyvsp[0].tv_str);
	}
#line 3545 "asn1p_y.c"
    break;

  case 154: /* FieldName: TOK_typefieldreference  */
#line 1582 "asn1p_y.y"
                               {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_AmpUppercase);
		free((yyvsp[0].tv_str));
	}
#line 3555 "asn1p_y.c"
    break;

  case 155: /* FieldName: FieldName '.' TOK_typefieldreference  */
#line 1587 "asn1p_y.y"
                                               {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_AmpUppercase);
		free((yyvsp[0].tv_str));
	}
#line 3565 "asn1p_y.c"
    break;

  case 156: /* FieldName: FieldName '.' TOK_valuefieldreference  */
#line 1592 "asn1p_y.y"
                                                {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_Amplowercase);
		free((yyvsp[0].tv_str));
	}
#line 3575 "asn1p_y.c"
    break;

  case 157: /* DefinedObjectClass: TOK_capitalreference  */
#line 1600 "asn1p_y.y"
                             {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_CAPITALS);
		free((yyvsp[0].tv_str));
	}
#line 3585 "asn1p_y.c"
    break;

  case 158: /* ValueAssignment: Identifier Type TOK_PPEQ Value  */
#line 1623 "asn1p_y.y"
                                       {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		assert((yyval.a_expr)->Identifier == NULL);
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
#line 3597 "asn1p_y.c"
    break;

  case 161: /* $@5: %empty  */
#line 1635 "asn1p_y.y"
              { asn1p_lexer_hack_push_opaque_state(); }
#line 3603 "asn1p_y.c"
    break;

  case 162: /* Value: '{' $@5 Opaque  */
#line 1635 "asn1p_y.y"
                                                               {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_UNPARSED;
	}
#line 3613 "asn1p_y.c"
    break;

  case 163: /* SimpleValue: TOK_NULL  */
#line 1643 "asn1p_y.y"
                 {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_NULL;
	}
#line 3623 "asn1p_y.c"
    break;

  case 164: /* SimpleValue: TOK_FALSE  */
#line 1648 "asn1p_y.y"
                    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
#line 3633 "asn1p_y.c"
    break;

  case 165: /* SimpleValue: TOK_TRUE  */
#line 1653 "asn1p_y.y"
                   {
		(yyval.a_value) = asn1p_value_fromint(1);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
#line 3643 "asn1p_y.c"
    break;

  case 171: /* DefinedValue: TypeRefName '.' Identifier  */
#line 1666 "asn1p_y.y"
                                     {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno, currentModule);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, (yyvsp[-2].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component(ref, (yyvsp[0].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_value) = asn1p_value_fromref(ref, 0);
		checkmem((yyval.a_value));
		free((yyvsp[-2].tv_str));
		free((yyvsp[0].tv_str));
	}
#line 3662 "asn1p_y.c"
    break;

  case 172: /* RestrictedCharacterStringValue: TOK_cstring  */
#line 1684 "asn1p_y.y"
                    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem((yyval.a_value));
	}
#line 3671 "asn1p_y.c"
    break;

  case 173: /* RestrictedCharacterStringValue: TOK_tuple  */
#line 1688 "asn1p_y.y"
                    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TUPLE;
	}
#line 3681 "asn1p_y.c"
    break;

  case 174: /* RestrictedCharacterStringValue: TOK_quadruple  */
#line 1693 "asn1p_y.y"
                        {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_QUADRUPLE;
	}
#line 3691 "asn1p_y.c"
    break;

  case 175: /* Opaque: OpaqueFirstToken  */
#line 1701 "asn1p_y.y"
                     {
		(yyval.tv_opaque).len = (yyvsp[0].tv_opaque).len + 1;
		(yyval.tv_opaque).buf = malloc(1 + (yyval.tv_opaque).len + 1);
		checkmem((yyval.tv_opaque).buf);
		(yyval.tv_opaque).buf[0] = '{';
		memcpy((yyval.tv_opaque).buf + 1, (yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len);
		(yyval.tv_opaque).buf[(yyval.tv_opaque).len] = '\0';
		free((yyvsp[0].tv_opaque).buf);
    }
#line 3705 "asn1p_y.c"
    break;

  case 176: /* Opaque: Opaque TOK_opaque  */
#line 1710 "asn1p_y.y"
                            {
		int newsize = (yyvsp[-1].tv_opaque).len + (yyvsp[0].tv_opaque).len;
		char *p = malloc(newsize + 1);
		checkmem(p);
		memcpy(p         , (yyvsp[-1].tv_opaque).buf, (yyvsp[-1].tv_opaque).len);
		memcpy(p + (yyvsp[-1].tv_opaque).len, (yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len);
		p[newsize] = '\0';
		free((yyvsp[-1].tv_opaque).buf);
		free((yyvsp[0].tv_opaque).buf);
		(yyval.tv_opaque).buf = p;
		(yyval.tv_opaque).len = newsize;
	}
#line 3722 "asn1p_y.c"
    break;

  case 178: /* OpaqueFirstToken: Identifier  */
#line 1726 "asn1p_y.y"
                 {
        (yyval.tv_opaque).len = strlen((yyvsp[0].tv_str));
        (yyval.tv_opaque).buf = (yyvsp[0].tv_str);
    }
#line 3731 "asn1p_y.c"
    break;

  case 179: /* BasicTypeId: TOK_BOOLEAN  */
#line 1732 "asn1p_y.y"
                    { (yyval.a_type) = ASN_BASIC_BOOLEAN; }
#line 3737 "asn1p_y.c"
    break;

  case 180: /* BasicTypeId: TOK_NULL  */
#line 1733 "asn1p_y.y"
                   { (yyval.a_type) = ASN_BASIC_NULL; }
#line 3743 "asn1p_y.c"
    break;

  case 181: /* BasicTypeId: TOK_REAL  */
#line 1734 "asn1p_y.y"
                   { (yyval.a_type) = ASN_BASIC_REAL; }
#line 3749 "asn1p_y.c"
    break;

  case 182: /* BasicTypeId: TOK_OCTET TOK_STRING  */
#line 1735 "asn1p_y.y"
                               { (yyval.a_type) = ASN_BASIC_OCTET_STRING; }
#line 3755 "asn1p_y.c"
    break;

  case 183: /* BasicTypeId: TOK_OBJECT TOK_IDENTIFIER  */
#line 1736 "asn1p_y.y"
                                    { (yyval.a_type) = ASN_BASIC_OBJECT_IDENTIFIER; }
#line 3761 "asn1p_y.c"
    break;

  case 184: /* BasicTypeId: TOK_RELATIVE_OID  */
#line 1737 "asn1p_y.y"
                           { (yyval.a_type) = ASN_BASIC_RELATIVE_OID; }
#line 3767 "asn1p_y.c"
    break;

  case 185: /* BasicTypeId: TOK_EXTERNAL  */
#line 1738 "asn1p_y.y"
                       { (yyval.a_type) = ASN_BASIC_EXTERNAL; }
#line 3773 "asn1p_y.c"
    break;

  case 186: /* BasicTypeId: TOK_EMBEDDED TOK_PDV  */
#line 1739 "asn1p_y.y"
                               { (yyval.a_type) = ASN_BASIC_EMBEDDED_PDV; }
#line 3779 "asn1p_y.c"
    break;

  case 187: /* BasicTypeId: TOK_CHARACTER TOK_STRING  */
#line 1740 "asn1p_y.y"
                                   { (yyval.a_type) = ASN_BASIC_CHARACTER_STRING; }
#line 3785 "asn1p_y.c"
    break;

  case 188: /* BasicTypeId: TOK_UTCTime  */
#line 1741 "asn1p_y.y"
                      { (yyval.a_type) = ASN_BASIC_UTCTime; }
#line 3791 "asn1p_y.c"
    break;

  case 189: /* BasicTypeId: TOK_GeneralizedTime  */
#line 1742 "asn1p_y.y"
                              { (yyval.a_type) = ASN_BASIC_GeneralizedTime; }
#line 3797 "asn1p_y.c"
    break;

  case 192: /* BasicTypeId_UniverationCompatible: TOK_INTEGER  */
#line 1751 "asn1p_y.y"
                    { (yyval.a_type) = ASN_BASIC_INTEGER; }
#line 3803 "asn1p_y.c"
    break;

  case 193: /* BasicTypeId_UniverationCompatible: TOK_ENUMERATED  */
#line 1752 "asn1p_y.y"
                         { (yyval.a_type) = ASN_BASIC_ENUMERATED; }
#line 3809 "asn1p_y.c"
    break;

  case 194: /* BasicTypeId_UniverationCompatible: TOK_BIT TOK_STRING  */
#line 1753 "asn1p_y.y"
                             { (yyval.a_type) = ASN_BASIC_BIT_STRING; }
#line 3815 "asn1p_y.c"
    break;

  case 195: /* BuiltinType: BasicTypeId  */
#line 1757 "asn1p_y.y"
                    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = (yyvsp[0].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3826 "asn1p_y.c"
    break;

  case 196: /* BuiltinType: TOK_INTEGER '{' NamedNumberList '}'  */
#line 1763 "asn1p_y.y"
                                          {
        (yyval.a_expr) = (yyvsp[-1].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_INTEGER;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3836 "asn1p_y.c"
    break;

  case 197: /* BuiltinType: TOK_ENUMERATED '{' Enumerations '}'  */
#line 1768 "asn1p_y.y"
                                          {
        (yyval.a_expr) = (yyvsp[-1].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_ENUMERATED;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3846 "asn1p_y.c"
    break;

  case 198: /* BuiltinType: TOK_BIT TOK_STRING '{' NamedBitList '}'  */
#line 1773 "asn1p_y.y"
                                              {
        (yyval.a_expr) = (yyvsp[-1].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3856 "asn1p_y.c"
    break;

  case 199: /* BuiltinType: TOK_ExtValue_BIT_STRING '{' IdentifierList '}'  */
#line 1778 "asn1p_y.y"
                                                     {
        (yyval.a_expr) = (yyvsp[-1].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3866 "asn1p_y.c"
    break;

  case 200: /* BuiltinType: TOK_ExtValue_BIT_STRING '{' '}'  */
#line 1783 "asn1p_y.y"
                                      {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3877 "asn1p_y.c"
    break;

  case 201: /* BasicString: TOK_BMPString  */
#line 1792 "asn1p_y.y"
                      { (yyval.a_type) = ASN_STRING_BMPString; }
#line 3883 "asn1p_y.c"
    break;

  case 202: /* BasicString: TOK_GeneralString  */
#line 1793 "asn1p_y.y"
                            {
		(yyval.a_type) = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
#line 3892 "asn1p_y.c"
    break;

  case 203: /* BasicString: TOK_GraphicString  */
#line 1797 "asn1p_y.y"
                            {
		(yyval.a_type) = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
#line 3901 "asn1p_y.c"
    break;

  case 204: /* BasicString: TOK_IA5String  */
#line 1801 "asn1p_y.y"
                        { (yyval.a_type) = ASN_STRING_IA5String; }
#line 3907 "asn1p_y.c"
    break;

  case 205: /* BasicString: TOK_ISO646String  */
#line 1802 "asn1p_y.y"
                           { (yyval.a_type) = ASN_STRING_ISO646String; }
#line 3913 "asn1p_y.c"
    break;

  case 206: /* BasicString: TOK_NumericString  */
#line 1803 "asn1p_y.y"
                            { (yyval.a_type) = ASN_STRING_NumericString; }
#line 3919 "asn1p_y.c"
    break;

  case 207: /* BasicString: TOK_PrintableString  */
#line 1804 "asn1p_y.y"
                              { (yyval.a_type) = ASN_STRING_PrintableString; }
#line 3925 "asn1p_y.c"
    break;

  case 208: /* BasicString: TOK_T61String  */
#line 1805 "asn1p_y.y"
                        {
		(yyval.a_type) = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
#line 3934 "asn1p_y.c"
    break;

  case 209: /* BasicString: TOK_TeletexString  */
#line 1809 "asn1p_y.y"
                            { (yyval.a_type) = ASN_STRING_TeletexString; }
#line 3940 "asn1p_y.c"
    break;

  case 210: /* BasicString: TOK_UniversalString  */
#line 1810 "asn1p_y.y"
                              { (yyval.a_type) = ASN_STRING_UniversalString; }
#line 3946 "asn1p_y.c"
    break;

  case 211: /* BasicString: TOK_UTF8String  */
#line 1811 "asn1p_y.y"
                         { (yyval.a_type) = ASN_STRING_UTF8String; }
#line 3952 "asn1p_y.c"
    break;

  case 212: /* BasicString: TOK_VideotexString  */
#line 1812 "asn1p_y.y"
                             {
		(yyval.a_type) = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
#line 3961 "asn1p_y.c"
    break;

  case 213: /* BasicString: TOK_VisibleString  */
#line 1816 "asn1p_y.y"
                            { (yyval.a_type) = ASN_STRING_VisibleString; }
#line 3967 "asn1p_y.c"
    break;

  case 214: /* BasicString: TOK_ObjectDescriptor  */
#line 1817 "asn1p_y.y"
                               { (yyval.a_type) = ASN_STRING_ObjectDescriptor; }
#line 3973 "asn1p_y.c"
    break;

  case 219: /* optConstraint: %empty  */
#line 1829 "asn1p_y.y"
        { (yyval.a_constr) = 0; }
#line 3979 "asn1p_y.c"
    break;

  case 221: /* optManyConstraints: %empty  */
#line 1834 "asn1p_y.y"
        { (yyval.a_constr) = 0; }
#line 3985 "asn1p_y.c"
    break;

  case 223: /* optSizeOrConstraint: %empty  */
#line 1839 "asn1p_y.y"
        { (yyval.a_constr) = 0; }
#line 3991 "asn1p_y.c"
    break;

  case 226: /* Constraint: '(' ConstraintSpec ')'  */
#line 1845 "asn1p_y.y"
                           {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[-1].a_constr), 0);
    }
#line 3999 "asn1p_y.c"
    break;

  case 228: /* ManyConstraints: ManyConstraints Constraint  */
#line 1852 "asn1p_y.y"
                                     {
        if((yyvsp[0].a_constr)->type == ACT_CA_SET && (yyvsp[0].a_constr)->el_count == 1) {
            CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[-1].a_constr), (yyvsp[0].a_constr)->elements[0]);
        } else {
            CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[-1].a_constr), (yyvsp[0].a_constr));
        }
	}
#line 4011 "asn1p_y.c"
    break;

  case 232: /* ElementSetSpecs: "..."  */
#line 1866 "asn1p_y.y"
                       {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_EL_EXT;
	}
#line 4020 "asn1p_y.c"
    break;

  case 234: /* ElementSetSpecs: ElementSetSpec ',' "..."  */
#line 1871 "asn1p_y.y"
                                      {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[-2].a_constr), ct);
   }
#line 4031 "asn1p_y.c"
    break;

  case 235: /* ElementSetSpecs: ElementSetSpec ',' "..." ',' ElementSetSpec  */
#line 1877 "asn1p_y.y"
                                                         {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[-4].a_constr), ct);
       ct = (yyval.a_constr);
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, ct, (yyvsp[0].a_constr));
   }
#line 4044 "asn1p_y.c"
    break;

  case 237: /* ElementSetSpec: TOK_ALL TOK_EXCEPT Elements  */
#line 1889 "asn1p_y.y"
                                      {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_AEX, (yyvsp[0].a_constr), 0);
	}
#line 4052 "asn1p_y.c"
    break;

  case 239: /* Unions: Unions UnionMark Intersections  */
#line 1896 "asn1p_y.y"
                                         {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_UNI, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
#line 4060 "asn1p_y.c"
    break;

  case 241: /* Intersections: Intersections IntersectionMark IntersectionElements  */
#line 1903 "asn1p_y.y"
                                                               {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_INT, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
#line 4068 "asn1p_y.c"
    break;

  case 243: /* IntersectionElements: Elements TOK_EXCEPT Elements  */
#line 1911 "asn1p_y.y"
                                       {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_EXC, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
#line 4076 "asn1p_y.c"
    break;

  case 245: /* Elements: '(' ElementSetSpec ')'  */
#line 1918 "asn1p_y.y"
                             {
        int ret;
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_CA_SET;
        ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[-1].a_constr));
        checkmem(ret == 0);
    }
#line 4089 "asn1p_y.c"
    break;

  case 246: /* SubtypeElements: SingleValue  */
#line 1929 "asn1p_y.y"
                    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = (yyvsp[0].a_value);
	}
#line 4100 "asn1p_y.c"
    break;

  case 247: /* SubtypeElements: ContainedSubtype  */
#line 1935 "asn1p_y.y"
                           {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_TYPE;
		(yyval.a_constr)->containedSubtype = (yyvsp[0].a_value);
	}
#line 4111 "asn1p_y.c"
    break;

  case 253: /* PermittedAlphabet: TOK_FROM Constraint  */
#line 1951 "asn1p_y.y"
                            {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_FROM, (yyvsp[0].a_constr), 0);
	}
#line 4119 "asn1p_y.c"
    break;

  case 254: /* SizeConstraint: TOK_SIZE Constraint  */
#line 1956 "asn1p_y.y"
                            {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_SIZE, (yyvsp[0].a_constr), 0);
	}
#line 4127 "asn1p_y.c"
    break;

  case 255: /* PatternConstraint: TOK_PATTERN TOK_cstring  */
#line 1961 "asn1p_y.y"
                                {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
	}
#line 4137 "asn1p_y.c"
    break;

  case 256: /* PatternConstraint: TOK_PATTERN Identifier  */
#line 1966 "asn1p_y.y"
                                 {
		asn1p_ref_t *ref;
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		ref = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component(ref, (yyvsp[0].tv_str), RLT_lowercase);
		(yyval.a_constr)->value = asn1p_value_fromref(ref, 0);
		free((yyvsp[0].tv_str));
	}
#line 4151 "asn1p_y.c"
    break;

  case 257: /* ValueRange: LowerEndValue ConstraintRangeSpec UpperEndValue  */
#line 1978 "asn1p_y.y"
                                                    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[-1].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[-2].a_value);
		(yyval.a_constr)->range_stop = (yyvsp[0].a_value);
    }
#line 4163 "asn1p_y.c"
    break;

  case 259: /* LowerEndValue: TOK_MIN  */
#line 1988 "asn1p_y.y"
              {
		(yyval.a_value) = asn1p_value_fromint(-123);
		(yyval.a_value)->type = ATV_MIN;
    }
#line 4172 "asn1p_y.c"
    break;

  case 261: /* UpperEndValue: TOK_MAX  */
#line 1995 "asn1p_y.y"
              {
		(yyval.a_value) = asn1p_value_fromint(321);
		(yyval.a_value)->type = ATV_MAX;
    }
#line 4181 "asn1p_y.c"
    break;

  case 263: /* BitStringValue: TOK_bstring  */
#line 2003 "asn1p_y.y"
                    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[0].tv_str), 'B');
		checkmem((yyval.a_value));
		free((yyvsp[0].tv_str));
	}
#line 4191 "asn1p_y.c"
    break;

  case 264: /* BitStringValue: TOK_hstring  */
#line 2008 "asn1p_y.y"
                      {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[0].tv_str), 'H');
		checkmem((yyval.a_value));
		free((yyvsp[0].tv_str));
	}
#line 4201 "asn1p_y.c"
    break;

  case 265: /* ContainedSubtype: TOK_INCLUDES Type  */
#line 2016 "asn1p_y.y"
                      {
		(yyval.a_value) = asn1p_value_fromtype((yyvsp[0].a_expr));
		checkmem((yyval.a_value));
		asn1p_expr_free((yyvsp[0].a_expr));
    }
#line 4211 "asn1p_y.c"
    break;

  case 266: /* ContainedSubtype: DefinedUntaggedType  */
#line 2022 "asn1p_y.y"
                          {
		(yyval.a_value) = asn1p_value_fromtype((yyvsp[0].a_expr));
		checkmem((yyval.a_value));
		asn1p_expr_free((yyvsp[0].a_expr));
    }
#line 4221 "asn1p_y.c"
    break;

  case 267: /* InnerTypeConstraints: TOK_WITH TOK_COMPONENT SingleTypeConstraint  */
#line 2034 "asn1p_y.y"
                                                    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMP, (yyvsp[0].a_constr), 0);
	}
#line 4229 "asn1p_y.c"
    break;

  case 268: /* InnerTypeConstraints: TOK_WITH TOK_COMPONENTS MultipleTypeConstraints  */
#line 2037 "asn1p_y.y"
                                                          {
        assert((yyvsp[0].a_constr)->type == ACT_CA_CSV);
        (yyvsp[0].a_constr)->type = ACT_CT_WCOMPS;
        (yyval.a_constr) = (yyvsp[0].a_constr);
	}
#line 4239 "asn1p_y.c"
    break;

  case 272: /* FullSpecification: '{' TypeConstraints '}'  */
#line 2045 "asn1p_y.y"
                                           { (yyval.a_constr) = (yyvsp[-1].a_constr); }
#line 4245 "asn1p_y.c"
    break;

  case 273: /* PartialSpecification: '{' "..." ',' TypeConstraints '}'  */
#line 2047 "asn1p_y.y"
                                              {
        assert((yyvsp[-1].a_constr)->type == ACT_CA_CSV);
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        (yyval.a_constr)->type = ACT_CA_CSV;
		asn1p_constraint_t *ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		ct->type = ACT_EL_EXT;
        asn1p_constraint_insert((yyval.a_constr), ct);
        for(unsigned i = 0; i < (yyvsp[-1].a_constr)->el_count; i++) {
            asn1p_constraint_insert((yyval.a_constr), (yyvsp[-1].a_constr)->elements[i]);
        }
    }
#line 4262 "asn1p_y.c"
    break;

  case 274: /* TypeConstraints: NamedConstraint  */
#line 2060 "asn1p_y.y"
                    {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        (yyval.a_constr)->type = ACT_CA_CSV;
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[0].a_constr));
    }
#line 4272 "asn1p_y.c"
    break;

  case 275: /* TypeConstraints: TypeConstraints ',' NamedConstraint  */
#line 2065 "asn1p_y.y"
                                          {
        (yyval.a_constr) = (yyvsp[-2].a_constr);
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[0].a_constr));
	}
#line 4281 "asn1p_y.c"
    break;

  case 276: /* NamedConstraint: IdentifierAsValue optConstraint optPresenceConstraint  */
#line 2071 "asn1p_y.y"
                                                              {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_EL_VALUE;
        (yyval.a_constr)->value = (yyvsp[-2].a_value);
        if((yyvsp[-1].a_constr)) asn1p_constraint_insert((yyval.a_constr), (yyvsp[-1].a_constr));
        (yyval.a_constr)->presence = (yyvsp[0].a_pres);
    }
#line 4294 "asn1p_y.c"
    break;

  case 277: /* optPresenceConstraint: %empty  */
#line 2085 "asn1p_y.y"
        { (yyval.a_pres) = ACPRES_DEFAULT; }
#line 4300 "asn1p_y.c"
    break;

  case 278: /* optPresenceConstraint: PresenceConstraint  */
#line 2086 "asn1p_y.y"
                             { (yyval.a_pres) = (yyvsp[0].a_pres); }
#line 4306 "asn1p_y.c"
    break;

  case 279: /* PresenceConstraint: TOK_PRESENT  */
#line 2090 "asn1p_y.y"
                    {
		(yyval.a_pres) = ACPRES_PRESENT;
	}
#line 4314 "asn1p_y.c"
    break;

  case 280: /* PresenceConstraint: TOK_ABSENT  */
#line 2093 "asn1p_y.y"
                     {
		(yyval.a_pres) = ACPRES_ABSENT;
	}
#line 4322 "asn1p_y.c"
    break;

  case 281: /* PresenceConstraint: TOK_OPTIONAL  */
#line 2096 "asn1p_y.y"
                       {
		(yyval.a_pres) = ACPRES_OPTIONAL;
	}
#line 4330 "asn1p_y.c"
    break;

  case 285: /* $@6: %empty  */
#line 2111 "asn1p_y.y"
                { asn1p_lexer_hack_push_opaque_state(); }
#line 4336 "asn1p_y.c"
    break;

  case 286: /* UserDefinedConstraint: TOK_CONSTRAINED TOK_BY '{' $@6 Opaque  */
#line 2111 "asn1p_y.y"
                                                                           {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CT_CTDBY;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem((yyval.a_constr)->value);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
#line 4349 "asn1p_y.c"
    break;

  case 287: /* ContentsConstraint: TOK_CONTAINING Type  */
#line 2122 "asn1p_y.y"
                            {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_CTNG;
		(yyval.a_constr)->value = asn1p_value_fromtype((yyvsp[0].a_expr));
		asn1p_expr_free((yyvsp[0].a_expr));
	}
#line 4360 "asn1p_y.c"
    break;

  case 288: /* ConstraintRangeSpec: ".."  */
#line 2131 "asn1p_y.y"
                                { (yyval.a_ctype) = ACT_EL_RANGE; }
#line 4366 "asn1p_y.c"
    break;

  case 289: /* ConstraintRangeSpec: ".." '<'  */
#line 2132 "asn1p_y.y"
                                { (yyval.a_ctype) = ACT_EL_RLRANGE; }
#line 4372 "asn1p_y.c"
    break;

  case 290: /* ConstraintRangeSpec: '<' ".."  */
#line 2133 "asn1p_y.y"
                                { (yyval.a_ctype) = ACT_EL_LLRANGE; }
#line 4378 "asn1p_y.c"
    break;

  case 291: /* ConstraintRangeSpec: '<' ".." '<'  */
#line 2134 "asn1p_y.y"
                                { (yyval.a_ctype) = ACT_EL_ULRANGE; }
#line 4384 "asn1p_y.c"
    break;

  case 292: /* TableConstraint: SimpleTableConstraint  */
#line 2137 "asn1p_y.y"
                              {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
#line 4392 "asn1p_y.c"
    break;

  case 293: /* TableConstraint: ComponentRelationConstraint  */
#line 2140 "asn1p_y.y"
                                      {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
#line 4400 "asn1p_y.c"
    break;

  case 294: /* SimpleTableConstraint: '{' TypeRefName '}'  */
#line 2149 "asn1p_y.y"
                            {
		asn1p_ref_t *ref = asn1p_ref_new(yylineno, currentModule);
		asn1p_constraint_t *ct;
		int ret;
		ret = asn1p_ref_add_component(ref, (yyvsp[-1].tv_str), 0);
		checkmem(ret == 0);
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(ref, 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, ct, 0);
		free((yyvsp[-1].tv_str));
	}
#line 4418 "asn1p_y.c"
    break;

  case 295: /* ComponentRelationConstraint: SimpleTableConstraint '{' AtNotationList '}'  */
#line 2165 "asn1p_y.y"
                                                     {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, (yyvsp[-3].a_constr), (yyvsp[-1].a_constr));
	}
#line 4426 "asn1p_y.c"
    break;

  case 296: /* AtNotationList: AtNotationElement  */
#line 2171 "asn1p_y.y"
                          {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_fromref((yyvsp[0].a_ref), 0);
	}
#line 4437 "asn1p_y.c"
    break;

  case 297: /* AtNotationList: AtNotationList ',' AtNotationElement  */
#line 2177 "asn1p_y.y"
                                               {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref((yyvsp[0].a_ref), 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[-2].a_constr), ct);
	}
#line 4450 "asn1p_y.c"
    break;

  case 298: /* AtNotationElement: '@' ComponentIdList  */
#line 2191 "asn1p_y.y"
                            {
		char *p = malloc(strlen((yyvsp[0].tv_str)) + 2);
		int ret;
		*p = '@';
		strcpy(p + 1, (yyvsp[0].tv_str));
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_ref), p, 0);
		checkmem(ret == 0);
		free(p);
		free((yyvsp[0].tv_str));
	}
#line 4466 "asn1p_y.c"
    break;

  case 299: /* AtNotationElement: '@' '.' ComponentIdList  */
#line 2202 "asn1p_y.y"
                                  {
		char *p = malloc(strlen((yyvsp[0].tv_str)) + 3);
		int ret;
		p[0] = '@';
		p[1] = '.';
		strcpy(p + 2, (yyvsp[0].tv_str));
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_ref), p, 0);
		checkmem(ret == 0);
		free(p);
		free((yyvsp[0].tv_str));
	}
#line 4483 "asn1p_y.c"
    break;

  case 300: /* ComponentIdList: Identifier  */
#line 2218 "asn1p_y.y"
                   {
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4491 "asn1p_y.c"
    break;

  case 301: /* ComponentIdList: ComponentIdList '.' Identifier  */
#line 2221 "asn1p_y.y"
                                         {
		int l1 = strlen((yyvsp[-2].tv_str));
		int l3 = strlen((yyvsp[0].tv_str));
		(yyval.tv_str) = malloc(l1 + 1 + l3 + 1);
		memcpy((yyval.tv_str), (yyvsp[-2].tv_str), l1);
		(yyval.tv_str)[l1] = '.';
		memcpy((yyval.tv_str) + l1 + 1, (yyvsp[0].tv_str), l3);
		(yyval.tv_str)[l1 + 1 + l3] = '\0';
		free((yyvsp[-2].tv_str));
		free((yyvsp[0].tv_str));
	}
#line 4507 "asn1p_y.c"
    break;

  case 302: /* optMarker: %empty  */
#line 2241 "asn1p_y.y"
        {
		(yyval.a_marker).flags = EM_NOMARK;
		(yyval.a_marker).default_value = 0;
	}
#line 4516 "asn1p_y.c"
    break;

  case 303: /* optMarker: Marker  */
#line 2245 "asn1p_y.y"
                 { (yyval.a_marker) = (yyvsp[0].a_marker); }
#line 4522 "asn1p_y.c"
    break;

  case 304: /* Marker: TOK_OPTIONAL  */
#line 2249 "asn1p_y.y"
                     {
		(yyval.a_marker).flags = EM_OPTIONAL | EM_INDIRECT;
		(yyval.a_marker).default_value = 0;
	}
#line 4531 "asn1p_y.c"
    break;

  case 305: /* Marker: TOK_DEFAULT Value  */
#line 2253 "asn1p_y.y"
                            {
		(yyval.a_marker).flags = EM_DEFAULT;
		(yyval.a_marker).default_value = (yyvsp[0].a_value);
	}
#line 4540 "asn1p_y.c"
    break;

  case 306: /* IdentifierList: IdentifierElement  */
#line 2260 "asn1p_y.y"
                      {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
    }
#line 4550 "asn1p_y.c"
    break;

  case 307: /* IdentifierList: IdentifierList ',' IdentifierElement  */
#line 2265 "asn1p_y.y"
                                           {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
    }
#line 4559 "asn1p_y.c"
    break;

  case 308: /* IdentifierElement: Identifier  */
#line 2271 "asn1p_y.y"
               {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
    }
#line 4571 "asn1p_y.c"
    break;

  case 309: /* NamedNumberList: NamedNumber  */
#line 2280 "asn1p_y.y"
                    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4581 "asn1p_y.c"
    break;

  case 310: /* NamedNumberList: NamedNumberList ',' NamedNumber  */
#line 2285 "asn1p_y.y"
                                          {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4590 "asn1p_y.c"
    break;

  case 311: /* NamedNumber: Identifier '(' SignedNumber ')'  */
#line 2292 "asn1p_y.y"
                                        {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4603 "asn1p_y.c"
    break;

  case 312: /* NamedNumber: Identifier '(' DefinedValue ')'  */
#line 2300 "asn1p_y.y"
                                          {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4616 "asn1p_y.c"
    break;

  case 313: /* NamedBitList: NamedBit  */
#line 2310 "asn1p_y.y"
                 {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4626 "asn1p_y.c"
    break;

  case 314: /* NamedBitList: NamedBitList ',' NamedBit  */
#line 2315 "asn1p_y.y"
                                    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4635 "asn1p_y.c"
    break;

  case 315: /* NamedBit: Identifier '(' "number" ')'  */
#line 2322 "asn1p_y.y"
                                      {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = asn1p_value_fromint((yyvsp[-1].a_int));
	}
#line 4648 "asn1p_y.c"
    break;

  case 316: /* NamedBit: Identifier '(' DefinedValue ')'  */
#line 2330 "asn1p_y.y"
                                          {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4661 "asn1p_y.c"
    break;

  case 317: /* Enumerations: UniverationList  */
#line 2340 "asn1p_y.y"
                    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
        asn1p_expr_t *first_memb = TQ_FIRST(&((yyval.a_expr)->members));
        if(first_memb) {
            if(first_memb->expr_type == A1TC_EXTENSIBLE) {
                return yyerror(param,
                    "The ENUMERATION cannot start with extension (...).");
            }
        } else {
            return yyerror(param,
                "The ENUMERATION list cannot be empty.");
        }
    }
#line 4679 "asn1p_y.c"
    break;

  case 318: /* UniverationList: UniverationElement  */
#line 2355 "asn1p_y.y"
                           {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4689 "asn1p_y.c"
    break;

  case 319: /* UniverationList: UniverationList ',' UniverationElement  */
#line 2360 "asn1p_y.y"
                                                 {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4698 "asn1p_y.c"
    break;

  case 320: /* UniverationElement: Identifier  */
#line 2367 "asn1p_y.y"
                   {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
	}
#line 4710 "asn1p_y.c"
    break;

  case 321: /* UniverationElement: Identifier '(' SignedNumber ')'  */
#line 2374 "asn1p_y.y"
                                          {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4723 "asn1p_y.c"
    break;

  case 322: /* UniverationElement: Identifier '(' DefinedValue ')'  */
#line 2382 "asn1p_y.y"
                                          {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4736 "asn1p_y.c"
    break;

  case 323: /* UniverationElement: SignedNumber  */
#line 2390 "asn1p_y.y"
                       {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
#line 4748 "asn1p_y.c"
    break;

  case 324: /* UniverationElement: "..."  */
#line 2397 "asn1p_y.y"
                        {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
	}
#line 4761 "asn1p_y.c"
    break;

  case 325: /* SignedNumber: "number"  */
#line 2408 "asn1p_y.y"
                   {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
	}
#line 4770 "asn1p_y.c"
    break;

  case 326: /* SignedNumber: "negative number"  */
#line 2412 "asn1p_y.y"
                              {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
	}
#line 4779 "asn1p_y.c"
    break;

  case 327: /* RealValue: TOK_realnumber  */
#line 2419 "asn1p_y.y"
                       {
		(yyval.a_value) = asn1p_value_fromdouble((yyvsp[0].a_dbl));
		checkmem((yyval.a_value));
	}
#line 4788 "asn1p_y.c"
    break;

  case 328: /* optTag: %empty  */
#line 2450 "asn1p_y.y"
        { memset(&(yyval.a_tag), 0, sizeof((yyval.a_tag))); }
#line 4794 "asn1p_y.c"
    break;

  case 329: /* optTag: Tag  */
#line 2451 "asn1p_y.y"
              { (yyval.a_tag) = (yyvsp[0].a_tag); }
#line 4800 "asn1p_y.c"
    break;

  case 330: /* Tag: TagTypeValue TagPlicit  */
#line 2455 "asn1p_y.y"
                               {
		(yyval.a_tag) = (yyvsp[-1].a_tag);
		(yyval.a_tag).tag_mode = (yyvsp[0].a_tag).tag_mode;
	}
#line 4809 "asn1p_y.c"
    break;

  case 331: /* TagTypeValue: '[' TagClass "number" ']'  */
#line 2462 "asn1p_y.y"
                                    {
		(yyval.a_tag) = (yyvsp[-2].a_tag);
		(yyval.a_tag).tag_value = (yyvsp[-1].a_int);
	}
#line 4818 "asn1p_y.c"
    break;

  case 332: /* TagClass: %empty  */
#line 2468 "asn1p_y.y"
        { (yyval.a_tag).tag_class = TC_CONTEXT_SPECIFIC; }
#line 4824 "asn1p_y.c"
    break;

  case 333: /* TagClass: TOK_UNIVERSAL  */
#line 2469 "asn1p_y.y"
                        { (yyval.a_tag).tag_class = TC_UNIVERSAL; }
#line 4830 "asn1p_y.c"
    break;

  case 334: /* TagClass: TOK_APPLICATION  */
#line 2470 "asn1p_y.y"
                          { (yyval.a_tag).tag_class = TC_APPLICATION; }
#line 4836 "asn1p_y.c"
    break;

  case 335: /* TagClass: TOK_PRIVATE  */
#line 2471 "asn1p_y.y"
                      { (yyval.a_tag).tag_class = TC_PRIVATE; }
#line 4842 "asn1p_y.c"
    break;

  case 336: /* TagPlicit: %empty  */
#line 2475 "asn1p_y.y"
        { (yyval.a_tag).tag_mode = TM_DEFAULT; }
#line 4848 "asn1p_y.c"
    break;

  case 337: /* TagPlicit: TOK_IMPLICIT  */
#line 2476 "asn1p_y.y"
                       { (yyval.a_tag).tag_mode = TM_IMPLICIT; }
#line 4854 "asn1p_y.c"
    break;

  case 338: /* TagPlicit: TOK_EXPLICIT  */
#line 2477 "asn1p_y.y"
                       { (yyval.a_tag).tag_mode = TM_EXPLICIT; }
#line 4860 "asn1p_y.c"
    break;

  case 339: /* TypeRefName: TOK_typereference  */
#line 2481 "asn1p_y.y"
                          {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4869 "asn1p_y.c"
    break;

  case 340: /* TypeRefName: TOK_capitalreference  */
#line 2485 "asn1p_y.y"
                               {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4878 "asn1p_y.c"
    break;

  case 341: /* optIdentifier: %empty  */
#line 2493 "asn1p_y.y"
        { (yyval.tv_str) = 0; }
#line 4884 "asn1p_y.c"
    break;

  case 342: /* optIdentifier: Identifier  */
#line 2494 "asn1p_y.y"
                     {
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4892 "asn1p_y.c"
    break;

  case 343: /* Identifier: "identifier"  */
#line 2500 "asn1p_y.y"
                       {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4901 "asn1p_y.c"
    break;

  case 344: /* IdentifierAsReference: Identifier  */
#line 2507 "asn1p_y.y"
               {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_lowercase);
		free((yyvsp[0].tv_str));
    }
#line 4911 "asn1p_y.c"
    break;

  case 345: /* IdentifierAsValue: IdentifierAsReference  */
#line 2514 "asn1p_y.y"
                          {
		(yyval.a_value) = asn1p_value_fromref((yyvsp[0].a_ref), 0);
    }
#line 4919 "asn1p_y.c"
    break;


#line 4923 "asn1p_y.c"

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
      yyerror (param, YY_("syntax error"));
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
                      yytoken, &yylval, param);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, param);
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
  yyerror (param, YY_("memory exhausted"));
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
                  yytoken, &yylval, param);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, param);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2518 "asn1p_y.y"



/*
 * Convert Xstring ('0101'B or '5'H) to the binary vector.
 */
static asn1p_value_t *
_convert_bitstring2binary(char *str, int base) {
	asn1p_value_t *val;
	int slen;
	int memlen;
	int baselen;
	int bits;
	uint8_t *binary_vector;
	uint8_t *bv_ptr;
	uint8_t cur_val;

	assert(str);
	assert(str[0] == '\'');

	switch(base) {
	case 'B':
		baselen = 1;
		break;
	case 'H':
		baselen = 4;
		break;
	default:
		assert(base == 'B' || base == 'H');
		errno = EINVAL;
		return NULL;
	}

	slen = strlen(str);
	assert(str[slen - 1] == base);
	assert(str[slen - 2] == '\'');

	memlen = slen / (8 / baselen);	/* Conservative estimate */

	bv_ptr = binary_vector = malloc(memlen + 1);
	if(bv_ptr == NULL)
		/* ENOMEM */
		return NULL;

	cur_val = 0;
	bits = 0;
	while(*(++str) != '\'') {
		switch(baselen) {
		case 1:
			switch(*str) {
			case '1':
				cur_val |= 1 << (7 - (bits % 8));
			case '0':
				break;
			default:
				assert(!"_y UNREACH1");
			case ' ': case '\r': case '\n':
				continue;
			}
			break;
		case 4:
			switch(*str) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				cur_val |= (*str - '0') << (4 - (bits % 8));
				break;
			case 'A': case 'B': case 'C':
			case 'D': case 'E': case 'F':
				cur_val |= ((*str - 'A') + 10)
					<< (4 - (bits % 8));
				break;
			default:
				assert(!"_y UNREACH2");
			case ' ': case '\r': case '\n':
				continue;
			}
			break;
		}

		bits += baselen;
		if((bits % 8) == 0) {
			*bv_ptr++ = cur_val;
			cur_val = 0;
		}
	}

	*bv_ptr = cur_val;
	assert((bv_ptr - binary_vector) <= memlen);

	val = asn1p_value_frombits(binary_vector, bits, 0);
	if(val == NULL) {
		free(binary_vector);
	}

	return val;
}

/*
 * For unnamed types (used in old X.208 compliant modules)
 * generate some sort of interim names, to not to force human being to fix
 * the specification's compliance to modern ASN.1 standards.
 */
static void
_fixup_anonymous_identifier(asn1p_expr_t *expr) {
	char *p;
	assert(expr->Identifier == 0);

	/*
	 * Try to figure out the type name
	 * without going too much into details
	 */
	expr->Identifier = ASN_EXPR_TYPE2STR(expr->expr_type);
	if(expr->reference && expr->reference->comp_count > 0)
		expr->Identifier = expr->reference->components[0].name;

	fprintf(stderr,
		"WARNING: Line %d: expected lower-case member identifier, "
		"found an unnamed %s.\n"
		"WARNING: Obsolete X.208 syntax detected, "
		"please give the member a name.\n",
		yylineno, expr->Identifier ? expr->Identifier : "type");

	if(!expr->Identifier)
		expr->Identifier = "unnamed";
	expr->Identifier = strdup(expr->Identifier);
	assert(expr->Identifier);
	/* Make a lowercase identifier from the type name */
	for(p = expr->Identifier; *p; p++) {
		switch(*p) {
		case 'A' ... 'Z': *p += 32; break;
		case ' ': *p = '_'; break;
		case '-': *p = '_'; break;
		}
	}
	fprintf(stderr, "NOTE: Assigning temporary identifier \"%s\". "
			"Name clash may occur later.\n",
		expr->Identifier);
}

static int
yyerror(void **param, const char *msg) {
	extern char *asn1p_text;
	(void)param;
	fprintf(stderr,
		"ASN.1 grammar parse error "
		"near %s:%d (token \"%s\"): %s\n",
		ASN_FILENAME, yylineno, asn1p_text, msg);
	return -1;
}

