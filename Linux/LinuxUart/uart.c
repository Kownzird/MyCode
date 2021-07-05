/*receive.c  û���߳�*/
#include <stdio.h>      /*��׼�����������*/
#include <stdlib.h>     /*��׼�����ⶨ��*/
#include <unistd.h>     /*Unix��׼��������*/
#include <string.h>
#include <sys/types.h>  /**/
#include <sys/stat.h>   /**/
#include <fcntl.h>      /*�ļ����ƶ���*/
#include <termios.h>    /*PPSIX�ն˿��ƶ���*/
#include <errno.h>      /*����Ŷ���*/
#define  TRUE 0
#define  FALSE -1
#define  RUN_SYSTEM "system:run"
/***@brief  ���ô���ͨ������
*@param  fd     ����int  �򿪴��ڵ��ļ����
*@param  speed  ����int  �����ٶ�
*@return  void*/



int speed_arr[] = {B115200, B38400, B19200, B9600, B4800, B2400, B1200, B300,
	    B38400, B19200, B9600, B4800, B2400, B1200, B300, };
int name_arr[] = {115200,38400,  19200,  9600,  4800,  2400,  1200,  300,
	    38400,  19200,  9600, 4800, 2400, 1200,  300, };
	     
//���ò�����
void set_speed(int fd, int speed)
{
  int   i;
  int   status;
  struct termios   Opt;
  tcgetattr(fd, &Opt);
  for ( i= 0;  i < sizeof(speed_arr) / sizeof(int);  i++)
   {
   	if  (speed == name_arr[i])
   	{
   	    tcflush(fd, TCIOFLUSH);  //��մ��ڵĻ����� 
    	cfsetispeed(&Opt, speed_arr[i]);
    	cfsetospeed(&Opt, speed_arr[i]);
    	status = tcsetattr(fd, TCSANOW, &Opt);
    	if  (status != 0)
            perror("tcsetattr fd1");
     	return;
     	}
   		tcflush(fd,TCIOFLUSH);//��մ��ڵĻ����� 
   }
}
/**
*@brief   ���ô�������λ��ֹͣλ��Ч��λ
*@param  fd     ���� int  �򿪵Ĵ����ļ����*
*@param  databits ���� int ����λ  ȡֵΪ7 ����*
*@param  stopbits ���� int ֹͣλ  ȡֵΪ1 ����*
*@param  parity  ���� int  Ч������ȡֵΪN,E,O,,S
*/
//�����Ƿ�õıȽ��������� ����ֱ��ʹ�� 
static int set_Parity(int fd, int databits, int stopbits, int parity)
{
	struct termios options;
	
	if(tcgetattr(fd,&options)!=0) 
	{ 
		perror("SetupSerial 1");     
		return(FALSE);  
	}
	options.c_cflag &= ~CSIZE;
	
	switch (databits) /*��������λ��*/
	{   
		case 7:		
			options.c_cflag |= CS7; 
			break;
		case 8:     
			options.c_cflag |= CS8;
			break;   
		default:    
			fprintf(stderr,"Unsupported data size\n"); return (FALSE);  
	}
	//����У������
	switch (parity) 
	{   
		case 'n':
		case 'N':    
			options.c_cflag &= ~PARENB;   /* Clear parity enable */
			options.c_iflag &= ~INPCK;     /* Enable parity checking */ 
			break;  
		case 'o':   
		case 'O':     
			options.c_cflag |= (PARODD | PARENB); /* ����Ϊ��Ч��*/  
			options.c_iflag |= INPCK;             /* Disnable parity checking */ 
			break;  
		case 'e':  
		case 'E':   
			options.c_cflag |= PARENB;     /* Enable parity */    
			options.c_cflag &= ~PARODD;   /* ת��ΪżЧ��*/     
			options.c_iflag |= INPCK;       /* Disnable parity checking */
			break;
		case 'S': 
		case 's':  /*as no parity*/   
	    		options.c_cflag &= ~PARENB;
			options.c_cflag &= ~CSTOPB;break;  
		default:   
			fprintf(stderr,"Unsupported parity\n");    
			return (FALSE);  
	} 
	 
	//����ֹͣλ  
	switch (stopbits)
	{   
		case 1:
			options.c_cflag &= ~CSTOPB;
			break;  
		case 2:    
			options.c_cflag |= CSTOPB;  
	   		break;
		default:    
		 	fprintf(stderr,"Unsupported stop bits\n");  
		 	return (FALSE); 
	} 
	
	/* Set input parity option */ 
	if (parity != 'n')options.c_iflag |= INPCK ; 
	//��bitλ  �ر��ַ�ӳ�� 0x0a 0x0d
	options.c_iflag &= ~(INLCR|ICRNL);
	//��bitλ  �ر������ַ� 0x11 0x13 
	options.c_iflag &= ~(IXON);
	
	//��Ҫע�����:
	//������ǿ����ն�֮��ģ�ֻ�Ǵ��ڴ������ݣ�������Ҫ������������ôʹ��ԭʼģʽ(Raw Mode)��ʽ��ͨѶ�����÷�ʽ���£� 
	options.c_lflag  &= ~(ICANON | ECHO | ECHOE | ISIG);  /*Input*/
	options.c_oflag  &= ~OPOST;   /*Output*/

	tcflush(fd,TCIFLUSH);
	options.c_cc[VTIME]=100;//���ó�ʱ10��
	options.c_cc[VMIN] = 0; /* Update the options and do it NOW */
	if (tcsetattr(fd,TCSANOW,&options) != 0)   
	{ 
		perror("SetupSerial 3");   
		return (FALSE);  
	} 
	return (TRUE);  
}
/**
*@breif �򿪴���
*/
int OpenDev(char *Dev)
{
int	fd = open( Dev, O_RDWR| O_NOCTTY | O_NDELAY );         //
	if (-1 == fd)
		{ /*��������λ��*/
			perror("Can't Open Serial Port");
			return -1;
		}
	printf("Open Serial Success\n");
	return fd;
}
/**
*@breif 	main()
*/
//������ 
int main(int argc, char **argv)
{
	int fd;  //�򿪴��ڵ��ļ����
	int nread,nreads;
	//���ý��ջ������Ĵ�С
	char buff[1024];
	//����һ��һ���ֽڵĽ��� 
	char uart_0=0;
	
	//����һ���ַ��� 
	char buffs[]="Hello\n";
	//����һ��16���Ƶ��� 
	char buff2[1024];

	//COM1�����ļ�	
	char *dev ="/dev/ttyUSB0";
	//�򿪴����ļ� 
	fd = OpenDev(dev);
	
	
	
	//����ļ��򿪳ɹ� 
	if (fd>0)
	{
    	set_speed(fd,921600);//���ò�����	
	}
	else
	{
		printf("Can't Open Serial Port!\n");
		exit(0);
	}
	
	//���ô��ڵ����� 
	if (set_Parity(fd,8,1,'N')== FALSE)
    {
    	printf("Set Parity Error\n");
    	exit(1);
  	}
  	
  	//�ô��ڷ���16��������ʵ�� 
	buff2[0]=0xff;
	buff2[1]=0xfe;
	//buff2[2]='\0';
	
	//�ô��ڷ����ַ�����ʵ�� 
	//nreads=write(fd,buffs,sizeof(buffs));
	//�ô��ڷ���16��������ʵ�� 
	//nreads=write(fd,buff2,2);
	
  	//ѭ�����մ��ڵ����� 
    while(1)
  	{
		
  		//������ڻ������������� 
		// if((nread = read(fd,buff,1024))>0)
   		// {
   		// 	//������ַ����ô˷�����ʾ 
     	//   	printf("%s",buff);
		// 	printf("%ld",strlen(buff));
			
			
			
     	  	
			
     	//   	//����Է����͵���16���Ƶ��������ô˷������� 
  	  	//     printf("\n%d",buff[1]);
    	//   	printf("\n%d",buff[2]);
    	//     printf("\n%d",buff[3]);
    	//     printf("\n%d",buff[4]);
    	//   	printf("\n%d",buff[5]);
    	//  	printf("\n%d",buff[6]);
    	//   	printf("\n%d",buff[7]);
    	//  	printf("\n%d",buff[8]);
	 	//     printf("\n%d",buff[9]);
			
		// 	//uart_0=0;
    
    	// 	//��մ��ڵĻ����� 
		// 	tcflush(fd,TCIFLUSH);
		// 	//������� 
      	// 	bzero(buff,1024);
   	 	// }   
   	 	// else
   	 	// {
	    // 	usleep(1); 
   	 	// }
		
		write(fd,RUN_SYSTEM,strlen(RUN_SYSTEM));
		sleep(5);
		
   	}
   	
   	//�رմ����ļ� 
    close(fd);
    exit(0);
}

