/*Dar el ID del jugador que ha ganado más partidas*/

#include <stdio.h>
#inlcude <string.h>
#include <mysql.h>


int main(){
	MYSQL *conn;
	int err;
	int id_jugador;
	consulta [150],
	MYSQL_RES *resultado;
	MYSQL_ROW row;

	conn=mysql_init(NULL);
	if (conn ==NULL){
		printf("Error al crear la conexión \n");
		exit(1)
	}
	conn=mysql_real_connect(conn,"localhost","root", "mysql", "relacion", 0, NULL, 0);
	if (conn == NULL){
		printf ("Error al conectar \n");
		exit(1);}
		
	sprintf(consulta, "SELECT JUGADOR_ID FROM (JUGADOR, PARTIDA, RELACION) WHERE 
	JUGADOR.PARTIDAS_GANADAS=(SELECT MAX(PARTIDAS_GANADAS) FROM JUGADOR)");

	err=mysql_query(conn, consulta);
	if (err != 0){
		printf("Error en la consulta \n");
		exit(1);}
	resultado = mysql_store_result(conn);
	row =mysql_fetch_row(resultado);
	if (row==NULL){
		printf ("No hay datos \n");
	}
	else {
		id_jugador=atoi(row[0]);
		printf("El jugador que mas partidas ha ganado tiene la id %d ", id_jugador);
	}
	mysql_close(conn);
	exit(0);
}



SELECT JUGADOR_ID FROM (JUGADOR, PARTIDA, RELACION) WHERE 
JUGADOR.PARTIDAS_GANADAS=(SELECT MAX(PARTIDAS_GANADAS) FROM JUGADOR)  

SELECT JUGADOR.ID, SUM(PARTIDA.GANADOR)




