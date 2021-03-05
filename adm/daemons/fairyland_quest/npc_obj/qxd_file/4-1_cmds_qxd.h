// 支持幻境内基本指令
// 上一个文件写不下了，写到这里来
// 本指令参考 cmd i 而写
// 实话说，仔细地看了 i 指令，发现 hj 里实在大有可精简之处，sigh
// naihe 6:39 03-11-5
string get_msg( object *list, int type )
{
    mixed class123;
    object *temp;
    int n, i=0;
    string msg = "  ";

    if( !list || sizeof(list) < 1 ) return "";

    // 先进行处理，将同一名称物件分成各小组
    class123 = unique_array( list, (: sprintf( "%s%s%s",
            base_name($1), $1->name(), $1->query("id") ) :) );

    // 开始组织其信息
    foreach( temp in class123 )
    {
        // 以此方法保持每横排可列出 2 或 3 个名字，节约屏幕啊
        i++;
        if( i>3 && type ) { i=1;msg += "\n  "; }
        if( i>2 && !type ) { i=1;msg += "\n  "; }
        // 类型为 0 时，2个一横排，否则 3个一横排

        n = sizeof(temp);
        msg += sprintf( "(%2s)%s  ", n<10 ? "0"+n : ""+n, temp[0]->short() );
    }

    return msg;
}


int do_gi()
{
    object *inv, me = this_player(), *temp, *hjinv, *list;
    int n;
    string msg, cl;

    // 随时允许查询
//    if( !me_ok(me) ) return 0;

    inv = all_inventory(me);
    if( !inv || sizeof(inv) < 1 )
        return errs("你身上没有携带任何东西。\n");

    // 得到一个 object 组，该组内只包含 有query("hj_game/obj")信息的任何物件
    hjinv = filter_array( inv, (: $1->query("hj_game/obj") :) );

    // 若无该组，可直接返回
    if( !hjinv || !sizeof(hjinv) )
        return errs( "你共携带"+chinese_number(sizeof(inv))
                +"件其他物品，并没有任何幻境内物品。\n");
    // 设置头信息
    msg = sprintf(HIC"
你共携带 %d 件各式物品，负重是 %d%% 。
其中有 %d 件其他物品，%d 件幻境内物品：
=======================================================================\n"NOR,
        sizeof(inv),
        me->query_encumbrance() * 100 / me->query_max_encumbrance(), 
        sizeof(inv)-sizeof(hjinv), sizeof(hjinv) );

    cl = HIY;

// 开始进行详细的分类统计。

    // 剑器类
    list = filter_array( hjinv, (: $1->query("hj_game/obj") == "sword" :) );
    // 如果有剑器类，组织其信息并将这些从总列表中剔除
    if( n = sizeof( list ) )
    {
        msg += sprintf( cl+"攻击剑器类(共 %d 件)：\n"NOR"%s\n",
                n, get_msg( list, 1 ) );
        hjinv -= list;
    }

    // 魔法水晶类
    list = filter_array( hjinv, (: $1->query("hj_game/obj") == "magic" :) );
    if( n = sizeof( list ) )
    {
        msg += sprintf( cl+"魔法水晶类(共 %d 件)：\n"NOR"%s\n",
                n, get_msg( list, 1 ) );
        hjinv -= list;
    }

    // 技能石类
    list = filter_array( hjinv, (: $1->query("hj_game/obj") == "quest" :) );
    if( n = sizeof( list ) )
    {
        msg += sprintf( cl+"技能石类(共 %d 件)：\n"NOR"%s\n",
                n, get_msg( list, 1 ) );
        hjinv -= list;
    }

    // 辅助类
    list = filter_array( hjinv, (: $1->query("hj_game/obj") == "tools" :) );
    if( n = sizeof( list ) )
    {
        msg += sprintf( cl+"辅助道具类(共 %d 件)：\n"NOR"%s\n",
                n, get_msg( list, 1 ) );
        hjinv -= list;
    }

    // 果品或宝石类
    list = filter_array( hjinv, (: $1->query("hj_game/obj") == "other" :) );
    if( n = sizeof( list ) )
    {
        msg += sprintf( cl+"果品或宝石类(共 %d 件)：\n"NOR"%s\n",
                n, get_msg( list, 1 ) );
        hjinv -= list;
    }

    // 权杖、各族宝物类
    list = filter_array( hjinv, (: $1->query("hj_game/obj") == "the_gem"
                  || $1->query("hj_game/obj") == "the_gem_qz" :) );
    if( n = sizeof( list ) )
    {
        msg += sprintf( cl+"各族宝物类(共 %d 件)：\n"NOR"%s\n",
                n, get_msg( list, 0 ) );
        hjinv -= list;
    }

    // 如果还有剩余，即为特殊类
    if( n = sizeof( hjinv )  )
        msg += sprintf( cl+"特殊类(共 %d 件)：\n"NOR"%s\n",
                n, get_msg( hjinv, 0 ) );

    msg += HIC"=======================================================================\n"NOR;
    write( msg );
    return 1;
}

// 临时离开游戏
int do_hjleave(string arg)
{
    object me = this_player();
    if( !me_ok(me) )
        return errs( "什么？\n");
    if( !arg || arg != "yes" )
        return errs( 
            "当你在幻境游戏中需要暂时离开时，请使用这个指令。\n"
            "这个指令可以让你的游戏角色受到保护，不会受到来自任何方面的攻击。\n"
            "不过，关于你的一些游戏内容会继续，例如游戏总时间到达后你会结束游戏；等等。\n"
            "每局游戏里只能使用三次这个指令。使用时，你必须在空闲状态下。\n"
            "\n          如果你确实想暂时离开，请输入： hjleave yes\n\n"
        );
    if( me->query_temp( "hjleave_usetimes" ) >= 3 )
        return errs( "本局游戏你已经用过这个功能 3 次了。\n");
    if( me->is_busy()
      || me->query_temp("hj_healing")
      || me->query_temp("hj_fighting")
      || me->query_temp("hj_need_waiting")
    )
        return errs( "你还忙着呢！你必须在空闲时才能使用这个指令。\n");
    if( environment(me)->query("room_mark") == 1 )
        return errs( "你不能在 1 号地点使用这个指令。\n" );
    me->add_temp( "hjleave_usetimes", 1 );
    new( __DIR__"hj_temp_leave") -> move(me);
    return 1;
}
