-- MySQL dump 10.13  Distrib 5.5.46, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.46-0ubuntu0.14.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(11) NOT NULL,
  `symbol` varchar(25) NOT NULL,
  `status` varchar(25) NOT NULL,
  `shares` int(11) NOT NULL,
  `price` decimal(65,4) NOT NULL DEFAULT '0.0000',
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`date`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (11,'CBA','BUY',1000,8.9100,'2016-06-07 12:45:27'),(13,'ASX','BUY',200,5.7300,'2016-06-07 14:27:51'),(11,'ASX','BUY',100,5.7300,'2016-06-08 00:10:49'),(11,'CBA','BUY',20,9.0100,'2016-06-08 00:32:40'),(11,'CBA','BUY',200,9.0100,'2016-06-08 01:02:55'),(11,'CBA','SELL',200,9.0100,'2016-06-08 01:04:53'),(11,'ASX','BUY',124,5.7300,'2016-06-08 01:41:59'),(11,'ASX','BUY',145,5.7300,'2016-06-08 01:42:25'),(11,'ASX','BUY',100,5.7300,'2016-06-08 01:43:28'),(11,'CBA','BUY',100,9.0100,'2016-06-08 01:44:09'),(9,'ASX','BUY',123,5.7300,'2016-06-08 01:44:38'),(9,'CBA','BUY',100,9.0100,'2016-06-08 01:46:51'),(9,'GOOGL','BUY',10,731.0900,'2016-06-08 01:48:38'),(9,'ASX','BUY',100,5.7300,'2016-06-08 01:50:27'),(11,'ASX','BUY',100,5.7300,'2016-06-08 04:28:33'),(9,'ASX','BUY',5,5.7300,'2016-06-08 04:29:08'),(9,'CBA','BUY',1,9.0100,'2016-06-08 04:38:39'),(9,'ASX','BUY',1,5.7300,'2016-06-08 04:41:42'),(9,'ASX','BUY',5,5.7300,'2016-06-08 04:43:56'),(9,'ASX','BUY',2,5.7300,'2016-06-08 04:47:58'),(9,'ASX','BUY',3,5.7300,'2016-06-08 04:48:27'),(9,'CBA','BUY',2,9.0100,'2016-06-08 05:24:06'),(9,'ASX','BUY',2,5.7300,'2016-06-08 05:25:29'),(9,'GOOGL','BUY',5,731.0900,'2016-06-08 05:26:55'),(9,'GOOGL','BUY',1,731.0900,'2016-06-08 05:29:03'),(9,'GOOGL','BUY',2,731.0900,'2016-06-08 05:32:17'),(9,'ASX','BUY',2,5.7300,'2016-06-08 05:38:23'),(9,'ASX','BUY',15,5.7300,'2016-06-08 05:39:04'),(9,'ASX','BUY',9,5.7300,'2016-06-08 06:05:37'),(9,'ASX','BUY',20,5.7300,'2016-06-08 06:06:49');
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolio`
--

DROP TABLE IF EXISTS `portfolio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolio` (
  `id` int(11) NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` varchar(255) NOT NULL,
  PRIMARY KEY (`id`,`symbol`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolio`
--

LOCK TABLES `portfolio` WRITE;
/*!40000 ALTER TABLE `portfolio` DISABLE KEYS */;
INSERT INTO `portfolio` VALUES (9,'ASX','29'),(9,'CBA','24');
/*!40000 ALTER TABLE `portfolio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  `emailId` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'andi','$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS',10000.0000,''),(2,'caesar','$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa',10000.0000,''),(3,'eli','$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW',10000.0000,''),(4,'hdan','$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G',10000.0000,''),(5,'jason','$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe',10000.0000,''),(6,'john','$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy',10000.0000,''),(7,'levatich','$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK',10000.0000,''),(8,'rob','$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2',10000.0000,''),(9,'skroob','$2y$10$395b7wODm.o2N7W5UZSXXuXwrC0OtFB17w4VjPnCIn/nvv9e4XUQK',14267.8400,''),(10,'zamyla','$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e',10000.0000,''),(11,'punya','$2y$10$fv9inZcVcd3aRcCU2rjfDuXDI72s2imWMMT0vsRvbiKfs9TwywXVC',91773.6300,'punyachapagain@yahoo.com'),(12,'punya12','$2y$10$oB8q9x2In2dtEIiIK3oOlO56NtLmNidIVrRkBWk9PV6mei/I.orou',10000.0000,'');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-06-08  6:23:16
