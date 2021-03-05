//                标准描述长度示例                                   |
// 需要 DEBUG 之物件暂时存放之 房间
// by naihe  2002-10-31


// 本文件已弃置，对应功能代码已全部删除。
// naihe 0:01 03-10-21


#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",BLU"out room testing"NOR);
    set("long","

             "HIR" 幻境游戏 DEBUG OBJ 暂存房间 "NOR"

\n");

    set("no_fight", "1");
    set("no_steal", "1");
    set("no_sleep_room", "1");
    set("invalid_startroom",1);

    set("exits",([
        "out": __DIR__"ok_enterhuanjing",
    ]));

    setup();
}

void init()
{
    add_action("do_limits","update");
    add_action("do_limits","destroy");
    add_action("do_limits","get");
    add_action("do_limits","more");
    add_action("do_limits","cat");
    add_action("do_limits","info");
}

int do_limits()
{
    if(this_player()->query("id") !="naihe" ||
       this_player()->query("name") !="奈何" ||
       !wizardp(this_player()) )
    {
        write("本房间十分重要，请勿在此进行一些有可能造成失误的操作。\n");
        return 1;
    }

    return 0;
}

void reset()
{ 
              ::reset(); 
              set("no_clean_up", 1); 
}
