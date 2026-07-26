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
  YYSYMBOL_optImports = 143,               /* optImports  */
  YYSYMBOL_ImportsDefinition = 144,        /* ImportsDefinition  */
  YYSYMBOL_optImportsBundleSet = 145,      /* optImportsBundleSet  */
  YYSYMBOL_ImportsBundleSet = 146,         /* ImportsBundleSet  */
  YYSYMBOL_AssignedIdentifier = 147,       /* AssignedIdentifier  */
  YYSYMBOL_ImportsBundle = 148,            /* ImportsBundle  */
  YYSYMBOL_ImportsList = 149,              /* ImportsList  */
  YYSYMBOL_ImportsElement = 150,           /* ImportsElement  */
  YYSYMBOL_optExports = 151,               /* optExports  */
  YYSYMBOL_ExportsDefinition = 152,        /* ExportsDefinition  */
  YYSYMBOL_ExportsBody = 153,              /* ExportsBody  */
  YYSYMBOL_ExportsElement = 154,           /* ExportsElement  */
  YYSYMBOL_ValueSet = 155,                 /* ValueSet  */
  YYSYMBOL_ValueSetTypeAssignment = 156,   /* ValueSetTypeAssignment  */
  YYSYMBOL_DefinedType = 157,              /* DefinedType  */
  YYSYMBOL_DataTypeReference = 158,        /* DataTypeReference  */
  YYSYMBOL_ParameterArgumentList = 159,    /* ParameterArgumentList  */
  YYSYMBOL_ParameterArgumentName = 160,    /* ParameterArgumentName  */
  YYSYMBOL_ActualParameterList = 161,      /* ActualParameterList  */
  YYSYMBOL_ActualParameter = 162,          /* ActualParameter  */
  YYSYMBOL_optComponentTypeLists = 163,    /* optComponentTypeLists  */
  YYSYMBOL_ComponentTypeLists = 164,       /* ComponentTypeLists  */
  YYSYMBOL_ComponentType = 165,            /* ComponentType  */
  YYSYMBOL_AlternativeTypeLists = 166,     /* AlternativeTypeLists  */
  YYSYMBOL_AlternativeType = 167,          /* AlternativeType  */
  YYSYMBOL_ObjectClass = 168,              /* ObjectClass  */
  YYSYMBOL_optUNIQUE = 169,                /* optUNIQUE  */
  YYSYMBOL_FieldSpec = 170,                /* FieldSpec  */
  YYSYMBOL_ClassField = 171,               /* ClassField  */
  YYSYMBOL_optWithSyntax = 172,            /* optWithSyntax  */
  YYSYMBOL_WithSyntax = 173,               /* WithSyntax  */
  YYSYMBOL_174_3 = 174,                    /* $@3  */
  YYSYMBOL_WithSyntaxList = 175,           /* WithSyntaxList  */
  YYSYMBOL_WithSyntaxToken = 176,          /* WithSyntaxToken  */
  YYSYMBOL_ExtensionAndException = 177,    /* ExtensionAndException  */
  YYSYMBOL_Type = 178,                     /* Type  */
  YYSYMBOL_TaggedType = 179,               /* TaggedType  */
  YYSYMBOL_DefinedUntaggedType = 180,      /* DefinedUntaggedType  */
  YYSYMBOL_UntaggedType = 181,             /* UntaggedType  */
  YYSYMBOL_MaybeIndirectTaggedType = 182,  /* MaybeIndirectTaggedType  */
  YYSYMBOL_NSTD_IndirectMarker = 183,      /* NSTD_IndirectMarker  */
  YYSYMBOL_MaybeIndirectTypeDeclaration = 184, /* MaybeIndirectTypeDeclaration  */
  YYSYMBOL_TypeDeclaration = 185,          /* TypeDeclaration  */
  YYSYMBOL_ConcreteTypeDeclaration = 186,  /* ConcreteTypeDeclaration  */
  YYSYMBOL_ComplexTypeReference = 187,     /* ComplexTypeReference  */
  YYSYMBOL_ComplexTypeReferenceAmpList = 188, /* ComplexTypeReferenceAmpList  */
  YYSYMBOL_ComplexTypeReferenceElement = 189, /* ComplexTypeReferenceElement  */
  YYSYMBOL_PrimitiveFieldReference = 190,  /* PrimitiveFieldReference  */
  YYSYMBOL_FieldName = 191,                /* FieldName  */
  YYSYMBOL_DefinedObjectClass = 192,       /* DefinedObjectClass  */
  YYSYMBOL_ValueAssignment = 193,          /* ValueAssignment  */
  YYSYMBOL_Value = 194,                    /* Value  */
  YYSYMBOL_195_4 = 195,                    /* $@4  */
  YYSYMBOL_SimpleValue = 196,              /* SimpleValue  */
  YYSYMBOL_DefinedValue = 197,             /* DefinedValue  */
  YYSYMBOL_RestrictedCharacterStringValue = 198, /* RestrictedCharacterStringValue  */
  YYSYMBOL_Opaque = 199,                   /* Opaque  */
  YYSYMBOL_OpaqueFirstToken = 200,         /* OpaqueFirstToken  */
  YYSYMBOL_BasicTypeId = 201,              /* BasicTypeId  */
  YYSYMBOL_BasicTypeId_UniverationCompatible = 202, /* BasicTypeId_UniverationCompatible  */
  YYSYMBOL_BuiltinType = 203,              /* BuiltinType  */
  YYSYMBOL_BasicString = 204,              /* BasicString  */
  YYSYMBOL_UnionMark = 205,                /* UnionMark  */
  YYSYMBOL_IntersectionMark = 206,         /* IntersectionMark  */
  YYSYMBOL_optConstraint = 207,            /* optConstraint  */
  YYSYMBOL_optManyConstraints = 208,       /* optManyConstraints  */
  YYSYMBOL_optSizeOrConstraint = 209,      /* optSizeOrConstraint  */
  YYSYMBOL_Constraint = 210,               /* Constraint  */
  YYSYMBOL_ManyConstraints = 211,          /* ManyConstraints  */
  YYSYMBOL_ConstraintSpec = 212,           /* ConstraintSpec  */
  YYSYMBOL_SubtypeConstraint = 213,        /* SubtypeConstraint  */
  YYSYMBOL_ElementSetSpecs = 214,          /* ElementSetSpecs  */
  YYSYMBOL_ElementSetSpec = 215,           /* ElementSetSpec  */
  YYSYMBOL_Unions = 216,                   /* Unions  */
  YYSYMBOL_Intersections = 217,            /* Intersections  */
  YYSYMBOL_IntersectionElements = 218,     /* IntersectionElements  */
  YYSYMBOL_Elements = 219,                 /* Elements  */
  YYSYMBOL_SubtypeElements = 220,          /* SubtypeElements  */
  YYSYMBOL_PermittedAlphabet = 221,        /* PermittedAlphabet  */
  YYSYMBOL_SizeConstraint = 222,           /* SizeConstraint  */
  YYSYMBOL_PatternConstraint = 223,        /* PatternConstraint  */
  YYSYMBOL_ValueRange = 224,               /* ValueRange  */
  YYSYMBOL_LowerEndValue = 225,            /* LowerEndValue  */
  YYSYMBOL_UpperEndValue = 226,            /* UpperEndValue  */
  YYSYMBOL_SingleValue = 227,              /* SingleValue  */
  YYSYMBOL_BitStringValue = 228,           /* BitStringValue  */
  YYSYMBOL_ContainedSubtype = 229,         /* ContainedSubtype  */
  YYSYMBOL_InnerTypeConstraints = 230,     /* InnerTypeConstraints  */
  YYSYMBOL_SingleTypeConstraint = 231,     /* SingleTypeConstraint  */
  YYSYMBOL_MultipleTypeConstraints = 232,  /* MultipleTypeConstraints  */
  YYSYMBOL_FullSpecification = 233,        /* FullSpecification  */
  YYSYMBOL_PartialSpecification = 234,     /* PartialSpecification  */
  YYSYMBOL_TypeConstraints = 235,          /* TypeConstraints  */
  YYSYMBOL_NamedConstraint = 236,          /* NamedConstraint  */
  YYSYMBOL_optPresenceConstraint = 237,    /* optPresenceConstraint  */
  YYSYMBOL_PresenceConstraint = 238,       /* PresenceConstraint  */
  YYSYMBOL_GeneralConstraint = 239,        /* GeneralConstraint  */
  YYSYMBOL_UserDefinedConstraint = 240,    /* UserDefinedConstraint  */
  YYSYMBOL_241_5 = 241,                    /* $@5  */
  YYSYMBOL_ContentsConstraint = 242,       /* ContentsConstraint  */
  YYSYMBOL_ConstraintRangeSpec = 243,      /* ConstraintRangeSpec  */
  YYSYMBOL_TableConstraint = 244,          /* TableConstraint  */
  YYSYMBOL_SimpleTableConstraint = 245,    /* SimpleTableConstraint  */
  YYSYMBOL_ComponentRelationConstraint = 246, /* ComponentRelationConstraint  */
  YYSYMBOL_AtNotationList = 247,           /* AtNotationList  */
  YYSYMBOL_AtNotationElement = 248,        /* AtNotationElement  */
  YYSYMBOL_ComponentIdList = 249,          /* ComponentIdList  */
  YYSYMBOL_optMarker = 250,                /* optMarker  */
  YYSYMBOL_Marker = 251,                   /* Marker  */
  YYSYMBOL_IdentifierList = 252,           /* IdentifierList  */
  YYSYMBOL_IdentifierElement = 253,        /* IdentifierElement  */
  YYSYMBOL_NamedNumberList = 254,          /* NamedNumberList  */
  YYSYMBOL_NamedNumber = 255,              /* NamedNumber  */
  YYSYMBOL_NamedBitList = 256,             /* NamedBitList  */
  YYSYMBOL_NamedBit = 257,                 /* NamedBit  */
  YYSYMBOL_Enumerations = 258,             /* Enumerations  */
  YYSYMBOL_UniverationList = 259,          /* UniverationList  */
  YYSYMBOL_UniverationElement = 260,       /* UniverationElement  */
  YYSYMBOL_SignedNumber = 261,             /* SignedNumber  */
  YYSYMBOL_RealValue = 262,                /* RealValue  */
  YYSYMBOL_optTag = 263,                   /* optTag  */
  YYSYMBOL_Tag = 264,                      /* Tag  */
  YYSYMBOL_TagTypeValue = 265,             /* TagTypeValue  */
  YYSYMBOL_TagClass = 266,                 /* TagClass  */
  YYSYMBOL_TagPlicit = 267,                /* TagPlicit  */
  YYSYMBOL_TypeRefName = 268,              /* TypeRefName  */
  YYSYMBOL_optIdentifier = 269,            /* optIdentifier  */
  YYSYMBOL_Identifier = 270,               /* Identifier  */
  YYSYMBOL_IdentifierAsReference = 271,    /* IdentifierAsReference  */
  YYSYMBOL_IdentifierAsValue = 272         /* IdentifierAsValue  */
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
#define YYNNTS  147
/* YYNRULES -- Number of rules.  */
#define YYNRULES  343
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  525

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
     600,   617,   624,   638,   646,   645,   659,   672,   673,   676,
     686,   692,   693,   696,   701,   708,   709,   713,   724,   729,
     736,   742,   748,   758,   759,   771,   774,   777,   785,   790,
     797,   803,   809,   818,   821,   841,   851,   871,   877,   893,
     899,   907,   916,   927,   931,   939,   947,   955,   966,   971,
     978,   979,   987,   995,  1018,  1019,  1022,  1027,  1031,  1039,
    1046,  1052,  1059,  1065,  1070,  1074,  1081,  1086,  1089,  1096,
    1106,  1107,  1111,  1118,  1128,  1138,  1149,  1159,  1170,  1180,
    1191,  1203,  1204,  1211,  1210,  1219,  1223,  1230,  1234,  1237,
    1241,  1247,  1255,  1264,  1275,  1278,  1285,  1308,  1331,  1355,
    1362,  1381,  1382,  1385,  1386,  1392,  1398,  1404,  1414,  1424,
    1430,  1442,  1457,  1465,  1473,  1484,  1495,  1517,  1525,  1534,
    1538,  1543,  1552,  1557,  1562,  1570,  1593,  1603,  1604,  1605,
    1605,  1613,  1618,  1623,  1628,  1629,  1630,  1631,  1635,  1636,
    1654,  1658,  1663,  1671,  1680,  1695,  1696,  1702,  1703,  1704,
    1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,  1714,
    1721,  1722,  1723,  1727,  1733,  1738,  1743,  1748,  1753,  1762,
    1763,  1767,  1771,  1772,  1773,  1774,  1775,  1779,  1780,  1781,
    1782,  1786,  1787,  1794,  1794,  1795,  1795,  1799,  1800,  1804,
    1805,  1809,  1810,  1811,  1815,  1821,  1822,  1831,  1831,  1833,
    1836,  1840,  1841,  1847,  1858,  1859,  1865,  1866,  1872,  1873,
    1880,  1881,  1887,  1888,  1899,  1905,  1911,  1912,  1914,  1915,
    1916,  1921,  1926,  1931,  1936,  1948,  1957,  1958,  1964,  1965,
    1970,  1973,  1978,  1986,  1992,  2004,  2007,  2013,  2014,  2014,
    2015,  2017,  2030,  2035,  2041,  2055,  2056,  2060,  2063,  2066,
    2074,  2075,  2076,  2081,  2080,  2092,  2101,  2102,  2103,  2104,
    2107,  2110,  2119,  2135,  2141,  2147,  2161,  2172,  2188,  2191,
    2211,  2215,  2219,  2223,  2230,  2235,  2241,  2250,  2255,  2262,
    2270,  2280,  2285,  2292,  2300,  2310,  2325,  2330,  2337,  2344,
    2352,  2360,  2367,  2378,  2382,  2389,  2420,  2421,  2425,  2432,
    2438,  2439,  2440,  2441,  2445,  2446,  2447,  2451,  2455,  2463,
    2464,  2470,  2477,  2484
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
  "Assignment", "$@2", "optImports", "ImportsDefinition",
  "optImportsBundleSet", "ImportsBundleSet", "AssignedIdentifier",
  "ImportsBundle", "ImportsList", "ImportsElement", "optExports",
  "ExportsDefinition", "ExportsBody", "ExportsElement", "ValueSet",
  "ValueSetTypeAssignment", "DefinedType", "DataTypeReference",
  "ParameterArgumentList", "ParameterArgumentName", "ActualParameterList",
  "ActualParameter", "optComponentTypeLists", "ComponentTypeLists",
  "ComponentType", "AlternativeTypeLists", "AlternativeType",
  "ObjectClass", "optUNIQUE", "FieldSpec", "ClassField", "optWithSyntax",
  "WithSyntax", "$@3", "WithSyntaxList", "WithSyntaxToken",
  "ExtensionAndException", "Type", "TaggedType", "DefinedUntaggedType",
  "UntaggedType", "MaybeIndirectTaggedType", "NSTD_IndirectMarker",
  "MaybeIndirectTypeDeclaration", "TypeDeclaration",
  "ConcreteTypeDeclaration", "ComplexTypeReference",
  "ComplexTypeReferenceAmpList", "ComplexTypeReferenceElement",
  "PrimitiveFieldReference", "FieldName", "DefinedObjectClass",
  "ValueAssignment", "Value", "$@4", "SimpleValue", "DefinedValue",
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
  "$@5", "ContentsConstraint", "ConstraintRangeSpec", "TableConstraint",
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

#define YYPACT_NINF (-387)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-301)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     104,  -387,  -387,   162,    38,   162,  -387,  -387,   162,  -387,
    -387,   -63,    53,    58,  -387,  -387,  -387,  -387,    70,  -387,
       0,   205,  -387,  -387,   111,    65,    59,    69,   107,   110,
     245,   205,  -387,   108,  -387,  -387,  -387,  -387,  -387,   231,
    -387,  -387,   185,   102,   208,  -387,   212,  -387,   160,  -387,
     189,  -387,   191,  -387,  -387,   196,   680,  -387,  -387,  -387,
     241,   188,  -387,   194,   241,  -387,   -14,  -387,   206,  -387,
    -387,   320,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,   680,  -387,  -387,  -387,  -387,
    -387,    19,   220,  -387,  -387,  -387,  -387,   162,   241,   228,
    -387,  -387,    -2,   834,   128,   340,  -387,   757,  -387,   -19,
     341,   -63,  -387,  -387,  -387,   232,  -387,  -387,   257,  -387,
     258,   271,  -387,  -387,  -387,  -387,  -387,   290,   263,  -387,
    -387,  -387,   -29,  -387,   235,  -387,  -387,   236,  -387,  -387,
    -387,   339,   243,   234,   238,   246,   319,   274,   253,   254,
     293,   261,   115,   138,  -387,  -387,   255,  -387,   264,  -387,
    -387,  -387,  -387,  -387,   547,  -387,  -387,   296,  -387,  -387,
    -387,  -387,  -387,   368,   834,   241,   241,   259,   379,  -387,
     162,   280,    12,   342,   265,    84,    90,   300,   365,   255,
      61,   270,   303,  -387,  -387,    61,   306,  -387,  -387,   255,
     621,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
     275,  -387,  -387,  -387,    51,    28,   -21,  -387,    -2,  -387,
    -387,  -387,  -387,  -387,  -387,   234,   238,   279,   255,   220,
    -387,   120,   284,  -387,   405,   255,  -387,  -387,   272,   281,
     217,   221,  -387,   295,  -387,  -387,  -387,  -387,  -387,   -26,
     112,  -387,  -387,  -387,  -387,  -387,   278,  -387,  -387,  -387,
    -387,    80,  -387,  -387,   365,   365,   283,   113,  -387,  -387,
    -387,  -387,   220,  -387,   288,   285,  -387,  -387,   291,  -387,
     143,  -387,   292,  -387,   332,   297,   294,  -387,  -387,    -9,
     220,   376,   220,   162,   309,  -387,  -387,  -387,  -387,  -387,
    -387,   313,  -387,   365,   315,   365,  -387,   316,  -387,   152,
    -387,  -387,  -387,  -387,   262,   365,  -387,  -387,   547,  -387,
      -9,    10,    -9,  -387,  -387,   314,    10,    -9,   324,   296,
    -387,  -387,   513,  -387,  -387,  -387,  -387,   255,   321,   322,
    -387,  -387,   325,  -387,  -387,   513,  -387,  -387,   513,   513,
     311,   327,   527,   310,  -387,   365,  -387,   157,  -387,   326,
     226,  -387,    25,   757,   255,  -387,  -387,    90,   226,  -387,
     365,   226,   220,  -387,    24,  -387,    -9,   330,  -387,   331,
    -387,   328,   220,  -387,  -387,   220,  -387,   621,  -387,   433,
    -387,  -387,  -387,  -387,  -387,   312,  -387,  -387,  -387,    -9,
    -387,  -387,   356,  -387,  -387,  -387,  -387,  -387,  -387,    14,
    -387,  -387,  -387,  -387,   329,   221,  -387,  -387,  -387,   336,
    -387,  -387,  -387,  -387,  -387,  -387,   365,   229,  -387,  -387,
      84,  -387,  -387,  -387,  -387,   333,   335,  -387,   338,   345,
    -387,    42,  -387,  -387,  -387,  -387,    26,   158,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,   343,   334,   175,  -387,
     255,   405,  -387,  -387,   346,   347,    16,  -387,  -387,  -387,
    -387,    22,   262,   365,   349,  -387,  -387,   328,  -387,  -387,
    -387,   365,  -387,   365,   135,  -387,  -387,  -387,  -387,  -387,
    -387,   433,   349,   365,  -387,    57,   176,  -387,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,    57,    36,  -387,  -387,
    -387,    39,  -387,  -387,  -387
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   337,   338,     0,     0,     3,     4,     6,     2,     1,
       5,     8,     0,     0,     9,   341,    16,    11,     0,    12,
      14,    17,    10,    13,     0,     0,     0,     0,     0,     0,
       0,    18,    19,     0,    25,    23,    21,    24,    22,     0,
      20,    15,    53,     0,     0,    27,    37,    54,     0,    57,
       0,    58,    60,    62,     7,    41,     0,    38,    56,    55,
       0,     0,    40,     0,    42,    43,     0,    48,    50,    52,
     199,     0,   200,   201,   202,   203,   204,   212,   205,   206,
     207,   208,   209,   210,   211,    28,    29,    33,    31,    32,
      36,   326,   326,    59,    61,    39,    44,     0,     0,     0,
      34,    30,   326,     0,   330,     0,   124,     0,   327,   334,
       0,    45,    49,    51,    35,     0,    68,    67,     0,   177,
       0,     0,   191,   183,   187,   190,   178,     0,     0,   179,
     182,   186,     0,    71,     0,   189,   188,    73,   332,   333,
     331,     0,     0,   142,   143,     0,   139,     0,     0,   191,
       0,   190,   221,   221,   132,   125,   219,   131,    65,   193,
     133,   336,   335,   328,     0,    46,    47,     0,   192,   185,
     184,   181,   180,     0,     0,     0,     0,     0,     0,    64,
       0,     0,     0,     0,   192,   326,     0,     0,     0,     0,
     326,     0,     0,   222,   223,   326,     0,   127,   225,   220,
       0,   261,   170,   262,   323,   324,   325,   171,   172,   162,
     161,   163,   159,   156,   157,   158,   166,   167,   164,   165,
       0,   342,   343,   168,   326,   326,     0,   102,   326,    72,
      77,    76,    75,    74,   329,   142,   143,     0,     0,   326,
     257,     0,     0,   230,     0,   219,   264,   260,     0,   231,
     234,   236,   238,   240,   242,   246,   247,   249,   250,     0,
     244,   245,   248,   144,   150,   151,   146,   147,   149,   145,
     198,     0,   304,   306,     0,     0,   121,     0,    93,    97,
      98,   129,   326,   322,     0,   315,   316,   321,   318,   141,
       0,   307,     0,   252,     0,     0,    85,    86,    92,   300,
     326,     0,   326,   159,     0,   227,   229,   228,   280,   282,
     281,   290,   291,   339,     0,   339,   226,   161,    83,     0,
      78,    80,    81,    82,     0,     0,   155,   152,     0,   302,
     300,   300,   300,   104,   301,   100,   300,   300,   111,     0,
      70,    69,     0,   251,   263,   253,   254,     0,     0,     0,
     126,    63,     0,   213,   214,     0,   215,   216,     0,     0,
     286,     0,     0,     0,   197,     0,   140,     0,   311,     0,
       0,   134,   326,     0,   219,    96,   195,     0,     0,   194,
       0,     0,   326,   135,   326,    90,   300,     0,   285,     0,
     224,     0,   326,   340,   136,   326,    66,     0,   175,   160,
     173,   176,   169,   303,   109,     0,   108,   110,   101,   300,
     106,   107,     0,    99,   112,   103,   235,   267,   265,     0,
     266,   268,   269,   243,   232,   237,   239,   241,   287,   288,
     259,   255,   258,   148,   305,   196,     0,     0,   122,   123,
     326,    94,   130,   128,   317,     0,     0,   308,     0,     0,
      91,   326,    87,    89,   283,   292,     0,     0,   294,   129,
     129,    79,   174,   153,   154,   105,     0,     0,     0,   272,
     217,     0,   289,   312,     0,     0,     0,   320,   319,   310,
     309,     0,     0,     0,   296,   298,   293,     0,   137,   138,
     113,     0,   270,     0,   275,   218,   233,   313,   314,    95,
      88,   284,   297,     0,   295,     0,     0,   273,   278,   279,
     277,   274,   276,   299,   117,   118,     0,     0,   115,   119,
     271,     0,   114,   116,   120
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -387,  -387,   452,   237,  -387,  -387,   353,  -387,   447,  -387,
    -387,   435,  -387,  -387,  -387,   384,  -387,  -387,  -387,  -387,
    -387,  -387,   411,  -387,   380,  -387,  -387,  -387,   417,   337,
    -387,  -106,  -387,  -387,   307,  -387,    83,   289,    34,   103,
      46,   116,   267,  -387,  -387,   150,  -387,  -387,  -387,   -18,
    -225,  -172,   -82,  -387,  -387,   389,  -176,  -387,  -125,   124,
    -387,   317,  -387,   137,  -164,   276,   277,  -387,  -140,  -387,
    -192,  -188,  -387,    21,  -387,   -20,  -387,  -387,     5,  -387,
    -387,  -387,  -227,   352,  -150,  -387,  -387,  -387,   318,  -237,
    -387,   151,   149,  -268,  -387,  -387,   184,  -387,  -387,  -387,
    -387,   148,  -387,  -387,  -387,  -387,  -387,  -387,  -387,    20,
      23,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
    -387,  -387,    27,    29,  -220,  -387,  -387,   154,  -387,   133,
    -387,    79,  -387,  -387,   140,  -160,  -387,   -87,  -387,  -387,
    -387,  -387,    11,   218,   -12,  -387,  -386
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,    11,    13,    14,    18,    19,    30,
      31,    32,    44,    45,    85,    86,   114,    56,    57,    63,
      64,   166,    65,    66,    67,    46,    47,    50,    51,   318,
      87,   245,    88,   132,   133,   319,   320,   295,   296,   297,
     277,   278,   116,   409,   226,   227,   413,   414,   505,   517,
     518,   298,   105,   106,   246,   321,   299,   373,   374,   156,
     157,   158,   266,   267,   519,   331,   332,    89,   247,   324,
     214,   215,   216,   399,   400,   159,   135,   160,   136,   355,
     358,   494,   197,   192,   198,   199,   304,   305,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     431,   260,   217,   261,   262,   418,   420,   421,   422,   468,
     469,   511,   512,   307,   308,   482,   309,   362,   310,   311,
     312,   457,   458,   484,   333,   334,   271,   272,   290,   291,
     367,   368,   284,   285,   286,   218,   219,   281,   108,   109,
     141,   163,   220,   392,   221,   222,   223
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,   154,   193,   193,   107,   107,    20,   349,   322,   280,
     110,     7,   323,   279,     7,   107,     7,   268,   350,     7,
     117,   499,   102,    15,   213,    15,   287,   500,   451,   440,
     161,    53,   328,   470,   115,    15,    15,    15,     9,   293,
      97,   162,   514,    69,    92,   514,   326,   327,    53,   316,
      12,   328,    69,    15,    52,   264,   265,   515,   264,   265,
     515,    90,   294,   514,    15,    16,    68,    91,   329,   326,
     327,    52,    15,    92,   416,    68,   264,   265,   515,   385,
     294,    15,    16,   134,   360,   173,    69,   329,   343,   174,
      90,   427,   328,   338,   154,    15,    91,   339,   361,   294,
      21,    15,   204,   205,    98,   470,   375,   470,   111,    68,
     404,   406,   407,    15,   137,    24,   410,   411,   104,     1,
       2,     1,     2,    33,   386,   467,   270,    48,   329,   345,
      34,    15,   103,   405,   372,   276,   276,   107,   107,   104,
     384,   107,   330,   335,   104,   104,   341,   443,   104,   483,
     522,    35,   107,   276,   134,   138,   516,   344,   508,   516,
     524,    36,   104,   231,   233,  -300,   453,    17,    37,  -300,
     273,   104,   276,   282,   288,   -84,   292,   516,   300,     1,
       2,   104,   438,   300,    22,   137,   230,   232,   403,   465,
     445,   263,   269,   448,   364,   276,   280,   417,   365,   268,
     279,   283,    38,   189,   104,   322,   450,    15,     3,   323,
     439,   139,   509,     1,     2,   107,   510,   287,   446,    49,
     388,   449,  -256,    25,    41,   140,   189,   371,   190,   346,
     191,   372,   -26,    26,   496,    43,  -256,    15,   204,   205,
      15,   474,    10,     1,     2,    10,     1,     2,    39,   475,
      62,   195,    15,   191,    27,    54,    28,   379,     1,     2,
      42,   380,   366,   369,   280,    29,   396,   154,   279,   398,
     397,   435,   486,    15,    55,   436,   487,    58,   201,   202,
     203,    15,   204,   205,   206,   207,   208,   235,   236,   492,
     520,   154,   523,   493,   493,   237,   523,     1,     2,   264,
     265,   393,    94,   393,    61,   459,    59,    60,   460,   301,
     302,    95,   401,   402,   389,   224,   225,   143,   144,    99,
     495,   347,   348,   209,   238,   353,   354,   356,   357,   264,
     265,   463,   464,   239,   488,   489,   194,   194,   100,   240,
     104,   210,   113,   142,   164,   167,   168,   169,   241,   171,
     170,   177,   172,   273,   175,   176,   178,   180,   189,   182,
     282,   181,   183,   184,   211,   288,   185,   186,   292,   187,
     191,   228,   300,   242,   188,   274,    15,   200,   275,   313,
     234,   243,   315,   303,   342,   244,   351,   201,   202,   203,
      15,   204,   205,   206,   207,   208,   235,   236,   325,   352,
     359,   363,   376,   377,   237,   370,   378,   381,   382,   387,
     408,   383,   384,   201,   202,   203,    15,   204,   205,   206,
     207,   208,   235,   236,   369,   390,   391,   412,   282,   394,
     237,  -178,   209,   238,   419,   428,   424,   429,   423,   300,
     462,   437,   239,   454,   485,   455,   466,   471,   240,   477,
     210,   478,   491,   456,   479,     8,   490,   241,   209,   238,
     472,   480,   497,   498,   165,    23,    40,   189,   239,   101,
     401,   485,   503,   211,   240,    96,   210,    93,   112,   179,
     461,   229,   242,   241,   314,   481,   476,   452,   441,   415,
     243,   513,   212,   189,   244,   340,   155,   442,   521,   211,
     433,   336,   337,   501,   289,   196,   425,   426,   242,   306,
     432,   506,   502,   447,   504,   473,   507,   444,   212,   434,
     244,   201,   202,   203,    15,   204,   205,   206,   207,   208,
     235,   236,     0,   395,     0,   201,   202,   203,    15,   204,
     205,   206,   207,   208,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   202,   203,    15,   204,
     205,   206,   207,   208,     1,     2,   209,   238,     0,     0,
       0,     0,     0,     0,     0,     0,   239,     0,     0,     0,
     209,     0,   240,     0,   210,     0,     0,     0,     0,     0,
       0,   241,     0,     0,     0,   430,     0,     0,   210,     0,
     209,   189,     0,     0,     0,     0,     0,   211,     0,     0,
       0,     0,     0,     0,     0,     0,   242,     0,   210,     0,
       0,   211,     0,     0,     0,     0,   212,     0,   244,   201,
     202,   203,    15,   204,   205,   206,   207,   208,   235,   236,
     212,   211,     0,   145,     0,     0,     0,   146,     0,     0,
       0,   147,    70,   119,     0,   120,   148,     0,     0,     0,
     212,     0,     0,     0,     0,   121,     0,     0,     0,   149,
       0,     0,     0,   123,   209,     0,   124,    72,    73,    74,
       0,     0,     0,     0,     0,   150,     0,   151,    75,     0,
       0,    15,   317,    76,   127,    77,   128,     1,     2,     0,
       0,     0,     0,    78,     0,   129,   130,   152,   153,     0,
       0,    70,    79,     0,    80,   211,     0,     0,     0,    81,
     131,    82,    83,    84,     0,     0,    71,     0,     0,     0,
       0,     0,     0,     0,   178,     0,    72,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,    75,     0,     0,
       0,     0,    76,     0,    77,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,    80,   143,   144,     0,     0,    81,   145,
      82,    83,    84,   146,     0,     0,     0,   147,    70,   119,
       0,   120,   148,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   149,     0,     0,     0,   123,
       0,     0,   124,    72,    73,    74,     0,     0,     0,     0,
       0,   150,     0,   151,    75,     0,     0,     0,   126,    76,
     127,    77,   128,     0,     0,     0,     0,     0,     0,    78,
       0,   129,   130,   152,   153,     0,     0,     0,    79,     0,
      80,     1,     2,     0,     0,    81,   131,    82,    83,    84,
       0,     0,     0,     0,   118,    70,   119,     0,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,     0,     0,     0,   123,     0,     0,   124,
      72,    73,    74,     0,     0,     0,     0,     0,     0,     0,
     125,    75,     0,     0,     0,   126,    76,   127,    77,   128,
       0,     0,     0,     0,     0,     0,    78,     0,   129,   130,
       0,     0,     0,     0,     0,    79,     0,    80,     0,     0,
       0,     0,    81,   131,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      12,   107,   152,   153,    91,    92,    18,   244,   200,   185,
      92,     0,   200,   185,     3,   102,     5,   181,   245,     8,
     102,     5,     3,    11,   164,    11,   186,     5,     4,     4,
      49,    43,    41,   419,    36,    11,    11,    11,     0,   189,
      54,    60,     6,    55,    56,     6,    18,    19,    60,   199,
     113,    41,    64,    11,    43,    19,    20,    21,    19,    20,
      21,    56,    38,     6,    11,    12,    55,    56,    77,    18,
      19,    60,    11,    85,   342,    64,    19,    20,    21,   299,
      38,    11,    12,   103,   110,   114,    98,    77,   238,   118,
      85,   359,    41,   114,   200,    11,    85,   118,   124,    38,
      42,    11,    12,    13,   118,   491,   282,   493,    97,    98,
     330,   331,   332,    11,   103,   115,   336,   337,   120,    17,
      18,    17,    18,    12,   300,   111,   114,    25,    77,     9,
      65,    11,   113,   123,   118,   111,   111,   224,   225,   120,
     118,   228,   224,   225,   120,   120,   228,   374,   120,   123,
     114,    92,   239,   111,   174,    27,   120,   239,    23,   120,
     121,    92,   120,   175,   176,   114,   386,   114,    61,   118,
     182,   120,   111,   185,   186,   114,   188,   120,   190,    17,
      18,   120,   370,   195,   114,   174,   175,   176,   328,   409,
     378,   180,   181,   381,   114,   111,   372,   347,   118,   363,
     372,   111,    92,    88,   120,   397,   382,    11,   104,   397,
     370,    83,    77,    17,    18,   302,    81,   377,   378,   117,
     302,   381,   110,    18,   116,    97,    88,   114,   113,   241,
     115,   118,    47,    28,   471,    50,   124,    11,    12,    13,
      11,    12,     5,    17,    18,     8,    17,    18,     3,   437,
      54,   113,    11,   115,    49,    47,    51,   114,    17,    18,
      29,   118,   274,   275,   440,    60,   114,   373,   440,     7,
     118,   114,   114,    11,    62,   118,   118,   117,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,   114,
     114,   397,   517,   118,   118,    25,   521,    17,    18,    19,
      20,   313,   114,   315,   113,   392,   117,   118,   395,    39,
      40,   117,   324,   325,   303,    19,    20,    17,    18,   113,
     470,    37,    38,    53,    54,   108,   109,   106,   107,    19,
      20,    19,    20,    63,   459,   460,   152,   153,    18,    69,
     120,    71,   114,     3,     3,   113,    89,    89,    78,    59,
      79,    12,    89,   365,   119,   119,   113,   123,    88,   113,
     372,   123,    43,    89,    94,   377,   113,   113,   380,    76,
     115,     3,   384,   103,   113,    33,    11,   113,   113,    76,
     121,   111,    76,   113,   105,   115,   114,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   123,   118,
     105,   123,   114,   118,    25,   122,   115,   115,    76,    33,
      96,   114,   118,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   436,   116,   113,   103,   440,   114,
      25,   115,    53,    54,   113,   124,   111,   110,   116,   451,
       7,   115,    63,   113,   456,   114,    90,   118,    69,   116,
      71,   116,   118,   125,   116,     3,   113,    78,    53,    54,
     124,   116,   116,   116,   111,    18,    31,    88,    63,    85,
     482,   483,   123,    94,    69,    64,    71,    60,    98,   142,
     397,   174,   103,    78,   195,   451,   440,   384,   372,   339,
     111,   503,   113,    88,   115,   228,   107,   373,   516,    94,
     363,   225,   225,   482,   187,   153,   355,   358,   103,   191,
     362,   491,   483,   380,   487,   436,   493,   377,   113,   365,
     115,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,   315,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      53,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,
      53,    88,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    71,    -1,
      -1,    94,    -1,    -1,    -1,    -1,   113,    -1,   115,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     113,    94,    -1,    22,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    30,    31,    32,    -1,    34,    35,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    67,    -1,
      -1,    11,    71,    72,    73,    74,    75,    17,    18,    -1,
      -1,    -1,    -1,    82,    -1,    84,    85,    86,    87,    -1,
      -1,    31,    91,    -1,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    93,    17,    18,    -1,    -1,    98,    22,
     100,   101,   102,    26,    -1,    -1,    -1,    30,    31,    32,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
       0,    17,    18,   104,   127,   128,   129,   268,   128,     0,
     129,   130,   113,   131,   132,    11,    12,   114,   133,   134,
     270,    42,   114,   134,   115,    18,    28,    49,    51,    60,
     135,   136,   137,    12,    65,    92,    92,    61,    92,     3,
     137,   116,    29,    50,   138,   139,   151,   152,    25,   117,
     153,   154,   268,   270,    47,    62,   143,   144,   117,   117,
     118,   113,    54,   145,   146,   148,   149,   150,   268,   270,
      31,    46,    56,    57,    58,    67,    72,    74,    82,    91,
      93,    98,   100,   101,   102,   140,   141,   156,   158,   193,
     204,   268,   270,   154,   114,   117,   148,    54,   118,   113,
      18,   141,     3,   113,   120,   178,   179,   263,   264,   265,
     178,   268,   150,   114,   142,    36,   168,   178,    30,    32,
      34,    44,    48,    52,    55,    66,    71,    73,    75,    84,
      85,    99,   159,   160,   201,   202,   204,   268,    27,    83,
      97,   266,     3,    17,    18,    22,    26,    30,    35,    48,
      64,    66,    86,    87,   157,   181,   185,   186,   187,   201,
     203,    49,    60,   267,     3,   132,   147,   113,    89,    89,
      79,    59,    89,   114,   118,   119,   119,    12,   113,   155,
     123,   123,   113,    43,    89,   113,   113,    76,   113,    88,
     113,   115,   209,   210,   222,   113,   209,   208,   210,   211,
     113,     8,     9,    10,    12,    13,    14,    15,    16,    53,
      71,    94,   113,   194,   196,   197,   198,   228,   261,   262,
     268,   270,   271,   272,    19,    20,   170,   171,     3,   160,
     268,   270,   268,   270,   121,    17,    18,    25,    54,    63,
      69,    78,   103,   111,   115,   157,   180,   194,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     227,   229,   230,   268,    19,    20,   188,   189,   190,   268,
     114,   252,   253,   270,    33,   113,   111,   166,   167,   177,
     182,   263,   270,   111,   258,   259,   260,   261,   270,   187,
     254,   255,   270,   210,    38,   163,   164,   165,   177,   182,
     270,    39,    40,   113,   212,   213,   214,   239,   240,   242,
     244,   245,   246,    76,   163,    76,   210,    71,   155,   161,
     162,   181,   196,   197,   195,   123,    18,    19,    41,    77,
     178,   191,   192,   250,   251,   178,   191,   192,   114,   118,
     168,   178,   105,   210,   178,     9,   270,    37,    38,   215,
     208,   114,   118,   108,   109,   205,   106,   107,   206,   105,
     110,   124,   243,   123,   114,   118,   270,   256,   257,   270,
     122,   114,   118,   183,   184,   182,   114,   118,   115,   114,
     118,   115,    76,   114,   118,   250,   182,    33,   178,   268,
     116,   113,   269,   270,   114,   269,   114,   118,     7,   199,
     200,   270,   270,   194,   250,   123,   250,   250,    96,   169,
     250,   250,   103,   172,   173,   171,   219,   210,   231,   113,
     232,   233,   234,   116,   111,   217,   218,   219,   124,   110,
      68,   226,   227,   189,   253,   114,   118,   115,   197,   261,
       4,   167,   185,   208,   260,   197,   261,   255,   197,   261,
     182,     4,   165,   250,   113,   114,   125,   247,   248,   263,
     263,   162,     7,    19,    20,   250,    90,   111,   235,   236,
     272,   118,   124,   257,    12,   197,   166,   116,   116,   116,
     116,   164,   241,   123,   249,   270,   114,   118,   184,   184,
     113,   118,   114,   118,   207,   210,   215,   116,   116,     5,
       5,   199,   249,   123,   248,   174,   235,   236,    23,    77,
      81,   237,   238,   270,     6,    21,   120,   175,   176,   190,
     114,   175,   114,   176,   121
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   126,   127,   127,   128,   128,   130,   129,   131,   131,
     132,   132,   133,   133,   134,   134,   134,   135,   135,   136,
     136,   137,   137,   137,   137,   137,   138,   138,   139,   140,
     140,   141,   141,   141,   142,   141,   141,   143,   143,   144,
     144,   145,   145,   146,   146,   147,   147,   148,   149,   149,
     150,   150,   150,   151,   151,   152,   152,   152,   153,   153,
     154,   154,   154,   155,   156,   157,   157,   158,   158,   158,
     158,   159,   159,   160,   160,   160,   160,   160,   161,   161,
     162,   162,   162,   162,   163,   163,   164,   164,   164,   165,
     165,   165,   165,   166,   166,   166,   167,   167,   167,   168,
     169,   169,   170,   170,   171,   171,   171,   171,   171,   171,
     171,   172,   172,   174,   173,   175,   175,   176,   176,   176,
     176,   177,   177,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   185,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   187,   187,   187,   187,   187,   188,   188,   189,
     190,   190,   191,   191,   191,   192,   193,   194,   194,   195,
     194,   196,   196,   196,   196,   196,   196,   196,   197,   197,
     198,   198,   198,   199,   199,   200,   200,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     202,   202,   202,   203,   203,   203,   203,   203,   203,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   205,   205,   206,   206,   207,   207,   208,
     208,   209,   209,   209,   210,   211,   211,   212,   212,   213,
     214,   214,   214,   214,   215,   215,   216,   216,   217,   217,
     218,   218,   219,   219,   220,   220,   220,   220,   220,   220,
     220,   221,   222,   223,   223,   224,   225,   225,   226,   226,
     227,   228,   228,   229,   229,   230,   230,   231,   232,   232,
     233,   234,   235,   235,   236,   237,   237,   238,   238,   238,
     239,   239,   239,   241,   240,   242,   243,   243,   243,   243,
     244,   244,   245,   246,   247,   247,   248,   248,   249,   249,
     250,   250,   251,   251,   252,   252,   253,   254,   254,   255,
     255,   256,   256,   257,   257,   258,   259,   259,   260,   260,
     260,   260,   260,   261,   261,   262,   263,   263,   264,   265,
     266,   266,   266,   266,   267,   267,   267,   268,   268,   269,
     269,   270,   271,   272
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     0,     9,     0,     1,
       3,     2,     1,     2,     1,     4,     1,     0,     1,     1,
       2,     2,     2,     2,     2,     2,     0,     1,     3,     1,
       2,     1,     1,     1,     0,     3,     1,     0,     1,     3,
       2,     0,     1,     1,     2,     0,     1,     4,     1,     3,
       1,     3,     1,     0,     1,     3,     3,     2,     1,     3,
       1,     3,     1,     3,     4,     1,     4,     3,     3,     6,
       6,     1,     3,     1,     3,     3,     3,     3,     1,     3,
       1,     1,     1,     1,     0,     1,     1,     3,     5,     3,
       2,     3,     1,     1,     3,     5,     2,     1,     1,     5,
       0,     1,     1,     3,     2,     4,     3,     3,     3,     3,
       3,     0,     1,     0,     6,     1,     2,     1,     1,     1,
       3,     1,     3,     3,     1,     2,     2,     2,     3,     0,
       2,     1,     1,     1,     4,     4,     4,     6,     6,     1,
       4,     3,     1,     1,     3,     3,     3,     1,     3,     1,
       1,     1,     1,     3,     3,     1,     4,     1,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     4,     4,     5,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     0,
       1,     0,     1,     1,     3,     1,     2,     1,     1,     1,
       1,     1,     3,     5,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     3,     1,     1,     1,
       3,     5,     1,     3,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     2,     1,     2,     2,     3,
       1,     1,     3,     4,     1,     3,     2,     3,     1,     3,
       0,     1,     1,     2,     1,     3,     1,     1,     3,     4,
       4,     1,     3,     4,     4,     1,     1,     3,     1,     4,
       4,     1,     1,     1,     1,     1,     0,     1,     2,     4,
       0,     1,     1,     1,     0,     1,     1,     1,     1,     0,
       1,     1,     1,     1
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
#line 1984 "asn1p_y.c"
    break;

  case 3: /* ParsedGrammar: ModuleList  */
#line 414 "asn1p_y.y"
                     {
		*param = (yyvsp[0].a_grammar);
	}
#line 1992 "asn1p_y.c"
    break;

  case 4: /* ModuleList: ModuleDefinition  */
#line 420 "asn1p_y.y"
                         {
		(yyval.a_grammar) = asn1p_new();
		checkmem((yyval.a_grammar));
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[0].a_module), mod_next);
	}
#line 2002 "asn1p_y.c"
    break;

  case 5: /* ModuleList: ModuleList ModuleDefinition  */
#line 425 "asn1p_y.y"
                                      {
		(yyval.a_grammar) = (yyvsp[-1].a_grammar);
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[0].a_module), mod_next);
	}
#line 2011 "asn1p_y.c"
    break;

  case 6: /* $@1: %empty  */
#line 442 "asn1p_y.y"
                    { currentModule = asn1p_module_new(); }
#line 2017 "asn1p_y.c"
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
#line 2039 "asn1p_y.c"
    break;

  case 8: /* optObjectIdentifier: %empty  */
#line 471 "asn1p_y.y"
        { (yyval.a_oid) = 0; }
#line 2045 "asn1p_y.c"
    break;

  case 9: /* optObjectIdentifier: ObjectIdentifier  */
#line 472 "asn1p_y.y"
                           { (yyval.a_oid) = (yyvsp[0].a_oid); }
#line 2051 "asn1p_y.c"
    break;

  case 10: /* ObjectIdentifier: '{' ObjectIdentifierBody '}'  */
#line 476 "asn1p_y.y"
                                     {
		(yyval.a_oid) = (yyvsp[-1].a_oid);
	}
#line 2059 "asn1p_y.c"
    break;

  case 11: /* ObjectIdentifier: '{' '}'  */
#line 479 "asn1p_y.y"
                  {
		(yyval.a_oid) = 0;
	}
#line 2067 "asn1p_y.c"
    break;

  case 12: /* ObjectIdentifierBody: ObjectIdentifierElement  */
#line 485 "asn1p_y.y"
                                {
		(yyval.a_oid) = asn1p_oid_new();
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[0].a_oid_arc));
		if((yyvsp[0].a_oid_arc).name)
			free((yyvsp[0].a_oid_arc).name);
	}
#line 2078 "asn1p_y.c"
    break;

  case 13: /* ObjectIdentifierBody: ObjectIdentifierBody ObjectIdentifierElement  */
#line 491 "asn1p_y.y"
                                                       {
		(yyval.a_oid) = (yyvsp[-1].a_oid);
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[0].a_oid_arc));
		if((yyvsp[0].a_oid_arc).name)
			free((yyvsp[0].a_oid_arc).name);
	}
#line 2089 "asn1p_y.c"
    break;

  case 14: /* ObjectIdentifierElement: Identifier  */
#line 500 "asn1p_y.y"
                   {					/* iso */
		(yyval.a_oid_arc).name = (yyvsp[0].tv_str);
		(yyval.a_oid_arc).number = -1;
	}
#line 2098 "asn1p_y.c"
    break;

  case 15: /* ObjectIdentifierElement: Identifier '(' "number" ')'  */
#line 504 "asn1p_y.y"
                                        {		/* iso(1) */
		(yyval.a_oid_arc).name = (yyvsp[-3].tv_str);
		(yyval.a_oid_arc).number = (yyvsp[-1].a_int);
	}
#line 2107 "asn1p_y.c"
    break;

  case 16: /* ObjectIdentifierElement: "number"  */
#line 508 "asn1p_y.y"
                     {					/* 1 */
		(yyval.a_oid_arc).name = 0;
		(yyval.a_oid_arc).number = (yyvsp[0].a_int);
	}
#line 2116 "asn1p_y.c"
    break;

  case 17: /* optModuleDefinitionFlags: %empty  */
#line 518 "asn1p_y.y"
        { (yyval.a_module_flags) = MSF_NOFLAGS; }
#line 2122 "asn1p_y.c"
    break;

  case 18: /* optModuleDefinitionFlags: ModuleDefinitionFlags  */
#line 519 "asn1p_y.y"
                                {
		(yyval.a_module_flags) = (yyvsp[0].a_module_flags);
	}
#line 2130 "asn1p_y.c"
    break;

  case 19: /* ModuleDefinitionFlags: ModuleDefinitionFlag  */
#line 528 "asn1p_y.y"
                             {
		(yyval.a_module_flags) = (yyvsp[0].a_module_flags);
	}
#line 2138 "asn1p_y.c"
    break;

  case 20: /* ModuleDefinitionFlags: ModuleDefinitionFlags ModuleDefinitionFlag  */
#line 531 "asn1p_y.y"
                                                     {
		(yyval.a_module_flags) = (yyvsp[-1].a_module_flags) | (yyvsp[0].a_module_flags);
	}
#line 2146 "asn1p_y.c"
    break;

  case 21: /* ModuleDefinitionFlag: TOK_EXPLICIT TOK_TAGS  */
#line 540 "asn1p_y.y"
                              {
		(yyval.a_module_flags) = MSF_EXPLICIT_TAGS;
	}
#line 2154 "asn1p_y.c"
    break;

  case 22: /* ModuleDefinitionFlag: TOK_IMPLICIT TOK_TAGS  */
#line 543 "asn1p_y.y"
                                {
		(yyval.a_module_flags) = MSF_IMPLICIT_TAGS;
	}
#line 2162 "asn1p_y.c"
    break;

  case 23: /* ModuleDefinitionFlag: TOK_AUTOMATIC TOK_TAGS  */
#line 546 "asn1p_y.y"
                                 {
		(yyval.a_module_flags) = MSF_AUTOMATIC_TAGS;
	}
#line 2170 "asn1p_y.c"
    break;

  case 24: /* ModuleDefinitionFlag: TOK_EXTENSIBILITY TOK_IMPLIED  */
#line 549 "asn1p_y.y"
                                        {
		(yyval.a_module_flags) = MSF_EXTENSIBILITY_IMPLIED;
	}
#line 2178 "asn1p_y.c"
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
#line 2198 "asn1p_y.c"
    break;

  case 26: /* optModuleBody: %empty  */
#line 574 "asn1p_y.y"
        { (yyval.a_module) = 0; }
#line 2204 "asn1p_y.c"
    break;

  case 27: /* optModuleBody: ModuleBody  */
#line 575 "asn1p_y.y"
                     {
		(yyval.a_module) = (yyvsp[0].a_module);
	}
#line 2212 "asn1p_y.c"
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
#line 2227 "asn1p_y.c"
    break;

  case 29: /* AssignmentList: Assignment  */
#line 597 "asn1p_y.y"
                   {
		(yyval.a_module) = (yyvsp[0].a_module);
	}
#line 2235 "asn1p_y.c"
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
#line 2250 "asn1p_y.c"
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
#line 2262 "asn1p_y.c"
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
#line 2274 "asn1p_y.c"
    break;

  case 33: /* Assignment: ValueSetTypeAssignment  */
#line 638 "asn1p_y.y"
                                 {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[0].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[0].a_expr)->meta_type != AMT_INVALID);
		asn1p_module_member_add((yyval.a_module), (yyvsp[0].a_expr));
	}
#line 2286 "asn1p_y.c"
    break;

  case 34: /* $@2: %empty  */
#line 646 "asn1p_y.y"
                { asn1p_lexer_hack_push_encoding_control(); }
#line 2292 "asn1p_y.c"
    break;

  case 35: /* Assignment: TOK_ENCODING_CONTROL TOK_capitalreference $@2  */
#line 647 "asn1p_y.y"
                        {
		fprintf(stderr,
			"WARNING: ENCODING-CONTROL %s "
			"specification at %s:%d ignored\n",
			(yyvsp[-1].tv_str), ASN_FILENAME, yylineno);
		free((yyvsp[-1].tv_str));
		(yyval.a_module) = 0;
	}
#line 2305 "asn1p_y.c"
    break;

  case 36: /* Assignment: BasicString  */
#line 659 "asn1p_y.y"
                      {
		return yyerror(param,
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
#line 2315 "asn1p_y.c"
    break;

  case 37: /* optImports: %empty  */
#line 672 "asn1p_y.y"
        { (yyval.a_module) = 0; }
#line 2321 "asn1p_y.c"
    break;

  case 39: /* ImportsDefinition: TOK_IMPORTS optImportsBundleSet ';'  */
#line 676 "asn1p_y.y"
                                            {
		if(!saved_aid && 0)
			return yyerror(param, "Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		(yyval.a_module) = (yyvsp[-1].a_module);
	}
#line 2333 "asn1p_y.c"
    break;

  case 40: /* ImportsDefinition: TOK_IMPORTS TOK_FROM  */
#line 686 "asn1p_y.y"
                                         {
		return yyerror(param, "Empty IMPORTS list");
	}
#line 2341 "asn1p_y.c"
    break;

  case 41: /* optImportsBundleSet: %empty  */
#line 692 "asn1p_y.y"
        { (yyval.a_module) = asn1p_module_new(); }
#line 2347 "asn1p_y.c"
    break;

  case 43: /* ImportsBundleSet: ImportsBundle  */
#line 696 "asn1p_y.y"
                      {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[0].a_xports), xp_next);
	}
#line 2357 "asn1p_y.c"
    break;

  case 44: /* ImportsBundleSet: ImportsBundleSet ImportsBundle  */
#line 701 "asn1p_y.y"
                                         {
		(yyval.a_module) = (yyvsp[-1].a_module);
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[0].a_xports), xp_next);
	}
#line 2366 "asn1p_y.c"
    break;

  case 45: /* AssignedIdentifier: %empty  */
#line 708 "asn1p_y.y"
        { memset(&(yyval.a_aid), 0, sizeof((yyval.a_aid))); }
#line 2372 "asn1p_y.c"
    break;

  case 46: /* AssignedIdentifier: ObjectIdentifier  */
#line 709 "asn1p_y.y"
                           { (yyval.a_aid).oid = (yyvsp[0].a_oid); }
#line 2378 "asn1p_y.c"
    break;

  case 47: /* ImportsBundle: ImportsList TOK_FROM TypeRefName AssignedIdentifier  */
#line 713 "asn1p_y.y"
                                                            {
		(yyval.a_xports) = (yyvsp[-3].a_xports);
		(yyval.a_xports)->fromModuleName = (yyvsp[-1].tv_str);
		(yyval.a_xports)->identifier = (yyvsp[0].a_aid);
		/* This stupid thing is used for look-back hack. */
		saved_aid = (yyval.a_xports)->identifier.oid ? 0 : &((yyval.a_xports)->identifier);
		checkmem((yyval.a_xports));
	}
#line 2391 "asn1p_y.c"
    break;

  case 48: /* ImportsList: ImportsElement  */
#line 724 "asn1p_y.y"
                       {
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[0].a_expr), next);
	}
#line 2401 "asn1p_y.c"
    break;

  case 49: /* ImportsList: ImportsList ',' ImportsElement  */
#line 729 "asn1p_y.y"
                                         {
		(yyval.a_xports) = (yyvsp[-2].a_xports);
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[0].a_expr), next);
	}
#line 2410 "asn1p_y.c"
    break;

  case 50: /* ImportsElement: TypeRefName  */
#line 736 "asn1p_y.y"
                    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
#line 2421 "asn1p_y.c"
    break;

  case 51: /* ImportsElement: TypeRefName '{' '}'  */
#line 742 "asn1p_y.y"
                              {		/* Completely equivalent to above */
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
#line 2432 "asn1p_y.c"
    break;

  case 52: /* ImportsElement: Identifier  */
#line 748 "asn1p_y.y"
                     {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
#line 2443 "asn1p_y.c"
    break;

  case 53: /* optExports: %empty  */
#line 758 "asn1p_y.y"
        { (yyval.a_module) = 0; }
#line 2449 "asn1p_y.c"
    break;

  case 54: /* optExports: ExportsDefinition  */
#line 759 "asn1p_y.y"
                            {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		if((yyvsp[0].a_xports)) {
			TQ_ADD(&((yyval.a_module)->exports), (yyvsp[0].a_xports), xp_next);
		} else {
			/* "EXPORTS ALL;" */
		}
	}
#line 2463 "asn1p_y.c"
    break;

  case 55: /* ExportsDefinition: TOK_EXPORTS ExportsBody ';'  */
#line 771 "asn1p_y.y"
                                    {
		(yyval.a_xports) = (yyvsp[-1].a_xports);
	}
#line 2471 "asn1p_y.c"
    break;

  case 56: /* ExportsDefinition: TOK_EXPORTS TOK_ALL ';'  */
#line 774 "asn1p_y.y"
                                  {
		(yyval.a_xports) = 0;
	}
#line 2479 "asn1p_y.c"
    break;

  case 57: /* ExportsDefinition: TOK_EXPORTS ';'  */
#line 777 "asn1p_y.y"
                          {
		/* Empty EXPORTS clause effectively prohibits export. */
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
	}
#line 2489 "asn1p_y.c"
    break;

  case 58: /* ExportsBody: ExportsElement  */
#line 785 "asn1p_y.y"
                       {
		(yyval.a_xports) = asn1p_xports_new();
		assert((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[0].a_expr), next);
	}
#line 2499 "asn1p_y.c"
    break;

  case 59: /* ExportsBody: ExportsBody ',' ExportsElement  */
#line 790 "asn1p_y.y"
                                         {
		(yyval.a_xports) = (yyvsp[-2].a_xports);
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[0].a_expr), next);
	}
#line 2508 "asn1p_y.c"
    break;

  case 60: /* ExportsElement: TypeRefName  */
#line 797 "asn1p_y.y"
                    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
#line 2519 "asn1p_y.c"
    break;

  case 61: /* ExportsElement: TypeRefName '{' '}'  */
#line 803 "asn1p_y.y"
                              {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
#line 2530 "asn1p_y.c"
    break;

  case 62: /* ExportsElement: Identifier  */
#line 809 "asn1p_y.y"
                     {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
#line 2541 "asn1p_y.c"
    break;

  case 63: /* ValueSet: '{' ElementSetSpecs '}'  */
#line 818 "asn1p_y.y"
                                  { (yyval.a_constr) = (yyvsp[-1].a_constr); }
#line 2547 "asn1p_y.c"
    break;

  case 64: /* ValueSetTypeAssignment: TypeRefName Type TOK_PPEQ ValueSet  */
#line 821 "asn1p_y.y"
                                           {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
	}
#line 2559 "asn1p_y.c"
    break;

  case 65: /* DefinedType: ComplexTypeReference  */
#line 841 "asn1p_y.y"
                             {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[0].a_ref);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
#line 2571 "asn1p_y.c"
    break;

  case 66: /* DefinedType: ComplexTypeReference '{' ActualParameterList '}'  */
#line 851 "asn1p_y.y"
                                                           {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[-3].a_ref);
		(yyval.a_expr)->rhs_pspecs = (yyvsp[-1].a_expr);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
#line 2584 "asn1p_y.c"
    break;

  case 67: /* DataTypeReference: TypeRefName TOK_PPEQ Type  */
#line 871 "asn1p_y.y"
                                  {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		assert((yyval.a_expr)->expr_type);
		assert((yyval.a_expr)->meta_type);
	}
#line 2595 "asn1p_y.c"
    break;

  case 68: /* DataTypeReference: TypeRefName TOK_PPEQ ObjectClass  */
#line 877 "asn1p_y.y"
                                           {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
#line 2606 "asn1p_y.c"
    break;

  case 69: /* DataTypeReference: TypeRefName '{' ParameterArgumentList '}' TOK_PPEQ Type  */
#line 893 "asn1p_y.y"
                                                                  {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-5].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[-3].a_plist);
	}
#line 2616 "asn1p_y.c"
    break;

  case 70: /* DataTypeReference: TypeRefName '{' ParameterArgumentList '}' TOK_PPEQ ObjectClass  */
#line 899 "asn1p_y.y"
                                                                         {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-5].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[-3].a_plist);
	}
#line 2626 "asn1p_y.c"
    break;

  case 71: /* ParameterArgumentList: ParameterArgumentName  */
#line 907 "asn1p_y.y"
                              {
		int ret;
		(yyval.a_plist) = asn1p_paramlist_new(yylineno);
		checkmem((yyval.a_plist));
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[0].a_parg).governor, (yyvsp[0].a_parg).argument);
		checkmem(ret == 0);
		asn1p_ref_free((yyvsp[0].a_parg).governor);
		free((yyvsp[0].a_parg).argument);
	}
#line 2640 "asn1p_y.c"
    break;

  case 72: /* ParameterArgumentList: ParameterArgumentList ',' ParameterArgumentName  */
#line 916 "asn1p_y.y"
                                                          {
		int ret;
		(yyval.a_plist) = (yyvsp[-2].a_plist);
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[0].a_parg).governor, (yyvsp[0].a_parg).argument);
		checkmem(ret == 0);
		asn1p_ref_free((yyvsp[0].a_parg).governor);
		free((yyvsp[0].a_parg).argument);
	}
#line 2653 "asn1p_y.c"
    break;

  case 73: /* ParameterArgumentName: TypeRefName  */
#line 927 "asn1p_y.y"
                    {
		(yyval.a_parg).governor = NULL;
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
#line 2662 "asn1p_y.c"
    break;

  case 74: /* ParameterArgumentName: TypeRefName ':' Identifier  */
#line 931 "asn1p_y.y"
                                     {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[-2].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
		free((yyvsp[-2].tv_str));
	}
#line 2675 "asn1p_y.c"
    break;

  case 75: /* ParameterArgumentName: TypeRefName ':' TypeRefName  */
#line 939 "asn1p_y.y"
                                      {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[-2].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
		free((yyvsp[-2].tv_str));
	}
#line 2688 "asn1p_y.c"
    break;

  case 76: /* ParameterArgumentName: BasicTypeId ':' Identifier  */
#line 947 "asn1p_y.y"
                                     {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor,
			ASN_EXPR_TYPE2STR((yyvsp[-2].a_type)), 1);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
#line 2701 "asn1p_y.c"
    break;

  case 77: /* ParameterArgumentName: BasicTypeId ':' TypeRefName  */
#line 955 "asn1p_y.y"
                                      {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor,
			ASN_EXPR_TYPE2STR((yyvsp[-2].a_type)), 1);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
#line 2714 "asn1p_y.c"
    break;

  case 78: /* ActualParameterList: ActualParameter  */
#line 966 "asn1p_y.y"
                        {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2724 "asn1p_y.c"
    break;

  case 79: /* ActualParameterList: ActualParameterList ',' ActualParameter  */
#line 971 "asn1p_y.y"
                                                  {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2733 "asn1p_y.c"
    break;

  case 81: /* ActualParameter: SimpleValue  */
#line 979 "asn1p_y.y"
                      {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("?");
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
#line 2746 "asn1p_y.c"
    break;

  case 82: /* ActualParameter: DefinedValue  */
#line 987 "asn1p_y.y"
                       {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("?");
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
#line 2759 "asn1p_y.c"
    break;

  case 83: /* ActualParameter: ValueSet  */
#line 995 "asn1p_y.y"
                   {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->expr_type = A1TC_VALUESET;
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
	}
#line 2770 "asn1p_y.c"
    break;

  case 84: /* optComponentTypeLists: %empty  */
#line 1018 "asn1p_y.y"
        { (yyval.a_expr) = NEW_EXPR(); }
#line 2776 "asn1p_y.c"
    break;

  case 85: /* optComponentTypeLists: ComponentTypeLists  */
#line 1019 "asn1p_y.y"
                             { (yyval.a_expr) = (yyvsp[0].a_expr); }
#line 2782 "asn1p_y.c"
    break;

  case 86: /* ComponentTypeLists: ComponentType  */
#line 1022 "asn1p_y.y"
                      {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2792 "asn1p_y.c"
    break;

  case 87: /* ComponentTypeLists: ComponentTypeLists ',' ComponentType  */
#line 1027 "asn1p_y.y"
                                               {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2801 "asn1p_y.c"
    break;

  case 88: /* ComponentTypeLists: ComponentTypeLists ',' TOK_VBracketLeft ComponentTypeLists TOK_VBracketRight  */
#line 1031 "asn1p_y.y"
                                                                                       {
		(yyval.a_expr) = (yyvsp[-4].a_expr);
		asn1p_expr_add_many((yyval.a_expr), (yyvsp[-1].a_expr));
		asn1p_expr_free((yyvsp[-1].a_expr));
	}
#line 2811 "asn1p_y.c"
    break;

  case 89: /* ComponentType: Identifier MaybeIndirectTaggedType optMarker  */
#line 1039 "asn1p_y.y"
                                                     {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyvsp[0].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 2823 "asn1p_y.c"
    break;

  case 90: /* ComponentType: MaybeIndirectTaggedType optMarker  */
#line 1046 "asn1p_y.y"
                                            {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		(yyvsp[0].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
#line 2834 "asn1p_y.c"
    break;

  case 91: /* ComponentType: TOK_COMPONENTS TOK_OF MaybeIndirectTaggedType  */
#line 1052 "asn1p_y.y"
                                                        {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->meta_type = (yyvsp[0].a_expr)->meta_type;
		(yyval.a_expr)->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2846 "asn1p_y.c"
    break;

  case 92: /* ComponentType: ExtensionAndException  */
#line 1059 "asn1p_y.y"
                                {
		(yyval.a_expr) = (yyvsp[0].a_expr);
	}
#line 2854 "asn1p_y.c"
    break;

  case 93: /* AlternativeTypeLists: AlternativeType  */
#line 1065 "asn1p_y.y"
                        {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2864 "asn1p_y.c"
    break;

  case 94: /* AlternativeTypeLists: AlternativeTypeLists ',' AlternativeType  */
#line 1070 "asn1p_y.y"
                                                   {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2873 "asn1p_y.c"
    break;

  case 95: /* AlternativeTypeLists: AlternativeTypeLists ',' TOK_VBracketLeft AlternativeTypeLists TOK_VBracketRight  */
#line 1074 "asn1p_y.y"
                                                                                           {
		(yyval.a_expr) = (yyvsp[-4].a_expr);
		asn1p_expr_add_many((yyval.a_expr), (yyvsp[-1].a_expr));
	}
#line 2882 "asn1p_y.c"
    break;

  case 96: /* AlternativeType: Identifier MaybeIndirectTaggedType  */
#line 1081 "asn1p_y.y"
                                           {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-1].tv_str);
	}
#line 2892 "asn1p_y.c"
    break;

  case 97: /* AlternativeType: ExtensionAndException  */
#line 1086 "asn1p_y.y"
                                {
		(yyval.a_expr) = (yyvsp[0].a_expr);
	}
#line 2900 "asn1p_y.c"
    break;

  case 98: /* AlternativeType: MaybeIndirectTaggedType  */
#line 1089 "asn1p_y.y"
                                  {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
#line 2909 "asn1p_y.c"
    break;

  case 99: /* ObjectClass: TOK_CLASS '{' FieldSpec '}' optWithSyntax  */
#line 1096 "asn1p_y.y"
                                                  {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->with_syntax = (yyvsp[0].a_wsynt);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
#line 2921 "asn1p_y.c"
    break;

  case 100: /* optUNIQUE: %empty  */
#line 1106 "asn1p_y.y"
        { (yyval.a_int) = 0; }
#line 2927 "asn1p_y.c"
    break;

  case 101: /* optUNIQUE: TOK_UNIQUE  */
#line 1107 "asn1p_y.y"
                     { (yyval.a_int) = 1; }
#line 2933 "asn1p_y.c"
    break;

  case 102: /* FieldSpec: ClassField  */
#line 1111 "asn1p_y.y"
                   {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_CLASSDEF;
		(yyval.a_expr)->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2945 "asn1p_y.c"
    break;

  case 103: /* FieldSpec: FieldSpec ',' ClassField  */
#line 1118 "asn1p_y.y"
                                   {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2954 "asn1p_y.c"
    break;

  case 104: /* ClassField: TOK_typefieldreference optMarker  */
#line 1128 "asn1p_y.y"
                                         {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-1].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_TFS;	/* TypeFieldSpec */
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 2967 "asn1p_y.c"
    break;

  case 105: /* ClassField: TOK_valuefieldreference Type optUNIQUE optMarker  */
#line 1138 "asn1p_y.y"
                                                           {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_FTVFS;	/* FixedTypeValueFieldSpec */
		(yyval.a_expr)->unique = (yyvsp[-1].a_int);
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
		asn1p_expr_add((yyval.a_expr), (yyvsp[-2].a_expr));
	}
#line 2981 "asn1p_y.c"
    break;

  case 106: /* ClassField: TOK_valuefieldreference FieldName optMarker  */
#line 1149 "asn1p_y.y"
                                                      {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVFS;
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 2994 "asn1p_y.c"
    break;

  case 107: /* ClassField: TOK_valuefieldreference DefinedObjectClass optMarker  */
#line 1159 "asn1p_y.y"
                                                               {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_OFS;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3008 "asn1p_y.c"
    break;

  case 108: /* ClassField: TOK_typefieldreference FieldName optMarker  */
#line 1170 "asn1p_y.y"
                                                     {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVSFS;
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3021 "asn1p_y.c"
    break;

  case 109: /* ClassField: TOK_typefieldreference Type optMarker  */
#line 1180 "asn1p_y.y"
                                                {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_FTVSFS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[-1].a_expr));
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3035 "asn1p_y.c"
    break;

  case 110: /* ClassField: TOK_typefieldreference DefinedObjectClass optMarker  */
#line 1191 "asn1p_y.y"
                                                              {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_OSFS;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3049 "asn1p_y.c"
    break;

  case 111: /* optWithSyntax: %empty  */
#line 1203 "asn1p_y.y"
        { (yyval.a_wsynt) = 0; }
#line 3055 "asn1p_y.c"
    break;

  case 112: /* optWithSyntax: WithSyntax  */
#line 1204 "asn1p_y.y"
                     {
		(yyval.a_wsynt) = (yyvsp[0].a_wsynt);
	}
#line 3063 "asn1p_y.c"
    break;

  case 113: /* $@3: %empty  */
#line 1211 "asn1p_y.y"
                { asn1p_lexer_hack_enable_with_syntax(); }
#line 3069 "asn1p_y.c"
    break;

  case 114: /* WithSyntax: TOK_WITH TOK_SYNTAX '{' $@3 WithSyntaxList '}'  */
#line 1213 "asn1p_y.y"
                    {
		(yyval.a_wsynt) = (yyvsp[-1].a_wsynt);
	}
#line 3077 "asn1p_y.c"
    break;

  case 115: /* WithSyntaxList: WithSyntaxToken  */
#line 1219 "asn1p_y.y"
                        {
		(yyval.a_wsynt) = asn1p_wsyntx_new();
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[0].a_wchunk), next);
	}
#line 3086 "asn1p_y.c"
    break;

  case 116: /* WithSyntaxList: WithSyntaxList WithSyntaxToken  */
#line 1223 "asn1p_y.y"
                                         {
		(yyval.a_wsynt) = (yyvsp[-1].a_wsynt);
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[0].a_wchunk), next);
	}
#line 3095 "asn1p_y.c"
    break;

  case 117: /* WithSyntaxToken: TOK_whitespace  */
#line 1230 "asn1p_y.y"
                       {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[0].tv_opaque).buf, 0);
		(yyval.a_wchunk)->type = WC_WHITESPACE;
	}
#line 3104 "asn1p_y.c"
    break;

  case 118: /* WithSyntaxToken: TOK_Literal  */
#line 1234 "asn1p_y.y"
                      {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[0].tv_str), 0);
	}
#line 3112 "asn1p_y.c"
    break;

  case 119: /* WithSyntaxToken: PrimitiveFieldReference  */
#line 1237 "asn1p_y.y"
                                  {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[0].a_refcomp).name, 0);
		(yyval.a_wchunk)->type = WC_FIELD;
	}
#line 3121 "asn1p_y.c"
    break;

  case 120: /* WithSyntaxToken: '[' WithSyntaxList ']'  */
#line 1241 "asn1p_y.y"
                                 {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromsyntax((yyvsp[-1].a_wsynt));
	}
#line 3129 "asn1p_y.c"
    break;

  case 121: /* ExtensionAndException: "..."  */
#line 1247 "asn1p_y.y"
                      {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3142 "asn1p_y.c"
    break;

  case 122: /* ExtensionAndException: "..." '!' DefinedValue  */
#line 1255 "asn1p_y.y"
                                         {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->value = (yyvsp[0].a_value);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3156 "asn1p_y.c"
    break;

  case 123: /* ExtensionAndException: "..." '!' SignedNumber  */
#line 1264 "asn1p_y.y"
                                         {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		(yyval.a_expr)->value = (yyvsp[0].a_value);
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3170 "asn1p_y.c"
    break;

  case 125: /* TaggedType: optTag UntaggedType  */
#line 1278 "asn1p_y.y"
                        {
        (yyval.a_expr) = (yyvsp[0].a_expr);
        (yyval.a_expr)->tag = (yyvsp[-1].a_tag);
    }
#line 3179 "asn1p_y.c"
    break;

  case 126: /* DefinedUntaggedType: DefinedType optManyConstraints  */
#line 1285 "asn1p_y.y"
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
#line 3204 "asn1p_y.c"
    break;

  case 127: /* UntaggedType: TypeDeclaration optManyConstraints  */
#line 1308 "asn1p_y.y"
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
#line 3229 "asn1p_y.c"
    break;

  case 128: /* MaybeIndirectTaggedType: optTag MaybeIndirectTypeDeclaration optManyConstraints  */
#line 1331 "asn1p_y.y"
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
#line 3255 "asn1p_y.c"
    break;

  case 129: /* NSTD_IndirectMarker: %empty  */
#line 1355 "asn1p_y.y"
        {
		(yyval.a_int) = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
#line 3264 "asn1p_y.c"
    break;

  case 130: /* MaybeIndirectTypeDeclaration: NSTD_IndirectMarker TypeDeclaration  */
#line 1362 "asn1p_y.y"
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
#line 3285 "asn1p_y.c"
    break;

  case 134: /* ConcreteTypeDeclaration: TOK_CHOICE '{' AlternativeTypeLists '}'  */
#line 1386 "asn1p_y.y"
                                                  {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_CHOICE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3296 "asn1p_y.c"
    break;

  case 135: /* ConcreteTypeDeclaration: TOK_SEQUENCE '{' optComponentTypeLists '}'  */
#line 1392 "asn1p_y.y"
                                                     {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3307 "asn1p_y.c"
    break;

  case 136: /* ConcreteTypeDeclaration: TOK_SET '{' optComponentTypeLists '}'  */
#line 1398 "asn1p_y.y"
                                                {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3318 "asn1p_y.c"
    break;

  case 137: /* ConcreteTypeDeclaration: TOK_SEQUENCE optSizeOrConstraint TOK_OF optIdentifier optTag MaybeIndirectTypeDeclaration  */
#line 1404 "asn1p_y.y"
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
#line 3333 "asn1p_y.c"
    break;

  case 138: /* ConcreteTypeDeclaration: TOK_SET optSizeOrConstraint TOK_OF optIdentifier optTag MaybeIndirectTypeDeclaration  */
#line 1414 "asn1p_y.y"
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
#line 3348 "asn1p_y.c"
    break;

  case 139: /* ConcreteTypeDeclaration: TOK_ANY  */
#line 1424 "asn1p_y.y"
                                                        {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3359 "asn1p_y.c"
    break;

  case 140: /* ConcreteTypeDeclaration: TOK_ANY TOK_DEFINED TOK_BY Identifier  */
#line 1430 "asn1p_y.y"
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
#line 3376 "asn1p_y.c"
    break;

  case 141: /* ConcreteTypeDeclaration: TOK_INSTANCE TOK_OF ComplexTypeReference  */
#line 1442 "asn1p_y.y"
                                                   {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[0].a_ref);
		(yyval.a_expr)->expr_type = A1TC_INSTANCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3388 "asn1p_y.c"
    break;

  case 142: /* ComplexTypeReference: TOK_typereference  */
#line 1457 "asn1p_y.y"
                          {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[0].tv_str));
	}
#line 3401 "asn1p_y.c"
    break;

  case 143: /* ComplexTypeReference: TOK_capitalreference  */
#line 1465 "asn1p_y.y"
                               {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_CAPITALS);
		free((yyvsp[0].tv_str));
		checkmem(ret == 0);
	}
#line 3414 "asn1p_y.c"
    break;

  case 144: /* ComplexTypeReference: TOK_typereference '.' TypeRefName  */
#line 1473 "asn1p_y.y"
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
#line 3430 "asn1p_y.c"
    break;

  case 145: /* ComplexTypeReference: TOK_capitalreference '.' TypeRefName  */
#line 1484 "asn1p_y.y"
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
#line 3446 "asn1p_y.c"
    break;

  case 146: /* ComplexTypeReference: TOK_capitalreference '.' ComplexTypeReferenceAmpList  */
#line 1495 "asn1p_y.y"
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
#line 3470 "asn1p_y.c"
    break;

  case 147: /* ComplexTypeReferenceAmpList: ComplexTypeReferenceElement  */
#line 1517 "asn1p_y.y"
                                    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].a_refcomp).name, (yyvsp[0].a_refcomp).lex_type);
		free((yyvsp[0].a_refcomp).name);
		checkmem(ret == 0);
	}
#line 3483 "asn1p_y.c"
    break;

  case 148: /* ComplexTypeReferenceAmpList: ComplexTypeReferenceAmpList '.' ComplexTypeReferenceElement  */
#line 1525 "asn1p_y.y"
                                                                      {
		int ret;
		(yyval.a_ref) = (yyvsp[-2].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].a_refcomp).name, (yyvsp[0].a_refcomp).lex_type);
		free((yyvsp[0].a_refcomp).name);
		checkmem(ret == 0);
	}
#line 3495 "asn1p_y.c"
    break;

  case 150: /* PrimitiveFieldReference: TOK_typefieldreference  */
#line 1538 "asn1p_y.y"
                               {
		(yyval.a_refcomp).lex_type = RLT_AmpUppercase;
		(yyval.a_refcomp).name = (yyvsp[0].tv_str);
	}
#line 3504 "asn1p_y.c"
    break;

  case 151: /* PrimitiveFieldReference: TOK_valuefieldreference  */
#line 1543 "asn1p_y.y"
                                  {
		(yyval.a_refcomp).lex_type = RLT_Amplowercase;
		(yyval.a_refcomp).name = (yyvsp[0].tv_str);
	}
#line 3513 "asn1p_y.c"
    break;

  case 152: /* FieldName: TOK_typefieldreference  */
#line 1552 "asn1p_y.y"
                               {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_AmpUppercase);
		free((yyvsp[0].tv_str));
	}
#line 3523 "asn1p_y.c"
    break;

  case 153: /* FieldName: FieldName '.' TOK_typefieldreference  */
#line 1557 "asn1p_y.y"
                                               {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_AmpUppercase);
		free((yyvsp[0].tv_str));
	}
#line 3533 "asn1p_y.c"
    break;

  case 154: /* FieldName: FieldName '.' TOK_valuefieldreference  */
#line 1562 "asn1p_y.y"
                                                {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_Amplowercase);
		free((yyvsp[0].tv_str));
	}
#line 3543 "asn1p_y.c"
    break;

  case 155: /* DefinedObjectClass: TOK_capitalreference  */
#line 1570 "asn1p_y.y"
                             {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_CAPITALS);
		free((yyvsp[0].tv_str));
	}
#line 3553 "asn1p_y.c"
    break;

  case 156: /* ValueAssignment: Identifier Type TOK_PPEQ Value  */
#line 1593 "asn1p_y.y"
                                       {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		assert((yyval.a_expr)->Identifier == NULL);
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
#line 3565 "asn1p_y.c"
    break;

  case 159: /* $@4: %empty  */
#line 1605 "asn1p_y.y"
              { asn1p_lexer_hack_push_opaque_state(); }
#line 3571 "asn1p_y.c"
    break;

  case 160: /* Value: '{' $@4 Opaque  */
#line 1605 "asn1p_y.y"
                                                               {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_UNPARSED;
	}
#line 3581 "asn1p_y.c"
    break;

  case 161: /* SimpleValue: TOK_NULL  */
#line 1613 "asn1p_y.y"
                 {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_NULL;
	}
#line 3591 "asn1p_y.c"
    break;

  case 162: /* SimpleValue: TOK_FALSE  */
#line 1618 "asn1p_y.y"
                    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
#line 3601 "asn1p_y.c"
    break;

  case 163: /* SimpleValue: TOK_TRUE  */
#line 1623 "asn1p_y.y"
                   {
		(yyval.a_value) = asn1p_value_fromint(1);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
#line 3611 "asn1p_y.c"
    break;

  case 169: /* DefinedValue: TypeRefName '.' Identifier  */
#line 1636 "asn1p_y.y"
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
#line 3630 "asn1p_y.c"
    break;

  case 170: /* RestrictedCharacterStringValue: TOK_cstring  */
#line 1654 "asn1p_y.y"
                    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem((yyval.a_value));
	}
#line 3639 "asn1p_y.c"
    break;

  case 171: /* RestrictedCharacterStringValue: TOK_tuple  */
#line 1658 "asn1p_y.y"
                    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TUPLE;
	}
#line 3649 "asn1p_y.c"
    break;

  case 172: /* RestrictedCharacterStringValue: TOK_quadruple  */
#line 1663 "asn1p_y.y"
                        {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_QUADRUPLE;
	}
#line 3659 "asn1p_y.c"
    break;

  case 173: /* Opaque: OpaqueFirstToken  */
#line 1671 "asn1p_y.y"
                     {
		(yyval.tv_opaque).len = (yyvsp[0].tv_opaque).len + 1;
		(yyval.tv_opaque).buf = malloc(1 + (yyval.tv_opaque).len + 1);
		checkmem((yyval.tv_opaque).buf);
		(yyval.tv_opaque).buf[0] = '{';
		memcpy((yyval.tv_opaque).buf + 1, (yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len);
		(yyval.tv_opaque).buf[(yyval.tv_opaque).len] = '\0';
		free((yyvsp[0].tv_opaque).buf);
    }
#line 3673 "asn1p_y.c"
    break;

  case 174: /* Opaque: Opaque TOK_opaque  */
#line 1680 "asn1p_y.y"
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
#line 3690 "asn1p_y.c"
    break;

  case 176: /* OpaqueFirstToken: Identifier  */
#line 1696 "asn1p_y.y"
                 {
        (yyval.tv_opaque).len = strlen((yyvsp[0].tv_str));
        (yyval.tv_opaque).buf = (yyvsp[0].tv_str);
    }
#line 3699 "asn1p_y.c"
    break;

  case 177: /* BasicTypeId: TOK_BOOLEAN  */
#line 1702 "asn1p_y.y"
                    { (yyval.a_type) = ASN_BASIC_BOOLEAN; }
#line 3705 "asn1p_y.c"
    break;

  case 178: /* BasicTypeId: TOK_NULL  */
#line 1703 "asn1p_y.y"
                   { (yyval.a_type) = ASN_BASIC_NULL; }
#line 3711 "asn1p_y.c"
    break;

  case 179: /* BasicTypeId: TOK_REAL  */
#line 1704 "asn1p_y.y"
                   { (yyval.a_type) = ASN_BASIC_REAL; }
#line 3717 "asn1p_y.c"
    break;

  case 180: /* BasicTypeId: TOK_OCTET TOK_STRING  */
#line 1705 "asn1p_y.y"
                               { (yyval.a_type) = ASN_BASIC_OCTET_STRING; }
#line 3723 "asn1p_y.c"
    break;

  case 181: /* BasicTypeId: TOK_OBJECT TOK_IDENTIFIER  */
#line 1706 "asn1p_y.y"
                                    { (yyval.a_type) = ASN_BASIC_OBJECT_IDENTIFIER; }
#line 3729 "asn1p_y.c"
    break;

  case 182: /* BasicTypeId: TOK_RELATIVE_OID  */
#line 1707 "asn1p_y.y"
                           { (yyval.a_type) = ASN_BASIC_RELATIVE_OID; }
#line 3735 "asn1p_y.c"
    break;

  case 183: /* BasicTypeId: TOK_EXTERNAL  */
#line 1708 "asn1p_y.y"
                       { (yyval.a_type) = ASN_BASIC_EXTERNAL; }
#line 3741 "asn1p_y.c"
    break;

  case 184: /* BasicTypeId: TOK_EMBEDDED TOK_PDV  */
#line 1709 "asn1p_y.y"
                               { (yyval.a_type) = ASN_BASIC_EMBEDDED_PDV; }
#line 3747 "asn1p_y.c"
    break;

  case 185: /* BasicTypeId: TOK_CHARACTER TOK_STRING  */
#line 1710 "asn1p_y.y"
                                   { (yyval.a_type) = ASN_BASIC_CHARACTER_STRING; }
#line 3753 "asn1p_y.c"
    break;

  case 186: /* BasicTypeId: TOK_UTCTime  */
#line 1711 "asn1p_y.y"
                      { (yyval.a_type) = ASN_BASIC_UTCTime; }
#line 3759 "asn1p_y.c"
    break;

  case 187: /* BasicTypeId: TOK_GeneralizedTime  */
#line 1712 "asn1p_y.y"
                              { (yyval.a_type) = ASN_BASIC_GeneralizedTime; }
#line 3765 "asn1p_y.c"
    break;

  case 190: /* BasicTypeId_UniverationCompatible: TOK_INTEGER  */
#line 1721 "asn1p_y.y"
                    { (yyval.a_type) = ASN_BASIC_INTEGER; }
#line 3771 "asn1p_y.c"
    break;

  case 191: /* BasicTypeId_UniverationCompatible: TOK_ENUMERATED  */
#line 1722 "asn1p_y.y"
                         { (yyval.a_type) = ASN_BASIC_ENUMERATED; }
#line 3777 "asn1p_y.c"
    break;

  case 192: /* BasicTypeId_UniverationCompatible: TOK_BIT TOK_STRING  */
#line 1723 "asn1p_y.y"
                             { (yyval.a_type) = ASN_BASIC_BIT_STRING; }
#line 3783 "asn1p_y.c"
    break;

  case 193: /* BuiltinType: BasicTypeId  */
#line 1727 "asn1p_y.y"
                    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = (yyvsp[0].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3794 "asn1p_y.c"
    break;

  case 194: /* BuiltinType: TOK_INTEGER '{' NamedNumberList '}'  */
#line 1733 "asn1p_y.y"
                                          {
        (yyval.a_expr) = (yyvsp[-1].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_INTEGER;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3804 "asn1p_y.c"
    break;

  case 195: /* BuiltinType: TOK_ENUMERATED '{' Enumerations '}'  */
#line 1738 "asn1p_y.y"
                                          {
        (yyval.a_expr) = (yyvsp[-1].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_ENUMERATED;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3814 "asn1p_y.c"
    break;

  case 196: /* BuiltinType: TOK_BIT TOK_STRING '{' NamedBitList '}'  */
#line 1743 "asn1p_y.y"
                                              {
        (yyval.a_expr) = (yyvsp[-1].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3824 "asn1p_y.c"
    break;

  case 197: /* BuiltinType: TOK_ExtValue_BIT_STRING '{' IdentifierList '}'  */
#line 1748 "asn1p_y.y"
                                                     {
        (yyval.a_expr) = (yyvsp[-1].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3834 "asn1p_y.c"
    break;

  case 198: /* BuiltinType: TOK_ExtValue_BIT_STRING '{' '}'  */
#line 1753 "asn1p_y.y"
                                      {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3845 "asn1p_y.c"
    break;

  case 199: /* BasicString: TOK_BMPString  */
#line 1762 "asn1p_y.y"
                      { (yyval.a_type) = ASN_STRING_BMPString; }
#line 3851 "asn1p_y.c"
    break;

  case 200: /* BasicString: TOK_GeneralString  */
#line 1763 "asn1p_y.y"
                            {
		(yyval.a_type) = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
#line 3860 "asn1p_y.c"
    break;

  case 201: /* BasicString: TOK_GraphicString  */
#line 1767 "asn1p_y.y"
                            {
		(yyval.a_type) = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
#line 3869 "asn1p_y.c"
    break;

  case 202: /* BasicString: TOK_IA5String  */
#line 1771 "asn1p_y.y"
                        { (yyval.a_type) = ASN_STRING_IA5String; }
#line 3875 "asn1p_y.c"
    break;

  case 203: /* BasicString: TOK_ISO646String  */
#line 1772 "asn1p_y.y"
                           { (yyval.a_type) = ASN_STRING_ISO646String; }
#line 3881 "asn1p_y.c"
    break;

  case 204: /* BasicString: TOK_NumericString  */
#line 1773 "asn1p_y.y"
                            { (yyval.a_type) = ASN_STRING_NumericString; }
#line 3887 "asn1p_y.c"
    break;

  case 205: /* BasicString: TOK_PrintableString  */
#line 1774 "asn1p_y.y"
                              { (yyval.a_type) = ASN_STRING_PrintableString; }
#line 3893 "asn1p_y.c"
    break;

  case 206: /* BasicString: TOK_T61String  */
#line 1775 "asn1p_y.y"
                        {
		(yyval.a_type) = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
#line 3902 "asn1p_y.c"
    break;

  case 207: /* BasicString: TOK_TeletexString  */
#line 1779 "asn1p_y.y"
                            { (yyval.a_type) = ASN_STRING_TeletexString; }
#line 3908 "asn1p_y.c"
    break;

  case 208: /* BasicString: TOK_UniversalString  */
#line 1780 "asn1p_y.y"
                              { (yyval.a_type) = ASN_STRING_UniversalString; }
#line 3914 "asn1p_y.c"
    break;

  case 209: /* BasicString: TOK_UTF8String  */
#line 1781 "asn1p_y.y"
                         { (yyval.a_type) = ASN_STRING_UTF8String; }
#line 3920 "asn1p_y.c"
    break;

  case 210: /* BasicString: TOK_VideotexString  */
#line 1782 "asn1p_y.y"
                             {
		(yyval.a_type) = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
#line 3929 "asn1p_y.c"
    break;

  case 211: /* BasicString: TOK_VisibleString  */
#line 1786 "asn1p_y.y"
                            { (yyval.a_type) = ASN_STRING_VisibleString; }
#line 3935 "asn1p_y.c"
    break;

  case 212: /* BasicString: TOK_ObjectDescriptor  */
#line 1787 "asn1p_y.y"
                               { (yyval.a_type) = ASN_STRING_ObjectDescriptor; }
#line 3941 "asn1p_y.c"
    break;

  case 217: /* optConstraint: %empty  */
#line 1799 "asn1p_y.y"
        { (yyval.a_constr) = 0; }
#line 3947 "asn1p_y.c"
    break;

  case 219: /* optManyConstraints: %empty  */
#line 1804 "asn1p_y.y"
        { (yyval.a_constr) = 0; }
#line 3953 "asn1p_y.c"
    break;

  case 221: /* optSizeOrConstraint: %empty  */
#line 1809 "asn1p_y.y"
        { (yyval.a_constr) = 0; }
#line 3959 "asn1p_y.c"
    break;

  case 224: /* Constraint: '(' ConstraintSpec ')'  */
#line 1815 "asn1p_y.y"
                           {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[-1].a_constr), 0);
    }
#line 3967 "asn1p_y.c"
    break;

  case 226: /* ManyConstraints: ManyConstraints Constraint  */
#line 1822 "asn1p_y.y"
                                     {
        if((yyvsp[0].a_constr)->type == ACT_CA_SET && (yyvsp[0].a_constr)->el_count == 1) {
            CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[-1].a_constr), (yyvsp[0].a_constr)->elements[0]);
        } else {
            CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[-1].a_constr), (yyvsp[0].a_constr));
        }
	}
#line 3979 "asn1p_y.c"
    break;

  case 230: /* ElementSetSpecs: "..."  */
#line 1836 "asn1p_y.y"
                       {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_EL_EXT;
	}
#line 3988 "asn1p_y.c"
    break;

  case 232: /* ElementSetSpecs: ElementSetSpec ',' "..."  */
#line 1841 "asn1p_y.y"
                                      {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[-2].a_constr), ct);
   }
#line 3999 "asn1p_y.c"
    break;

  case 233: /* ElementSetSpecs: ElementSetSpec ',' "..." ',' ElementSetSpec  */
#line 1847 "asn1p_y.y"
                                                         {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[-4].a_constr), ct);
       ct = (yyval.a_constr);
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, ct, (yyvsp[0].a_constr));
   }
#line 4012 "asn1p_y.c"
    break;

  case 235: /* ElementSetSpec: TOK_ALL TOK_EXCEPT Elements  */
#line 1859 "asn1p_y.y"
                                      {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_AEX, (yyvsp[0].a_constr), 0);
	}
#line 4020 "asn1p_y.c"
    break;

  case 237: /* Unions: Unions UnionMark Intersections  */
#line 1866 "asn1p_y.y"
                                         {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_UNI, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
#line 4028 "asn1p_y.c"
    break;

  case 239: /* Intersections: Intersections IntersectionMark IntersectionElements  */
#line 1873 "asn1p_y.y"
                                                               {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_INT, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
#line 4036 "asn1p_y.c"
    break;

  case 241: /* IntersectionElements: Elements TOK_EXCEPT Elements  */
#line 1881 "asn1p_y.y"
                                       {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_EXC, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
#line 4044 "asn1p_y.c"
    break;

  case 243: /* Elements: '(' ElementSetSpec ')'  */
#line 1888 "asn1p_y.y"
                             {
        int ret;
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_CA_SET;
        ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[-1].a_constr));
        checkmem(ret == 0);
    }
#line 4057 "asn1p_y.c"
    break;

  case 244: /* SubtypeElements: SingleValue  */
#line 1899 "asn1p_y.y"
                    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = (yyvsp[0].a_value);
	}
#line 4068 "asn1p_y.c"
    break;

  case 245: /* SubtypeElements: ContainedSubtype  */
#line 1905 "asn1p_y.y"
                           {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_TYPE;
		(yyval.a_constr)->containedSubtype = (yyvsp[0].a_value);
	}
#line 4079 "asn1p_y.c"
    break;

  case 251: /* PermittedAlphabet: TOK_FROM Constraint  */
#line 1921 "asn1p_y.y"
                            {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_FROM, (yyvsp[0].a_constr), 0);
	}
#line 4087 "asn1p_y.c"
    break;

  case 252: /* SizeConstraint: TOK_SIZE Constraint  */
#line 1926 "asn1p_y.y"
                            {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_SIZE, (yyvsp[0].a_constr), 0);
	}
#line 4095 "asn1p_y.c"
    break;

  case 253: /* PatternConstraint: TOK_PATTERN TOK_cstring  */
#line 1931 "asn1p_y.y"
                                {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
	}
#line 4105 "asn1p_y.c"
    break;

  case 254: /* PatternConstraint: TOK_PATTERN Identifier  */
#line 1936 "asn1p_y.y"
                                 {
		asn1p_ref_t *ref;
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		ref = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component(ref, (yyvsp[0].tv_str), RLT_lowercase);
		(yyval.a_constr)->value = asn1p_value_fromref(ref, 0);
		free((yyvsp[0].tv_str));
	}
#line 4119 "asn1p_y.c"
    break;

  case 255: /* ValueRange: LowerEndValue ConstraintRangeSpec UpperEndValue  */
#line 1948 "asn1p_y.y"
                                                    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[-1].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[-2].a_value);
		(yyval.a_constr)->range_stop = (yyvsp[0].a_value);
    }
#line 4131 "asn1p_y.c"
    break;

  case 257: /* LowerEndValue: TOK_MIN  */
#line 1958 "asn1p_y.y"
              {
		(yyval.a_value) = asn1p_value_fromint(-123);
		(yyval.a_value)->type = ATV_MIN;
    }
#line 4140 "asn1p_y.c"
    break;

  case 259: /* UpperEndValue: TOK_MAX  */
#line 1965 "asn1p_y.y"
              {
		(yyval.a_value) = asn1p_value_fromint(321);
		(yyval.a_value)->type = ATV_MAX;
    }
#line 4149 "asn1p_y.c"
    break;

  case 261: /* BitStringValue: TOK_bstring  */
#line 1973 "asn1p_y.y"
                    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[0].tv_str), 'B');
		checkmem((yyval.a_value));
		free((yyvsp[0].tv_str));
	}
#line 4159 "asn1p_y.c"
    break;

  case 262: /* BitStringValue: TOK_hstring  */
#line 1978 "asn1p_y.y"
                      {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[0].tv_str), 'H');
		checkmem((yyval.a_value));
		free((yyvsp[0].tv_str));
	}
#line 4169 "asn1p_y.c"
    break;

  case 263: /* ContainedSubtype: TOK_INCLUDES Type  */
#line 1986 "asn1p_y.y"
                      {
		(yyval.a_value) = asn1p_value_fromtype((yyvsp[0].a_expr));
		checkmem((yyval.a_value));
		asn1p_expr_free((yyvsp[0].a_expr));
    }
#line 4179 "asn1p_y.c"
    break;

  case 264: /* ContainedSubtype: DefinedUntaggedType  */
#line 1992 "asn1p_y.y"
                          {
		(yyval.a_value) = asn1p_value_fromtype((yyvsp[0].a_expr));
		checkmem((yyval.a_value));
		asn1p_expr_free((yyvsp[0].a_expr));
    }
#line 4189 "asn1p_y.c"
    break;

  case 265: /* InnerTypeConstraints: TOK_WITH TOK_COMPONENT SingleTypeConstraint  */
#line 2004 "asn1p_y.y"
                                                    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMP, (yyvsp[0].a_constr), 0);
	}
#line 4197 "asn1p_y.c"
    break;

  case 266: /* InnerTypeConstraints: TOK_WITH TOK_COMPONENTS MultipleTypeConstraints  */
#line 2007 "asn1p_y.y"
                                                          {
        assert((yyvsp[0].a_constr)->type == ACT_CA_CSV);
        (yyvsp[0].a_constr)->type = ACT_CT_WCOMPS;
        (yyval.a_constr) = (yyvsp[0].a_constr);
	}
#line 4207 "asn1p_y.c"
    break;

  case 270: /* FullSpecification: '{' TypeConstraints '}'  */
#line 2015 "asn1p_y.y"
                                           { (yyval.a_constr) = (yyvsp[-1].a_constr); }
#line 4213 "asn1p_y.c"
    break;

  case 271: /* PartialSpecification: '{' "..." ',' TypeConstraints '}'  */
#line 2017 "asn1p_y.y"
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
#line 4230 "asn1p_y.c"
    break;

  case 272: /* TypeConstraints: NamedConstraint  */
#line 2030 "asn1p_y.y"
                    {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        (yyval.a_constr)->type = ACT_CA_CSV;
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[0].a_constr));
    }
#line 4240 "asn1p_y.c"
    break;

  case 273: /* TypeConstraints: TypeConstraints ',' NamedConstraint  */
#line 2035 "asn1p_y.y"
                                          {
        (yyval.a_constr) = (yyvsp[-2].a_constr);
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[0].a_constr));
	}
#line 4249 "asn1p_y.c"
    break;

  case 274: /* NamedConstraint: IdentifierAsValue optConstraint optPresenceConstraint  */
#line 2041 "asn1p_y.y"
                                                              {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_EL_VALUE;
        (yyval.a_constr)->value = (yyvsp[-2].a_value);
        if((yyvsp[-1].a_constr)) asn1p_constraint_insert((yyval.a_constr), (yyvsp[-1].a_constr));
        (yyval.a_constr)->presence = (yyvsp[0].a_pres);
    }
#line 4262 "asn1p_y.c"
    break;

  case 275: /* optPresenceConstraint: %empty  */
#line 2055 "asn1p_y.y"
        { (yyval.a_pres) = ACPRES_DEFAULT; }
#line 4268 "asn1p_y.c"
    break;

  case 276: /* optPresenceConstraint: PresenceConstraint  */
#line 2056 "asn1p_y.y"
                             { (yyval.a_pres) = (yyvsp[0].a_pres); }
#line 4274 "asn1p_y.c"
    break;

  case 277: /* PresenceConstraint: TOK_PRESENT  */
#line 2060 "asn1p_y.y"
                    {
		(yyval.a_pres) = ACPRES_PRESENT;
	}
#line 4282 "asn1p_y.c"
    break;

  case 278: /* PresenceConstraint: TOK_ABSENT  */
#line 2063 "asn1p_y.y"
                     {
		(yyval.a_pres) = ACPRES_ABSENT;
	}
#line 4290 "asn1p_y.c"
    break;

  case 279: /* PresenceConstraint: TOK_OPTIONAL  */
#line 2066 "asn1p_y.y"
                       {
		(yyval.a_pres) = ACPRES_OPTIONAL;
	}
#line 4298 "asn1p_y.c"
    break;

  case 283: /* $@5: %empty  */
#line 2081 "asn1p_y.y"
                { asn1p_lexer_hack_push_opaque_state(); }
#line 4304 "asn1p_y.c"
    break;

  case 284: /* UserDefinedConstraint: TOK_CONSTRAINED TOK_BY '{' $@5 Opaque  */
#line 2081 "asn1p_y.y"
                                                                           {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CT_CTDBY;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem((yyval.a_constr)->value);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
#line 4317 "asn1p_y.c"
    break;

  case 285: /* ContentsConstraint: TOK_CONTAINING Type  */
#line 2092 "asn1p_y.y"
                            {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_CTNG;
		(yyval.a_constr)->value = asn1p_value_fromtype((yyvsp[0].a_expr));
		asn1p_expr_free((yyvsp[0].a_expr));
	}
#line 4328 "asn1p_y.c"
    break;

  case 286: /* ConstraintRangeSpec: ".."  */
#line 2101 "asn1p_y.y"
                                { (yyval.a_ctype) = ACT_EL_RANGE; }
#line 4334 "asn1p_y.c"
    break;

  case 287: /* ConstraintRangeSpec: ".." '<'  */
#line 2102 "asn1p_y.y"
                                { (yyval.a_ctype) = ACT_EL_RLRANGE; }
#line 4340 "asn1p_y.c"
    break;

  case 288: /* ConstraintRangeSpec: '<' ".."  */
#line 2103 "asn1p_y.y"
                                { (yyval.a_ctype) = ACT_EL_LLRANGE; }
#line 4346 "asn1p_y.c"
    break;

  case 289: /* ConstraintRangeSpec: '<' ".." '<'  */
#line 2104 "asn1p_y.y"
                                { (yyval.a_ctype) = ACT_EL_ULRANGE; }
#line 4352 "asn1p_y.c"
    break;

  case 290: /* TableConstraint: SimpleTableConstraint  */
#line 2107 "asn1p_y.y"
                              {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
#line 4360 "asn1p_y.c"
    break;

  case 291: /* TableConstraint: ComponentRelationConstraint  */
#line 2110 "asn1p_y.y"
                                      {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
#line 4368 "asn1p_y.c"
    break;

  case 292: /* SimpleTableConstraint: '{' TypeRefName '}'  */
#line 2119 "asn1p_y.y"
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
#line 4386 "asn1p_y.c"
    break;

  case 293: /* ComponentRelationConstraint: SimpleTableConstraint '{' AtNotationList '}'  */
#line 2135 "asn1p_y.y"
                                                     {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, (yyvsp[-3].a_constr), (yyvsp[-1].a_constr));
	}
#line 4394 "asn1p_y.c"
    break;

  case 294: /* AtNotationList: AtNotationElement  */
#line 2141 "asn1p_y.y"
                          {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_fromref((yyvsp[0].a_ref), 0);
	}
#line 4405 "asn1p_y.c"
    break;

  case 295: /* AtNotationList: AtNotationList ',' AtNotationElement  */
#line 2147 "asn1p_y.y"
                                               {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref((yyvsp[0].a_ref), 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[-2].a_constr), ct);
	}
#line 4418 "asn1p_y.c"
    break;

  case 296: /* AtNotationElement: '@' ComponentIdList  */
#line 2161 "asn1p_y.y"
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
#line 4434 "asn1p_y.c"
    break;

  case 297: /* AtNotationElement: '@' '.' ComponentIdList  */
#line 2172 "asn1p_y.y"
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
#line 4451 "asn1p_y.c"
    break;

  case 298: /* ComponentIdList: Identifier  */
#line 2188 "asn1p_y.y"
                   {
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4459 "asn1p_y.c"
    break;

  case 299: /* ComponentIdList: ComponentIdList '.' Identifier  */
#line 2191 "asn1p_y.y"
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
#line 4475 "asn1p_y.c"
    break;

  case 300: /* optMarker: %empty  */
#line 2211 "asn1p_y.y"
        {
		(yyval.a_marker).flags = EM_NOMARK;
		(yyval.a_marker).default_value = 0;
	}
#line 4484 "asn1p_y.c"
    break;

  case 301: /* optMarker: Marker  */
#line 2215 "asn1p_y.y"
                 { (yyval.a_marker) = (yyvsp[0].a_marker); }
#line 4490 "asn1p_y.c"
    break;

  case 302: /* Marker: TOK_OPTIONAL  */
#line 2219 "asn1p_y.y"
                     {
		(yyval.a_marker).flags = EM_OPTIONAL | EM_INDIRECT;
		(yyval.a_marker).default_value = 0;
	}
#line 4499 "asn1p_y.c"
    break;

  case 303: /* Marker: TOK_DEFAULT Value  */
#line 2223 "asn1p_y.y"
                            {
		(yyval.a_marker).flags = EM_DEFAULT;
		(yyval.a_marker).default_value = (yyvsp[0].a_value);
	}
#line 4508 "asn1p_y.c"
    break;

  case 304: /* IdentifierList: IdentifierElement  */
#line 2230 "asn1p_y.y"
                      {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
    }
#line 4518 "asn1p_y.c"
    break;

  case 305: /* IdentifierList: IdentifierList ',' IdentifierElement  */
#line 2235 "asn1p_y.y"
                                           {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
    }
#line 4527 "asn1p_y.c"
    break;

  case 306: /* IdentifierElement: Identifier  */
#line 2241 "asn1p_y.y"
               {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
    }
#line 4539 "asn1p_y.c"
    break;

  case 307: /* NamedNumberList: NamedNumber  */
#line 2250 "asn1p_y.y"
                    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4549 "asn1p_y.c"
    break;

  case 308: /* NamedNumberList: NamedNumberList ',' NamedNumber  */
#line 2255 "asn1p_y.y"
                                          {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4558 "asn1p_y.c"
    break;

  case 309: /* NamedNumber: Identifier '(' SignedNumber ')'  */
#line 2262 "asn1p_y.y"
                                        {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4571 "asn1p_y.c"
    break;

  case 310: /* NamedNumber: Identifier '(' DefinedValue ')'  */
#line 2270 "asn1p_y.y"
                                          {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4584 "asn1p_y.c"
    break;

  case 311: /* NamedBitList: NamedBit  */
#line 2280 "asn1p_y.y"
                 {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4594 "asn1p_y.c"
    break;

  case 312: /* NamedBitList: NamedBitList ',' NamedBit  */
#line 2285 "asn1p_y.y"
                                    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4603 "asn1p_y.c"
    break;

  case 313: /* NamedBit: Identifier '(' "number" ')'  */
#line 2292 "asn1p_y.y"
                                      {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = asn1p_value_fromint((yyvsp[-1].a_int));
	}
#line 4616 "asn1p_y.c"
    break;

  case 314: /* NamedBit: Identifier '(' DefinedValue ')'  */
#line 2300 "asn1p_y.y"
                                          {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4629 "asn1p_y.c"
    break;

  case 315: /* Enumerations: UniverationList  */
#line 2310 "asn1p_y.y"
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
#line 4647 "asn1p_y.c"
    break;

  case 316: /* UniverationList: UniverationElement  */
#line 2325 "asn1p_y.y"
                           {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4657 "asn1p_y.c"
    break;

  case 317: /* UniverationList: UniverationList ',' UniverationElement  */
#line 2330 "asn1p_y.y"
                                                 {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4666 "asn1p_y.c"
    break;

  case 318: /* UniverationElement: Identifier  */
#line 2337 "asn1p_y.y"
                   {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
	}
#line 4678 "asn1p_y.c"
    break;

  case 319: /* UniverationElement: Identifier '(' SignedNumber ')'  */
#line 2344 "asn1p_y.y"
                                          {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4691 "asn1p_y.c"
    break;

  case 320: /* UniverationElement: Identifier '(' DefinedValue ')'  */
#line 2352 "asn1p_y.y"
                                          {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4704 "asn1p_y.c"
    break;

  case 321: /* UniverationElement: SignedNumber  */
#line 2360 "asn1p_y.y"
                       {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
#line 4716 "asn1p_y.c"
    break;

  case 322: /* UniverationElement: "..."  */
#line 2367 "asn1p_y.y"
                        {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
	}
#line 4729 "asn1p_y.c"
    break;

  case 323: /* SignedNumber: "number"  */
#line 2378 "asn1p_y.y"
                   {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
	}
#line 4738 "asn1p_y.c"
    break;

  case 324: /* SignedNumber: "negative number"  */
#line 2382 "asn1p_y.y"
                              {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
	}
#line 4747 "asn1p_y.c"
    break;

  case 325: /* RealValue: TOK_realnumber  */
#line 2389 "asn1p_y.y"
                       {
		(yyval.a_value) = asn1p_value_fromdouble((yyvsp[0].a_dbl));
		checkmem((yyval.a_value));
	}
#line 4756 "asn1p_y.c"
    break;

  case 326: /* optTag: %empty  */
#line 2420 "asn1p_y.y"
        { memset(&(yyval.a_tag), 0, sizeof((yyval.a_tag))); }
#line 4762 "asn1p_y.c"
    break;

  case 327: /* optTag: Tag  */
#line 2421 "asn1p_y.y"
              { (yyval.a_tag) = (yyvsp[0].a_tag); }
#line 4768 "asn1p_y.c"
    break;

  case 328: /* Tag: TagTypeValue TagPlicit  */
#line 2425 "asn1p_y.y"
                               {
		(yyval.a_tag) = (yyvsp[-1].a_tag);
		(yyval.a_tag).tag_mode = (yyvsp[0].a_tag).tag_mode;
	}
#line 4777 "asn1p_y.c"
    break;

  case 329: /* TagTypeValue: '[' TagClass "number" ']'  */
#line 2432 "asn1p_y.y"
                                    {
		(yyval.a_tag) = (yyvsp[-2].a_tag);
		(yyval.a_tag).tag_value = (yyvsp[-1].a_int);
	}
#line 4786 "asn1p_y.c"
    break;

  case 330: /* TagClass: %empty  */
#line 2438 "asn1p_y.y"
        { (yyval.a_tag).tag_class = TC_CONTEXT_SPECIFIC; }
#line 4792 "asn1p_y.c"
    break;

  case 331: /* TagClass: TOK_UNIVERSAL  */
#line 2439 "asn1p_y.y"
                        { (yyval.a_tag).tag_class = TC_UNIVERSAL; }
#line 4798 "asn1p_y.c"
    break;

  case 332: /* TagClass: TOK_APPLICATION  */
#line 2440 "asn1p_y.y"
                          { (yyval.a_tag).tag_class = TC_APPLICATION; }
#line 4804 "asn1p_y.c"
    break;

  case 333: /* TagClass: TOK_PRIVATE  */
#line 2441 "asn1p_y.y"
                      { (yyval.a_tag).tag_class = TC_PRIVATE; }
#line 4810 "asn1p_y.c"
    break;

  case 334: /* TagPlicit: %empty  */
#line 2445 "asn1p_y.y"
        { (yyval.a_tag).tag_mode = TM_DEFAULT; }
#line 4816 "asn1p_y.c"
    break;

  case 335: /* TagPlicit: TOK_IMPLICIT  */
#line 2446 "asn1p_y.y"
                       { (yyval.a_tag).tag_mode = TM_IMPLICIT; }
#line 4822 "asn1p_y.c"
    break;

  case 336: /* TagPlicit: TOK_EXPLICIT  */
#line 2447 "asn1p_y.y"
                       { (yyval.a_tag).tag_mode = TM_EXPLICIT; }
#line 4828 "asn1p_y.c"
    break;

  case 337: /* TypeRefName: TOK_typereference  */
#line 2451 "asn1p_y.y"
                          {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4837 "asn1p_y.c"
    break;

  case 338: /* TypeRefName: TOK_capitalreference  */
#line 2455 "asn1p_y.y"
                               {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4846 "asn1p_y.c"
    break;

  case 339: /* optIdentifier: %empty  */
#line 2463 "asn1p_y.y"
        { (yyval.tv_str) = 0; }
#line 4852 "asn1p_y.c"
    break;

  case 340: /* optIdentifier: Identifier  */
#line 2464 "asn1p_y.y"
                     {
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4860 "asn1p_y.c"
    break;

  case 341: /* Identifier: "identifier"  */
#line 2470 "asn1p_y.y"
                       {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4869 "asn1p_y.c"
    break;

  case 342: /* IdentifierAsReference: Identifier  */
#line 2477 "asn1p_y.y"
               {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_lowercase);
		free((yyvsp[0].tv_str));
    }
#line 4879 "asn1p_y.c"
    break;

  case 343: /* IdentifierAsValue: IdentifierAsReference  */
#line 2484 "asn1p_y.y"
                          {
		(yyval.a_value) = asn1p_value_fromref((yyvsp[0].a_ref), 0);
    }
#line 4887 "asn1p_y.c"
    break;


#line 4891 "asn1p_y.c"

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

#line 2488 "asn1p_y.y"



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

