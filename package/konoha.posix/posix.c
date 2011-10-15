/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
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

// **************************************************************************
// LIST OF CONTRIBUTERS
//  kimio - Kimio Kuramitsu, Yokohama National University, Japan
//  shinpei_NKT - Shinpei Nakata, Yokohama National University, Japan
// **************************************************************************

/* ************************************************************************ */

#define USE_STRUCT_Path
#include<konoha1.h>



#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/ioctl.h>
#include <sys/file.h>
#include <sys/utsname.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ======================================================================== */
/* ConstData */

//## @Native String System.getHostName();
KMETHOD System_getHostName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const char *s = NULL;
	char buf[256];
	if(gethostname(buf, sizeof(buf)) == -1) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "gethostname", K_PERROR, ldata);
	}
	else {
		s = (const char*)buf;
	}
	RETURN_(new_String(ctx, s));
}

//## @Native Map System.uname();
KMETHOD System_uname(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *mdata = KNH_TNULL(Map);
	struct utsname buf;
	int ret = uname(&buf);
	knh_ldata_t ldata[] = {LOG_END};
	if (ret == -1) {
	  KNH_NTRACE(ctx, "uname", K_PERROR, ldata);
	} else {
	  mdata = new_DataMap(ctx);
	  knh_DataMap_setString(ctx, mdata, "sysname", buf.sysname);
	  knh_DataMap_setString(ctx, mdata, "nodename", buf.nodename);
	  knh_DataMap_setString(ctx, mdata, "release", buf.release);
	  knh_DataMap_setString(ctx, mdata, "version", buf.version);
	  knh_DataMap_setString(ctx, mdata, "machine", buf.machine);
	  KNH_NTRACE(ctx, "uname", K_OK, ldata);
	  
	}
	RETURN_(mdata);
}

//## @Native String System.getDomainName();
KMETHOD System_getDomainName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const char *s = NULL;
	char buf[256];
	if (getdomainname(buf, sizeof(buf)) == -1) {
	  knh_ldata_t ldata[] = {LOG_END};
	  KNH_NTRACE(ctx, "getdomainname", K_PERROR, ldata);
	} else {
	  s = (const char *)buf;
	}
	RETURN_(new_String(ctx, s));
}

//## @Native String System.getLogin();
KMETHOD System_getLogin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	char *loginname = getlogin();
	knh_ldata_t ldata[] = {LOG_END};
	KNH_NTRACE(ctx, "getlogin", (loginname != NULL) ? K_OK : K_PERROR, ldata);
	RETURN_(new_String(ctx, loginname));
}

//## @Native int System.getUid();
KMETHOD System_getUid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getuid());
}

//## @Native int System.getEuid();
KMETHOD System_getEuid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(geteuid());
}

//## @Native int System.getGid();
KMETHOD System_getGid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getgid());
}

//## @Native int System.getEgid();
KMETHOD System_getEgid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getegid());
}

//## @Native int System.getPid();
KMETHOD System_getPid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getpid());
}

//## @Native int System.getPPid();
KMETHOD System_getPPid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(getppid());
}

/* should functions below move to proc?? */
//## @Native int System.getPgid(int pid);
KMETHOD System_getPgid(CTX ctx, knh_sfp_t *sfp _RIX)
{
  pid_t pid = Int_to(pid_t, sfp[1]);
  knh_ldata_t ldata[] = {LOG_i("pid", pid), LOG_END};
  KNH_NTRACE(ctx, "getpgid", (pid != -1) ? K_OK : K_PERROR, ldata);
  RETURNi_(pid); // TODO: is this okay to return -1?
}

//## @Native int System.setPgid(int pid, int pgid);
KMETHOD System_setPgid(CTX ctx, knh_sfp_t *sfp _RIX)
{
  pid_t pid = Int_to(pid_t, sfp[1]);
  pid_t pgid = Int_to(pid_t, sfp[2]);
  
  int ret = setpgid(pid, pgid);
  knh_ldata_t ldata[] = {LOG_i("pid", pid), LOG_i("pgid", pgid), LOG_END};
  if (ret == -1) {
	// error
	KNH_NTRACE(ctx, "setpgid", K_PERROR, ldata);
	RETURNb_(0); // false
  } else {
	KNH_NTRACE(ctx, "setpgid", K_OK, ldata);
	RETURNb_(1);
  }
}

//## @Native Array<int> System.getGroups(int pid);
KMETHOD System_getGroups(CTX ctx, knh_sfp_t *sfp _RIX)
{
  gid_t groups[NGROUPS_MAX] = {0};
  int group_num = getgroups(NGROUPS_MAX, groups);
  knh_ldata_t ldata[] = {LOG_END};
  knh_Array_t *a = KNH_TNULL(Array);
  if (group_num == -1) {
	// error
	KNH_NTRACE(ctx, "getgroups", K_PERROR, ldata);
  } else {
	DBG_P("groups:%d", group_num);
	int i, n = 0;
	BEGIN_LOCAL(ctx, lsfp, group_num);
	a = new_Array(ctx, CLASS_Int, group_num);
	for(i = 0; i < group_num; i++) {
	  lsfp[n++].ndata = groups[i];
	}
	a->api->multiadd(ctx, a, lsfp);
	END_LOCAL(ctx, lsfp);
	KNH_NTRACE(ctx, "getgroups", K_OK, ldata);
  }
  RETURN_(a);
}

/* ------------------------------------------------------------------------ */
/* [resource] */

//@Public @Native Map System.getrusage(int who);
KMETHOD System_getResourceUsage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *mdata = KNH_TNULL(Map);
	int who = Int_to(int, sfp[1]);
	knh_ldata_t ldata[] = {LOG_i("who", who), LOG_END};
	struct rusage usage;
	int ret = getrusage(who, &usage);
	if (ret == -1) {
	  // error
	  KNH_NTRACE(ctx, "getrusage", K_PERROR, ldata);
	} else {
	  mdata = new_DataMap(ctx);
	  //TODO: ru_utime, ru_stime is postponed...
	  knh_DataMap_setInt(ctx, mdata, "ru_maxrss", usage.ru_maxrss);
	  knh_DataMap_setInt(ctx, mdata, "ru_ixrss", usage.ru_ixrss);
	  knh_DataMap_setInt(ctx, mdata, "ru_idrss", usage.ru_idrss);
	  knh_DataMap_setInt(ctx, mdata, "ru_isrss", usage.ru_isrss);
	  knh_DataMap_setInt(ctx, mdata, "ru_minflt", usage.ru_minflt);
	  knh_DataMap_setInt(ctx, mdata, "ru_majflt", usage.ru_majflt);
	  knh_DataMap_setInt(ctx, mdata, "ru_nswap", usage.ru_nswap);
	  knh_DataMap_setInt(ctx, mdata, "ru_inblock", usage.ru_inblock);
	  knh_DataMap_setInt(ctx, mdata, "ru_oublock", usage.ru_oublock);
	  knh_DataMap_setInt(ctx, mdata, "ru_msgsnd", usage.ru_msgsnd);
	  knh_DataMap_setInt(ctx, mdata, "ru_msgrcv", usage.ru_msgrcv);
	  knh_DataMap_setInt(ctx, mdata, "ru_nsignals", usage.ru_nsignals);
	  knh_DataMap_setInt(ctx, mdata, "ru_nvcsw", usage.ru_nvcsw);
	  knh_DataMap_setInt(ctx, mdata, "ru_nivcsw", usage.ru_nivcsw);
	  KNH_NTRACE(ctx, "getrusage", K_OK, ldata);
	}
	RETURN_(mdata);
}

//## @Public @Native Map System.getRlimit(int rtype);
KMETHOD System_getRlimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *mdata = KNH_TNULL(Map);
	int rtype = Int_to(int, sfp[1]);
	struct rlimit limit;
	int ret = getrlimit(rtype, &limit);
	knh_ldata_t ldata[] = {LOG_i("rtype", rtype), LOG_END};
	if (ret == -1) {
	  //error
	  KNH_NTRACE(ctx, "getrlimit", K_PERROR, ldata);
	} else {
	  mdata = new_DataMap(ctx);
	  knh_DataMap_setInt(ctx, mdata, "rlim_cur", limit.rlim_cur);
	  knh_DataMap_setInt(ctx, mdata, "rlim_max", limit.rlim_max);
	  KNH_NTRACE(ctx, "getrlimit", K_OK, ldata);
	}
	RETURN_(mdata);
}
/* ------------------------------------------------------------------------ */
/* [signal] */

//## @Native int System.sleep(int sec);
KMETHOD System_sleep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(sleep(Int_to(int, sfp[1])));
}

//## @Native boolean System.usleep(int usec);
KMETHOD System_usleep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int tf = (usleep(Int_to(useconds_t, sfp[1])) != -1);
	if(!tf) {
		knh_ldata_t ldata[] = {LOG_i("usec", sfp[1].ivalue), LOG_END};
		KNH_NTRACE(ctx, "usleep", K_PERROR, ldata);
	}
	RETURNb_(tf);
}

/* ------------------------------------------------------------------------ */

//## @Native String System.getCwd();

KMETHOD System_getCwd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	char tmpbuf[K_PATHMAX];
	char *ret = getcwd(tmpbuf, sizeof(tmpbuf));
	if (ret == NULL) {
	  knh_ldata_t ldata[] = {LOG_END};
	  KNH_NTRACE(ctx, "getcwd", K_PERROR, ldata);
	}
	RETURN_(new_String(ctx, (const char*)tmpbuf));
}

static int fileop(CTX ctx, knh_sfp_t *sfp, const char *name, int (*func)(const char*), knh_Path_t *pth)
{
	knh_ldata_t ldata[] = {LOG_s("path", S_totext(pth->urn)), LOG_s("ospath", pth->ospath), LOG_END};
	if(func(pth->ospath) == -1) {
		KNH_NTRACE(ctx, name, K_PERROR, ldata);
		return 0;
	}
	else {
		KNH_NTRACE(ctx, name, K_OK, ldata);
	}
	return 1;
}

static int fileop2(CTX ctx, knh_sfp_t *sfp, const char *name, int (*func)(const char*, const char*), knh_Path_t *pth, knh_Path_t *pth2)
{
	knh_ldata_t ldata[] = {LOG_s("path", S_totext(pth->urn)), LOG_s("ospath", pth->ospath),
			LOG_s("path2", S_totext(pth2->urn)), LOG_s("ospath2", pth2->ospath), LOG_END};
	if(func(pth->ospath, pth2->ospath) == -1) {
		KNH_NTRACE(ctx, name, K_PERROR, ldata);
		return 0;
	}
	else {
		KNH_NTRACE(ctx, name, K_OK, ldata);
	}
	return 1;
}

//## @Native @Restricted boolean System.link(Path path, Path path2);
KMETHOD System_link(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop2(ctx, sfp, "link", link, sfp[1].pth, sfp[2].pth));
}

//## @Native @Restricted boolean System.symlink(Path path, Path path2);
KMETHOD System_symlink(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop2(ctx, sfp, "symlink", symlink, sfp[1].pth, sfp[2].pth));
}

//## @Native @Restricted boolean System.rename(Path path, Path path2);
KMETHOD System_rename(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop2(ctx, sfp, "rename", rename, sfp[1].pth, sfp[2].pth));
}

//## @Native @Restricted boolean System.unlink(Path path);
KMETHOD System_unlink(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop(ctx, sfp, "unlink", unlink, sfp[1].pth));
}

//## @Native String System.readlink(Path path);
KMETHOD System_readlink(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = sfp[1].pth;
	char tmpbuf[K_PATHMAX] = {0};

	int ret = readlink(pth->ospath, tmpbuf, K_PATHMAX);
	knh_ldata_t ldata[] = {LOG_s("path", S_totext(pth->urn)), LOG_s("ospath", pth->ospath), LOG_END};
	knh_String_t *str = KNH_TNULL(String);
	if (ret == -1) {
	  // error
	  KNH_NTRACE(ctx, "readlink", K_PERROR, ldata);
	} else {
	  str = new_String(ctx, (const char*)tmpbuf);
	  DBG_P("pathmax:%d, %s, %s", K_PATHMAX, tmpbuf, S_totext(str));
	  KNH_NTRACE(ctx, "readlink", K_OK, ldata);
	}
	RETURN_(str);
}


//## @native boolean System.chdir(Path path);
KMETHOD System_chdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop(ctx, sfp, "chdir", chdir, sfp[1].pth));
}

//## @Public @Restricted @Native boolean System.chroot(Path path);
KMETHOD System_chroot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop(ctx, sfp, "chroot", chroot, sfp[1].pth));
}



//## @Native @Restricted boolean System.mkdir(Path path, int mode);
KMETHOD System_mkdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = sfp[1].pth;
	mode_t mode =  (mode_t)sfp[2].ivalue;
	int ret = mkdir(pth->ospath, mode);
	knh_ldata_t ldata[] = {LOG_s("path", S_totext(pth->urn)), LOG_s("ospath", pth->ospath), LOG_i("mode", mode), LOG_END};
	KNH_NTRACE(ctx, "mkdir", (ret == 0) ? K_OK : K_PERROR, ldata);
	RETURNb_(ret == 0 ? 1 : 0);
}

//## @Native @Restricted boolean System.rmdir(Path path);
KMETHOD System_rmdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(fileop(ctx, sfp, "rmdir", rmdir, sfp[1].pth));
}

//## @Native int System.getPriority(int which, int who);
KMETHOD System_getPriority(CTX ctx, knh_sfp_t *sfp _RIX)
{
  int which = Int_to(int, sfp[1]);
  int who = Int_to(int, sfp[2]);
  errno = 0;
  int pri = getpriority(which, who);
  knh_ldata_t ldata[] = {LOG_i("which", which), LOG_i("who", who), LOG_END};
  KNH_NTRACE(ctx, "getpriority", (errno == 0)? K_OK : K_PERROR, ldata);
  RETURNi_(pri);
}

//## @Native @Restricted int System.setPriority(int which, int who, int pri);
KMETHOD System_setPriority(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int which = Int_to(int, sfp[1]);
	int who = Int_to(int, sfp[2]);
	int pri = Int_to(int, sfp[3]);
	int ret = setpriority(which, who, pri);
	if (ret == -1) {
	  knh_ldata_t ldata[] = {LOG_i("which", which), LOG_i("who", who), LOG_i("pri", pri), LOG_END};
	  KNH_NTRACE(ctx, "setpriority", K_PERROR, ldata);
	}
	RETURNb_(ret == -1);
}

//## @Native int System.getPageSize()
KMETHOD System_getPageSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	// there is no error in getpagesize
	RETURNi_(getpagesize());
}


/* ------------------------------------------------------------------------ */
/* [DIR] */

static void Dir_init(CTX ctx, knh_RawPtr_t *po)
{
	po->rawptr = NULL;
}

static void Dir_free(CTX ctx, knh_RawPtr_t *po)
{
	if (po->rawptr != NULL) {
		closedir((DIR*)po->rawptr);
		po->rawptr = NULL;
	}
}

static void Dir_checkout(CTX ctx, knh_RawPtr_t *po, int isFailed)
{
	if (po->rawptr != NULL) {
		closedir((DIR*)po->rawptr);
		po->rawptr = NULL;
	}
}

DEFAPI(void) defDir(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "Dir";
	cdef->init = Dir_init;
	cdef->free = Dir_free;
	cdef->checkout = Dir_checkout;
}

static knh_IntData_t DirConstInt[] = {
	{"DT_UNKNOWN", DT_UNKNOWN},
	{"DT_FIFO",    DT_FIFO},
	{"DT_CHR",     DT_CHR},
	{"DT_DIR",     DT_DIR},
	{"DT_BLK",     DT_BLK},
	{"DT_REG",     DT_REG},
	{"DT_LNK",     DT_LNK},
	{"DT_SOCK",    DT_SOCK},
	{"DT_WHT",     DT_WHT},
	{NULL}
};

DEFAPI(void) constDir(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, DirConstInt);
}

/* ------------------------------------------------------------------------ */

//## @Native @Throwable Dir System.openDir(Path path);
KMETHOD System_openDir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = sfp[1].pth;
	DIR *dirptr = opendir(pth->ospath);
	knh_RawPtr_t *po = 	new_ReturnCppObject(ctx, sfp, dirptr, NULL/*ignored*/);
	knh_ldata_t ldata[] = {LOG_s("path", S_totext(pth->urn)), LOG_s("ospath", pth->ospath), LOG_END};
	KNH_NTRACE(ctx, "opendir", (dirptr != NULL) ? K_OK : K_PERROR, ldata);
	RETURN_(po);
}

//## @Native void Dir.close();
KMETHOD Dir_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DIR *dirptr = (DIR*)sfp[0].p->rawptr;
	if(dirptr != NULL) {
		sfp[0].p->rawptr = NULL;
		closedir(dirptr);
	}
	RETURNvoid_();
}

//## @Const @Static @Hidden Dir Dir.opLink(String urn, NameSpace _);
KMETHOD Dir_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KNH_SETv(ctx, sfp[1].o, new_Path(ctx, sfp[1].s));
	System_openDir(ctx, sfp, K_RIX);
}

//## @Native @Iterative Map Dir.read();
KMETHOD Dir_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *mdata = KNH_TNULL(Map);
	DIR *dirptr = (DIR*)sfp[0].p->rawptr;
	if(dirptr != NULL) {
		struct dirent *dp = readdir(dirptr);
		if(dp != NULL) {
			mdata = new_DataMap(ctx);
			knh_DataMap_setString(ctx, mdata, "d_name", dp->d_name);
			knh_DataMap_setInt(ctx, mdata, "d_type", dp->d_type);
		}
	}
	RETURN_(mdata);
}

//## @Native @Iterative String Dir.readName();
KMETHOD Dir_readName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	const char *dname = NULL;
	DIR *dirptr = (DIR*) sfp[0].p->rawptr;
	if(dirptr != NULL) {
		struct dirent *dp = readdir(dirptr);
		if(dp != NULL) {
			dname = dp->d_name;
		}
	}
	RETURN_(new_String(ctx, dname));
}



/* ======================================================================== */
/* FILE Stream*/

static void DFile_init(CTX ctx, knh_RawPtr_t *po)
{
	po->rawptr = NULL;
}

static void DFile_free(CTX ctx, knh_RawPtr_t *po)
{
	if (po->rawptr != NULL) {
		fclose((FILE*)po->rawptr);
		po->rawptr = NULL;
	}
}

static void DFile_checkout(CTX ctx, knh_RawPtr_t *po, int isFailed)
{
	if (po->rawptr != NULL) {
		fclose((FILE*)po->rawptr);
		po->rawptr = NULL;
	}
}

DEFAPI(void) defDFile(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "DFile";
	cdef->init = DFile_init;
	cdef->free = DFile_free;
	cdef->checkout = DFile_checkout;
}

//## @Native @Throwable DFile System.fopen(Path path, String mode);
KMETHOD System_fopen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = sfp[1].pth;
	const char *mode = IS_NULL(sfp[2].s) ? "r" : S_totext(sfp[2].s);
	FILE *fp = fopen(pth->ospath, mode);
	knh_RawPtr_t *po = 	new_ReturnCppObject(ctx, sfp, fp, NULL/*ignored*/);
	knh_ldata_t ldata[] = {LOG_s("path", S_totext(pth->urn)), LOG_s("ospath", pth->ospath), LOG_s("mode", mode), LOG_END};
	KNH_NTRACE(ctx, "fopen", (fp != NULL) ? K_OK : K_PERROR, ldata);
	RETURN_(po);
}

//## @Native @Restricted boolean System.chmod(Path path, int mode);
KMETHOD System_chmod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = sfp[1].pth;
	mode_t mode = Int_to(mode_t, sfp[2]);
	int ret = -1;
	if (mode <= 07777) { // including set-user-ID + set-group-ID + stkckybit
	  ret = chmod(pth->ospath, mode);
	}
	knh_ldata_t ldata[] = {LOG_s("path", S_totext(pth->urn)), LOG_s("ospath", pth->ospath), LOG_i("mode", mode), LOG_END};
	KNH_NTRACE(ctx, "chmod", (ret == 0) ? K_OK : K_PERROR, ldata);
	RETURNb_(ret == 0);
}

//## @Native @Restricted boolean System.chown(Path path, int owner, int group);
KMETHOD System_chown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = sfp[1].pth;
	uid_t owner = Int_to(uid_t, sfp[2]);
	gid_t group = Int_to(gid_t, sfp[3]);
	int ret = chown(pth->ospath, owner, group);
	knh_ldata_t ldata[] = {LOG_s("path", S_totext(pth->urn)), LOG_s("ospath", pth->ospath), LOG_i("owner", owner), LOG_i("group", group), LOG_END};
	KNH_NTRACE(ctx, "chown", (ret == 0) ? K_OK : K_PERROR, ldata);
	RETURNb_(ret == 0);
}

//## @Native @Restricted boolean System.access(Path path);
KMETHOD System_access(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = sfp[1].pth;
	mode_t mode = Int_to(mode_t, sfp[2]);
	int ret = access(pth->ospath, mode);
	knh_ldata_t ldata[] = {LOG_s("path", S_totext(pth->urn)), LOG_s("ospath", pth->ospath), LOG_i("mode", mode), LOG_END};
	KNH_NTRACE(ctx, "access", ret == 0 ? K_OK : K_PERROR, ldata);
	RETURNb_(ret == 0);
}

//## @Native void System.sync(void);
KMETHOD System_sync(CTX ctx, knh_sfp_t *sfp _RIX)
{
	// there is no error in sync
	sync();
	RETURNvoid_();
}

//## @Native Map System.truncate(Path path, int length);
KMETHOD System_truncate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Path_t *pth = sfp[1].pth;
	int length = Int_to(int, sfp[2]);
	int ret = truncate(pth->ospath, length);
	knh_ldata_t ldata[] = {LOG_s("path", S_totext(pth->urn)), LOG_s("ospath", pth->ospath), LOG_i("length", length), LOG_END};
	KNH_NTRACE(ctx, "truncate", (ret == 0) ? K_OK : K_PERROR, ldata);
	RETURNb_(ret == 0);
}

//## @Native Map System.stat(Path path);
KMETHOD System_stat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Map_t *mdata = KNH_TNULL(Map);
	knh_Path_t *pth = sfp[1].pth;
	struct stat fbuf = {0};
	int ret = lstat(pth->ospath, &fbuf);
	knh_ldata_t ldata[] = {LOG_s("path", S_totext(pth->urn)), LOG_s("ospath", pth->ospath), LOG_END};
	KNH_NTRACE(ctx, "stat", (ret != -1) ? K_OK : K_PERROR, ldata);
	if (ret != -1) {
	  mdata = new_DataMap(ctx);
	  knh_DataMap_setInt(ctx, mdata, "dev_major", major(fbuf.st_dev));
	  knh_DataMap_setInt(ctx, mdata, "dev_minor", minor(fbuf.st_dev));
	  knh_DataMap_setInt(ctx, mdata, "ino", fbuf.st_ino);
	  knh_DataMap_setInt(ctx, mdata, "nlink", fbuf.st_mode);
	  knh_DataMap_setInt(ctx, mdata, "uid", fbuf.st_uid);
	  knh_DataMap_setInt(ctx, mdata, "gid", fbuf.st_gid);
	  knh_DataMap_setInt(ctx, mdata, "rdev", fbuf.st_rdev);
	  knh_DataMap_setInt(ctx, mdata, "size", fbuf.st_size);
	  knh_DataMap_setInt(ctx, mdata, "blksize", fbuf.st_blksize);
	  knh_DataMap_setInt(ctx, mdata,  "blocks", fbuf.st_blocks);
	  knh_DataMap_setInt(ctx, mdata,  "atime", fbuf.st_atime);
	  knh_DataMap_setInt(ctx, mdata,  "mtime", fbuf.st_mtime);
	  knh_DataMap_setInt(ctx, mdata,  "ctime", fbuf.st_ctime);

	  // mode
	  mode_t filetype = fbuf.st_mode & S_IFMT;
	  switch (filetype) {
	  case S_IFSOCK:
		knh_DataMap_setString(ctx, mdata, "filetype", "socket");
		break;
	  case S_IFLNK:
		knh_DataMap_setString(ctx, mdata, "filetype", "symlink");
		break;
	  case S_IFREG:
		knh_DataMap_setString(ctx, mdata, "filetype", "regularfile");
		break;
	  case S_IFBLK:
		knh_DataMap_setString(ctx, mdata, "filetype", "block device");
		break;
	  case S_IFDIR:
		knh_DataMap_setString(ctx, mdata, "filetype", "directory");
		break;
	  case S_IFCHR:
		knh_DataMap_setString(ctx, mdata, "filetype", "char device");
		break;
	  case S_IFIFO:
		knh_DataMap_setString(ctx, mdata, "filetype", "FIFO");
		break;
	  default:
		knh_DataMap_setString(ctx, mdata, "filetype", "unknown");
		break;
	  }
	}
	RETURN_(mdata);
}

//## @Native int File.getC();
KMETHOD DFile_getC(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	int ch = EOF;
	if(fp != NULL) {
		ch = fgetc(fp);
	}
	RETURNi_(ch);
}

//## @Native int File.read(Bytes buf, int offset, int len);
KMETHOD DFile_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	size_t size = 0;
	if(fp != NULL) {
		knh_Bytes_t *ba = sfp[1].ba;
		size_t offset = (size_t)sfp[2].ivalue;
		size_t len = (size_t)sfp[3].ivalue;
		size = BA_size(ba);
		if(!(offset < size)) {
			THROW_OutOfRange(ctx, sfp, offset, size);
		}
		if(len == 0) len = size - offset;
		size = fread(ba->bu.buf + offset, 1, len, fp);
	}
	RETURNi_(size);
}

//## @Native boolean File.putC(int ch);
KMETHOD DFile_putC(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	if(fp != NULL) {
		int ch = fputc((int)sfp[1].ivalue, fp);
		RETURNb_((ch != EOF));
	}
	RETURNb_(0);
}

//## @Native int File.write(Bytes buf, int offset, int len);
KMETHOD DFile_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	size_t size = 0;
	if(fp != NULL) {
		knh_Bytes_t *ba = sfp[1].ba;
		size_t offset = (size_t)sfp[2].ivalue;
		size_t len = (size_t)sfp[3].ivalue;
		size = BA_size(ba);
		if(!(offset < size)) {
			THROW_OutOfRange(ctx, sfp, offset, size);
		}
		if(len == 0) len = size - offset;
		size = fwrite(ba->bu.buf + offset, 1, len, fp);
	}
	RETURNi_(size);
}

//## @Native void File.close();
KMETHOD DFile_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	if(fp != NULL) {
		sfp[0].p->rawptr = NULL;
		fclose(fp);
	}
	RETURNvoid_();
}

/* ======================================================================== */
/* FILE low-level*/

//## @Native int DFile.lseek(int offset, int whence)
KMETHOD DFile_lseek(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	// fileno only returns EBADF
	if (fp == NULL) RETURNi_(-1);
	int fd = fileno(fp);
	knh_ldata_t ldata[] = {LOG_p("fp", fp), LOG_END};
	if (fd == -1) {
	  KNH_NTRACE(ctx, "fileno", K_PERROR, ldata);
	  RETURNi_(-1);
	}

	int offset = Int_to(int, sfp[1]);
	int whence = Int_to(int, sfp[2]);
	off_t ret_offset = lseek(fd, offset, whence);
	knh_ldata_t ldata2[] = {LOG_i("offset", offset), LOG_i("whence", whence), LOG_END};
	KNH_NTRACE(ctx, "lseek", (ret_offset != -1) ? K_OK : K_PERROR, ldata2);
	RETURNi_((int)ret_offset);
}


//## @Native boolean DFile.truncate(int length)
KMETHOD DFile_truncate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	int length = Int_to(int, sfp[1]);
	if (fp == NULL) RETURNb_(0); 
	int fd = fileno(fp);
	knh_ldata_t ldata[] = {LOG_p("fp", fp), LOG_END};
	if (fd == -1) {
	  KNH_NTRACE(ctx, "fileno", K_PERROR, ldata);
	  RETURNb_(0);
	}
	int ret = ftruncate(fd, length);
	knh_ldata_t ldata2[] = {LOG_p("fp", fp), LOG_i("length", length), LOG_END};
	KNH_NTRACE(ctx, "ftruncate", (ret == 0) ? K_OK : K_PERROR, ldata2);
	RETURNb_(ret == 0);
}

//## @Native boolean DFile.chmod(int length)
KMETHOD DFile_chmod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	mode_t mode = Int_to(mode_t, sfp[1]);
	if (fp == NULL) RETURNb_(0); 
	int fd = fileno(fp);
	knh_ldata_t ldata[] = {LOG_p("fp", fp), LOG_END};
	if (fd == -1) {
	  KNH_NTRACE(ctx, "fileno", K_PERROR, ldata);
	  RETURNb_(0);
	}
	int ret = fchmod(fd, mode);
	knh_ldata_t ldata2[] = {LOG_p("fp", fp), LOG_i("mode", mode), LOG_END};
	KNH_NTRACE(ctx, "fchmod", (ret == 0) ? K_OK : K_PERROR, ldata2);
	RETURNb_(ret == 0);
}

//## @Native boolean DFile.chown(int owner, int group)
KMETHOD DFile_chown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	uid_t owner = Int_to(uid_t, sfp[1]);
	gid_t group = Int_to(gid_t, sfp[2]);
	if (fp == NULL) RETURNb_(0); 
	int fd = fileno(fp);
	knh_ldata_t ldata[] = {LOG_p("fp", fp), LOG_END};
	if (fd == -1) {
	  KNH_NTRACE(ctx, "fileno", K_PERROR, ldata);
	  RETURNb_(0);
	}
	int ret = fchown(fd, owner, group);
	knh_ldata_t ldata2[] = {LOG_p("fp", fp), LOG_i("owner", owner), LOG_i("group", group), LOG_END};
	KNH_NTRACE(ctx, "fchown", ret == 0 ? K_OK : K_PERROR, ldata2);
	RETURNb_(ret == 0);
}

// TODO: isn't ioctl difficult for script users? should we support this?
//## @Native int File.ioctl(int request, String[] args)
KMETHOD DFile_ioctl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	int request  = Int_to(int, sfp[1]);
	char *argp = String_to(char*, sfp[2]);
	if (fp == NULL) RETURNb_(0);
	int fd = fileno(fp);
	knh_ldata_t ldata[] = {LOG_p("fp", fp), LOG_END};
	if (fd == -1) {
	  KNH_NTRACE(ctx, "fileno", K_PERROR, ldata);
	  RETURNb_(0);
	}
	int ret = ioctl(fd, request, argp);
	knh_ldata_t ldata2[] = {LOG_p("fp", fp), LOG_i("request", request), LOG_s("arg", argp), LOG_END};
	KNH_NTRACE(ctx, "ioctl", ret != -1 ? K_OK : K_PERROR, ldata2); 
	RETURNb_(ret != -1);
}

// NOTE: sys_flock can use for a file, only for 
//## @Native boolean File.flock(int opretaion);
KMETHOD DFile_flock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	int operation  = Int_to(int, sfp[1]);
	if (fp == NULL) RETURNb_(0);
	int fd = fileno(fp);
	knh_ldata_t ldata[] = {LOG_p("fp", fp), LOG_END};
	if (fd == -1) {
	  KNH_NTRACE(ctx, "fileno", K_PERROR, ldata);
	  RETURNb_(0);
	}

	int ret = flock(fd, operation);
	knh_ldata_t ldata2[] = {LOG_p("fp", fp), LOG_i("operation", operation), LOG_END};
	KNH_NTRACE(ctx, "flock", ret == 0 ? K_OK : K_PERROR, ldata2);
	RETURNb_(ret == 0);
}

//## @Native boolean File.sync(void);
KMETHOD DFile_sync(CTX ctx, knh_sfp_t *sfp _RIX)
{
	FILE *fp = (FILE*)sfp[0].p->rawptr;
	if (fp == NULL) RETURNb_(0);
	int fd = fileno(fp);
	knh_ldata_t ldata[] = {LOG_p("fp", fp), LOG_END};
	if (fd == -1) {
	  KNH_NTRACE(ctx, "fileno", K_PERROR, ldata);
	  RETURNb_(0);
	}
	int ret = fsync(fd);
	knh_ldata_t ldata2[] = {LOG_p("fp", fp), LOG_END};
	KNH_NTRACE(ctx, "fsync", ret == 0 ? K_OK : K_PERROR, ldata2);
	RETURNb_(ret == 0);
}

/* ======================================================================== */

#ifdef _SETUP

static knh_IntData_t IntConstData[] = {
	{"SIGHUP", SIGHUP},   // hang up (1)
	{"SIGINT", SIGINT},   // interrupt (2)
	{"SIGQUIT", SIGQUIT}, // quit (3)
	{"SIGABRT", SIGABRT}, // abort (9)
	{"SIGKILL", SIGKILL}, // kill 9
	{"SIGALRM", SIGALRM}, // alarm clock (14)
	{"SIGTERM", SIGTERM}, // software termination signal 15
	{"SIGBUS",  SIGBUS},
	{"SIGSEGV", SIGSEGV},
	{"SIGPIPE", SIGPIPE},

	{"RUSAGE_SELF", RUSAGE_SELF}, // used by getrusage 
	{"RUSAGE_CHILDREN", RUSAGE_CHILDREN},// used by getrusage 

	{"RLIMIT_CPU", RLIMIT_CPU}, // for rlimit
	{"RLIMIT_FSIZE", RLIMIT_FSIZE}, // for rlimit
	{"RLIMIT_DATA", RLIMIT_DATA}, // for rlimit
	{"RLIMIT_STACK", RLIMIT_STACK}, // for rlimit
	{"RLIMIT_CORE", RLIMIT_CORE}, // for rlimit
	{"RLIMIT_NOFILE", RLIMIT_NOFILE}, // for rlimit

	{"SEEK_SET", SEEK_SET},
	{"SEEK_CUR", SEEK_CUR},
	{"SEEK_END", SEEK_END},

	{"R_OK", R_OK},
	{"W_OK", W_OK},
	{"X_OK", X_OK},
	{"F_OK", F_OK},

//	{"System.WNOHANG", WNOHANG},  // What is THIS?
//	{"System.WUNTRACED", WUNTRACED},
//	{"System.WCONTINUED", WCONTINUED},
	{NULL}  // end of const data
};

//static knh_FloatData_t FloatConstData[] = {
//	{NULL}  // end of const data
//};
//
//static knh_StringData_t StringConstData[] = {
//	{NULL}  // end of const data
//};


DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, CLASS_System, IntConstData);
	RETURN_PKGINFO("konoha.posix");
}

//DEFAPI(void) SystemCONST(CTX ctx, const knh_LoaderAPI_t *kapi, knh_NameSpace_t *ns)
//{
//	kapi->loadIntData(ctx, ns, IntConstData);
//}

#endif


/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif

