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

/*
    INSERT INTO deepnet.public.locksecondleveldomain 
      (SECONDLEVELDOMAIN_ID, CRAWLERSESSION_ID, schedule)
    SELECT
      NEW.SECONDLEVELDOMAIN_ID,
      0,
      NOW() AT TIME ZONE 'UTC'
    FROM
      deepnet.public.locksecondleveldomain nvi
    WHERE NOT EXISTS (
      SELECT 1
      FROM deepnet.public.locksecondleveldomain up
      WHERE up.SECONDLEVELDOMAIN_ID=NEW.SECONDLEVELDOMAIN_ID
    );

*/


/*
    WITH vals
      (SECONDLEVELDOMAIN_ID, CRAWLERSESSION_ID, schedule)
    AS
      (VALUES (NEW.SECONDLEVELDOMAIN_ID, 0, NOW() AT TIME ZONE 'UTC') ),
    upsert AS (
        UPDATE
          deepnet.public.locksecondleveldomain m
        SET
          SECONDLEVELDOMAIN_ID=nvu.SECONDLEVELDOMAIN_ID,
          CRAWLERSESSION_ID=nvu.CRAWLERSESSION_ID,
          schedule=nvu.schedule
        FROM vals nvu
        WHERE
          m.SECONDLEVELDOMAIN_ID=nvu.SECONDLEVELDOMAIN_ID
        AND
          m.CRAWLERSESSION_ID=nvu.CRAWLERSESSION_ID
        RETURNING m.* )
    INSERT INTO deepnet.public.locksecondleveldomain
      (SECONDLEVELDOMAIN_ID, CRAWLERSESSION_ID, schedule)
    SELECT
      SECONDLEVELDOMAIN_ID, CRAWLERSESSION_ID, schedule
    FROM vals nvi
    WHERE NOT EXISTS (
      SELECT 1
      FROM upsert up
      WHERE SECONDLEVELDOMAIN_ID=nvi.SECONDLEVELDOMAIN_ID
      AND CRAWLERSESSION_ID=nvi.CRAWLERSESSION_ID 
    );
*/

    RETURN NULL;
END;
$emp_stamp$ LANGUAGE plpgsql;

CREATE TRIGGER after_insert_urls AFTER INSERT ON deepnet.public.urls
    FOR EACH ROW EXECUTE PROCEDURE after_insert_urls();
