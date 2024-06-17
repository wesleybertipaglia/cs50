-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports;

SELECT * FROM interviews WHERE transcript LIKE '%confess%' OR transcript LIKE '%steal%';

SELECT atm_transactions.*
FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year >= <crime_year> AND atm_transactions.month >= <crime_month>
AND atm_transactions.day >= <crime_day>;

SELECT flights.*, airports.city
FROM flights
JOIN airports ON flights.destination_airport_id = airports.id
WHERE flights.year >= <crime_year> AND flights.month >= <crime_month>
AND flights.day >= <crime_day>;

SELECT * FROM phone_calls WHERE caller = '<suspect_phone>' OR receiver = '<suspect_phone>';

SELECT * FROM bakery_security_logs
WHERE license_plate IN (
    SELECT license_plate FROM people WHERE name = '<suspect_name>'
);
