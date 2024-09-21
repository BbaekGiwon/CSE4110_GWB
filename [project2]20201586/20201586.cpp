/**************************************************
 * Title: DatabaseSystem - Project 2 Example
 * Summary: blah blah
 *  |Date              |Author             |Version
    |2024-12-31        |Gildong Hong       |1.0.0
**************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "mysql.h"

#pragma comment(lib, "libmysql.lib")

const char* host = "localhost"; // change if necessary
const char* user = "root";      // change if necessary
const char* pw = "santa5268!";       // change if necessary
const char* db = "project";

#define MAX_LEN			13000

int main(void) {
	int Sold_ID = 41;

    MYSQL* connection = NULL;
    MYSQL conn;
    MYSQL_RES* sql_result;
    MYSQL_ROW sql_row;
    FILE* fp = fopen("CRUD.txt", "rt");    // open CRUD file.
    char line[MAX_LEN];

    if (mysql_init(&conn) == NULL)
        printf("mysql_init() error!");

    connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);   // the first NULL can be replaced to an existing db instance.
    if (connection == NULL) {
        printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
        return 1;
    }
    else {
        printf("Connection Succeed\n\n");

        while (fgets(line, sizeof(line), fp) != NULL) {
            if (!strcmp(line, "$$$\n"))      // read lines from CRUD file, '$$$' separates CREATE / DELETE parts.
                break;
            mysql_query(connection, line);
        }

        if (mysql_select_db(&conn, "project")) {
            printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
            return 1;
        }

        while (1) {
            printf("\n\n------- SELECT QUERY TYPES -------\n\n");
            printf("\t1. TYPE 1\n");
            printf("\t2. TYPE 2\n");
            printf("\t3. TYPE 3\n");
            printf("\t4. TYPE 4\n");
            printf("\t5. TYPE 5\n");
            printf("\t6. TYPE 6\n");
            printf("\t7. TYPE 7\n");
            printf("\t0. QUIT\n");
            printf("\n----------------------------------\n");
            
            int cmd = 0;
			printf("Enter type : ");
            if (scanf("%d", &cmd) != 1) {
                printf("scanf ERROR\n");
                continue;
            }

            if (cmd == 0) {
                break;
            }
			else if (cmd == 1) {
				const char* query = "SELECT House_street, House_detail_address\nFROM House\nWHERE House_district = 'Mapo';";
				int state = 0;
				state = mysql_query(connection, query);
				if (state == 0) {
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						printf(" %s  %s \n", sql_row[0], sql_row[1]);

					mysql_free_result(sql_result);


					while (1) {
						printf("\n\n----- Subtypes in TYPE 1 -----\n");
						printf("\t1. TYPE 1-1.\n");

						int sub_cmd = 0;
						printf("Enter subtype : ");
						if (scanf("%d", &sub_cmd) != 1) {
							printf("scanf ERROR\n");
							continue;
						}

						if (sub_cmd == 0) {
							break;
						}
						else if (sub_cmd == 1) {
							const char* sub_query = "SELECT House_street, House_detail_address\nFROM House\nWHERE House_district = 'Mapo'\nAND House_price BETWEEN 1000000000 AND 1500000000;";
							state = mysql_query(connection, sub_query);
							if (state == 0) {
								sql_result = mysql_store_result(connection);
								while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
									printf(" %s  %s \n", sql_row[0], sql_row[1]);

								mysql_free_result(sql_result);
							}
							else {
								printf("Query failed\n");
							}
						}
					}
				}
				else {
					printf("Query failed\n");
				}
			}
            else if (cmd == 2) {
				const char* query = "SELECT House_district, House_street, House_detail_address\nFROM House\nWHERE House_school_district = 8;";
				int state = 0;
				state = mysql_query(connection, query);
				if (state == 0) {
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						printf(" %s  %s  %s \n", sql_row[0], sql_row[1], sql_row[2]);

					mysql_free_result(sql_result);


					while (1) {
						printf("\n\n----- Subtypes in TYPE 2 -----\n");
						printf("\t1. TYPE 2-1.\n");

						int sub_cmd = 0;
						printf("Enter subtype : ");
						if (scanf("%d", &sub_cmd) != 1) {
							printf("scanf ERROR\n");
							continue;
						}

						if (sub_cmd == 0) {
							break;
						}
						else if (sub_cmd == 1) {
							const char* sub_query = "SELECT House_district, House_street, House_detail_address\nFROM House\nWHERE House_school_district = 8\nAND House_num_of_bedroom >= 4\nAND House_num_of_bathroom = 2;";
							state = mysql_query(connection, sub_query);
							if (state == 0) {
								sql_result = mysql_store_result(connection);
								while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
									printf(" %s  %s  %s \n", sql_row[0], sql_row[1], sql_row[2]);

								mysql_free_result(sql_result);
							}
							else {
								printf("Query failed\n");
							}
						}
					}
				}
				else {
					printf("Query failed\n");
				}
            }
            else if (cmd == 3) {
				const char* query = "SELECT Agent_name \nFROM Agent\nJOIN Sold ON Agent.Agent_ID = Sold.Sold_Seller_Agent_ID\nWHERE YEAR(Sold_sale_date) = 2022\nGROUP BY Agent.Agent_ID\nORDER BY SUM(Sold_price) DESC\nLIMIT 1;";
				int state = 0;
				state = mysql_query(connection, query);
				if (state == 0) {
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						printf(" %s \n", sql_row[0]);

					mysql_free_result(sql_result);


					while (1) {
						printf("\n\n----- Subtypes in TYPE 3 -----\n");
						printf("\t1. TYPE 3-1.\n");
						printf("\t2. TYPE 3-2.\n");

						int sub_cmd = 0;
						printf("Enter subtype : ");
						if (scanf("%d", &sub_cmd) != 1) {
							printf("scanf ERROR\n");
							continue;
						}

						if (sub_cmd == 0) {
							break;
						}
						else if (sub_cmd == 1) {
							int k = 0;
							printf("\n** Then find the top k agents in the year 2023 by total won value. **\n Which K? : ");
							if (scanf("%d", &k) != 1) {
								printf("scanf ERROR\n");
								continue;
							}

							char query_template[] = "SELECT Agent_name \nFROM Agent\nJOIN Sold ON Agent.Agent_ID = Sold.Sold_Seller_Agent_ID\nWHERE YEAR(Sold_sale_date) = 2023\nGROUP BY Agent.Agent_ID\nORDER BY SUM(Sold_price) DESC\nLIMIT %d;";
							char sub_query[256];
							sprintf(sub_query, query_template, k);
							
							state = mysql_query(connection, sub_query);
							if (state == 0) {
								sql_result = mysql_store_result(connection);
								while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
									printf(" %s \n", sql_row[0]);

								mysql_free_result(sql_result);
							}
							else {
								printf("Query failed\n");
							}
						}
						else if (sub_cmd == 2) {
							const char* sub_query = "SELECT Agent_name"
								"\nFROM("
								"\nSELECT Agent.Agent_name, SUM(Sold.Sold_price) AS TotalSales,"
								"\nROW_NUMBER() OVER(ORDER BY SUM(Sold.Sold_price) ASC) AS RowNum"
								"\nFROM Agent"
								"\nJOIN Sold ON Agent.Agent_ID = Sold.Sold_Seller_Agent_ID"
								"\nWHERE YEAR(Sold.Sold_sale_date) = 2021"
								"\nGROUP BY Agent.Agent_ID"
								"\n) AS RankedAgents"
								"\nWHERE RowNum <= (SELECT ROUND(COUNT(*) * 0.1) FROM("
								"\nSELECT Agent.Agent_ID"
								"\nFROM Agent"
								"\nJOIN Sold ON Agent.Agent_ID = Sold.Sold_Seller_Agent_ID"
								"\nWHERE YEAR(Sold.Sold_sale_date) = 2021"
								"\nGROUP BY Agent.Agent_ID"
								"\n) AS TotalAgents);";

							state = mysql_query(connection, sub_query);
							if (state == 0) {
								sql_result = mysql_store_result(connection);
								while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
									printf(" %s \n", sql_row[0]);

								mysql_free_result(sql_result);
							}
							else {
								printf("Query failed\n");
							}
						}
					}
				}
				else {
					printf("Query failed\n");
				}
            }
            else if (cmd == 4) {
				const char* query = "SELECT Agent_name, AVG(Sold_price) AS avg_price, AVG(DATEDIFF(Sold_sale_date, Sold_registration_date)) AS avg_market_time\nFROM Agent\nJOIN Sold ON Agent.Agent_ID = Sold.Sold_Seller_Agent_ID\nWHERE YEAR(Sold_sale_date) = 2022\nGROUP BY Agent.Agent_ID;";
				int state = 0;
				state = mysql_query(connection, query);
				if (state == 0) {
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						printf(" %s  %s  %s \n", sql_row[0], sql_row[1], sql_row[2]);

					mysql_free_result(sql_result);


					while (1) {
						printf("\n\n----- Subtypes in TYPE 4 -----\n");
						printf("\t1. TYPE 4-1.\n");
						printf("\t2. TYPE 4-2.\n");

						int sub_cmd = 0;
						printf("Enter subtype : ");
						if (scanf("%d", &sub_cmd) != 1) {
							printf("scanf ERROR\n");
							continue;
						}

						if (sub_cmd == 0) {
							break;
						}
						else if (sub_cmd == 1) {
							const char* sub_query = "SELECT Agent_name, \nMAX(Sold_price) AS max_price\nFROM Agent\nJOIN Sold ON Agent.Agent_ID = Sold.Sold_Seller_Agent_ID\nWHERE YEAR(Sold_sale_date) = 2023\nGROUP BY Agent.Agent_ID;";

							state = mysql_query(connection, sub_query);
							if (state == 0) {
								sql_result = mysql_store_result(connection);
								while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
									printf(" %s \n", sql_row[0]);

								mysql_free_result(sql_result);
							}
							else {
								printf("Query failed\n");
							}
						}
						else if (sub_cmd == 2) {
							const char* sub_query = "SELECT Agent_name, MAX(DATEDIFF(Sold_sale_date, Sold_registration_date)) AS max_market_time\nFROM Agent\nJOIN Sold ON Agent.Agent_ID = Sold.Sold_Seller_Agent_ID\nGROUP BY Agent.Agent_ID;";
							state = mysql_query(connection, sub_query);
							if (state == 0) {
								sql_result = mysql_store_result(connection);
								while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
									printf(" %s \n", sql_row[0]);

								mysql_free_result(sql_result);
							}
							else {
								printf("Query failed\n");
							}
						}
					}
				}
				else {
					printf("Query failed\n");
				}

            }
            else if (cmd == 5) {
				printf("  **studio**\n");
				const char* query_1 =
					"SELECT I.Interior_photo_photo, E.Exterior_photo_photo, F.Floor_plan_photo_photo\n"
					"FROM House H\n"
					"LEFT JOIN Interior_photo I ON H.House_ID = I.Interior_photo_House_ID\n"
					"LEFT JOIN Exterior_photo E ON H.House_ID = E.Exterior_photo_House_ID\n"
					"LEFT JOIN Floor_plan_photo F ON H.House_ID = F.Floor_plan_photo_House_ID\n"
					"WHERE H.House_type = 'studio'\n"
					"ORDER BY H.House_price DESC\n"
					"LIMIT 1;";
				int state = 0;
				state = mysql_query(connection, query_1);
				if (state == 0) {
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						printf(" %s  %s  %s \n", sql_row[0], sql_row[1], sql_row[2]);

					mysql_free_result(sql_result);
				}
				else {
					printf("Query failed\n");
				}

				printf("  **one-bedroom**\n");
				const char* query_2 =
					"SELECT I.Interior_photo_photo, E.Exterior_photo_photo, F.Floor_plan_photo_photo\n"
					"FROM House H\n"
					"LEFT JOIN Interior_photo I ON H.House_ID = I.Interior_photo_House_ID\n"
					"LEFT JOIN Exterior_photo E ON H.House_ID = E.Exterior_photo_House_ID\n"
					"LEFT JOIN Floor_plan_photo F ON H.House_ID = F.Floor_plan_photo_House_ID\n"
					"WHERE H.House_type = 'one-bedroom'\n"
					"ORDER BY H.House_price DESC\n"
					"LIMIT 1;";
				state = 0;
				state = mysql_query(connection, query_2);
				if (state == 0) {
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						printf(" %s  %s  %s \n", sql_row[0], sql_row[1], sql_row[2]);

					mysql_free_result(sql_result);
				}
				else {
					printf("Query failed\n");
				}

				printf("  **multi-bedroom**\n");
				const char* query_3 =
					"SELECT I.Interior_photo_photo, E.Exterior_photo_photo, F.Floor_plan_photo_photo\n"
					"FROM House H\n"
					"LEFT JOIN Interior_photo I ON H.House_ID = I.Interior_photo_House_ID\n"
					"LEFT JOIN Exterior_photo E ON H.House_ID = E.Exterior_photo_House_ID\n"
					"LEFT JOIN Floor_plan_photo F ON H.House_ID = F.Floor_plan_photo_House_ID\n"
					"WHERE H.House_type = 'multi-bedroom'\n"
					"ORDER BY H.House_price DESC\n"
					"LIMIT 1;";
				state = 0;
				state = mysql_query(connection, query_3);
				if (state == 0) {
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						printf(" %s  %s  %s \n", sql_row[0], sql_row[1], sql_row[2]);

					mysql_free_result(sql_result);
				}
				else {
					printf("Query failed\n");
				}

				printf("  **apartment**\n");
				const char* query_4 =
					"SELECT I.Interior_photo_photo, E.Exterior_photo_photo, F.Floor_plan_photo_photo\n"
					"FROM House H\n"
					"LEFT JOIN Interior_photo I ON H.House_ID = I.Interior_photo_House_ID\n"
					"LEFT JOIN Exterior_photo E ON H.House_ID = E.Exterior_photo_House_ID\n"
					"LEFT JOIN Floor_plan_photo F ON H.House_ID = F.Floor_plan_photo_House_ID\n"
					"WHERE H.House_type = 'detached house'\n"
					"ORDER BY H.House_price DESC\n"
					"LIMIT 1;";
				state = 0;
				state = mysql_query(connection, query_4);
				if (state == 0) {
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						printf(" %s  %s  %s \n", sql_row[0], sql_row[1], sql_row[2]);

					mysql_free_result(sql_result);
				}
				else {
					printf("Query failed\n");
				}
            }
            else if (cmd == 6) {
				int B_ID = 0, H_ID = 0, A_ID = 0;
				char datetime[100];
				printf("\n** Then who bought which house through which agent at when? **\n Insert Buyer_ID (int): ");
				if (scanf("%d", &B_ID) != 1) {
					printf("scanf ERROR\n");
					continue;
				}
				printf("Insert House_ID (int): ");
				if (scanf("%d", &H_ID) != 1) {
					printf("scanf ERROR\n");
					continue;
				}
				printf("Insert Agent_ID (int): ");
				if (scanf("%d", &A_ID) != 1) {
					printf("scanf ERROR\n");
					continue;
				}
				while (getchar() != '\n');
				printf("Insert datetime[total 10 char] (ex) YYYY-MM-DD : ");
				if (fgets(datetime, sizeof(datetime), stdin) == NULL) {
					printf("fgets ERROR\n");
					continue;
				}
				datetime[strcspn(datetime, "\n")] = 0;


				//char query_template[] = "INSERT INTO Sold(Sold_ID, Sold_House_ID, Sold_Seller_Agent_ID, Sold_Seller_ID, Sold_Buyer_ID, Sold_registration_date, Sold_sale_date, Sold_price, Sold_Buyer_Agent_ID)\nSELECT COALESCE(MAX(Sold_ID), 0) + 1, Sale_House_ID, Sale_Seller_Agent_ID, Sale_Seller_ID, %d, Sale_registration_date, '%s', Sale_price, %d\nFROM Sale\nWHERE Sale_House_ID = %d;";
				char query[512];
				char query_1[512];
				//sprintf(query, query_template, B_ID, datetime, A_ID, H_ID);
				
				//printf("%d %s %d %d", B_ID, datetime, A_ID, H_ID);
				char query_template[] = "SELECT Sale_House_ID, Sale_Seller_Agent_ID, Sale_Seller_ID, Sale_registration_date, Sale_price\nFROM Sale\nWHERE Sale_House_ID = %d;";
				sprintf(query, query_template, H_ID);

				int state = 0;
				state = mysql_query(connection, query);
				if (state == 0) {
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
						sprintf(query_1, "INSERT INTO Sold VALUES (%d, %s, %s, %s, %d, '%s', '%s', %s, %d);", Sold_ID++, sql_row[0], sql_row[1], sql_row[2], B_ID, sql_row[3], datetime, sql_row[4], A_ID);
					}
					
					mysql_free_result(sql_result);
				}
				else {
					printf("Query failed\n");
				}

				state = mysql_query(connection, query_1);
				if (state == 0) {
					sql_result = mysql_store_result(connection);
					mysql_free_result(sql_result);
				}
				else {
					printf("Query failed\n");
				}


				char query_2[64];
				sprintf(query_2, "DELETE FROM Sale\nWHERE Sale_House_ID = %d;", H_ID);


				state = mysql_query(connection, query_2);
				if (state == 0) {
					sql_result = mysql_store_result(connection);
					//while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						//printf(" %s  %s \n", sql_row[0], sql_row[1]);

					mysql_free_result(sql_result);
				}
				else {
					printf("Query failed\n");
				}

				
            }
            else if (cmd == 7) {
				int A_ID = 0;
				char A_name[20], A_phone[20];
				printf("\n** Then tell me ID, name, phone number of Agent. **\n Insert ID (int) : ");
				if (scanf("%d", &A_ID) != 1) {
					printf("scanf ERROR\n");
					continue;
				}
				while (getchar() != '\n');
				printf("Insert name (maximum 20 char) (press enter twice at the end!) : ");
				if (fgets(A_name, sizeof(A_name), stdin) == NULL) {
					printf("fgets ERROR\n");
					continue;
				}
				while (getchar() != '\n');
				printf("Insert phone number (maximum 20 char) (ex) 000-0000-0000 : ");
				if (fgets(A_phone, sizeof(A_phone), stdin) == NULL) {
					printf("fgets ERROR\n");
					continue;
				}
				A_name[strcspn(A_name, "\n")] = 0;
				A_phone[strcspn(A_phone, "\n")] = 0;

				char query[100];
				sprintf(query, "INSERT INTO Agent VALUES(%d, '%s', '%s');", A_ID, A_name, A_phone);

				int state = 0;
				state = mysql_query(connection, query);
				if (state == 0) {
					sql_result = mysql_store_result(connection);
					mysql_free_result(sql_result);
				}
				else {
					printf("Query failed\n");
				}
            }
        }

            // comment out if you want to persist example db instance.
        while (fgets(line, sizeof(line), fp) != NULL)
            mysql_query(connection, line);			// these are DELETEs & DROPs.

        mysql_close(connection);
    }
    return 0;
}