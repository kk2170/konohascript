#define PKGInt_to(T, I)   ((T) sfp[I].ivalue)
#define PKGFloat_to(T, I) ((T) sfp[I].fvalue)
#define PKGString_to(T, I) ((T) S_totext(sfp[I].s))
#define PKGArray_to(T, I)  ((T) sfp[I].a); assert(0)
#define PKGFArray_to(T, I)  ((T) sfp[I].a); assert(0)
#define PKGIArray_to(T, I)  ((T) sfp[I].a); assert(0)
#define PKGRawPtr_to(T, I) ((T) sfp[I].p->rawptr)
#define PKG_Error_to(T, I) ((T)0); assert(0)
#define RETURN_error(V) ((void)V); assert(0)
#define WRAP(p) ((void*)p)
