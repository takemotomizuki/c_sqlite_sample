#include <stdio.h>
#include <sqlite3.h>

int main(void){
    sqlite3 *db;
    char *filename="database/db_test.sqlite3";
    int rc; //result codes
    sqlite3_stmt *stmt;

    rc = sqlite3_open(filename, &db);
    if(rc != SQLITE_OK){
        return 1;
    }

    //プリペアドステートメントを生成
    rc = sqlite3_prepare_v2(db,"SELECT id, name FROM tb_test WHERE id = ?", -1, &stmt, 0);
    if(rc != SQLITE_OK){
        printf("ERROR(%d) %s\n",rc, sqlite3_errmsg(db));
        sqlite3_close(db);
        return 2;
    }
    
    //選択する行
    int id = 1;
    //バインド
    sqlite3_bind_int(stmt, 1, id);

    //行を読み取る。
    rc = sqlite3_step(stmt);
    while(rc == SQLITE_ROW){
        printf("%d %s",
                sqlite3_column_int(stmt,0),
                sqlite3_column_text(stmt,1));
        printf("\n");
        rc = sqlite3_step(stmt);
    }

    //プレペアドステートメントの解放
    rc = sqlite3_finalize(stmt);
    if(rc != SQLITE_OK){
        printf("ERROR(%d) %s\n",rc,sqlite3_errmsg(db));
    }

    sqlite3_close(db);

    return 0;
}