\c deepnet

CREATE FUNCTION after_insert_urls() RETURNS trigger AS $emp_stamp$
BEGIN
    IF NEW.SECONDLEVELDOMAIN_ID IS NULL THEN
        RAISE EXCEPTION 'SECONDLEVELDOMAIN_ID cannot be null';
    END IF;

    INSERT INTO deepnet.public.syncurls (URL_ID, SECONDLEVELDOMAIN_ID, CRAWLERSESSION_ID, schedule) 
		VALUES ( NEW.ID, NEW.SECONDLEVELDOMAIN_ID, 0, NOW() AT TIME ZONE 'UTC' );

    INSERT INTO deepnet.public.locksecondleveldomain (SECONDLEVELDOMAIN_ID, CRAWLERSESSION_ID, schedule) 
		VALUES (NEW.SECONDLEVELDOMAIN_ID, 0, NOW() AT TIME ZONE 'UTC' );

    RETURN NULL;
END;
$emp_stamp$ LANGUAGE plpgsql;

CREATE TRIGGER after_insert_urls AFTER INSERT ON deepnet.public.urls
    FOR EACH ROW EXECUTE PROCEDURE after_insert_urls();
