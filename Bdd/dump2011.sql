CREATE TABLE country (
  chCountryCode char(2) NOT NULL default '' PRIMARY KEY ,
  vchCountryDesc varchar(255) NOT NULL default ''
);
INSERT INTO "country" VALUES('FR', 'France');
INSERT INTO "country" VALUES('CA', 'Canada');
INSERT INTO "country" VALUES('US', 'USA');
INSERT INTO "country" VALUES('IT', 'Italie');
INSERT INTO "country" VALUES('GB', 'Great-Britain');
INSERT INTO "country" VALUES('SP', 'Spain');
CREATE TABLE dvd (
  iDVDId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  iUserId int(4) NOT NULL default '0',
  vchDVDTitle varchar(255) NOT NULL default '',
  dtDVDDate year(4) default NULL,
  vchComments varchar(255) default NULL,
  irating int(4) NOT NULL default '0',
  iRegion int(4) NOT NULL default '1',
  dtInsertDate datetime NOT NULL default '0000-00-00 00:00:00',
  genre varchar(255) default NULL
);
INSERT INTO "dvd" VALUES(1, 7, 'Dirty Dancing - édition collector', 1990, 'Patrick Swayze, Jennifer Gray, Jerry Orbach &amp; Cynthia Rhodes.', 4, 1, '2003-01-23 21:41:10','Culte');
INSERT INTO "dvd" VALUES(2, 7, 'Le corniaud et La grande Vadrouille (PACK 2 GRANDS FILMS)', 1990, 'Louis de Funes, Bourvil', 5, 1, '2003-01-23 21:42:06','comédie');
INSERT INTO "dvd" VALUES(3, 2, 'Le tombeau des lucioles', 2000, 'Yoshido Shinohara , Ayano Shiraishi , Tsutomu Tatsumi , Akemi Yamaguchi', 3, 1, '2003-01-23 21:44:37','Action');
INSERT INTO "dvd" VALUES(4, 2, 'Les bronzés - Les bronzés font du ski', 1991, 'Josiane Balasko , Michel Blanc , Marie-Anne Chazel , Maurice Chevit , Christian Clavier , Gérard Jugnot , Dominique Lavanant , Thierry Lhermitte , Bruno Moynot , David Pontremoli', 3, 1, '2003-01-23 21:45:31','comédie');
INSERT INTO "dvd" VALUES(5, 5, 'Le nom de la rose', 1991, 'ELYA BASKIN SEAN CONNERY CHRISTIAN SLATER', 5, 1, '2003-01-23 21:54:31','Aventure');
INSERT INTO "dvd" VALUES(6, 5, 'LARGO WINCH', 1992, 'Avec Paolo Seganti, Sydney Penny.', 3, 1, '2003-01-23 21:55:17','Aventure');
INSERT INTO "dvd" VALUES(7, 3, 'Le Pacte des loups - Ãdition 2 DVD', 2000, 'Samuel Le Bihan', 5, 2, '2003-01-24 12:39:15','Action');
INSERT INTO "dvd" VALUES(8, 3, 'LéonThe Professional', 1994, 'Jean Réno', 3, 1, '2003-01-24 12:39:55','Action');
INSERT INTO "dvd" VALUES(9, 3, 'Braveheart - édition CollectorBraveheart', 1990, 'Mel Gibson', 4, 1, '2003-01-24 12:40:31','Action');
INSERT INTO "dvd" VALUES(10, 3, 'Gladiator - Edition Collector 2 DVDGladiator', 2001, 'Russell Crowe', 3, 1, '2003-01-24 12:41:23','Action');
INSERT INTO "dvd" VALUES(11, 6, 'Apollo 13', 1994, 'Tom Hanks', 3, 1, '2003-01-24 12:47:23','Aventure');
INSERT INTO "dvd" VALUES(12, 6, 'Le Parrain : La Trilogie - Coffret 5 DVDThe Godfather', 1990, 'Marlon Brando', 3, 1, '2003-01-24 12:50:04','Culte');
INSERT INTO "dvd" VALUES(13, 6, 'Pulp Fiction', 1990, 'John Travolta', 3, 1, '2003-01-24 12:50:47','Action');

CREATE TABLE loan (
  iLoanId INTEGER NOT NULL PRIMARY KEY autoincrement,
  iDVDId int(4) NOT NULL default '0',  -- FOREIGN KEY dvd.iDVDId
  iUserId int(4) NOT NULL default '0', -- FOREIGN KEY user.iUserId
  dtLoanDate date NOT NULL default '0000-00-00',
  tiReturned tinyint(4) NOT NULL default '0'
);
INSERT INTO "loan" VALUES(1, 6, 7, '2003-01-24', 0);
INSERT INTO "loan" VALUES(2, 10, 4, '2003-01-24', 0);
INSERT INTO "loan" VALUES(4, 7, 7, '2003-01-24', 0);
INSERT INTO "loan" VALUES(5, 12, 2, '2003-01-24', 1);
INSERT INTO "loan" VALUES(7, 7, 3, '2002-03-21', 1);
INSERT INTO "loan" VALUES(8, 1, 2, '2001-12-2', 1);
INSERT INTO "loan" VALUES(9, 2, 1, '2003-01-21', 1);
INSERT INTO "loan" VALUES(10, 3, 4, '2003-01-20', 1);
CREATE TABLE region (
  chRegionCode char(2) NOT NULL default '' PRIMARY KEY,
  vchRegionDesc varchar(255) NOT NULL default ''
);
INSERT INTO "region" VALUES('BC', 'British Columbia');
INSERT INTO "region" VALUES('WA', 'Washington');
INSERT INTO "region" VALUES('RO', 'Roma');
INSERT INTO "region" VALUES('MI', 'Milan');
INSERT INTO "region" VALUES('RA', 'Rhone-Alpes');
INSERT INTO "region" VALUES('IF', 'Ile de france');
INSERT INTO "region" VALUES('NO', 'Nord');

CREATE TABLE user (
  iUserID INTEGER NOT NULL PRIMARY KEY autoincrement,
  vchEmail varchar(255) NOT NULL default '',
  vchPassword varchar(32) NOT NULL default '',
  vchFirstName varchar(255) NOT NULL default '',
  vchLastName varchar(255) NOT NULL default '',
  vchCity varchar(255) NOT NULL default '',
  chRegionCode char(2) NOT NULL default '',
  chCountryCode char(2) NOT NULL default '',
  tiEnabled tinyint(4) NOT NULL default '0',
  tiAdmin tinyint(4) NOT NULL default '0',
  dtLastVisit datetime NOT NULL default '0000-00-00 00:00:00',
  dtLastCheck datetime NOT NULL default '0000-00-00 00:00:00'
);
INSERT INTO "user" VALUES(1, 'prof@yahoo.com', '741f63d12d767bb3fd2b0251ed839499', 'prof', 'prof', 'france', 'IF', 'FR', 1, 1, '2003-01-27 19:44:51', '0000-00-00 00:00:00');
INSERT INTO "user" VALUES(2, 'eleve1@cours.com', 'cd3dc8b6cffb41e4163dcbd857ca87da', 'eleve1', 'eleve1', 'Champagne', 'RA', 'FR', 1, 1, '2003-01-23 21:46:04', '0000-00-00 00:00:00');
INSERT INTO "user" VALUES(3, 'eleve2@cours.com', '68a9e49bbc88c02083a062a78ab3bf30', 'eleve2', 'eleve2', 'Champagne', 'NO', 'FR', 1, 1, '2003-01-27 19:45:06', '0000-00-00 00:00:00');
INSERT INTO "user" VALUES(4, 'eleve3@cours.com', '7ed21b04c0dcde1c638e5c8480ad0026', 'eleve3', 'eleve3', 'Champagne', 'IF', 'FR', 1, 1, '2003-01-23 21:52:45', '0000-00-00 00:00:00');
INSERT INTO "user" VALUES(5, 'eleve4@cours.com', '38de3f7d221a2910710874b0b220cb26', 'eleve4', 'eleve4', 'Champagne', 'IF', 'FR', 1, 1, '2003-01-24 14:59:42', '0000-00-00 00:00:00');
INSERT INTO "user" VALUES(6, 'eleve5@cours.com', '72baa9d520b127dd4ab03ff904cc1959', 'eleve5', 'eleve5', 'Champagne', 'WA', 'US', 1, 0, '2003-01-24 13:04:04', '0000-00-00 00:00:00');
INSERT INTO "user" VALUES(7, 'eleve6@cours.com', 'f38f5bf94ee2de0b42d1829fbf66ea9c', 'eleve6', 'eleve6', 'Champagne', 'RO', 'IT', 1, 1, '2003-01-24 12:44:50', '0000-00-00 00:00:00');