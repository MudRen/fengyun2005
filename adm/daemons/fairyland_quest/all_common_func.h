// 本文件被 all_room_info_hj.h
// 及 1_room_info_special.h 
// 共同调用。

// naihe 0:33 03-10-21



void reset()
{ 
    ::reset();
    set("no_clean_up", 1); 
}

int block_cmds()
{
    write("幻境里不允许使用这个指令。关于 hj 里使用的一些基本指令，请输入 help hj2003 查询。\n");
    return 1;
}

int do_look(string arg)
{
    string *orention;

    if( !arg )
        return 0;
    orention=({ "east","west","south","north",
        "northeast","northwest","southeast","southwest"
    });
    if( member_array( arg , orention ) != -1 )
    {
        write("到处都是一片密林，你看不到远处的情况。\n");
        return 1;
    }
    return 0;
}

int do_get(string arg)
{
    if( !arg || arg != "all")
        return 0;
    write("还是一样一样地拣罢。\n");
    return 1;
}

void get_out_here( object me )
{
    if( !me ) return;

    message_vision( HIR"$N"HIR"不知怎么的闯进了幻境密林里，一阵奇异的震荡把$N"HIR"抛了出去。\n"NOR,me);
    me->move( __DIR__"room_door_hj" );
    message_vision("一阵莫名的震荡忽来忽逝，$N不知怎么的就忽地出现在这里了。\n",me);
}


void full_all( object me )
{
    if( !me )
        return;
    me->set("jingli",me->query("max_jingli") ); // 只要加些精力给走路时消耗，以及保持饿不死就行了。
    me->set("food", 50 );
    me->set("water",50 );
}

int valid_leave(object me, string dir)
{
    string temp;

    if( me->query_temp("hj_move_busy") > 1000 )
        return notify_fail("密林里纠结重重，你无法行走太快。\n");

    temp = me->query_temp("hj_need_waiting");
    if( temp && me->is_busy() )
    {
        switch(temp)
        {
            case "healing":return notify_fail("你正在疗伤呢，走不开。\n");
            case "fighting":return notify_fail("你还在战斗中，被缠住了走不开。\n");
            default:return notify_fail("你正忙着呢，无法离开。\n");
        }
    }

    if( me->query_temp("hj_the_orention") == dir && random( 10 ) == 1 &&
        !me->query("hj_game/npc") )
    {
        call_out("games_random_move",1, me);
        message_vision( HIR"\n一阵奇异的震荡忽然传来……\n"NOR, me );
        me->start_busy(2);
        return notify_fail("\n");
    }

    // 走路 busy 方式更改，配合 七星灯 来实现新的效果。
    // 七星灯有将此数值逐秒递减的函数。
    // 风之国度主动技能效果  走路时忙时较低
    if( !me->query("hj_game/npc") )
    {
        if( me->query_temp("hj_game_find") == "feng" )
            me->add_temp("hj_move_busy", (150+random(100)) );  // 再增强
        else me->add_temp("hj_move_busy", (300+random(200) ) );
    }

    me->set_temp("hj_the_orention",dir); //  记录这一步的方向

    return ::valid_leave(me, dir);
}

void games_random_move( object me )
{
    object rooms;
    string random_rooms;

    if( !me || !environment(me) || environment(me) != this_object() ) return;
    random_rooms=__DIR__"hj_room"+( 2 + random( HJ_ROOM_AMOUNT-1 ));

    tell_room( environment(me), HIR+me->query("name")+HIR"突然凭空消失不见！\n"NOR, ({ me }) );
    rooms=find_object(random_rooms);
    if(!rooms) rooms = load_object(random_rooms);
    if( !rooms ) rooms = this_object();
    this_player()->move(rooms);
    message_vision(HIG"$N"HIG"被一股奇怪的震荡送到了这里来。\n"NOR,me);
}

