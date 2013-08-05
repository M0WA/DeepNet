\c deepnet

CREATE FUNCTION after_insert_urls() RETURNS trigger AS $emp_stamp$
BEGIN
    IF NEW.SECONDLEVELDOMAIN_ID IS NULL THEN
        RAISE EXCEPTION 'SECONDLEVELDOMAIN_ID cannot be null';
    END IF;

    INSERT INTO deepnet.public.syncurls (URL_ID, SECONDLEVELDOMAIN_ID, CRAWLERSESSION_ID, schedule) 
		VALUES ( NEW.ID, NEW.SECONDLEVELDOMAIN_ID, 0, NOW() AT TIME ZONE 'UTC' );

    BEGIN
      INSERT INTO deepnet.public.locksecondleveldomain
        (SECONDLEVELDOMAIN_ID, CRAWLERSESSION_ID, schedule) 
      VALUES ( NEW.SECONDLEVELDOMAIN_ID, 0, NOW() AT TIME ZONE 'UTC');
    EXCEPTION WHEN unique_violation THEN
    END;

    RETURN NULL;
END;

$emp_stamp$ LANGUAGE plpgsql;

CREATE FUNCTION before_insert_urlpathparts() RETURNS trigger AS $emp_stamp$
BEGIN
  IF NEW.URLPATHPART_ID_NEXT IS NULL AND EXISTS(SELECT 1 FROM deepnet.public.urlpathparts tmp WHERE tmp.PATHPART_ID=NEW.PATHPART_ID AND tmp.URLPATHPART_ID_NEXT IS NULL) THEN
    RETURN NULL;
  END IF;

  RETURN NEW;
END;

$emp_stamp$ LANGUAGE plpgsql;

CREATE TRIGGER after_insert_urls AFTER INSERT ON deepnet.public.urls
    FOR EACH ROW EXECUTE PROCEDURE after_insert_urls();

CREATE TRIGGER before_insert_urlpathparts BEFORE INSERT ON deepnet.public.urlpathparts
    FOR EACH ROW EXECUTE PROCEDURE before_insert_urlpathparts();
