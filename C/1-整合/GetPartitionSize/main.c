#include <stdio.h>
#include <sys/vfs.h>
//#include <sys/statfs.h>



//获取挂载目录 剩余大小，总大小，单位M
int getFsSize(char *path, long long *freeSize, long long *totalSize) {

 struct statfs myStatfs;

 if (statfs(path, &myStatfs) == -1) {
  return -1;
 }
 
 //注明long long，避免数据溢出
 *freeSize = (((long long)myStatfs.f_bsize * (long long)myStatfs.f_bfree) / (long long) 1024 / (long long) 1024);
 *totalSize = (((long long)myStatfs.f_bsize * (long long)myStatfs.f_blocks) / (long long) 1024 / (long long) 1024);

 return 0;
}

int main()
{
	long long freeSize;
	long long totalSize;
	char* path = "/system"
	getFsSize(path, &freeSize, &totalSize);
	printf("freeSize=%lld totalSize=%lld\n");
}

/*

int statfs(const char *path, struct statfs *buf);

int fstatfs(int fd, struct statfs *buf);

成功返回0， 失败返回-1。


系统中的statfs机构体声明：

 __SWORD_TYPE int
 __fsblkcnt_t unsigned long int
 __fsblkcnt64_t unsigned long long int

struct statfs
  {
    __SWORD_TYPE f_type;
    __SWORD_TYPE f_bsize;    //数据块大小，单位字节
#ifndef __USE_FILE_OFFSET64
    __fsblkcnt_t f_blocks;  //数据块总数
    __fsblkcnt_t f_bfree;    //可用数据块数
    __fsblkcnt_t f_bavail;  //非超级用户可用数据块
    __fsfilcnt_t f_files;
    __fsfilcnt_t f_ffree;
#else
    __fsblkcnt64_t f_blocks;
    __fsblkcnt64_t f_bfree;
    __fsblkcnt64_t f_bavail;
    __fsfilcnt64_t f_files;
    __fsfilcnt64_t f_ffree;
#endif
    __fsid_t f_fsid;
    __SWORD_TYPE f_namelen;
    __SWORD_TYPE f_frsize;
    __SWORD_TYPE f_spare[5];
  };
 */ 
  
  
  