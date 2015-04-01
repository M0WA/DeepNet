\c deepnet

INSERT INTO deepnet.public.pathparts (path,md5)
VALUES ( '__SPECIAL_DEEPNET_PATH_PART_END_MARKER__', '258500cd7b3da8087b787eb202901460');

ALTER TABLE deepnet.public.urlpathparts DISABLE TRIGGER ALL;

INSERT INTO 
  deepnet.public.urlpathparts (PATHPART_ID,URLPATHPART_ID_NEXT)
SELECT
  pp.ID,
  0
FROM deepnet.public.pathparts pp
WHERE pp.path = '__SPECIAL_DEEPNET_PATH_PART_END_MARKER__';

UPDATE deepnet.public.urlpathparts
SET URLPATHPART_ID_NEXT = (SELECT id FROM deepnet.public.urlpathparts LIMIT 1);

ALTER TABLE deepnet.public.urlpathparts ENABLE TRIGGER ALL;
