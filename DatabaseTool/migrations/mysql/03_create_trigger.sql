USE `documents`;

DELIMITER |

CREATE TRIGGER `after_insert_urls` AFTER INSERT ON `documents`.`urls`
  FOR EACH ROW
  BEGIN
    INSERT INTO `sync`.`syncurls` (`URL_ID`, `SECONDLEVELDOMAIN_ID`, `CRAWLERSESSION_ID`, `schedule`) 
		VALUES ( NEW.`ID`, NEW.`SECONDLEVELDOMAIN_ID`, 0, UTC_TIMESTAMP() );

    INSERT INTO `sync`.`locksecondleveldomain` (`SECONDLEVELDOMAIN_ID`, `CRAWLERSESSION_ID`, `schedule`) 
		VALUES (NEW.`SECONDLEVELDOMAIN_ID`, 0, UTC_TIMESTAMP() ) ON DUPLICATE KEY UPDATE `SECONDLEVELDOMAIN_ID`=`SECONDLEVELDOMAIN_ID`;
  END;
|

DELIMITER ;
