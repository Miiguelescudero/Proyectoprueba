
CREATE TABLE JUGADOR(
	ID INT NOT NULL,
	USERNAME VARCHAR (50),
	PASSWORD VARCHAR(50),
	PRIMARY KEY (ID)
) ENGINE = InnoDB;


CREATE TABLE PARTIDA (
	ID INT NOT NULL,
	DIA_FECHA INT,
	MES_FECHA INT,
	ANY_FECHA INT,
	HORA_HORA INT,
	MINUTO_HORA INT,
	DURACION INT,
	GANADOR VARCHAR (50),
	PRIMARY KEY (ID)
)ENGINE=InnoDB;

TIMESTAMP

CREATE TABLE RELACION (
	JUGADOR_ID INT NOT NULL,
	PARTIDA_ID INT NOT NULL,
	FOREIGN KEY (JUGADOR_ID) REFERENCES JUGADOR (ID), 
	FOREIGN KEY (PARTIDA_ID) REFERENCES PARTIDA (ID)
) ENGINE = InnoDB;

