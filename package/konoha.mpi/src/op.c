#ifndef _KNH_ON_T2K
#include "../konoha_mpi.h"
#endif

/* ------------------------------------------------------------------------ */
//## method MPIOp MPIOp.new(MPIOpFunc opfunc, Boolean commutable);

static knh_MPIData_t* new_MPIData_Bytes(CTX ctx, void *vec, int vlen)
{
	knh_Bytes_t *ba = new_Bytes(ctx, NULL, vlen);
	knh_memcpy(ba->bu.buf, vec, vlen);
	BA_size(ba) = vlen;
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	data->ba = ba;
	MPID_TYPE(data) = MPI_CHAR;
	MPID_DCID(data) = CLASS_Bytes;
	return data;
}

static knh_MPIData_t* new_MPIData_ArrayInt(CTX ctx, void *vec, int vlen)
{
	knh_Array_t *a = new_Array(ctx, CLASS_Int, vlen);
	knh_memcpy(a->ilist, vec, sizeof(knh_int_t) * vlen);
	knh_Array_size(a) = vlen;
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	data->a = a;
	MPID_TYPE(data) = MPI_LONG;
	MPID_DCID(data) = CLASS_Array;
	return data;
}

static knh_MPIData_t* new_MPIData_ArrayFloat(CTX ctx, void *vec, int vlen)
{
	knh_Array_t *a = new_Array(ctx, CLASS_Float, vlen);
	knh_memcpy(a->flist, vec, sizeof(knh_float_t) * vlen);
	knh_Array_size(a) = vlen;
	MPID(data, new_O(MPIData, knh_getcid(ctx, B("konoha.mpi.MPIData"))));
	data->a = a;
	MPID_TYPE(data) = MPI_DOUBLE;
	MPID_DCID(data) = CLASS_Array;
	return data;
}


void knh_reduce(knh_Func_t *fo, void *ivec, void *iovec, int *len, MPI_Datatype *dtype)
{
	knh_MPIData_t* (*new_func)(CTX ctx, void *vec, int vlen);
	size_t rsize;
	int vlen = *len;
	CLOSURE_start(2);
	if (*dtype == MPI_CHAR) {
		new_func = new_MPIData_Bytes;
		rsize = vlen;
	}
	else if (*dtype == MPI_LONG) {
		new_func = new_MPIData_ArrayInt;
		rsize = sizeof(knh_int_t) * vlen;
	}
	else if (*dtype == MPI_DOUBLE) {
		new_func = new_MPIData_ArrayFloat;
		rsize = sizeof(knh_float_t) * vlen;
	}
	else {
		knh_ldata_t ldata[] = {LOG_i("unsupported datatype", *dtype), LOG_END};
		KNH_NTHROW(lctx, lsfp, "Script!!", "MPI_Reduce failed", K_FAILED, ldata);
		CLOSURE_end(return);
	}
	knh_MPIData_t *o1 = new_func(lctx, ivec, vlen);
	knh_MPIData_t *o2 = new_func(lctx, iovec, vlen);
	lsfp[1].o = (Object*)o1;
	lsfp[2].o = (Object*)o2;
	CLOSURE_call(fo);
	knh_memcpy(iovec, MPID_ADDR(o2), rsize);
	CLOSURE_end(return);
}

void dummyMPIOpFunc(void *invec, void *inoutvec, int *len, MPI_Datatype *dtype)
{
	return knh_reduce((knh_Func_t*)CALLBACK_MARKER, invec, inoutvec, len, dtype);
}

KMETHOD MPIOp_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	MPIO(op, sfp[0].o);
	knh_Func_t *fo = (knh_Func_t*)sfp[1].fo;
	MPI_User_function *func = (MPI_User_function*)knh_copyCallbackFunc(ctx, (void*)dummyMPIOpFunc, (void*)knh_reduce, fo);
	if (func) {
		if (MPI_Op_create(func, ((sfp[2].bvalue) ? 1 : 0), &MPIO_OP(op)) == MPI_SUCCESS) {
			MPIO_OPFUNC(op) = func;
			goto L_RET;
		}
	}
	KNH_MPI_OP_NULL(op);
	knh_ldata_t ldata[] = {LOG_p("MPI_User_function", func), LOG_END};
	KNH_NTHROW(ctx, sfp, "Script!!", "MPIOp_new failed", K_FAILED, ldata);
	L_RET:;
	RETURN_(op);
}

