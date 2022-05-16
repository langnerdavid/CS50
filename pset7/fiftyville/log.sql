-- Keep a log of any SQL queries you execute as you solve the mystery.
-- July 28, 2021 on Humphrey Street

SELECT desciption FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28
AND street = "Humphrey Street";
-- find out what happened
-->10.15am
 --> 3 intervies with 3 witnesses

--find out whats in the interviews
SELECT transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28;
--never bought anything
--came half an hour earlier on the phone(9:45AM)
--as he left he talked to someone less than a minute
--earliest flight out of fiftyville on 29. july
--was on legget street earlier in the morning withdraw sth at atm
--accomplice purchased the flight tickets

--find out what flight they took
SELECT * FROM flights
WHERE year = 2021 AND month = 7 AND day = 29
AND origin_airport_id =
(SELECT id FROM airports
WHERE city = "Fiftyville");
--> flight id 36 or 43 because they are early in the morning

--look at atm transaction on 28th July
SELECT people.name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28
AND atm_transactions.atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw";
--> all possible suspects

--cross reference with bakery security logs who checked in at about 9:45

SELECT people.name FROM people
WHERE people.name IN
    (SELECT people.name FROM people
    JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
    WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7
    AND bakery_security_logs.day = 28 AND (bakery_security_logs.hour = 9 OR
    (bakery_security_logs.hour = 10 AND bakery_security_logs.hour < 16)))
        AND people.name IN
    (SELECT people.name FROM people
    JOIN bank_accounts ON bank_accounts.person_id = people.id
    JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
    WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28
    AND atm_transactions.atm_location = "Leggett Street"
    AND atm_transactions.transaction_type = "withdraw");
--> Luca, Iman, Taylor, Diana, Bruce possible suspects

-->check with  phone records who has made at least two phone calls
SELECT * FROM phone_calls
WHERE caller = (SELECT phone_number FROM people
WHERE name = "Bruce") AND year = 2021 AND month = 7 AND day = 28;
--> Luca hasnt made any
--> Iman neither
--> Taylor has made 2 (possible suspect)
--> Diana has made 1
--> Bruce has made 4 (possible suspect)
--> Bruce and Taylor remaining suspects

--look again at bakery sec logs who checked out right after the theft
SELECT people.name, bakery_security_logs.minute FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28 AND bakery_security_logs.hour = 10
AND bakery_security_logs.activity = "exit"
AND (people.name = "Bruce" OR people.name = "Taylor");
--> Taylor left 10:35 20min after the Theft
--> Bruce is the THIEF bc he left 10:18 right after the THEFT

--check who Bruce called:
SELECT people.name FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number
WHERE phone_calls.caller = (SELECT people.phone_number FROM people
WHERE name = "Bruce") AND phone_calls.year = 2021 AND phone_calls.month = 7
AND phone_calls.day = 28 AND phone_calls.duration < 60;
--> only one phone call under a minute so whoever bruce called in that phone call is
-- his accomplice --> RObin is his accomplice

--recalled that its either flight id 36 or 43
SELECT city FROM airports
WHERE id =
(SELECT flights.destination_airport_id FROM passengers
JOIN flights ON flights.id = passengers.flight_id
JOIN people ON people.passport_number = passengers.passport_number
WHERE flight_id IN
    (SELECT flights.id FROM flights
    WHERE flights.year = 2021 AND flights.month = 7
    AND flights.day = 29 AND flights.hour < 12
    AND flights.origin_airport_id =
    (SELECT id FROM airports
    WHERE city = "Fiftyville"))
AND people.name = "Bruce");

-->so Bruce must have escaped to New York City :)
-->mystery finally solved it feels so good :)
--> P.S.: if someone reads this, this was one of the best
--> if not the best pset :) it was really fun solving this mystery
-- and i learned alot from it


