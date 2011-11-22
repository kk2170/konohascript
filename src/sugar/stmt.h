/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved..
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/* ************************************************************************ */

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif


/* ------------------------------------------------------------------------ */


#define Expr_setConst(ctx, expr, data)  Expr_setConst_(ctx, expr, UPCAST(data))
static knh_Expr_t *Expr_setConst_(CTX ctx, knh_Expr_t *expr, knh_Object_t *data)
{
	expr->expr = TEXPR_CONST;
	KNH_SETv(ctx, expr->data, data);
	expr->type = O_cid(data);
	return expr;
}

static knh_Expr_t* Expr_typeCheck(CTX ctx, knh_Expr_t *expr, knh_Gamma_t *gma, knh_class_t reqt);

static knh_Object_t *Expr_getConst(CTX ctx, knh_Expr_t *expr, knh_class_t cid)
{
	if(Expr_typeCheck(ctx, expr, NULL, cid)) {
		if(expr->expr == TEXPR_CONST) {
			return expr->data;
		}
	}
	return NULL;
}

/* ------------------------------------------------------------------------ */

#define Stmt_getTokenNULL(ctx, stmt, T)          Stmt_getTokenNULL_(ctx, stmt, STEXT(T))
#define Stmt_getConst(ctx, stmt, T, cid)         Stmt_getConst_(ctx, stmt, STEXT(T), cid)
#define Stmt_getint(ctx, stmt, T, n)                Stmt_getint_(ctx, stmt, STEXT(T), n)

#define Stmt_getBlock(ctx, stmt, T)              Stmt_getBlock_(ctx, stmt, STEXT(T))

#define Stmt_getcid(ctx, stmt, T, ns, defcid)    Stmt_getcid_(ctx, stmt, STEXT(T), ns, defcid)
#define Stmt_gettype(ctx, stmt, T, ns, defcid)   Stmt_getcid_(ctx, stmt, STEXT(T), ns, defcid)
#define Stmt_getmn(ctx, stmt, T, def)            Stmt_getmn_(ctx, stmt, STEXT(T), def)
#define Stmt_getfn(ctx, stmt, T, def)            Stmt_getfn_(ctx, stmt, STEXT(T), def)
#define Stmt_uline(stmt)  stmt->uline
#define Stmt_done(ctx, stmt)  KNH_SETv(ctx, stmt->parent, KNH_NULL);

#define AKEY(T)   T, sizeof(T)

typedef struct flagop_t {
	const char *key;
	size_t keysize;
	knh_flag_t flag;
} flagop_t ;

static knh_flag_t Stmt_flag(CTX ctx, knh_Stmt_t *stmt, flagop_t *fop, knh_flag_t flag)
{
	while(fop->key != NULL) {
		knh_bytes_t n = {{fop->key}, fop->keysize};
		knh_Object_t *op = knh_DictMap_getNULL(ctx, stmt->clauseDictMap, n);
		if(op != NULL) flag |= fop->flag;
	}
	return flag;
}

static knh_Object_t* Stmt_getConst_(CTX ctx, knh_Stmt_t *stmt, knh_bytes_t name, knh_class_t cid)
{
	knh_Object_t *term = knh_DictMap_getNULL(ctx, stmt->clauseDictMap, name);
	if(term != NULL && IS_Expr(term)) {
		return Expr_getConst(ctx, (knh_Expr_t*)term, cid);
	}
	return NULL;
}

static knh_int_t Stmt_getint_(CTX ctx, knh_Stmt_t *stmt, knh_bytes_t name, knh_int_t defn)
{
	knh_Object_t *o = Stmt_getConst_(ctx, stmt, name, CLASS_Int);
	if(o != NULL) {
		return ((knh_Int_t*)o)->n.ivalue;
	}
	return defn;
}


static knh_Token_t *Stmt_getTokenNULL_(CTX ctx, knh_Stmt_t *stmt, knh_bytes_t name)
{
	knh_Object_t *term = knh_DictMap_getNULL(ctx, stmt->clauseDictMap, name);
	if(term != NULL && IS_Expr(term)) {
		return ((knh_Expr_t*)term)->token;
	}
	return NULL;
}

static knh_Block_t *Stmt_getBlock_(CTX ctx, knh_Stmt_t *stmt, knh_bytes_t name)
{
	knh_Block_t *bk = (knh_Block_t*)knh_DictMap_getNULL(ctx, stmt->clauseDictMap, name);
	if(bk != NULL && IS_Block(bk)) {
		return bk;
	}
	return KNH_TNULL(Block);
}

static knh_class_t Stmt_getcid_(CTX ctx, knh_Stmt_t *stmt, knh_bytes_t name, knh_NameSpace_t *ns, knh_class_t defcid)
{
//	knh_Expr_t *expr = Stmt_getExprNULL_(ctx, stmt, name);
//	if(expr == NULL) {
//		return defcid;
//	}
//	if(expr->expr == UEXPR_TOKEN) {
//		knh_class_t cid = knh_NameSpace_getcid(ctx, ns, S_tobytes(expr->token->text));
//		if(cid == CLASS_unknown) {
//			ERROR_TokenUndefined(ctx, tk, "class");
//			ERROR_TokenAlternativeClass(ctx, tk, defcid);
//			cid = defcid;
//		}
//		expr->expr = EXPR_TYPE;
//		expr->cid = cid;
//	}
//	DBG_ASSERT(expr->expr == EXPR_TYPE);
//	if(expr->expr == EXPR_TYPE) {
//		return expr->cid;
//	}
	return defcid;
}

//define Term_fn(ctx, tk) FN_UNMASK(Term_fnq(ctx, tk))
//
//ksymbol_t Term_fnq(CTX ctx, knh_Term_t *tk)
//{
//	ksymbol_t fn = FN_;
//	if(TT_(tk) == TT_NAME || TT_(tk) == TT_UNAME) {
//		fn = knh_getfnq(ctx, TK_tobytes(tk), FN_NEWID);
//	}
//	return fn;
//}
//
//static knh_methodn_t Term_mn(CTX ctx, knh_Term_t *tk)
//{
//	if(TT_(tk) == TT_FUNCNAME || TT_(tk) == TT_NAME || TT_(tk) == TT_UNAME || TT_(tk) == TT_UFUNCNAME) {
//		TT_(tk) = TT_MN;
//		(tk)->mn = knh_getmn(ctx, TK_tobytes(tk), MN_NEWID);
//	}
//	if(TT_(tk) == TT_NEW) {
//		TT_(tk) = TT_MN;
//		(tk)->mn = knh_getmn(ctx, TK_tobytes(tk), MN_NEWID);
//	}
//	DBG_ASSERT(TT_(tk) == TT_MN);
//	if(Term_isISBOOL(tk)) {
//		(tk)->mn = MN_toISBOOL(MN_toFN((tk)->mn));
//		Term_setISBOOL(tk, 0);
//	}
//	else if(Term_isGetter(tk)) {
//		(tk)->mn = MN_toGETTER(MN_toFN((tk)->mn));
//		Term_setGetter(tk, 0);
//	}
//	else if(Term_isSetter(tk)) {
//		(tk)->mn = MN_toSETTER(MN_toFN((tk)->mn));
//		Term_setSetter(tk, 0);
//	}
//	return (tk)->mn;
//}

static ksymbol_t Stmt_getfn_(CTX ctx, knh_Stmt_t *stmt, knh_bytes_t name, ksymbol_t deffn)
{
	return deffn;
}

static knh_methodn_t Stmt_getmn_(CTX ctx, knh_Stmt_t *stmt, knh_bytes_t name, knh_methodn_t defmn)
{
//	knh_Expr_t *expr = Stmt_getExprNULL_(ctx, stmt, name);
//	if(expr == NULL) {
//		return defmn;
//	}
//	if(expr->expr == UEXPR_TOKEN) {
//		knh_methodn_t mn = knh_getmn(ctx, TK_tobytes(tk), defmn);
//		expr->expr = EXPR_METHOD;
//		expr->mn   = mn;
//	}
//	DBG_ASSERT(expr->expr == EXPR_METHOD);
//	if(expr->expr == EXPR_METHOD) {
//		return expr->mn;
//	}
	return defmn;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif