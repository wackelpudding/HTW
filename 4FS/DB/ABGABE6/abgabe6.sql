CREATE TABLE Hoheitsgebiet (Name VARCHAR(30) NOT NULL, Bescheibung VARCHAR(200), PRIMARY KEY (Name));
CREATE TABLE Kategorie (Kname VARCHAR(30) NOT NULL, Bescheibung VARCHAR(200), PRIMARY KEY (Kname));
CREATE TABLE Ort (OrtID INT UNSIGNED NOT NULL AUTO_INCREMENT, Längengrad VARCHAR(50), Breitengrad VARCHAR(50), PRIMARY KEY (OrtID));
CREATE TABLE Sektor (SektorID INT UNSIGNED NOT NULL AUTO_INCREMENT, OrtID_MAX INT NOT NULL, OrtID_MIN INT NOT NULL, Hoheitsgebiet VARCHAR(30), Tiefe INT, Bescheibung VARCHAR(200), PRIMARY KEY(SektorID), FOREIGN KEY (OrtID_MAX) REFERENCES Ort (OrtID) ON UPDATE NO CASCADE ON DELETE NO ACTION, FOREIGN KEY (OrtID_MIN) REFERENCES Ort (OrtID) ON UPDATE NO CASCADE ON DELETE NO ACTION, FOREIGN KEY (Hoheitsgebiet) REFERENCES Hoheitsgebiet (Name)ON UPDATE NO CASCADE ON DELETE NO ACTION);
CREATE TABLE Adresse (AdrID INT NOT NULL AUTO_INCREMENT, Straße VARCHAR(200), Hausnummer VARCHAR(200), PLZ INT, Ort VARCHAR(200), Land VARCHAR(200), PRIMARY KEY (AdrID));
CREATE TABLE Kunden (KID INT UNSIGNED NOT NULL AUTO_INCREMENT, Name VARCHAR(200), Vorname VARCHAR(200), AdrID INT NOT NULL, Telefonnummer VARCHAR(200), PRIMARY KEY (KID), FOREIGN KEY (AdrID) REFERENCES Adresse (AdrID) ON UPDATE NO CASCADE ON DELETE NO ACTION);
CREATE TABLE Verkauf (VNr INT UNSIGNED NOT NULL AUTO_INCREMENT, KID INT UNSIGNED, Verkaufsdatum TIMESTAMP, Gesamtpreis FLOAT, PRIMARY KEY (VNr), FOREIGN KEY (KID) REFERENCES Kunden (KID) ON UPDATE NO CASCADE ON DELETE NO ACTION);
CREATE TABLE Artefakt (AID INT NOT NULL AUTO_INCREMENT, Kname VARCHAR(30), VNr INT UNSIGNED, SektorID INT UNSIGNED, Titel VARCHAR(200), Bescheibung VARCHAR(200),Verkaufspreis FLOAT, PRIMARY KEY (AID), FOREIGN KEY (Kname) REFERENCES Kategorie (Kname) ON UPDATE NO CASCADE ON DELETE NO ACTION, FOREIGN KEY (SektorID) REFERENCES Sektor (SektorID) ON UPDATE NO CASCADE ON DELETE NO ACTION, FOREIGN KEY (VNr) REFERENCES Verkauf (VNr) ON UPDATE NO CASCADE ON DELETE NO ACTION);
CREATE TABLE Taucher (TaucherID INT UNSIGNED NOT NULL AUTO_INCREMENT, AdrID INT NOT NULL, Name VARCHAR(200), Vorname VARCHAR(200), Geburtsdatum DATE, Dienstjahre SMALLINT UNSIGNED, PRIMARY KEY (TaucherID), FOREIGN KEY (AdrID) REFERENCES Adresse (AdrID) ON UPDATE NO CASCADE ON DELETE NO ACTION);
CREATE TABLE Wrack (WrID INT UNSIGNED NOT NULL AUTO_INCREMENT, OrtID INT UNSIGNED, Titel VARCHAR(200), Beschreibung VARCHAR(200), Tiefe INT, PRIMARY KEY(WrID), FOREIGN KEY (OrtID) REFERENCES Ort (OrtID) ON UPDATE NO CASCADE ON DELETE NO ACTION);
CREATE TABLE Sektor_Wrack (SektorID INT UNSIGNED NOT NULL, WrID INT UNSIGNED NOT NULL, PRIMARY KEY (SektorID,WrID), FOREING KEY SektorID REFERENCES Sektor (SektorID) ON UPDATE NO CASCADE ON DELETE NO ACTION, FOREIGN KEY WrID REFERENCES Wrack (WrID) ON UPDATE NO CASCADE ON DELETE NO ACTION);
CREATE TABLE Tauchgang (TauchID INT UNSIGNED NOT NULL AUTO_INCREMENT, Tauchleiter INT NOT NULL, AID INT, Startzeit TIMESTAMP, Endzeit TIMESTAMP, Notizen VARCHAR(250), Primary KEY (TauchID), FOREIGN KEY (Tauchleiter) REFERENCES Taucher (TaucherID) ON UPDATE NO CASCADE ON DELETE NO ACTION, FOREIGN KEY AID REFERENCES Artefakt (AID) ON UPDATE NO CASCADE ON DELETE NO ACTION);
CREATE TABLE Aufträge (AufID INT UNSIGNED NOT NULL AUTO_INCREMENT, WrID INT UNSIGNED, AID INT UNSIGNED, KID INT UNSIGNED, Auftragsdatum TIMESTAMP, Enddatum TIMESTAMP, Preis FLOAT, PRIMARY KEY (AufID), FOREIGN KEY (WrID) REFERENCES Wrack (WrID) ON UPDATE NO CASCADE ON DELETE NO ACTION, FOREIGN KEY (AID) REFERENCES Artefakt (AID) ON UPDATE NO CASCADE ON DELETE NO ACTION, FOREIGN KEY (KID) REFERENCES Kunden (KID) ON UPDATE NO CASCADE ON DELETE NO ACTION);
CREATE TABLE Kunden_Aufträge (KID INT UNSIGNED NOT NULL, AufID INT UNSIGNED NOT NULL, PRIMARY KEY (KID, AufID), FOREIGN KEY (KID) REFERENCES Kunden (KID) ON UPDATE NO CASCADE ON DELETE NO ACTION, FOREIGN KEY (AufID) REFERENCES Aufträge (AufID) ON UPDATE NO CASCADE ON DELETE NO ACTION);
CREATE TABLE Wrack_Tauchgang (WrID INT UNSIGNED NOT NULL, TauchID INT UNSIGNED NOT NULL, PRIMARY KEY (WrID, TauchID), FOREIGN KEY (WrID) REFERENCES Wrack (WrID) ON UPDATE NO CASCADE ON DELETE NO ACTION, FOREIGN KEY (TauchID) REFERENCES Tauchgang (TauchID) ON UPDATE NO CASCADE ON DELETE NO ACTION);
CREATE TABLE Taucher_Tauchgang (TaucherID INT UNSIGNED NOT NULL, TauchID INT UNSIGNED NOT NULL, PRIMARY KEY (TaucherID, TauchID), FOREIGN KEY (TaucherID) REFERENCES Taucher (TaucherID) ON UPDATE NO CASCADE ON DELETE NO ACTION, FOREIGN KEY (TauchID) REFERENCES Tauchgang (TauchID) ON UPDATE NO CASCADE ON DELETE NO ACTION);
