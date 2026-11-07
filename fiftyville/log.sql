--Firstly getting the description from the crime scene on that day
SELECT description FROM crime_scene_reports WHERE year=2024 AND month=7 AND day=28 AND street='Humphrey Street';
--Theft took place at 10:15am and interviews were conducted with three witnesses


--checking the interviews of the witnesses for clues
SELECT * FROM interviews WHERE year=2024 AND month=7 AND day=28;
--7count.  Ruth, Eugene , Raymond were the three witnesses...thief left within 10 minutes of the theft....thief was
--withdrawing money at the ATM on Legett Street before the theft. As they were leaving the bakery, the thief called someone
-- for less than a minute
--and they were planning to take the earliest flight the next day and asked the other person to book the tickets


--people who exited the bakery in the given time frame
SELECT people.* FROM people JOIN bakery_security_logs ON people.license_plate=bakery_security_logs.license_plate WHERE year=2024
 AND month=7 AND day=28 AND hour =10 AND minute BETWEEN 15 AND 25 AND
activity='exit';

--checking the people who withdrew money from Leggett Street on the given day to see whose number plate matches to tjose
--coming out of the bakery in the given time
SELECT people.name, atm_transactions.* FROM atm_transactions JOIN bank_accounts ON atm_transactions.account_number=bank_accounts.account_number
JOIN people ON bank_accounts.person_id=people.id WHERE atm_transactions.year=2024
AND atm_transactions.month=7 AND atm_transactions.day=28 AND atm_transactions.atm_location='Leggett Street' AND atm_transactions.transaction_type='withdraw'
AND people.license_plate IN (SELECT people.license_plate FROM people JOIN bakery_security_logs ON people.license_plate=bakery_security_logs.license_plate WHERE year=2024
AND month=7 AND day=28 AND hour =10 AND minute BETWEEN 15 AND 25 AND
activity='exit');
--4 people. Bruce, Diana, Iman and Luca are the suspects right now

--checking the earliest flights the next day
SELECT flights.* FROM flights JOIN airports ON flights.origin_airport_id=airports.id
WHERE year=2024 AND month= AND day=29 AND airports.city='Fiftyville';
--earliest flights are at 8.20 and 9.30

SELECT airports.city, flights.* FROM flights JOIN airports ON flights.destination_airport_id=airports.id
WHERE year=2024 AND month=7 AND day=29 AND hour IN (8,9) AND origin_airport_id IN ( SELECT id FROM airports
WHERE city = 'Fiftyville');
--the flights at 8.20 go to New York and at 9.30 go to Chicago

--checking who among the suspects matches the witness's statement of them calling someone after robbery
SELECT people.name,phone_calls.* FROM phone_calls JOIN people ON phone_calls.caller=people.phone_number WHERE
phone_calls.duration<=60 AND people.name IN
(SELECT people.name FROM atm_transactions JOIN bank_accounts ON atm_transactions.account_number=bank_accounts.account_number
JOIN people ON bank_accounts.person_id=people.id WHERE atm_transactions.year=2024
AND atm_transactions.month=7 AND atm_transactions.day=28 AND atm_transactions.atm_location='Leggett Street' AND atm_transactions.transaction_type='withdraw'
AND people.license_plate IN (SELECT people.license_plate FROM people JOIN bakery_security_logs ON people.license_plate=bakery_security_logs.license_plate WHERE year=2024
AND month=7 AND day=28 AND hour =10 AND minute BETWEEN 15 AND 25 AND
activity='exit'));
--Bruce and Diana are the only suspects who called on that day for less than 1 minute

--check who among bruce or diana boarded the listed flight the next day
SELECT flights.*, people.name FROM people JOIN passengers ON people.passport_number=passengers.passport_number JOIN
flights ON flights.id=passengers.flight_id WHERE flights.year=2024 AND flights.month=7 AND flights.day=29 AND flights.hour IN (8,9) AND
flights.origin_airport_id IN ( SELECT id FROM airports WHERE city = 'Fiftyville') AND people.name IN ('Bruce', 'Diana');
--Bruce took the 8.20 flight to New York and hence is the robber

--finally checking whom did bruce call and who his accomplice was
SELECT people.name FROM phone_calls JOIN people ON phone_calls.receiver=people.phone_number WHERE phone_calls.year=2024
AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.caller IN (SELECT phone_number FROM people WHERE name='Bruce')
AND phone_calls.duration<60;
--Robin is the accomplice
