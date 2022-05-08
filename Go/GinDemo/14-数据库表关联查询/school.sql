/*
SQLyog Ultimate v12.08 (32 bit)
MySQL - 8.0.29 : Database - school
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`school` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;

USE `school`;

/*Table structure for table `article` */

DROP TABLE IF EXISTS `article`;

CREATE TABLE `article` (
  `id` int NOT NULL AUTO_INCREMENT,
  `title` varchar(255) DEFAULT NULL,
  `cate_id` int DEFAULT NULL,
  `state` tinyint(1) DEFAULT NULL,
  KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

/*Data for the table `article` */

insert  into `article`(`id`,`title`,`cate_id`,`state`) values (1,'五常达成一致，安理会全票通过涉乌克兰问题声明，古特雷斯也表态',2,1),(2,'被问到“是否支持俄罗斯人持有人民币”，中国驻俄大使回复有水平',1,1),(3,'张纪中怒批新生代演员，战争戏还化妆，拍的一塌糊涂',3,1),(4,'台渔民在钓鱼岛周边偶遇辽宁舰：第一次见这么大阵仗',1,1),(5,'X战警：这枪法，这命中率，燕双鹰都表示自愧不如！',3,1),(6,'卢卡申科：在搞垮俄罗斯之后，美国将全力“解决中国”',2,1),(7,'小米40亿美金资产被印度冻结',4,1);

/*Table structure for table `article_cate` */

DROP TABLE IF EXISTS `article_cate`;

CREATE TABLE `article_cate` (
  `id` int NOT NULL AUTO_INCREMENT,
  `title` varchar(255) DEFAULT NULL,
  `state` tinyint(1) DEFAULT NULL,
  KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

/*Data for the table `article_cate` */

insert  into `article_cate`(`id`,`title`,`state`) values (1,'国内',1),(2,'国际',1),(3,'娱乐',1),(4,'互联网',1);

/*Table structure for table `class` */

DROP TABLE IF EXISTS `class`;

CREATE TABLE `class` (
  `id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `email` varchar(255) DEFAULT NULL,
  `score` tinyint DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

/*Data for the table `class` */

insert  into `class`(`id`,`name`,`email`,`score`) values (1,'张三','zhangsan@qq.com',78),(2,'李四','lisi@qq.com',69),(3,'王五','wangwu@qq.com',88),(4,'孙六','sunliu@163.com',28),(5,'赵气','zhaoqi@gmail.com',97);

/*Table structure for table `lession` */

DROP TABLE IF EXISTS `lession`;

CREATE TABLE `lession` (
  `id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

/*Data for the table `lession` */

insert  into `lession`(`id`,`name`) values (1,'计算机网络'),(2,'Java程序设计'),(3,'软件项目管理'),(4,'物联网');

/*Table structure for table `lession_student` */

DROP TABLE IF EXISTS `lession_student`;

CREATE TABLE `lession_student` (
  `lession_id` int DEFAULT NULL,
  `student_id` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

/*Data for the table `lession_student` */

insert  into `lession_student`(`lession_id`,`student_id`) values (1,1),(2,1),(4,1),(4,2),(2,2),(1,3),(3,3),(1,4),(2,4),(3,4),(4,4),(1,5),(4,6),(2,6);

/*Table structure for table `student` */

DROP TABLE IF EXISTS `student`;

CREATE TABLE `student` (
  `id` int NOT NULL AUTO_INCREMENT,
  `number` int DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  `classId` int DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

/*Data for the table `student` */

insert  into `student`(`id`,`number`,`password`,`classId`,`name`) values (1,160101,'202cb58a55ace59',1,'张三'),(2,160201,'202cb58a55ace59',2,'李四'),(3,160102,'202cb58a55ace59',1,'王五'),(4,160103,'202cb58a55ace59',1,'孙六'),(5,160104,'202cb58a55ace59',1,'赵七'),(6,160202,'202cb58a55ace59',2,'钱八');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
