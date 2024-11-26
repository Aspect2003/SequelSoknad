-- phpMyAdmin SQL Dump
-- version 4.0.4
-- http://www.phpmyadmin.net
--
-- Vert: localhost
-- Generert den: 16. Sep, 2024 15:18 PM
-- Tjenerversjon: 5.6.12-log
-- PHP-Versjon: 5.4.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `lab1`
--
CREATE DATABASE IF NOT EXISTS `lab1` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `lab1`;

-- --------------------------------------------------------

--
-- Tabellstruktur for tabell `encounters`
--

CREATE TABLE IF NOT EXISTS `encounters` (
  `RaidID` int(255) NOT NULL,
  `Encounters` int(255) NOT NULL,
  PRIMARY KEY (`RaidID`),
  KEY `idx_encounters_raidid` (`RaidID`),
  KEY `idx_encounters_encounters` (`Encounters`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dataark for tabell `encounters`
--

INSERT INTO `encounters` (`RaidID`, `Encounters`) VALUES
(6, 2),
(7, 3),
(10, 3),
(2, 4),
(5, 4),
(9, 4),
(11, 4),
(12, 4),
(13, 4),
(14, 4),
(1, 5),
(4, 5),
(15, 5),
(3, 6),
(8, 6);

-- --------------------------------------------------------

--
-- Tabellstruktur for tabell `enemy`
--

CREATE TABLE IF NOT EXISTS `enemy` (
  `RaidID` int(255) NOT NULL,
  `Enemy` varchar(255) NOT NULL,
  KEY `idx_enemy_raidid` (`RaidID`),
  KEY `idx_enemy_enemy` (`Enemy`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dataark for tabell `enemy`
--

INSERT INTO `enemy` (`RaidID`, `Enemy`) VALUES
(1, 'Vex'),
(2, 'Hive'),
(3, 'Hive'),
(4, 'Taken'),
(5, 'Fallen (SIVA)'),
(6, 'Cabal'),
(7, 'Vex'),
(8, 'Cabal'),
(9, 'Taken'),
(10, 'Fallen'),
(11, 'Hive'),
(12, 'Vex'),
(13, 'Fallen'),
(14, 'Scorn'),
(14, 'Scorn'),
(15, 'The Dread'),
(15, 'Vex'),
(15, 'Cabal'),
(15, 'Hive'),
(15, 'Taken'),
(15, 'Scorn');

-- --------------------------------------------------------

--
-- Tabellstruktur for tabell `raid`
--

CREATE TABLE IF NOT EXISTS `raid` (
  `RaidID` int(255) NOT NULL,
  `Raid` varchar(255) NOT NULL,
  `Location` varchar(255) NOT NULL,
  `ReleaseYear` year(4) NOT NULL,
  PRIMARY KEY (`RaidID`),
  KEY `idx_raid_location` (`Location`),
  KEY `idx_raid_releaseyear` (`ReleaseYear`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dataark for tabell `raid`
--

INSERT INTO `raid` (`RaidID`, `Raid`, `Location`, `ReleaseYear`) VALUES
(1, 'Vault of Glass', 'Venus', 2014),
(2, 'Crota''s End', 'Moon', 2014),
(3, 'Kings Fall', 'Dreadnaught', 2015),
(4, 'Wrath of the Machine', 'Plagueplands', 2016),
(5, 'Leviathan', 'Nessus Orbit', 2017),
(6, 'Eater of Worlds', 'Nessus Orbit', 2017),
(7, 'Spire of Stars', 'Nessus Orbit', 2018),
(8, 'Last Wish', 'The Dreaming City', 2018),
(9, 'Scourge of the Past', 'The Last City', 2018),
(10, 'Crown of Sorrows', 'Nessus Orbit', 2019),
(11, 'Garden of Salvation', 'Black Garden', 2019),
(12, 'Deep Stone Crypt', 'Europa', 2020),
(13, 'Vow of the Disciple', 'Throne World', 2022),
(14, 'Root of Nightmares', 'Neomuna', 2023),
(15, 'Salvations Edge', 'The Pale Heart', 2024);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
