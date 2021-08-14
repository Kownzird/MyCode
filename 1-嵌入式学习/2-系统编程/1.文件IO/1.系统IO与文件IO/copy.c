#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>  // 全局变量: errno(0:正常,  非0:异常)
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("用法: %s <源文件> <目标文件>\n", argv[0]);	
		exit(0);
	}
	
	/*********************************************
	 *       使用系统IO的方式来拷贝文件
	 * ******************************************/

	// 1，打开文件
	// 当第一个参数包含O_CREAT时，需要指定权限
	int fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1)
	{
		perror("打开源文件失败");
		exit(0);
	}

	int fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if(fd2 == -1)
	{
		printf("打开【%s】失败: %s\n", argv[2], strerror(errno));
		exit(0);
	}

	// 2，定义数组，并且循环地读取源文件的内容
	char *buf = calloc(1, 1000);

	while(1)
	{
		int n = read(fd1, buf, 1000);

		if(n == 0)
		{
			printf("拷贝完毕！\n");
			break;
		}

		if(n == -1)
		{
			perror("读取源文件失败");
			printf("读取【%s】失败: %s\n", argv[1], strerror(errno));
			break;
		}

		write(fd2, buf, n);
	}

	// 3，释放相应资源
	free(buf);

	close(fd1);
	close(fd2);


	/**************************************************
	 *       使用标准IO的方式来拷贝文件（文本文件）
	 * ***********************************************/
#if 0
	// 1，打开文件
	FILE *fp1 = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "w");

	// 2，不断读取源文件，并且写入目标文件
	buf = calloc(1, 1000);
	while(1)
	{
		if(fgets(buf, 1000, fp1) == NULL)
		{
			// a. 出错了！
			if(ferror(fp1))
			{
				perror("读取目标文件失败");
				break;
			}

			// b. 读完了！
			if(feof(fp1))
			{
				printf("恭喜！读完收工！\n");
				break;
			}
		}
		fputs(buf, fp2);
	}

	// 3，释放相应的资源
	free(buf);

	fclose(fp1);
	fclose(fp2);

#else

	/**************************************************
	 *      使用标准IO的方式来拷贝文件（二进制文件）
	 * ***********************************************/

	FILE *fp1 = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "w");

	buf = calloc(1, 1000);
	while(1)
	{
		// 马上要读数据了，这次可能就是最后一次
		long begin = ftell(fp1);

		int n = fread(buf, 200, 5, fp1); // 1000 => 5（读到的块数【取整】)
		//                                  950  => 4
		//                                  200  => 1
		//                                  199  => 0
		//                                  1    => 0

		if(n < 5)
		{
			// a. 出错了！
			if(ferror(fp1))
			{
				perror("读取目标文件失败");
				break;
			}

			// b. 读完了！
			if(feof(fp1))
			{
				printf("恭喜！读完收工！\n");

				// 马上计算真正读到的字节数
				long end = ftell(fp1);
				fwrite(buf, end-begin, 1, fp2);
				break;
			}
		}

		fwrite(buf, 200, 5, fp2);
	}

	// 3，释放相应的资源
	free(buf);

	fclose(fp1);
	fclose(fp2);

#endif

	return 0;
}
