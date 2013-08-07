INSERT INTO documents.pathparts (path,md5)
VALUES ( '__SPECIAL_DEEPNET_PATH_PART_END_MARKER__', '258500cd7b3da8087b787eb202901460');

SET foreign_key_checks = 0;

INSERT INTO 
  documents.urlpathparts (PATHPART_ID,URLPATHPART_ID_NEXT)
SELECT
  pp.ID,
  0
FROM documents.pathparts pp
WHERE pp.path = "__SPECIAL_DEEPNET_PATH_PART_END_MARKER__";
SET @urlpathpart = LAST_INSERT_ID();

SET foreign_key_checks = 1;

UPDATE  documents.urlpathparts
SET URLPATHPART_ID_NEXT = @urlpathpart;
