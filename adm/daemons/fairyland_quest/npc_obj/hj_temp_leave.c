// 配合 qxd 使用，玩家暂时离开时可以保护其角色的安全(携带此物件)
// naihe 05-9-4 13:48
// naihe 05-9-12 9:22 修正BUG，若指令 quit 时，则 quit.

#include <ansi.h>
inherit ITEM;

void create()
{
    set_name( "幻境物件·临时离开时用", ({ "hj temp leave obj" }) );
    set_weight(1);
    if (clonep())
        set_default_object(__FILE__);
    else
    {
        set("long", "玩家携带时即禁止其一切指令。\n");
        set("unit", "个");
        set("value", 0);
    }
    set("hj_game/obj","hj leave obj");
//    setup();
}
void init()
{
    object env, me = this_player();
    if( (env=environment(this_object()))
      && env == me
    )
    {
        mapping find_name = ([
            "feng" : HIW"风之国度"NOR,
            "yu"   : HIM"雨之国度"NOR,
            "lei"  : HIC"雷之国度"NOR,
            "dian" : HIG"电之国度"NOR,
        ]);
        me->set_temp( "apply/short", ({ sprintf( HIR"<暂时离开游戏> "NOR"%s %s(%s)"NOR,
            find_name[ me->query_temp( "hj_game_find" ) ],
            me->query("name"), capitalize(me->query("id")) ), })
        );
        me->set_temp( "hj_apply_short", 1 );
        message_vision( "\n$N暂时离开了幻境游戏，系统将保护$N的角色安全。\n\n", me );
        tell_object( me, "\n\n                  返回游戏请输入 \"back\" \n\n\n" );
        add_action( "filter_cmds", "", 1 );
    }
}
int filter_cmds(string arg)
{
    object me = this_player();
    if( query_verb() == "quit" )
    {
        return 0;
    }
    if( query_verb() == "back" )
    {
        mapping find_name = ([
            "feng" : HIW"风之国度"NOR,
            "yu"   : HIM"雨之国度"NOR,
            "lei"  : HIC"雷之国度"NOR,
            "dian" : HIG"电之国度"NOR,
        ]);
        me->set_temp( "apply/short", ({ sprintf( "%s %s(%s)"NOR,
            find_name[ me->query_temp( "hj_game_find" ) ],
            me->query("name"), capitalize(me->query("id")) ), })
        );
        me->set_temp( "hj_apply_short", 1 );
        message_vision( "\n$N返回了幻境游戏。\n\n", me );
        destruct( this_object() );
        return 1;
    }
    tell_object( me, "你现在暂时离开幻境游戏。若需返回游戏，请输入 \"back\" \n" );
    return 1;
}
