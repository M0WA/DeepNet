DROP TRIGGER after_insert_urls;

--#SET TERMINATOR @

CREATE TRIGGER after_insert_urls 
  AFTER INSERT ON urls
  REFERENCING
    NEW AS POST
  FOR EACH ROW
  BEGIN ATOMIC
    INSERT INTO syncurls (URL_ID, SECONDLEVELDOMAIN_ID, CRAWLERSESSION_ID, schedule) 
    VALUES ( POST.ID, POST.SECONDLEVELDOMAIN_ID, 0, current timestamp - current timezone );
    

    MERGE INTO locksecondleveldomain lck
      USING (VALUES (POST.SECONDLEVELDOMAIN_ID))
      ON (POST.SECONDLEVELDOMAIN_ID = lck.SECONDLEVELDOMAIN_ID)
    WHEN NOT MATCHED THEN
      INSERT (SECONDLEVELDOMAIN_ID, CRAWLERSESSION_ID, schedule)
      VALUES (POST.SECONDLEVELDOMAIN_ID, 0, current timestamp - current timezone)
    ELSE IGNORE;
  END@

--#SET TERMINATOR ;
