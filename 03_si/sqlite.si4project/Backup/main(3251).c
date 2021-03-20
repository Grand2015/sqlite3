/*********************************************************************************
 *      Copyright:  (C) 2017 zoulei
 *                  All rights reserved.
 *
 *       Filename:  insert.c
 *    Description:  This file i
 *
 *        Version:  1.0.0(2017��06��22��)
 *         Author:  zoulei <zoulei121@gmail.com>
 *      ChangeLog:  1, Release initial version on "2017��06��22�� 19ʱ31��12��"
 *
 ********************************************************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#define _DEBUG_
int main(int argc, char**argv)
{
	sqlite3 *db=NULL;
	int len;
	int i=0;
	int nrow=0;
	int ncolumn = 0;
	char *zErrMsg =NULL;
	char **azResult=NULL; //��ά�����Ž��

	/* �����ݿ� */
	len = sqlite3_open("user", &db);
	if(len)
	{
		/*  fprintf������ʽ�����������Ϣ��ָ����stderr�ļ�����  */
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));//sqlite3_errmsg(db)���Ի�����ݿ�򿪴������Ӣ��������
		sqlite3_close(db);
		exit(1);
	}
	else 
		printf("You have opened a sqlite3 database named user successfully!\n");

	/* ������ */
	char *sql = " CREATE TABLE SensorData(\
		ID INTEDER PRIMARY KEY,\
		SensorID INTEGER,\
		siteNum INTEGER,\
		Time VARCHAR(12),\
		SensorParameter REAL\
		);" ;

	sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);
#ifdef _DEBUG_
	printf("%s\n",zErrMsg);
	sqlite3_free(zErrMsg);
#endif
	/*��������  */
	char*sql1 ="INSERT INTO 'SensorData'VALUES(NULL,1,2,201430506201,13.5);";
	sqlite3_exec(db,sql1,NULL,NULL,&zErrMsg);
	char*sql2 ="INSERT INTO 'SensorData'VALUES(NULL,3,4,201530506302,14.5);";
	sqlite3_exec(db,sql2,NULL,NULL,&zErrMsg);
	char*sql3 ="INSERT INTO 'SensorData'VALUES(NULL,5,6,201630506413,18.6);";
	sqlite3_exec(db,sql3,NULL,NULL,&zErrMsg);

	/* ��ѯ���� */
	sql="select *from SensorData";
	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
	printf("nrow=%d ncolumn=%d\n",nrow,ncolumn);
	printf("the result is:\n");
	for(i=0;i<(nrow+1)*ncolumn;i++)
	{
		printf("azResult[%d]=%s\n",i,azResult[i]);
	}

	/* ɾ��ĳ���ض������� */
	sql="delete from SensorData where SensorID = 1 ;";
	sqlite3_exec( db , sql , NULL , NULL , &zErrMsg );
#ifdef _DEBUG_
	printf("zErrMsg = %s \n", zErrMsg);
	sqlite3_free(zErrMsg);
#endif

	/* ��ѯɾ��������� */
	sql = "SELECT * FROM SensorData ";
	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
	printf( "row:%d column=%d\n " , nrow , ncolumn );
	printf( "After deleting , the result is : \n" );
	for( i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
	{
		printf( "azResult[%d] = %s\n", i , azResult[i] );
	}
	sqlite3_free_table(azResult);
#ifdef _DEBUG_
	printf("zErrMsg = %s \n", zErrMsg);
	sqlite3_free(zErrMsg);
#endif

	sqlite3_close(db);
	return 0;
}

