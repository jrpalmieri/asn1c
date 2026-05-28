#ifndef	ASN1C_SAVE_H
#define	ASN1C_SAVE_H

/* Forward declaration — full definition is in asn1c_internal.h */
typedef struct arg_s arg_t;

int asn1c_save_compiled_output(arg_t *arg, const char *datadir, const char* destdir,
	int argc, int optc, char **argv);

/*
 * Configure a common directory for skeleton/support files.
 * name:    subdirectory name (e.g. "asn1c"); defaults to "asn1c" if NULL/empty.
 * destdir: the -D output directory (must be set, with trailing '/').
 * The common dir is placed as a sibling of destdir's parent.
 * Must be called before asn1c_save_compiled_output().
 */
int asn1c_set_common_dir(const char *name, const char *destdir);

/*
 * Return the relative #include prefix for common/skeleton headers
 * (e.g. "../../asn1c/"), or NULL if -fcommon was not used.
 */
const char *asn1c_get_common_include_prefix(void);

/*
 * Return a quoted or angle-bracket include string for a skeleton file.
 * When -fcommon is active returns "../../asn1c/name.h"; otherwise falls
 * back to "name.h" (quoted) or <name.h> (angle).
 */
const char *asn1c_skeleton_include_str(const char *name, int quoted);

#endif	/* ASN1C_SAVE_H */
