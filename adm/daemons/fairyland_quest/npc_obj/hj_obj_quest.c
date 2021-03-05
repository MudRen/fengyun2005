//                标准描述长度示例                                   |
// 幻境内物品  迷题型（包括学习技能的类型）
// by naihe  2002-10-23  于茂名
// 本物件只作为学习技能型的物品使用。 21:42 02-10-28 by naihe
// naihe 05-9-7 9:15 v1.7 继续调整。

#include <ansi.h>
#include <errs_func.h>

inherit ITEM;

string *names=({
    HIW"呼风之石"NOR,
    MAG"唤雨之石"NOR,
    HIC"落雷之石"NOR,
    HIG"引电之石"NOR,
    YEL"滚石之石"NOR,
    RED"飞火之石"NOR,
    BLU"夺魂之石"NOR,
    CYN"复活之石"NOR,
    CYN"复活之石"NOR,  // 多一个机会获得本物品
});

string *ids=({
    "hufeng shi",
    "huanyu shi",
    "luolei shi",
    "yindian shi",
    "gunshi shi",
    "feihuo shi",
    "duohun shi",
    "fuhuo shi",
    "fuhuo shi",
});

string *longs=({
    "这是一颗呼风之石，它似乎给你一种神秘的感觉。\n你不妨仔细领会(linghui)一下这种感觉。\n",
    "这是一颗唤雨之石，它似乎给你一种神秘的感觉。\n你不妨仔细领会(linghui)一下这种感觉。\n",
    "这是一颗落雷之石，它似乎给你一种神秘的感觉。\n你不妨仔细领会(linghui)一下这种感觉。\n",
    "这是一颗引电之石，它似乎给你一种神秘的感觉。\n你不妨仔细领会(linghui)一下这种感觉。\n",
    "这是一颗滚石之石，它似乎给你一种神秘的感觉。\n你不妨仔细领会(linghui)一下这种感觉。\n",
    "这是一颗飞火之石，它似乎给你一种神秘的感觉。\n你不妨仔细领会(linghui)一下这种感觉。\n",
    "这是一颗夺魂之石，它似乎给你一种神秘的感觉。\n你不妨仔细领会(linghui)一下这种感觉。\n",
    "这是一颗复活之石，它似乎给你一种神秘的感觉。\n你不妨仔细领会(linghui)一下这种感觉。\n",
    "这是一颗复活之石，它似乎给你一种神秘的感觉。\n你不妨仔细领会(linghui)一下这种感觉。\n",
});

string *units=({
    "颗",
    "颗",
    "颗",
    "颗",
    "颗",
    "颗",
    "颗",
    "颗",
    "颗",
});

string *skills=({
    "hfzj",
    "hyzj",
    "llzj",
    "ydzj",
    "gszj",
    "fhzj",
    "dhzj",
    "heal",
    "heal",
});

string *skills_names=({
    "呼风之技",
    "唤雨之技",
    "落雷之技",
    "引电之技",
    "滚石之技",
    "飞火之技",
    "夺魂之技",
    "恢复之技",
    "恢复之技",
});

int *sks_damages=({   // 初学时能得到的 效力（等级）
    3+random(3),
    3+random(3),
    3+random(3),
    3+random(3),
    5,
    5,
    3,
    5+random(6),
    5+random(6),
});


void setme( int iii )
{
    if( iii == 99 ) iii = random( sizeof(names) );
    set( "iii", iii );
    set_name(names[ iii ], ({ids[ iii ],"shi"}));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);

    set("long", longs[ iii ]);
    set("unit", units[ iii ]);
    set("hj_game/obj","quest");

    set("value", 1);  // 该物件扔下后不会消失。
    set("use_times", 5 + random(4)); // 最大领会5-8次
    set("no_refresh",1); // 不会被房间更新。
}

void create()
{
    setme( 99 );
  //  setup();
}

void init()
{
    add_action("do_linghui", ({ "linghui", "lh"}) );
}

void delete_me()
{
    message_vision("$N灵气已尽，「嘭」地一声消失了。\n"NOR,this_object());
    destruct(this_object());
}

int do_linghui(string arg)
{
    object me,ob;
    string temp;
    int iii = query("iii"), lh_fail;

    if(query("delete_now")) return 0;

    ob=this_object();
    me=this_player();

    if( !environment(me) || !environment(me)->query("room_mark") ){
    		errs("这个地方不能领会技能！");
}
    if( environment(me)->query("room_mark") == 1 ){
        return notify_fail("这个地方不能领会技能。\n");
    }
    if(!arg || (arg != ob->query("id") && arg != skills[ iii ] && arg != "shi") ){
    	errs("你打算领会什么技能！");
 }

    if( !me->query_temp("huanjing") || me->query_temp("huanjing") != "start" ||
    !me->query_temp("hj_hp") || me->query_temp("hj_hp") < 1 ){
        errs("你都这样了就别着急领会技能了！");
   }
    if( me->is_busy() || me->query_temp("hj_need_waiting") ){
        return notify_fail("你还忙着呢。\n");
}
    if( me->query_temp("hj_hp") <50 ){
        return notify_fail("你已经头昏眼花了，还是先休息休息吧。\n");
}
    message_vision(CYN"$N"NOR+CYN"拿起$n"NOR+CYN"仔细端详着，领会着它所带来的神秘气息。\n"NOR,me, ob);
    me->add_temp("hj_hp",-(5+random(6)));

    lh_fail = random(3);  // 0, 1, 2.  0 时才是成功的
    // 雨之国度被动技能效果  领会神秘石的技能时，成功几率上涨。
    // 失败了的话，还有一次机会
    if( lh_fail && me->query_temp("hj_special/cm") )
        lh_fail = random(3);    // 0, 1, 2.  0 时才是成功的
    if( lh_fail )
        message_vision(CYN"$N"NOR+CYN"似乎十分疲惫，却仍是无法抓住那种飘渺之感。\n"NOR,me);
    else
    {
        if( !me->query_temp("hj_game_skills/"+skills[ iii ])
          || !me->query_temp("hj_game_damages/"+skills[ iii ])
        )
            temp="new";
        else
            temp="up";
        if(temp == "new")
        {
            me->set_temp("hj_game_skills/"+skills[ iii ],skills_names[ iii ]);
            me->set_temp("hj_game_damages/"+skills[ iii ],sks_damages[ iii ]);
            message_vision(CYN"$N"NOR+CYN"只觉得突然之间似有神灵启示，已领悟了「"+skills_names[ iii ]+"」！\n"NOR,me);
        }
        else
        {
            if(me->query_temp("hj_game_damages/"+skills[ iii ]) >= 99)
                message_vision(CYN"$N"NOR+CYN"只觉得心若冰清，看来早已把它全数领会了。\n"NOR,me);
            else
            {
                me->add_temp("hj_game_damages/"+skills[ iii ], 1 );
                message_vision(CYN"$N"NOR+CYN"只觉得突然之间心境大清，对「"+skills_names[ iii ]+"」的领会又进了一层！\n"NOR,me);
            }
        }
    }
    me->start_busy(1);      // 忙时下调了
    add("use_times", -1);
    if( !random(2) || query("use_times") < 1 )
    {
        if( query("wait_delete") )
        {
            set("delete_now", 1);
            remove_call_out("delete_me");
            call_out("delete_me",1);
        }
        set("wait_delete",1);
    }
    return 1;
}
