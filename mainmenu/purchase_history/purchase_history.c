
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[22];
};
static const struct sqlcxp sqlfpn =
{
    21,
    ".\\purchase_history.pc"
};


static unsigned int sqlctx = 138518243;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned int   sqlpfmem;
            void  *sqhstv[5];
   unsigned int   sqhstl[5];
            int   sqhsts[5];
            void  *sqindv[5];
            int   sqinds[5];
   unsigned int   sqharm[5];
   unsigned int   *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {13,5};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,1,0,0,
5,0,0,1,0,0,17,83,0,0,1,1,0,1,0,1,97,0,0,
24,0,0,1,0,0,45,89,0,0,0,0,0,1,0,
39,0,0,1,0,0,13,100,0,0,5,0,0,1,0,2,3,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,9,0,0,
74,0,0,1,0,0,15,168,0,0,0,0,0,1,0,
89,0,0,2,0,0,29,170,0,0,0,0,0,1,0,
104,0,0,3,0,0,24,239,0,0,1,1,0,1,0,1,97,0,0,
123,0,0,4,0,0,29,241,0,0,0,0,0,1,0,
};


// ?????????? : 2020.11.17
// win32 Visual C 2010 ???????????? ????
// ???????? ???? ?? ???? ?????? ??
#define _CRT_SECURE_NO_WARNINGS
//-----------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

/* for oracle */
#include <sqlda.h>
#include <sqlca.h>
#include <sqlcpr.h>

// win32 Visual C 2010 ???????????? ????
#define getch() _getch()
//-----------------------------------------

/*---------------  ???? ???? ???? ???? ----------------------*/
#include < windows.h >
// void gotoxy(int x, int y);
// void getxy(int *x, int *y);
// void clrscr(void);
/*-----------------------------------------------------------*/
//void print_screen(char fname[]);
//void DB_connect();

extern void mainmenu_main(char *userid);

void purchase_history(char *userid);
int menu_input(char input,int flag, char *userid);
void Delete_tuple(int num);
void sql_error(char *);

/* EXEC SQL BEGIN DECLARE SECTION; */ 

/* VARCHAR uid[80]; */ 
struct { unsigned short len; unsigned char arr[80]; } uid;

/* VARCHAR pwd[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } pwd;

/* EXEC SQL END DECLARE SECTION; */ 


#define getch() _getch()

int no[100]={0,};

#define PAGE_NUM 10
void purchase_history(char *userid)
{
   /* --------------------------------------------------------------------------
      Retrieve the current maximum employee number
   -------------------------------------------------------------------------- */

   memset(no, 0, sizeof(int) * 100);
   /* EXEC SQL BEGIN DECLARE SECTION; */ 

   int id;
   /* varchar p_name[100]; */ 
struct { unsigned short len; unsigned char arr[100]; } p_name;

   int cnt;
   int price;
   /* varchar o_date[100]; */ 
struct { unsigned short len; unsigned char arr[100]; } o_date;

   

   char dynstmt[1000];
   /* EXEC SQL END DECLARE SECTION; */ 


   int x, y, count = 0, i, j;

   
   /* Register sql_error() as the error handler. */
   /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


   /* ?????? ???? */
   clrscr();

   print_screen("screen/product_purchase_history_screen.txt");

   /* ???????? SQL ????*/
   sprintf(dynstmt, "SELECT id, product_name, cnt, totalprice, orderdate from V_ORDERS where userid='%s'",userid);

   /* select ?????? ?????? ???????? ?????? ?????? ?????? */
   // printf("dynstmt:%s\n", dynstmt);

   /* EXEC SQL PREPARE S FROM : dynstmt; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 1;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )5;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (         void  *)dynstmt;
   sqlstm.sqhstl[0] = (unsigned int  )1000;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         void  *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



   /* cursor ???? */
   /* EXEC SQL DECLARE c_cursor CURSOR FOR S; */ 


   /* cursor open */
   /* EXEC SQL OPEN c_cursor; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 1;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )24;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqcmod = (unsigned int )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



   //EXEC SQL WHENEVER NOT FOUND DO break;

   x = 3;
   y = 16;
   j = 1;
   char input;
   for (;;)
   {
      //EXEC SQL WHENEVER NOT FOUND DO break;
      /* EXEC SQL FETCH c_cursor INTO : id, : p_name, : cnt, : price, : o_date; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 13;
      sqlstm.arrsiz = 5;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )39;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.sqlpfmem = (unsigned int  )0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqfoff = (           int )0;
      sqlstm.sqfmod = (unsigned int )2;
      sqlstm.sqhstv[0] = (         void  *)&id;
      sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         void  *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned int  )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (         void  *)&p_name;
      sqlstm.sqhstl[1] = (unsigned int  )102;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         void  *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned int  )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (         void  *)&cnt;
      sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         void  *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned int  )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (         void  *)&price;
      sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         void  *)0;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned int  )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (         void  *)&o_date;
      sqlstm.sqhstl[4] = (unsigned int  )102;
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         void  *)0;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned int  )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}




      if(sqlca.sqlcode == 1403) {
         break;
      }

      p_name.arr[p_name.len] = '\0';
      o_date.arr[o_date.len] = '\0';

      no[j]=id;




      gotoxy(x, y);
      printf(" |  %4d    |    %20s    |   %4d??    | ??%10d  |%10s |", j, p_name.arr,cnt,price,o_date.arr);
      
      j++;
      y++;
      count++;

      
      if (count == PAGE_NUM)
      {

         count = 0;
         
         /**
          * n ???? x?? ?????? ???? (?????? ?????? ?????? ???? ???? ???? ????)
          * ?????????? ?? ???????? ???? ?????? ?????? ?? ????
          */
         while ((input = getch()) != 'n' && input != 'x' && input != 'm'); 
         
         int ret;
         ret =menu_input(input,0,userid);
         if(ret == 16){
            y=ret;
            for(i = 0 ; i < PAGE_NUM-1; i++)
               printf("                                                                                                                        \n");

         } 
         else if(ret==17){
            gotoxy(0, 1);
            clrscr();
            purchase_history(userid);
         }
         
         else
            break;
      }
       for(i = count ; i < PAGE_NUM-1; i++)
               printf("                                                                                                                        \n");

   }
 
   while ((input = getch()) != 'n' && input != 'x' && input != 'm');
   if(menu_input(input,1,userid)==17)
   {  
      gotoxy(0, 1);
      clrscr();
      purchase_history(userid);
   }
   
   


   /* Close the cursor. */
   /* EXEC SQL CLOSE c_cursor; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )74;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



   /* EXEC SQL COMMIT; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )89;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


}
int menu_input(char input,int flag, char *userid)
{
         if(input == 'n')
         { 
               gotoxy(0, 16); // ???? ???? ???? ??????
               for (int i = 0; i < PAGE_NUM; i++)
               {
                  printf("                                                                                                                        \n");
                  return 16+flag;
               }

         }

         else if(input == 'x')
         {  
            gotoxy(0,28);
            printf("          ?????? ???? ???? ???? :                ( [0] ???? ??, ???? )");
            gotoxy(34,28);
            int input_num;
            scanf("%d",&input_num);
            if(input_num==0)
            {
               gotoxy(0,28);
               printf("                                                                                                                        \n");
               printf("--------------------------------------------------------------------------------------------");
               return 17;

            } else 
            {
               
               Delete_tuple(no[input_num]);
               
               gotoxy(0,28);
               printf("                                                                                                                        \n");
               printf("--------------------------------------------------------------------------------------------");
               
               

               return 17;
                

            }
         }
         else if(input == 'm')
         {
            mainmenu_main(userid);
         }

   return 0;
   
}

void Delete_tuple(int num)
{

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      int tempnum;
      char dynstmt[1000];

   /* EXEC SQL END DECLARE SECTION; */ 


   /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 

   tempnum = num;
   sprintf(dynstmt,"DELETE FROM orders WHERE id = %d", tempnum);
   printf("%s",dynstmt);

   
   /* EXEC SQL EXECUTE IMMEDIATE :dynstmt; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )104;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (         void  *)dynstmt;
   sqlstm.sqhstl[0] = (unsigned int  )1000;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         void  *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



   /* EXEC SQL COMMIT WORK ; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )123;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}

 

}


// void print_screen(char fname[])
// {
//    FILE *fp;
//    char line[100];

//    if ((fp = fopen(fname, "r")) == NULL)
//    {
//       printf("file open error\n");
//       getch();
//       exit(-1);
//    }
//    while (1)
//    {
//       if (fgets(line, 99, fp) == NULL)
//       {
//          break;
//       }
//       printf("%s", line);
//    }

//    fclose(fp);
// }

/* --------------------------------------------------------------------------
int sql_error()

   errrpt prints the ORACLE error msg and number.
-------------------------------------------------------------------------- */
// void sql_error(char *msg)
// {
//    char err_msg[128];
//    size_t buf_len, msg_len;

//    EXEC SQL WHENEVER SQLERROR CONTINUE;

//    printf("\n%s\n", msg);
//    buf_len = sizeof(err_msg);
//    sqlglm(err_msg, &buf_len, &msg_len);
//    printf("%.*s\n", msg_len, err_msg);

//    getch();
//    EXEC SQL ROLLBACK WORK;
//    // exit(EXIT_FAILURE);
// }
// /*---------------  ???? ???? ???? ???? --------------------*/
// #define STD_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)

// void gotoxy(int x, int y)
// {
//    COORD Cur = {(SHORT)x, (SHORT)y};

//    SetConsoleCursorPosition(STD_HANDLE, Cur);
// }

// void getxy(int *x, int *y)
// {
//    CONSOLE_SCREEN_BUFFER_INFO Buf;

//    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Buf);
//    *x = (int)Buf.dwCursorPosition.X;
//    *y = (int)Buf.dwCursorPosition.Y;
// }

// void clrscr(void)
// {
//    COORD Cur = {0, 0};
//    unsigned long dwLen;

//    FillConsoleOutputCharacter(STD_HANDLE, ' ', 80 * 25, Cur, &dwLen);
// }

// /*---------------------------------------------------------*/
