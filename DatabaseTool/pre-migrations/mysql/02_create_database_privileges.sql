CREATE USER 'write'@'localhost' IDENTIFIED BY 'Ahrah5leFup5BaidYoh1INgiKa9soocoael3eaLeiV8ooVauquee8SohzeeF2oa0';
CREATE USER 'read'@'localhost' IDENTIFIED BY 'kiz8Cah7ooW0fiehChi8shaikaeseQu2Oow4iex6bi7IiCaiaiyouM2lxohsh9Sh';

GRANT SELECT, UPDATE, INSERT, DELETE ON `sync`.* TO 'write'@'localhost';
GRANT SELECT ON `sync`.* TO 'read'@'localhost';

GRANT SELECT, UPDATE, INSERT, DELETE ON `content`.* TO 'write'@'localhost';
GRANT SELECT ON `content`.* TO 'read'@'localhost';

GRANT SELECT, UPDATE, INSERT, DELETE ON `lexicon`.* TO 'write'@'localhost';
GRANT SELECT ON `lexicon`.* TO 'read'@'localhost';

GRANT SELECT, UPDATE, INSERT, DELETE ON `documents`.* TO 'write'@'localhost';
GRANT SELECT ON `documents`.* TO 'read'@'localhost';

GRANT SELECT, UPDATE, INSERT, DELETE ON `queryserver`.* TO 'write'@'localhost';
GRANT SELECT ON `queryserver`.* TO 'read'@'localhost';

GRANT SELECT, UPDATE, INSERT, DELETE ON `webifserver`.* TO 'write'@'localhost';
GRANT SELECT ON `webifserver`.* TO 'read'@'localhost';

GRANT SELECT, UPDATE, INSERT, DELETE ON `logging`.* TO 'write'@'localhost';
GRANT SELECT ON `logging`.* TO 'read'@'localhost';

FLUSH PRIVILEGES;
