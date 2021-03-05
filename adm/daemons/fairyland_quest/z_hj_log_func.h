// 本文件被 room_gameover_hj.c 及 room_cession_hj.c 调用。
// 22:53 03-10-22


#define        MY_LOG_FILE_NAME        "static/hj2003"

string get_log_file_name()
{
    int temp;

#ifdef        IS_TEST

temp = IS_TEST;

#endif

    if( temp )
        return MY_LOG_FILE_NAME + "_" + "testlog";

    return MY_LOG_FILE_NAME + ctime_format( "_YYM" );
}

// 每个月生成一份 LOG。
// 该月的LOG如果太大时，由MUD系统自动改写，这里不作考虑。
// 如果在测试状态，得分以及兑换奖品的记录，则会写入另一个 log 文件中。

// 奖品转让处的 LOG 则依旧。

void hj_log_file(string log_msg)
{
    if( !log_msg ) return;
    log_file( get_log_file_name(), log_msg );
}


