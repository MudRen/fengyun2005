// 放置于  /adm/daemons/ 下，用于获得写权限来建立 hj 的房间文件。
// 使用 call_out() 方式，慢慢建立……
// naihe 13:27 03-10-19


#include <ansi.h>

string HJ_DIR;

void create()
{
    seteuid( getuid() );
}

string create_room( object me, string hj_dir, int last_num )
{
    if( !me || !wizardp(me) || getuid(me) != "debug" )
        return "只能由巫师 奈何 启用本程序。\n";

    if( !last_num || last_num < 30 || last_num > 200 || last_num % 10 != 0 )
        return "房间数量范围 30 - 200 ，并且必须是整十数。\n";

    HJ_DIR = hj_dir;

    remove_call_out( "create_room_now" );
    call_out( "create_room_now", 1, me, 1, last_num, 0 );
    message_vision( HIR"\n$N"HIR"启动了 幻境一 建立房间文件程序！\n\n"NOR, me);
    return "正在启动房间建立程序……\n";
}

void create_room_now( object me, int now_num, int last_num, int create_amount )
{
    string filename, msg, content;

    if( !me || !wizardp(me) || getuid(me) != "naihe" )
        return;

    if( !last_num || last_num < 30 || last_num > 200 || last_num % 10 != 0 )
        return;

    filename = HJ_DIR + "hj_room" + now_num + ".c";

    msg = WHT"正在写入： "+filename+ "  >>>>>>>>>>>>>  "NOR;



    if( file_size( filename ) == -1 )
    {
        // 1号房间要特别写
        if( now_num == 1 )
            content = "

// “幻境一·遥远传说之起缘·幽灵显现” 地图房间文件
// 最为特殊的一号房间，需要嵌入一个特别的文件。
// by "+base_name(this_object())+" , " +ctime_format() +"

#include <ansi.h>
inherit ROOM;

int mark=1;

#include \"1_room_info_special.h\"

";
        else content = "

// “幻境一·遥远传说之起缘·幽灵显现” 地图房间文件
// by "+base_name(this_object())+" , " +ctime_format() +"

#include <ansi.h>
inherit ROOM;

int mark="+now_num+";

#include \"all_room_info_hj.h\"

";

// 开始写
        if( write_file( filename, content, 1 ) )
        {
            msg += HIG"成功！\n"NOR;
            create_amount ++;
        }
        else msg += HIR"写入失败。\n"NOR;
    }
    else msg += HIY"已有该文件存在。\n"NOR;

    message_vision( msg, me );

    now_num ++;
    if( now_num > last_num )
    {
        message_vision( HIR"\n所有文件建立完毕，共成功建立 "+create_amount+" 个文件！\n\n"NOR, me);
        return;
    }

    remove_call_out( "create_room_now" );
    call_out( "create_room_now", 1, me, now_num, last_num, create_amount );
}


